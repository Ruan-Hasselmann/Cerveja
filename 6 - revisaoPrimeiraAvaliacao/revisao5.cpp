#include <iostream>
#include <cstdlib>
#include <string>
#include <sstream>
#include <fstream>
using namespace std;

typedef struct {
	int x;
	int y;
	float valor;
} Ponto;

/**
	metodo que recebe 3 parametros
	linha contendo 3 valores de um ponto x y valor
	ponteiro para x
	ponteiro para y
	ponteiro para valor
	
	cada ponteiro vai receber seu valor respectivo da linha
*/
void converte(string linha, int *x, int *y, float *valor) {
	stringstream sX, 
	             sY, 
		         sValor;
	int parteLinha = 0; //0 para x; 1 para y; 2 para valor
	int i;
	for (i = 0; linha[i] != ' '; i++) {
		sX << linha[i];
	}
	sX << "\0";
	stringstream conversaoX(sX.str());
	conversaoX >> *x;
	
	for (++i; linha[i] != ' '; i++) {
		sY << linha[i];
	}
	sY << "\0";
	stringstream conversaoY(sY.str());
	conversaoY >> *y;
	
	for (++i; i < linha.length(); i++) {
		sValor << linha[i];
	}
	sValor << "\0";
	stringstream conversaoValor(sValor.str());
	conversaoValor >> *valor;
}

int main() {
	string linha;	
	Ponto umPonto;
	
	int x,y;
	float valor;
	
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
        while (getline(procuradorLeitura, linha)) {
				//metodo que recebe uma linha e endereco de x
				//                              endereco de y
				//                              endereco de valor
				converte(linha, &x, &y, &valor);
				
				umPonto.x = x;
				umPonto.y = y;
				umPonto.valor = valor;
	
				cout << umPonto.x << "," << umPonto.y << "," << umPonto.valor << endl;
		}
		procuradorLeitura.close();
	}
	return 1;
}
	
	
	

