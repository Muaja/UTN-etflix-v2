#ifndef ESTRUCTURAS_H_INCLUDED
#define ESTRUCTURAS_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Estructuras */

typedef struct
{
    int admin;
    int idUsuario;
    char nombreUsuario[15];
    char genero;
    char pais[20];
    int pass[2][5];
    int anioNacimiento;
    int eliminado;
    int administrador;
} stUsuario;

typedef struct
{
    int idPelicula;
    char nombrePelicula[60];
    char director[30];
    char genero[20];
    char pais[20];
    int anio;
    int valoracion;
    int reproducciones;
    int pm;
    char url[128];
    int eliminado;
} stPelicula;

typedef struct
{
    stPelicula p;
    struct nodoListaPelicula * sig;
} nodoListaPelicula;

typedef struct
{
    stPelicula p;
    struct nodoArbolPelicula * izq;
    struct nodoArbolPelicula * der;
} nodoArbolPelicula;

typedef struct
{
    stUsuario usr;
    nodoListaPelicula * listaPelis;
} stCelda;

typedef struct
{
    int idPeliVista;
    int idUsuario;
    int idPelicula;
} stPelisVistas;

/* Constantes */

static const char ARCHIVO_USUARIOS[] = "usuarios.dat";
static const char ARCHIVO_PELICULAS[] = "peliculas.dat";
static const char ARCHIVO_PELISVISTAS[] = "peliculasVistas.dat";
static const int MATRIZ_TESTIGO[2][2] = {{2,1},{5,3}};
static const int INTENTOS_MAXIMOS = 3;

/* Variables globales */

nodoArbolPelicula * arbolP;
stCelda * usuarios;
int val;
stPelisVistas * pelisVistas;
int valpv;
int sesion;

#endif
