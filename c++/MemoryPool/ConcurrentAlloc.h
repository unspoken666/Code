#pragma once
#include "Common.h"
#include "ThreadCache.h"

void* ConcurrentAlloc(size_t size)
{
	if (size > MAXBYTES)
		return malloc(size);
	else
	{
		//ͨ��tls����ȡ�߳��Լ���thread cache
		if (tls_threadcache == nullptr)
		{
			tls_threadcache = new ThreadCache;
			//cout << std::this_thread::get_id() << "->" << tls_threadcache << endl;
		}

		return tls_threadcache->Allocate(size);
	}
}

void ConcurrentFree(void* ptr,size_t size)
{
	if (size > MAXBYTES)
	{
		free(ptr);
	}
	else
	{
		tls_threadcache->Deallocate(ptr,size);
	}
}
