/*Este programa muestra los algoritmos de ordenamiento y búsqueda para los ips
 dentro de un archivo. Se utilizan los métodos de Merge Sort y Búsqueda Binaria
 e imprime el listado de datos desde el ip inicial hasta el ip final
 proporcionadas por el usuario.
Equipo conformado por:
Jose Carlos Zertuche de la Cruz A01198177
Guillermo Garrido torres A00835087
Eugenio Herrera Garza A01721377
Adrian Cantu Antunez A01284748
Alejandro Mendoza Prado A00819383
 */

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

struct Bitacora {
  string mes;
  int dia;
  string hora;
  int ip1;
  int ip2;
  int ip3;
  int ip4;
  int puerto;
  string razon;
};

// Imprime un vector
void imprimir(vector<Bitacora> v) {
  for (int f = 0; f < v.size(); f++) {
    cout << v[f].mes << " " << v[f].dia << " " << v[f].hora << " " << v[f].ip1
         << "." << v[f].ip2 << "." << v[f].ip3 << "." << v[f].ip4 << ":"
         << v[f].puerto << " " << v[f].razon << endl;
  }
}

// Lee un archivo
void leerBitacora(vector<Bitacora> &v) {
  ifstream archivo;
  archivo.open("bitacora.txt");
  string mes, dia, hora, ip1, ip2, ip3, ip4, puerto, razon;

  while (!archivo.eof()) {
    getline(archivo, mes, ' ');
    getline(archivo, dia, ' ');
    getline(archivo, hora, ' ');
    getline(archivo, ip1, '.');
    getline(archivo, ip2, '.');
    getline(archivo, ip3, '.');
    getline(archivo, ip4, ':');
    getline(archivo, puerto, ' ');
    getline(archivo, razon, '\n');

    v.push_back(Bitacora{mes, stoi(dia), hora, stoi(ip1), stoi(ip2), stoi(ip3),
                         stoi(ip4), stoi(puerto), razon});
  }
  archivo.close();
}

/*
 *Define sobre carga de operador para ordenar por los ip1,ip2,ip3,ip4

 *@param: const Bitacora &a -> bitacora de arriba
 const Bitacora &b -> bitacora de abajo
 const es una variable constante, acá la usamos porque a y b se
 quedan constantes lo que va a cambiar es su dirección de variable, por eso
 usamos & para tener la dirección de la variable e ir comparando todas las
 bitacoras diferentes
 *@return: true -> si la condición es true, se tiene que ordenar ese ip
 false -> si la condición es flase, no se tiene que ordenar ese ip
 */
bool operator<=(const Bitacora &a, const Bitacora &b) {
  if (a.ip1 < b.ip1) {
    return true;
  }

  else if (a.ip1 == b.ip1) {
    if (a.ip2 < b.ip2) {
      return true;
    }

    else if (a.ip2 == b.ip2) {
      if (a.ip3 < b.ip3) {
        return true;
      }

      else if (a.ip3 == b.ip3) {
        if (a.ip4 < b.ip4) {
          return true;
        }

        else if (a.ip4 == b.ip4) {
          if (a.puerto < b.puerto) {
            return true;
          }
        }
      }
    }
  }
  return false;
}

/*
 *Ordena el vector Bitacora por ip
 *Definicion de la funcion merge sort para Bitacora

 *Complejidad en tiempo: O(n log2(n))
 *Complejidad en espacio: O(n)

 *@param: vector<Bitacora> -> el vector tiene que ser tipo Bitacora porque es lo
 que le pasamos del mergesort() se utiliza & porque necesitamos la dirección de
 la variable para guardar su valor En otras palabras, manda la direccion de
 memoria del vector int l -> desde donde empieza el ordenamiento int m -> la
 mitdad de los datos int r -> hasta donde vamos a ordenar
 */
void merge(vector<Bitacora> &bitacora, int l, int m, int r) {
  int n1 = m - l + 1;     // elementos en la parte izquierda
  int n2 = r - m;         // elementos en la parte derecha
  vector<Bitacora> L(n1); // vector para los elementos en la izquierda
  vector<Bitacora> R(n2); // vector para los elementos en la derecha

  // Recorren los vecotres de izquierda a derecha para asignar los valores de
  // los vectores que queremos asignar
  for (int i = 0; i < n1; i++) {
    L[i] = bitacora[l + i];
  }

  for (int j = 0; j < n2; j++) {
    R[j] = bitacora[m + 1 + j];
  }

  // Estas varibles nos van a servir para los ciclos while
  int i = 0;
  int j = 0;
  int k = l;

  // Hace el ordenamiento
  while (i < n1 && j < n2) {
    // Acá sucede la sobrecarga
    if (L[i] <= R[j]) {
      bitacora[k] = L[i];
      i++;
    }

    else {
      bitacora[k] = R[j];
      j++;
    }
    k++;
  }

  // Vacia los vectores izquiero y derecho (si i o j son menores)
  while (i < n1) {
    bitacora[k] = L[i];
    i++;
    k++;
  }

  while (j < n2) {
    bitacora[k] = R[j];
    j++;
    k++;
  }
}

/*
 *Implementacion del metodo de ordenamiento
 *Es una funcion recursiva

 *@param: vector<T> -> el vector tiene que ser tipo template porque la bitacora
 tiene elementos que son tipo string e int se utiliza & para mandar la direccion
 de memoria del vector int izq -> desde donde empieza el ordenamiento int der ->
 hasta donde vamos a ordenar
 */
template <class T> void mergeSort(vector<T> &v, int izq, int der) {
  if (izq < der) {
    int m = (izq + der) / 2;
    mergeSort(v, izq, m);
    mergeSort(v, m + 1, der);
    merge(v, izq, m, der);
  }
}

// Almace en un archivo el resultado del ordenamiento
void archivoResultado(vector<Bitacora> v) {
  ofstream folio("registroOrdenado.txt");
  for (int i = 0; i < v.size() - 1; i++) {
    folio << v[i].mes << " " << v[i].dia << " " << v[i].hora << " " << v[i].ip1
          << "." << v[i].ip2 << "." << v[i].ip3 << "." << v[i].ip4 << ":"
          << v[i].puerto << " " << v[i].razon << endl;
  }
}

/*
 *Busca valores ip en el vector bitacora

 *Complejidad en tiempo: O(log(n))
 *Complejidad en espacio: O(1)

 *@param: vector<Bitacora> -> el vector de tipo bitácora que hemos estado usando
 desde el inicio
 int ip1, ip2, ip3, ip4, puerto -> como desde el inicio se separo la parte del
 ip en 5 partes diferentes para poderlo ordenar, ahora hay que igualmente
 comparar cada cada una de ellas int start, end -> valores de inicio de donde se
 está buscando hasta el final, para poder calcular la mitad y hacer la búsqueda
 binaria

 */
int busqBinaria(vector<Bitacora> &v, int &ip1, int &ip2, int &ip3, int &ip4,
                int puerto, int start, int end) {

  if (start > end) {
    return -1;
  }

  int mid = (start + end) / 2;
  int res;

  // Ya se encontró el valor
  if (ip1 == v[mid].ip1 && ip2 == v[mid].ip2 && ip3 == v[mid].ip3 &&
      ip4 == v[mid].ip4 && puerto == v[mid].puerto)
    return mid;

  // El valor es menor
  else if (ip1 < v[mid].ip1 || (ip1 == v[mid].ip1 && ip2 < v[mid].ip2) ||
           (ip1 == v[mid].ip1 && ip2 == v[mid].ip2 && ip3 < v[mid].ip3) ||
           (ip1 == v[mid].ip1 && ip2 == v[mid].ip2 && ip3 == v[mid].ip3 &&
            ip4 < v[mid].ip4) ||
           (ip1 == v[mid].ip1 && ip2 == v[mid].ip2 && ip3 == v[mid].ip3 &&
            ip4 == v[mid].ip4 && puerto < v[mid].puerto)) {
    end = mid - 1;
    res = busqBinaria(v, ip1, ip2, ip3, ip4, puerto, start, mid - 1);
  }

  // El valor es mayor
  else {
    start = mid + 1;
    res = busqBinaria(v, ip1, ip2, ip3, ip4, puerto, start, mid + 1);
  }

  return res;
}

// Imprime los resultados que hay entre las dos posiciones donde está la ip
// inicial y la final
void registros(vector<Bitacora> &v, int &posIn, int &posFin) {
  for (int i = posIn; i <= posFin; i++) {
    cout << v[i].mes << " " << v[i].dia << " " << v[i].hora << " " << v[i].ip1
         << "." << v[i].ip2 << "." << v[i].ip3 << "." << v[i].ip4 << ":"
         << v[i].puerto << " " << v[i].razon << endl;
  }
}

int main() {
  vector<Bitacora> b;
  int ipin1, ipin2, ipin3, ipin4, puertoin, ipfin1, ipfin2, ipfin3, ipfin4,
      puertofin, posIn, posFin;

  leerBitacora(b);
  mergeSort(b, 0, b.size() - 1);
  archivoResultado(b);

  cout << "Ingrese el primer valor del ip inicial a buscar" << endl;
  cin >> ipin1;
  cout << "Ingrese el segundo valor del ip inicial a buscar" << endl;
  cin >> ipin2;
  cout << "Ingrese el tercer valor del ip inicial a buscar" << endl;
  cin >> ipin3;
  cout << "Ingrese el cuarto valor del ip inicial a buscar" << endl;
  cin >> ipin4;
  cout << "Ingrese el último valor del ip inicial a buscar" << endl;
  cin >> puertoin;

  cout << "-------------------------------------" << endl;

  cout << "Ingrese el primer valor del ip final a buscar" << endl;
  cin >> ipfin1;
  cout << "Ingrese el segundo valor del ip final a buscar" << endl;
  cin >> ipfin2;
  cout << "Ingrese el tercer valor del ip final a buscar" << endl;
  cin >> ipfin3;
  cout << "Ingrese el cuarto valor del ip final a buscar" << endl;
  cin >> ipfin4;
  cout << "Ingrese el último valor del ip final a buscar" << endl;
  cin >> puertofin;

  posIn = busqBinaria(b, ipin1, ipin2, ipin3, ipin4, puertoin, 0, b.size() - 1);
  posFin = busqBinaria(b, ipfin1, ipfin2, ipfin3, ipfin4, puertofin, 0,
                       b.size() - 1);
  if (posIn == -1 || posFin == -1) {
    cout << "Valores IP no encontrados" << endl;
  } else {
    cout << "Los registros encontrados son: " << endl;
    registros(b, posIn, posFin);
  }
}
