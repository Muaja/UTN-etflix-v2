#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Estructuras.h"
#include "Menues.h"
#include "ADLusuarios.h"
#include "listaPeliculas.h"
#include "ArbolPeliculas.h"
#include "ADLusuarios.h"

void preCarga();
void preCargaUsuarios();
void preCargaPeliculas();
void preCargaPelisVistas();

int main()
{
    preCarga();
    menuInicio();
    return 0;
}

void preCarga()
{
    preCargaUsuarios();
    preCargaPeliculas();
    preCargaPelisVistas();
}

void preCargaUsuarios()
{
    archivoUsuariosToADL(ARCHIVO_USUARIOS);
}

void preCargaPeliculas()
{
    listaP = inicLista();
    arbolP = inicArbol();
    listaP = archivoAListaPelis(ARCHIVO_PELICULAS, listaP, 2);

    arbolP = archivoAArbolPelis(ARCHIVO_PELICULAS, arbolP);
    arbolP = balancearArbolPelis(arbolP);
}

void preCargaPelisVistas()
{

}
