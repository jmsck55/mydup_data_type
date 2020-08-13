
#pragma once

#include "common.h"

class small_class
{
public:
	int_t a;
	small_class()
	{
		a = 0;
	}
	small_class(const small_class& src)
	{
		a = src.a;
	}
	~small_class()
	{
		// put code in here if needed.
	}
};

