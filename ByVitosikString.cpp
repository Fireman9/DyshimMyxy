#include<iostream>
#include<iomanip>
#include<string>

using namespace std;

string* Enter(int  n);//ввід рядків
string* Code(string* M, int n);//шифрування рядків(спочатку символи,що стоять на парних позиціях, потім тібщо на непарних в зворотньому порядку)
string* Delete(string* M, int n);//видаляє повтри символів
string* LowerRegistr(string* M, int n);//Шукає кількість букв з нижчого регістру і записує інформацію про це в масив 
void Output(string* M, int n);// функція для виводу масиву рядків

int main()
{
	setlocale(LC_ALL, "en_US.UTF-8");
	int n;//кількість рідків ,я і хоче ввести коритувач
	cout << "Please enter the number of rows,press ENTER, and then enter the rows (After each line you enter,press ENTER) :" << endl;
	cin >> n;
	cin.ignore( 1,  '\n');
	string* A;//masiv strok 
	A = Enter(n);
	A = Code(A, n);
	cout << " Result 1 : " << endl;
	Output(A, n);
	A = Delete(A, n);
	cout << " Result 2 : " << endl;
	Output(A, n);
	string* B;//масив , де записана буде інформація про кількість літер з нижнього регістру
	cout << " Result 3 : " << endl;
	B = LowerRegistr(A, n);
	Output(B, n);
}

void Output(string* M, int n)
{
	for (int i = 0;i < n;i++)
	{
		cout << M[i] << endl;
	}
}

string* Enter(int n)
{
	string* M = new string [n];
	for (int i = 0; i < n; i++)
	{
		getline(cin, M[i]);
	}
	return M;
}

string* Code(string* M, int n)
{
	int a;// довжина рядка
	string* N = new string [n];//масив куди записується результат і який повертається користувачеві
	string h, g;//h - символи , що стоять в непариних позиціх записані в зворотньому порядку, gсимволи з непарних позицій
	for (int i = 0;i < n;i++)
	{
		g = "";
		h = "";
		a = M[i].length();
		//N[i] = new char[a];
		for (int j = 0;j < a;j++)
		{
			if (j % 2 == 0 && (a % 2) == 0)
			{
				N[i] += M[i][j];
				g += M[i][j + 1];
			}
			if (j % 2 == 0 && (a % 2) != 0)
			{
				N[i]+= M[i][j];


			}
			if (j % 2 == 0 && (a % 2) != 0&&(j+1)!=a)
			{
				
				g += M[i][j + 1];

			}
		}
		for (int k = g.length() - 1; k >= 0; k--)
		{
			h += g[k];
		}
		N[i] += h;
	}
	delete[] M;
	return N;
}

string* Delete(string* M, int n)
{
	string* N = new string[n];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < M[i].length(); j++)
		{
			
			if (M[i][j] != M[i][j + 1]&& M[i][j + 1]!= M[i].length())
			{
				N[i] += M[i][j];
			}
			if (M[i][j] == M[i][j + 1])
			{
				N[i] += "";
					//M[i]=M[i].erase(M[i][j]);
			}
		}
	}
	delete[] M;
	return N;
}

string* LowerRegistr(string* M, int n)
{
	bool a;//чи є літера нижнім регістром
	int k;//кількість літер з нижнього регістру в рядку
	string* N = new string[n];
	for (int i = 0; i < n; i++)
	{
		k = 0;
		for (int j = 0; j < M[i].length(); j++)
		{
			a = islower(M[i][j]);
			if (a == true)
			{
				k++;
			}
		}
		N[i] = M[i] + "   in this line the lower case is  " + to_string(k) + " litters";
	}
	return N;
}

