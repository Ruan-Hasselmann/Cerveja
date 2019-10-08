#include <iostream>
#include <fstream>
#include <locale.h>
#include <numeric>
using namespace std;

int main() {
    setlocale(LC_ALL,"Portuguese");
    cout << "Programa3 para escrever nomes em arquivo"  << endl;   

    char nomeArquivo[200];
    ofstream procuradorEscrita;

    cout << "Digite o nome do arquivo a ser aberto para adicionar nomes: ";
    cin >> nomeArquivo;

    procuradorEscrita.open(nomeArquivo);
    char nome[100];
    int op;
    do {
        cout << "Digite um nome: ";
        cin >> nome;
        procuradorEscrita << nome << endl;
        cout << "Continua? Tecle 1: ";
        cin >> op;
        
    } while (op == 1);

    procuradorEscrita.close();
    return 1;
}