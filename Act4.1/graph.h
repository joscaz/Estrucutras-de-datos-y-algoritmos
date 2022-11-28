#include <iostream>
#include<list>
#include<queue>
using namespace std;

template<class T> class Graph{
private:
    int numVert;
public:

    Graph(int cantVertices){
        this->numVert=0;

    }

// Complejidad computacional O
    void LoadGraph(int cantVertices,int cantArcos,T MatrizAdy[][8],list<T> ListaAdy[] ){
        this->numVert = cantVertices;
        //LLenar matrix y lista de adyancencia
        for(int i=0;i<cantArcos;i++){
            int u,v;
            cin>>u>>v;
            //Insertar datos en la matriz
            MatrizAdy[u][v]=1;
            MatrizAdy[v][u]=1;
            //Insert data in the list
            ListaAdy[u].push_back(v);
            ListaAdy[v].push_back(u);
        }

    }
    //Complejidad computacional O(n^2) ó 0(v^2)
    void DFS(int matrix[][8],int nodo,int n){
        static int visited[8] {0};
        if (visited[nodo] == 0){
            cout << nodo << ", " << flush;
            visited[nodo] = 1;
            for (int v=1; v<n; v++){
                if (matrix[nodo][v] == 1 && visited[v] == 0){
                    DFS(matrix,v, n);
                }
            }
        }

    }
    //Complejidad computacional O(n^2) ó 0(v^2)
    void BFS(int node,int mat[][8],int n){
        queue<int> Q;
        int visited[8]{0};

        cout << node << ", " << flush;  // Visit vertex
        visited[node] = 1;
        Q.emplace(node);

        while(!Q.empty()){
            int vertToExp=Q.front();
            Q.pop();
            for(int v=1;v<=n;v++){
                if(mat[vertToExp][v]==1&&visited[v]==0){
                    cout<<v<<", "<<flush;
                    visited[v]=1;
                    Q.emplace(v);
                }
            }
        }

        cout<<endl;
    }

    void ImprimirMatrizAdy(int noVerts,T MatrizAdy[][8]){
        for (int i = 0; i < noVerts; i++) {
            cout << i << " : ";
            for (int j = 0; j < noVerts; j++)
                cout << MatrizAdy[i][j] << " ";
            cout << "\n";
        }
    }
    void ImprimirListaAdy(int noVerts,list<T> ListaAdyacencia[]){
        for (int d = 0; d < noVerts; ++d) {
            cout << "\n Vertice "
                 << d << ":";
            for (auto x : ListaAdyacencia[d])
                cout << "-> " << x;
            printf("\n");
        }

    }

};


