
// This is actually a "C" file.

#ifndef __MYDUP_H__
#define __MYDUP_H__

// File: MyDup.H

// Description: Performs like a Dynamic Link Library (dll) only allocating the same data once.

// Duplicate data type (or "dup" for short)


#include "common.h"

// This value is 1 for compatibility with the Aramaic number system
#define START_COUNT_AT 1


// Version 1

typedef struct mydatatype1 {
	// This variable is customizable, can be any data that can be dynamically allocated.
	
	int_t customizable_datatype; // customizable
	int_t some_values; // customizable
	int_t more_values; // customizable
} mydatatype;

typedef struct dup1 {
	int_t count;
	mydatatype* data;
} dup;


// Version 2

typedef struct mydatatype2 {
	int_t count; // required member
	int_t customizable_datatype;
	int_t some_values;
	int_t more_values;
} mydup;



// Prototypes

dup* CopyDup1(dup* d);
mydup* CopyDup2(mydup* d);
void free_dup1(dup* d);
void free_dup2(mydup* d);
dup* AssociateDataToDup1(mydatatype* data);
mydup* NewDup2(int_t arg0, int_t arg1, int_t arg2);
void AssignDup1(dup* dst, dup* src);
void AssignDup2(mydup* dst, mydup* src);
mydatatype* ViewPointerOfData1(dup* d);
mydatatype* GetCopyOfData1(dup* d);
mydup* ViewPointerOfData2(mydup* d);
mydup* GetCopyOfData2(mydup* d);



#endif // __MYDUP_H__
