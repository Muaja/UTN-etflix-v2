#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Estructuras.h"
#ifndef LISTAPELICULAS_H_INCLUDED
#define LISTAPELICULAS_H_INCLUDED

nodoListaPelicula *inicLista();

stPelicula altaPelicula(nodoListaPelicula * listaP);
nodoListaPelicula * crearNodo (stPelicula nuevo);

nodoListaPelicula *agregarPeliPpio(nodoListaPelicula * listaP, nodoListaPelicula * nuevoNodo);
nodoListaPelicula * cargarNodosPpio (nodoListaPelicula* listaP);

nodoListaPelicula * cargarNodosFinalPpio (nodoListaPelicula* listaP);
nodoListaPelicula * agregarPeliFinal(nodoListaPelicula * listaP, nodoListaPelicula * nuevoNodo);

nodoListaPelicula * buscarUltimo(nodoListaPelicula * listaP);

nodoListaPelicula * insertarPeliOrden(nodoListaPelicula * listaP, nodoListaPelicula * nuevoNodo);

nodoListaPelicula * insertarPeliOrden(nodoListaPelicula * listaP, nodoListaPelicula * nuevoNodo);

int existePelicula(nodoListaPelicula * listaP, char nombre[]);
int eliminarPelicula(nodoListaPelicula * listaP, int idPelicula);
int cantidadPeliculas(nodoListaPelicula * listaP);
nodoListaPelicula * buscarPeliID(int idPelicula,nodoListaPelicula * listaP);

void mostrarUnaPelicula(stPelicula pelicula);
void mostrarTodasLasPelis(nodoListaPelicula * listaP);
void mostrarSoloPelisActivas(nodoListaPelicula * listaP);

nodoListaPelicula * archivoAListaOrdenado(nodoListaPelicula * listaP,FILE* archi);
nodoListaPelicula * archivoALista(nodoListaPelicula * listaP);

#endif // LISTAPELICULAS_H_INCLUDED
