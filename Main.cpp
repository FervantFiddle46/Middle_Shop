

#include "Login.hpp"



int main()
{
	Start();
	
	delete[] logArr;
	delete[] passArr;
	delete[] userStatus;
	delete[] awardArr;
	delete[] fineArr;
	delete[] userId;

	delete[] idArr;
	delete[] nameArr;
	delete[] priceArr;
	delete[] countArr;







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


