#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "list.h"

typedef struct Nodo{
  const char* data;
  struct Nodo* prev;
  struct Nodo* next;
}Nodo;

typedef struct List{
  Nodo* primero;
  Nodo* ultimo;
  Nodo* current;
}List;

typedef List Lista;


/*Crear nuevo Nodo*/
Nodo* crearNodo(const void * data){
    Nodo * nuevoNodo = (Nodo*)malloc(sizeof(Nodo));
    if(nuevoNodo == NULL){
      return NULL;
    }
    
    nuevoNodo->data = (void*)data;
    nuevoNodo->prev = NULL;
    nuevoNodo->next = NULL;
    
    return nuevoNodo;
}

/*Crear nueva Lista*/
List* createList(){
  List* list = (List*) malloc(sizeof(List));
  list->primero = NULL;
  list->ultimo = NULL;
  list->current =NULL;

  return list;
}

void* firstList(List* list){

  if(list->primero == NULL){
    return NULL;
  }

  list->current = list->primero;
  
  return (void*)list->current->data;
}

void * nextList(List * list) {
 
  if(list->current && list->current->next != NULL){
    list->current=list->current->next;
  }else{
    return NULL;
  }
 
   return (void*)list->current->data;
}

void * lastList(List * list) {
 
  if(list->ultimo == NULL){ 
    return NULL; 
  }else{ 
    list->current=list->ultimo; 
    return (void *)list->current->data;
  
  }
}

void * prevList(List * list) {
   
    if(list->current && list->current->prev != NULL){    
      list->current=list->current->prev;  
    }else{  
    return NULL;   
    }
    
     return (void *)list->current->data;
}

void pushFront(List * list, const void * data) {
    
    if(list != NULL){ 
    Nodo* nodo = crearNodo(data);  
      if (list->primero == NULL) { 
          list->ultimo = nodo;
      } else {
          nodo->next = list->primero;    
          list->primero->prev = nodo;
      }    
      list->primero = nodo;
    }
}

void * popFront(List * list){
    
    list->current = list->primero;    
    return popCurrent(list);
}

void pushBack(List * list, const void * data) {
    
    list->current = list->ultimo;
    if(list->current==NULL){  
      pushFront(list,data);    
    }else{     
      pushCurrent(list,data);  
    }
}

void * popBack(List * list){
   
    list->current = list->ultimo;
   
    return popCurrent(list);
}

void pushCurrent(List * list, const void * data) {
    if(list != NULL && list->current !=NULL){

    Nodo* nodo = crearNodo(data);

    if(list->current->next)
        nodo->next = list->current->next;
    nodo->prev = list->current;

    if(list->current->next)
        list->current->next->prev = nodo;
    list->current->next = nodo;

    if(list->current == list->ultimo)
        list->ultimo = nodo;
    }
}

void * popCurrent(List * list){
    if(list->current == list->primero) {
   list->primero = list->primero->next;
   list->primero->prev = NULL;}
  else{ 
    if (list->current == list->ultimo){
         list->ultimo = list->ultimo->prev;
         list->ultimo->next = NULL;}
        else{ 
          list->primero = list->current;
          }
      }
       return (void*)(list->current->data);
  }

void cleanList(List * list) {
    if(list != NULL){
    
      while (list->primero != NULL) {
          popFront(list);
      }
    }
}
