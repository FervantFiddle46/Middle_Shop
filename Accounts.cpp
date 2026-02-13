#include "Accounts.hpp"

size_t userSize = 3;
std::string currentStatus;
unsigned int currentId = 0;
std::string* logArr = new std::string[userSize]{ "admin", "user1", "user2" };
std::string* passArr = new std::string[userSize]{ "admin", "user1", "user2" };
std::string* userStatus = new std::string[userSize]{ "SuperAdmin", "Admin", "User" };
double* awardArr = new double[userSize] {};
double* fineArr = new double[userSize] {};
unsigned int* userId = new unsigned int[userSize] {0, 1, 2};
bool isSetCreated = false;

std::unordered_set<char> loginSymbols;
std::unordered_set<char> passSymbols;
unsigned int maxLogin = 20;
unsigned int maxPass = 20;
unsigned int minLogin = 5;
unsigned int minPass = 8;

//---------------------------------------- Изменение аккаунтов --------------------------------------

void ChangeAccounts()
{
	if (!isSetCreated)
	{
		CreateSet();
	}

	std::string choose;
	while (true)
	{
		system("cls");
		std::cout << "1 - Создать новый аккаунт\n";
		std::cout << "2 - Показать всех сотрудников\n";
		std::cout << "3 - Изменить логин\n";
		std::cout << "4 - Изменить пароль\n";
		std::cout << "5 - Изменить уровень доступа\n";
		std::cout << "6 - Редактировать профиль сотрудника\n";
		std::cout << "7 - Удалить аккаунт\n";
		std::cout << "0 - Выход\n\n";
		std::cout << "Ввод: ";
		GetLine(choose);
		if (choose == "1")
		{
			CreateNewUser();
		}
		else if (choose == "2")
		{
			if (currentStatus == userStatus[1])
			{
				ShowUser();
			}
			else if (currentStatus == userStatus[0])
			{
				ShowUser(1);
			}
			system("pause");
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
		else if (choose == "0")
		{
			std::cout << "Выход из редактора учётных записей\n";
			Sleep(1500);
			break;
		}
		else
		{
			Err();
		}
	}
}

void CreateNewUser()
{
	std::string choose, chooseLogin, choosePass, chooseStatus;
	bool isExit = true;
	while (true)
	{
		while (true)
		{
			isExit = true;
			system("cls");
			std::cout << "Введите логин для регистрации нового пользователя / \"exit\" для выхода\n\nВвод: ";
			GetLine(chooseLogin);
			if (chooseLogin == "exit")
			{
				std::cout << "Отмена создания нового пользователя\n";
				isExit = false;
				Sleep(1500);
				break;
			}

			if (CheckLogin(chooseLogin))
			{
				break;
			}

		}

		while (isExit)
		{
			system("cls");
			std::cout << "Введите пароль / \"exit\" для выхода\n\nВвод: ";
			GetLine(choosePass);
			if (choosePass == "exit")
			{
				std::cout << "Отмена создания нового пользователя\n";
				isExit = false;
				Sleep(1500);
				break;
			}

			if (CheckPass(choosePass))
			{
				break;
			}
		}

		while (isExit)
		{
			system("cls");
			std::cout << "Введите уровень доступа для нового пользователя / \"exit\" для выхода\n\n";
			std::cout << "1 - Сотрудник\n";
			std::cout << "2 - Администратор\n";
			std::cout << "Ввод: ";
			GetLine(choose);
			if (choose == "exit")
			{
				std::cout << "Отмена создания нового пользователя\n";
				isExit = false;
				Sleep(1500);
				break;
			}

			if (choose == "1")
			{
				chooseStatus = "User";
			}
			else if (choose == "2")
			{
				std::cout << "\nВведите пароль супер-администратора для подтверждения: ";
				GetLine(choose);
				if (choose == passArr[0])
				{
					chooseStatus = "Administrator";
					break;
				}
				else
				{
					Err();
				}
			}
			else
			{
				Err();
			}

			
		}

		if (!isExit)
		{
			break;
		}
		else
		{
			system("cls");
			std::cout << "Логин: " << chooseLogin << "\n";
			std::cout << "Пароль: " << choosePass << "\n";
			std::cout << "Увровень доступа: " << chooseStatus << "\n\n";
			std::cout << "Подтвердить?\n1 - Да\n2 - Отмена\n\nВвод: ";
			GetLine(choose);
			if (choose == "1")
			{
				ArrPushBack(logArr, userSize);
				ArrPushBack(passArr, userSize);
				ArrPushBack(userStatus, userSize);
				ArrPushBack(awardArr, userSize);
				ArrPushBack(fineArr, userSize);
				ArrPushBack(userId, userSize);
				userSize++;
				userId[userSize - 1] = userSize - 1;
				awardArr[userSize - 1] = 0;
				fineArr[userSize - 1] = 0;
				logArr[userSize - 1] = chooseLogin;
				passArr[userSize - 1] = choosePass;
				userStatus[userSize - 1] = chooseStatus;

				std::cout << "Пользователь успешно создан!\n\n";
				Sleep(1700);
				break;
			}
			else if (choose == "2")
			{
				std::cout << "Отмена создания нового пользователя!\n";
				Sleep(1500);
				break;
			}
			else
			{
				Err();
			}

		}
	}
}



//---------------------------------------- 1. Создание нового аккаунта --------------------------------------

	


//---------------------------------------- 2. Показ пользователей --------------------------------------

void ShowUser(int mode)
{
	system("cls");
	if (mode == 0)
	{
		std::cout << "ID" << "\tЛогин\t" << std::left << std::setw(maxLogin + 15)
			<< "\t\tПароль" << "\n";

		for (size_t i = 1; i < userSize; i++)
		{
			std::cout << userId[i] << "\t" << std::left << std::setw(maxLogin) << logArr[i]
				<< "\t" << passArr[i] << "\n";

		}
	}
	else if (mode == 1)
	{
		std::cout << "ID" << "\tЛогин\t" << std::left << std::setw(maxLogin + 15)
			<< "\t\tПароль" << "\n";

		for (size_t i = 0; i < userSize; i++)
		{
			std::cout << userId[i] << "\t" << std::left << std::setw(maxLogin) << logArr[i]
				<< "\t" << passArr[i] << "\n";

		}
	}
}



//---------------------------------------- Проверка логина на символы --------------------------------------

bool CheckLogin(const std::string& chooseLogin)
{
	if (chooseLogin.size() < minLogin || chooseLogin.size() > maxLogin)
	{
		std::cout << "\nОшибка длины логина! От " << minLogin << " до " << maxLogin << " символов\n";
		Sleep(1500);
		return false;
	}
	else
	{
		for (size_t i = 0; i < chooseLogin.size(); i++)
		{
			if (!loginSymbols.count(chooseLogin[i]))
			{
				std::cout << "Ваш логин содержит некорректные символы. Допустимые символы: A-Z, a-z, 0-9\n\n";
				Sleep(2000);
				return false;
			}
		}
	}


	for (size_t i = 0; i < userSize; i++)
	{
		if (chooseLogin == logArr[i])
		{
			std::cout << "Такой пользователь уже создан\n";
			Sleep(1500);
			return false;
		}
	}

	return true;

}



//---------------------------------------- Проверка пароля на символы --------------------------------------

bool CheckPass(const std::string& choosePass)
{
	int symbolCount = 0, maxSymbols = 3, numberCount = 0, maxNumber = 3, letterCount = 0, maxLetter = 3;
	if (choosePass.size() < minLogin || choosePass.size() > maxPass)
	{
		std::cout << "Ошибка длины пароля! От " << minPass << " до " << maxPass << "\n";
		Sleep(1500);
		return false;
	}
	else
	{
		for (size_t i = 0; i < choosePass.size(); i++)
		{
			if (!passSymbols.count(choosePass[i]))
			{
				std::cout << "Некорретный пароль. Допустимые символы: A-Z, a-z, 0-9 и стандартные символы\n\n";
				Sleep(2000);
				return false;
			}
			else if (std::isdigit(choosePass[i]))
			{		
				numberCount++;
			}
			else if (choosePass[i] >= 'A' && choosePass[i] <= 'Z' || choosePass[i] >= 'a' && choosePass[i] <= 'z')
			{
				letterCount++;
			}
			else
			{
				symbolCount++;
			}
		}
	}

	if (numberCount >= maxNumber && letterCount >= maxLetter && symbolCount >= maxSymbols)
	{
		return true;
	}
	else
	{
		std::cout << "\nСлишком простой пароль\n";
		std::cout << "Минимум " << maxLetter << " букв, " << maxNumber << " цифры, " << maxSymbols << " символа в пароле\n";
		Sleep(2000);
		return false;
	}
}



//---------------------------------------- Создание сета логинов и паролей --------------------------------------

void CreateSet()
{
	if (isSetCreated)
	{
		return;
	}
	else
	{
		isSetCreated = true;
		for (char i = '0'; i <= '9'; i++)
		{
			loginSymbols.insert(i);
		}
		for (char i = 'A'; i <= 'Z'; i++)
		{
			loginSymbols.insert(i);
		}
		for (char i = 'a'; i <= 'z'; i++)
		{
			loginSymbols.insert(i);
		}


		for (char i = '!'; i <= '}'; i++)
		{
			passSymbols.insert(i);
		}

	}
}
