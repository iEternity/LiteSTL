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

	/*�ϵ���8�ı���*/
	static size_t roundUp(size_t bytes)
	{
		return (bytes + kAlignSize - 1) & ~(kAlignSize - 1);
	}

	/*����һ��������� n*bytes ��С���ڴ��*/
	static char* chunkAlloc(size_t bytes, size_t& n);

private:
	/*С���ڴ�������*/
	static const int kMaxBytes = 128;
	/*�ڴ����ϵ��*/
	static const int kAlignSize = 8;
	/*free-list �ĸ���*/
	static const int kNumFreeLists = kMaxBytes / kAlignSize;
	/*ÿ�����ӵĽڵ���*/
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