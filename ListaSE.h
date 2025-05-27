

#include "Nodo.h"

#ifndef _LISTASE
#define _LISTASE

// ****************************
// Lista Simplesmente Encadeada
typedef struct ListaSE{ 
  Nodo *Inicio;
  Nodo *Fim;

  void CriaLista();
  void ImprimeLista();
  int InsereNoInicio(int dado);
  int InsereNoFim(int dado);
  int RemoveDoInicio();
  Nodo* BuscaDado(int dado);
  int RemoveDado(int dado);

} ListaSE;

#endif
