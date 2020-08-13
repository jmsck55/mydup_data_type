
#pragma once

#include "pch.h"
#include "common.h"

#include "datamember.h"

template <class T = datamember, class S = std::vector<T>> class classdata
{
	//private_data;
	int_t length;
	T** members;
public:
	int_t GetLength()
	{
		return length;
	}
	T* GetMember(int_t i)
	{
		return members[i];
	}
	classdata()
	{
		length = 0;
		members = nullptr;
	}
	classdata(int_t len)
	{
		length = len;
		members = (T * *)calloc(length, sizeof(void*));
	}
	classdata(S& ar)
	{
		length = (int_t)ar.size();
		members = (T * *)calloc(length, sizeof(void*));
		for (int_t i = 0; i < length; i++)
		{
			members[i] = new T(ar[i]);
		}
	}
	classdata(const classdata& src, int_t offset = -1, T * member = nullptr) // offset starts at 0.
	{
		// hard copy, without copying offset member
		length = src.length;
		members = (T * *)calloc(length, sizeof(void*));
		if ((offset >= 0) && (offset < length))
		{
			for (int_t i = 0; i < offset; i++)
			{
				members[i] = new T(*src.members[i]);
			}
			if (member != nullptr)
			{
				members[offset] = new T(*member);
			}
			for (int_t i = offset + 1; i < length; i++)
			{
				members[i] = new T(*src.members[i]);
			}
		}
		else
		{
			for (int_t i = 0; i < length; i++)
			{
				members[i] = new T(*src.members[i]);
			}
		}
	}

	~classdata()
	{
		for (int_t i = 0; i < length; i++)
		{
			delete members[i];
		}
		free(members);
	}
};

