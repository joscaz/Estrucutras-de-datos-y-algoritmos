#include <iostream>
#include "list"

using namespace std;

template <class T> class HashTable{
private:
    int bucket;
    list<T>* tab;

 public:
    HashTable(){

    }

    HashTable(int b){
        this->bucket = b;
        tab = new list<int>[bucket];
    }

    void insertItemChain(int key){
        int index = chain(key);
        tab[index].push_back(key);
    }

    void deleteItemChain(int key){
        int index = chain(key);

        list <int> :: iterator i;
        for (i = tab[index].begin();
             i != tab[index].end(); i++) {
            if (*i == key)
                break;
        }

        // if key is found in hash table, remove it
        if (i != tab[index].end())
            tab[index].erase(i);
    }

    int chain(int x){
        return (x % bucket);
    }

    //funcion para implementar manejo de desbordamiento por sondeo cuadratico
    void quadratic(int table[], int tsize, int arr[], int N){
        // Iterar en el arreglo
        for (int i = 0; i < N; i++) {
            // Calculando el valor hash
            int hv = arr[i] % tsize;

            // Insertar si no existe colision
            if (table[hv] == -1)
                table[hv] = arr[i];
            else {
                // Si existe colision, iterar en todos los posible valores cuadraticos
                for (int j = 0; j < tsize; j++) {
                    // Calcular nuevo valor hash
                    int t = (hv + j * j) % tsize;
                    if (table[t] == -1) {
                        //Romper el ciclo e insertar el valor en la tabla
                        table[t] = arr[i];
                        break;
                    }
                }
            }
        }
        printQuadratic(table, N);
    }

    void printQuadratic(int arr[], int n){
        for(int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
    }

    void printChain(){
        for (int i = 0; i < bucket; i++) {
            cout << i;
            for (auto x : tab[i])
                cout << " --> " << x;
            cout << endl;
        }
    }
};