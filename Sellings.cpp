#include "Sellings.hpp"

size_t checkSize = 0;
unsigned int* idArrCheck = nullptr;
std::string* nameArrCheck = nullptr;
unsigned int* countArrCheck = nullptr;
double* priceArrCheck = nullptr;
double* totalPriceArrCheck = nullptr;
double cashIncome = 0.0;
double nonCashIncome = 0.0;
double cashbox = 15000;



//---------------------------------------- Продажи --------------------------------------

void Selling()
{
	srand(time(NULL));
	std::string choose, chooseId, chooseCount, chooseCash;
	int id = 0, count = 0, cardChance = 0, sleepTimer;
	double totalSum = 0.0, money = 0.0;
	size_t index = 0;
	checkSize = 0;
	bool isFirst = true;

	while (true)
	{
		ShowStorage();
		std::cout << "\nВведите ID товара для покупки / \"exit\" для завершения покупки: ";
		GetLine(chooseId);
		if (chooseId == "exit")
		{
			if (isFirst)
			{
				std::cout << "Выход без покупок\n";
				Sleep(1500);
				break;
			}
			else
			{
				PrintCheck(totalSum);
				std::cout << "Подтвердить покупку?\n\n1 - Да\n2 - Добавить ещё товар\n3 - Отмена\n\nВвод: ";
				GetLine(choose);
				if (choose == "1")
				{
					system("cls");
					system("cls");
					std::cout << "Выберите способ оплаты\n1 - Наличными\n2 - Безнал\n\nВвод: ";
					GetLine(choose);
					if (choose == "1")
					{
						std::cout << "Введите количество наличных: ";
						GetLine(chooseCash);
						if (IsNumber(chooseCash))
						{
							money = std::stod(chooseCash);
							if (money < totalSum)
							{
								std::cout << "Недостаточно средств!\n";
								Sleep(1500);
								continue;
							}
							else if (money - totalSum > cashbox)
							{
								std::cout << "Нет возможности выдать сдачу. Повторите попытку\n";
								Sleep(1500);
								continue;
							}
							else
							{
								std::cout << "Ваши " << money << " успешно внесены\n";
								Sleep(1500);
								std::cout << "Оплата прошла успешно. Сдача " << money - totalSum << " рублей\n\n";
								Sleep(1800);
								cashbox += totalSum;
								cashIncome += totalSum;
								system("cls");
							}
						}
					}
					else if (choose == "2")
					{
						while (true)
						{
							cardChance = rand() % 100 + 1;
							sleepTimer = 150;
							std::cout << "Приложите карту\n";
							system("pause");
							if (cardChance <= 10)
							{
								for (size_t i = 0; i < 5; i++)
								{
									std::cout << i + 1 << " ";
									Sleep(sleepTimer);
									sleepTimer -= 30;
									Beep(400, 800);
								}
								std::cout << "\n\nОшибка чтения карты. Пожалуйста, приложите карту повторно\n\n";
								Sleep(1500);
							}
							else
							{
								for (size_t i = 0; i < 5; i++)
								{
									std::cout << i + 1 << " ";
									Sleep(sleepTimer);
									sleepTimer -= 30;
									Beep(500, 800);
								}
								std::cout << "\n\nОплата прошла успешно!\n\n";
								Sleep(1500);
								nonCashIncome += totalSum;
								break;
							}

						}
					}
					else if (choose == "EpohaBezKnig" || choose == "epohabezknig")
					{
						std::cout << "Книги изъяты\n";
						Sleep(1500);
						system("cls");
						CheckArrDeleter();
						return;
					}
					else
					{
						Err();
					}
				}
				else if (choose == "2")
				{
					continue;
				}
				else if (choose == "3")
				{
					for (size_t i = 0; i < checkSize; i++)
					{
						countArr[idArrCheck[i] - 1] += countArrCheck[i];
					}
					CheckArrDeleter();
					std::cout << "Отмена покупки\n";
					Sleep(1500);
					system("cls");
					return;
				}
				else
				{
					Err();
					continue;
				}
				CheckArrDeleter();
				awardArr[currentId] += totalSum;
				system("cls");
				return;
			}
			
		}
		if (IsNumber(chooseId))
		{
			id = std::stoi(chooseId) - 1;
			if (id < 0 || id > size)
			{
				std::cout << "Ошибка ID\n";
				Sleep(1500);
				continue;
			}
		}

		std::cout << "\nВведите количество товара / \"exit\" для выбора другого товара: ";
		GetLine(chooseCount);

		if (IsNumber(chooseCount))
		{
			count = std::stoi(chooseCount);
			if (count < 1 || count > countArr[id])
			{
				std::cout << "\nОшибка количества. Максимум: " << countArr[id] << "\n\n";
				Sleep(1500);
				continue;
			}
		}
		else
		{
			continue;
		}

		ArrPushBack(idArrCheck, checkSize);
		ArrPushBack(nameArrCheck, checkSize);
		ArrPushBack(countArrCheck, checkSize);
		ArrPushBack(priceArrCheck, checkSize);
		ArrPushBack(totalPriceArrCheck, checkSize);
		idArrCheck[index] = idArr[id];
		nameArrCheck[index] = nameArr[id];
		countArrCheck[index] = count;
		priceArrCheck[index] = priceArr[id];
		totalPriceArrCheck[index] = priceArr[id] * count;
		index++;
		checkSize++;
		totalSum += priceArr[id] * count;
		countArr[id] -= count;
		std::cout << "\nТовар добавлен в чек\n";
		if (isFirst)
		{
			isFirst = false;
		}
		Sleep(1000);

		
	}

}




//---------------------------------------- Печать чека --------------------------------------

void PrintCheck(double totalSum)
{
	system("cls");
	std::cout << "#   " << "ID\t" << std::left << std::setw(60) << "Название книги\t\t" << "Кол-во\t" << "Цена\t" << "Итого\n";
	for (size_t i = 0; i < checkSize; i++)
	{
		std::cout << i + 1 << "   " << idArrCheck[i] << "\t" << std::left << std::setw(30) << nameArrCheck[i] 
			<< "\t\t\t" << countArrCheck[i] << "\t" << priceArrCheck[i] << "\t" << totalPriceArrCheck[i] << "\t|\n";
	}
	std::cout << "-----------------------------\n\nИтого к оплате: " << totalSum << "\n\n";
	system("pause");
}





//---------------------------------------- Удаление чека --------------------------------------

void CheckArrDeleter()
{
	delete[] idArrCheck;
	delete[] nameArrCheck;
	delete[] countArrCheck;
	delete[] priceArrCheck;
	delete[] totalPriceArrCheck;
	idArrCheck = nullptr;
	nameArrCheck = nullptr;
	countArrCheck = nullptr;
	priceArrCheck = nullptr;
	totalPriceArrCheck = nullptr;
}
