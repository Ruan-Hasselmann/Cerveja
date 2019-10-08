#include <iostream>
#include <string>
#include <locale.h>
using namespace std;
typedef struct { //criacao de um tipo artificial
	string nome;
	float altura, peso, imc;
} IMC;
int main() {
	setlocale(LC_ALL,"Portuguese");
	IMC pessoa; //variavel pessoa eh heterogenea
	char opcao;
	do {	
		cout << "Seu nome é: ";
		cin >> pessoa.nome;
		
		cout << "Seu peso em kg: ";
		cin >> pessoa.peso;
		
		cout << "Sua altura em metros: ";
		cin >> pessoa.altura;
		
		pessoa.imc = pessoa.peso / (pessoa.altura * pessoa.altura);
		
		cout << pessoa.nome << " seu IMC é: " << pessoa.imc << endl;
		
		if (pessoa.imc < 18.5) {
			cout << " você está abaixo do peso" << endl;
		} else if (pessoa.imc < 24.9) {
			cout << " você está com peso normal" << endl;
		} else if (pessoa.imc < 29.9) {
			cout << " você está com sobre peso" << endl;
		} else  {
			cout << " você está ralado" << endl;
		}
		cout << "Continua [s/n]? ";
		cin >> opcao;
		
	} while (opcao == 'S' || opcao == 's');
	return 1;
}
