#include <iostream>
#include "HashTable.h"

using namespace std;

//menu de pruebas
int main(){

    int dato;
    int i = 0;
    int x = 0;
    int N = 1000;
    int arr[N];
    int size = 16807;
    int n = sizeof(arr)/sizeof(arr[0]);
    HashTable<int> hashing(N);
    vector<int> puertos;
    int y;

    ifstream bitacora("../input/bitacora.txt");

    string line;
    ofstream TableHashing;
    TableHashing.open("../output/TablaHashing.txt");
    while(getline(bitacora, line)) {
        int n = sizeof(arr)/sizeof(arr[0]);
        stringstream ss(line);
        istream_iterator<string> begin(ss);
        istream_iterator<string> end;
        vector<string> vstrings(begin, end);
        string ip_port = vstrings[3];
        int pos = ip_port.find(":");
        string port = ip_port.substr(pos+1);
        stringstream newint(port);
        newint >> x;
        hashing.insertar(x);
        puertos.push_back(x);
    }
    //Se crea tabla hash
    hashing.tablaEncadena();
    cout << "En el archivo TablaHashing.txt podra encontrar la tabla hash tambien" << endl;
    // Cuenta los puertos
    hashing.count_puertos(puertos);
    cout << "\n";
    cout << "Buscar puerto: ";
    cin >> y;
    cout << endl;
    // Se imprime el resumen del puerto
    hashing.print(y);
    TableHashing.close();
    return 0;
}
