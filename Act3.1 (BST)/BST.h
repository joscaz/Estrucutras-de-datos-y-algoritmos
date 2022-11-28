#pragma once
#include "queue"
#include <iostream>

#define GLOBALSPACE 5

using namespace std;

template<class T> class BST
{
protected:

	T* data;
	BST<T>* left;
	BST<T>* right;

public:

	BST(){
        this->data = NULL;
        this->left = NULL;
        this->right = NULL;
    }

	BST(T* dato){
        this->data = dato;
        this->left = NULL;
        this->right = NULL;
    }

    BST<T>* Insert(BST<T>* root, T* data){
        if(root == NULL){
            return new BST<T>(data);
        }
        if(*data < (*root->data)){
            root->left = Insert(root->left, data);
        }
        else if(*data > (*root->data)){
            root->right = Insert(root->right, data);
        }
        return root;
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

    int height(BST<T>* root){

        if(root == NULL){
            return 0;
        }
        else {
            int ld = height(root->left);
            int rd = height(root->right);

            return (max(ld, rd)+1);
        }

    }

	bool esVacio()
	{
		return this->root == NULL;
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
            cout<<(*item->data)<<" ";
            q.pop();

            if(item->left != NULL){
                q.push(item->left);
            }

            if(item->right != NULL){
                q.push(item->right);
            }
        }
    }

    bool ancestors(BST<T>* root, T target){
        /* base cases */
        if(root == NULL){
            return false;
        }

        if(*root->data == target){
            return true;
        }
    /* If target is present in either left or right subtree of this node, then print this node */
        if(ancestors(root->left, target) || ancestors(root->right, target)){
            cout<<*root->data<<" ";
            return true;
        }
        //Else return false
        return false;
    }

    void mostrarArbolVisual(BST<T>* root, T space){
        if(root == NULL) {
            return;
        }
        space += GLOBALSPACE;

        mostrarArbolVisual(root->right, space);
        cout<<endl;
        for(int i = GLOBALSPACE; i < space; i++){
            cout<<" ";
        }
        cout<<*root->data<<"\n";
        mostrarArbolVisual(root->left, space);
    }

    int whichLevelAmI(BST<T>* root, T ptr, int level = 0){
        if(root == NULL)
            return -1;
        if(*root->data == ptr)
            return level;
        // If NULL or leaf Node
        if(root->left == NULL && root->right == NULL)
            return -1;
        // Find If ptr is present in the left or right subtree.
        int levelLeft = whichLevelAmI(root->left, ptr, level+1);
        int levelRight = whichLevelAmI(root->right, ptr, level+1);

        if(levelLeft == -1)
            return levelRight;
        else
            return levelLeft;
    }

};



