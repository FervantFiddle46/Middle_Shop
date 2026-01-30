#ifndef _STORAGE_HPP_
#define _STORAGE_HPP_

#include "Accounts.hpp"


extern size_t size;
extern unsigned int* idArr;
extern std::string* nameArr;
extern unsigned int* countArr;
extern double* priceArr;
extern bool isStorageCreated;
extern unsigned int maxStorageSize;
extern unsigned int currentStorageSize;
extern double maxPrice;

void CreateStorage();

void ShowStorage(int mode = 0);

void AddProduct();

void RemoveProduct();

void ChangePrice();


void ChangeStorage();

void AddNewItem();


template<typename ArrType>
inline void FillArray(ArrType* dynamicArr, ArrType* staticArr);

template<typename ArrType>
static inline void FillArray(ArrType* dynamicArr, ArrType* staticArr)
{
	for (size_t i = 0; i < size; i++)
	{
		dynamicArr[i] = staticArr[i];
	}
}

#endif 
