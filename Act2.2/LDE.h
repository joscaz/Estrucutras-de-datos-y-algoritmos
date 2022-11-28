#include <iostream>
#include "Node.h"

using namespace std;

class LDE{
public:
    Node *head;

    LDE(){
        head = NULL;
    }

    LDE(Node *n){
        head = n;
    }

    //1. Checar si el nodo existe con el valor del key
    Node* nodeExists(int k){
        Node* temp = NULL;
        Node* ptr = head;

        while(ptr!= NULL){
            if(ptr->key == k){
                temp = ptr;
            }
            ptr = ptr->next;
        }
        return temp;
    }

    //2. Append a node to a list
    void appendNode(Node* n){
        if(nodeExists(n->key)!=NULL){
            cout<<"Nodo ya existe con valor clave: "<<n->key<<". Enlaza otro nodo con diferente valor clave."<<endl;
        }
        else {
            if(head==NULL) {
                head = n;
                cout << "Nodo enlazado como cabeza" << endl;
            } else {
                Node* ptr = head;
                while(ptr->next!= NULL){
                    ptr = ptr->next;
                }
                ptr->next = n;
                n->prev = ptr;
                cout<<"Nodo enlazado"<<endl;
            }
        }
    }

    //3. Insertar nodo al principio
    void insertarAlInicio(Node *n){
        if(nodeExists(n->key)!=NULL) {
            cout << "Nodo ya existe con clave: " << n->key << ". Inserta un nodo con diferente clave." << endl;
        } else {
            if(head == NULL){
                head = n;
                cout<<"Nodo insertado como cabeza"<<endl;
            } else{
                head->prev = n;
                n->next = head;
                head = n;
                cout<<"Nodo insertado al inicio."<<endl;
            }
        }
    }

    //4. Insertar nodo despues de uno particular en la lista
    void insertarDespuesDe(int k, Node *n){
        Node* ptr = nodeExists(k);
        if(ptr == NULL){
            cout<<"No existe nodo con valor clave: "<<k<<endl;
        } else {
            if(nodeExists(n->key)!=NULL){
                cout<<"Nodo ya existe con valor clave: "<<n->key<<". Inserte nodo con un diferente valor"<<endl;
            } else {
                cout<<"Insertando"<<endl;

                Node *nextNode = ptr->next;

                //insertando al final
                if(nextNode == NULL){
                    ptr->next = n;
                    n->prev = ptr;
                    cout<<"Nodo insertado al final"<<endl;
                }

                //insertando en medio

                else {
                    n->next = nextNode;
                    nextNode->prev = n;
                    n->prev = ptr;
                    ptr->next = n;

                    cout<<"Nodo insertado en medio"<<endl;
                }
            }
        }
    }

    //4. Eliminar nodo por clave. Des-enlazar, no eliminar.
    void eliminarPorClave(int k){
        Node* ptr = nodeExists(k);
        if(ptr == NULL){
            cout<<"No existe nodo con valor clave: "<<k<<endl;
        }
        else {
            if(head->key == k){
                head = head->next;
                cout<<"Nodo desenlazado con la clave: "<<k<<endl;
            }
            else {
                Node *nextNode = ptr->next;
                Node *prevNode = ptr->prev;

                //eliminando al final
                if(nextNode == NULL){
                    prevNode->next = NULL;
                    cout<<"Nodo al final eliminado correctamente"<<endl;
                }

                //eliminando en medio
                else{
                    prevNode->next = nextNode;
                    nextNode->prev = prevNode;
                    cout<<"Nodo en medio de la lista eliminado"<<endl;
                }
            }
        }
    }

    //6. Actualizar nodo
    void actNodoPorid(int k, int d){
        Node* ptr = nodeExists(k);
        if(ptr!=NULL){
            ptr->data = d;
            cout<<"Mpdp actualizado correctamente"<<endl;
        }
        else {
            cout<<"Nodo no existe con clave: "<<k<<endl;
        }
    }

    //7. Imprimir lista
    void printList(){
        if(head == NULL){
            cout<<"No hay ningun nodo en la lista"<<endl;
        }
        else{
            cout<<endl<<"Valores de la lista doblemente enlazada: ";
            Node* temp = head;

            while(temp!=NULL){
                cout<<"("<<temp->key<<", "<<temp->data<<") <-->";
                temp = temp->next;
            }
        }
    }

    void buscarPorClave(int k){
        Node* ptr = nodeExists(k);
        if(ptr == NULL) {
            cout<<"No se encontro el nodo con clave "<<k<<" en la lista"<<endl;
        } else {
            cout << "Ese nodo si se encuentra en la lista y tiene un valor de: "<<ptr->data<< endl;
        }
    }
};