#include <windows.h>
#include <iostream>
#include <memory>

class BaseFactory
{
public:
	virtual void show() = 0;
	virtual void destroy() = 0;
};

void deleter(BaseFactory* obj)
{
	obj->destroy();
}

int main()
{
	HMODULE hMod = LoadLibrary(L"TestDll.dll");

	if (hMod == NULL)
	{
		std::cout << "Sorry, nothing to do here!" << std::endl;
		return 0;
	}

	typedef BaseFactory*(*getFlowersFactory)(char*);

	getFlowersFactory pFn = (getFlowersFactory)GetProcAddress(hMod, "getFactory");

	if (pFn == NULL)
	{
		std::cout << "Sorry, nothing to mult with." << std::endl;
		FreeLibrary(hMod);
		return 0;
	}
	{
		char buf[50];
		std::shared_ptr<BaseFactory> flower(pFn(buf), deleter);
		std::cout << buf << std::endl;
		flower->show();
	}

	return 0;
}