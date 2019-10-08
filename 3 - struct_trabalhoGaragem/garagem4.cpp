#include <iostream>
#include <string>
#include <locale.h>
#include <sstream>
#include <time.h>

#include <ctime> 
#include <fstream>

#define TAMANHOGARAGEM 10
using namespace std;

typedef struct {
	string placa;
	string dataEntrada;
	string horaEntrada;
	string dataSaida;
	string horaSaida;
	float valor;
} Vaga;

string pegaDataString() {
    time_t tempo = time(NULL);
	stringstream data;
    
    tm *horaLocal = localtime(&tempo);
    
	data << horaLocal->tm_mday << "/" << 1 + horaLocal->tm_mon << "/" 
         << 1900 + horaLocal->tm_year << endl;
	
    return data.str();
}

string pegaHoraString() {
    time_t tempo = time(NULL);
	stringstream hora;
    
    tm *horaLocal = localtime(&tempo);
    
	hora << horaLocal->tm_hour << ":" << horaLocal->tm_min << endl;
	
    return hora.str();
}

void inicializaGaragem(Vaga garagem[], int n) {
	//inicializar garagem
	for (int i = 0; i < n; i++) {
		garagem[i].placa = "";
		garagem[i].dataEntrada = "";
		garagem[i].horaEntrada = "";
		garagem[i].dataSaida = "";
		garagem[i].horaSaida = "";
		garagem[i].valor = 0;		
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

void entraCarroGaragem(Vaga garagem[], int n) {
	int i;
	for (i = 0; i < n; i++){
		if (garagem[i].placa == "") {
			break;
		}
	}        				         	
	//outra opcao de for (i = 0; garagem[i].placa != ""; i++);			         	
	cout << "Placa: ";
	cin >> garagem[i].placa;

	garagem[i].placa = paraMaiusculo(garagem[i].placa);

	garagem[i].dataEntrada = pegaDataString();
	garagem[i].horaEntrada = pegaHoraString();
	cout << "Carro cadastrado na garagem" << endl;
}

void saidaCarroGaragem(Vaga garagem[], int n) {
	string placa;
	cout << "Digite a placa para saÃ­da: ";
	cin >> placa;

	placa = paraMaiusculo(placa);
	
	int i;
	for (i = 0; i < n; i++) {
		if (garagem[i].placa == placa) {
			cout << "Carro localizado...." << endl;
			//calculo da cobranï¿½a
			cout << "Saida: " << pegaHoraString() << endl;
			//impressao do valor
			//liberar a vaga
			garagem[i].placa = "";
			garagem[i].dataEntrada = "";
			garagem[i].horaEntrada = "";
			garagem[i].dataSaida = "";
			garagem[i].horaSaida = "";
			garagem[i].valor = 0;
			cout << "SaÃ­da da garagem OK" << endl;						 		
			break;
		}
	}
	if (i == n) {
		cout << "Placa nÃ£o localizada no sistema." << endl;
	}
}

void listaCarrosGaragem(Vaga garagem[], int n){
	for (int i = 0; i < n; i++) {
		if (garagem[i].placa != "") {
			cout << "Placa: " << garagem[i].placa << endl;
			cout << "Data Entrada: " << garagem[i].dataEntrada << endl;
			cout << "Hora Entrada: " << garagem[i].horaEntrada << endl;
			cout << "------------------------------------" << endl;
		}
	}
}

void converte(string linha, string *placa, string *data, string *hora) {
	stringstream sPlaca, 
	             sData, 
		         sHora;
	int parteLinha = 0; //0 para placa; 1 para data; 2 para hora
	int i;
	for (i = 0; linha[i] != ' '; i++) {
		sPlaca << linha[i];
	}
	sPlaca << "\0";
	stringstream conversaoPlaca(sPlaca.str());
	conversaoPlaca >> *placa;
	
	for (++i; linha[i] != ' '; i++) {
		sData << linha[i];
	}
	sData << "\0";
	stringstream conversaoData(sData.str());
	conversaoData >> *data;
	
	for (++i; i < linha.length(); i++) {
		sHora << linha[i];
	}
	sHora << "\0";
	stringstream conversaoHora(sHora.str());
	conversaoHora >> *hora;
}


int populaGaragemArquivo(ifstream &procurador, Vaga garagem[], int n) {
    string conteudoLinha;
    int i = 0;
    //transferir o conteudo do arquivo para o vetor garagem
    while (getline(procurador,conteudoLinha)) {
        //cout << conteudoLinha << endl;
        converte(conteudoLinha, &garagem[i].placa,
		                        &garagem[i].dataEntrada,
								&garagem[i].horaEntrada);
        i++;
        
    }
    return i;
}

int main() {
	setlocale(LC_ALL,"Portuguese");
	int opcao;
	int qtdCarros = 0;
	Vaga garagem[TAMANHOGARAGEM];
	inicializaGaragem(garagem, TAMANHOGARAGEM);
    ofstream procuradorEscrita;
    ifstream procuradorLeitura;
    procuradorLeitura.open("carros.dat");
    if (procuradorLeitura) {
        //popula vetor garagem
        qtdCarros = populaGaragemArquivo(procuradorLeitura, garagem, TAMANHOGARAGEM);
        cout << "Arquivo lido para vetor" << endl;
        procuradorLeitura.close();
    } else {
        //cria arquivo
        procuradorEscrita.open("carros.dat");
    }
    
	do {
		cout << "MENU GARAGEM" << endl;
		cout << "1 - Entrada veículo" << endl;
		cout << "2 - Saída veículo" << endl;
		cout << "3 - Lista veículos na garagem" << endl;
		cout << "4 - Relatórios" << endl;
		cout << "5 - Sair" << endl;
		cout << "Opção: ";
		cin >> opcao;
		
		switch (opcao) {
			case 1 : //entrada veiculo
			         cout << "ENTRADA DE VEÍCULO" << endl;
			         if (qtdCarros == TAMANHOGARAGEM) {
			         	cout << "Garagem lotada." << endl;
			         } else {
			         	qtdCarros++;
			         	entraCarroGaragem(garagem, TAMANHOGARAGEM);
						//grava vetor em arquivo
			         }
			         break;
			case 2 : //saida veiculo
			 		 cout << "SAÍDA DE VEÍCULO" << endl;
			 		 if (qtdCarros == 0) {
			 		 	cout << "Garagem vazia." << endl;
			 		 } else {
			 		 	saidaCarroGaragem(garagem, TAMANHOGARAGEM);
						//atualiza vetor em arquivo
						qtdCarros--; 
					 }
			         break;
			case 3 : //listagem de veiculos na garagem
					 cout << "LISTAGEM DE VEÍCULOS" << endl;
					 if (qtdCarros == 0) {
					 	cout << "Garagem vazia." << endl;
					 } else {					 
						 listaCarrosGaragem(garagem, TAMANHOGARAGEM);
					 }
			         break;
			case 4 : //relatorios
			         break;
			case 5 : cout << "Obrigado por usar o sistema." << endl;
                     procuradorEscrita.close();
			         break;
			default: cout << "Opção inválida." << endl;	 		 		 			         
		}
	} while (opcao != 5);
	return 1;
}
