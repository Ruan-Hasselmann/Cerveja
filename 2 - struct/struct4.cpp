#include <iostream>
#include <string>
#include <locale.h>
#include <stdlib.h>
#include <stdio.h>
#define TAM 100 //constante para o tamanho do vetor
using namespace std;
typedef struct { //criacao de um tipo artificial
	string data; //dd/mm/aaaa
	string estilo;
	int nota; //0 a 5
	string fabricante;
} Degustacao;

int main() {
	setlocale(LC_ALL,"Portuguese");
	Degustacao vetor[TAM];
	int qtdDegustacao = -1;
	
	
	int opcao;
	int i = 0; //indice para o vetor de no maximo TAM pessoas
	do {
	    system("cls");	
		cout << "Menu Degusta Cerveja Artesanal" << endl;
		cout << "1 - Cadastrar degustação" << endl;
		cout << "2 - Listar degustações" << endl;
		cout << "3 - Lista degustações por estilo de cerveja" << endl;
		cout << "4 - Ranking das cervejas" << endl;
		cout << "5 - Sair" << endl;
		cout << "Opção: ";
		cin >> opcao;
		
		switch (opcao) {
			case 1 : cout << "Cadastra degustação" << endl;	
			         if (qtdDegustacao == TAM){
			         	cout << "Vetor lotado..." << endl;
			         } else {
			         	qtdDegustacao++;
			         	cout << "Data [dd/mm/aaaa]: ";
			         	cin >> vetor[qtdDegustacao].data;
			         	cout << "Estilo da cerveja (Pilsen, APA, IPA, etc): ";
			         	cin >> vetor[qtdDegustacao].estilo;
			         	
			         	//validar se o estilo estah correto
			         	
			         	do {
							cout << "Nota geral [0 a 5]: ";			         	
						 	cin >> vetor[qtdDegustacao].nota;
					    } while (vetor[qtdDegustacao].nota < 0 || vetor[qtdDegustacao].nota > 5);
			         	cout << "Nome do fabricante: ";
			         	cin >> vetor[qtdDegustacao].fabricante;			         	
			         }		         
			         break;
			case 2 : cout << "Listagem de degustações" << endl;
			         if (qtdDegustacao == -1) {
			         	cout << "Nenhuma degustação cadastrada..." << endl;
			         } else {
			         	for (int i = 0; i <= qtdDegustacao; i++) {
			         		cout << "-------------------------" << endl;
			         		cout << "Data      : " << vetor[i].data << endl;
			         		cout << "Estilo    : " << vetor[i].estilo << endl;
			         		cout << "Nota      : " << vetor[i].nota << endl;
			         		cout << "Fabricante: " << vetor[i].fabricante << endl;
			         		cout << "-------------------------" << endl;
			         	}
			         }
			         cout << "Total de degustações: " << qtdDegustacao+1 << endl;
			         break;         
			case 3 : cout << "Listagem por estilo de cerveja" << endl;
			         if (qtdDegustacao == -1) {
			         	cout << "Nenhuma degustação cadastrada..." << endl;
			         } else {
			         	string estiloPesquisa;
			         	cout << "Digite o estilo de cerveja para pesquisar: ";
			         	cin >> estiloPesquisa;
			         	
			         	for (int i = 0; i <= qtdDegustacao; i++) {
			         		if (estiloPesquisa == vetor[i].estilo) {
				         		cout << "-------------------------" << endl;
				         		cout << "Data      : " << vetor[i].data << endl;
				         		cout << "Estilo    : " << vetor[i].estilo << endl;
				         		cout << "Nota      : " << vetor[i].nota << endl;
				         		cout << "Fabricante: " << vetor[i].fabricante << endl;
				         		cout << "-------------------------" << endl;
				         	}
			         	}
			         	cout << "Total de degustações do estilo: " << i+1 << endl;
			         }
			         break;
			case 4 : cout << "Ranking de cervejas" << endl;
			         break;
            case 5 : cout << "Tchau. Obrigado." << endl;
                     exit(1);
			default : cout << "Opção inválida....." << endl;
		}		
		cout << "Tecle ENTER para continuar....";
		getchar();
		cin.ignore();
	} while ((opcao != 5) && (i < TAM));
	
	
	
	return 1;
}
