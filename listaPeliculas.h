#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Estructuras.h"
#ifndef LISTAPELICULAS_H_INCLUDED
#define LISTAPELICULAS_H_INCLUDED

stPelicula altaPelicula(nodoListaPelicula * listaP);
int existePelicula(nodoListaPelicula * listaP, char nombre[]);
int eliminarPelicula(nodoListaPelicula * listaP, int idPelicula);
int cantidadPeliculas(nodoListaPelicula * listaP);
void mostrarUnaPelicula(stPelicula pelicula);
void mostrarTodasLasPelis(nodoListaPelicula * listaP);
void mostrarSoloPelisActivas(nodoListaPelicula * listaP);

nodoListaPelicula * inicLista();
nodoListaPelicula * crearNodo(stPelicula nuevo);
nodoListaPelicula * cargarNodosPpio(nodoListaPelicula* listaP);
nodoListaPelicula * cargarNodosFinal(nodoListaPelicula* listaP);
nodoListaPelicula * insertarPeliPpio(nodoListaPelicula * listaP, nodoListaPelicula * nuevoNodo);
nodoListaPelicula * insertarPeliOrden(nodoListaPelicula * listaP, nodoListaPelicula * nuevoNodo);
nodoListaPelicula * insertarPeliFinal(nodoListaPelicula * listaP, nodoListaPelicula * nuevoNodo);
nodoListaPelicula * buscarUltimo(nodoListaPelicula * listaP);
nodoListaPelicula * buscarPeliID(int idPelicula,nodoListaPelicula * listaP);
nodoListaPelicula * archivoAListaPelis(char archivo[], nodoListaPelicula * listaP);
nodoListaPelicula * archivoAListaPelisR(FILE * archi, nodoListaPelicula * listaP);
void listaPelisAArchivo(nodoListaPelicula *listaP);

#endif // LISTAPELICULAS_H_INCLUDED
