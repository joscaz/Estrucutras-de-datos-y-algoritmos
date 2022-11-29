/*
Equipo conformado por:
Jose Carlos Zertuche de la Cruz A01198177
Guillermo Garrido torres A00835087
Eugenio Herrera Garza A01721377
Adrian Cantu Antunez A01284748
Alejandro Mendoza Prado A00819383
*/

#include <iostream>
#include "hastable.h"

using namespace std;

int main(){

    HashTable<int> HashCuadratica;
    HashTable<int> HashCadena(7);

    int arr[] = { 50, 700, 76, 85, 92, 73, 101 };
    int N = 7;
    int n = sizeof(arr)/sizeof(arr[0]);

    // Size of the hash table
    int L = 7;
    int hash_table[7];

    // Initializing the hash table cuadratic form
    for (int i = 0; i < L; i++) {
        hash_table[i] = -1;
    }

    // Function call metodo cuadratico
    HashCuadratica.quadratic(hash_table, L, arr, N);
    cout<<endl;

    // Function call metodo de cadena
    for(int i = 0; i < n; i++){
        HashCadena.insertItemChain(arr[i]);
    }

    HashCadena.deleteItemChain(12);

    HashCadena.printChain();


    return 0;
}
