#include <iostream>
#include <sstream>
#include <string>

using namespace std;

string transformaData(int dia, int mes, int ano) {
    stringstream data;
    stringstream diaS, mesS;

    if (dia < 10) diaS << "0" << dia;
    else diaS << dia;

    if (mes < 10) mesS << "0" << mes;
    else mesS << mes;

    data << diaS.str() << "/" << mesS.str() << "/" << ano;

    return data.str(); //convertendo data para string antes de retornar
}

int main() {
    int dia, mes, ano;

    cout << "Digite dia: ";
    cin >> dia;

    cout << "Digite mes: ";
    cin >> mes;

    cout << "Digite ano: ";
    cin >> ano;
    
    string data = transformaData(dia,mes,ano);
    cout << data << endl;

    return 1;
}