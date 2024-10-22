#include<iostream>
#include<string>


class Calculator {
	enum Operations
	{
		Adding,
		Subtracting,
		Multpling,
		Dividing,
		Result
	};

	std::string _setOperation(Operations opt) {
		switch (opt)
		{
		case Operations::Adding:
			return "Adding";
			break;
		case Operations::Subtracting:
			return "Subtracting";
			break;
		case Operations::Multpling:
			return "Multpling";
			break;
		case Operations::Dividing:
			return "Dividing";
			break;
		default:
			return "Result";
			break;
		}
	}
	int _flipZeroToOne(int number) {
		if (number == 0) return 1;
		return number;
	}
	int _result = 0;
	int _operand = 0;

	std::string _operation = _setOperation(Operations::Adding);
public:
	void Clear() {
		_result = 0;
		_operand = 0;
	}
	void Add(int number) {
		_result += number;
		_operation = _setOperation(Operations::Adding);
		_operand = number;
	}
	void Subtract(int number) {
		_result -= number;
		_operation = _setOperation(Operations::Subtracting);
		_operand = number;
	}
	void Multplie(int number) {
		_result *= number;
		_operation = _setOperation(Operations::Multpling);
		_operand = number;
	}

	void Divide(int number) {
		number = _flipZeroToOne(number);
		_result /= number;
		_operation = _setOperation(Operations::Dividing);
		_operand = number;
	}
	void PrintResult() {
		std::cout << "Result After " << _operation << " " << _operand << " is : " << _result << "\n";
	}

};

int main() {
	Calculator calculator;

	calculator.Clear();
	calculator.Add(10);
	calculator.PrintResult();
	calculator.Subtract(2);
	calculator.PrintResult();
	calculator.Multplie(3);
	calculator.PrintResult();
	calculator.Divide(0);
	calculator.PrintResult();
	return 0;
}