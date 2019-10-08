#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;
int main() {
	int vetor[] = {10, 15, 20};
	printf("Endereco principal de vetor: %p\n", vetor);
	for (int i = 0; i < 3; i++) {
		printf("%p -> %d\n", &vetor[i], vetor[i]);
	}
	
	int *outroVetor;
	int tamanho;
	cout << "Qtos elementos quer no vetor?";
	cin >> tamanho;
	outroVetor = (int *)malloc(sizeof(int) * tamanho);
	for (int i = 0; i < tamanho; i++) {
		outroVetor[i] = i;
	}
	
	printf("Endereco principal de outroVetor: %p\n", outroVetor);
	for (int i = 0; i < tamanho; i++) {
		printf("%p -> %d\n", &outroVetor[i], outroVetor[i]);
	}
	free(outroVetor);
	cin >> tamanho;
	return 1;
}
