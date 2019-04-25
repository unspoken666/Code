#pragma once
#include "Common.h"

class PageCache
{
public:
	static PageCache* GetInstance()
	{
		return &_inst;
	}

	Span* NewSpan(size_t npage);

	//��ȡ�Ӷ���span��ӳ��
	Span* MapObjectToSpan(void* obj);
	//�ͷſ���span�ص�Pagecache,���ϲ����ڵ�span
	void ReleaseSpanToPageCache(Span* span);

private:
	SpanList _pagelist[NPAGES];
private:
	PageCache() = default;
	PageCache(const PageCache&) = delete;
	static PageCache _inst;

	//std::unordered_map<PageID,Span*> _id_span_map;
	std::map<PageID,Span*> _id_span_map;
};