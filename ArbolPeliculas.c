#include "ArbolPeliculas.h"

nodoArbolPelicula * inicArbol()
{
    return NULL;
}

nodoArbolPelicula * crearNodoArbolPelicula(stPelicula pelicula)
{
    nodoArbolPelicula * aux = (nodoArbolPelicula *) malloc(sizeof(nodoArbolPelicula));
    aux->p = pelicula;
    aux->der=NULL;
    aux->izq=NULL;
    return aux;
}

nodoArbolPelicula * insertarNodoArbol(nodoArbolPelicula * arbol, nodoArbolPelicula * nuevo)
{
    if(!arbol)
    {
        arbol = nuevo;
    }
    else
    {
        if(nuevo->p.idPelicula>arbol->p.idPelicula) arbol->der = insertarNodoArbol(arbol->der, nuevo);
        else arbol->izq = insertarNodoArbol(arbol->izq, nuevo);
    }
    return arbol;
}

void MostrarArbolPreorder(nodoArbolPelicula * arbol)
{
    if(arbol)
    {
        printf("\n%d  %s", arbol->p.idPelicula, arbol->p.nombrePelicula);
        MostrarArbolPreorder(arbol->izq);
        MostrarArbolPreorder(arbol->der);
    }

}

void MostrarArbolInorder(nodoArbolPelicula * arbol)
{
    if(arbol)
    {
        MostrarArbolInorder(arbol->izq);
        printf("\n%d  %s", arbol->p.idPelicula, arbol->p.nombrePelicula);
        MostrarArbolInorder(arbol->der);
    }
}

void MostrarArbolPostorder(nodoArbolPelicula * arbol)
{
    if(arbol)
    {
        MostrarArbolPostorder(arbol->izq);
        MostrarArbolPostorder(arbol->der);
        printf("\n%d  %s", arbol->p.idPelicula, arbol->p.nombrePelicula);
    }
}

nodoArbolPelicula * buscarPelicula(nodoArbolPelicula * arbol, int idPelicula)
{
    nodoArbolPelicula * rta = NULL;
    if(arbol)
    {
        if(idPelicula == arbol->p.idPelicula)
        {
            rta = arbol;
        }
        else if(idPelicula > arbol->p.idPelicula)
        {
            rta = buscarPelicula(arbol->der, idPelicula);
        }
        else
        {
            rta = buscarPelicula(arbol->izq, idPelicula);
        }
    }
    return rta;
}

nodoArbolPelicula * buscarNombre(nodoArbolPelicula * arbol, char nombre[])
{
    nodoArbolPelicula * rta=NULL;
    if(arbol)
    {
        if(strcmp(nombre,arbol->p.nombrePelicula) == 0)
        {
            rta = arbol;
        }
        else
        {
            rta = buscarNombre(arbol->izq, nombre);
            if(!rta) rta = buscarNombre(arbol->der, nombre);
        }
    }
    return rta;
}

int nodosArbol(nodoArbolPelicula * arbol)
{
    int rta = 0;
    if(arbol) rta = 1 + nodosArbol(arbol->izq) + nodosArbol(arbol->der);
    return rta;
}

int hojaArbol(nodoArbolPelicula * arbol)
{
    return (!(arbol->der) && !(arbol->izq));
}

int hojasArbol(nodoArbolPelicula * arbol)
{
    int rta = 0;
    if(arbol)
    {
        if(hojaArbol(arbol)) rta = 1 + hojasArbol(arbol->izq) + hojasArbol(arbol->der);
        else rta = hojasArbol(arbol->izq) + hojasArbol(arbol->der);
    }
    return rta;
}

int alturaArbol(nodoArbolPelicula * arbol)
{
    int rta = 0;
    if(arbol)
    {
        int izq = alturaArbol(arbol->izq);
        int der = alturaArbol(arbol->der);
        if(izq > der) rta = 1 + izq;
        else rta = 1 + der;
    }
    return rta;
}

nodoArbolPelicula * borrarNodoArbol(nodoArbolPelicula * arbol, int idPelicula)
{
    if(arbol)
    {
        if(idPelicula == arbol->p.idPelicula)
        {
            if(arbol->izq != NULL)
            {
                nodoArbolPelicula * nmd = NMD(arbol->izq);
                arbol->p = nmd->p;
                arbol->izq = borrarNodoArbol(arbol->izq, nmd->p.idPelicula);
            }
            else if(arbol->der != NULL)
            {
                nodoArbolPelicula * nmi = NMI(arbol->der);
                arbol->p = nmi->p;
                arbol->der = borrarNodoArbol(arbol->der,nmi->p.idPelicula);
            }
            else
            {
                free(arbol);
                arbol = NULL;
            }
        }
        else if(idPelicula>arbol->p.idPelicula)
        {
            arbol->der = borrarNodoArbol(arbol->der, idPelicula);
        }
        else
        {
            arbol->izq = borrarNodoArbol(arbol->izq, idPelicula);
        }
    }
    return arbol;
}

nodoArbolPelicula * borrarArbol(nodoArbolPelicula * arbol)
{
    if(arbol)
    {
        arbol = borrarArbol(arbol->izq);
        arbol = borrarArbol(arbol->der);
        free(arbol);
    }
    return arbol;
}

nodoArbolPelicula * NMI(nodoArbolPelicula * arbol)
{
    nodoArbolPelicula * rta = NULL;
    if(arbol)
    {
        if(arbol->izq) rta = NMI(arbol->izq);
        else rta = arbol;
    }
    return rta;
}

nodoArbolPelicula * NMD(nodoArbolPelicula * arbol)
{
    nodoArbolPelicula * rta = NULL;
    if(arbol)
    {
        if(arbol->der) rta = NMD(arbol->der);
        else rta = arbol;
    }
    return rta;
}

nodoArbolPelicula * archivoAArbolPelis(const char archivo[], nodoArbolPelicula * arbol)
{
    FILE *archi;
    archi = fopen(archivo,"rb");
    if(archi != NULL)
    {
        stPelicula aux;
        while(fread(&aux, sizeof(stPelicula), 1, archi) > 0 && !(aux.eliminado)) //recorro el archivo de peliculas
        {
            nodoArbolPelicula * nuevo = crearNodoArbolPelicula(aux);
            arbol = insertarNodoArbol(arbol,nuevo);
        }
        fclose(archi);
    }
    return arbol;
}

nodoArbolPelicula * mejorRaiz(nodoArbolPelicula * arbol)
{
    nodoArbolPelicula * mejor = NULL;
    if(!hojaArbol(arbol))
    {
        nodoArbolPelicula * nmi = NMD(arbol);
        nodoArbolPelicula * nmd = NMD(arbol);
        int difidmejor = (nmd->p.idPelicula-nmi->p.idPelicula)/2;
        if(difidmejor != 0)
        {
            int idmejor = nmi->p.idPelicula+difidmejor;
            mejor = buscarPelicula(arbol,idmejor);
        }
    }
    return mejor;
}

nodoArbolPelicula * recargarArbol(nodoArbolPelicula * arbol)
{
    int cant = nodosArbol(arbolP);
    stPelicula peliculas[cant];
    arbol = arbolAArreglo(arbol, peliculas, 0);
    for(int i = 0; i < cant; i++)
    {
        arbol = insertarNodoArbol(arbol,crearNodoArbolPelicula(peliculas[i]));
    }
    return arbol;
}

nodoArbolPelicula * arbolAArreglo(nodoArbolPelicula * arbol, stPelicula peliculas[], int i)
{
    if(arbol)
    {
        peliculas[i] = arbol->p;
        arbol = arbolAArreglo(arbol->der, peliculas, i+1);
        free(arbol);
    }
    return arbol;
}

nodoArbolPelicula * balancearArbolPelis(nodoArbolPelicula * arbol)
{
    if(arbol)
    {
        nodoArbolPelicula * mejor = mejorRaiz(arbol);
        if(mejor)
        {
            stPelicula aux = arbol->p;
            arbol->p = mejor->p;
            mejor->p = aux;
            arbol->der = recargarArbol(arbol->der);
            arbol->der = balancearArbolPelis(arbol->der);
        }
    }
    return arbol;
}

void MostrarArbol2D(nodoArbolPelicula * arbol, int espacio)
{
    if(arbol == NULL)
        return;

    espacio += 10;
    MostrarArbol2D(arbol->der, espacio);

    printf("\n");
    for (int i = 10; i < espacio; i++)
        printf(" ");
    printf("%d\n", arbol->p.idPelicula);

    MostrarArbol2D(arbol->izq, espacio);
}

void MostrarArbol(nodoArbolPelicula * arbol, int opcion)
{
    switch(opcion)
    {
        case 1: MostrarArbolPreorder(arbol);
        case 2: MostrarArbolInorder(arbol);
        case 3: MostrarArbolPostorder(arbol);
        case 4: MostrarArbol2D(arbol,0);
    }
}
