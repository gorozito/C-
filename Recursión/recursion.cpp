#include<iostream>
#include<conio.h>


// declaraci�n de una constante
#define N 6

using namespace std;

// Ejemplo de una funci�n recursiva
void recursion(int repeticiones) {
	if (repeticiones != 0) {
		cout << repeticiones;
		recursion(repeticiones - 1);
		//cout << repeticiones;
	}	
}

int main() {	

	recursion(20);
			
	return 100;
}			 	
	 

		
		
		
		
	



