#ifndef _SELLINGSFUNCTIONS_HPP_
#define _SELLINGSFUNCTIONS_HPP_

#include <string>
#include <iostream>
#include <Windows.h>

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

template<typename ArrType>
void ArrPushBack(ArrType*& arr, int arrSize);

#endif 
