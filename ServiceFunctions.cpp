#include "ServiceFunctions.hpp"

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
		if (!std::isdigit(str[i]))
		{
			std::cout << "Введённые данные не являются числом\n";
			Sleep(1500);
			return false;
		}
	}
	return true;
}


//---------------------------------------- Шаблонная функция для добавления элемента в конец массива --------------------------------------

template<typename ArrType>
inline void ArrPushBack(ArrType*& arr, int arrSize)
{
	arrSize++;
	ArrType* temp = new ArrType[arrSize];
	for (size_t i = 0; i < arrSize - 1; i++)
	{
		temp[i] = arr[i];
	}
	std::swap(arr, temp);
	delete[]temp;

}
