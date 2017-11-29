/*
*   CARLOS ALEJANDRO GONZALEZ ORTIZ
*   01217290
*   PROGRAMA BASICO PARA GENERAR GRAFOS DEL TIPO ARBOL
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct nodoArbol
{
    struct nodoArbol *izq,*der;
    int dato;
}nodoArbol;

void insertar (nodoArbol **raiz,int dato);
nodoArbol *buscarNumero (nodoArbol **raiz,int dato);
void borrarNodo (nodoArbol **nodo,int dato);
void orden(nodoArbol *raiz);

int main()
{
    nodoArbol *raiz = NULL;
    int opcion = 0;
    int dato;
    do
    {
        printf("-- PRACTICA ARBOLES --\n\n");
        printf("1.- INGRESAR NODO\n");
        printf("2.- BUSCAR DATO\n");
        printf("3.- BORRAR NODO\n");
        printf("4.- IMPRIMIR\n");
        printf("5.- SALIR\n");

        printf("\nINGRESA OPCION -> ");
        scanf("%d",&opcion);
        fflush(stdin);

        switch(opcion)
        {
            case 1:
                system("cls");
                printf("INGRESA DATO -> ");
                scanf("%d",&dato);
                if (raiz != NULL)
                    insertar(&raiz,dato);
                else
                {
                    raiz =(nodoArbol*) malloc(sizeof(nodoArbol));
                    raiz ->dato = dato;
                    raiz ->der = NULL;
                    raiz ->izq = NULL;

                    printf("\nDATO EN RAIZ = [%d]\n",raiz -> dato);
                    system("pause");
                }
            break;

            case 2:
                if(raiz)
                {
                    system("cls");
                    printf("INGRESA DATO -> ");
                    scanf("%d",&dato);
                    buscarNumero(&raiz,dato);
                }
                else
                {
                    printf("NO HAY NODOS\n");
                    system("pause");
                }
            break;

            case 3:
                if(raiz)
                {
                    nodoArbol *aux = NULL;
                    system("cls");
                    printf("INGRESA DATO -> ");
                    scanf("%d",&dato);
                    aux = buscarNumero(&raiz,dato);
                    borrarNodo(&aux,dato);
                }
                else
                {
                    printf("NO HAY NODOS\n");
                    system("pause");
                }
            break;

            case 4:
                orden(raiz);
                printf("\n");
                system("pause");
            break;

            case 5:
            break;

            default:
                system("cls");
                printf("OPCION NO VALIDA\n");
                system("pause");
            break;
        }
        system("cls");
    }while(opcion != 5);


    return 0;
}
void orden(nodoArbol *raiz)
{
    if(raiz != NULL)
    {
        orden(raiz->izq);
        printf("\n%d",raiz->dato);
        orden(raiz->der);
    }
}

void borrarNodo (nodoArbol **nodo,int dato)         // AUN NO FUNCIONA
{
    if((*nodo)->der == NULL && (*nodo)->izq == NULL)
    {

        return free(nodo);
    }
    else if((*nodo)->der != NULL)
        return borrarNodo(&((*nodo)->der),dato);
    else if((*nodo)->izq != NULL)
        return borrarNodo(&((*nodo)->izq),dato);
}

void insertar (nodoArbol **raiz,int dato)
{
    nodoArbol *actual = NULL;
    nodoArbol *anterior = NULL;
    nodoArbol *nodoNuevo = NULL;
    nodoNuevo = (nodoArbol*)malloc(sizeof(nodoArbol));
    /*  Inicializamos el nodo   */
    nodoNuevo -> dato = dato;
    /* Aseguramos que los apuntadores sean nulos
       de lo contrario podria apuntar a contenido basura */
    nodoNuevo -> der = NULL;
    nodoNuevo -> izq = NULL;
    actual = *raiz; // Apuntador auxiliar para movernos entre direcciones de memoria
    while(actual != NULL) //    El Ciclo ayuda a recorrer los nodos del arbol
    {
        anterior = actual;  //  Almacena la direccion del nodo con el que conectara al nodo nuevo en el ultimo paso
        if(nodoNuevo->dato > actual->dato)
            actual = actual ->der;
        else if (nodoNuevo ->dato == actual->dato)
        {
            printf("\n YA EXISTE DATO");
            return;
        }
        else
            actual = actual->izq;
    }
    if (nodoNuevo -> dato > anterior ->dato)
        anterior ->der = nodoNuevo;
    else
        anterior->izq = nodoNuevo;
}

nodoArbol *buscarNumero (nodoArbol **raiz,int dato)
{
    nodoArbol *actual = NULL;
    if(dato != (*raiz)->dato)
    {
        actual = *raiz;
        while(actual != NULL)
        {
            if(dato > actual->dato)
                actual = actual ->der;
            else if (dato == actual->dato)
            {
                printf("SE ENCONTRO, DIRECCION = [%p]\n",actual);
                system("pause");
                return actual;
            }
            else
                actual = actual->izq;
        }
            printf("NO SE ENCONTRO\n");
            system("pause");
    }
    else
    {
        printf("VALOR ESTA EN RAIZ\n");
        system("pause");
    }
    return NULL;
}

