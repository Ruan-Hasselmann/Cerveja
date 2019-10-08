#include <iostream>
#include <fstream>
#include <locale.h>
using namespace std;

int main() {
    setlocale(LC_ALL,"Portuguese");
    cout << "Programa1 para ler arquivo em cpp"  << endl;   

    char nomeArquivo[200];
    ifstream procuradorLeitura;

    cout << "Digite o nome do arquivo a ser aberto: ";
    cin >> nomeArquivo;

    procuradorLeitura.open(nomeArquivo);

    if (procuradorLeitura == NULL) {
        cout << "Arquivo não localizado" << endl;
    } else {
        cout << "Arquivo localizado e aberto" << endl;
        //percorrer o procurador e jogar conteudo na tela
        char conteudoLinha[200];

        while (procuradorLeitura >> conteudoLinha) {
            cout << conteudoLinha << endl;
        }
        procuradorLeitura.close();   
	}
    return 1;
}