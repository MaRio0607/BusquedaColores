#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
using namespace std;
 

struct Nodo {
    int src, dest;
};
 
class Grafo{
public:
    vector<vector<int>> adjList;
 
    Grafo(vector<Nodo> const &nodos, int n)
    {

        adjList.resize(n);
 

        for (Nodo nodo: nodos)
        {
            int src = nodo.src;
            int dest = nodo.dest;
 
            adjList[src].push_back(dest);
            adjList[dest].push_back(src);
        }
    }
};
 
string color[] =
{
    "", "Azul", "Rojo", "Verde",
};


void colorear(Grafo const &grafo, int n)
{
    unordered_map<int, int> result;
    for (int u = 0; u < n; u++)
    {
        set<int> asignacion;
 
        for (int i: grafo.adjList[u])
        {
            if (result[i]) {
                asignacion.insert(result[i]);
            }
        }
 
        int color = 1;
        for (auto &c: asignacion )
        {
            if (color != c) {
                break;
            }
            color++;
        }
 
        result[u] = color;
    }
    for (int v = 0; v < n; v++)
    {
        cout << "El vertice " << v << " es de color "
             << color[result[v]] << endl;
    }
}
 
int main()
{
    vector<Nodo> nodos = {
//   {0,1},
//   {0,4},
//   {0,3},
//   {0,2},
//   {0,7},
//   {3,7},
// // {3,6},
//   {4,7},
//   {7,6},
//   {7,5},
//   {5,6}
        {0, 2},
        {0, 7},
        {7,10},
        {7, 2},
        {2, 10}, 
        {2, 6}, 
        {10, 6}, 
        {6, 4},
        {6, 1},
        {6, 8},
        {8, 4},
        {8, 12},
        {12, 1},
        {12, 5},
        {1, 3},
        {1, 5},
        {1, 11},
        {4, 11},
        {5, 1},
        {5, 11},
        {11, 9},
        {9, 3}
    };
 
    int n = 13;
 
    Grafo grafo(nodos, n);
 
    colorear(grafo, n);
 
    return 0;
}