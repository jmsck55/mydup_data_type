
#pragma once

#include "pch.h"
#include "common.h"

#include "small_class.h"

class datamember
{
public:
	char* chardata;
	size_t sizeof_chardata;
	int_t* int_array;
	size_t length_of_int_array;
	small_class** sm_data;
	size_t length_of_sm_data;

	int_t customizable_datatype; // customizable
	int_t some_values; // customizable
	int_t more_values; // customizable
	datamember()
	{
		chardata = nullptr;
		sizeof_chardata = 0;
		int_array = nullptr;
		length_of_int_array = 0;
		sm_data = nullptr;
		length_of_sm_data = 0;

		customizable_datatype = 0; // customizable
		some_values = 0; // customizable
		more_values = 0; // customizable
	}
	datamember(const datamember& src)
	{
		sizeof_chardata = src.sizeof_chardata;
		chardata = (char*)malloc(sizeof_chardata);
		if (chardata != nullptr)
		{
			memcpy(chardata, src.chardata, sizeof_chardata);
		}

		length_of_int_array = src.length_of_int_array;
		int_array = (int_t*)calloc(length_of_int_array, sizeof(int_t));
		if (int_array != nullptr)
		{
			memcpy(int_array, src.int_array, length_of_int_array * sizeof(int_t));
		}

		length_of_sm_data = src.length_of_sm_data;
		sm_data = (small_class * *)calloc(length_of_sm_data, sizeof(void*));
		if (sm_data != nullptr)
		{
			for (size_t i = 0; i < length_of_sm_data; i++)
			{
				sm_data[i] = new small_class(*src.sm_data[i]);
			}
			memcpy(sm_data, src.sm_data, length_of_sm_data * sizeof(small_class));
		}

		customizable_datatype = src.customizable_datatype;
		some_values = src.some_values;
		more_values = src.more_values;
	}
	datamember(char* st, size_t ch_size, int_t* int_ar, size_t ar_size, small_class** mn, size_t mn_length, int_t a, int_t b, int_t c)
	{
		chardata = st;
		sizeof_chardata = ch_size;
		int_array = int_ar;
		length_of_int_array = ar_size;
		sm_data = mn;
		length_of_sm_data = mn_length;
		customizable_datatype = a;
		some_values = b;
		more_values = c;
	}
	~datamember()
	{
		free(chardata);
		free(int_array);
		for (size_t i = 0; i < length_of_sm_data; i++)
		{
			delete sm_data[i];
		}
		free(sm_data);

		// put code in here if needed.
	}
};

