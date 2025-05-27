#ifndef GRAFO
#define GRAFO

#include <iostream>
#include <cstdlib>
#include <stdio.h>
using namespace std;

#include "ListaSE.h"

#define MAX_VERTICES 100
#define MAX_ARESTAS 100

class Grafo{
  int MatrizAdjacencias[MAX_VERTICES][MAX_VERTICES];
  int MatrizDeIncidencias[MAX_VERTICES][MAX_ARESTAS];
  int nVertices;
  int nArestas;

  ListaSE VetorDeListaDeAdjacencias[MAX_VERTICES];

  public:

  int getNVertices(){ return nVertices;}
  int getNArestas() { return nArestas;}

  void InsereVertice(int label);

  void SalvaMatrizINC(string nome);
  void SalvaMatrizADJ(string Nome);
  void LeMatrizADJ(string nome);
  void LeMatrizINC(string Nome);
  
  void ConverteDaEstruturaEncadeadaParaMatrizDeIncidencias();
  void ConverteDaEstruturaEncadeadaParaMatrizDeAdjacencias();

  void ConverteDaMatrizDeIncidenciasParaEstruturaEncadeada();
  void ConverteDaMatrizDeAdjacenciasParaEstruturaEncadeada();
  
  void ImprimeMatrizAdjacencias();

};

#endif // GRAFO
