#include "pelisVistas.h"

///Crea una nueva estructura con la peli nueva que ve el user
stPelisVistas verPelicula(int idPelicula,int idUser,int validosPelisVistas)
{
    stPelisVistas nuevaPeli;
    nuevaPeli.idPeliVista=validosPelisVistas;
    nuevaPeli.idPelicula=idPelicula;
    nuevaPeli.idUsuario=idUser;

    return nuevaPeli;
}
///Agrega una nueva peli al arreglo recibiendo el dato nuevo de la funcion verPelicula y a la vez llama a una nueva función para con el id de la pelicula
///y del usuario, agregar esta nueva peli a la lista de pelis del user. Llama a la funciòn especifica.
int cargarADLpelisVistas(stPelisVistas pelisVistas[], int val, stPelisVistas datos, nodoListaPelicula * listaP, stCelda user[],int cantUser)
{
    pelisVistas=realloc(pelisVistas,(val+1)*(sizeof(stPelisVistas)));///reacondiciona el tamaño del arreglo
    val++;
    pelisVistas[val-1]=datos;///datos es la struct que se pasa por archivo
    pasarPeliListaToListaUser(datos.idPelicula,datos.idUsuario,listaP);
    return val;
}

///Pasa la nueva pelivista al struc de usuario.
void pasarPeliListaToListaUser(int idPelicula,int idUser, nodoListaPelicula * listaP)
{
    int i = 0;
    while(i < val && idUser != usuarios[i].usr.idUsuario)
    {
        if(idUser == usuarios[i].usr.idUsuario)
        {
            nodoListaPelicula * aux = buscarPeliID(idPelicula,listaP);
            usuarios[i].listaPelis = crearNodoListaPelicula(aux->p);
        }
        i++;
    }
}

///Carga las pelisvistas del archivo al arreglo. Llama a la funciòn de cargar al ADL
void pasarArchivoPelisVistaToADL(stPelisVistas pelisVistas[], int val, nodoListaPelicula * listaP, stCelda user[],int cantUser)
{
    FILE *archi;
    archi = fopen(ARCHIVO_PELISVISTAS,"rb");
    if(archi!=NULL)
    {
       stPelisVistas datos;///copia el dato del archivo
       while(fread(&datos,sizeof(stPelisVistas),1,archi)>0)
       {
           cargarADLpelisVistas(pelisVistas,val,datos,listaP,user,cantUser);
       }

    }

}///hacer un ftell para saber la cantidad de registros y evitar el uso de realloc

///FUNCIONES ADL A ARCHIVO

///Carga el archivo.
void pasarPelisVistasTOarchivo(stPelisVistas pelisVistas[], int val)
{
    FILE *archi;
    archi = fopen(ARCHIVO_PELISVISTAS,"ab");
    if(archi!=NULL)
    {
        for(int i=0; i<val; i++)
        {
            fwrite(&pelisVistas[i],sizeof(stPelisVistas),1,archi);

        }
        fclose(archi);
    }
}
