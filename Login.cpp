#include "Login.hpp"



//---------------------------------------- Проверка логина и пароля --------------------------------------

bool Login()
{
	std::string login, pass;

	while (true)
	{
		std::cout << "\n\nВведите логин: ";
		GetLine(login);

		std::cout << "\nВведите пароль: ";
		GetLine(pass);

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




//---------------------------------------- Приветствие --------------------------------------

void Start()
{
	SetConsoleOutputCP(1251);
	std::cout << "\n\n\n\t\t\tДобро пожаловать! :3\n\n\t\t\t Книжный магазин \"Литера\"";
	if (Login())
	{
		if (currentStatus == userStatus[0])
		{
			CreateStorage();
			SuperAdminMenu();
		}
		else if (currentStatus == userStatus[1])
		{
			std::cout << "2\n\n";
		}
		else if (currentStatus == userStatus[2])
		{
			std::cout << "3\n\n";
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



//---------------------------------------- Меню супер-админа --------------------------------------

void SuperAdminMenu()
{
	std::string choose;
	while (true)
	{
		system("cls");
		std::cout << "1. Начать продажу\n";
		std::cout << "2. Показать склад\n";
		std::cout << "3. Пополнить товары\n";
		std::cout << "4. Списать товары\n";
		std::cout << "5. Изменить цены\n";
		std::cout << "6. Редактировать клад\n";
		std::cout << "7. Редактировать сотрудника\n";
		std::cout << "8. Отчёт о прибыли\n";
		std::cout << "0. Выйти из учётной записи\n\n";
		std::cout << "Ввод: ";
		std::getline(std::cin, choose, '\n');

		if (choose == "1")
		{

		}
		else if (choose == "2")
		{
			ShowStorage();
		}
		else if (choose == "3")
		{
			AddProduct();
		}
		else if (choose == "4")
		{
			RemoveProduct();
		}
		else if (choose == "5")
		{
			ChangePrice();
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


