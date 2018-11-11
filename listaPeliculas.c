#include "listaPeliculas.h"

nodoListaPelicula *inicLista()
{
    return NULL;
}

int cantidadPeliculas(nodoListaPelicula * listaP)
{
    int numero = 0;
    if(listaP)
    {
        numero = 1 + cantidadPeliculas(listaP->sig);
    }
    return numero;
}

int existePelicula(nodoListaPelicula * listaP, char nombre[])
{
    int flag = 0;
    if(listaP)
    {
        if(!strcmpi(listaP->p.nombrePelicula, nombre))
        {
            flag = listaP->p.idPelicula;
        }
        else
        {
            flag = existePelicula(listaP->sig,nombre);
        }
    }
    return flag;
}

nodoListaPelicula * crearNodoListaPelicula(stPelicula nuevo)
{
    nodoListaPelicula*aux = (nodoListaPelicula*)malloc(sizeof(nodoListaPelicula));
    aux->p = nuevo;
    aux->sig = NULL;
    return aux;
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
    while(existePelicula(listaP,aux.nombrePelicula))
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
    aux.idPelicula = cantidadPeliculas(listaP)+1;
    return aux;
}

void altaPelicula()
{
    stPelicula aux = cargaPelicula();

    int opcion = 0;

    encabezado("POSICION PELICULA","ADMINISTRADOR");
    printf("\n1-Principio");
    printf("\n2-Final");
    printf("\n3-En orden por nombre");

    printf("\n\n0-Volver atras");
    printf("\n\nEsperando opcion: ");
    scanf("%i", &opcion);

    if(opcion == 0)
    {
        menuAdministrarPeliculas();
    }
    else
    {
        nodoListaPelicula * nuevo = crearNodoListaPelicula(aux);

        switch(opcion)
        {
            case 1:
            {
                listaP = insertarPeliPpio(listaP,nuevo);
                break;
            }
            case 2:
            {
                listaP = insertarPeliFinal(listaP,nuevo);
                break;
            }
            case 3:
            {
                listaP = insertarPeliOrden(listaP,nuevo);
                break;
            }
        }
        listaPelisAArchivo(ARCHIVO_PELICULAS, listaP);
    }

    printf("\nLa pelicula se guardo correctamente.\n\n");
    system("pause");
}

void modificarPelicula(int idPelicula)
{
    nodoListaPelicula * aux = buscarListaPeliID(idPelicula,listaP);

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
                while(existePelicula(listaP,aux->p.nombrePelicula))
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

nodoListaPelicula * insertarPeliPpio(nodoListaPelicula * listaP, nodoListaPelicula * nuevoNodo)
{
    if(listaP==NULL)
    {
        listaP=nuevoNodo;
    }
    else
    {
        nuevoNodo->sig=listaP;
        listaP=nuevoNodo;
    }
    return listaP;
}

nodoListaPelicula * insertarPeliFinal(nodoListaPelicula * listaP, nodoListaPelicula * nuevoNodo)
{
    if(listaP==NULL)
    {
        listaP=nuevoNodo;
    }
    else
    {
        nodoListaPelicula * aux = buscarListaPeliUltimo(listaP);
        aux->sig=nuevoNodo;
    }
    return listaP;
}

nodoListaPelicula * insertarPeliOrden(nodoListaPelicula * listaP, nodoListaPelicula * nuevoNodo)
{
    if(listaP)
    {
        if(listaP->p.nombrePelicula > nuevoNodo->p.nombrePelicula)
        {
            listaP = (nodoListaPelicula *)insertarPeliOrden(listaP->sig, nuevoNodo);
        }
        else
        {
            nodoListaPelicula * aux = listaP->sig;
            listaP->sig = nuevoNodo;
            nuevoNodo->sig = aux;
        }
    }
    else
    {
        listaP = nuevoNodo;
    }
    return listaP;
}

nodoListaPelicula * buscarListaPeliID(int idPelicula, nodoListaPelicula * listaP)
{
    nodoListaPelicula * aux = NULL;
    if(listaP)
    {
        if(listaP->p.idPelicula == idPelicula)
        {
            aux = listaP;
        }
        else
        {
            aux = buscarListaPeliID(idPelicula,listaP->sig);
        }
    }
    return aux;
}

nodoListaPelicula * buscarListaPeliUltimo(nodoListaPelicula * listaP)
{
    nodoListaPelicula * seg = listaP;
    if(seg != NULL)
    {
        while(seg->sig != NULL)
        {
            seg = seg->sig;
        }
    }

    return seg;
}

nodoListaPelicula * borrarPelicula(nodoListaPelicula * listaP, int id)
{
    if(listaP)
    {
        if(listaP->p.idPelicula == id)
        {
            nodoListaPelicula * aux = listaP;
            listaP = listaP->sig;
            free(aux);
        }
        else
        {
            nodoListaPelicula * seg = listaP->sig;
            if(seg->p.idPelicula != id)
            {
                listaP->sig = (nodoListaPelicula *)borrarPelicula(listaP->sig, id);
            }
            else
            {
                seg = listaP->sig;
                listaP->sig = seg->sig;
                free(seg);
            }
        }
    }
    return listaP;
}

void eliminarPelicula(nodoListaPelicula * listaP, int idPelicula)
{
    if(listaP)
    {
        if(listaP->p.idPelicula == idPelicula)
        {
            listaP->p.eliminado = !(listaP->p.eliminado);
        }
        else
        {
            eliminarPelicula(listaP->sig,idPelicula);
        }
    }
}

nodoListaPelicula * borrarListaPeliculas(nodoListaPelicula * lista)
{
    nodoListaPelicula * proximo;
    nodoListaPelicula * seg;
    seg = lista;
    while(seg != NULL)
    {
        proximo = seg->sig;
        free(seg);
        seg = proximo;
    }
    return seg;
}

void mostrarPelicula(stPelicula pelicula)
{
    printf("%i\t%s\t%s\t\t%s\t\t%i\t%s\t%i\t%i\n",pelicula.idPelicula,pelicula.nombrePelicula,pelicula.director,pelicula.genero,pelicula.anio,pelicula.pais,pelicula.pm,pelicula.valoracion);
}

void mostrarListaPelis(nodoListaPelicula * listaP)
{
    if(listaP!=NULL)
    {
        mostrarPelicula(listaP->p);
        mostrarListaPelis(listaP->sig);
    }
}

void mostrarListaPelisActivas(nodoListaPelicula * listaP)
{
    if(listaP!=NULL)
    {
        if(listaP->p.eliminado == 0) mostrarPelicula(listaP->p);
        mostrarListaPelisActivas(listaP->sig);
    }
}

nodoListaPelicula * archivoAListaPelis(const char archivo[], nodoListaPelicula * listaP, int carga)
{
    FILE *archi;
    archi = fopen(archivo, "rb");
    if(archi != NULL)
    {
        stPelicula aux;
        while(fread(&aux, sizeof(stPelicula), 1, archi) > 0 && !(aux.eliminado)) //recorro el archivo de peliculas
        {
            nodoListaPelicula * nuevo = crearNodoListaPelicula(aux);
            switch(carga)
            {
                case 1:
                {
                    listaP = insertarPeliPpio(arbolP,nuevo);
                    break;
                }
                case 2:
                {
                    listaP = insertarPeliFinal(arbolP,nuevo);
                    break;
                }
                case 3:
                {
                    listaP = insertarPeliOrden(arbolP,nuevo);
                    break;
                }
            }
        }
        fclose(archi);
    }
    return listaP;
}

void listaPelisAArchivo(const char archivo[], nodoListaPelicula *listaP)
{
    FILE *archi;
    archi = fopen(archivo,"wb");
    if(archi!=NULL)
    {
        nodoListaPelicula * seg = listaP;
        while(seg != NULL)
        {
            fwrite(&seg->p,sizeof(stPelicula),1,archi);
            seg = seg->sig;
        }
        fclose(archi);
    }
}
///Modificando el struct stPelicula para así añadirle una variable llamada reproducciones hacemos que se pueda generar un promedio para calcular la valoracion.
stPelicula calificarPelicula(stPelicula pelicula)
{
    int numero;

    printf("\nCalifique la película del 1 al 10: ");
    fflush(stdin);
    scanf("%i", &numero);

    while(numero<1 && numero> 10)
    {
        printf("\nCalifique la película del 1 al 10: ");
        fflush(stdin);
        scanf("%i", &numero);
    }

//    (float)pelicula.valoracion = ((float)numero+ pelicula.valoracion)/pelicula.reproducciones

    return pelicula;
}
