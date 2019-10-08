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
	int qtdCarros = -1;
	
	do {
		cout << "MENU GARAGEM" << endl;
		cout << "1 - Entrada veículo" << endl;
		cout << "2 - Saída veículo" << endl;
		cout << "3 - Lista veículos na garagem" << endl;
		cout << "4 - Relatórios" << endl;
		cout << "5 - Sair" << endl;
		cout << "Opção: ";
		cin >> opcao;
		
		switch (opcao) {
			case 1 : //entrada veiculo
			         break;
			case 2 : //saida veiculo
			         break;
			case 3 : //listagem de veiculos na garagem
			         break;
			case 4 : //relatorios
			         break;
			case 5 : cout << "Obrigado por usar o sistema." << endl;
			         break;
			default: cout << "Opção inválida." << endl;	 		 		 			         
		}
	} while (opcao != 5);
	return 1;
}
