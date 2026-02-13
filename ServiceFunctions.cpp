#include "ServiceFunctions.hpp"



//---------------------------------------- Проверка на число --------------------------------------


bool IsNumber(const std::string& str)
{
	if (str.size() <= 0 || str.size() >= 10)
	{
		std::cout << "Ошибка длины. Максимум 9-значные числа\n";
		Sleep(1500);
		return false;
	}

	for (size_t i = 0; i < str.size(); i++)
	{
		if (!std::isdigit(static_cast<unsigned char>(str[i])))
		{
			std::cout << "Введённые данные не являются числом\n";
			Sleep(1500);
			return false;
		}
	}
	return true;
}




