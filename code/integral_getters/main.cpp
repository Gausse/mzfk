#include <iostream>
#include <conio.h>
#include <climits>
#include <stdlib.h>

#define MAX_INT_POS 12
#define MAX_DOUBLE_POS 25

void backspace()
{
	std::cout << (char) 8;
    std::cout << ' ';
    std::cout << (char) 8;
}

int get_int( char* hello_text, int max_num )
{
    int chr;
    int number_index = 0;
	int number_sign = 0;
    char number_str[ MAX_INT_POS ] = {0};
	
	std::cout << hello_text;
    while(true)
    {
    	chr = _getch();
		if ( chr == 13 )
		{
			number_str[number_index] = '\n';
			break;
		} else if ( number_index == 0 && chr == '-' )
		{
			number_sign = -1;
			number_str[number_index++] = (char)chr;
			std::cout << (char) chr;
		} else if ( chr >= '0' && chr <= '9' && max_num > (number_index + number_sign) )
    	{
    		std::cout << (char) chr;
    		number_str[number_index++] = (char) chr;
    	} else if ( chr == 8 && number_index != 0 )
    	{
			backspace();
			if (number_str[number_index] == '-')
			{
				number_sign = 0;
			}
    		number_str[number_index--] = 0;
    	}
    }
	std::cout << std::endl;
	return atoi(number_str);
}

double get_double(char* hello_text, int max_num)
{
	int chr;
	int number_index = 0;
	int number_sign = 0;
	char number_str[MAX_DOUBLE_POS] = { 0 };
	bool dot = false;
	std::cout << hello_text;
	while (true)
	{
		chr = _getch();
		if (chr == 13)
		{
			number_str[number_index] = '\n';
			break;
		}
		else if (chr == '.' && !dot)
		{
			number_str[number_index++] = (char)chr;
			std::cout << (char)chr;
		}
		else if (number_index == 0 && chr == '-')
		{
			number_sign = -1;
			number_str[number_index++] = (char)chr;
			std::cout << (char)chr;
		}
		else if (chr >= '0' && chr <= '9' && max_num > (number_index + number_sign))
		{
			std::cout << (char)chr;
			number_str[number_index++] = (char)chr;
		}
		else if (chr == 8 && number_index != 0)
		{
			backspace();
			if (number_str[number_index] == '-')
			{
				number_sign = 0;
			}
			else if (number_str[number_index] == '.')
			{
				dot = false;
			}
			number_str[number_index--] = 0;
		}
	}
	std::cout << std::endl;
	return atof(number_str);
}

int main()
{
	//char* intro = "Type in int with max length 10 symbols : ";
 //   int a = get_int( intro, 10 );
	//std:: cout << "My int " << a << std:: endl;
	char* intro_2 = "Type in double with max length 10 symbols : ";
	double b = get_double(intro_2, 25);
	std::cout << "My double " << b << std::endl;
    return 0;
}
