#ifndef _STORAGE_HPP_
#define _STORAGE_HPP_
#include "Accounts.hpp"

extern size_t size;
extern unsigned int* idArr;
extern std::string* nameArr;
extern unsigned int* countArr;
extern double* priceArr;
extern bool isStorageCreated;

void CreateStorage();
void ShowStorage(int mode = 0);

template<typename ArrType>
inline void FillArray(ArrType* dynamicArr, ArrType* staticArr);


#endif 
