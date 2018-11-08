#ifndef ARBOLPELICULAS_H_INCLUDED
#define ARBOLPELICULAS_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Estructuras.h"

nodoArbolPelicula * inicArbol();
nodoArbolPelicula * crearnodoArbolPelicula(stPelicula pelicula);
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
void cargarArbolDesdeArchivo(nodoArbolPelicula * arbol, char archivo[]);

#endif // ARBOLPELICULAS_H_INCLUDED
