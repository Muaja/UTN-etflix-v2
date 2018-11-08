#ifndef ADLUSUARIOS_H_INCLUDED
#define ADLUSUARIOS_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Estructuras.h"
#include "Menues.h"

/* Funciones usuarios */
int agregarPeliculaToUsuario(stCelda usuarios[],int val, int idUsuario, int idPelicula );
void limpiarArregloDeListas(stCelda usuarios[], int val);
void persistirPeliculasVistas(stCelda usuarios[], int val, char archivo[]);

stCelda * dimensionarUsuarios(stCelda usuarios[], int cant);
stCelda * redimensionarUsuarios(stCelda usuarios[], int cant);
void archivoUsuariosToADL(const char archivo[]);
void ADLToArchivoUsuarios(const char archivo[]);
int cantidadUsuarios(const char archivo[]);
int existeUsuario(char nombreUsuario[], stCelda * usuarios, int val);
int agregarUsuario();
int eliminarUsuario(int idUsuario, stCelda usuarios[], int val);
int buscarUsuario(stCelda usuarios[], int val, int idUsuario);
int esAdministrador(int idUsuario, stCelda usuarios[], int val);
int modificarUsuario(int idUsuario, int acceso, stCelda usuarios[], int val);
int loginUsuario(stCelda usuarios[], int val);

int consultaUsuarios(int tipo, char filtro[], int filtro2, stUsuario muestra[], int dim, stCelda usuarios[], int val);
void listarUsuarios(int tipo, stUsuario muestra[], int dim, stCelda usuarios[], int val);
int posMenorNombreUsuarios(stUsuario muestra[], int pos, int cant);
void ordenaArregloUsuariosSeleccionNombre(stUsuario muestra[], int cant);
int posMenorAnioUsuarios(stUsuario muestra[], int pos, int cant);
void ordenaArregloUsuariosSeleccionAnio(stUsuario muestra[], int cant);
int posMenorPaisUsuarios(stUsuario muestra[], int pos, int cant);
void ordenaArregloUsuariosSeleccionPais(stUsuario muestra[], int cant);
void mostrarUsuarios(stUsuario muestra[], int val);

/* Funciones password */
int determinante2x2(int fila, int columna, const int matriz[][columna]);
void calcularadjunta2x2(int fila, int columna, const int matriz[][columna], float matrizinv[][columna]);
void calcularInversa2x2(int fila, int columna, const int matriz[][columna], float matrizinv[][columna]);
void calculartransversa2x2flotante(int fila, int columna, float matriz[][columna]);

void encriptarPass(char pass[], int password[2][5]);
void desencriptarPass(char pass[], int password[2][5]);
void passwordAMatriz(char pass[], int matriz[2][5]);
void matrizAPassword(char pass[], int matriz[2][5]);
void encriptarMatriz(int matrizpassword[2][5], int password[2][5]);
void desencriptarMatriz(int matrizencriptada[2][5], float matrizinversa[2][2], int password[2][5]);

#endif // ADLUSUARIOS_H_INCLUDED
