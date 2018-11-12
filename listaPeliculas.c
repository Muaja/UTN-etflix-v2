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

void verPelicula(int idUsuario, int idPelicula)
{
    nodoArbolPelicula * vista = buscarPelicula(arbolP,idPelicula);
    stPelicula aux = vista->p;
    nodoListaPelicula * nuevo = crearNodoListaPelicula(aux);
    usuarios[idUsuario-1].listaPelis = insertarPeliFinal(usuarios[idUsuario-1].listaPelis,nuevo);
    pelisVistasTOArchivo(ARCHIVO_PELISVISTAS);
}

void calificarPelicula(int idPelicula, int calificacion)
{
    nodoArbolPelicula * buscado = buscarPelicula(arbolP, idPelicula);
    if(buscado)
    {
        buscado->p.reproducciones++;
        buscado->p.valoracion += calificacion;
    }
}

float calificacionPelicula(int idPelicula)
{
    float calificacion = 0;
    nodoArbolPelicula * buscado = buscarPelicula(arbolP, idPelicula);
    if(buscado) calificacion = (float)buscado->p.valoracion/buscado->p.reproducciones;
    return calificacion;
}

int cantidadPelisVistas(const char archivo[])
{
    int cantidad = 0;
    FILE *archi;
    archi = fopen(archivo,"rb");
    if(archi != NULL)
    {
        fseek(archi,0,SEEK_END);
        cantidad = ftell(archi)/sizeof(stPelisVistas);
        fclose(archi);
    }
    return cantidad;
}

void archivoPelisVistasToADL(const char archivo[])
{
    int cant = cantidadPelisVistas(archivo);
    if(cant > 0)
    {
        FILE *archi;
        archi = fopen(archivo,"rb");
        if(archi != NULL)
        {
           stPelisVistas dato;
           while(fread(&dato,sizeof(stPelisVistas),1,archi) > 0)
           {
               verPelicula(dato.idUsuario,dato.idPelicula);
           }
           fclose(archi);
        }
    }
}

void pelisVistasTOArreglo()
{
    int i = 0;
    valpv = 0;
    while(i < val)
    {
        if(usuarios[i].listaPelis != NULL)
        {
            listaPelisVistasToArreglo(usuarios[i].listaPelis, usuarios[i].usr.idUsuario);
        }
        i++;
    }
}

void listaPelisVistasToArreglo(nodoListaPelicula * lista, int idUsuario)
{
    if(lista != NULL)
    {
        agregarPeliculaToArreglo(idUsuario, lista->p.idPelicula);
        listaPelisVistasToArreglo(lista->sig, idUsuario);
    }
}

void agregarPeliculaToArreglo(int idUsuario, int idPelicula)
{
    if(!valpv) pelisVistas = dimensionarPelisVistas(pelisVistas,valpv+1);
    else pelisVistas = redimensionarPelisVistas(pelisVistas,valpv+1);
    pelisVistas[valpv].idPeliVista = valpv+1;
    pelisVistas[valpv].idUsuario = idUsuario;
    pelisVistas[valpv].idPelicula = idPelicula;
    valpv++;
}

stPelisVistas * dimensionarPelisVistas(stPelisVistas pelisVistas[], int cant)
{
    pelisVistas = calloc(cant, sizeof(stPelisVistas));
    return pelisVistas;
}

stPelisVistas * redimensionarPelisVistas(stPelisVistas pelisVistas[], int cant)
{
    pelisVistas = realloc(pelisVistas, sizeof(stPelisVistas)*cant);
    return pelisVistas;
}

void arregloPelisVistasTOarchivo(const char archivo[])
{
    FILE *archi;
    archi = fopen(archivo,"wb");
    if(archi != NULL)
    {
        for(int i = 0; i < valpv; i++)
        {
            fwrite(&pelisVistas[i],sizeof(stPelisVistas),1,archi);
        }
        fclose(archi);
    }
}

void pelisVistasTOArchivo(const char archivo[])
{
    pelisVistasTOArreglo();
    arregloPelisVistasTOarchivo(archivo);
    free(pelisVistas);
    pelisVistas = realloc(pelisVistas, sizeof(stPelisVistas *));
}
