#include <iostream>
#include <string>
#include <locale.h>
#include <sstream>
#include <time.h>
#include <ctime> 
#include <fstream>

#define TAM 10
#define NOMEARQUIVO "ceva.dat"

using namespace std;

typedef struct {
	string data;
	string estilo;
	float nota;
	string fabricante;
} Degustacao;

string pegaDataString() {
    time_t tempo = time(NULL);
	stringstream data;
    
    tm *horaLocal = localtime(&tempo);
    
	data << horaLocal->tm_mday << "/" << 1 + horaLocal->tm_mon << "/" 
         << 1900 + horaLocal->tm_year;
	
    return data.str();
}

void inicializaCeva(Degustacao vetor[], int n) {
	//inicializar garagem
	for (int i = 0; i < n; i++) {
		vetor[i].data = "";
		vetor[i].estilo = "";
		//vetor[i].nota = "";
		vetor[i].fabricante = "";
	}
}

string paraMaiusculo(string palavra) {
	int i = 0;
    do{
        if ( palavra[i] == '\n' || palavra[i] == '\0')
        {      
            break;
        }
        palavra[i] = toupper(palavra[i]);
        i++;
    }while (1);

	return palavra;
}

void atualizaArquivoComCeva(Degustacao vetor[], int n) {
	ofstream procuradorEscrita;
	procuradorEscrita.open(NOMEARQUIVO);
	
	for (int i = 0; i < n; i++) {
		if (vetor[i].data != "") {
			procuradorEscrita << vetor[i].data 
			     << " " << vetor[i].estilo
                 << " " << vetor[i].nota 
				 << " " << vetor[i].fabricante << endl;
		}
	}
	procuradorEscrita.close();
}

void cadastraCerveja(Degustacao vetor[], int n, int qtdCeva) {
	int i;
	if (qtdCeva == TAM){
	   	cout << "Vetor lotado..." << endl;
	} else {
	   	qtdCeva++;
    	vetor[i].data = pegaDataString();
		cout << "Estilo da cerveja (Pilsen, APA, IPA, etc): ";
      	cin >> vetor[qtdCeva].estilo;
		vetor[i].estilo = paraMaiusculo(vetor[i].estilo);
			         	
		//validar se o estilo estah correto
			         	
		do {
			cout << "Nota geral [0 a 5]: ";			         	
			cin >> vetor[qtdCeva].nota;
		} while (vetor[qtdCeva].nota < 0 || vetor[qtdCeva].nota > 5);
       	cout << "Nome do fabricante: ";
       	cin >> vetor[qtdCeva].fabricante;
	}

	//atualiza arquivo carros.dat com os carros
	//da garagem
	atualizaArquivoComCeva(vetor, n);
	
	cout << "Cerveja cadastrada na degustação!" << endl;
}

void listaCevaDegustacao(Degustacao vetor[], int n){
	for (int i = 0; i < n; i++) {
		if (vetor[i].data != "") {
			cout << "-------------------------" << endl;
		    cout << "Data      : " << vetor[i].data << endl;
	    	cout << "Estilo    : " << vetor[i].estilo << endl;
	    	cout << "Nota      : " << vetor[i].nota << endl;
	    	cout << "Fabricante: " << vetor[i].fabricante << endl;
	      	cout << "-------------------------" << endl;
		}
	}
}

void listaCevaTipo(Degustacao vetor[], int i, int qtdCeva){
    cout << "Listagem por estilo de cerveja" << endl;
	if (qtdCeva == -1) {
	cout << "Nenhuma degusta��o cadastrada..." << endl;
	} else {
		string estiloPesquisa;
		cout << "Digite o estilo de cerveja para pesquisar: ";
		cin >> estiloPesquisa;
		estiloPesquisa = paraMaiusculo(estiloPesquisa);
			         	
	    for (int i = 0; i <= qtdCeva; i++) {
		    if (estiloPesquisa == vetor[i].estilo) {
		    cout << "-------------------------" << endl;
		    cout << "Data      : " << vetor[i].data << endl;
	    	cout << "Estilo    : " << vetor[i].estilo << endl;
	    	cout << "Nota      : " << vetor[i].nota << endl;
	    	cout << "Fabricante: " << vetor[i].fabricante << endl;
	      	cout << "-------------------------" << endl;
	    	}
    	}
        int i = 0;
	   	cout << "Total de degusta��es do estilo: " << i+1 << endl;
	}
}

void converte(string linha, string *data, string *estilo, float *nota, string *fabricante) {
	stringstream sData, 
	             sEstilo,
                 sNota,
		         sFabricante;
	int parteLinha = 0; //0 para placa; 1 para data; 2 para hora
	int i;
	for (i = 0; linha[i] != ' '; i++) {
		sData << linha[i];
	}
	sData << "\0";
	stringstream conversaoData(sData.str());
	conversaoData >> *data;
	
	for (++i; linha[i] != ' '; i++) {
		sEstilo << linha[i];
	}
	sEstilo << "\0";
	stringstream conversaoEstilo(sEstilo.str());
	conversaoEstilo >> *estilo;

    for (++i; linha[i] != ' '; i++) {
		sData << linha[i];
	}
	sData << "\0";
	stringstream conversaoNota(sNota.str());
	conversaoNota >> *nota;
	
	for (++i; i < linha.length(); i++) {
		sFabricante << linha[i];
	}
	sFabricante << "\0";
	stringstream conversaoFabricante(sFabricante.str());
	conversaoFabricante >> *fabricante;
}


int populaCevaArquivo(ifstream &procurador, Degustacao vetor[], int n) {
    string conteudoLinha;
    int i = 0;
    //transferir o conteudo do arquivo para o vetor garagem
    while (getline(procurador,conteudoLinha)) {
        //cout << conteudoLinha << endl;
        converte(conteudoLinha, &vetor[i].data,
		                        &vetor[i].estilo,
                                &vetor[i].nota,
								&vetor[i].fabricante);
        i++;
        
    }
    return i;
}

int main() {
	setlocale(LC_ALL,"Portuguese");
	int opcao;
	int qtdCeva = 0;
	Degustacao vetor[TAM];
	inicializaCeva(vetor, TAM);
    ofstream procuradorEscrita;
    ifstream procuradorLeitura;
    procuradorLeitura.open(NOMEARQUIVO);
    if (procuradorLeitura) {
        //popula vetor garagem
        qtdCeva = populaCevaArquivo(procuradorLeitura, vetor, TAM);
        cout << "Arquivo lido para vetor" << endl;
        procuradorLeitura.close();
    } else {
        //cria arquivo
        procuradorEscrita.open(NOMEARQUIVO);
        procuradorEscrita.close();
    }
    
	do {
		//system("cls");	
		cout << "Menu Degusta Cerveja Artesanal" << endl;
		cout << "1 - Cadastrar degusta��o" << endl;
		cout << "2 - Listar degusta��es" << endl;
		cout << "3 - Lista degusta��es por estilo de cerveja" << endl;
		cout << "4 - Ranking das cervejas" << endl;
		cout << "5 - Sair" << endl;
		cout << "Op��o: ";
		cin >> opcao;
		
		switch (opcao) {
			case 1 : //entrada veiculo
			         cout << "Cadastrar degusta��o" << endl;
			         if (qtdCeva == TAM) {
			         	cout << "Arquivo lotada." << endl;
			         } else {
			         	qtdCeva++;
			         	cadastraCerveja(vetor, TAM, qtdCeva);
						//grava vetor em arquivo
			         }
			         break;
			case 2 : //saida veiculo
			 		 cout << "Listar degusta��es" << endl;
			 		 if (qtdCeva == 0) {
			 		 	cout << "Arquivo vazio." << endl;
			 		 } else {
			 		 	listaCevaDegustacao(vetor, TAM);
						//atualiza vetor em arquivo
						qtdCeva--; 
					 }
			         break;
			case 3 : //listagem de veiculos na garagem
					 cout << "Lista degusta��es por estilo de cerveja" << endl;
					 if (qtdCeva == 0) {
					 	cout << "Arquivo vazio." << endl;
					 } else {					 
						 listaCevaTipo(vetor, TAM, qtdCeva);
					 }
			         break;
			case 4 : //relatorios
			         break;
			case 5 : cout << "Obrigado por usar o sistema." << endl;
			         break;
			default: cout << "Op��o inv�lida." << endl;	 		 		 			         
		}
	} while (opcao != 5);
	return 1;
}
