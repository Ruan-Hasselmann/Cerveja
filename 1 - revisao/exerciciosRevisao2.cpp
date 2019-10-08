/*
Escrever um algoritmo para ler quatro valores inteiros, calcular a sua média, e escrever na tela os que são superiores à média.
 */

#include <iostream>
#include <string>
#include <locale.h>

#define TAM 4

using namespace std;

int main()
{
    setlocale(LC_ALL, "Portuguese");
    int* valores = new int[TAM]; //versão c++ para vetor
    //int valores[TAM]; //versão c para vetor

    int i;
    float media = 0;

    for (i = 0; i < TAM; i++)
    {
        cout << "Digite um valor inteiro: ";
        cin >> valores[i];

        media = media + valores[i];
    }
    
    media = media / TAM;

    cout << "A media dos valores é: " << media << "\n";

    for (i = 0; i < TAM; i++)
    {
        if (valores[i] > media)
        {
            cout << valores[i] << "\n";
        }
        
    }

    return 1;
}