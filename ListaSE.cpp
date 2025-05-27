

#include <stdio.h>
#include <stdlib.h>
#include "ListaSE.h"

void ListaSE::CriaLista()
{
  Inicio = NULL;
  Fim = NULL;
}

void ListaSE::ImprimeLista()
{

  Nodo *ptr;
  if (Inicio == NULL)
  {
    printf("--- Lista Vazia\n");
    return;
  }
  // Caso a lista nao esteja vazia
  ptr = Inicio;
  while (ptr !=NULL) {
     printf("Info = %d\n",ptr->info);
     ptr = ptr->prox;
  }
  printf("--- fim da lista ---\n\n");
}


//--------------------------------------------------------
// Funcao que insere um elemento do inicio da lista.
// Retorna:
//	0 - se nao ha'  memoria para inserir
//	1 - se conseguiu inserir
int ListaSE::InsereNoInicio(int dado)
{
   Nodo *p;
   p =  (Nodo *) malloc(sizeof(Nodo));
   if (p==NULL)
   {
     printf("Erro de alocacao\n");
     return 0;
   }
   p->info = dado;
   p->prox = NULL;
   if (Inicio==NULL) // Lista Vazia??
      Inicio = p;
   else {
	  p->prox = Inicio;
	  Inicio  = p;
	}
   return 1;
}

//--------------------------------------------------------
// Funcao que remove um elemento do Inicio da lista.
// Retorna:
//	0 - se a lista ja'  estava vazia
//	1 - se conseguiu remover
int ListaSE::RemoveDoInicio()
{
  Nodo *ptr;
  if (Inicio==NULL)
    return 0;
  else
  {
    ptr = Inicio;
    Inicio = Inicio->prox;
    free(ptr);
    return 1;
  }
}


//--------------------------------------------------------
// Funcao que busca um elemento na lista.
// Retorna:
//	- NULL caso nao encontre
//	- ponteiro para o NODO onde esta' o dado, se conseguir encontrar
Nodo* ListaSE::BuscaDado(int dado)
{
  Nodo *ptr;
  if (Inicio == NULL)
  {
    return NULL;  // Lista Vazia
  }
  // Caso a lista nao esteja vazia
  ptr = Inicio;
  while (ptr !=NULL) {
     if (ptr->info == dado)  // achou !!
	      return (ptr);        // 
      else ptr = ptr->prox;  // avança para o próximo nodo
     
  }
  return NULL;
}

//--------------------------------------------------------
// Funcao que remove um elemento especificado por 'dado'
// Retorna:
//	0 - se nao conseguiu achar
//	1 - se conseguiu remover
int ListaSE::RemoveDado(int dado)
{
  Nodo *ptr, *antes;
  if (Inicio==NULL)
  {
      return 0;  // Lista vazia !!!
  }
  else
  {   // Caso a lista nao esteja vazia
      ptr = Inicio;
      antes = Inicio;
      while (ptr !=NULL)
      {
	    if (ptr->info == dado) // achou !!
	    {
	      if (ptr == Inicio) // se esta removendo o primeiro da lista
	      {
	        Inicio = Inicio->prox;
	        free(ptr);
	        return 1; // removeu !!
	      }
	      else  // esta removendo do meio da lista
	      {
	       antes->prox = ptr->prox;  // Refaz o encadeamento
	       free(ptr);                // Libera a area do nodo
	       return 1;   // removeu !!
	      }
	  }
	  else  // continua procurando no prox. nodo
	  {
	    antes = ptr;
	    ptr = ptr->prox;
	  }
      }
      return 0; // Nao achou !!!
  }
}
//--------------------------------------------------------
// Funcao que insere um elemento do FIM da lista.
// Retorna:
//	0 - se nao ha'  memoria para inserir
//	1 - se conseguiu inserir
int ListaSE::InsereNoFim(int dado)
{
   Nodo *p;
   p =  (Nodo *) malloc(sizeof(Nodo));
   if (p==NULL)
   {
     printf("Erro de alocacao\n");
     return 0;
   }
   p->info = dado;
   p->prox = NULL;
    Nodo *ptr, *antes;
   if (Inicio==NULL) // Lista Vazia??
      Inicio = p;
   else {
      ptr = Inicio;
	    while (ptr !=NULL) // vai até o final da lista
      {
        antes = ptr;
	      ptr = ptr->prox;
      }
      antes->prox = p;
	}
   return 1;
}