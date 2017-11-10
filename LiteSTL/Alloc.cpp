#include "Alloc.h"
#include <new>
using namespace LiteSTL;

Alloc::Obj* Alloc::freeLists_[kNumFreeLists] = { 0 };
char* Alloc::startFree_ = nullptr;
char* Alloc::endFree_	= nullptr;
size_t Alloc::heapSize_ = 0;

void* Alloc::allocate(size_t bytes)
{
	if (bytes > kMaxBytes)
	{
		return ::malloc(bytes);
	}
	
	size_t index = freeListIndex(bytes);
	Obj* list = freeLists_[index];
	if (list)
	{
		freeLists_[index] = list->next;
		return list;
	}
	else
	{
		return refill(roundUp(bytes));
	}
}

void Alloc::deallocate(void* ptr, size_t bytes)
{
	if (bytes > kMaxBytes)
	{
		::free(ptr);
	}
	else
	{
		int index = freeListIndex(bytes);
		Obj* freeList = freeLists_[index];
		static_cast<Obj*>(ptr)->next = freeList;
		freeList = static_cast<Obj*>(ptr);
	}
}

void* Alloc::reallocate(void* ptr, size_t oldSize, size_t newSize)
{
	deallocate(ptr, oldSize);
	ptr = allocate(newSize);

	return ptr;
}

void* Alloc::refill(size_t bytes)
{
	size_t nObjs = kNumObjs;
	char* chunk = chunkAlloc(bytes, nObjs);

	Obj** myFreeList = nullptr;
	Obj* result = nullptr;
	Obj* currentObj = nullptr, *nextObj = nullptr;

	if (nObjs == 1)
	{
		return chunk;
	}
	else
	{
		myFreeList = freeLists_ + freeListIndex(bytes);
		result = (Obj*)chunk;
		*myFreeList = nextObj = (Obj*)(chunk + bytes);
		for (int i = 1;; i++)
		{
			currentObj = nextObj;
			nextObj = (Obj*)((char*)nextObj + bytes);
			if (i == nObjs - 1)
			{
				currentObj->next = nullptr;
				return result;
			}
			else
			{
				currentObj->next = nextObj;
			}
		}
		return result;
	}
}

char* Alloc::chunkAlloc(size_t bytes, size_t& numObjs)
{
	char* result = nullptr;
	size_t totalBytes = numObjs * bytes;
	size_t bytesLeft = endFree_ - startFree_;

	if (bytesLeft >= totalBytes)
	{
		result = startFree_;
		startFree_ += totalBytes;
		return result;
	}
	else if (bytesLeft >= bytes)
	{
		numObjs = bytesLeft / bytes;
		totalBytes = numObjs * bytes;
		result = startFree_;
		startFree_ = startFree_ + totalBytes;
		return result;
	}
	else
	{
		size_t bytesToGet = totalBytes * 2 + roundUp(heapSize_ >> 4);
		
		if (bytesLeft > 0)
		{
			Obj** myFreeList = freeLists_ + freeListIndex(bytesLeft);
			((Obj*)startFree_)->next = *myFreeList;
			*myFreeList = (Obj*)startFree_;
		}

		startFree_ = (char*)::malloc(bytesToGet);
		if (!startFree_)
		{
			Obj** myFreeList = nullptr, *p = nullptr;

			for (int i = bytes; i < kMaxBytes; i += kAlignSize)
			{
				myFreeList = freeLists_ + freeListIndex(i);
				p = *myFreeList;
				if (p != nullptr)
				{
					*myFreeList = p->next;
					startFree_ = (char*)p;
					endFree_ = startFree_ + i;
					return chunkAlloc(bytes, numObjs);
				}
			}
			endFree_ = 0;
		}

		heapSize_ += bytesToGet;
		endFree_ = startFree_ + bytesToGet;

		return chunkAlloc(bytes, numObjs);
	}
}