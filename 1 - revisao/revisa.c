#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

//estrutura de c�digo c PADR�O
main() {
	char nome[100];
	
	setlocale(LC_ALL, "Portuguese");
	
	printf("Seu nome: ");	
	gets(nome);
	
	printf ("ol� %s!\nSeja bem vindo a turma de algoritimos \n ", nome);
}
