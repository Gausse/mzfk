#include <iostream>
#include <windows.h>
#include <stdlib.h>
#include <memory>

struct Params
{
	int** data;
	int size;
	int* currMatrixIndex;
    HANDLE* mutex;
    Params(int** arr, int len, int* index, HANDLE* synchrono) : data(arr), size(len), currMatrixIndex(index), mutex(synchrono) {}
};

DWORD WINAPI ThFirst(void *pV)
{
	std::shared_ptr<Params> sh((Params*)pV);
	int index = 0;

	WaitForSingleObject(sh->mutex, INFINITE);

	index = (*sh->currMatrixIndex)++;

	ReleaseMutex(sh->mutex);

	for (int i = 0; i < sh->size; ++i)
	{
		sh->data[index][i] += 1;
	}
	return 0;
}

DWORD WINAPI ThSecond(void *pV)
{
	std::shared_ptr<Params> sh((Params*)pV);
	int index = 0;

	WaitForSingleObject(sh->mutex, INFINITE);

	index = (*sh->currMatrixIndex)++;

	ReleaseMutex(sh->mutex);

	for (int i = 0; i < sh->size; ++i)
	{
		sh->data[index][i] -= 1;
	}
	return 0;
}

DWORD WINAPI ThThird(void *pV)
{
	std::shared_ptr<Params> sh((Params*)pV);
	int index = 0;

	WaitForSingleObject(sh->mutex, INFINITE);

	index = (*sh->currMatrixIndex)++;

	ReleaseMutex(sh->mutex);

	for (int i = 0; i < sh->size; ++i)
	{
		sh->data[index][i] += 2;
	}
	return 0;
}

int main()
{
	int currIndex = 0;
    int size = 5;
    int** array = new int*[size];

    for(int i = 0; i < size; ++i)
    {
		array[i] = new int[size];
		for (int j = 0; j < size; ++j)
		{
			array[i][j] = rand() % 10;
			std::cout << array[i][j] << " ";
		}
		std::cout << std::endl;
    }

	HANDLE mutex = CreateMutex(NULL, TRUE, L"word");

	system("pause");

	ReleaseMutex(mutex);

	HANDLE my_thread = CreateThread(0, 0, ThFirst, new Params(array, size, &currIndex, &mutex), 0, 0);
	HANDLE my_thread1 = CreateThread(0, 0, ThSecond, new Params(array, size, &currIndex, &mutex), 0, 0);
	HANDLE my_thread2 = CreateThread(0, 0, ThThird, new Params(array, size, &currIndex, &mutex), 0, 0);
	
	system("pause");
	std::cout << "----------------------------" << std::endl;

	for (int i = 0; i < size; ++i)
	{
		for (int j = 0; j < size; ++j)
		{
			std::cout << array[i][j] << " ";
		}
		std::cout << std::endl;
	}

    CloseHandle(my_thread);
    CloseHandle(my_thread1);
	CloseHandle(my_thread2);

	for (int i = 0; i < size; ++i)
		delete[] array[i];
	delete[] array;
    return 0;
}

