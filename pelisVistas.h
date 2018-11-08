#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listaPeliculas.h"
#include "ADLusuarios.h"
#include "Estructuras.h"
#ifndef PELISVISTAS_H_INCLUDED
#define PELISVISTAS_H_INCLUDED



void pasarArchivoPelisVistaToADL(stPelisVistas pelisVistas[], int val, nodoListaPelicula * listaP, stCelda user[],int cantUser);
int cargarADLpelisVistas(stPelisVistas pelisVistas[], int val, stPelisVistas datos, nodoListaPelicula * listaP, stCelda user[],int cantUser);
void pasarPeliListaToListaUser(int idPelicula,int idUser, nodoListaPelicula * listaP, stCelda user[],int cantUser);
stPelisVistas verPelicula(int idPelicula,int idUser,int validosPelisVistas);
void pasarPelisVistasTOarchivo(stPelisVistas pelisVistas[], int val);


#endif // PELISVISTAS_H_INCLUDED
