#include <iostream>
#include <cstdlib>
#include <time.h>

#define TAM 3

using namespace std;

typedef struct {
	int matricula;
	string nome;
} Pessoa;

int existe(int numero, Pessoa vetor[], int n) {
	for (int i = 0; i < n; i++) {
		if (numero == vetor[i].matricula) { //localizado
			return 1; //encontrei
		}
	}
	return 0; //se chegou ate aqui, pq nao localizou
}

void paraMaiusculo(char palavra[]) {
    int i=0;
    do{
        if ( palavra[i] == '\n' || palavra[i] == '\0')
        {      
            break;
        }
        palavra[i] = toupper(palavra[i]);
        i++;
    }while (1);
}

void populaControlandoDuplicidade(Pessoa vetor[], int n) {
	int numero;
	string nome;
	
	for (int i = 0; i < n;  ) {
		cout << "Digite a matricula: ";
		cin >> numero;
		cin.ignore(); //equivale ao fflush do c
		
		if (!existe(numero, vetor, i)){
			cout << "Qual seu nome: ";
			getline (cin,nome);
			//nome = paraMaiusculo(nome);
			vetor[i].matricula = numero;
			vetor[i].nome = nome;
			i++;
		} else {
			cout << "Matricula jah existente. Redigite" << endl;
		}
	}
}

void exibe(Pessoa vetor[], int n) {
	for (int i = 0; i < n; i++) {
		cout << "Matricula: " << vetor[i].matricula << endl;
		cout << "Nome: " << vetor[i].nome << endl;
		cout << "----------------------------------" << endl;
	}
}

void ordena(Pessoa vetor[], int n, int tipo) { //metodo da bolha
	int i, houveTroca;
	Pessoa aux;
	if (tipo == 0) { //ordena por matricula	
		do {
			houveTroca = 0;
			for (i = 0; i < n-1; i++) {
				if (vetor[i].matricula > vetor[i + 1].matricula) {
					houveTroca = 1;
					aux = vetor[i];
					vetor[i] = vetor[i + 1];
					vetor[i + 1] = aux;
				}
			}
		} while (houveTroca);
	} else { //ordena por nome
		do {
			houveTroca = 0;
			for (i = 0; i < n-1; i++) {
				if (vetor[i].nome > vetor[i + 1].nome) {
					houveTroca = 1;
					aux = vetor[i];
					vetor[i] = vetor[i + 1];
					vetor[i + 1] = aux;
				}
			}
		} while (houveTroca);
	}
}

int main() {
	Pessoa vetor[TAM];
	
	populaControlandoDuplicidade(vetor, TAM);
	cout << "Vetor ordenado por matricula" << endl;
	ordena(vetor, TAM,0); //0 ordena por matricula
	exibe(vetor, TAM);
	
	
	cout << "Vetor ordenado por nome" << endl;
	ordena(vetor, TAM,1); //1 ordena por nome
	exibe(vetor, TAM);

	return 1;
}
