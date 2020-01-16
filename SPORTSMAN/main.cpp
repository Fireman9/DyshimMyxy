#include <iostream>
#include "proc.h"

using namespace std;

int main() {
	int amountsprt, amountmarks, controlmark;	//к-сть спортсменів, к-сть оцінок, прохідний бал
	cout << "Enter how many sportsmen will be: ";
	cin >> amountsprt;
	cout << "Enter how many marks will be(more than 3): ";
	cin >> amountmarks;
	if (amountmarks < 3) {
		cout << "More then 3 marks!" << endl;
		return 0;
	}
	cout << "Enter control mark: ";
	cin >> controlmark;
	string* names = new string[amountsprt];	//ств. масиву рядків, який зберігає імена
	double** marksdata = createdatabase(amountmarks, amountsprt); //ств. двомірного масиву, який зберігає оцінки відповідно масиву рядків 
	getdata(marksdata, names, amountsprt);
	arithmean(marksdata, names, amountmarks, amountsprt);
	rating(marksdata, names, amountmarks, amountsprt, controlmark);
	sortbyalphabet(marksdata, names, amountmarks, amountsprt, controlmark);
	deletedatabase(marksdata, amountmarks);
	delete[] names;
	return 0;
	//хай прибуде сила з тим, кому попадеться цей білет
}