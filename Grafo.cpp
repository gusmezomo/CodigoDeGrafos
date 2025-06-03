#include <iostream>
#include <fstream>
#include <cstdlib>
#include <stdio.h>
using namespace std;

#include "Grafo.h"

void Grafo::LeMatrizINC(string Nome) {
    ifstream entrada;
    entrada.open(Nome.c_str(), ios::in);
    if (!entrada) {
        cout << "Problemas na abertura do arquivo!" << endl;
        exit(0);
    }

    entrada >> nVertices >> nArestas;

    for(int i = 0; i < nVertices; i++) {
        for(int j = 0; j < nArestas; j++) {
            entrada >> MatrizDeIncidencias[i][j];
            if (!entrada) {
                cout << "Problemas na leitura!" << endl;
                exit(0);
            }
        }
    }

    entrada.close();
}

void Grafo::SalvaMatrizADJ(string Nome) {
    ConverteDaEstruturaEncadeadaParaMatrizDeAdjacencias();

    for(int i = 0; i < nVertices; i++) {
        for(int j = 0; j < nVertices; j++) {
            cout << MatrizAdjacencias[i][j] << ",";
        }
        cout << endl;
    }
}

void Grafo::LeMatrizADJ(string nome)
{
/*
4   // vertices 
0 1 1 1 
1 0 1 0 
1 1 0 0 
1 0 0 0  
*/
  ifstream entrada;
  entrada.open(nome.c_str(), ios::in);
  if (!entrada) 
  {
    cout << "Problemas na abertura!";
    exit (0);
  }
  entrada >> nVertices;
  for(int linha = 0; linha< nVertices;linha++)
  {
    for(int coluna = 0; coluna< nVertices;coluna++)
    {
       entrada >> MatrizAdjacencias[linha][coluna];
        if (!entrada) 
        {
          cout << "Problemas na leitura!";
          exit (0);
        }
    }
  }
  entrada.close();
  
}

void Grafo::SalvaMatrizINC(string N)
{
    ConverteDaEstruturaEncadeadaParaMatrizDeIncidencias();
    for(int i = 0; i < getNVertices(); i++) {
        for(int j = 0; j < getNArestas(); j++) { 
            cout << MatrizDeIncidencias[i][j] << ",";
        }
        cout << endl;
    }
}

void Grafo::ImprimeMatrizAdjacencias()
{
  for(int linha = 0; linha< nVertices;linha++)
  {
    for(int coluna = 0; coluna< nVertices;coluna++)
    {
       cout << MatrizAdjacencias[linha][coluna] << ",";
    }
    cout << endl;
  }

}

// CRIADO NOVO BALA
void Grafo::ImprimeMatrizDeIncidencias() {
    for(int i = 0; i < nVertices; i++) {
        for(int j = 0; j < nArestas; j++) {
            cout << MatrizDeIncidencias[i][j] << ",";
        }
        cout << endl;
    }
}

void Grafo::ConverteDaEstruturaEncadeadaParaMatrizDeIncidencias()
{
    nArestas = 0;
    for(int i = 0; i < nVertices; i++) {
        for(int j = 0; j < MAX_ARESTAS; j++) {
            MatrizDeIncidencias[i][j] = 0;
        }
    }

    for(int i = 0; i < nVertices; i++) {
        Nodo* ptr = VetorDeListaDeAdjacencias[i].Inicio;
        while(ptr != NULL) {
            int j = ptr->info;
            if(i < j) {
                MatrizDeIncidencias[i][nArestas] = 1;
                MatrizDeIncidencias[j][nArestas] = 1;
                nArestas++;
            }
            ptr = ptr->prox;
        }
    }
}

void Grafo::ConverteDaMatrizDeAdjacenciasParaEstruturaEncadeada() {
    for(int i = 0; i < nVertices; i++) {
        VetorDeListaDeAdjacencias[i].CriaLista();
        for(int j = 0; j < nVertices; j++) {
            if(MatrizAdjacencias[i][j] != 0) {
                VetorDeListaDeAdjacencias[i].InsereNoFim(j);
            }
        }
    }
}

void Grafo::ConverteDaMatrizDeIncidenciasParaEstruturaEncadeada() {
    for(int i = 0; i < nVertices; i++) {
        VetorDeListaDeAdjacencias[i].CriaLista();
    }
    
    for(int a = 0; a < nArestas; a++) {
        int v1 = -1, v2 = -1;

        for(int v = 0; v < nVertices; v++) {
            if(MatrizDeIncidencias[v][a] == 1) {
                if(v1 == -1)
                    v1 = v;
                else
                    v2 = v;
            }
        }

        if(v1 != -1 && v2 != -1) {
            VetorDeListaDeAdjacencias[v1].InsereNoFim(v2);
            VetorDeListaDeAdjacencias[v2].InsereNoFim(v1);
        }
    }
}

void Grafo::ConverteDaEstruturaEncadeadaParaMatrizDeAdjacencias() {
    for(int i = 0; i < nVertices; i++) {
        for(int j = 0; j < nVertices; j++) {
            MatrizAdjacencias[i][j] = 0;
        }
    }

    for(int i = 0; i < nVertices; i++) {
        Nodo* ptr = VetorDeListaDeAdjacencias[i].Inicio;
        while(ptr != NULL) {
            int j = ptr->info;
            MatrizAdjacencias[i][j] = 1;
            ptr = ptr->prox;
        }
    }
}

