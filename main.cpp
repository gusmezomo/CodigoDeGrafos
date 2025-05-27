
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

  G1.LeMatrizADJ(Nome);
  G1.ImprimeMatrizAdjacencias();

  // Conversão da Matriz de Adjacência para Estrutura Encadeada
  G1.ConverteDaMatrizDeAdjacenciasParaEstruturaEncadeada();

  G1.SalvaMatrizINC(Nome);

  // Ou 

  G1.LeMatrizINC(Nome);

  // Conversão da Matriz de Incidência para Estrutura Encadeada
  G1.ConverteDaMatrizDeIncidenciasParaEstruturaEncadeada();

  G1.SalvaMatrizADJ(Nome);
  
}