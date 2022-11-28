#include <iostream>
#include "BST.h"
#include "queue"
#include "PriorityQueue.h"

using namespace std;

int main(){

    int c, i, p;


    PriorityQueue<int> pq;

    do
    {
        cout << "1.Insert\n";
        cout << "2.Delete\n";
        cout << "3.Display\n";
        cout << "4.Size\n";
        cout << "5.Top\n";
        cout << "6.Empty?\n";
        cout << "7.Exit\n";
        cout << "Enter your choice : ";
        cin >> c;
        switch (c)
        {
            case 1:
                cout << "Input the item value to be added in the queue : ";
                cin >> i;
                cout << "Enter its priority : ";
                cin >> p;
                pq.push(i, p);
                break;
            case 2:
                pq.pop();
                break;
            case 3:
                pq.show();
                break;
            case 4:
                pq.size();
                break;
            case 5:
                pq.top();
                break;
            case 6:
                pq.empty();
            case 7:
                break;
            default:
                cout << "Wrong choice\n";
        }
    } while (c != 7);

    //Codigo Arbol Binario
    /*
    int option;
    BST<int>* root = NULL;

    root = root->Insert(root, new int(50));
    root = root->Insert(root, new int(19));
    root = root->Insert(root, new int(40));
    root = root->Insert(root, new int(16));
    root = root->Insert(root, new int(70));
    root = root->Insert(root, new int(55));
    root = root->Insert(root, new int(56));
    root = root->Insert(root, new int(17));
    root = root->Insert(root, new int(90));

    do{
        cout<<"¿De qué manera deseas recorrer el Árbol Binario de Búsqueda?\n";
        cout<<"1. Recorrido en preorden\n";
        cout<<"2. Recorrido en entreorden\n";
        cout<<"3. Recorrido en postorden\n";
        cout<<"4. Recorrido a lo ancho o por niveles\n";
        cin>>option;

        if(option == 1){
            cout<<"Recorriendo el árbol en preorden"<<endl;
            root->preOrder(root);
            cout<<"\n";
        }
        else if(option == 2){
            cout<<"Recorriendo el árbol en entreorden"<<endl;
            root->inOrder(root);
            cout<<"\n";
        }
        else if(option == 3){
            cout<<"Recorriendo el árbol en postorden"<<endl;
            root->postOrder(root);
            cout<<"\n";
        }
        else if(option == 4){
            cout<<"Recorriendo el árbol a lo ancho"<<endl;
            root->levelOrder(root);
            cout<<"\n";
        }
    }while(option<5);
    //root->mostrarArbolVisual(root, 1);

    cout<<"La altura del árbol es: "<<endl;
    cout<<root->height(root)<<endl;

    cout<<"Ancestros del sub-árbol con valor 50: ";
    cout<<root->ancestors(root, 90)<<endl;
    cout<<"Ancestros del sub-árbol con valor 70: ";
    cout<<root->ancestors(root, 70)<<endl;
    cout<<"Ancestros del sub-árbol con valor 100: ";
    cout<<root->ancestors(root, 100)<<endl;
    cout<<"Ancestros del sub-árbol con valor 16: ";
    cout<<root->ancestors(root, 16)<<endl;

    cout<<"¿En qué nivel se encuentra el sub-árbol con valor 50?: ";
    cout<<root->whichLevelAmI(root, 50)<<endl;
    cout<<"¿En qué nivel se encuentra el sub-árbol con valor 90?: ";
    cout<<root->whichLevelAmI(root, 90)<<endl;
    cout<<"¿En qué nivel se encuentra el sub-árbol con valor 5?: ";
    cout<<root->whichLevelAmI(root, 5)<<endl;
    cout<<"¿En qué nivel se encuentra el sub-árbol con valor 56?: ";
    cout<<root->whichLevelAmI(root, 56)<<endl;
     */

	return 0;
}