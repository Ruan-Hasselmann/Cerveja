#include <iostream>
#include <sstream>
#include <time.h>
#include <chrono> 
#include <ctime> 

using namespace std;


string pegaDataHoraPadrao() {
    // declaring argument of time() 
    time_t tempo = time(NULL); 
    // ctime() used to give the present time 
    return ctime(&tempo); 
}

void mostraDataHora() {
    time_t tempo = time(NULL);
	stringstream data;
    
    tm *horaLocal = localtime(&tempo);
    
	data << horaLocal->tm_mday << "/" << 1 + horaLocal->tm_mon << "/" 
         << 1900 + horaLocal->tm_year << endl;
	
    cout << data.str();

    stringstream hora;
    hora << horaLocal->tm_hour << ":" << horaLocal->tm_min << endl;
    cout << hora.str();
}

string pegaDataString() {
    time_t tempo = time(NULL);
	stringstream data;
    
    tm *horaLocal = localtime(&tempo);
    
	data << horaLocal->tm_mday << "/" << 1 + horaLocal->tm_mon << "/" 
         << 1900 + horaLocal->tm_year << endl;
	
    return data.str();
}


int main() {
    string data = pegaDataHoraPadrao();
    cout << data;
    
    mostraDataHora();
    
    return 1;
}