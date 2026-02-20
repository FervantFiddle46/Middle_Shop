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
		std::cout << "6 - Редактировать премии и штрафы\n";
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
			if (currentStatus == "Admin")
			{
				ShowUser();
			}
			else if (currentStatus == "SuperAdmin")
			{
				ShowUser(1);
			}
			system("pause");
		}
		else if (choose == "3")
		{
			ChangeLogin();
		}
		else if (choose == "4")
		{
			ChangePass();
		}
		else if (choose == "5")
		{
			if (userSize > 1)
			{
				ChangeStatus();
			}
			else
			{
				std::cout << "Нет доступных пользователей\n";
				Sleep(1500);
			}
		}
		else if (choose == "6")
		{
			if (userSize > 1)
			{
				ChangeAwards();
			}
			else
			{
				std::cout << "Нет доступных пользователей\n";
				Sleep(1500);
			}
		}
		else if (choose == "7")
		{
			if (userSize > 1)
			{
				DeleteUser();
			}
			else
			{
				std::cout << "Нет доступных пользователей\n";
				Sleep(1500);
			}
		}
		else if (choose == "0")
		{
			std::cout << "\nВыход из редактора учётных записей\n";
			Sleep(1500);
			break;
		}
		else
		{
			Err();
		}
	}
}






//---------------------------------------- 1. Создание нового аккаунта --------------------------------------


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
				break;
			}
			else if (choose == "2")
			{
				std::cout << "\nВведите пароль супер-администратора для подтверждения: ";
				GetLine(choose);
				if (choose == passArr[0])
				{
					chooseStatus = "Admin";
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




//---------------------------------------- 2. Показ пользователей --------------------------------------

void ShowUser(int mode)
{
	system("cls");
	std::cout << "ID" << "\tЛогин\t" << std::left << std::setw(maxLogin - 2)
		<< "\t\tПароль" << "\tРоль" << "\t\t\tСумма продаж" << "\t\tШтрафы" << "\n";
	if (mode == 0)
	{
		for (size_t i = 1; i < userSize; i++)
		{
			std::cout << userId[i] << "\t" << std::left << std::setw(maxLogin) << logArr[i]
				<< "\t" << std::setw(maxPass / 1.5) << passArr[i] << "\t\t" << std::setw(maxLogin) << userStatus[i] << "\t"
				<< awardArr[i] << "\t\t\t" << fineArr[i] << "\n";
		}
	}
	else if (mode == 1)
	{
		for (size_t i = 0; i < userSize; i++)
		{
			std::cout << userId[i] << "\t" << std::left << std::setw(maxLogin) << logArr[i]
				<< "\t" << std::setw(maxPass / 1.5) << passArr[i] << "\t\t" << std::setw(maxLogin) << userStatus[i] << "\t" 
				<< awardArr[i] << "\t\t\t" << fineArr[i] << "\n";

		}
	}

	else if (mode == 2)
	{
		system("cls");
		std::cout << "ID" << "\tЛогин\t" << std::left << std::setw(maxLogin + 15)
			<< "\t\tРоль" << "\n";
		for (size_t i = 1; i < userSize; i++)
		{
			std::cout << userId[i] << "\t" << std::left << std::setw(maxLogin) << logArr[i]
				<< "\t" << userStatus[i] << "\n";

		}
	}

	else if (mode == 3)
	{
		system("cls");
		std::cout << "ID" << "\tЛогин\t" << std::left << std::setw(maxLogin + 7)
			<< "\t\t\tКоличество продаж" << "\tШтрафы" << "\n";
		for (size_t i = 1; i < userSize; i++)
		{
			std::cout << userId[i] << "\t" << std::left << std::setw(maxLogin) << logArr[i]
				<< "\t\t" << awardArr[i] << "\t\t\t\t" << fineArr[i] << "\n";

		}
	}

	else if (mode == 4)
	{
		system("cls");
		std::cout << "ID" << "\tЛогин\t" << std::left << std::setw(maxLogin + 7)
			<< "\t\t\tКоличество продаж" << "\tШтрафы" << "\n";
		for (size_t i = 1; i < userSize; i++)
		{
			if (userStatus[i] == "User")
			{
				std::cout << userId[i] << "\t" << std::left << std::setw(maxLogin) << logArr[i]
					<< "\t\t" << awardArr[i] << "\t\t\t\t" << fineArr[i] << "\n";
			}
			

		}
	}
}







//---------------------------------------- 3. Изменение логина --------------------------------------


void ChangeLogin()
{
	std::string chooseId, chooseLogin, choose;
	int id = 0, isSuperAdmin = 0;
	while (true)
	{
		if (currentStatus == "Admin")
		{
			ShowUser();
			isSuperAdmin = 1;
		}
		else if (currentStatus == "SuperAdmin")
		{
			ShowUser(1);
			isSuperAdmin = 0;
		}
		
		std::cout << "\nВведите ID пользователя или \"exit\" для выхода\n\nВвод: ";
		GetLine(chooseId);
		if (chooseId == "exit")
		{
			std::cout << "Отмена изменения логина\n\n";
			Sleep(1500);
			break;
		}
		else if (IsNumber(chooseId))
		{
			id = std::stoi(chooseId);
			if (id < isSuperAdmin || id > userSize - 1)
			{
				Err();
			}
			else
			{
				std::cout << "Придумайте новый логин: ";
				GetLine(chooseLogin);
				if (CheckLogin(chooseLogin))
				{
					system("cls");
					std::cout << logArr[id] << " ------> " << chooseLogin << "\n\n";
					std::cout << "Подтвердить?\n1 - Да\n2 - Нет\n\nВвод: ";
					GetLine(choose);
					if (choose == "1")
					{
						logArr[id] = chooseLogin;
						std::cout << "Логин успешно изменён\n";
						Sleep(1500);
						break;
					}
					else if (choose == "2")
					{
						std::cout << "Отмена\n";
						Sleep(1500);
					}
					else
					{
						Err();
					}
				}
			}
		}
	}
}





//---------------------------------------- 4. Изменение пароля --------------------------------------

void ChangePass()
{
	std::string chooseId, choosePass, choose, currentPass, verifyPass;
	int id = 0, isSuperAdmin = 0;
	while (true)
	{
		if (currentStatus == "Admin")
		{
			ShowUser();
			isSuperAdmin = 1;
		}
		else if (currentStatus == "SuperAdmin")
		{
			ShowUser(1);
			isSuperAdmin = 0;
		}

		std::cout << "\nВведите ID пользователя или \"exit\" для выхода\n\nВвод: ";
		GetLine(chooseId);
		if (chooseId == "exit")
		{
			std::cout << "Отмена изменения пароля\n\n";
			Sleep(1500);
			break;
		}
		else if (IsNumber(chooseId))
		{
			id = std::stoi(chooseId);
			if (id < isSuperAdmin || id > userSize - 1)
			{
				Err();
			}
			else
			{
				system("cls");
				std::cout << "Введите текущий пароль: ";
				GetLine(currentPass);
				std::cout << "Придумайте новый пароль: ";
				GetLine(choosePass);
				std::cout << "Подтвердите новый пароль: ";
				GetLine(verifyPass);

				if (currentPass != passArr[id])
				{
					std::cout << "Ошибка пароля\n";
					Sleep(1500);
					continue;
				}

				if (choosePass == verifyPass)
				{
					if (CheckPass(choosePass))
					{
						system("cls");
						std::cout << passArr[id] << " ------> " << choosePass << "\n\n";
						std::cout << "Подтвердить?\n1 - Да\n2 - Нет\n\nВвод: ";
						GetLine(choose);
						if (choose == "1")
						{
							passArr[id] = choosePass;
							std::cout << "Пароль успешно изменён\n";
							Sleep(1500);
							break;
						}
						else if (choose == "2")
						{
							std::cout << "Отмена\n";
							Sleep(1500);
						}
						else
						{
							Err();
						}
					}
				}
				else
				{
					std::cout << "Пароли не совпадают\n";
					Sleep(1500);
				}

			
			}
		}
	}
}






//---------------------------------------- 5. Изменение уровня доступа --------------------------------------


void ChangeStatus()
{
	std::string chooseId, chooseStatus, choose;
	int id = 0, isSuperAdmin = 0;
	while (true)
	{
		ShowUser(2);

		std::cout << "\nВведите ID пользователя или \"exit\" для выхода\n\nВвод: ";
		GetLine(chooseId);
		if (chooseId == "exit")
		{
			std::cout << "Отмена изменения роли\n\n";
			Sleep(1500);
			break;
		}
		else if (IsNumber(chooseId))
		{
			id = std::stoi(chooseId);
			if (id < 1 || id > userSize - 1)
			{
				Err();
			}
			else
			{
				system("cls");
				std::cout << "Введите новый уровень доступа для пользователя / \"exit\" для выхода\n\n";
				std::cout << "1 - Сотрудник\n";
				std::cout << "2 - Администратор\n";
				std::cout << "Ввод: ";
				GetLine(choose);
				if (choose == "exit")
				{
					std::cout << "Отмена изменения уровня доступа\n";
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
						chooseStatus = "Admin";
					}
					else
					{
						Err();
						continue;
					}
				}
				else
				{
					Err();
					continue;
				}

				std::cout << "\n" << userStatus[id] << " ------> " << chooseStatus << "\n\n";
				std::cout << "Подтвердить?\n1 - Да\n2 - Нет\n\nВвод:";
				GetLine(choose);
				if (choose == "1")
				{
					userStatus[id] = chooseStatus;
					std::cout << "Успешно!\n";
					Sleep(1500);
					break;
				}
				else if (choose == "2")
				{
					std::cout << "Отмена\n";
					Sleep(1500);
				}
				else
				{
					Err();
				}
			}
		}
	}
}






//---------------------------------------- 6. Редактировать премий и штрафов --------------------------------------


void ChangeAwards()
{
	std::string chooseId, chooseSum, choose;
	int id = 0, isSuperAdmin = 0;
	double sum = 0.0;
	while (true)
	{
		system("cls");
		if (currentStatus == "SuperAdmin")
		{
			std::cout << "\nВведите пароль супер-администратора для подтверждения: ";
			GetLine(choose);
			if (choose == passArr[0])
			{
				isSuperAdmin = 0;
				ShowUser(3);
			}
			else
			{
				Err();
				break;
			}
		}

		else if (currentStatus == "Admin")
		{
			std::cout << "\nВведите свой пароль дял подтверждения: ";
			GetLine(choose);
			if (choose == passArr[currentId])
			{
				isSuperAdmin = 1;
				ShowUser(4);
			}
			else
			{
				Err();
				break;
			}
		}


		ShowUser(3);

		std::cout << "\nВведите ID пользователя или \"exit\" для выхода\n\nВвод: ";
		GetLine(chooseId);
		if (chooseId == "exit")
		{
			std::cout << "Отмена редактирвоания премий и штрафов\n\n";
			Sleep(1500);
			break;
		}
		else if (IsNumber(chooseId))
		{
			id = std::stoi(chooseId);
			if (id < 1 || id > userSize - 1)
			{
				Err();
			}
			else
			{
				if (currentStatus == "Admin" && userStatus[id] != "User")
				{
					std::cout << "Некорректный пользователь\n";
					Sleep(1500);
					continue;
				}

				system("cls");
				std::cout << "Выберите пункт меню / \"exit\" для выхода\n\n";
				std::cout << "1 - Изменить сумму продаж\n";
				std::cout << "2 - Изменить сумму штрафов\n";
				std::cout << "Ввод: ";
				GetLine(choose);
				if (choose == "exit")
				{
					std::cout << "Отмена редактирования премиф и штрафов\n";
					Sleep(1500);
					break;
				}

				if (choose == "1")
				{
					while (true)
					{
						system("cls");
						std::cout << "Введите сумму продаж / \"exit\" для выхода\n\nВвод: ";
						GetLine(chooseSum);
						if (chooseSum == "exit")
						{
							std::cout << "Отмена редактирования суммы продаж\n\n";
							Sleep(1500);
							break;
						}

						if (IsNumber(chooseSum))
						{
							sum = std::stod(chooseSum);
							if (sum < 5 || sum > MAXINT)
							{
								std::cout << "Ошибка! Максимальная сумма: " << MAXINT << " рублей\n\n";
								Sleep(1500);
							}
							else
							{
								awardArr[id] = sum;
								std::cout << "Успешно!\n";
								Sleep(1500);
								return;
							}
						}
						else
						{
							Err();
						}
					}
				}

				else if (choose == "2")
				{

					{
						while (true)
						{
							system("cls");
							std::cout << "Введите сумму штрафов / \"exit\" для выхода\n\nВвод: ";
							GetLine(chooseSum);
							if (chooseSum == "exit")
							{
								std::cout << "Отмена редактирования штрафов\n\n";
								Sleep(1500);
								break;
							}

							if (IsNumber(chooseSum))
							{
								sum = std::stod(chooseSum);
								if (sum < 5 || sum > 25000)
								{
									std::cout << "Ошибка! Максимальная сумма: " << 25000 << " рублей\n\n";
									Sleep(1500);
								}
								else
								{
									fineArr[id] = sum;
									std::cout << "Успешно!\n";
									Sleep(1500);
									return;
								}
							}
							else
							{
								Err();
							}
						}
					}
				}

				else
				{
					Err();
					continue;
				}
			}
		}
	}
}






//---------------------------------------- 7. Удалить аккаунтя --------------------------------------

void DeleteUser()
{
	std::string chooseId, choose;
	int id = 0;
	while (true)
	{
		ShowUser(2);

		std::cout << "\nВведите ID пользователя или \"exit\" для выхода\n\nВвод: ";
		GetLine(chooseId);
		if (chooseId == "exit")
		{
			std::cout << "Отмена удаления пользователя\n\n";
			Sleep(1500);
			break;
		}
		else if (IsNumber(chooseId))
		{
			id = std::stoi(chooseId);
			if (id < 1 || id > userSize - 1)
			{
				Err();
			}
			else if (id == currentId)
			{
				std::cout << "Нельзя удалять себя\n";
			}
			else
			{
				std::cout << "Удалить пользователя " << logArr[id] << "?\n";
				std::cout << "Для подтверждения введите пароль супер-администратора / \"exit\" для выхода\n\nВвод: ";
				GetLine(choose);
				if (choose == "exit")
				{
					std::cout << "Отмена\n\n";
					Sleep(1500);
				}
				else if (choose == passArr[0])
				{
					if (id < currentId)
					{
						--currentId;
					}

					ArrDeleteByIndex(logArr, userSize, id);
					ArrDeleteByIndex(passArr, userSize, id);
					ArrDeleteByIndex(userStatus, userSize, id);
					ArrDeleteByIndex(awardArr, userSize, id);
					ArrDeleteByIndex(fineArr, userSize, id);
					--userSize;
					for (size_t i = 0; i < userSize; i++)
					{
						userId[i] = i;
					}

					std::cout << "\nИдёт процесс удаления...\n";
					Sleep(750);
					std::cout << "Сверяем аккаунты...\n";
					Sleep(750);
					std::cout << "Почти справились...\n\n";
					Sleep(750);
					std::cout << "Пользователь удалён!\n";
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
