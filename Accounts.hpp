#ifndef _ACCOUNTS_HPP_
#define _ACCOUNTS_HPP_

#include <string>
#include <iomanip>
#include <iostream>
#include <unordered_set>

#include "ServiceFunctions.hpp"

extern size_t userSize;
extern std::string currentStatus;
extern unsigned int currentId;
extern std::string* logArr;
extern std::string* passArr;
extern std::string* userStatus;
extern double* awardArr;
extern double* fineArr;
extern unsigned int* userId;

extern std::unordered_set<char> loginSymbols;
extern std::unordered_set<char> passSymbols;
extern unsigned int maxLogin;
extern unsigned int maxPass;
extern unsigned int minLogin;
extern unsigned int minPass;

extern bool isSetCreated;

void ChangeAccounts();
void ChangeLogin();
void ChangePass();
void ChangeStatus();
void CreateNewUser();
void ShowUser(int mode = 0);
bool CheckLogin(const std::string& chooseLogin);
bool CheckPass(const std::string& choosePass);
void CreateSet();

#endif 
