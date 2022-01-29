#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <windows.h>
#include <stdlib.h>

#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77


using namespace std;

struct Coordenada {
	int x; 
	int y; 
};

struct Lista {
	struct Lista * sig;
	struct Coordenada c;
};

void agregarNodo(struct Lista * &lista, struct Coordenada c) {
	struct Lista * nuevo = new struct Lista();
	nuevo->c = c;
	nuevo->sig = lista;
	lista = nuevo;	
}
	
struct Lista * inicializarCola(struct Coordenada inicio, struct Lista * &cola) {
	struct Lista * cabeza = NULL; 
	agregarNodo(cabeza, inicio);
	cola = cabeza; 
	return cabeza; 
}

void actualizarCola(struct Lista * cola, struct Coordenada c) {
	if (cola) {
		while(cola->sig) {
			cola->sig->c = cola->c;
			cola = cola->sig;
		}
		cola->c = c;
	}
}

void pausa() {
	for (long i=0; i<50000000; i++);
}

void gotoxy(int x,int y){  
      HANDLE hcon;  
      hcon = GetStdHandle(STD_OUTPUT_HANDLE);  
      COORD dwPos;  
      dwPos.X = x;  
      dwPos.Y= y;  
      SetConsoleCursorPosition(hcon,dwPos);  
} 
/*
bool retrocedio(struct Coordenada anterior, struct Coordenada actual) {
	bool volvio = false; 
	if (anterior.x == )
}*/

bool actualizarCoordenadas(int cursor, struct Lista * &cabeza) {
	bool gameOver = false;
	switch (cursor) {
    case UP: 
		cabeza->c->y = cabeza->c->y - 1;
		//actual.y = actual.y - 1; 
		if (cabeza->c->y == -1) gameOver = true; // control de margenes 
        break;

    case DOWN:  
		cabeza->c->y = cabeza->c->y + 1;
		//actual.y = actual.y + 1; 
		if (cabeza->c->y == 26) gameOver = true;            
        break;
        
    case LEFT:   
    	cabeza->c->x = cabeza->c->x - 1;
		//actual.x = actual.x - 1;  
		if (cabeza->c->x == -1) gameOver = true;        
        break;
        
    case RIGHT:  
    	cabeza->c->x = cabeza->c->x + 1;
		//actual.x = actual.x + 1; 
		if (cabeza->c->x == 81) gameOver = true;           
        break;
	}
	return gameOver;
	
}

bool mover(int cursor, struct Lista * &cabeza, struct Lista * &cola) {
	dibujarCola(cola, " ");
	if (actualizarCoordenadas(cursor, cabeza) == false) {
		dibujarCola(cabeza, "@");
		pausa();
		
		
		//gotoxy(actual.x, actual.y);
		//cout << "@";
		//gotoxy(anterior.x, anterior.y);
		//cout << " ";
		//pausa(); // la ubicacion de la pausa es fundamental porque "congela" la imagen, y puede 
		// mostrar 2 caracteres, o ninguno por un tiempo determinado. 
		// Por esto, es necesario insertar la pausa despues de eliminar y ubicar el nuevo caracter. 
		return true;
	}
	return false; 	
}

bool retrocede(int cursorActual, int cursorAnterior) {
	// la resta entre UP/DOWN nos da 8, y la resta entre LEFT/RIGHT nos da 2. Por eso pregunto lo siguiente en el bendito if. 
	// Ahora, agrego la funcion abs para que quite el signo, porque me da lo mismo hacer 72-78 o 78-72, por ejemplo. 
	return abs(cursorActual - cursorAnterior) == 2 || abs(cursorActual - cursorAnterior) == 8; 
	
}

void startGame() {
	int cursorAnterior = UP;
	int cursorActual = UP;
	struct Coordenada inicio; 
	inicio.x = 10;
	inicio.y = 10;
	struct Lista * cola = null;
	struct Lista * cabeza = inicializarCola(inicio, cola);
		
	bool game = true; 
	while (game) {
		while(game && !_kbhit()) {
			game = mover(cursorActual, cabeza, cola);
		}
		if (game) { // Solo sigo leyendo las teclas si aun estoy en juego. Porque me pude haber caido del mapa...
			if (_getch() == 224) // al presionar una flecha, primero se carga el ascii 224!!!, no la compliques tanto Mr _getch()!!!
			cursorActual = _getch(); // dejo pasar el 224 arriba, y leo la tecla que ha presionado con otro _getch()
			game = !retrocede(cursorActual, cursorAnterior);
			cursorAnterior = cursorActual;
		}
	}
	cout << "Game over";
}

int main() {
	startGame();
	return 0;
}
