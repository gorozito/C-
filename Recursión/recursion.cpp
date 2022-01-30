#include<iostream>
#include<conio.h>


// declaración de una constante
#define N 6

using namespace std;

// Ejemplo de una función recursiva
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
	 

		
		
		
		
	



