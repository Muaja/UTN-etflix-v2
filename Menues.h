#ifndef MENUES_H_INCLUDED
#define MENUES_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Estructuras.h"
#include "ADLusuarios.h"
#include "listaPeliculas.h"
#include "ArbolPeliculas.h"

void encabezado(char titulo[], char acceso[]);
void menuInicio();
void menuPrincipal();
void menuCalificar(int idPelicula);
void mirandoPelicula(int idPelicula);
void peliculasRecomendadas(int idUsuario);
void reproductor();
void menuListarPeliculas(int dim, int acceso);
void menuBuscarPelicula(int dim, int acceso);
void menuListarUsuarios(int dim, int acceso);
void menuBuscarUsuario(int dim, int acceso);
void menuAdministracion();
void menuAdministrarUsuarios();
void menuAdministrarPeliculas();
void salir();
void menuArbolPeliculas();
void menuMostrarArbol();

#endif
