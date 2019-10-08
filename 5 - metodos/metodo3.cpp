#include <iostream>
#include <cstdlib>
#include <time.h>

#define TAM 10
using namespace std;

int recebeNumero(int numero) {
    cout << "Digite um numero inteiro: ";
    cin >> numero;

    return numero;
}

int modulo(int numero) {
    if (numero > 0) return numero;
    else return numero * -1;
}

int ehPrimo(int numero) {
    int i;
    if (numero == 0) cout << "Nao posso processar este tipo de numero" << endl;
    if (numero == 1 || numero == -1) return 0;

    numero = modulo(numero);

    for (i = 2; i < numero; i++) {
        if (numero % i == 0) return 0; //nao eh primo
    }

    return 1; //testei tudo e verifiquei que eh primo
}

void popula(int vetor[], int n) {
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        vetor[i] = (rand() % 20) - 10;
    }
}

void exibe(int vetor[], int n) {
    for (int i = 0; i < n; i++) {
        cout << vetor[i] << "\t";
    }
    cout << endl;
}

void quaisSaoPrimos(int vetor[], int n) {
    for (int i = 0; i < n; i++) {
        if (ehPrimo(vetor[i])) {
            cout << vetor[i] << " eh primo" << endl;
        }
    }
}

int main() {
    int vetor[TAM];
    popula(vetor, TAM);
    exibe(vetor, TAM);

    quaisSaoPrimos(vetor, TAM);

    return 1;
}