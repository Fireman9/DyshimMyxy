#pragma once
int **create_matr(int m, int n);
void del_matr(int** matr, int m);
void gener_matr(int** matr, int m, int n);
void print_matr(int** matr, int m, int n);
int** del_row(int** matr, int& m, int& n);
int** del_col(int** matr, int& m, int& n);
