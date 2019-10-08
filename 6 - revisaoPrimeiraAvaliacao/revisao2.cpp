#include <iostream>
#include <cstdlib>
#include <time.h>
#define TAM 4000

using namespace std;
/*
 struct eh um artificio para criarmos
 tipos artificiais heterogeneos
*/

typedef struct {
	int x;
	int y;
	float valor;
} Ponto;

int main() {
	Ponto vetorPontos[TAM];
	srand(time(NULL));
	
	for (int i = 0; i < TAM; i++) {
		vetorPontos[i].x = 10 - (rand() % 20);
		vetorPontos[i].y = 10 - (rand() % 20);
		vetorPontos[i].valor = rand() % 20;
	}
	
	for (int i = 0; i < TAM; i++) {
		cout << "Ponto " << i << " - x: " << vetorPontos[i].x << endl;
		cout << "Ponto " << i << " - y: " << vetorPontos[i].y << endl;
		cout << "Ponto " << i << " - valor: " << vetorPontos[i].valor << endl;
		cout << "------------------------------" << endl;
	}
	
	return 1;
}
