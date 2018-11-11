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
stPelicula cargaPelicula();
void altaPelicula();
void modificarPelicula(int idPelicula);
void MostrarArbol(nodoArbolPelicula * arbol, int opcion);
void MostrarArbolPreorder(nodoArbolPelicula * arbol);
void MostrarArbolInorder(nodoArbolPelicula * arbol);
void MostrarArbolPostorder(nodoArbolPelicula * arbol);
void MostrarArbol2D(nodoArbolPelicula * arbolP, int espacio);
nodoArbolPelicula * buscarPelicula(nodoArbolPelicula * arbol, int idPelicula);
nodoArbolPelicula * buscarNombre(nodoArbolPelicula * arbol, char nombre[]);
int nodosArbol(nodoArbolPelicula * arbol);
int hojaArbol(nodoArbolPelicula * arbol);
int hojasArbol(nodoArbolPelicula * arbol);
int alturaArbol(nodoArbolPelicula * arbol);
void eliminarPelicula(nodoArbolPelicula * arbol, int idPelicula);
nodoArbolPelicula * borrarNodoArbol(nodoArbolPelicula * arbol, int legajo);
nodoArbolPelicula * borrarArbol(nodoArbolPelicula * arbol);
nodoArbolPelicula * NMI(nodoArbolPelicula * arbol);
nodoArbolPelicula * NMD(nodoArbolPelicula * arbol);
nodoArbolPelicula * archivoAArbolPelis(const char archivo[], nodoArbolPelicula * arbol);
void arbolPelisAArchivo(const char archivo[], nodoArbolPelicula * arbol);
void arbolPelisAArchivoR(FILE* archi, nodoArbolPelicula * arbol);
nodoArbolPelicula * insertarNodoArbolBalanceado(nodoArbolPelicula * arbol, nodoArbolPelicula * nuevo);
nodoArbolPelicula * rotarIzq(nodoArbolPelicula * arbol);
nodoArbolPelicula * rotarDer(nodoArbolPelicula * arbol);
int arbolDesbalanceado(nodoArbolPelicula * arbol);

#endif // ARBOLPELICULAS_H_INCLUDED
