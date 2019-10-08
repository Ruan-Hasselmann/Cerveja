#include <iostream>
#include <cstdlib>
#include <string>
#include <time.h>
#define TAM 4
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

void populaPontos(Ponto v[], int qtd) {
	srand(time(NULL));
	for (int i = 0; i < qtd; i++) {
		v[i].x = 10 - (rand() % 20);
		v[i].y = 10 - (rand() % 20);
		v[i].valor = rand() % 20;
	}
}

string qualQuadrante(Ponto p) {
	if (p.x > 0 && p.y > 0) return "Primeiro quadrante";
	if (p.x < 0 && p.y > 0) return "Segundo quadrante";
	if (p.x < 0 && p.y < 0) return "Terceiro quadrante";
	if (p.x > 0 && p.y < 0) return "Quarto quadrante";
	if (p.x == 0 && p.y == 0) return "Origem";
	if (p.x != 0 && p.y == 0) return "Eixo x";
	if (p.x == 0 && p.y != 0) return "Eixo y";
}
	
void exibePontos(Ponto v[], int qtd) {
	for (int i = 0; i < qtd; i++) {
		cout << "Ponto " << i << " - x: " << v[i].x << endl;
		cout << "Ponto " << i << " - y: " << v[i].y << endl;
		cout << "Ponto " << i << " - valor: " << v[i].valor << endl;
		cout << "------------------------------" << endl;
	}
}

void exibeQuadrantePontos(Ponto v[], int qtd) {
	string resposta;
	for (int i = 0; i < qtd; i++) {
		resposta = qualQuadrante(v[i]);		
		cout << "(" << v[i].x << "," << v[i].y << "," 
		     << v[i].valor << ") - " << resposta << endl;
		cout << "------------------------------" << endl;
	}
}
/*
 	TODO VETOR OU MATRIZ TEM PASSAGEM POR REFERENCIA
 	PORQUE TODO VETOR/MATRIZ EH UM PONTEIRO
*/
int main() {
	Ponto vetorPontos[TAM];
	//metodo sem retorno com 2 parametros
	//1o parametro eh passagem por referencia (endereco)
	//2o parametro eh passagem por valor (copia)
	populaPontos(vetorPontos,TAM);
	//metodo sem retorno com 2 parametros
	//1o parametro eh passagem por referencia (endereco)
	//2o parametro eh passagem por valor (copia)
	exibePontos(vetorPontos,TAM);
	/*
	string resposta = qualQuadrante(vetorPontos[3]);	
	cout << "O ponto estah: " << resposta << endl;
	*/
	exibeQuadrantePontos(vetorPontos,TAM);
	return 1;
}
