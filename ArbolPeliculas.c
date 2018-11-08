#include "ArbolPeliculas.h"

nodoArbolPelicula * inicArbol()
{
    return NULL;
}

nodoArbolPelicula * crearnodoArbolPelicula(stPelicula pelicula)
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

void MostarArbolPreorder(nodoArbolPelicula * arbol)
{
    if(arbol)
    {
        printf("\n%d  %s", arbol->p.idPelicula, arbol->p.nombrePelicula);
        MostarArbolPreorder(arbol->izq);
        MostarArbolPreorder(arbol->der);
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

void MostarArbolPostorder(nodoArbolPelicula * arbol)
{
    if(arbol)
    {
        MostarArbolPostorder(arbol->izq);
        MostarArbolPostorder(arbol->der);
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
    nodoArbolPelicula * rta = NULL;
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

void cargarArbolDesdeArchivo(nodoArbolPelicula * arbol, char archivo[])
{
    stPelicula aux;
    FILE *archi;
    archi = fopen(ARCHIVO_PELICULAS,"rb");
    if(archi != NULL)
    {
        while(fread(&aux, sizeof(stPelicula), 1, archi) > 0 && !(aux.eliminado)) //recorro el archivo de peliculas
        {
            nodoArbolPelicula * nuevo = crearnodoArbolPelicula(aux);
            arbol = insertarNodoArbol(arbol,nuevo);
        }
        fclose(archi);
    }
}
