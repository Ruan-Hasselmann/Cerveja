#include <iostream>
#include <string>
#include <locale.h>
#define TAM 5 //constante para o tamanho do vetor
using namespace std;
typedef struct { //criacao de um tipo artificial
	string nome;
	float altura, peso, imc;
} IMC;
int main() {
	setlocale(LC_ALL,"Portuguese");
	IMC vetorPessoa[TAM];
	char opcao;
	int i = 0; //indice para o vetor de no maximo TAM pessoas
	do {	
		cout << "Seu nome é: ";
		cin >> vetorPessoa[i].nome;
		
		cout << "Seu peso em kg: ";
		cin >> vetorPessoa[i].peso;
		
		cout << "Sua altura em metros: ";
		cin >> vetorPessoa[i].altura;
		
		vetorPessoa[i].imc = vetorPessoa[i].peso / (vetorPessoa[i].altura * vetorPessoa[i].altura);
		
		cout << vetorPessoa[i].nome << " seu IMC é: " << vetorPessoa[i].imc << endl;
		
		if (vetorPessoa[i].imc < 18.5) {
			cout << "você está abaixo do peso" << endl;
		} else if (vetorPessoa[i].imc < 24.9) {
			cout << "você está com peso normal" << endl;
		} else if (vetorPessoa[i].imc < 29.9) {
			cout << "você está com sobre peso" << endl;
		} else  {
			cout << "você está ralado" << endl;
		}
		cout << "Continua [s/n]? ";
		cin >> opcao;
		i++;		
	} while ((opcao == 'S' || opcao == 's') && (i < TAM));
	
	cout << "Lista dos cadastrados..." << endl;
	for (int iAux = 0; iAux < i; iAux++) {
		cout << vetorPessoa[iAux].nome << " - IMC: " << vetorPessoa[iAux].imc << endl; 
	}
	return 1;
}
