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

    // le os valores da matriz de incidência linha por linha
    for(int i = 0; i < nVertices; i++) { // percorre as linhas da matriz, ou seja, os vértices {
        for(int j = 0; j < nArestas; j++) { // percorre as colunas da matriz, ou seja, as arestas {
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

// Imprime matriz de adjacência no console (usado apenas para debug visual)
// Esta função imprime a matriz de adjacência, que possui dimensões fixas nVertices x nVertices
// Cada célula indica se existe uma aresta direta entre dois vértices
// Esta função imprime a matriz de adjacência
// A matriz de adjacência é sempre quadrada: nVertices x nVertices
// Cada célula [i][j] indica se há uma conexão entre os vértices i e j
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

// Criado função auxiliar para imprimir matriz de incidência
// Esta função imprime a matriz de incidência, que tem dimensões nVertices x nArestas
// Cada coluna representa uma aresta e cada linha indica se o vértice incide nessa aresta
// Diferente da matriz de adjacência, a quantidade de colunas (arestas) depende da estrutura encadeada
// A matriz de incidência é retangular: nVertices x nArestas
// Cada coluna representa uma aresta, e cada linha indica se o vértice está conectado àquela aresta
// A quantidade de colunas (arestas) depende da estrutura encadeada, ou seja, da quantidade real de arestas no grafo
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
        // Para cada vizinho do vértice i
        while(ptr != NULL) {
            int j = ptr->info; // j é vizinho de i
            if(i < j) { // Para evitar duplicação de arestas (grafo não direcionado)
                MatrizDeIncidencias[i][nArestas] = 1;
                MatrizDeIncidencias[j][nArestas] = 1;
                nArestas++;
            }
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

