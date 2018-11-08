#include "listaPeliculas.h"

nodoListaPelicula *inicLista()
{
    return NULL;
}

nodoListaPelicula * crearNodo (stPelicula nuevo)
{
    nodoListaPelicula*aux=(nodoListaPelicula*)malloc(sizeof(nodoListaPelicula));
    aux->p=nuevo;
    aux->sig=NULL;
    return aux;
}

stPelicula altaPelicula(nodoListaPelicula * listaP)
{
    stPelicula aux;

    printf("\nIngrese el nombre de la nueva pelicula:\n");
    fflush(stdin);
    gets(aux.nombrePelicula);
    ///Crear función existePelicula
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
    printf("\nIngrese la clasificacion por edad de la pelicula:(0- si es ATP / 13: mayor de trece / 16: mayor de 16 / 18: mayor de 18):\n\n");
    fflush(stdin);
    scanf("%i", &aux.pm);
    while(aux.pm != 0 && aux.pm != 13 && aux.pm != 16 && aux.pm != 18)
    {
        printf("\nIngrese la clasificacion por edad de la pelicula\n(0- si es ATP / 13: mayor de trece / 16: mayor de 16 / 18: mayor de 18):\n");
        fflush(stdin);
        scanf("%i", &aux.pm);
    }

    aux.eliminado = 0;
    ///Hacer la función para las ID
    aux.idPelicula = cantidadPeliculas(listaP);


    return aux;
}
void modificarPelicula(int idPelicula, nodoListaPelicula ** listaP)
{
    nodoListaPelicula* aux = buscarPeliID(&listaP,idPelicula);

    int opcion = 0;

    encabezado("MODIFICAR PELICULA");
    printf("\n1-Nombre de la pelicula: [%s]", aux->p.nombrePelicula);
    printf("\n2-Nombre del director: [%s]", aux->p.director);
    printf("\n3-Genero: [%s]", aux->p.genero);
    printf("\n4-Pais: [%s]", aux->p.pais);
    printf("\n5-Anio: [%i]", aux->p.anio);
    printf("\n6-Valoracion inicial: [%i]", aux->p.valoracion);
    printf("\n7-Clasificacion: [%i]", aux->p.pm);

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
        }

        printf("\nSe guardo la modificacion realizada.\n\n");
        system("pause");
        modificarPelicula(listaP,idPelicula);
    }
}
nodoListaPelicula *agregarPeliPpio(nodoListaPelicula * listaP, nodoListaPelicula * nuevoNodo)
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
nodoListaPelicula * cargarNodosPpio (nodoListaPelicula* listaP)
{
    nodoListaPelicula * nuevoNodo;
    char cont= 's';
    stPelicula aux;
    while (cont=='s')
    {

        aux=altaPelicula(listaP);

        nuevoNodo=crearNodo(aux);

        listaP= agregarPeliPpio(listaP, nuevoNodo);

        printf("desea continuar s/n");
        fflush(stdin);
        scanf("%c",&cont);
        printf("\n");
    }
    return listaP;
}
nodoListaPelicula * cargarNodosFinalPpio (nodoListaPelicula* listaP)
{
    nodoListaPelicula * nuevoNodo;
    char cont= 's';
    stPelicula aux;
    while (cont=='s')
    {

        aux=altaPelicula(listaP);

        nuevoNodo=crearNodo(aux);

        listaP= agregarPeliFinal(listaP, nuevoNodo);

        printf("desea continuar s/n");
        fflush(stdin);
        scanf("%c",&cont);
        printf("\n");
    }
    return listaP;
}
nodoListaPelicula * agregarPeliFinal(nodoListaPelicula * listaP, nodoListaPelicula * nuevoNodo)
{
    if(listaP==NULL)
    {
        listaP=nuevoNodo;
    }
    else
    {
        nodoListaPelicula * aux = buscarUltimo(listaP);
        aux->sig=nuevoNodo;
    }
    return listaP;
}
nodoListaPelicula * buscarUltimo(nodoListaPelicula * listaP)
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
    if(listaP != NULL)
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
nodoListaPelicula * insertarPeliOrden(nodoListaPelicula * listaP, nodoListaPelicula * nuevoNodo)
{
    if(listaP != NULL)
    {
        if(listaP->p.idPelicula > nuevoNodo->p.idPelicula)
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
int existePelicula(nodoListaPelicula * listaP, char nombre[])
{
    int flag = 0;

    if(listaP!=NULL)
    {
        if (strcmpi(listaP->p.nombrePelicula,nombre)==0 && flag==0)
            flag = 1;
        else
            flag=existePelicula(listaP->sig,nombre);
    }
    return flag;
}
nodoListaPelicula * buscarPeliID(int idPelicula,nodoListaPelicula * listaP)
{
    nodoListaPelicula * aux;
    if(listaP != NULL)
    {
        if(listaP->p.idPelicula == idPelicula)
        {
            nodoListaPelicula * aux = listaP;
        }
        else
        {
            if(listaP->p.idPelicula != idPelicula)
            {
                aux = (nodoListaPelicula *)buscarPeliID(idPelicula,listaP->sig);
            }

        }
    }
    return aux;
}
int eliminarPelicula(nodoListaPelicula * listaP, int idPelicula)
{
    int flag = 0;

    if (listaP!=NULL)
    {
        if(listaP->p.idPelicula == idPelicula && listaP->p.eliminado == 0 && flag == 0)
        {
            listaP->p.eliminado = 1;
            flag=1;
        }
        else
        {
            flag = eliminarPelicula(listaP->sig,idPelicula);
        }
    }
    return flag;
}
int cantidadPeliculas(nodoListaPelicula * listaP)
{
    int numero = 0;
    if(listaP != NULL)
    {
        numero = cantidadPeliculas(listaP->sig) + 1;
    }
    return numero;
}
nodoListaPelicula * archivoALista(nodoListaPelicula * listaP)
{
    FILE *archi;
    archi = fopen(ARCHIVO_PELICULAS,"rb");
    if(archi != NULL)
    {
        listaP = archivoAListaOrdenado(listaP,archi);
        fclose(archi);
    }
    return listaP;
}
nodoListaPelicula * archivoAListaOrdenado(nodoListaPelicula * listaP,FILE* archi)
{
    stPelicula aux;
    nodoListaPelicula * nuevo = NULL;
    if(fread(&aux,sizeof(stPelicula),1,archi) > 0)
    {
        nuevo = crearNodo(aux);
        nuevo->sig = archivoAListaOrdenado(listaP, archi);
    }
    return nuevo;
}
void pasarPeliculasTOarchivo(nodoListaPelicula *listaP)
{
    FILE *archi;
    archi = fopen(ARCHIVO_PELICULAS,"ab");
    if(archi!=NULL)
    {
        nodoListaPelicula * seg=listaP;
        while (seg!=NULL)
        {
            fwrite(&seg->p,sizeof(stPelicula),1,archi);
            seg=seg->sig;
        }
        fclose(archi);
    }
}

void mostrarUnaPelicula(stPelicula pelicula)
{
    printf("%i\t%s\t%s\t\t%s\t\t%i\t%s\t%i\t%i\n",pelicula.idPelicula,pelicula.nombrePelicula,pelicula.director,pelicula.genero,pelicula.anio,pelicula.pais,pelicula.pm,pelicula.valoracion);
}
void mostrarTodasLasPelis(nodoListaPelicula * listaP)
{
    if(listaP!=NULL)
    {
        mostrarUnaPelicula(listaP->p);
        mostrarTodasLasPelis(listaP->sig);
    }
}
void mostrarSoloPelisActivas(nodoListaPelicula * listaP)
{
    if(listaP!=NULL)
    {
        if(listaP->p.eliminado==0)
            mostrarUnaPelicula(listaP->p);
            mostrarTodasLasPelis(listaP->sig);
    }
}
