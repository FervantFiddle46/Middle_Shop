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

void Seeling()
{
	std::string choose, chooseId, chooseCount, chooseCash;
	int id = 0, count;
	double totalSum = 0.0;
	checkSize = 0;

	while (true)
	{
		ShowStorage();
		std::cout << "\nВведите ID товара для покупки / \"exit\" для завершения покупки: ";
		GetLine(chooseId);
		if (chooseId == "exit")
		{

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

		if (IsNumber(chooseId))
		{
			id = std::stoi(chooseId) - 1;
			if (id < 1 || count > countArr[id])
			{
				std::cout << "Ошибка количества. Максимум: " << countArr[id] << "\n";
				Sleep(1500);
				continue;
			}
		}
		else
		{
			continue;
		}

		//to do==================
	}

}
