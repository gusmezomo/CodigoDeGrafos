#include <iostream>
#include <fstream>
#include <cstdlib>
#include <stdio.h>
using namespace std;

#include "Grafo.h"

// le a matriz de incidência de um arquivo texto e preenche a matriz interna
void Grafo::LeMatrizINC(string Nome) {
    ifstream entrada;
    entrada.open(Nome.c_str(), ios::in);
    if (!entrada) {
        cout << "Problemas na abertura do arquivo!" << endl;
        exit(0);
    }

    entrada >> nVertices >> nArestas; // Lê número de vértices e arestas

    for(int i = 0; i < nVertices; i++) { // percorre as linhas da matriz,
        for(int j = 0; j < nArestas; j++) { // percorre as colunas da matriz,
            entrada >> MatrizDeIncidencias[i][j];
            if (!entrada) {
                cout << "Problemas na leitura!" << endl;
                exit(0);
            }
        }
    }

    entrada.close();
}

// imprime matriz de adjacência convertida da estrutura encadeada
void Grafo::SalvaMatrizADJ(string Nome) {
    ConverteDaEstruturaEncadeadaParaMatrizDeAdjacencias();

    // imprime a matriz linha por linha, separando os valores por vírgulas
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

// CRIADO função para imprimir matriz de incidência
void Grafo::ImprimeMatrizDeIncidencias() {
    for(int i = 0; i < nVertices; i++) {
        for(int j = 0; j < nArestas; j++) {
            cout << MatrizDeIncidencias[i][j] << ",";
        }
        cout << endl;
    }
}

// Converte lista encadeada (estrutura interna) para matriz de incidência
void Grafo::ConverteDaEstruturaEncadeadaParaMatrizDeIncidencias()
{
    nArestas = 0; // Zera o contador de arestas

    // Inicializa a matriz de incidência zerando todas as posições
    for(int i = 0; i < nVertices; i++) {
        for(int j = 0; j < MAX_ARESTAS; j++) {
            MatrizDeIncidencias[i][j] = 0;
        }
    }

    // Percorre cada lista de adjacência do grafo
    for(int i = 0; i < nVertices; i++) {
        Nodo* ptr = VetorDeListaDeAdjacencias[i].Inicio;
        while(ptr != NULL) {
            int j = ptr->info;
            if(i < j) { // Para evitar duplicação de arestas (grafo não direcionado)
                MatrizDeIncidencias[i][nArestas] = 1;
                MatrizDeIncidencias[j][nArestas] = 1;
                nArestas++;
            }
            ptr = ptr->prox;
        }
    }
}

// Converte lista encadeada para matriz de adjacência
void Grafo::ConverteDaEstruturaEncadeadaParaMatrizDeAdjacencias() {
    // Zera toda a matriz de adjacência
    for(int i = 0; i < nVertices; i++) {
        for(int j = 0; j < nVertices; j++) {
            MatrizAdjacencias[i][j] = 0;
        }
    }

    // Percorre cada lista encadeada e marca os vizinhos na matriz
    for(int i = 0; i < nVertices; i++) {
        Nodo* ptr = VetorDeListaDeAdjacencias[i].Inicio;
        while(ptr != NULL) {
            int j = ptr->info;
            MatrizAdjacencias[i][j] = 1;
            ptr = ptr->prox;
        }
    }
}

// Converte matriz de adjacência para lista encadeada
void Grafo::ConverteDaMatrizDeAdjacenciasParaEstruturaEncadeada() {
    // Para cada vértice, cria uma lista nova
    for(int i = 0; i < nVertices; i++) {
        VetorDeListaDeAdjacencias[i].CriaLista();
        // Adiciona vizinhos com base nos valores da matriz
        for(int j = 0; j < nVertices; j++) {
            if(MatrizAdjacencias[i][j] != 0) {
                VetorDeListaDeAdjacencias[i].InsereNoFim(j);
            }
        }
    }
}

// Converte matriz de incidência para lista encadeada
void Grafo::ConverteDaMatrizDeIncidenciasParaEstruturaEncadeada() {
     // Inicializa as listas encadeadas de todos os vértices
    for(int i = 0; i < nVertices; i++) {
        VetorDeListaDeAdjacencias[i].CriaLista();
    }
    
    // Percorre cada coluna da matriz de incidência (cada aresta)
    for(int a = 0; a < nArestas; a++) {
        int v1 = -1, v2 = -1;

        // Encontra os dois vértices conectados por essa aresta
        for(int v = 0; v < nVertices; v++) {
            if(MatrizDeIncidencias[v][a] == 1) {
                if(v1 == -1)
                    v1 = v;
                else
                    v2 = v;
            }
        }

         // Adiciona os dois vértices à lista um do outro
        if(v1 != -1 && v2 != -1) {
            VetorDeListaDeAdjacencias[v1].InsereNoFim(v2);
            VetorDeListaDeAdjacencias[v2].InsereNoFim(v1);
        }
    }
}


