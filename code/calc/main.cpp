#include <iostream>

enum state {
	CALC_OK = 0,
	CALC_WRONG_OPERATOR,
	CALC_ZERO_DIVISION
};

int status = 0;

int mult(int op1, int op2)
{
	status = (int) CALC_OK;
	return op1 * op2;
}

int sum(int op1, int op2)
{
	status = (int) CALC_OK;
	return op1 + op2;
}

int subt(int op1, int op2)
{
	status = (int) CALC_OK;
	return op1 - op2;
}

int division(int op1, int op2)
{
	if (op2 == 0)
	{
		status = (int) CALC_ZERO_DIVISION;
		return 0;
	}
	else 
	{
		status = (int) CALC_OK;
	}

	return op1 / op2;
}

int main()
{
	int op1 = 0;
	int op2 = 0;
	char operation_symbol;

	int(*ops[6])(int, int) = { mult, sum, 0, subt, 0, division };
	std::cout << "Type first operand: ";
	std::cin >> op1;
	std::cout << "Type second operand: ";
	std::cin >> op2;
	std::cout << "Type operation: ";
	std::cin >> operation_symbol;

	int res;
	switch (operation_symbol)
	{
		case '*':
		case '+':
		case '-':
		case '/':
			res = ops[operation_symbol - '*'](op1, op2);
			break;
		default:
			status = (int) CALC_WRONG_OPERATOR;
			break;
	}

	std::cout << std::endl;
	std::cout << "Result is : " << res << std::endl;
	switch (status)
	{
	case 0:
		std::cout << "Calc worked ok." << std::endl;
		break;
	case 1:
		std::cout << "Input wrong operator." << std::endl;
		break;
	case 2:
		std::cout << "Division by zero." << std::endl;
		break;
	}


	return 0;
}