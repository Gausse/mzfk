#include <iostream>
#include <conio.h>
#include <climits>
#include <stdlib.h>

#define MAX_INT_POS 11

void backspace()
{
	std::cout << (char) 8;
    std::cout << ' ';
    std::cout << (char) 8;
}

int pow(int power)
{
	int result = 1;
	for( int i = 0; i < power; ++i )
		result *= 10;
	return result;
}

//int atoi(char number_str[])
//{
//	int result = 0;
//	for(int index = 0, power = strlen(number_str) - 2, len = strlen(number_str) - 1; index < len; ++index, --power )
//	{
//		long long tmp = result + (number_str[index] - 48) * pow(power);
//		if (tmp < INT_MAX)
//			result += (number_str[index] - 48) * pow(power);
//		else
//			return 0;
//	}
//	return result;
//}

int get_int( char* hello_text, int max_num )
{
    int chr;
    int number_index = 0;
	int number_sign = 1;
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
			std::cout << (char) chr;
		} else if ( chr >= '0' && chr <= '9' && max_num > number_index )
    	{
    		std::cout << (char) chr;
    		number_str[number_index++] = (char) chr;
    	} else if ( chr == 8 && number_index != 0 )
    	{
			backspace();
    		number_str[number_index--] = 0;
    	} else if ( chr == 8 && number_index == 0 && number_sign == -1 )
		{
			backspace();
			number_sign = 1;
		}
    }
	std::cout << std::endl;
	return number_sign * atoi(number_str);
}

int main()
{
	int ten = pow(2);
	char* intro = "Type in int with max length 10 symbols : ";
    int a = get_int( intro, 10 );
	std:: cout << "My int " << a << std:: endl;
    return 0;
}
