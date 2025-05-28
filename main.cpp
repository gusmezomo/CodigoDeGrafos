
#include <iostream>
#include <cstdlib>
#include <stdio.h>
using namespace std;

#include "Nodo.h"
#include "ListaSE.h"
#include "Grafo.h"

Grafo G1;

int main() {

  string Nome;

  Nome = "GrafoADJ.txt";

  cout << "Leitura da Matriz de Adjacencia:" << endl;
  G1.LeMatrizADJ(Nome);
  G1.ImprimeMatrizAdjacencias();

  // Conversão da Matriz de Adjacência para Estrutura Encadeada
  cout << "\nConversao para Matriz de Incidencia:" << endl;
  G1.ConverteDaMatrizDeAdjacenciasParaEstruturaEncadeada();
  G1.SalvaMatrizINC(Nome);

  // Ou 

  Nome = "GrafoINC.txt";
  
  cout << "\nLeitura da Matriz de Incidencia:" << endl;
  G1.LeMatrizINC(Nome);

  // Conversão da Matriz de Incidência para Estrutura Encadeada
  cout << "\nConversao para Matriz de Adjacencia:" << endl;
  G1.ConverteDaMatrizDeIncidenciasParaEstruturaEncadeada();
  G1.SalvaMatrizADJ(Nome);
}