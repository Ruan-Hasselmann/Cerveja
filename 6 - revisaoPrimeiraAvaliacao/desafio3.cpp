#include <iostream>
#include <cstdlib>
#include <time.h>

#define TAM 10

using namespace std;

int existe(int numero, int vetor[], int n) {
	for (int i = 0; i < n; i++) {
		if (numero == vetor[i]) { //localizado
			return 1; //encontrei
		}
	}
	return 0; //se chegou ate aqui, pq nao localizou
}

void populaControlandoDuplicidade(int vetor[], int n) {
	srand(time(NULL));
	
	int numero;
	
	for (int i = 0; i < n;  ) {
		numero = rand() % 20;
		if (!existe(numero, vetor, i)){
			vetor[i] = numero;
			i++;
		}		
	}
}

void exibe(int vetor[], int n) {
	for (int i = 0; i < n; i++) {
		cout << vetor[i] << "\t";
	}
	cout << endl;
}

void ordena(int vetor[], int n) { //metodo da bolha
	int i, houveTroca, aux;
	do {
		houveTroca = 0;
		for (i = 0; i < n-1; i++) {
			if (vetor[i] > vetor[i + 1]) {
				houveTroca = 1;
				aux = vetor[i];
				vetor[i] = vetor[i + 1];
				vetor[i + 1] = aux;
			}
		}
	} while (houveTroca);
}

int main() {
	int vetor[TAM];
	
	populaControlandoDuplicidade(vetor, TAM);
	cout << "Vetor original sem ordenacao" << endl;
	exibe(vetor, TAM);
	ordena(vetor, TAM);
	cout << "Vetor ordenado" << endl;
	exibe(vetor, TAM);
	return 1;
}
