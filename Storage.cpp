#include "Storage.hpp"


size_t size = 0;
unsigned int* idArr = nullptr;
std::string* nameArr = nullptr;
unsigned int* countArr = nullptr;
double* priceArr = nullptr;
bool isStorageCreated = false;


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
	unsigned int staticCountArr[staticSize]{12, 8, 14, 19, 4, 9, 13, 14, 7, 1};
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
	}
	
}

void ShowStorage(int mode)
{
	if (mode == 0)
	{
		std::cout << "ID\t" << std::left << std::setw(60) << "Название книги\t\t" << "Кол-во\t\t" << "Цена\n";
		for (size_t i = 0; i < size; i++)
		{
			std::cout << idArr[i] << "\t" << std::left << std::setw(60) << nameArr[i] << "\t\t" << countArr[i]
				<< "\t\t" << priceArr[i] << "\n";
		}
	}
}

template<typename ArrType>
inline void FillArray(ArrType* dynamicArr, ArrType* staticArr)
{
	for (size_t i = 0; i < size; i++)
	{
		dynamicArr[i] = staticArr[i];
	}
}