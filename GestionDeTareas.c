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
void mostrarLists(Nodo *Inicio);
Nodo *BNPQ(Nodo **Lista,int id);//Busqueda Nodo Para Sacar
Nodo *buscarNodoporId(Nodo *buscado,int id);
Nodo *buscarNodoporPalabra(Nodo *Start, char *clave);
void EliminarNodo(Nodo *nodo);
void liberarLista(Nodo *Inicio);

int main(){
    char estado='s',estado2;
    int idx=1000,idBuscada,eleccion;
    Nodo *InicioP;
    Nodo *InicioR;
    Nodo *Resultado;
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
    mostrarLists(InicioP);
    printf("Apriete (y/Y) si desea pasar una o mas Tareas de Pendientes a Realizadas, (n/N) sino\n");
    scanf("%c",&estado2);
    while (tolower(estado2)=='y')
    {
        printf("Ingrese la ID de la Tarea que quiere colocar en la Lista de Realizadas:");
        scanf("%i",&idBuscada);
        enLista(&InicioR,BNPQ(&InicioP,idBuscada));
        puts("Desea Ingresar otra tarea Realizada(y/n)");
        scanf(" %c",&estado2);  
    }
    mostrarLists(InicioR);
    printf("Desea Buscar un Nodo por Id o por palabra clave?? 1=id,2=Palabra Clave");
    scanf("%i",&eleccion);
    if (eleccion==1)
    {
        int idBusq;
        printf("Ingrese La ID a Buscar:");
        scanf("%i",&idBusq);
        Resultado=buscarNodoporId(InicioP,idBusq);
        if (Resultado!=NULL)
        {
            mostrarLists(Resultado);  
            printf("El nodo se encuentra en la Lista de tareas pendientes"); 
        }else{
            Resultado=buscarNodoporId(InicioR,idBusq);
            if (Resultado!=NULL)
            {
                mostrarLists(Resultado);
                printf("El nodo se encuentra en la Lista de tareas realizadas");
            }
            else
            {
                printf("El nodo NO se encuentra en ninguna Lista");
            }
        } 
    }else if (eleccion==2)
    {
        char clave[15];
        printf("Ingrese La Palabra a Buscar:");
        scanf("%s",clave);
        int tamClave=strlen(clave)+1;
        char *clavex;
        clavex=(char*)malloc(tamClave*sizeof(char));
        strcpy(clavex,clave);
        Resultado=buscarNodoporPalabra(InicioP,clavex);
        if (Resultado!=NULL)
        {
            mostrarLists(Resultado);  
            printf("El nodo se encuentra en la Lista de tareas pendientes"); 
        }else{
            Resultado=buscarNodoporPalabra(InicioR,clavex);
            if (Resultado!=NULL)
            {
                mostrarLists(Resultado);
                printf("El nodo se encuentra en la Lista de tareas realizadas");
            }else
            {
                printf("El nodo NO se encuentra en ninguna Lista");
            } 
        }
        free(clavex); 
    }
    liberarLista(InicioP);
    liberarLista(InicioR);
     
    return 0;
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
        while (nodoMos!=NULL)
        {
            printf("-------------------------\n");
            printf("ID:%i\n",nodoMos->T.TareaID);
            printf("DESCRIPCION:%s\n",nodoMos->T.Descripcion);
            printf("DURACION:%i\n",nodoMos->T.Duracion);
            printf("-------------------------\n");
            nodoMos=nodoMos->Siguiente;
        }    
    }
}
Nodo *BNPQ(Nodo **Lista,int id){
    Nodo *nodoAux = (*Lista);
    Nodo *nodoAnt = NULL;
    while (nodoAux != NULL && nodoAux->T.TareaID != id)
    {
        nodoAnt = nodoAux;
        nodoAux = nodoAux->Siguiente;
    }
    if (nodoAux != NULL)
    {
        if (nodoAux == (*Lista))
        {
            (*Lista) = nodoAux->Siguiente;
        }
        else
        {
            nodoAnt->Siguiente = nodoAux->Siguiente;
        }
        nodoAux->Siguiente = NULL;
    }
    return (nodoAux);
}
Nodo *buscarNodoporId(Nodo *Start, int IdBuscado){
    Nodo *Aux = Start;
    while(Aux && Aux -> T.TareaID != IdBuscado)
    {
        Aux = Aux -> Siguiente;
    }      
    if (Aux!=NULL)
    {
        return Aux;
    }
    else{
        return NULL;
    }
}
Nodo *buscarNodoporPalabra(Nodo *Start, char *clave){
    Nodo *Aux = Start;
    while(Aux && strstr(Aux->T.Descripcion,clave))
    {
        Aux = Aux -> Siguiente;
    }      
    if (Aux!=NULL)
    {
        return Aux;
    }
    else{
        return NULL;
    }
}
void EliminarNodo(Nodo *nodo)
{
    if (nodo) 
    {
        free(nodo->T.Descripcion);
        free(nodo);
    }
    
}
void liberarLista(Nodo *Inicio) {
    Nodo *aux;
    while (Inicio != NULL) {
        aux = Inicio;
        Inicio = Inicio->Siguiente;
        free(aux->T.Descripcion); // liberar descripción
        free(aux);                // liberar nodo
    }
}
