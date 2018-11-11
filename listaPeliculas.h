#ifndef LISTAPELICULAS_H_INCLUDED
#define LISTAPELICULAS_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Estructuras.h"
#include "Menues.h"

nodoListaPelicula * inicLista();
int cantidadPeliculas(nodoListaPelicula * lista);
int existePelicula(nodoListaPelicula * lista, char nombre[]);
nodoListaPelicula * crearNodoListaPelicula(stPelicula nuevo);
nodoListaPelicula * insertarPeliPpio(nodoListaPelicula * lista, nodoListaPelicula * nuevoNodo);
nodoListaPelicula * insertarPeliOrden(nodoListaPelicula * lista, nodoListaPelicula * nuevoNodo);
nodoListaPelicula * insertarPeliFinal(nodoListaPelicula * lista, nodoListaPelicula * nuevoNodo);
nodoListaPelicula * buscarListaPeliID(nodoListaPelicula * lista, int idPelicula);
nodoListaPelicula * buscarListaPeliUltimo(nodoListaPelicula * lista);
nodoListaPelicula * borrarPelicula(nodoListaPelicula * lista, int id);
nodoListaPelicula * borrarListaPeliculas(nodoListaPelicula * lista);
void mostrarPelicula(stPelicula pelicula);
void mostrarListaPelis(nodoListaPelicula * lista);
void mostrarListaPelisActivas(nodoListaPelicula * lista);
stPelicula calificarPelicula(stPelicula pelicula);
void pasarArchivoPelisVistaToADL(stPelisVistas pelisVistas[], int val, nodoListaPelicula * listaP, stCelda user[],int cantUser);
int cargarADLpelisVistas(stPelisVistas pelisVistas[], int val, stPelisVistas datos, nodoListaPelicula * listaP, stCelda user[],int cantUser);
void pasarPeliListaToListaUser(int idPelicula,int idUser, nodoListaPelicula * listaP);
stPelisVistas verPelicula(int idPelicula,int idUser,int validosPelisVistas);
void pasarPelisVistasTOarchivo(stPelisVistas pelisVistas[], int val);

#endif // LISTAPELICULAS_H_INCLUDED
