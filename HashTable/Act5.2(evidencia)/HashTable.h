#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <iterator>
#include <list>
#include <cmath>
#include <unordered_map>

using namespace std;

template <class T> class HashTable{
public:
    HashTable(int V) //Numero del bucket
    {
        BUCKET = V;
        table = new list<int>[BUCKET];
    }

    void insertar(int key)
    {
        insertaElemento(key);
    }

    void tablaEncadena()
    {
        displayChain();
    }

    void count_puertos(vector<int>& puertos)
    {
        count_occurrence(puertos);
    }

    void print(int x)
    {
        desplegar_contado(x);
    }

    unordered_map<int, int> contado;

private:
    int BUCKET; // Número de buckets

    // Apuntador a lista con buckets
    list<int> *table;

    // Funcion hash para calcular posicion
    int funcionHash(int x)
    {
        return (x % BUCKET);
    }

    // Insertar en la tabla
    void insertaElemento(int key)
    {
        int pos = funcionHash(key);
        table[pos].push_back(key);
        unordered_map<int, int> m;
    }

    // Funcion que despliega tabla de hash por metodo de encadenamiento
    void displayChain()
    {
        ofstream TableHashing;
        TableHashing.open("../output/TablaHashing.txt");
        for (int i = 0; i < BUCKET; i++) {
            cout << "[ " << i << " ]";
            TableHashing << "[ " << i << " ]";
            for (auto x : table[i])
                cout << " --> " << x;
            cout << endl << "\n";
            for (auto x : table[i])
                TableHashing << " --> " << x;
            TableHashing << endl << "\n";
        }
        TableHashing.close();
    }

    // Funcion que hace conteo de los puertos
    void count_occurrence(vector<int>& puertos)
    {
        for(auto x = puertos.begin(); x != puertos.end(); ++x)
        {
            ++contado[*x];
        }
    }

    // Desplegar el conteo de puertos y direccion ip
    void desplegar_contado(int x)
    {
        ofstream SearchPort;
        SearchPort.open("../output/ResumenPuerto.txt");
        cout << x << " fue accesado: " << contado[x] << endl << "\n";
        SearchPort << x << " fue accesado: " << contado[x] << endl << "\n";

        ifstream bitacora2("../input/bitacora.txt");
        string line2;
        while(getline(bitacora2, line2)) {
            stringstream ss(line2);
            istream_iterator<string> begin(ss);
            istream_iterator<string> end;
            vector<string> vstrings(begin, end);
            string ip_port = vstrings[3];
            int pos = ip_port.find(":");
            string ip = ip_port.substr(0, pos);
            string port = ip_port.substr(pos+1);
            stringstream newint(port);
            int k = 0;
            newint >> k;
            if (x == k)
            {
                cout << ip << endl;
                SearchPort << ip << endl;
                cout << "\n";
            }
        }
        cout << "En el archivo ResumenPuerto.txt podra encontrar el resumen del puerto " << x << " tambien" << endl;
        SearchPort.close();
    }
};