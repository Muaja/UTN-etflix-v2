#include "ArbolPeliculas.h"

nodoArbolPelicula * inicArbol()
{
    return NULL;
}

nodoArbolPelicula * crearNodoArbolPelicula(stPelicula pelicula)
{
    nodoArbolPelicula * aux = (nodoArbolPelicula *) malloc(sizeof(nodoArbolPelicula));
    aux->p = pelicula;
    aux->der=NULL;
    aux->izq=NULL;
    return aux;
}

nodoArbolPelicula * insertarNodoArbol(nodoArbolPelicula * arbol, nodoArbolPelicula * nuevo)
{
    if(!arbol)
    {
        arbol = nuevo;
    }
    else
    {
        if(nuevo->p.idPelicula>arbol->p.idPelicula) arbol->der = insertarNodoArbol(arbol->der, nuevo);
        else arbol->izq = insertarNodoArbol(arbol->izq, nuevo);
    }
    return arbol;
}

stPelicula cargaPelicula()
{
    stPelicula aux;

    printf("\nIngrese el nombre de la nueva pelicula:\n");
    fflush(stdin);
    gets(aux.nombrePelicula);
    while(!strlen(aux.nombrePelicula))
    {
        printf("\nIngrese el nombre de la nueva pelicula (Error: El campo pelicula no puede estar vacio):\n");
        fflush(stdin);
        gets(aux.nombrePelicula);
    }
    while(buscarNombre(arbolP,aux.nombrePelicula))
    {
        printf("\nIngrese el nombre de la nueva pelicula (Error: La pelicula ya existe):\n");
        fflush(stdin);
        gets(aux.nombrePelicula);
    }

    printf("\nIngrese el nombre del director:\n");
    fflush(stdin);
    gets(aux.director);

    printf("\nIngrese el genero de la pelicula:\n");
    fflush(stdin);
    gets(aux.genero);

    printf("\nIngrese el pais de la pelicula:\n");
    fflush(stdin);
    gets(aux.pais);

    printf("\nIngrese el anio en que se grabo la pelicula:\n");
    fflush(stdin);
    scanf("%i", &aux.anio);

    printf("\nIngrese la valoracion inicial de la pelicula:\n");
    fflush(stdin);
    scanf("%i", &aux.valoracion);

    //(0- si es ATP / 13: mayor de trece / 16: mayor de 16 / 18: mayor de 18;
    printf("\nIngrese la clasificacion por edad de la pelicula:\n(0- ATP / 13- mayor de 13 / 16- mayor de 16 / 18- mayor de 18):\n");
    fflush(stdin);
    scanf("%i", &aux.pm);
    while(aux.pm != 0 && aux.pm != 13 && aux.pm != 16 && aux.pm != 18)
    {
        printf("\nIngrese la clasificacion por edad de la pelicula\n(0- si es ATP / 13: mayor de trece / 16: mayor de 16 / 18: mayor de 18):\n");
        fflush(stdin);
        scanf("%i", &aux.pm);
    }

    printf("\nIngrese la URL de la pelicula: ");
    fflush(stdin);
    gets(aux.url);
    while(!strlen(aux.url))
    {
        printf("\nIngrese la URL de la pelicula (Error: El campo URL no puede estar vacio): ");
        fflush(stdin);
        gets(aux.url);
    }

    aux.eliminado = 0;
    aux.idPelicula = nodosArbol(arbolP)+1;
    return aux;
}

void altaPelicula()
{
    stPelicula aux = cargaPelicula();
    nodoArbolPelicula * nuevo = crearNodoArbolPelicula(aux);
    arbolP = insertarNodoArbol(arbolP,nuevo);
    arbolPelisAArchivo(ARCHIVO_PELICULAS,arbolP);

    printf("\nLa pelicula se guardo correctamente.\n\n");
    system("pause");
}

void modificarPelicula(int idPelicula)
{
    nodoArbolPelicula * aux = buscarPelicula(arbolP,idPelicula);

    int opcion = 0;

    encabezado("MODIFICAR PELICULA","ADMINISTRADOR");
    printf("\n1-Nombre de la pelicula: [%s]", aux->p.nombrePelicula);
    printf("\n2-Nombre del director: [%s]", aux->p.director);
    printf("\n3-Genero: [%s]", aux->p.genero);
    printf("\n4-Pais: [%s]", aux->p.pais);
    printf("\n5-Anio: [%i]", aux->p.anio);
    printf("\n6-Valoracion total: [%i]", aux->p.valoracion);
    printf("\n7-Clasificacion: [%i]", aux->p.pm);
    printf("\n8-URL: [%s]", aux->p.url);

    printf("\n\n0-Volver atras");
    printf("\n\nEsperando opcion: ");
    scanf("%i", &opcion);

    if(opcion == 0)
    {
        menuAdministrarPeliculas();
    }
    else
    {
        switch(opcion)
        {
            case 1:
            {
                char nombre[60]; //Variable local para comprobar nombre
                printf("\nIngrese el nombre de la pelicula: ");
                fflush(stdin);
                gets(nombre);
                while(buscarNombre(arbolP,nombre))
                {
                    printf("\nIngrese el nombre de la pelicula (Error: La pelicula ya existe): ");
                    fflush(stdin);
                    gets(nombre);
                }
                strcpy(aux->p.nombrePelicula, nombre);
                break;
            }
            case 2:
            {
                printf("\nIngrese el nombre del director: ");
                fflush(stdin);
                gets(aux->p.director);
                break;
            }
            case 3:
            {
                printf("\nIngrese el genero de la pelicula: ");
                fflush(stdin);
                gets(aux->p.genero);
                break;
            }
            case 4:
            {
                printf("\nIngrese el pais de la pelicula: ");
                fflush(stdin);
                gets(aux->p.pais);
                break;
            }
            case 5:
            {
                printf("\nIngrese el anio en que se grabo la pelicula: ");
                fflush(stdin);
                scanf("%i", &aux->p.anio);
                break;
            }
            case 6:
            {
                printf("\nIngrese la valoracion inicial de la pelicula: ");
                fflush(stdin);
                scanf("%i", &aux->p.valoracion);
                break;
            }
            case 7:
            {
                //(0- si es ATP / 13: mayor de trece / 16: mayor de 16 / 18: mayor de 18;
                printf("\nIngrese la clasificacion por edad de la pelicula\n(0- si es ATP / 13: mayor de trece / 16: mayor de 16 / 18: mayor de 18): ");
                fflush(stdin);
                scanf("%i", &aux->p.pm);
                while(aux->p.pm != 0 && aux->p.pm != 13 && aux->p.pm != 16 && aux->p.pm != 18)
                {
                    printf("\nIngrese la clasificacion por edad de la pelicula\n(0- si es ATP / 13: mayor de trece / 16: mayor de 16 / 18: mayor de 18): ");
                    fflush(stdin);
                    scanf("%i", &aux->p.pm);
                }
                break;
            }
            case 8:
            {
                printf("\nIngrese la URL de la película:\n");
                fflush(stdin);
                gets(aux->p.url);
                while(!strlen(aux->p.url))
                {
                    printf("\nIngrese la URL de la película (Error: El campo URL no puede estar vacio):\n");
                    fflush(stdin);
                    gets(aux->p.url);
                }
                break;
            }

        }

        printf("\nSe guardo la modificacion realizada.\n\n");
        system("pause");
        modificarPelicula(idPelicula);
    }
}

/* Funcion mostrarArregloPeliculas(): recibe por parametro un arreglo de peliculas y su dimension. Recorre el arreglo y muestra las peliculas de forma organizada.
void mostrarArregloPeliculas(stPelicula peliculas[], int dim)

Parametros:
stPelicula peliculas[] - arreglo de peliculas conteniendo la informacion que deseamos mostrar.
int dim - dimension del arreglo de peliculas. */
void mostrarArregloPeliculas(stPelicula peliculas[], int i, int validos)
{
    if(i < validos) printf("\nID\tPelicula\t\tDirector\tGenero\t\tAnio\tPais\tPM\tValoracion\n");
    while(i < validos)
    {
        printf("%i\t%s\t\t%s\t\t%s\t\t%i\t%s\t%i\t%d\n",peliculas[i].idPelicula,peliculas[i].nombrePelicula,peliculas[i].director,peliculas[i].genero,peliculas[i].anio,peliculas[i].pais,peliculas[i].pm,peliculas[i].valoracion);
        i++;
    }
    printf("\n\n");
}

int arbolAArreglo(int tipo, nodoArbolPelicula * arbol, stPelicula peliculas[], int i, int dim, char filtro[], int filtro2)
{
    if(arbol && i < dim)
    {
        i = arbolAArreglo(tipo,arbol->izq,peliculas,i,dim,filtro,filtro2);
        int flag = 0;
        switch(tipo)
        {
            case 0:
            {
                flag = 1;
            } break;
            case 1:
            {
                if(strstr(arbol->p.nombrePelicula,filtro) != NULL) flag = 1;
            } break;
            case 2:
            {
                if(strstr(arbol->p.genero,filtro) != NULL) flag = 1;
            } break;
            case 3:
            {
                if(strstr(arbol->p.pais,filtro) != NULL) flag = 1;
            } break;
            case 4:
            {
                if(arbol->p.valoracion == filtro2) flag = 1;
            } break;
            case 5:
            {
                if(arbol->p.anio == filtro2) flag = 1;
            } break;
            case 6:
            {
                if(arbol->p.pm == filtro2) flag = 1;
            } break;
        }
        if(flag)
        {
            peliculas[i] = arbol->p;
            i++;
        }
        i = arbolAArreglo(tipo,arbol->der,peliculas,i,dim,filtro,filtro2);
    }
    return i;
}

/* Funcion consulta peliculas: busca en el archivo las peliculas que coinciden con los parametros establecidos, modifica arreglo peliculas
con las peliculas encontradas.
int consultaPeliculas(int tipo, char filtro, int filtro2, int peliculas[], int dim)

Parametros:
int tipo - tipo de busqueda que queremos.
char filtro - primer filtro, utilizado para las busquedas por titulo, genero y pais.
int filtro2 - segundo filtro, utilizado para las bussquedas por valoracion, anio y clasificacion.
stPelicula peliculas[] - arreglo de peliculas donde se guardan las id de las peliculas encontradas.
int dim - dimension que establece la cantidad de peliculas que podremos buscar.

switch(tipo de busqueda):
    0-sin filtro
    1-por titulo.
    2-por genero.
    3-por pais
    4-por valoracion.
    5-por anio.
    6-por clasificacion para mayores PM.

Retorna:
>0 - La cantidad de peliculas encontradas que coinciden con la busqueda.
0 - Si no se encontraron peliculas o no pudo ser abierto el archivo. */
int consultaPeliculas(int tipo, char filtro[], int filtro2, stPelicula peliculas[], int dim)
{
    int i = 0;
    if(arbolP != NULL)
    {
        i = arbolAArreglo(tipo,arbolP,peliculas,i,dim,filtro,filtro2);
    }
    return i;
}

/* Funcion listar peliculas: recibe el tipo de lista, el arreglo de peliculas y su dimension por parametro. Lista las peliculas de la forma seleccionada y
los guarda en el arreglo de peliculas hasta completarlo.

int listarPeliculas(int tipo, stPelicula peliculas[], int dim, int lleno)

Parametros:
int tipo - tipo de lista que queremos
stPelicula peliculas[] - arreglo donde se cargan y se ordenan los registros
int dim - tamaño del arreglo
int lleno - indica si el arreglo ya tiene datos

switch(tipo):
    0-sin filtro
    1-por titulo. (ordenado por seleccion)
    2-por genero. (ordenado por insercion)
    3-por pais
    4-por valoracion.
    5-por anio.
    6-por clasificacion para mayores PM.
*/
int listarPeliculas(int tipo, stPelicula peliculas[], int validos, int dim, int lleno)
{
    int i = 0;
    if(!lleno) i = arbolAArreglo(0,arbolP,peliculas,0,dim,"",0);
    else i = validos;
    switch(tipo)
    {
        case 1:
        {
            ordenaArregloPeliculasSeleccionTitulo(peliculas,dim);
        } break;
        case 2:
        {
            ordenaArregloPeliculasInsercionGenero(peliculas,dim);
        } break;
        case 3:
        {
            ordenaArregloPeliculasSeleccionPais(peliculas,dim);
        } break;
        case 4:
        {
            ordenaArregloPeliculasSeleccionValoracion(peliculas,dim);
        } break;
        case 5:
        {
            ordenaArregloPeliculasSeleccionAnio(peliculas,dim);
        } break;
        case 6:
        {
            ordenaArregloPeliculasSeleccionClasificacion(peliculas,dim);
        } break;
    }
    return i;
}

int posMenorTituloPeliculas(stPelicula peliculas[], int pos, int cant)
{

    int i = pos+1;
    int posMenor = pos;
    char menor[30];
    strcpy(menor, peliculas[pos].nombrePelicula);

    while(i < cant)
    {
        if(strcmp(menor, peliculas[i].nombrePelicula) > 0)
        {
            strcpy(menor, peliculas[i].nombrePelicula);
            posMenor = i;
        }
        i++;
    }
    return posMenor;
}

void ordenaArregloPeliculasSeleccionTitulo(stPelicula peliculas[], int cant)
{
    int i = 0;
    int menor;
    stPelicula aux;

    while(i < cant)
    {
        menor = posMenorTituloPeliculas(peliculas, i, cant);
        aux = peliculas[menor];
        peliculas[menor] = peliculas[i];
        peliculas[i] = aux;
        i++;
    }
}

int insertaPeliculaOrdenadoGenero(stPelicula peliculas[], int cant, stPelicula aux)
{
    int j = cant-1; // j es el subindice anterior
    while(j >= 0 && strcmp(peliculas[j].genero,aux.genero) > 0) // corro los elementos para liberar el espacio necesario
    {
        peliculas[j+1] = peliculas[j];
        j--;
    }
    peliculas[j+1] = aux; // inserto el elemento en el lugar indicado
    return cant+1;
}

void ordenaArregloPeliculasInsercionGenero(stPelicula peliculas[], int cant)
{
    int i;
    stPelicula aux;
    for(i = 1; i < cant; i++) //empiezo por el segundo elemento hasta el final
    {
        aux = peliculas[i]; // guardo el elemento en aux
        insertaPeliculaOrdenadoGenero(peliculas, i, aux);
    }
}

int posMenorPaisPeliculas(stPelicula peliculas[], int pos, int cant)
{

    int i = pos+1;
    int posMenor = pos;
    char menor[30];
    strcpy(menor, peliculas[pos].pais);

    while(i < cant)
    {
        if(strcmp(menor, peliculas[i].pais) > 0)
        {
            strcpy(menor, peliculas[i].pais);
            posMenor = i;
        }
        i++;
    }
    return posMenor;
}

void ordenaArregloPeliculasSeleccionPais(stPelicula peliculas[], int cant)
{
    int i = 0;
    int menor;
    stPelicula aux;

    while(i < cant)
    {
        menor = posMenorPaisPeliculas(peliculas, i, cant);
        aux = peliculas[menor];
        peliculas[menor] = peliculas[i];
        peliculas[i] = aux;
        i++;
    }
}

int posMayorValoracionPeliculas(stPelicula peliculas[], int pos, int cant)
{

    int i = pos+1;
    int posMayor = pos;
	int mayor = peliculas[pos].valoracion;

    while(i < cant)
    {
        if(mayor < peliculas[i].valoracion)
        {
            mayor = peliculas[i].valoracion;
            posMayor = i;
        }
        i++;
    }
    return posMayor;
}

void ordenaArregloPeliculasSeleccionValoracion(stPelicula peliculas[], int cant)
{
    int i = 0;
    int mayor;
    stPelicula aux;

    while(i < cant)
    {
        mayor = posMayorValoracionPeliculas(peliculas, i, cant);
        aux = peliculas[mayor];
        peliculas[mayor] = peliculas[i];
        peliculas[i] = aux;
        i++;
    }
}

int posMenorAnioPeliculas(stPelicula peliculas[], int pos, int cant)
{

    int i = pos+1;
    int posMenor = pos;
	int menor = peliculas[pos].anio;

    while(i < cant)
    {
        if(menor > peliculas[i].anio)
        {
            menor = peliculas[i].anio;
            posMenor = i;
        }
        i++;
    }
    return posMenor;
}

void ordenaArregloPeliculasSeleccionAnio(stPelicula peliculas[], int cant)
{
    int i = 0;
    int menor;
    stPelicula aux;

    while(i < cant)
    {
        menor = posMenorAnioPeliculas(peliculas, i, cant);
        aux = peliculas[menor];
        peliculas[menor] = peliculas[i];
        peliculas[i] = aux;
        i++;
    }
}

int posMenorClasificacionPeliculas(stPelicula peliculas[], int pos, int cant)
{

    int i = pos+1;
    int posMenor = pos;
	int menor = peliculas[pos].pm;

    while(i < cant)
    {
        if(menor > peliculas[i].pm)
        {
            menor = peliculas[i].pm;
            posMenor = i;
        }
        i++;
    }
    return posMenor;
}

void ordenaArregloPeliculasSeleccionClasificacion(stPelicula peliculas[], int cant)
{
    int i = 0;
    int menor;
    stPelicula aux;

    while(i < cant)
    {
        menor = posMenorClasificacionPeliculas(peliculas, i, cant);
        aux = peliculas[menor];
        peliculas[menor] = peliculas[i];
        peliculas[i] = aux;
        i++;
    }
}

void MostrarArbol(nodoArbolPelicula * arbol, int opcion)
{
    switch(opcion)
    {
        case 1: MostrarArbolPreorder(arbol);
        case 2: MostrarArbolInorder(arbol);
        case 3: MostrarArbolPostorder(arbol);
        case 4: MostrarArbol2D(arbol,0);
    }
    printf("\n\n");
}

void MostrarArbolPreorder(nodoArbolPelicula * arbol)
{
    if(arbol)
    {
        printf("\n%d-%s", arbol->p.idPelicula, arbol->p.nombrePelicula);
        MostrarArbolPreorder(arbol->izq);
        MostrarArbolPreorder(arbol->der);
    }

}

void MostrarArbolInorder(nodoArbolPelicula * arbol)
{
    if(arbol)
    {
        MostrarArbolInorder(arbol->izq);
        printf("\n%d-%s", arbol->p.idPelicula, arbol->p.nombrePelicula);
        MostrarArbolInorder(arbol->der);
    }
}

void MostrarArbolPostorder(nodoArbolPelicula * arbol)
{
    if(arbol)
    {
        MostrarArbolPostorder(arbol->izq);
        MostrarArbolPostorder(arbol->der);
        printf("\n%d-%s", arbol->p.idPelicula, arbol->p.nombrePelicula);
    }
}

void MostrarArbol2D(nodoArbolPelicula * arbol, int espacio)
{
    if(arbol == NULL)
        return;

    espacio += 10;
    MostrarArbol2D(arbol->der, espacio);

    printf("\n");
    for (int i = 10; i < espacio; i++)
        printf(" ");
    printf("%d\n", arbol->p.idPelicula);

    MostrarArbol2D(arbol->izq, espacio);
}

nodoArbolPelicula * buscarPelicula(nodoArbolPelicula * arbol, int idPelicula)
{
    nodoArbolPelicula * rta = NULL;
    if(arbol)
    {
        if(idPelicula == arbol->p.idPelicula)
        {
            rta = arbol;
        }
        else if(idPelicula > arbol->p.idPelicula)
        {
            rta = buscarPelicula(arbol->der, idPelicula);
        }
        else
        {
            rta = buscarPelicula(arbol->izq, idPelicula);
        }
    }
    return rta;
}

nodoArbolPelicula * buscarNombre(nodoArbolPelicula * arbol, char nombre[])
{
    nodoArbolPelicula * rta=NULL;
    if(arbol)
    {
        if(strcmp(nombre,arbol->p.nombrePelicula) == 0)
        {
            rta = arbol;
        }
        else
        {
            rta = buscarNombre(arbol->izq, nombre);
            if(!rta) rta = buscarNombre(arbol->der, nombre);
        }
    }
    return rta;
}

int nodosArbol(nodoArbolPelicula * arbol)
{
    int rta = 0;
    if(arbol) rta = 1 + nodosArbol(arbol->izq) + nodosArbol(arbol->der);
    return rta;
}

int hojaArbol(nodoArbolPelicula * arbol)
{
    return (!(arbol->der) && !(arbol->izq));
}

int hojasArbol(nodoArbolPelicula * arbol)
{
    int rta = 0;
    if(arbol)
    {
        if(hojaArbol(arbol)) rta = 1 + hojasArbol(arbol->izq) + hojasArbol(arbol->der);
        else rta = hojasArbol(arbol->izq) + hojasArbol(arbol->der);
    }
    return rta;
}

int alturaArbol(nodoArbolPelicula * arbol)
{
    int rta = 0;
    if(arbol)
    {
        int izq = alturaArbol(arbol->izq);
        int der = alturaArbol(arbol->der);
        if(izq > der) rta = 1 + izq;
        else rta = 1 + der;
    }
    return rta;
}

int eliminarPelicula(nodoArbolPelicula * arbol, int idPelicula)
{
    int rta = 0;
    if(arbol)
    {
        if(idPelicula == arbol->p.idPelicula)
        {
            arbol->p.eliminado = 1;
            rta = 1;
        }
        else if(idPelicula > arbol->p.idPelicula)
        {
            rta = eliminarPelicula(arbol->der, idPelicula);
        }
        else
        {
            rta = eliminarPelicula(arbol->izq, idPelicula);
        }
    }
    return rta;
}

nodoArbolPelicula * borrarNodoArbol(nodoArbolPelicula * arbol, int idPelicula)
{
    if(arbol)
    {
        if(idPelicula == arbol->p.idPelicula)
        {
            if(arbol->izq != NULL)
            {
                nodoArbolPelicula * nmd = NMD(arbol->izq);
                arbol->p = nmd->p;
                arbol->izq = borrarNodoArbol(arbol->izq, nmd->p.idPelicula);
            }
            else if(arbol->der != NULL)
            {
                nodoArbolPelicula * nmi = NMI(arbol->der);
                arbol->p = nmi->p;
                arbol->der = borrarNodoArbol(arbol->der,nmi->p.idPelicula);
            }
            else
            {
                free(arbol);
                arbol = NULL;
            }
        }
        else if(idPelicula>arbol->p.idPelicula)
        {
            arbol->der = borrarNodoArbol(arbol->der, idPelicula);
        }
        else
        {
            arbol->izq = borrarNodoArbol(arbol->izq, idPelicula);
        }
    }
    return arbol;
}

nodoArbolPelicula * borrarArbol(nodoArbolPelicula * arbol)
{
    int cant = nodosArbol(arbol);
    for(int i = 0; i < cant+1; i++)
    {
        arbol = borrarNodoArbol(arbol,i);
    }
    return arbol;
}

nodoArbolPelicula * NMI(nodoArbolPelicula * arbol)
{
    nodoArbolPelicula * rta = NULL;
    if(arbol)
    {
        if(arbol->izq) rta = NMI(arbol->izq);
        else rta = arbol;
    }
    return rta;
}

nodoArbolPelicula * NMD(nodoArbolPelicula * arbol)
{
    nodoArbolPelicula * rta = NULL;
    if(arbol)
    {
        if(arbol->der) rta = NMD(arbol->der);
        else rta = arbol;
    }
    return rta;
}

void calificarPelicula(int idPelicula, int calificacion)
{
    nodoArbolPelicula * buscado = buscarPelicula(arbolP, idPelicula);
    if(buscado)
    {
        buscado->p.valoracion += calificacion;
        buscado->p.reproducciones++;
    }
}

float calificacionPelicula(int valoracion, int reproducciones)
{
    float calificacion = 0.0;
    if(!reproducciones) calificacion = (float)valoracion/reproducciones;
    return calificacion;
}

nodoArbolPelicula * archivoAArbolPelis(const char archivo[], nodoArbolPelicula * arbol, int balanceado)
{
    FILE *archi;
    archi = fopen(archivo,"rb");
    if(archi != NULL)
    {
        stPelicula aux;
        while(fread(&aux, sizeof(stPelicula), 1, archi) > 0 && !(aux.eliminado)) //recorro el archivo de peliculas
        {
            nodoArbolPelicula * nuevo = crearNodoArbolPelicula(aux);
            if(balanceado) arbol = insertarNodoArbolBalanceado(arbol,nuevo);
            else arbol = insertarNodoArbol(arbol,nuevo);

        }
        fclose(archi);
    }
    return arbol;
}

void arbolPelisAArchivo(const char archivo[], nodoArbolPelicula * arbol)
{
    FILE *archi;
    archi = fopen(archivo,"wb");
    if(archi!=NULL)
    {
        arbolPelisAArchivoR(archi, arbolP);
        fclose(archi);
    }
}

void arbolPelisAArchivoR(FILE* archi, nodoArbolPelicula * arbol)
{
    if(arbol)
    {
        arbolPelisAArchivoR(archi, arbol->izq);
        fwrite(&arbol->p,sizeof(stPelicula),1,archi);
        arbolPelisAArchivoR(archi, arbol->der);
    }
}

nodoArbolPelicula * insertarNodoArbolBalanceado(nodoArbolPelicula * arbol, nodoArbolPelicula * nuevo)
{
    if(!arbol)
    {
        arbol = nuevo;
    }
    else
    {
        if(arbol->p.idPelicula < nuevo->p.idPelicula)
        {
            arbol->der = insertarNodoArbolBalanceado(arbol->der ,nuevo);
        }
        else
        {
            arbol->izq = insertarNodoArbolBalanceado(arbol -> izq , nuevo);
        }
        arbol = balancearArbol(arbol);
    }
    return arbol;
}

nodoArbolPelicula * rotarIzq(nodoArbolPelicula * arbol)
{
    nodoArbolPelicula * pivot = arbol->der;
    if(arbol->der)
    {
        arbol->der = pivot->izq;
        pivot->izq = arbol;
    }
    return pivot;
}

nodoArbolPelicula * rotarDer(nodoArbolPelicula * arbol)
{
    nodoArbolPelicula * pivot = arbol;
    if(arbol->izq)
    {
        nodoArbolPelicula * pivot = arbol->izq;
        arbol->izq = pivot->der;
        pivot->der = arbol;
    }
    return pivot;
}

nodoArbolPelicula * balancearArbol(nodoArbolPelicula * arbol)
{
    if(arbol)
    {
        int alturaizq = alturaArbol(arbol->izq);
        int alturader = alturaArbol(arbol->der);
        if(fabs(alturaizq-alturader) > 1)
        {
            if(alturaizq > alturader) arbol = rotarDer(arbol);
            else arbol = rotarIzq(arbol);
            arbol = balancearArbol(arbol);
        }
    }
    return arbol;
}
