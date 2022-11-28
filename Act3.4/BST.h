//
// Created by memo on 09/11/22.
//

#ifndef ACTIVIDAD3_4_BST_H
#define ACTIVIDAD3_4_BST_H



#pragma once
#include "queue"
#include <iostream>

using namespace std;

template<class T> class BST
{
protected:

    T* data;
    T* valor;
    BST<T>* left;
    BST<T>* right;

public:

    BST(){
        this->data = NULL;
        this->valor = NULL;
        this->left = NULL;
        this->right = NULL;
    }

    BST(T* dato){
        this->data = dato;
        this->valor = NULL;
        this->left = NULL;
        this->right = NULL;
    }

    BST(T* dato, T* valor){
        this->data = dato;
        this->valor = valor;
        this->left = NULL;
        this->right = NULL;
    }


    T* getData(){
        return this->data;
    }

    T* getValor(){
        return this->valor;
    }


    BST<T>* getRight(){
        return this->right;
    }

    BST<T>* getLeft(){
        return this->left;
    }

    // la peor complexidad para este algoritmo es de O(h) donde h es la altura del arbol

    BST<T>* Insert(BST<T>* root, T* data, T* valor){
        if(root == NULL){  // caso base, crea un nuevo arbol cuando ya llega al lugar donde debe ser insertado
            return new BST<T>(data, valor);
        }
        if(*data <= (*root->data) && (*root->valor) != *valor){ // recursividad, si el arbol actual es mayor que lo que queremos meter , se va a la izquerda
            root->left = Insert(root->left, data, valor);
        }
        else if(*data > (*root->data)){// recursividad, si el arbol actual es menor que lo que queremos meter , se va a la derecha
            root->right = Insert(root->right, data, valor);
        }
        return root;
    }

    BST<T>* Insert(BST<T>* root, T* data){
        if(root == NULL){  // caso base, crea un nuevo arbol cuando ya llega al lugar donde debe ser insertado
            return new BST<T>(data);
        }
        if(*data <= (*root->data) ){ // recursividad, si el arbol actual es mayor que lo que queremos meter , se va a la izquerda
            root->left = Insert(root->left, data);
        }
        else if(*data > (*root->data)){// recursividad, si el arbol actual es menor que lo que queremos meter , se va a la derecha
            root->right = Insert(root->right, data);
        }
        return root;
    }

    BST<T>* minValueNode(BST<T>* node)
    {
        BST<T>* current = node;

        /* loop down to find the leftmost leaf */
        while (current && current->left != NULL)
            current = current->left;

        return current;
    }

/* Given a binary search tree and a key, this function
deletes the key and returns the new root */
    BST<T>* deleteNode(BST<T>* root, T* key)
    {
        // base case
        if (root == NULL)
            return root;

        // If the key to be deleted is
        // smaller than the root's
        // key, then it lies in left subtree
        if (*key < *root->data)
            root->left = deleteNode(root->left, key);

            // If the key to be deleted is
            // greater than the root's
            // key, then it lies in right subtree
        else if (*key > *root->data)
            root->right = deleteNode(root->right, key);

            // if key is same as root's key, then This is the node
            // to be deleted
        else {
            // node has no child
            if (root->left==NULL and root->right==NULL){
                root->data = NULL;
                root->valor = NULL;
                return NULL;
            }


                // node with only one child or no child
            else if (root->left == NULL) {
                BST<T>* temp = root->right;
                free(root);
                return temp;
            }
            else if (root->right == NULL) {
                BST<T>* temp = root->left;
                free(root);
                return temp;
            }

            // node with two children: Get the inorder successor
            // (smallest in the right subtree)
            BST<T>* temp = minValueNode(root->right);

            // Copy the inorder successor's content to this node
            root->data = temp->data;
            root->valor = temp->valor;

            // Delete the inorder successor
            root->right = deleteNode(root->right, temp->data);
        }
        return root;
    }

    BST<T>* search(BST<T>* root, T* key)
    {
        // Base Cases: root is null or key is present at root
        if (root == NULL || root->data == key)
            return root;

        // Key is greater than root's key
        if (root->data < key)
            return search(root->right, key);

        // Key is smaller than root's key
        return search(root->left, key);
    }

    BST<T>* mostRight(BST<T>* root){
        if(root->right == NULL){
            return root;
        }
        else{
            return mostRight(root->right);
        }
    }

    int cantHojas()
    {
        if (esHoja())
        {
            return 1;
        }

        int cantIzq = !this->left->esVacio() ? this->left->cantHojas() : 0;
        int cantDer = !this->right->esVacio() ? this->right->cantHojas() : 0;

        return cantIzq + cantDer;
    }


    // la complejidad de este algoritmo es de O(h), pues recorre hasta el fondo del arbol
    int altura(BST<T>* root){

        if(root == NULL){// si esta vacio regresa 0
            return 0;
        }
        else { // va por cada arbol y se va sumando
            int ld = altura(root->left);
            int rd = altura(root->right);

            return (max(ld, rd)+1);// el lado que sea mas grande es el que se saca
        }

    }


    bool esVacio()
    {
        return this->data == NULL;
    };

    bool esHoja()
    {
        return this->left->esVacio() && this->right->esVacio();
    };

    void inOrder(BST<T> *root){
        if(root == NULL){
            return;
        }
        inOrder(root->left);
        cout<<*root->data<<" ";
        inOrder(root->right);
    }

    void preOrder(BST<T> *root){
        if(root == NULL){
            return;
        }
        cout << *root->data << " ";

        /* then recur on left subtree */
        preOrder(root->left);

        /* now recur on right subtree */
        preOrder(root->right);
    }

    void postOrder(BST<T>* root){
        if(root == NULL){
            return;
        }

        postOrder(root->left);
        postOrder(root->right);
        cout<<*root->data<<" ";
    }

    void levelOrder(BST<T>* root){
        //Utilizando TDA cola
        if(root == NULL){
            return;
        }
        queue<BST<T>*> q;

        q.push(root);

        while(!q.empty()){
            BST<T>* item = q.front();
            cout<<(*item->getData())<<" ";
            q.pop();

            if(item->left != NULL){
                q.push(item->left);
            }

            if(item->right != NULL){
                q.push(item->right);
            }
        }
    }

    void visit(BST<T>* root, int orden){
        switch(orden){
            case 1:
                cout<<"Preorden: ";
                preOrder(root);
                cout<<endl;
                break;
            case 2:
                cout<<"Inorden: ";
                inOrder(root);
                cout<<endl;
                break;
            case 3:
                cout<<"Postorden: ";
                postOrder(root);
                cout<<endl;
                break;
            case 4:
                cout<<"Level by Level: ";
                levelOrder(root);
                cout<<endl;
                break;
            default:
                cout<<"la opcion elegida no es valida"<<endl;
        }
    }

    bool ancestors(BST<T>* root, T target){

        if(root == NULL){
            return false;
        }

        if(*root->data == target){
            return true;
        }

        if(ancestors(root->left, target) || ancestors(root->right, target)){
            cout<<*root->data<<" ";
            return true;
        }

        return false;
    }

    BST<T>* lca(BST<T>* root, T* key, T* value)
    {
        if (root == NULL)
            return NULL;

        // If both n1 and n2 are smaller
        // than root, then LCA lies in left
        if (root->data > key && root->valor > value)
            return lca(root->left, key, value);

        // If both n1 and n2 are greater than
        // root, then LCA lies in right
        if (root->data < key && root->valor < value)
            return lca(root->right, key, value);

        return root;
    }


    int whatLevelAmI(BST<T>* root, T* target) {
        if (root == NULL) return -1;
        int level = 1;

        while (root != NULL) {
            if (*target == *(root->getData())) return level;
            level++;
            root = (*target < *(root->getData())) ? root->getLeft() : root->getRight();
        }
        return -1;
    }






};



#endif //ACTIVIDAD3_4_BST_H
