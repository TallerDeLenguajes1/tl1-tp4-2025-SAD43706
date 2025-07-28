#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
struct Tarea{
    int TareaID;//Numérico autoincremental comenzando en 1000
    char *Descripcion; //
    int Duracion; // entre 10 – 100
}typedef Tarea;
typedef struct Nodo{
    Tarea T;
    struct Nodo *Siguiente;
}Nodo;
Nodo *crearLista();
Tarea cargarTarea();
Nodo *CrearNodo(Tarea T);
void enLista(Nodo **Inicio,Nodo *Nodo);
void mostrarLists();
int main(){
    char estado='s';
    int idx=1000;
    Nodo *InicioP;
    Nodo *InicioR;
    InicioP=crearLista();
    InicioR=crearLista();
    do
    {
       puts("Ingrese la Tarea Pendiente:");
        Tarea TareaX=cargarTarea();
        TareaX.TareaID=idx++;
       Nodo *nuevo=CrearNodo(TareaX);
       enLista(&InicioP,nuevo);
       puts("Desea Ingresar otra tarea Pendiente(s/n)");
       scanf(" %c",&estado);
       getchar();
    } while (tolower(estado)=='s');
    
}
Nodo *crearLista(){
    return NULL;
}
Tarea cargarTarea(){
    Tarea T;

    char des[500];
    int duracion;
    puts("Ingrese la Descrpcion de la Tarea a Realizar:");
    fgets(des,500,stdin);
    des[strcspn(des, "\n")] = '\0';//Mas seguro y no se corta despues del espacio fgets(desino,tamaño,stdin tecladox)
    int tamDes=strlen(des)+1;
    char *description;
    description=(char*)malloc(tamDes*sizeof(char));
    strcpy(description,des);
    
    puts("Ingrese la Duracion(10-100):");
    scanf(" %i",&duracion);
    getchar();

    T.Descripcion=description;
    T.Duracion=duracion;
    
    return T;
}
Nodo *CrearNodo(Tarea T)
{
    Nodo *Nnodo = (Nodo *) malloc (sizeof(Nodo));
    Nnodo->T = T;
    Nnodo->Siguiente = NULL;
    return Nnodo;
}
void enLista(Nodo **Inicio,Nodo *nuevo){
    nuevo->Siguiente=*Inicio;
    *Inicio=nuevo;
}
void mostrarLists(Nodo *Inicio){
    Nodo *nodoMos=Inicio;
    int TamDes,i;
    if (nodoMos==NULL)
    {
        printf("La Lista esta Vacia");
    }
    else
    {
        while (Inicio!=NULL)
        {
            printf("ID\n:%i",nodoMos->T.TareaID);
            /*TamDes=strlen(nodoMos->T.Descripcion);
            for ( i = 0; i < TamDes; i++)
            {
            
            }*/
            printf("DESCRIPCION:%s\n",nodoMos->T.Descripcion);
            printf("DURACION:%i\n",nodoMos->T.Duracion);
            nodoMos=nodoMos->Siguiente;
        }    
    }
}