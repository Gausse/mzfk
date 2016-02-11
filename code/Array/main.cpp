#include "Array.h"

int main()
{
	Array my(10);

	for (int i = 0; i < 12; ++i)
	{
		my.push_back(i);
	}
	my.show();

	return 0;
}