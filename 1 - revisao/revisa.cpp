#include <iostream>
#include <string>
#include <locale.h>

using namespace std;

int main() {
	string nome;
	
	setlocale(LC_ALL, "Portuguese");
	
	cout << "Seu nome: ";
	cin >> nome;
	
	cout << "ol� " << nome << "!\nSeja bem vindo a turma de algoritimos\n";
	
	return 1;
}
