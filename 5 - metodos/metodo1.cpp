#include<iostream>
#include<stdio.h>
#include<ctype.h>
#include<string.h>

using namespace std;

void paraMaiusculo(char palavra[]) {
    int i=0;
    do{
        if ( palavra[i] == '\n' || palavra[i] == '\0')
        {      
            break;
        }
        palavra[i] = toupper(palavra[i]);
        i++;
    }while (1);
}

void limpa(char palavra[]) {
    

}

void recebePalavra(char palavra[]){
    do {
        cout << "digite algo: " ;
        //cin >> palavra;
        gets(palavra);
        if (palavra[0] == ' ' || palavra[strlen(palavra)-1] == ' ') {
            cout << "Voce digitou um espaco em branco no inicio ou no fim. Corrija" << endl;        
        }
    } while (palavra[0] == ' ' || palavra[strlen(palavra)-1] == ' ');

    limpa(palavra);

    paraMaiusculo(palavra);
}

void mostraPalavra(char palavra[]){
    cout << "voce digitou: " << palavra << endl;
}
void mostraConsoantes(char palavra[]){
    int i=0;
    do{
        if (palavra[i] == '\n' || palavra[i] == '\0')
        {
          
        break;
        }
        if ( palavra[i] != 'A' && palavra[i] != 'E' && palavra[i] != 'I'  && palavra[i] != 'O' && palavra[i] != 'U')
        {
            cout << palavra[i] << endl;
        }
        i++;
    }while (1);
    
}

 void mostraPrimeiraPalavra(char palavra[]) {
    char palavraTemp[100];

    int i=0;
    do {
        if ( palavra[i] == '\n' || palavra[i] == '\0' || palavra[i] == ' ' )
        {      
            break;
        }
        
        //cout << palavra[i];
        palavraTemp[i] = palavra[i];
        i++;
    }while (1);
    
    palavraTemp[i] = '\0';

    cout << palavraTemp << endl;
}

void mostraUltimaPalavra(char palavra[]) {
    char palavraTemp[100];
    int i;
    int iPalavraTemp;
    int posicaoUltimoEspacoEmBranco = 1;
    
    i = 0;
    do {
        if ( palavra[i] == '\n' || palavra[i] == '\0')
        {      
            break;
        }
        if (palavra[i] == ' ') posicaoUltimoEspacoEmBranco = i;
        
        i++;
    }while (1);

    //cout << "Ultimo espaco em branco: " << posicaoUltimoEspacoEmBranco << endl;

    i = posicaoUltimoEspacoEmBranco+1;
    iPalavraTemp = 0;
    do {
        if ( palavra[i] == '\n' || palavra[i] == '\0')
        {      
            break;
        }
        palavraTemp[iPalavraTemp] = palavra[i];
        iPalavraTemp++;
        i++;
    }while (1);
    
    palavraTemp[iPalavraTemp] = '\0';

    cout << palavraTemp << endl;
}

 int main(){
     char palavra[100];
     
     recebePalavra(palavra);
     mostraPalavra(palavra);
     mostraPrimeiraPalavra(palavra);
     mostraUltimaPalavra(palavra);

     //mostraConsoantes(palavra);

    return 1;
 }
