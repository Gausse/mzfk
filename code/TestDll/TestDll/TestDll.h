// The following ifdef block is the standard way of creating macros which make exporting 
// from a DLL simpler. All files within this DLL are compiled with the TESTDLL_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see 
// TESTDLL_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#ifdef TESTDLL_EXPORTS
#define TESTDLL_API __declspec(dllexport)
#else
#define TESTDLL_API __declspec(dllimport)
#endif

// This class is exported from the TestDll.dll
class TESTDLL_API CTestDll {
public:
	CTestDll(void);
	// TODO: add your methods here.
};

extern TESTDLL_API int nTestDll;

TESTDLL_API int fnTestDll(void);

class BaseFactory
{
public:
	virtual void show() = 0;
	virtual void destroy() = 0;
};

class Flowers : public BaseFactory
{
	char* field;
public:
	Flowers() : field("Flowers") 
	{
		std::cout << "Flowers constr this=" << this << std::endl;
	}

	~Flowers()
	{
		std::cout << "Flowers destr this=" << this << std::endl;
	}

	void show()
	{
		std::cout << field << std::endl;
	}

	void destroy()
	{
		delete this;
	}

};

extern "C" TESTDLL_API BaseFactory* getFactory(char* pCategoryName);

extern "C" TESTDLL_API int Mult(int a, int b);
