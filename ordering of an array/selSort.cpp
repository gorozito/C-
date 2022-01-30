#include<iostream>
#include<conio.h>


// declaración de una constante
#define N 6

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

void mostrarArreglo(int * numeros, int n) {
	cout << "\n";
	// Recorrido de der. a izq.
	for (int i = n - 1; i >= 0; i--)
		cout << numeros[i] << " ";
		
	cout << "\n";	
	
	// Recorrido de izq. a der.
	for (int i = 0; i < N; i++)
		cout << numeros[i] << " ";
	cout << "\n";	
	
}

int main() {	
	/*
	int cantidad = 0;
	int * arreglo = cargarDatos(cantidad);
	mostrarArreglo(arreglo, cantidad);
	
	*/
			
	return 100;
}			 	
	 

		
		
		
		
	



