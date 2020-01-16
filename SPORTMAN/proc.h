#pragma once
double** createdatabase(int m, int n);
void deletedatabase(double** marks, int m);
void getdata(double** marks, std:: string* names, int amountsprt);
void arithmean(double** marks, std::string* names, int amountmarks, int amountsprt);
void rating(double** marks, std::string* names, int amountmarks, int amountsprt, int controlmark);
void sortbyalphabet(double** marks, std::string* names, int amountmarks, int amountsprt, int controlmark);