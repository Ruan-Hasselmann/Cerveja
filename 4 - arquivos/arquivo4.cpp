#include <iostream>
#include <fstream>
#include <numeric>
#include <locale.h>
#include <time.h>
#include <cstdlib>
#define TAM 15
using namespace std;

int main() {
    setlocale(LC_ALL,"Portuguese");
    cout << "Programa4 para escrever numeros de vetor em arquivo"  << endl;   
    int vetor[TAM];
    char nomeArquivo[200];
    ofstream procuradorEscrita;

    //gerar numeros aleatorios dentro do vetor
    srand(time(NULL));
    for (int i = 0; i < TAM; i++) {
        vetor[i] = rand() % 1000;
    }

    //ORDENANDO PELO BOLHA
    int i, aux, houveTroca;
        do {
            houveTroca = 0;
            for (i = 0; i < TAM - 1; i++) {
                if (vetor[i] < vetor[i+1]) {
                    houveTroca = 1;
                    aux = vetor[i];
                    vetor[i] = vetor[i+1];
                    vetor[i+1] = aux;
                }
            }
        } while (houveTroca);

    cout << "Digite o nome do arquivo a ser aberto para adicionar numeros: ";
    cin >> nomeArquivo;

    procuradorEscrita.open(nomeArquivo);
    
    for (int i = 0; i < TAM; i++) {
        procuradorEscrita << vetor[i] << endl;
    }

    procuradorEscrita.close();
    return 1;
}