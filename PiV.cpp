#include <iostream>
#include<ctime>
#include<iomanip>
#include<algorithm>
#include<string>
using namespace std;

int** createArray(int n, int m);//створення динамічного двовимірного масиву
int** init(int** M, int n, int m);//наповнення матриці
void Print(int** M, int n, int m);//виведення матриці
int* MaxStone(int** M, int* N, int n, int m);//створення масиву максимумів стовбців
int** SortMatrix(int** M, int* N, int n, int m);//упорядковуємо матрицю за зростанням максимумів стовбців
string* Skleyka(int** M, int n, int m);//склеюємо рядок матриці в рядок
void NumberMinePlus(string* M, int n);//визначає кількість додатніх і від'ємних елементів в рядку і виводить їх значення

int main()
{
	setlocale(LC_ALL, "Russian");
	int n, m;
	cout << "Введите количество строк матрицы : ";
	cin >> n;
	cout << "Введите количество столбцов матрицы : ";
	cin >> m;
	int** A;
	A = createArray(n, m);
	A = init(A, n, m);
	cout << "Матрица А =: " << "\n";
	Print(A, n, m);
	int* B = new int[m];
	B = MaxStone(A, B, n, m);
	cout << "масив максимумов столбцов";
	for (int i = 0; i < m; i++)//лінь було нову функцію писати :) соре
	{
		cout << "  " << B[i];
	}
	cout << endl;
	A = SortMatrix(A, B, n, m);
	cout << "Новая упорядочена матрица:" << endl;
	Print(A, n, m);
	string* C = new string[n];
	C = Skleyka(A, n, m);
	NumberMinePlus(C, n);
}

int** createArray(int n, int m)//створюємо матрицю 
{
	int** M;
	M = new int* [n];
	srand(time(NULL));
	for (int i = 0; i < n; i++) {
		M[i] = new int[m];
	}
	return M;
}

int** init(int** M, int n, int m)// наповнюємо матрицю елементами
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			M[i][j] = rand() % 41 - 20;
		}
	}
	return M;
}

void Print(int** M, int n, int m)//виводимо матрицю
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << setw(7) << M[i][j];
		}
		cout << endl;
	}
}

int* MaxStone(int** M, int* N, int n, int m)
{
	int a;
	for (int i = 0; i < m; i++)
	{
		a = M[0][i];
		for (int j = 0; j < n; j++)
		{
			if (a <= M[j][i])
			{
				a = M[j][i];
			}
		}
		N[i] = a;
	}
	return N;
}

int** SortMatrix(int** M, int* N, int n, int m)
{
	int a;
	for (int i = 0;i < m; i++)
	{
		a = N[0];
		for (int j = i + 1;j < m;j++)
		{
			if (N[i] > N[j])
			{
				a = N[i];
				N[i] = N[j];
				N[j] = a;
				for (int k = 0;k < n;k++)
				{
					a = M[k][i];
					M[k][i] = M[k][j];
					M[k][j] = a;
				}
			}
		}
	}
	return M;
}

string* Skleyka(int** M, int n, int m)//склеюємо рядок матриці в рядок
{

	string* C = new string[n];
	string c;
	for (int i = 0; i < n; i++)
	{
		c = " ";
		for (int j = 0;j < m;j++)
		{
			string a = to_string(M[i][j]) +" " ;
			c += a;
		}
		C[i] = c;
	}
	return C;
}

void NumberMinePlus(string* M, int n)//визначає кількість додатніх і від'ємних елементів в рядку і виводить їх значення
{
	for (int j = 0;j < n;j++)
	{
		string a, b, k;
		int c, d;
		c = 0;//додатні числа в рядку
		d = 0;//від'ємні числа в рядку
		a = M[j];
		for (int i = 0; i < (a.length()-1); i++)
		{
			k = M[j][i];
			if (k == " ")
			{
				b = M[j][i + 1];
				if (b == "-")
				{
					d++;
				}
				else {
					c++;
				}
			}
		}
		cout << "  " << M[j] << "положительных"<< c  << "  "<< "отрицательных" << " " << d<< " "<< "\n";
	}
}