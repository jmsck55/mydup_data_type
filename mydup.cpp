
// This is actually a "C" file.

#include "pch.h"

#include "mydup.h"

dup* CopyDup1(dup* d)
{
	d->count++;
	return d;
}

mydup* CopyDup2(mydup* d)
{
	d->count++;
	return d;
}


void free_dup1(dup* d)
{
	if (d->count > START_COUNT_AT)
	{
		d->count--;
	}
	else
	{
		// deallocate
		free(d->data);
		free(d);
	}
}

void free_dup2(mydup* d)
{
	if (d->count > START_COUNT_AT)
	{
		d->count--;
	}
	else
	{
		// deallocate
		free(d);
	}
}


dup* AssociateDataToDup1(mydatatype* data)
{
	dup* retValue;
	retValue = (dup*)malloc(sizeof(dup));
	if (retValue != NULL)
	{
		retValue->count = START_COUNT_AT;
		retValue->data = data;
	}
	return retValue;
}

mydup* NewDup2(int_t arg0, int_t arg1, int_t arg2)
{
	mydup* retValue;
	retValue = (mydup*)malloc(sizeof(mydup));
	if (retValue != NULL)
	{
		retValue->count = START_COUNT_AT;
		retValue->customizable_datatype = arg0;
		retValue->some_values = arg1;
		retValue->more_values = arg2;
	}
	return retValue;
}


void AssignDup1(dup* dst, dup* src)
{
	// deallocate dup:
	if (dst != src)
	{
		src->count++;
		free_dup1(dst);
		dst = src;
	}
}

void AssignDup2(mydup* dst, mydup* src)
{
	// deallocate dup:
	if (dst != src)
	{
		free_dup2(dst);
		src->count++;
		dst = src;
	}
}


mydatatype* ViewPointerOfData1(dup* d)
{
	return d->data;
}

mydup* ViewPointerOfData2(mydup* d)
{
	return d;
}


mydatatype* GetCopyOfData1(dup* d)
{
	mydatatype* ret;
	ret = (mydatatype*)malloc(sizeof(mydatatype));
	if (ret != NULL)
	{
		memcpy(ret, d->data, sizeof(mydatatype));
	}
	return ret;
}


mydup* GetCopyOfData2(mydup* d)
{
	mydup* ret;
	ret = (mydup*)malloc(sizeof(mydup));
	if (ret != NULL)
	{
		memcpy(ret, d, sizeof(mydup));
		ret->count = START_COUNT_AT;
	}
	return ret;
}


