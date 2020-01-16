#include <iostream>
#include <string>

using namespace std;

double** createdatabase(int m, int n) {	//ініціалізація 2мірного масиву
	double** marks = new double* [m];
	for (int i = 0; i < m; i++) {
		marks[i] = new double[m];
	}
	return marks;
}
void deletedatabase(double** marks, int m) {	//звільнення пам'яті від 2мірного масиву
	for (int i = 0; i < m; i++) {
		delete[]marks[i];
	}
	delete[]marks;
}
void getdata(double** marks, string* names, int amountsprt) {	//зчитування та запис даних у відповідні масиви
	int datacount = 0;	//лічильник для занесення інфи в відповідні масиви по правильному індексу
	cout << "Enter name then marks(example: Vasya: 7.6 8.9): " << endl;
	cin.get();	//очищення буфера для подальшого зчитування
	for (int i = 0; i < amountsprt; i++) {
		int words = 0, index = 0, tcount = 0; //лічильники к-сть слів, індекс початковий для ділення слів на лексеми, індекс кінцевий...
		cout << datacount + 1 << ": ";
		string text;	//рядок, який сприймає текст
		getline(cin, text);
		text += " ";
		for (int i = 0; i < text.length(); i++) {	//підрахунок к-сті слів
			if (text[i] == ' ') {
				words++;
			}
		}
		string* temp = new string[words];	//2мірний масив рядків для ділення слів на лексеми
		for (int i = 0; i < text.length(); i++) {	//саме ділення рядків на лексеми
			if (text[i] == ' ') {
				temp[tcount].assign(text, index, i - index);
				index = i + 1;
				tcount++;
			}
		}
		names[datacount].assign(temp[0]);	//1ша лексема-ім'я, ми заносимо його в масив імен
		for (int i = 0; i < words-1; i++) {	//все інше-оцінки, заносимо в 2мірний масив балів
			marks[datacount][i] = stod(temp[i+1]);
		}
			datacount++;
		delete[]temp;
	}
	cout << endl;
}
void arithmean(double** marks, std::string* names, int amountmarks, int amountsprt) {	//ф-ція, яка знаходить найбільший та найменший бал, рахує середнє арифметичне, не враховуючи max i mіn бали, та відповідно виводить це на екран
	double arithmean;	//середнє арифметичне
	cout << "Arithmetic mean (without the min and max mark): " << endl;
	for (int i = 0; i < amountsprt; i++) {	//знаходження min i max
		arithmean = 0;
		double max = marks[i][0], min = marks[i][0];
		cout << names[i] << ": ";
		for (int j = 0; j < amountmarks; j++) {
			if (max < marks[i][j]) {
				max = marks[i][j];
			}
			if (min > marks[i][j]) {
				min = marks[i][j];
			}
		}
		for (int j = 0; j < amountmarks; j++) {	// виведення всіх елементів окрім min і max
			if (marks[i][j] != max && marks[i][j] != min) {
				cout << marks[i][j] << " ";
				arithmean += marks[i][j];
			}
		}
		cout << "(" << min << " , " << max << ")";	//саме виведення min i max у відповідній формі
		cout << " = " << arithmean/(amountmarks-2) << endl;
	}
	cout << endl;
}
void rating(double** marks, string* names, int amountmarks, int amountsprt, int controlmark) {	//ф-ція, що сортує спортсменів за балами, виводить у порядку спадання допущених студентів та недопущених студентів
	double gpa = 0, gpatemp = 0;	//змінні середнього бала для бульбашкового сортування
	for (int k = 0; k < amountsprt; k++) {	//алгоритм бульбашкового сортування
		for (int i = 0; i < amountsprt - 1; i++) {
			gpa = 0, gpatemp = 0;
			for (int j = 0; j < amountmarks; j++) {
				gpa += marks[i][j];
			}
			gpa /= amountmarks;
			for (int j = 0; j < amountmarks; j++) {
				gpatemp += marks[i + 1][j];
			}
			gpatemp /= amountmarks;
			if (gpatemp > gpa) {
				for (int j = 0; j < amountmarks; j++) {
					swap(marks[i][j], marks[i + 1][j]);
				}
				swap(names[i], names[i + 1]);
			}
		}
	}
	cout << "Mark is higher than Control mark: " << endl;
	for (int i = 0; i < amountsprt; i++) {	//виведення студентів, які мають середній бал вище прохідного
		gpa = 0;
		for (int j = 0; j < amountmarks; j++) {
			gpa += marks[i][j];
		}
		gpa /= amountmarks;
		if (gpa > controlmark) {
			cout << names[i] << ": ";
			cout << gpa << endl;
		}
	}
	cout << endl;
	cout << "Mark isn't enough: " << endl;
	for (int i = 0; i < amountsprt; i++) {	//виведення студентів, які мають середній бал нижче прохідного
		gpa = 0;
		for (int j = 0; j < amountmarks; j++) {
			gpa += marks[i][j];
		}
		gpa /= amountmarks;
		if (gpa < controlmark) {
			cout << names[i] << ": ";
			cout << gpa << endl;
		}
	}
	cout << endl;
}
void sortbyalphabet(double** marks, string* names, int amountmarks, int amountsprt, int controlmark) {	//ф-ція сортує недопущених студентів в алфавітному порядку, та виводить їх так на екран
	double gpa;	//змінна середнього бала
	for (int k = 0; k < amountsprt; k++) {	//бульбашкове сортування спортсменів за абеткою
		for (int i = 0; i < amountsprt - 1; i++) {
			if (names[i][0] > names[i + 1][0]) {	//для сортування порівнюються коди ASCII перших букв спортсменів
				swap(names[i], names[i + 1]);
				for (int j = 0; j < amountmarks; j++) {
					swap(marks[i][j], marks[i + 1][j]);
				}
			}
		}
	}
	cout << "Mark isn't enough(sorted by alphabet): " << endl;
	for (int i = 0; i < amountsprt; i++) {	//виведення спортсменів, що набрали менший бал ніж прохідний, в алфавітному порядку
		gpa = 0;
		for (int j = 0; j < amountmarks; j++) {
			gpa += marks[i][j];
		}
		gpa /= amountmarks;
		if (gpa < controlmark) {
			cout << names[i] << ": ";
			cout << gpa << endl;
		}
	}
	cout << endl;
}