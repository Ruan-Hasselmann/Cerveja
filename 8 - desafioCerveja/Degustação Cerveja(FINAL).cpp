#include <iostream>
#include <string>
#include <sstream>
#include <ctime>
#include <fstream>

#include <stdlib.h>
#include <time.h>
#include <locale.h>

#define TAM 10
#define NOMEARQUIVO "ceva.dat"

using namespace std;

typedef struct
{
	string nome;
	string data;
	string estilo;
	int nota;
	string fabricante;
} Degustacao;

string pegaDataString()
{
	time_t tempo = time(NULL);
	stringstream data;

	tm *horaLocal = localtime(&tempo);

	data << horaLocal->tm_mday << "/" << 1 + horaLocal->tm_mon << "/"
		 << 1900 + horaLocal->tm_year;

	return data.str();
}

string paraMaiusculo(string palavra)
{
	int i = 0;
	do
	{
		if (palavra[i] == '\n' || palavra[i] == '\0')
		{
			break;
		}
		palavra[i] = toupper(palavra[i]);
		i++;
	} while (1);

	return palavra;
}

void atualizaArquivoComCeva(Degustacao vetor[], int qtdCeva)
{
	ofstream procuradorEscrita;
	procuradorEscrita.open(NOMEARQUIVO);

	for (int i = 0; i < qtdCeva; i++)
	{
		if (vetor[i].nome != "")
		{
			procuradorEscrita << vetor[i].nome
							  << " " << vetor[i].data
							  << " " << vetor[i].estilo
							  << " " << vetor[i].nota
							  << " " << vetor[i].fabricante << endl;
		}
	}

	procuradorEscrita.close();
}

void cadastraCerveja(Degustacao vetor[], int n, int qtdCeva)
{
	int i;

	for (i = 0; i < n; i++)
	{
		if (vetor[i].estilo == "")
		{
			break;
		}
	}

	cout << "PARA NOME COMPOSTO UTILIZE HIFEM '-' !" << endl;
	cout << "Nome: ";
	cin >> vetor[i].nome;

	vetor[i].data = pegaDataString();

	cout << "PARA NOME COMPOSTO UTILIZE HIFEM '-' !" << endl;
	cout << "Estilo: ";
	cin >> vetor[i].estilo;

	do
	{
		cout << "Nota geral [0 a 5]: ";
		cin >> vetor[i].nota;
	} while (vetor[i].nota < 0 || vetor[i].nota > 5);

	cout << "PARA NOME COMPOSTO UTILIZE HIFEM '-' !" << endl;
	cout << "Fabricante: ";
	cin >> vetor[i].fabricante;

	vetor[i].nome = paraMaiusculo(vetor[i].nome);

	vetor[i].estilo = paraMaiusculo(vetor[i].estilo);

	vetor[i].fabricante = paraMaiusculo(vetor[i].fabricante);

	atualizaArquivoComCeva(vetor, qtdCeva);

	cout << "Cerveja cadastrada na degustação!" << endl;

	system("cls");
}

void listaCevaTipo(Degustacao vetor[], int i, int qtdCeva)
{
	system("cls");

	int tipoCeva = 0;
	cout << "Listagem por estilo de cerveja" << endl;
	if (qtdCeva == -1)
	{
		cout << "Nenhuma degustação cadastrada..." << endl;
	}
	else
	{
		string estiloPesquisa;

		cout << "Digite o estilo de cerveja para pesquisar: ";
		cin >> estiloPesquisa;

		estiloPesquisa = paraMaiusculo(estiloPesquisa);

		system("cls");

		for (int i = 0; i <= qtdCeva; i++)
		{
			if (estiloPesquisa == vetor[i].estilo)
			{
				cout << "-------------------------" << endl;
				cout << "Nome      : " << vetor[i].nome << endl;
				cout << "Data      : " << vetor[i].data << endl;
				cout << "Estilo    : " << vetor[i].estilo << endl;
				cout << "Nota      : " << vetor[i].nota << endl;
				cout << "Fabricante: " << vetor[i].fabricante << endl;
				cout << "-------------------------" << endl;
				tipoCeva++;
			}
		}

		cout << "Total de degustações do estilo: " << tipoCeva << endl
			 << endl;
	}
}

void organizaNota(Degustacao vetor[], int n)
{
	system("cls");

	int i, houveTroca;
    Degustacao aux;
    do{
        houveTroca = 0;
        for(i = 0; i < n-1; i++){
            if(vetor[i].nota < vetor[i+1].nota){
                houveTroca = 1;
                aux = vetor[i];
                vetor[i] = vetor[i+1];
                vetor[i+1] = aux;
            }
        }
    }while(houveTroca);
}

void listaCevaDegustacao(Degustacao vetor[], int qtdCeva)
{
	system("cls");

	for (int i = 0; i < qtdCeva; i++)
	{
		if (vetor[i].nome != "")
		{
			cout << "-------------------------" << endl;
			cout << "Nome      : " << vetor[i].nome << endl;
			cout << "Data      : " << vetor[i].data << endl;
			cout << "Estilo    : " << vetor[i].estilo << endl;
			cout << "Nota      : " << vetor[i].nota << endl;
			cout << "Fabricante: " << vetor[i].fabricante << endl;
			cout << "-------------------------" << endl;
		}
	}
}

void apagarDegustacao(Degustacao vetor[], int qtdCeva, int n)
{
	string nome;
	cout << "Digite o nome para excluir: ";
	cin >> nome;

	nome = paraMaiusculo(nome);

	int i;
	for (i = 0; i < n; i++)
	{
		if (vetor[i].nome == nome)
		{
			cout << "Cerveja excluida...." << endl;

			vetor[i].nome = "";
			vetor[i].data = "";
			vetor[i].estilo = "";
			vetor[i].nota = 0;
			vetor[i].fabricante = "";

			atualizaArquivoComCeva(vetor, n);

			break;
		}
	}
	if (i == n)
	{
		cout << "Cerveja não localizada no sistema." << endl;
	}
}

void converte(string linha, string *nome, string *data, string *estilo, int *nota, string *fabricante)
{
	stringstream sNome, sData, sEstilo, Nota, sFabricante;

	int parteLinha = 0;
	int i;

	for (i = 0; linha[i] != ' '; i++)
	{
		sNome << linha[i];
	}
	sNome << "\0";
	stringstream conversaoNome(sNome.str());
	conversaoNome >> *nome;

	for (++i; linha[i] != ' '; i++)
	{
		sData << linha[i];
	}
	sData << "\0";
	stringstream conversaoData(sData.str());
	conversaoData >> *data;

	for (++i; linha[i] != ' '; i++)
	{
		sEstilo << linha[i];
	}
	sEstilo << "\0";
	stringstream conversaoEstilo(sEstilo.str());
	conversaoEstilo >> *estilo;

	for (++i; linha[i] != ' '; i++)
	{
		Nota << linha[i];
	}
	Nota << "\0";
	stringstream conversaoNota(Nota.str());
	conversaoNota >> *nota;

	for (++i; i < linha.length(); i++)
	{
		sFabricante << linha[i];
	}
	sFabricante << "\0";
	stringstream conversaoFabricante(sFabricante.str());
	conversaoFabricante >> *fabricante;
}

int populaCevaArquivo(ifstream &procurador, Degustacao vetor[], int n)
{
	string conteudoLinha;
	int i = 0;

	while (getline(procurador, conteudoLinha))
	{
		converte(conteudoLinha, &vetor[i].nome,
				 &vetor[i].data,
				 &vetor[i].estilo,
				 &vetor[i].nota,
				 &vetor[i].fabricante);
		i++;
	}
	return i;
}

void inicializaCeva(Degustacao vetor[], int n)
{
	for (int i = 0; i < n; i++)
	{
		vetor[i].nome = "";
		vetor[i].data = "";
		vetor[i].estilo = "";
		vetor[i].nota = 0;
		vetor[i].fabricante = "";
	}
}

int main()
{
	setlocale(LC_ALL, "Portuguese");
	int opcao;
	int qtdCeva = 0;
	Degustacao vetor[TAM];
	inicializaCeva(vetor, TAM);
	ofstream procuradorEscrita;
	ifstream procuradorLeitura;
	procuradorLeitura.open(NOMEARQUIVO);
	if (procuradorLeitura)
	{
		qtdCeva = populaCevaArquivo(procuradorLeitura, vetor, TAM);
		procuradorLeitura.close();
	}
	else
	{
		procuradorEscrita.open(NOMEARQUIVO);
		procuradorEscrita.close();
	}

	do
	{
		cout << "MENU DEGUSTAÇÃO CERVEJA ARTESANAL" << endl;
		cout << "1 - Cadastrar degustação" << endl;
		cout << "2 - Listar degustações" << endl;
		cout << "3 - Lista degustações por estilo de cerveja" << endl;
		cout << "4 - Ranking das cervejas" << endl;
		cout << "5 - Apagar degustação" << endl;
		cout << "6 - Sair" << endl;
		cout << "Opção: ";
		cin >> opcao;

		switch (opcao)
		{
		case 1:
			cout << "CADASTRAR DEGUSTAÇÃO" << endl;
			if (qtdCeva == TAM)
			{
				cout << "ARQUIVO LOTADO." << endl;
			}
			else
			{
				qtdCeva++;
				cadastraCerveja(vetor, TAM, qtdCeva);
			}
			break;
		case 2:
			cout << "LISTAR DEGUSTAÇÕES" << endl;
			if (qtdCeva == 0)
			{
				cout << "NENHUMA DEGUSTAÇÃO CADASTRADA!" << endl;
			}
			else
			{
				listaCevaDegustacao(vetor, qtdCeva);
			}
			break;
		case 3:
			cout << "LISTAR DEGUSTAÇÕES POR ESTILO DE CERVEJA" << endl;
			if (qtdCeva == 0)
			{
				cout << "NENHUMA DEGUSTAÇÃO CADASTRADA!" << endl;
			}
			else
			{
				listaCevaTipo(vetor, TAM, qtdCeva);
			}
			break;
		case 4:
			cout << "LISTAR DEGUSTAÇÕES POR RANKING" << endl;
			if (qtdCeva == 0)
			{
				cout << "NENHUMA DEGUSTAÇÃO CADASTRADA!" << endl;
			}
			else
			{
				organizaNota(vetor, TAM);
				listaCevaDegustacao(vetor, TAM);
			}
			break;
		case 5:
			cout << "EXCLUIR DEGUSTAÇÃO" << endl;
			if (qtdCeva == 0)
			{
				cout << "NENHUMA DEGUSTAÇÃO CADASTRADA!" << endl;
			}
			else
			{
				apagarDegustacao(vetor, TAM, qtdCeva);
			}
			break;
		case 6:
			cout << "OBRIGADO POR USAR O SISTEMA" << endl;
			break;
		default:
			cout << "OPÇÃO INVALIDA" << endl;
		}
	} while (opcao != 6);
	return 1;
}
