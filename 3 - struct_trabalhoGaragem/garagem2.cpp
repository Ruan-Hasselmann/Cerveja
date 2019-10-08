#include <iostream>
#include <string>
#include <locale.h>
#define TAMANHOGARAGEM 10
using namespace std;

typedef struct {
	string placa;
	string dataEntrada;
	string horaEntrada;
	string dataSaida;
	string horaSaida;
	float valor;
} Vaga;

int main() {
	setlocale(LC_ALL,"Portuguese");
	int opcao;
	Vaga garagem[TAMANHOGARAGEM];
	int qtdCarros = 0;
	
	//inicializar garagem
	for (int i = 0; i < TAMANHOGARAGEM; i++) {
		garagem[i].placa = "";
		garagem[i].dataEntrada = "";
		garagem[i].horaEntrada = "";
		garagem[i].dataSaida = "";
		garagem[i].horaSaida = "";
		garagem[i].valor = 0;		
	}
	
	do {
		cout << "MENU GARAGEM" << endl;
		cout << "1 - Entrada ve�culo" << endl;
		cout << "2 - Sa�da ve�culo" << endl;
		cout << "3 - Lista ve�culos na garagem" << endl;
		cout << "4 - Relat�rios" << endl;
		cout << "5 - Sair" << endl;
		cout << "Op��o: ";
		cin >> opcao;
		
		switch (opcao) {
			case 1 : //entrada veiculo
			         cout << "ENTRADA DE VE�CULO" << endl;
			         if (qtdCarros == TAMANHOGARAGEM) {
			         	cout << "Garagem lotada." << endl;
			         } else {
			         	qtdCarros++;
			         	int i;
			         	for (i = 0; i < TAMANHOGARAGEM; i++){
			         		if (garagem[i].placa == "") {
			         			break;
			         		}
			         	}        				         	
						//outra opcao de for (i = 0; garagem[i].placa != ""; i++);			         	
			         	cout << "Placa: ";
			         	cin >> garagem[i].placa;
			         	cout << "Data entrada [dd/mm/aaaa]: ";
			         	cin >> garagem[i].dataEntrada;
			         	cout << "Hora entrada [hh:mm]: ";
			         	cin >> garagem[i].horaEntrada;
			         }
			         break;
			case 2 : //saida veiculo
			 		 cout << "SA�DA DE VE�CULO" << endl;
			 		 if (qtdCarros == 0) {
			 		 	cout << "Garagem vazia." << endl;
			 		 } else {
			 		 	string placa;
			 		 	cout << "Digite a placa para sa�da: ";
			 		 	cin >> placa;
			 		 	int i;
			 		 	for (i = 0; i < TAMANHOGARAGEM; i++) {
						 	if (garagem[i].placa == placa) {
						 		cout << "Carro localizado...." << endl;
						 		//calculo da cobran�a
						 		
						 		//impressao do valor
						 		
						 		//liberar a vaga
						 		garagem[i].placa = "";
								garagem[i].dataEntrada = "";
								garagem[i].horaEntrada = "";
								garagem[i].dataSaida = "";
								garagem[i].horaSaida = "";
								garagem[i].valor = 0;						 		
								qtdCarros--;
								break;
						 	}
					 	}
					 	if (i == TAMANHOGARAGEM) {
					 		cout << "Placa n�o localizada no sistema." << endl;
					 	}
			 		 }
			         break;
			case 3 : //listagem de veiculos na garagem
					 cout << "LISTAGEM DE VE�CULOS" << endl;
					 if (qtdCarros == 0) {
					 	cout << "Garagem vazia." << endl;
					 } else {					 
						 for (int i = 0; i < TAMANHOGARAGEM; i++) {
						 	if (garagem[i].placa != "") {
						 		cout << "Placa: " << garagem[i].placa << " Hora Entrada: " << garagem[i].horaEntrada <<endl;
						 	}
						 }
					 }
			         break;
			case 4 : //relatorios
			         break;
			case 5 : cout << "Obrigado por usar o sistema." << endl;
			         break;
			default: cout << "Op��o inv�lida." << endl;	 		 		 			         
		}
	} while (opcao != 5);
	return 1;
}
