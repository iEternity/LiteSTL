#pragma once

namespace LiteSTL
{

class Alloc
{
public:
	static void* allocate(size_t bytes);
	static void deallocate(void* ptr, size_t bytes);
	static void* reallocate(void* ptr, size_t oldSize, size_t newSize);

private:
	static size_t freeListIndex(size_t bytes)
	{
		return (bytes + kAlignSize - 1) / kAlignSize - 1;
	}

	static void* refill(size_t bytes);

	/*上调至8的倍数*/
	static size_t roundUp(size_t bytes)
	{
		return (bytes + kAlignSize - 1) & ~(kAlignSize - 1);
	}

	/*分配一块可以容纳 n*bytes 大小的内存块*/
	static char* chunkAlloc(size_t bytes, size_t& n);

private:
	/*小型内存块的上限*/
	static const int kMaxBytes = 128;
	/*内存对齐系数*/
	static const int kAlignSize = 8;
	/*free-list 的个数*/
	static const int kNumFreeLists = kMaxBytes / kAlignSize;
	/*每次增加的节点数*/
	static const int kNumObjs = 20;

	union Obj
	{
		Obj* next;
		char client[1];
	};
	static Obj* freeLists_[kNumFreeLists];

	static char*	startFree_;
	static char*	endFree_;
	static size_t	heapSize_;
};

}