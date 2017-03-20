#include "Test.h"
using namespace std;
#define INT_MAX numeric_limits<int>::max()

int* getShortestPath(int** graph, int size, int origin)
{
    int* answer = new int[size];
    for(int i = 0; i < size; i++)
        answer[i] = INT_MAX;
    answer[origin] = 0;

    for (int k = 0; k < size - 1; k++) {
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                if(graph[j][i] != -1)
                    if (answer[j] != INT_MAX && answer[i] > answer[j] + graph[j][i]) {
                        answer[i] = answer[j] + graph[j][i];
                    }
            }
        }
    }

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if(graph[j][i] != -1){
                if (answer[i] > answer[j] + graph[j][i]) {
                    return NULL;
                }
            }
        }
    }

    return answer;
}

int main ()
{
    test();
    return 0;
}

 /*

   bool BellmanFord(Grafo G, nodo_origen s)
      // inicializamos el grafo. Ponemos distancias a INFINITO menos el nodo origen que
      // tiene distancia 0
       for v ∈ V[G] do
           distancia[v]=INFINITO
           predecesor[v]=NIL
       distancia[s]=0


       // relajamos cada arista del grafo tantas veces como número de nodos -1 haya en el grafo
       for i=1 to |V[G]|-1 do
           for (u, v) ∈ E[G] do
               if distancia[v]>distancia[u] + peso(u, v) then
                   distancia[v] = distancia[u] + peso (u, v)
                   predecesor[v] = u
       // comprobamos si hay ciclos negativo
       for (u, v) ∈ E[G] do
           if distancia[v] > distancia[u] + peso(u, v) then
               print ("Hay ciclo negativo")
               return FALSE
       return TRUE

  */