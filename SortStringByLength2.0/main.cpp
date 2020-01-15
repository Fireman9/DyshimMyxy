#include <iostream>
#include <string>
#include "proc.h"

using namespace std;

int main() {
	string text;
	getline(cin, text);
	proc(text);
	return 0;
}