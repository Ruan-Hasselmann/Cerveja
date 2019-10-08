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
		cout << "1 - Entrada ve�culo" << endl;
		cout << "2 - Sa�da ve�culo" << endl;
		cout << "3 - Lista ve�culos na garagem" << endl;
		cout << "4 - Relat�rios" << endl;
		cout << "5 - Sair" << endl;
		cout << "Op��o: ";
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
			default: cout << "Op��o inv�lida." << endl;	 		 		 			         
		}
	} while (opcao != 5);
	return 1;
}
