/*Este programa muestra los algoritmos de ordenamiento y búsqueda para las fechas dentro de un archivo. Se utilizan los métodos de Bubble Sort y Búsqueda Binaria e imprime el listado de datos desde la fecha inicial hasta la fecha final proporcionadas por el usuario.*/
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Bitacora {
  int mes;
  int dia;
  string hora;
  string ip;
  string razon;
};

// Cambia el valor del mes por un número
int cambiarMes(string valor) {
  string mes[] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun",
                  "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
  int dia[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};

  for (int i = 0; i < 12; i++) {
    if (mes[i] == valor) {
      return dia[i];
    }
  }
  return 0;
}

// Cambia el valor del numero por el mes
string cambiarNumero(int valor) {
  string mes[] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun",
                  "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
  int dia[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};

  for (int i = 0; i < 12; i++) {
    if (dia[i] == valor) {
      return mes[i];
    }
  }
  return 0;
}

// Imprime un vector
void imprimir(vector<Bitacora> v) {
  for (int f = 0; f < v.size(); f++) {
    cout << cambiarNumero(v[f].mes) << " " << v[f].dia << " " << v[f].hora
         << " " << v[f].ip << " " << v[f].razon << endl;
  }
}

// Leer un archivo
void leerBitacora(vector<Bitacora> &v) {
  ifstream archivo;
  archivo.open("bitacora.txt");
  string mes, dia, hora, ip, razon;

  while (!archivo.eof()) {
    getline(archivo, mes, ' ');
    getline(archivo, dia, ' ');
    getline(archivo, hora, ' ');
    getline(archivo, ip, ' ');
    getline(archivo, razon, '\n');

    v.push_back(Bitacora{cambiarMes(mes), stoi(dia), hora, ip, razon});
  }

  archivo.close();
}

/*
*Ordena el bector Bitacora por fecha

*Complejidad en tiempo O(n^2)
*Complejidad en espacio O(1)

*@param vector<Bitacora>
*@return vector<Bitacora> ordenado
*/
void ordenaBurbuja(vector<Bitacora> &v) {
  for (int i = 1; i < v.size(); i++) {
    for (int j = 0; j < v.size() - 1; j++) {
      // Ordenar por mes
      if (v[j + 1].mes < v[j].mes) {
        swap(v[j + 1], v[j]);
      }

      // Ordernar por dia
      else if ((v[j].mes == v[j + 1].mes) && (v[j].dia != v[j + 1].dia)) {
        if (v[j + 1].dia < v[j].dia) {
          swap(v[j + 1], v[j]);
        }
      }

      // Ordenar por hora
      else if ((v[j].dia == v[j + 1].dia) &&
               (stoi(v[j].hora.substr(0, 2)) !=
                stoi(v[j + 1].hora.substr(0, 2)))) {
        if (stoi(v[j + 1].hora.substr(0, 2)) < stoi(v[j].hora.substr(0, 2))) {
          swap(v[j + 1], v[j]);
        }
      }

      // Ordenar por minuto
      else if (stoi(v[j].hora.substr(0, 2)) ==
                   stoi(v[j + 1].hora.substr(0, 2)) &&
               (stoi(v[j].hora.substr(3, 5)) !=
                stoi(v[j + 1].hora.substr(3, 5)))) {
        if (stoi(v[j + 1].hora.substr(3, 5)) < stoi(v[j].hora.substr(3, 5))) {
          swap(v[j + 1], v[j]);
        }
      }

      // Ordenar por segundo
      else if (stoi(v[j].hora.substr(3, 5)) ==
               stoi(v[j + 1].hora.substr(3, 5))) {
        if (stoi(v[j + 1].hora.substr(6, 8)) < stoi(v[j].hora.substr(6, 8))) {
          swap(v[j + 1], v[j]);
        }
      }
    }
  }
}

// Almace en un archivo el resultado del ordenamiento
void archivoResultado(vector<Bitacora> v) {
  ofstream folio("registroOrdenado.txt");
  for (int i = 0; i < v.size() - 1; i++) {
    folio << cambiarNumero(v[i].mes) << " " << v[i].dia << " " << v[i].hora
          << " " << v[i].ip << " " << v[i].razon << endl;
  }
}

 /*
*Complejidad en tiempo: O(log(n))
*Complejidad en espacio: O(1)
*/
int busqBinariaInicial(vector<Bitacora> &v, int &mesin, int &diain, int start, int end){
    if(start > end){
        return -1;
    }
    
    int mid = (start + end) / 2;
    int res;
    
    if (mesin == v[mid].mes && diain == v[mid].dia)
        return mid;
    
    else if(mesin < v[mid].mes || (mesin == v[mid].mes && diain < v[mid].dia)){
        end = mid - 1;
        res = busqBinariaInicial(v, mesin, diain, start, mid - 1);
    }
    
    else{
        start = mid + 1;
        res = busqBinariaInicial(v, mesin, diain, mid + 1, end);
    }
    
    return res;
}

int busqBinariaFinal(vector<Bitacora> &v, int &mesfin, int &diafin, int start, int end){

    if(start > end){
        return -1;
    }
    
    int mid = (start + end) / 2;
    int res;
    
    if (mesfin == v[mid].mes && diafin == v[mid].dia)
        return mid;
    
    else if(mesfin < v[mid].mes || (mesfin == v[mid].mes && diafin < v[mid].dia)){
        end = mid - 1;
        res = busqBinariaFinal(v, mesfin, diafin, start, mid - 1);
    }
    
    else{
        start = mid + 1;
        res = busqBinariaFinal(v, mesfin, diafin, mid + 1, end);
    }
    return res;
}

void registros(vector<Bitacora> &v, int &posIn, int &posFin){
    for(int f = posIn; f <= posFin; f++){
      cout << cambiarNumero(v[f].mes) << " " << v[f].dia << " " << v[f].hora << " " << v[f].ip << " " << v[f].razon << endl;
    }
}

int main() {
    int diain, diafin, mesin, mesfin, posIn, posFin; 
    
    vector<Bitacora> b;
    leerBitacora(b);
    ordenaBurbuja(b);
    archivoResultado(b);
    //imprimir(b);
    
    cout << "------------------------------------" << endl;
    cout << "Los meses en numeros: \nEnero = 1 \nFebrero = 2 \nMarzo = 3 \nAbril = 4 \nMayo = 5 \nJunio = 6 \nJulio = 7 \nAgosto = 8 \nSeptiembre = 9 \nOctubre = 10 \nNoviembre = 11 \nDiciembre = 12" << endl; 
    cout << "Ingresa el mes inicial en numero" << endl;
    cin >> mesin;
    cout << "Ingresa el dia inicial" << endl;
    cin >> diain;
    cout << "Ingresa el mes final en numero" << endl;
    cin >> mesfin;
    cout << "Ingresa el dia final" << endl;
    cin >> diafin; 
  
    posIn = busqBinariaInicial(b, mesin, diain, 0, b.size() - 1);
    posFin = busqBinariaFinal(b, mesfin, diafin, 0, b.size() - 1); 

    cout << "La fecha inicial esta en la posicion: " << posIn << endl;
    cout << "La fecha final esta en la posicion: " << posFin << endl; 

    cout << "Los registros que se encuentran en esas fechas son: " << endl; 
    registros(b, posIn, posFin);   
}
