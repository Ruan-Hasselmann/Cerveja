#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

typedef struct {
	int matricula;
	string nome;
} Pessoa;

void atualizaNome(Pessoa *p, string novoNome) {
	//*p.nome = novoNome; ou
	
	p->nome = novoNome;
}

int main() {
	Pessoa p1;
	p1.matricula = 100;
	p1.nome = "Eduardo";
	printf("%p -> ", &p1);
	cout << p1.matricula << " - " << p1.nome << endl;
	atualizaNome(&p1,"Eduardo Palharini");	
	printf("%p -> ", &p1);
	cout << p1.matricula << " - " << p1.nome << endl;
	return 1;
}
