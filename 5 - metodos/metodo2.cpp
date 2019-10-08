#include <iostream>
using namespace std;
void mostraIntervalo(int numero) {
    int i;
    for (i = 0; i <= numero; i++) {
        cout << i << endl;
    }
}

int recebeNumero(int numero) {
    cout << "Digite um numero inteiro: ";
    cin >> numero;

    return numero;
}

int ehPar(int numero) {
   return numero % 2 == 0; 
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

int main() {
    int numero;
    numero = recebeNumero(numero);
    mostraIntervalo(numero);

    if (ehPar(numero)) {
        cout << "Numero digitado eh par" << endl;
    } else {
        cout << "Numero digitado nao eh par, ou seja, impar" << endl;
    }

    if (ehPrimo(numero)) {
        cout << numero << " eh primo" << endl;
    } else {
        cout << numero << " nao eh primo" << endl;
    }


    return 1;
}