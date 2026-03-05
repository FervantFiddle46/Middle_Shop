#ifndef _SELLINGS_HPP_
#define _SELLINGS_HPP_

#include "Storage.hpp"

extern size_t checkSize;
extern unsigned int* idArrCheck;
extern std::string* nameArrCheck;
extern unsigned int* countArrCheck;
extern double* priceArrCheck;
extern double* totalPriceArrCheck;
extern double cashIncome;
extern double nonCashIncome;
extern double cashbox;



void Selling();
void PrintCheck(const double totalSum);
void CheckArrDeleter();



#endif  // !_SELLINGS_HPP_