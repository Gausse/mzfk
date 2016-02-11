#ifndef _ARRAY_
#define _ARRAY_

#include <math.h>
#include <iostream>

class Array
{
	int nSize;
	int n_iCurrentIndex;
	int* pArray;

public:
	Array();
	Array(int size);
	~Array();
	void push_back(int number);
	void show();
private:
	void addMemory();
	void copyArray(int *from, int *to, int size);
};
#endif // _ARRAY_