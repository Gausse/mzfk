#include "Array.h"

Array::Array() : nSize(0), n_iCurrentIndex(0), pArray(0)
{
}

Array::Array(int size) : nSize(size), n_iCurrentIndex(0), pArray(0)
{
	this->pArray = new int[nSize];
	this->nSize = size;
	this->n_iCurrentIndex = 0;
}

Array::~Array()
{
	delete[] this->pArray;
}

void Array::addMemory()
{
	int tmpSize = this->nSize;
	this->nSize = (int)ceil((double)this->nSize*1.5);
	int *temp = new int[this->nSize];
	copyArray(this->pArray, temp, tmpSize);
	delete[] this->pArray;
	this->pArray = temp;
}

void Array::copyArray(int *from, int *to, int size)
{
	for (int i = 0; i < size; ++i)
	{
		to[i] = from[i];
	}
}

void Array::push_back(int number)
{
	if (this->nSize == this->n_iCurrentIndex)
	{
		this->addMemory();
	}

	this->pArray[n_iCurrentIndex++] = number;
}

void Array::show()
{
	for (int i = 0; i < this->n_iCurrentIndex; ++i)
	{
		std::cout << this->pArray[i] << " ";
	}
	std::cout << std::endl;
}