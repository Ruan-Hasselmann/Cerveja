/*
Escreva um algoritmo para calcular o reajuste salarial de uma empresa que possui 1000 funcionários, de acordo com os seguintes critérios:
•os funcionários com salário inferior a 10.000 devem receber 55% de reajuste
•os funcionários com salário entre 10.000 e 25.000 devem receber 30% de reajuste.
•os funcionários com salário acima de 25.000 devem receber 20% de reajuste.
 */

#include <iostream>
#include <string>
#include <locale.h>
#include <cstdlib> //para srand e rand()
#include <time.h>
#define TAM 4

using namespace std;

int main()
{
    setlocale(LC_ALL, "Portuguese");
    srand(time(NULL));

    float vetorSalarios[TAM];
    //float *vetorSalarios = new float[TAM]; //em c++
    cout << "Gerando salários aleatórios \n";
    for (int i = 0; i < TAM; i++)
    {
        vetorSalarios[i] = 1500 + rand() % 25000;
        cout << "Salario " << (i+1) << ": " << vetorSalarios[i] << "\n"; 
    }
    


    return 1;
}