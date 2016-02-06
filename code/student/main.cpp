#include <iostream>
#include <iomanip>

#define NAME_SIZE 10
#define CLASS_NUMBER 10

char names_surname[14][NAME_SIZE] = { "John", "Michale", "Momo", "Lol", "Sample", "Stranger", "Harley", "John", "Michale", "Momo", "Lol", "Sample", "Stranger", "Harley" };

struct Student
{
	char	sName[NAME_SIZE];
	char	sSurname[NAME_SIZE];
	int		Age;
	int		nMarks[CLASS_NUMBER];
	double	dAverage;
};

void init(Student* pStudentArr, int nSize)
{
	for (int i = 0; i < nSize; ++i)
	{
		int tmp = rand() % 14;
		memcpy(pStudentArr[i].sName, names_surname[tmp], NAME_SIZE);
		tmp = rand() % 14;
		memcpy(pStudentArr[i].sSurname, names_surname[tmp], NAME_SIZE);
		pStudentArr[i].Age = rand() % 25 + 17;
		pStudentArr[i].dAverage = 0.0;
		for (int j = 0; j < CLASS_NUMBER; ++j)
		{
			pStudentArr[i].nMarks[j] = rand() % 5;
			pStudentArr[i].dAverage += (double) pStudentArr[i].nMarks[j];
		}

		pStudentArr[i].dAverage /= CLASS_NUMBER;
	}
}

bool nameQualifierAsc(Student s1, Student s2)
{
	return strcmp(s1.sName, s2.sName) < 0;
}

bool nameQualifierDesc(Student s1, Student s2)
{
	return strcmp(s1.sName, s2.sName) > 0;
}

bool surnameQualifierAsc(Student s1, Student s2)
{
	return strcmp(s1.sSurname, s2.sSurname) < 0;
}

bool surnameQualifierDesc(Student s1, Student s2)
{
	return strcmp(s1.sSurname, s2.sSurname) > 0;
}

bool ageQualifierAsc(Student s1, Student s2)
{
	return s1.Age < s2.Age;
}

bool ageQualifierDesc(Student s1, Student s2)
{
	return s1.Age > s2.Age;
}

bool dAverageQualifierAsc(Student s1, Student s2)
{
	return s1.dAverage < s2.dAverage;
}

bool dAverageQualifierDesc(Student s1, Student s2)
{
	return s1.dAverage > s2.dAverage;
}

void sort(Student* pStudentArr, int nSize, bool(*qualifier)(Student, Student))
{
	Student nMin;
	int iMinInd;
	for (int i = 0; i < nSize; ++i)
	{
		nMin = pStudentArr[i];
		iMinInd = i;
		for (int j = i + 1; j < nSize; ++j)
		{
			if (qualifier(pStudentArr[j], nMin))
			{
				nMin = pStudentArr[j];
				iMinInd = j;
			}
		}
		pStudentArr[iMinInd] = pStudentArr[i];
		pStudentArr[i] = nMin;
	}
}
void show(Student* pStudentArr, int nSize)
{
	std::cout << std::endl;
	std::cout << "      Name    " << "  Surname    " << "Age    " << "Average Marks    " << std::endl;
	for (int i = 0; i < nSize; ++i)
	{
		std::cout << i + 1 << ".";
		std::cout << std::setw(NAME_SIZE);
		std::cout << pStudentArr[i].sName;
		std::cout << std::setw(NAME_SIZE);
		std::cout << pStudentArr[i].sSurname;
		std::cout << std::setw(8);
		std::cout << pStudentArr[i].Age;
		std::cout << std::setw(8);
		std::cout << pStudentArr[i].dAverage;
		std::cout << std::endl;
	}
}

int main()
{
	int nSize = 0;
	std::cout << "Enter number of students: ";
	std::cin >> nSize;
	Student* myclass = new Student[ nSize ];

	init( myclass, nSize );
	show(myclass, nSize);
	std::cout << std::endl;
	sort(myclass, nSize, ageQualifierAsc);
	show(myclass, nSize);
	delete[] myclass;
	return 0;
}