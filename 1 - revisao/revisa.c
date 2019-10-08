#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

//estrutura de código c PADRÃO
main() {
	char nome[100];
	
	setlocale(LC_ALL, "Portuguese");
	
	printf("Seu nome: ");	
	gets(nome);
	
	printf ("olá %s!\nSeja bem vindo a turma de algoritimos \n ", nome);
}
