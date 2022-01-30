#include <iostream>
#include <conio.h>

using namespace std;
	
int * cargarDatos (int &cantidad) { // aquí el parámetro cantidad es una variable por referencia (&), para que se vea reflejado su cambio
	cout << "Ingrese la cantidad de elementos: "; 
	cin >> cantidad;	
	int *numeros = new int(cantidad); // dinámico
	
	for (int i=0; i < cantidad; i++) {
	  cout << "Ingrese el elemento en la posición: " << i << " ";
	  cin >> numeros[i];	
	}	
	return numeros;	
}
		

bool esPrimo (int n) {
	int cantidadDivisores = 0;
	if (n == 1)
		return true;
		
	for (int i = 1; i <= n; i++){
		if (n % i == 0)
			cantidadDivisores++;
	}
	
	if (cantidadDivisores == 2)
		return true;
	else
		return false;
}

int cantidadPrimos (int *arreglo, int n){
	int cantidadPrimos = 0;
	for (int i=0; i<n; i++){
		if (esPrimo(arreglo[i]) == true)
			cantidadPrimos++;
	}	
	return cantidadPrimos++;
}

void mostrarArreglo(int * numeros, int n) {
	cout << "\n";
	// Recorrido de der. a izq.
	for (int i = 0; i < n; i++)
		cout << numeros[i] << " ";
}

int main (){
	
	int cantidad;
	int * arreglo = cargarDatos(cantidad);
	mostrarArreglo(arreglo, cantidad);
	cout << "La cant de primos es:  " << cantidadPrimos (arreglo, cantidad);
	

	
return 0;
}
