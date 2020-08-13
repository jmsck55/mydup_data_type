
#pragma once

#include "common.h"

// This value is 1 for compatibility with the Aramaic number system
// For the program to work correctly, this value really should be 1.
#define START_CLASS_COUNT_AT 1

#define DUPOBJ_ASSIGN(DST, SRC) (SRC)->CopyThisToArgument(& (DST))


template <class T> class dupobj
{
	int_t count;
	T* data;
public:
	dupobj()
	{
		count = START_CLASS_COUNT_AT;
		count--;
		data = nullptr;
	}
	dupobj(T* associate)
	{
		count = START_CLASS_COUNT_AT;
		data = associate;
	}

	dupobj<T>* CopyDup()
	{
		count++;
		return this;
	}

	void CopyThisToArgument(dupobj<T>** dst)
	{
		if (this != *dst)
		{
			(*dst)->deallocate();
			count++;
			*dst = this;
		}
	}
	int_t GetCount()
	{
		return count;
	}
	T* ViewPointerOfData()
	{
		return data;
	}
	//T* GetCopyOfData();
	T* GetNewClassData()
	{
		T* ret;
		ret = new T(*data);
		return ret;
	}

	void deallocate()
	{
		if (count > START_CLASS_COUNT_AT)
		{
			count--;
		}
		else
		{
			delete data;
			count = START_CLASS_COUNT_AT;
			count--;
			data = nullptr;
		}
	}

	void destroy()
	{
		if (count == START_CLASS_COUNT_AT - 1)
		{
			delete this;
		}
	}

	~dupobj()
	{
	}
};
