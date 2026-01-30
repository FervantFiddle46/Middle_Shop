#include "Storage.hpp"


size_t size = 0;
unsigned int* idArr = nullptr;
std::string* nameArr = nullptr;
unsigned int* countArr = nullptr;
double* priceArr = nullptr;
bool isStorageCreated = false;
unsigned int maxStorageSize = 4000;
unsigned int currentStorageSize = 0;
extern double maxPrice = 10000;



//---------------------------------------- Создание магазина --------------------------------------

void CreateStorage()
{
	const size_t staticSize = 10;

	unsigned int staticIdArr[staticSize]{ 1,2,3,4,5,6,7,8,9,10 };
	std::string staticNameArr[staticSize]{
		"'Война и мир' (1-2 тома) - Лев Николаевич Толстой", "'Отверженные' - Виктор Гюго",
		"'Золотой Жук' - Эдгар Аллан По", "'Мартин Иден' - Джек Лондон",
		"'Братья Карамазовы' - Фёдор Михайлович Достоевский", "'Человек, который смеётся' - Виктор Гюго",
		"'Мифы Ктулху' - Говард Филлипс Лавкрафт", "'Щегол' - Донна Тарт",
		"'Идиот' - Фёдор Михайлович Достоевский", "'Зов Ктулху' - Говард Филлипс Лавкрафт"
	};
	unsigned int staticCountArr[staticSize]{8, 6, 9, 10, 4, 9, 7, 9, 5, 1};
	double staticPriceArr[staticSize]{430,1200,350,350,430,350,350,1200,430,350};

	

	if (!isStorageCreated)
	{
		size = staticSize;
		idArr = new unsigned int[size];
		nameArr = new std::string[size];
		countArr = new unsigned int[size];
		priceArr = new double[size];
		FillArray(idArr, staticIdArr);
		FillArray(nameArr, staticNameArr);
		FillArray(countArr, staticCountArr);
		FillArray(priceArr, staticPriceArr);
		for (size_t i = 0; i < size; i++)
		{
			currentStorageSize += countArr[i];
		}
	}
	
}





//
// Функции супер-админа
//


//---------------------------------------- 2. Показ магазина --------------------------------------

void ShowStorage(int mode)
{
	if (mode == 0)
	{
		system("cls");
		std::cout << "Склад.\n------\n";
		std::cout << "ID\t" << std::left << std::setw(60) << "Название книги\t\t" << "Кол-во\t\t" << "Цена\n";
		for (size_t i = 0; i < size; i++)
		{
			std::cout << idArr[i] << "\t" << std::left << std::setw(60) << nameArr[i] << "\t\t" << countArr[i] << "\t\t" << priceArr[i] << "\t|\n";
		}
		std::cout << "-----------------------------\n\n";
		system("pause");
	}
	else if (mode == 1)
	{
		system("cls");
		std::cout << "Склад.\n------\n";
		std::cout << "ID\t" << std::left << std::setw(60) << "Название книги\t\t" << "Кол-во\t\t" << "\n";
		for (size_t i = 0; i < size; i++)
		{
			std::cout << idArr[i] << "\t" << std::left << std::setw(60) << nameArr[i] << "\t\t" << countArr[i] << "\t|\n";
		}
		std::cout << "\nЗаполненность склада: " << currentStorageSize << "/" << maxStorageSize <<  "\n-----------------------------\n\n";
	}
	else if (mode == 2)
	{
		system("cls");
		std::cout << "Склад.\n------\n";
		std::cout << "ID\t" << std::left << std::setw(60) << "Название книги\t\t" << "Цена\t\t" << "\n";
		for (size_t i = 0; i < size; i++)
		{
			std::cout << idArr[i] << "\t" << std::left << std::setw(60)
				<< nameArr[i] << "\t\t" << priceArr[i] << "\t|\n";
		}
		std::cout << "-----------------------------\n\n";
	
	}
}



//---------------------------------------- 3. Добавление товара --------------------------------------

void AddProduct()
{
	std::string chooseId, chooseCount, choose;
	int id = 0;
	unsigned int count = 0;
	while (true)
	{
		ShowStorage(1);
		std::cout << "Введите ID товара или \"exit\" для выхода\n\nВвод: ";
		GetLine(chooseId);
		if (chooseId == "exit")
		{
			std::cout << "Заверешение операции пополнения товара\n\n";
			Sleep(1500);
			break;
		}
		else if (IsNumber(chooseId))
		{
			id = std::stoi(chooseId) - 1;
			if (id < 0 || id > size - 1)
			{
				Err();
			}
			else
			{
				std::cout << "Введите количество товара для пополнения: ";
				GetLine(chooseCount);
				if (IsNumber(chooseCount))
				{
					count = std::stoi(chooseCount);
					if (count < 0 || count > maxStorageSize - currentStorageSize)
					{
						std::cout << "Некорректное количество! На складе осталось "
							<< maxStorageSize - currentStorageSize << " мест для товаров\n\n";
						Sleep(2000);
					}
					else
					{
						while (true)
						{
							std::cout << nameArr[id] << "\t\t" << countArr[id] << "  ----->  "
								<< countArr[id] + count << "\n\n";
							std::cout << "Подтвердить?\n1 - Да\n2 - Нет\n\nВвод: ";
							GetLine(choose);
							if (choose == "1")
							{
								std::cout << "Товар " << nameArr[id] << " успешно поплопнен\n";
								countArr[id] += count;
								currentStorageSize += count;
								Sleep(1500);
								break;
							}
							else if (choose == "2")
							{
								std::cout << "Отмена пополнения " << nameArr[id] << "\n";
								Sleep(1500);
								break;
							}
							else
							{
								Err(1);
							}
						}
						
					}
				}
			}
		}

	}
}



//---------------------------------------- 4. Списание товара --------------------------------------

void RemoveProduct()
{
	std::string chooseId, chooseCount, choose;
	int id = 0;
	unsigned int count = 0;
	while (true)
	{
		ShowStorage(1);
		std::cout << "Введите ID товара или \"exit\" для выхода\n\nВвод: ";
		GetLine(chooseId);
		if (chooseId == "exit")
		{
			std::cout << "Заверешение операции списания товара\n\n";
			Sleep(1500);
			break;
		}
		else if (IsNumber(chooseId))
		{
			id = std::stoi(chooseId) - 1;
			if (id < 0 || id > size - 1)
			{
				Err();
			}
			else
			{
				std::cout << "Введите количество товара для списания: ";
				GetLine(chooseCount);
				if (IsNumber(chooseCount))
				{
					count = std::stoi(chooseCount);
					if (count < 0 || count > countArr[id])
					{
						std::cout << "Некорректное количество! На складе осталось "
							<< countArr[id] << " выбранного товара\n\n";
						Sleep(2000);
					}
					else
					{
						while (true)
						{
							std::cout << nameArr[id] << "\t\t" << countArr[id] << "  ----->  "
								<< countArr[id] - count << "\n\n";
							std::cout << "Подтвердить?\n1 - Да\n2 - Нет\n\nВвод: ";
							GetLine(choose);
							if (choose == "1")
							{
								std::cout << "Товар " << nameArr[id] << " успешно списан\n";
								countArr[id] -= count;
								currentStorageSize -= count;
								Sleep(1500);
								break;
							}
							else if (choose == "2")
							{
								std::cout << "Отмена списания " << nameArr[id] << "\n";
								Sleep(1500);
								break;
							}
							else
							{
								Err(1);
							}
						}

					}
				}
			}
		}

	}
}



//---------------------------------------- 5. Изменение цены --------------------------------------

void ChangePrice()
{
	std::string chooseId, choosePrice, choose;
	int id = 0;
	double price = 0;
	while (true)
	{
		ShowStorage(2);
		std::cout << "Введите ID товара или \"exit\" для выхода\n\nВвод: ";
		GetLine(chooseId);
		if (chooseId == "exit")
		{
			std::cout << "Заверешение операции изменения цен\n\n";
			Sleep(1500);
			break;
		}
		else if (IsNumber(chooseId))
		{
			id = std::stoi(chooseId) - 1;
			if (id < 0 || id > size - 1)
			{
				Err();
			}
			else
			{
				std::cout << "Введите новую цену товара: ";
				GetLine(choosePrice);
				if (IsNumber(choosePrice))
				{
					price = std::stod(choosePrice);
					if (price < 150 || price > maxPrice)
					{
						std::cout << "Некорректная цена! Максимально возможная цена: "
							<< maxPrice << " рублей\n\n";
						Sleep(2000);
					}
					else
					{
						while (true)
						{
							std::cout << nameArr[id] << "\t\t" << priceArr[id] << "  ----->  "
								<< price << "\n\n";
							std::cout << "Подтвердить?\n1 - Да\n2 - Нет\n\nВвод: ";
							GetLine(choose);
							if (choose == "1")
							{
								std::cout << "Успешное изменение цены\n"; 
								priceArr[id] = price;
								Sleep(1500);
								break;
							}
							else if (choose == "2")
							{
								std::cout << "Отмена изменения цены " << priceArr[id] << "\n";
								Sleep(1500);
								break;
							}
							else
							{
								Err(1);
							}
						}

					}
				}
			}
		}

	}
}



//
// Функции изменения склада
//

//---------------------------------------- 6. Изменение склада --------------------------------------

void ChangeStorage()
{
	std::string choose;
	while (true)
	{
		std::cout << "1 - Добавить новый товар\n";
		std::cout << "2 - Изменить название товара\n";
		std::cout << "3 - Удалить твоар\n";
		std::cout << "4 - Изменить лимиты склада\n";
		std::cout << "0 - Выход\n\n";
		std::cout << "Ввод: ";
		GetLine(choose);
		if (choose == "1")
		{
			void AddNewItem();
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
		else if (choose == "0")
		{
			std::cout << "Выход из редактора склада\n";
			Sleep(1500);
			break;
		}
		else
		{
			Err();
		}
	}
}

//---------------------------------------- 6.1. Добавление нового товара --------------------------------------

void AddNewItem()
{
	std::string choose, choooseName, choosePrice, chooseCount;
	double price;
	unsigned int count = 0;
	bool isExit = true;
	while (true)
	{

	}
	/*ArrPushBack(idArr, size);
	ArrPushBack(nameArr, size);
	ArrPushBack(priceArr, size);
	ArrPushBack(countArr, size);
	size++;*/

}

