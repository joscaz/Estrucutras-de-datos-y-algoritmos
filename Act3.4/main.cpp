//Autores:
//Guillermo Garrido Torres A00835087
//Jose Carlos Zertuche de la Cruz A01198177
//Eugenio Herrera Garza A01721377

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "BST.h"


using namespace std;


// obtiene la los primeros numeros de la ip y los convierte en un digito
int convertidor(string linea)
{
    size_t pos;
    vector<string> aux;
    pos = linea.find(".");
    aux.push_back(linea.substr(0, pos));
    return stoi(aux[0]);
}

int main() {
    std::cout << "Programa trabajando" << std::endl;
    try {


        //lugar donde se guardan las ips
        vector<int> vec1;

        //lectura del file
        ifstream bitacora;
        bitacora.open("/Users/josecarloszertuche/Downloads/actividad3.4/bitacora.txt");
        if (!bitacora) {
            cout << "el archivo con el nombre " << "bitacora.txt" << " no se puede abrir " << endl;
        }
        // Fin de la apertura del archivo

        // Lectura del archivo para sacar solo las IPS
        string linea;
        size_t pos;
        vector<string> info_ips;
        while (!bitacora.eof()) {
            vector<string> aux;
            getline(bitacora, linea);
            info_ips.push_back(linea);
            while ((pos = linea.find(" ")) != string::npos) {
                aux.push_back(linea.substr(0, pos));
                linea.erase(0, pos + 1);
            }
            aux.push_back(linea);
            vec1.push_back(convertidor(aux[3]));
        }
        // Fin de la lectura

        vector<int> vec2 = vec1;
        int acceso = 0;
        bool existe = false;
        vector<int> ip;
        vector<int> accesos;
        // Contamos cuanto se repite cada ip y guardamos sus accessos como su numero
        for (int i = 0; i < vec1.size(); i++) {

            for (int k = 0; k < ip.size(); k++){
                if(vec1[i] == ip[k]){
                    existe = true;
                }
            }
            if(existe == false){
                for (int j = 0; j < vec2.size(); j++) {
                    if (vec1[i] == vec2[j]) {
                        acceso++;
                    }
                }
            }

            if(acceso != 0){
                ip.push_back(vec1[i]);// ip
                accesos.push_back(acceso);
            }
            acceso = 0;
            existe = false;
        }



        //imprimimos las ips con sus numeros de acceso
        for(int i = 0; i < ip.size(); i++)
        {
            cout<<ip[i]<<"-"<<accesos[i]<<endl;
        }

        // creamos un arbol binario de busqueda (BST)
        BST<int>* miArbol = NULL;

        // metemos nuestras ips como valor y su numero de accesos como llave
        // este mismo proceso ya nos ordena por cuales son las que tienen mas accesos, dejandolas del lado derecho
        for(int i = 0; i < ip.size();i++){

            miArbol = miArbol->Insert(miArbol, new int(accesos[i]),new int(ip[i]) );

        }

        // sacamos las 5 ips con mas acceso, es decir las que esten mas a la derecha
        // cada vez que encontramos el mas alto lo borramos para que obtener el segundo mas alto

         cout<<endl;
        cout<<"ips con mas accesos: "<< endl;
        for(int i = 0; i<5;i++){
            BST<int>* maximo = miArbol->mostRight(miArbol);
            cout<<*(maximo->getValor())<<" - "<<*(maximo->getData())<<endl;
            miArbol = miArbol->deleteNode(miArbol, maximo->getData());
        }



    }
    catch (const char *msg) {
        cout << msg << endl;
    }

    return 0;

}