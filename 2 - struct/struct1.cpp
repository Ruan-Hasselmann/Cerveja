#include <iostream>
#include <string>
#include <locale.h>
using namespace std;
int main() {
	setlocale(LC_ALL,"Portuguese");
	string nome;
	float altura, peso;
	
	cout << "Seu nome �: ";
	cin >> nome;
	
	cout << "Seu peso em kg: ";
	cin >> peso;
	
	cout << "Sua altura em metros: ";
	cin >> altura;
	
	float imc = peso / (altura * altura);
	
	cout << nome << " seu IMC �: " << imc << endl;
	
	/*Menos do que 18,5 	Abaixo do peso
	Entre 18,5 e 24,9 	Peso normal
	Entre 25 e 29,9 	Sobrepeso
	Entre 30 e 34,9 	Obesidade grau 1
	Entre 35 e 39,9 	Obesidade grau 2
	Mais do que 40 	Obesidade grau 3*/
	
	if (imc < 18.5) {
		cout << nome << " voc� est� abaixo do peso" << endl;
	} else if (imc < 24.9) {
		cout << nome << " voc� est� com peso normal" << endl;
	} else if (imc < 29.9) {
		cout << nome << " voc� est� com sobre peso" << endl;
	} else  {
		cout << nome << " voc� est� ralado" << endl;
	}
	
	return 1;
}
