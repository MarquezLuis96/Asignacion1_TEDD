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

float variance(int nElements, float arr[], int pos, float mean) {
	float poweredMinter = 1.0;
	if (pos == nElements - 1) {
		poweredMinter = ((arr[pos]) - (mean));
		poweredMinter *= poweredMinter;
		return ((poweredMinter) / (nElements));
	}
	poweredMinter = ((arr[pos]) - (mean));
	poweredMinter *= poweredMinter;
	return (((poweredMinter) / (nElements)) + (variance(nElements, arr, pos + 1, mean)));
}

float standardDeviation(int nElements, float arr[], int pos, float mean) {
	float poweredMinter = 1.0;
	if (pos == nElements - 1) {
		poweredMinter = ((arr[pos]) - (mean));
		poweredMinter *= poweredMinter;
		return ((poweredMinter) / (nElements));
	}
	poweredMinter = ((arr[pos]) - (mean));
	poweredMinter *= poweredMinter;

	if (pos == 0) {
		return sqrt(((poweredMinter) / (nElements)) + (standardDeviation(nElements, arr, pos + 1, mean)));
	}

	return (((poweredMinter) / (nElements)) + (standardDeviation(nElements, arr, pos + 1, mean)));
}

//Main function
int main(int args, char* argsv[]) {
	float arr[] = { 1500, 1200, 1700, 1300, 1800, NULL, NULL, NULL };
	int tam = length(arr, 0);
	float suma = sigmaArrayElements(tam, arr, 0);
	float prom = mean(tam, arr, 0);
	float varianza = variance(tam, arr, 0, prom);
	float stanDev = standardDeviation(tam, arr, 0, prom);
	cout << "El length es de: " << tam << endl;
	cout << "El sigma de los elementos es: " << suma << endl;
	cout << "El prom de los elementos es: " << prom << endl;
	cout << "La varianza de los elementos es: " << varianza << endl;
	cout << "La desviacion estandar de los elementos es: " << stanDev << endl;

	return 0;
}