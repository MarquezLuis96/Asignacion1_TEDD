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

float sigmaArrayElements(int nElements, float arr[], int pos) {
	if (pos == nElements) {
		return arr[pos];
	}
	return (arr[pos] + sigmaArrayElements(nElements, arr, pos + 1));
}

float mean(int nElements, float arr[], int pos) {
	if (pos == nElements) {
		return ((arr[pos]) / (nElements));
	}
	return (((arr[pos]) / (nElements)) + (mean(nElements, arr, pos + 1)));
}

//Main function
int main(int args, char* argsv[]) {
	float arr[] = { 1, 2, 3, 4, 5, NULL, NULL, NULL };
	int tam = length(arr, 0);
	float suma = sigmaArrayElements(tam, arr, 0);
	float prom = mean(tam, arr, 0);
	cout << "El length es de: " << tam << endl;
	cout << "El sigma de los elementos es: " << suma << endl;
	cout << "El prom de los elementos es: " << prom << endl;

	return 0;
}