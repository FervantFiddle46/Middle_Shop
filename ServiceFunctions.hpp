#ifndef _SELLINGSFUNCTIONS_HPP_
#define _SELLINGSFUNCTIONS_HPP_

#include <string>
#include <iostream>
#include <Windows.h>


//---------------------------------------- Проверка на число --------------------------------------


bool IsNumber(const std::string& str);



//---------------------------------------- Ввод строки --------------------------------------

inline void GetLine(std::string& str)
{
	std::getline(std::cin, str, '\n');
}


//---------------------------------------- Универсальная ошибка --------------------------------------

inline void Err(int mode = 0)
{
	std::cout << "Некорректный ввод\n";
	Sleep(1500);
	if (mode == 1)
	{
		system("cls");
	}

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

template <typename ArrType>
inline void ArrDeleteByIndex(ArrType*& arr, int arrSize, int index)
{
	arrSize--;
	ArrType* temp = new ArrType[arrSize];
	for (size_t i = 0, j = 0; i < arrSize; i++, j++)
	{
		if (index == j)
		{
			j++;
		}
		temp[i] = arr[j];
	}
	std::swap(arr, temp);
	delete[]temp;
}

#endif  
