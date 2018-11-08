#ifndef ARBOLPELICULAS_H_INCLUDED
#define ARBOLPELICULAS_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Estructuras.h"
#include "listaPeliculas.h"

nodoArbolPelicula * inicArbol();
nodoArbolPelicula * crearNodoArbolPelicula(stPelicula pelicula);
nodoArbolPelicula * insertarNodoArbol(nodoArbolPelicula * arbol, nodoArbolPelicula * nuevo);
void MostarArbolPreorder(nodoArbolPelicula * arbol);
void MostrarArbolInorder(nodoArbolPelicula * arbol);
void MostarArbolPostorder(nodoArbolPelicula * arbol);
nodoArbolPelicula * buscarPelicula(nodoArbolPelicula * arbol, int idPelicula);
nodoArbolPelicula * buscarNombre(nodoArbolPelicula * arbol, char nombre[]);
int nodosArbol(nodoArbolPelicula * arbol);
int hojaArbol(nodoArbolPelicula * arbol);
int hojasArbol(nodoArbolPelicula * arbol);
int alturaArbol(nodoArbolPelicula * arbol);
nodoArbolPelicula * borrarNodoArbol(nodoArbolPelicula * arbol, int legajo);
nodoArbolPelicula * NMI(nodoArbolPelicula * arbol);
nodoArbolPelicula * NMD(nodoArbolPelicula * arbol);
nodoArbolPelicula * archivoAArbolPelis(const char archivo[], nodoArbolPelicula * arbolP);
nodoArbolPelicula * mejorRaiz(nodoArbolPelicula * arbolP);
nodoArbolPelicula * recargarArbol(nodoArbolPelicula * arbol);
nodoArbolPelicula * arbolAArreglo(nodoArbolPelicula * arbol, stPelicula peliculas[], int i);
nodoArbolPelicula * balancearArbolPelis(nodoArbolPelicula * arbolP);

#endif // ARBOLPELICULAS_H_INCLUDED
