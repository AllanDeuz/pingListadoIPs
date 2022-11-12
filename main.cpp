#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

void mostrarArray(string array[]);
void hacerPing(string array);
int getLargoArray(string array[]);

int main()
{
    string line;
    string ipCompletas[100];
    ifstream myfile("./assets/listado_ip.txt");
    string ipParaPing;
    int largoArray;
    int acumulador = 0;
    printf("INICIANDO EJECUCION\r");

    if (myfile.is_open())
    {
        printf("El .txt se abrio correctamente\r");
        while (getline(myfile, line))
        {
            ipCompletas[acumulador] = line;
            acumulador++;
        }
        printf("Ip's del .txt correctamente extraidas\r");
        // mostrar el ultimo elemento del array
        largoArray = getLargoArray(ipCompletas);
        printf("Cantidad de ip's contenidas en el .txt: %d \r", largoArray);
        myfile.close();
    }
    else
    {
        cout << "No se pudo abrir el archivo";
    }
    printf("Ip's contenidas en el .txt:\r");
    mostrarArray(ipCompletas);
    for (int i = 0; i < largoArray; i++)
    {
        string ipParaPing = ipCompletas[i];
        hacerPing(ipParaPing);
    }
    return 0;
}

void mostrarArray(string array[])
{
    int largo = getLargoArray(array);
    for (int i = 0; i < largo; i++)
    {
        cout << array[i] << endl;
    }
}

void hacerPing(string ip)
{
    if (ip == "" && ip.length() == 0)
    {
        printf("No se puede hacer ping a una ip vacia\r");
        return;
    }
    else
    {
        string comando = "ping " + ip;
        system(comando.c_str());
    }
}

int getLargoArray(string array[])
{
    int largo = 0;
    for (int i = 0; i < 100; i++)
    {
        if (array[i] == "")
        {
            largo = i;
            break;
        }
    }
    return largo;
}