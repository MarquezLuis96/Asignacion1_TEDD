/*
* Authors:
*	Carlos Pedraza
*	Luis Marquez
*/

//Headers
#include <iostream>

//Name spaces
using namespace std;

int length(float arr[], int pos) {
	if (arr[pos] == NULL) {
		return pos--;
	}

	length(arr, ++pos);
}

int sigmaArrayElements(int nElements, float arr[], int pos) {
	if (nElements == pos) {
		return arr[pos];
	}
	return (arr[pos] + sigmaArrayElements(nElements, arr, pos + 1));
}

//Main function
int main(int args, char* argsv[]) {
	float arr[] = { 1, 2, 3, 4, 5, NULL, NULL, NULL };
	int tam = length(arr, 0);
	cout << "El length es de: " << tam << endl;
	cout << "El sigma de los elementos es: " << sigmaArrayElements(tam, arr, 0) << endl;
	return 0;
}