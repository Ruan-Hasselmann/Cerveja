#include <iostream>
#include <fstream>
#include <locale.h>
#include <numeric>
using namespace std;

int main() {
    setlocale(LC_ALL,"Portuguese");
    cout << "Programa2 para ler arquivo em cpp"  << endl;   

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
        int vetor[100];
        int numero;
        int ultimoElemento = 0;
        while (procuradorLeitura >> conteudoLinha) {
            numero = atoi(conteudoLinha);
            vetor[ultimoElemento] = numero;
            ultimoElemento++;            
            //cout << conteudoLinha << endl;
        }
        
        procuradorLeitura.close();   
        cout << "Conteúdo do arquivo!" << endl;
        for (int i = 0; i < ultimoElemento; i++) {
            cout << vetor[i] << endl;
        }

        //rotina para ordenar vetor de inteiros - metodo da bolha
        //indice i
        //aux para trocas
        //booleano para a ordenacao
        int i, aux, houveTroca;
        do {
            houveTroca = 0;
            for (i = 0; i < ultimoElemento - 1; i++) {
                if (vetor[i] < vetor[i+1]) {
                    houveTroca = 1;
                    aux = vetor[i];
                    vetor[i] = vetor[i+1];
                    vetor[i+1] = aux;
                }
            }
        } while (houveTroca);

        cout << "Conteúdo do vetor agora ordenado!" << endl;
        for (int i = 0; i < ultimoElemento; i++) {
            cout << vetor[i] << endl;
        }
	}
    return 1;
}