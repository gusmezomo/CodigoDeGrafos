
#ifndef _NODO
#define _NODO
// ****************************
typedef struct Nodo{
  int info;
  struct Nodo *prox;
  struct Nodo *prev;

  void setInfo(int i); 
  int getInfo();
  void setProx(Nodo *p);
  Nodo* getProx();
  void setPrev(Nodo *p);
  Nodo* getPrev();


} Nodo;

#endif 