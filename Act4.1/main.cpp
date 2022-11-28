#include <iostream>
#include "graph.h"

int main(){
    //cantidad de vertices
    int noVert =8;
    //cantidad de arcos
    int noArco =9;
    Graph<int> grafo(noVert);
    //Inicialización de matriz de adyacencia en 0
    int MatrizAdy[8][8] = {{0, 0, 0, 0, 0, 0, 0, 0},
                           {0, 0, 0, 0, 0, 0, 0, 0},
                           {0, 0, 0, 0, 0, 0, 0, 0},
                           {0, 0, 0, 0, 0, 0, 0, 0},
                           {0, 0, 0, 0, 0, 0, 0, 0},
                           {0, 0, 0, 0, 0, 0, 0, 0},
                           {0, 0, 0, 0, 0, 0, 0, 0},
                           {0, 0, 0, 0, 0, 0, 0, 0}};

    //Inicialización de lista de adyacencia
    list<int>*ListasAdy= new list<int>[noVert];
    grafo.LoadGraph(noVert,noArco,MatrizAdy,ListasAdy);
    cout<<"Busqueda por profundidad: "<<endl;
    grafo.DFS(MatrizAdy,2,8);
    cout<<endl;
    //Se despliegan los datos
    cout<<"Busqueda por lo ancho: "<<endl;
    grafo.BFS(1,MatrizAdy,8);
    cout<<"Lista de adyacencia:"<<endl;
    grafo.ImprimirListaAdy(noVert,ListasAdy);
    cout<<"Matriz de adyacencia:"<<endl;
    grafo.ImprimirMatrizAdy(noVert,MatrizAdy);
    return 0;
};