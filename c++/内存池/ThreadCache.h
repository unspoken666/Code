#pragma once

#include "Common.h"

class ThreadCache
{
public:
	void* Allocate(size_t size);
	void Deallocate(void* ptr, size_t size);

	// �����Ļ����ȡ����
	void* FetchFromCentralCache(size_t index, size_t size);
	//�����ж���̫�࣬��ʼ����
	void ListTooLong(FreeList* freelist,size_t byte);

private:
	FreeList _freelist[NLISTS];
	//int _tid;
	//ThreadCache* _next;
};

static _declspec (thread) ThreadCache* tls_threadcache = nullptr;