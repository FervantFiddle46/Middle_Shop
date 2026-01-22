

#include "Login and Password.cpp"

size_t userSize = 3;
std::string currentStatus;
unsigned int currentId = 0;
std::string * logArr = new std::string[userSize]{ "admin", "user1", "user2" };
std::string * passArr = new std::string[userSize]{ "admin", "user1", "user2" };
std::string * userStatus = new std::string[userSize]{ "SuperAdmin", "Admin", "User" };
double * awardArr = new double[userSize] {};
double * fineArr = new double[userSize] {};
unsigned int * userId = new unsigned int[userSize] {1, 2, 3};



int main()
{
	Start();
	
	delete[] logArr;
	delete[] passArr;
	delete[] userStatus;
	delete[] awardArr;
	delete[] userId;








	std::cout << "\n\n\n\n\n\n";
	system("pause");
	return 0;
}



/*
	Планы:
	
	Система продажи
	Учетные записи: сотрудник, администратор, супер администратотр
	Система авторизации
	Основное меню: склад, продажи, пополнить склад, списать со склада, изменить цену, редактирование склада (изменение названия товраа, удаление товара, добавление типа товара)
	Редактор учетных записей: добавление сотрудника, редактирование сотрудника, удалить сотрудника
	Отчет о прибыли. Премии
	Закрытие смены
	Счётчик покупателей
	Система штрафов
	Личный кабинет пользователя

	Условия выполнения:

	NoIntJanuary
	Нейминг, деление на файлы и функции, проверка на ввод


	Файлы cpp/hpp:

	1) Main
	2) Storage.cpp (склад)
	3) Accounts.cpp (учетные записи сотрудников)
	4) Sellings.cpp (продажи, скидки, акции)
	5) ServiceFunction.сзз (функции)
	6) Login.cpp


	Бибилиотеки:

	iostream
	Windows.h
	iomanip
	string
	cstdlib


*/


