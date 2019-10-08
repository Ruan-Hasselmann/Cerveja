#include <iostream>
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
	Ponto pontoInicial, pontoFinal;
	pontoInicial.x = 1;
	pontoInicial.y = 10;
	pontoInicial.valor = 4.7;
	cout << "(" << pontoInicial.x << "," << pontoInicial.y << "," << 
	     pontoInicial.valor << ")" << endl;
	
	
	pontoFinal.x = -3;
	pontoFinal.y = -4;
	pontoFinal.valor = 3.2;
	cout << "(" << pontoFinal.x << "," << pontoFinal.y << "," << 
	     pontoFinal.valor << ")" << endl;
	
	return 1;
}
