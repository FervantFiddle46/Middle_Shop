#include "Login and Password.hpp"
#include <string>
#include <iostream>
#include <Windows.h>





bool Login()
{
	std::string login, pass;

	while (true)
	{
		std::cout << "Введите логин";
		std::getline(std::cin,login, '\n');

		std::cout << "Введите пароль";
		std::getline(std::cin,pass, '\n');

		for (size_t i = 0; i < userSize; i++)
		{
			if (login == logArr[i] && pass == passArr[i])
			{
				std::cout << "Приятного пользования, " << logArr[i] << "\n";
				std::cout << "Ваш статус: " << userStatus[i] << "\n";
				currentStatus = userStatus[i];
				currentId = i;
				return true;
			}
		}
		std::cout << "Неверный логин или пароль. Потворите попытку\n\n";
		Sleep(1200);
		// to do exit to the programm

		
	}
}


void Start()
{
	SetConsoleOutputCP(1251);
	std::cout << "\n\n\n\t\t\tДобро пожаловать! :3\n\n\t\t\t Книжный магазин \"Литера\"";
	if (Login())
	{
		if (currentStatus == userStatus[0])
		{
			void SuperAdminMenu();
		}
		else if (currentStatus == userStatus[1])
		{

		}
		else if (currentStatus == userStatus[2])
		{

		}
		else
		{
			std::cerr << "_CURRENT_STATUS_LOGIN_ERROR_";
		}

	}
	else
	{
		// exit
	}
}

void SuperAdminMenu()
{
	std::string choose;
	while ()
	{
		std::cout << "1. Начать продажу\n";
		std::cout << "2. Показать склад\n";
		std::cout << "3. Пополнить товары\n";
		std::cout << "4. Списать товары\n";
		std::cout << "5. Изменить цены\n";
		std::cout << "6. Редактировать клад\n";
		std::cout << "7. Редактировать сотрудника\n";
		std::cout << "8. Отчёт о прибыли\n";
		std::cout << "0. Выйти из учётной записи\n";

		if (choose == "1")
		{

		}
		else if (choose == "2")
		{

		}
		else if (choose == "3")
		{

		}
		else if (choose == "4")
		{

		}
		else if (choose == "5")
		{

		}
		else if (choose == "6")
		{

		}
		else if (choose == "7")
		{

		}
		else if (choose == "8")
		{

		}
		else if (choose == "9")
		{

		}
		else if (choose == "0")
		{

		}
		else
		{

		}

	}
}
