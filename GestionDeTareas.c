#include<stdio.h>
#include<stdlib.h>
#include<string.h>
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
Nodo *CrearNodo(Tarea T);
Tarea cargarTarea();
int main(){
    char estado='s';
    Nodo *InicioP;
    Nodo *InicioR;
    InicioP=crearLista();
    InicioR=crearLista();
    do
    {
       Tarea TareaX=cargarTarea();
       Nodo *nodo=CrearNodo(TareaX);

    } while (estado=='s');
    
}
Nodo *crearLista(){
    return NULL;
}
Nodo *CrearNodo(Tarea T)
{
    Nodo *Nnodo = (Nodo *) malloc (sizeof(Nodo));
    Nnodo->T = T;
    Nnodo->Siguiente = NULL;
    return Nnodo;
}
Tarea cargarTarea(){
    Tarea T;

    int id=1000;
    
    char des[500];
    int duracion;
    puts("Ingrese la Descrpcion de la Tarea a Realizar:");
    gets(des);
    int tamDes=strlen(des)+1;
    char *description;
    description=(char*)malloc(tamDes*sizeof(char));
    strcpy(description,des);
    
    puts("Ingrese la Duracion(10-100):");
    scanf("%i",&duracion);

    T.TareaID=id++;
    T.Descripcion=description;
    T.Duracion=duracion;
    
    return T;
}