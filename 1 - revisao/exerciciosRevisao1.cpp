/*
Escrever um algoritmo que lê o código de um vendedor de uma empresa, seu salário fixo e o total de vendas efetuadas por ele. 
Cada  vendedor  recebe  um  salário  fixo,  mais  uma  comissão  proporcional  às  vendas  efetuadas  por  ele.  
A  comissão  é  de  3%  sobre  o total  de  vendas  até  R$1.000,00;  5%  de  R$1.000,00  à  R$2.000,00  e  10%  para  vendas  acima  de  R$2.000,00.  
Escrever  o  código  do vendedor, o total de suas vendas, seu salário fixo e seu salário total.
 */

#include <iostream>
#include <string>
#include <locale.h>

using namespace std;

int main()
{

    int codigoVendedor;
    float salarioFixoVendedor, totalVendasVendedor, salarioFinalVendedor;

    setlocale(LC_ALL, "Portuguese");

    cout << "Vendedor informe seu codigo: ";
    cin >> codigoVendedor;
    cout << "Informe seu salário fixo: ";
    cin >> salarioFixoVendedor;
    cout << "Informe seu total de vendas: ";
    cin >> totalVendasVendedor;
    if (totalVendasVendedor <= 1000)
    {
        salarioFinalVendedor = salarioFixoVendedor + (totalVendasVendedor * 3 / 100);
    }
    else if (totalVendasVendedor <= 2000)
    {
        salarioFinalVendedor = salarioFixoVendedor + (totalVendasVendedor * 5 / 100);
    }
    else
    {
        salarioFinalVendedor = salarioFixoVendedor + (totalVendasVendedor * 10 / 100);
    }
    cout << codigoVendedor << " Seu salario final será: " << salarioFinalVendedor;

    return 1;
}