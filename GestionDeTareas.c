#include<stdio.h>
#include<stdlib.h>
struct Tarea{
    int TareaID;//Numérico autoincremental comenzando en 1000
    char *Descripcion; //
    int Duracion; // entre 10 – 100
}typedef Tarea;
struct Nodo{
    Tarea T;
    Nodo *Siguiente;
}typedef Nodo;
void mostrarLists();
Nodo *crearLista();
int main(){
    Nodo *InicioP;
    Nodo *InicioR;
    InicioP=crearLista();
    InicioR=crearLista();
    
}
