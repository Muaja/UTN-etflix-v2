#include "listaPeliculas.h"

nodoListaPelicula *inicLista()
{
    return NULL;
}

int cantidadPeliculas(nodoListaPelicula * lista)
{
    int numero = 0;
    if(lista)
    {
        numero = 1 + cantidadPeliculas(lista->sig);
    }
    return numero;
}

int existePelicula(nodoListaPelicula * lista, char nombre[])
{
    int flag = 0;
    if(lista)
    {
        if(!strcmpi(lista->p.nombrePelicula, nombre))
        {
            flag = lista->p.idPelicula;
        }
        else
        {
            flag = existePelicula(lista->sig,nombre);
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

nodoListaPelicula * insertarPeliPpio(nodoListaPelicula * lista, nodoListaPelicula * nuevoNodo)
{
    if(lista==NULL)
    {
        lista=nuevoNodo;
    }
    else
    {
        nuevoNodo->sig=lista;
        lista=nuevoNodo;
    }
    return lista;
}

nodoListaPelicula * insertarPeliFinal(nodoListaPelicula * lista, nodoListaPelicula * nuevoNodo)
{
    if(lista==NULL)
    {
        lista=nuevoNodo;
    }
    else
    {
        nodoListaPelicula * aux = buscarListaPeliUltimo(lista);
        aux->sig=nuevoNodo;
    }
    return lista;
}

nodoListaPelicula * insertarPeliOrden(nodoListaPelicula * lista, nodoListaPelicula * nuevoNodo)
{
    if(lista)
    {
        if(lista->p.nombrePelicula > nuevoNodo->p.nombrePelicula)
        {
            lista = (nodoListaPelicula *)insertarPeliOrden(lista->sig, nuevoNodo);
        }
        else
        {
            nodoListaPelicula * aux = lista->sig;
            lista->sig = nuevoNodo;
            nuevoNodo->sig = aux;
        }
    }
    else
    {
        lista = nuevoNodo;
    }
    return lista;
}

nodoListaPelicula * buscarListaPeliID(nodoListaPelicula * lista,int idPelicula)
{
    nodoListaPelicula * aux = NULL;
    if(lista)
    {
        if(lista->p.idPelicula == idPelicula)
        {
            aux = lista;
        }
        else
        {
            aux = buscarListaPeliID(lista->sig,idPelicula);
        }
    }
    return aux;
}

nodoListaPelicula * buscarListaPeliUltimo(nodoListaPelicula * lista)
{
    nodoListaPelicula * seg = lista;
    if(seg != NULL)
    {
        while(seg->sig != NULL)
        {
            seg = seg->sig;
        }
    }
    return seg;
}

nodoListaPelicula * borrarPelicula(nodoListaPelicula * lista, int id)
{
    if(lista)
    {
        if(lista->p.idPelicula == id)
        {
            nodoListaPelicula * aux = lista;
            lista = lista->sig;
            free(aux);
        }
        else
        {
            nodoListaPelicula * seg = lista->sig;
            if(seg->p.idPelicula != id)
            {
                lista->sig = (nodoListaPelicula *)borrarPelicula(lista->sig, id);
            }
            else
            {
                seg = lista->sig;
                lista->sig = seg->sig;
                free(seg);
            }
        }
    }
    return lista;
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

void mostrarListaPelis(nodoListaPelicula * lista)
{
    if(lista!=NULL)
    {
        mostrarPelicula(lista->p);
        mostrarListaPelis(lista->sig);
    }
}

void mostrarListaPelisActivas(nodoListaPelicula * lista)
{
    if(lista!=NULL)
    {
        if(lista->p.eliminado == 0) mostrarPelicula(lista->p);
        mostrarListaPelisActivas(lista->sig);
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
