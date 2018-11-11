#ifndef LISTAPELICULAS_H_INCLUDED
#define LISTAPELICULAS_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Estructuras.h"
#include "Menues.h"

nodoListaPelicula * inicLista();
int cantidadPeliculas(nodoListaPelicula * listaP);
int existePelicula(nodoListaPelicula * listaP, char nombre[]);
nodoListaPelicula * crearNodoListaPelicula(stPelicula nuevo);
stPelicula cargaPelicula();
void altaPelicula();
void modificarPelicula(int idPelicula);
nodoListaPelicula * insertarPeliPpio(nodoListaPelicula * listaP, nodoListaPelicula * nuevoNodo);
nodoListaPelicula * insertarPeliOrden(nodoListaPelicula * listaP, nodoListaPelicula * nuevoNodo);
nodoListaPelicula * insertarPeliFinal(nodoListaPelicula * listaP, nodoListaPelicula * nuevoNodo);
nodoListaPelicula * buscarListaPeliID(int idPelicula,nodoListaPelicula * listaP);
nodoListaPelicula * buscarListaPeliUltimo(nodoListaPelicula * listaP);
nodoListaPelicula * borrarPelicula(nodoListaPelicula * listaP, int id);
void eliminarPelicula(nodoListaPelicula * listaP, int idPelicula);
nodoListaPelicula * borrarListaPeliculas(nodoListaPelicula * lista);
void mostrarPelicula(stPelicula pelicula);
void mostrarListaPelis(nodoListaPelicula * listaP);
void mostrarListaPelisActivas(nodoListaPelicula * listaP);

stPelicula calificarPelicula(stPelicula pelicula);

nodoListaPelicula * archivoAListaPelis(const char archivo[], nodoListaPelicula * listaP, int carga);
void listaPelisAArchivo(const char archivo[], nodoListaPelicula *listaP);

#endif // LISTAPELICULAS_H_INCLUDED
