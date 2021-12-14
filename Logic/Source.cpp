/*
* Authors:
*	Carlos Pedraza
*	Luis Marquez
*/

//Headers
#include <iostream>

//Name spaces
using namespace std;

int length(float x[], int pos) {
	if (x[pos] == NULL) {
		return pos--;
	}

	length(x, ++pos);
}

//Main function
int main(int args, char* argsv[]) {
	float arr[] = { 1, 2, 3, 4, 5, NULL, NULL, NULL };
	cout << "El length es de: " << length(arr, 0) << endl;
	return 0;
}