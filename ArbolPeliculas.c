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
    printf("\n6-Valoracion inicial: [%i]", aux->p.valoracion);
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
                printf("\nIngrese el nombre de la pelicula: ");
                fflush(stdin);
                gets(aux->p.nombrePelicula);
                while(buscarNombre(arbolP,aux->p.nombrePelicula))
                {
                    printf("\nIngrese el nombre de la pelicula (Error: La pelicula ya existe): ");
                    fflush(stdin);
                    gets(aux->p.nombrePelicula);
                }
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
                gets(&aux->p.url);
                while(!strlen(&aux->p.url))
                {
                    printf("\nIngrese la URL de la película (Error: El campo URL no puede estar vacio):\n");
                    fflush(stdin);
                    gets(&aux->p.url);
                }
                break;
            }

        }

        printf("\nSe guardo la modificacion realizada.\n\n");
        system("pause");
        modificarPelicula(idPelicula);
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
}

void MostrarArbolPreorder(nodoArbolPelicula * arbol)
{
    if(arbol)
    {
        printf("\n%d  %s", arbol->p.idPelicula, arbol->p.nombrePelicula);
        MostrarArbolPreorder(arbol->izq);
        MostrarArbolPreorder(arbol->der);
    }

}

void MostrarArbolInorder(nodoArbolPelicula * arbol)
{
    if(arbol)
    {
        MostrarArbolInorder(arbol->izq);
        printf("\n%d  %s", arbol->p.idPelicula, arbol->p.nombrePelicula);
        MostrarArbolInorder(arbol->der);
    }
}

void MostrarArbolPostorder(nodoArbolPelicula * arbol)
{
    if(arbol)
    {
        MostrarArbolPostorder(arbol->izq);
        MostrarArbolPostorder(arbol->der);
        printf("\n%d  %s", arbol->p.idPelicula, arbol->p.nombrePelicula);
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

void eliminarPelicula(nodoArbolPelicula * arbol, int idPelicula)
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
            rta = buscarPelicula(arbol->der, idPelicula);
        }
        else
        {
            rta = buscarPelicula(arbol->izq, idPelicula);
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
    if(arbol)
    {
        arbol = borrarArbol(arbol->izq);
        arbol = borrarArbol(arbol->der);
        free(arbol);
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

nodoArbolPelicula * archivoAArbolPelis(const char archivo[], nodoArbolPelicula * arbol)
{
    FILE *archi;
    archi = fopen(archivo,"rb");
    if(archi != NULL)
    {
        stPelicula aux;
        while(fread(&aux, sizeof(stPelicula), 1, archi) > 0 && !(aux.eliminado)) //recorro el archivo de peliculas
        {
            nodoArbolPelicula * nuevo = crearNodoArbolPelicula(aux);
            arbol = insertarNodoArbol(arbol,nuevo);
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

int arbolBalanceado(nodoArbolPelicula * arbol)
{
    int rta = 1;
    if(arbol && !hojaArbol(arbol))
    {
        int alturaizq = alturaArbol(arbol->izq);
        int alturader = alturaArbol(arbol->der);
        if(alturaizq-alturader > 1 || alturaizq-alturader < -1)
        {
            rta = 0;
        }
        else
        {
            rta = arbolBalanceado(arbol);
        }
    }
    return rta;
}


