#include <iostream>
#include "LDE.h"
#pragma once

using namespace std;

int main() {
    LDE obj;
    int option;
    int key1, k1, data1;

    do{
        cout<<"\nQue operacion deseas realizar? Presiona 0 para salir"<<endl;
        cout<<"1. Anadir nodo"<<endl;
        cout<<"2. Insertar nodo al inicio"<<endl;
        cout<<"3. Insertar nodo despues de "<<endl;
        cout<<"4. Borrar nodo"<<endl;
        cout<<"5. Buscar nodo por clave"<<endl;
        cout<<"6. Actualizar nodo"<<endl;
        cout<<"7. Imprimir lista"<<endl;
        cout<<"0. Salir"<<endl;

        cin>>option;
        Node* n1 = new Node();

        switch (option){
            case 0:
                break;
            case 1:
                cout<<"Anadir Nodo \nInserte el id del nodo y el dato del nodo que sera agregado"<<endl;
                cin>>key1;
                cin>>data1;
                n1->key = key1;
                n1->data = data1;
                obj.appendNode(n1);
                break;

            case 2:
                cout<<"Insertar al Inicio \nInserte el id del nodo y el dato del nodo que sera puesto al inicio"<<endl;
                cin>>key1;
                cin>>data1;
                n1->key = key1;
                n1->data = data1;
                obj.insertarAlInicio(n1);
                break;

            case 3:
                cout<<"Insertar despues de un nodo \nInserte el id del nodo existente despues del cual desea insertar este nuevo nodo"<<endl;
                cin>>k1;
                cout<<"Inserte clave y valor del nuevo nodo primero: "<<endl;
                cin>>key1;
                cin>>data1;
                n1->key = key1;
                n1->data = data1;
                obj.insertarDespuesDe(k1, n1);
                break;

            case 4:
                cout<<"Eliminar nodo por id - \nIngrese el id del nodo a eliminar"<<endl;
                cin>>k1;
                obj.eliminarPorClave(k1);
                break;

            case 5:
                cout<<"Buscar nodo por id \nIngrese el id del nodo a buscar"<<endl;
                cin>>k1;
                obj.buscarPorClave(k1);
                break;

            case 6:
                cout<<"Actualizar nodo por id \nIngrese el id y el nuevo valor a actualizar"<<endl;
                cin>>key1;
                cin>>data1;
                obj.actNodoPorid(key1, data1);
                break;

            case 7:
                obj.printList();
                break;

            default:
                cout<<"Ingrese una opcion correcta"<<endl;
        }

    } while (option!=0);

    return 0;
}
