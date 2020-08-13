//
// dup_data_type.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
// Changes:
// 1. Try to keep every class in its own "cpp code file" and "h header file" of file extensions: *.cpp and *.h respectively.


// PLEASE NOTE:
// Keep in mind about 64-bit:
// You can change between 32bit and 64bit in "common.h" by uncommenting "#define BIT64"
// Then, you "may" (actually "will") have to re-build everything so that everything is either 32bit or 64bit.


// "C++" file implimentation:
#include <iostream>
#include <vector>
#include "dupobj.h"
// Customizable class:
#include "classdata.h"


// "C" file implimentation:
// Containing version1 and version2, and customizable data types.
// Files include: mydup.h, mydup.cpp (really a "C" file)
#include "mydup.h"



// Main file include:
#include "dup_data_type.h"

int main()
{
	dup* x1, * y1, * z1;
	mydup* x2, * y2, * z2;
	mydatatype* d;
	int_t arg0, arg1, arg2;

	std::cout << "Demo Program using the \"dup data type\", in version1 and version2\n";

	d = (mydatatype*)malloc(sizeof(mydatatype));

	std::cout << "Input an integer for arg0: ";
	std::cin >> arg0;
	d->customizable_datatype = arg0;
	std::cout << "Input an integer for arg1: ";
	std::cin >> arg1;
	d->some_values = arg1;
	std::cout << "Input an integer for arg2: ";
	std::cin >> arg2;
	d->more_values = arg2;

	// Examples of usage:
	x1 = AssociateDataToDup1(d);
	x2 = NewDup2(arg0, arg1, arg2);

	y1 = CopyDup1(x1);
	y2 = CopyDup2(x2);

	AssignDup1(x1, x1);
	AssignDup1(x1, y1);

	AssignDup2(x2, x2);
	AssignDup2(x2, y2);

	z1 = AssociateDataToDup1(GetCopyOfData1(x1));
	z2 = GetCopyOfData2(x2);

	std::cout << "You entered in version (1): ";
	std::cout << z1->data->customizable_datatype << ", ";
	std::cout << z1->data->some_values << ", ";
	std::cout << z1->data->more_values << "\n";
	std::cout << "Or in version (2): ";
	std::cout << z2->customizable_datatype << ", ";
	std::cout << z2->some_values << ", ";
	std::cout << z2->more_values << "\n";

	free_dup1(x1);
	free_dup1(y1);
	free_dup1(z1);

	free_dup2(x2);
	free_dup2(y2);
	free_dup2(z2);


	// class template example:
	typedef std::vector<datamember> mycontainer;
	typedef classdata<datamember, mycontainer> mytype;
	mytype * f, * g;
	dupobj<mytype>* a, * b, * c;

	// String data test:
	char msg[] = "Hi world.";
	char* ptr;
	size_t size;
	size = strlen(msg) + 1;
	ptr = (char*)malloc(size);
	if (ptr != nullptr)
	{
		memcpy(ptr, msg, size);
	}

	datamember dm(ptr, size, NULL, 0, NULL, 0, 1, 2, 3);
	datamember* dm0, * dm1, * dm2;
	mycontainer ar(2);
	dm0 = new datamember(dm);
	dm1 = new datamember(dm);
	ar[0] = *dm0;
	ar[1] = *dm1;

	f = new mytype(ar);
	a = new dupobj<mytype>(f);
	b = a->CopyDup();
	f = b->ViewPointerOfData();

	dm.customizable_datatype = 4;
	dm.some_values = 5;
	dm.more_values = 6;
	g = new mytype(*f, 1, &dm);
	
	//g = new mytype(*f, 1);
	//g->members[1].customizable_datatype = 4;
	//g->members[1].some_values = 5;
	//g->members[1].more_values = 6;

	c = new dupobj<mytype>(g);
	b->CopyThisToArgument(&a);
	//c->CopyThisToArgument(&a);
	DUPOBJ_ASSIGN(a, c);

	std::cout << "Values are:\n";

	dm2 = c->ViewPointerOfData()->GetMember(1);
	std::cout << dm2->customizable_datatype << "\n";
	std::cout << dm2->some_values << "\n";
	std::cout << dm2->more_values << "\n";
	std::cout << "\n";

	a->deallocate();
	b->deallocate();
	c->deallocate();

	a->destroy();
	b->destroy();
	c->destroy();

	//delete a;
	//delete b;
	//delete c;

	//delete dm0;
	//delete dm1;
	//delete dm2;

	//free(ptr);

	std::cout << "\nDemo done.\n";
}
