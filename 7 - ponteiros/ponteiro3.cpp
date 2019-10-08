#include <iostream>
#include <string>

#include <stdio.h>
#include <stdlib.h>

using namespace std;

typedef struct {
	int matricula;
	string nome;
} Pessoa;

void troca(int *a, int *b) {
	int aux = *a;
	*a = *b;
	*b = aux;
}



int main() {
	int vetor[] = {10, 15, 20};
	printf("Endereco principal de vetor: %p\n", vetor);
	for (int i = 0; i < 3; i++) {
		printf("%p -> %d\n", &vetor[i], vetor[i]);
	}
	
	troca(&vetor[0], &vetor[1]);
	
	printf("Endereco principal de vetor: %p\n", vetor);
	for (int i = 0; i < 3; i++) {
		printf("%p -> %d\n", &vetor[i], vetor[i]);
	}
	
	
	return 1;
}
