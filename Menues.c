#include "Menues.h"

void encabezado(char titulo[], char acceso[])
{
    system("cls");
    printf("\n\t\t\t\t\t\t\t UTN-etflix\n\n");
    printf("\t\t\t\t\t\t   %s\n", acceso);
    printf("\n------------------------------------------------------------------------------------------------------------------------");
    printf("\n\t\t\t\t\t\t      %s",titulo);
    printf("\n------------------------------------------------------------------------------------------------------------------------\n");
}

/* Funcion menuInicio(): muestra el menu inicial del programa.

void menuInicio()

1 - Login
2 - Registro
3 - Administracion
0 - Salir a windows
*/
void menuInicio()
{
    system("COLOR F0");
    int opcion = 0;
    encabezado("MENU PRINCIPAL","USUARIO");
    printf("\n1-Login de usuario");
    printf("\n2-Registro de usuario");
    printf("\n3-Administracion");
    printf("\n4-Ver creditos");

    printf("\n\n0-Salir a windows");
    printf("\n\n\nEsperando opcion: ");

    scanf("%d", &opcion);
    switch(opcion)
    {
        case 1:
        {
            encabezado("LOGIN USUARIO","MENU INICIO");
            if(loginUsuario(usuarios,val)) menuPrincipal();
            else menuInicio();
            break;
        }
        case 2:
        {
            encabezado("REGISTRO USUARIO","MENU REGISTRO");
            if(altaUsuario()) menuInicio();
            break;
        }
        case 3:
        {
            encabezado("ADMINISTRACION","ADMINISTRADOR");
            int idUsuario = loginUsuario(usuarios,val);
            if(idUsuario && esAdministrador(idUsuario, usuarios, val)) menuAdministracion();
            else menuInicio();
            break;
        }
        case 4:
        {
            system("START https://trello.com/b/HeI4CpBO/burgue%C3%B1o-fanjul-latorre");
            system("START https://github.com/Muaja/UTN-etflix-v2");
            menuInicio();
            break;
        }
        case 0:
        {
            salir();
            break;
        }
    }
}

/* Funcion menuPrincipal(): muestra el menu inicial del programa.

void menuPrincipal()

1 - Ver pelicula
2 - Listar peliculas
3 - Buscar pelicula
4 - Peliculas recomendadas
5 - Ver perfil
0 - Salir al menu de inicio
*/
void menuPrincipal()
{
    int opcion = 0;
    encabezado("MENU PRINCIPAL","USUARIO");
    printf("\n1-Ver pelicula");
    printf("\n2-Listar peliculas");
    printf("\n3-Buscar pelicula");
    printf("\n4-Peliculas recomendadas");

    printf("\n\n5-Ver perfil");

    printf("\n\n0-Salir al menu de inicio");
    printf("\n\n\nEsperando opcion: ");

    scanf("%d", &opcion);

    switch(opcion)
    {
        case 1:
        {
            int idPelicula;
            encabezado("VER PELICULA","USUARIO");
            MostrarArbolInorder(arbolP);
            printf("\n\n0-Volver al menu");
            printf("\n\nEsperando opcion: ");
            scanf("%i", &idPelicula);
            while(idPelicula < 0 || idPelicula > nodosArbol(arbolP)+1)
            {
                printf("\n\nEsperando opcion (Error: Esa pelicula no existe): ");
                scanf("%i", &idPelicula);
            }
            if(!idPelicula)
            {
                menuPrincipal();
            }
            else
            {
                verPelicula(sesion,idPelicula);
                mirandoPelicula(idPelicula);
                menuCalificar(idPelicula);
            }
            break;
        }
        case 2:
        {
            menuListarPeliculas(0,0);
            break;
        }
        case 3:
        {
            menuBuscarPelicula(0,0);
            break;
        }
        case 4:
        {
            peliculasRecomendadas(sesion);
            break;
        }
        case 5:
        {
            modificarUsuario(sesion,0,usuarios,val);
            break;
        }
        case 0:
        {
            menuInicio();
            break;
        }
    }
}

void menuCalificar(int idPelicula)
{
    encabezado("GRACIAS POR MIRAR","USUARIO");
    printf("\n1-Ver de nuevo");
    printf("\n2-Calificar");
    printf("\n3-Ver otra pelicula");

    printf("\n\n0-Volver al menu");
    int opcion = 0;
    printf("\n\nEsperando opcion: ");
    scanf("%i", &opcion);
    switch(opcion)
    {
        case 1:
        {
            verPelicula(sesion,idPelicula);
            menuCalificar(idPelicula);
            break;
        }
        case 2:
        {
            encabezado("CALIFIQUE LA PELICULA","USUARIO");
            int num;
            printf("\nCalifica la película de 1 a 5: ");
            scanf("%i", &num);
            while(num < 1 && num > 5)
            {
                printf("\nCalifica la película de 1 a 5: ");
                scanf("%i", &num);
            }
            calificarPelicula(idPelicula,num);
            printf("\n\nEl puntaje ha sido actualizado satisfactoriamente.\nMuchas gracias.\n\n");
            system("pause");
            menuPrincipal();
            break;
        }
        case 3:
        {
            int idPelicula;
            encabezado("VER PELICULA","USUARIO");
            MostrarArbolInorder(arbolP);
            printf("\n\nEsperando opcion: ");
            scanf("%i", &idPelicula);
            while(idPelicula < 0 || idPelicula > nodosArbol(arbolP)+1)
            {
                printf("\n\nEsperando opcion (Error: Esa pelicula no existe): ");
                scanf("%i", &idPelicula);
            }
            if(!idPelicula)
            {
                menuPrincipal();
            }
            else
            {
                verPelicula(sesion,idPelicula);
                menuCalificar(idPelicula);
            }
            break;
        }
        case 0:
        {
            menuPrincipal();
            break;
        }
    }
}

/* Reproductor para la función de ver pelicula. A mejorar. */
void mirandoPelicula(int idPelicula)
{
    nodoArbolPelicula * nombre = buscarPelicula(arbolP,idPelicula);
    encabezado(nombre->p.nombrePelicula,nombre->p.url);
    reproductor();
    if(strstr(nombre->p.url,"http") != NULL) // Si la pelicula cuenta con url se abre en el navegador
    {
        char cmd[64];
        strcpy(cmd,"START ");
        strcat(cmd,nombre->p.url);
        system(cmd);
    }
    printf("\n\n");
    system("pause");
}

void peliculasRecomendadas(int idUsuario)
{
    encabezado("PELICULAS RECOMENDADAS","MEJORES PELICULAS");
    if(!arbolP || !buscarUsuario(usuarios,val,idUsuario))
    {
        printf("\n\nTodavia no se han creado peliculas. O todavia el usuario no esta registrado.");
        system("pause");
        menuPrincipal();
    }
    else
    {
        int dim = nodosArbol(arbolP);
        stPelicula peliculas[dim];
        int validos = listarPeliculas(4, peliculas, 0, dim, 0);
        mostrarArregloPeliculas(peliculas,0,validos);

        int idPelicula = 0;
        printf("\n\n0-Volver al menu");
        printf("\n\nEsperando opcion: ");
        scanf("%i", &idPelicula);
        while(idPelicula < 0 || idPelicula > validos)
        {
            printf("\n\nEsperando opcion (Error: Esa pelicula no existe): ");
            scanf("%i", &idPelicula);
        }
        if(!idPelicula)
        {
            menuPrincipal();
        }
        else
        {
            verPelicula(sesion,idPelicula);
            mirandoPelicula(idPelicula);
            menuCalificar(idPelicula);
        }
    }
}

void reproductor()
{
    int lado=22;
    int contador = 1;
    int contador2 = 1;

    while (contador2 < lado+1)
    {
        contador = 1;
        while (contador < lado+1)
        {
            if (contador2 == 1) printf("* ");
            if (contador2 != 1)
            {
                if (contador2 != lado)
                {
                    if (contador == 1)
                        printf("* ");
                    else
                        if (contador < lado)
                            printf("  ");
                        else
                            printf("* ");
                }
                else printf("* ");
            }
            contador++;
        }
        printf(" \n");
        contador2++;
    }
    printf("* <<  |>  >>  V                           *\n* * * * * * * * * * * * * * * * * * * * * *\n\n");
}

void menuListarPeliculas(int dim, int acceso)
{
    int opcion = 0;
    encabezado("LISTAR PELICULAS","Ver peliculas y series");
    printf("\n1-Por titulo");
    printf("\n2-Por genero");
    printf("\n3-Por pais");
    printf("\n4-Por valoracion");
    printf("\n5-Por anio");
    printf("\n6-Por clasificacion");

    printf("\n\n7-Cantidad que desea listar (0=Todas): %i", dim);

    printf("\n\n0-Volver hacia atras");
    printf("\n\n\nEsperando opcion: ");

    scanf("%d", &opcion);

    switch(opcion)
    {
        case 0:
        {
            switch(acceso)
            {
                case 0:
                {
                    menuPrincipal();
                    break;
                }
                case 1:
                {
                    menuAdministrarPeliculas();
                    break;
                }
            }
            break;
        }
        case 7:
        {
            encabezado("LISTAR PELICULAS","Ver peliculas y series");
            printf("\nIngrese la cantidad que desea listar: ");
            scanf("%d", &dim);
            menuListarPeliculas(dim,acceso);
        }
        default:
        {
            /*
            0-sin filtro
            1-por titulo. (ordenado por seleccion)
            2-por genero. (ordenado por insercion)
            3-por pais
            4-por valoracion.
            5-por anio.
            6-por clasificacion para mayores PM.
            */

            if(dim == 0) dim = nodosArbol(arbolP);
            stPelicula peliculas[dim];
            encabezado("LISTAR PELICULAS","Ver peliculas y series");
            int validos = listarPeliculas(opcion, peliculas, 0, dim, 0);
            mostrarArregloPeliculas(peliculas,0,validos);
            system("pause");
            menuListarPeliculas(dim,acceso);
        }
    }
}

void menuBuscarPelicula(int dim, int acceso)
{
    int opcion = 0;
    encabezado("BUSQUEDA PELICULAS","Ver peliculas y series");
    printf("\n1-Por titulo");
    printf("\n2-Por genero");
    printf("\n3-Por pais");
    printf("\n4-Por valoracion");
    printf("\n5-Por anio");
    printf("\n6-Por clasificacion");

    printf("\n\n7-Cantidad que desea buscar (0=Todas): %i", dim);

    printf("\n\n0-Volver hacia atras");
    printf("\n\n\nEsperando opcion: ");

    scanf("%d", &opcion);

    switch(opcion)
    {
        case 0:
        {
            switch(acceso)
            {
                case 0:
                {
                    menuPrincipal();
                } break;
                case 1:
                {
                    menuAdministrarPeliculas();
                } break;
            }
        } break;
        case 7:
        {
            encabezado("BUSQUEDA PELICULAS","Ver peliculas y series");
            printf("\nIngrese la cantidad que desea buscar: ");
            scanf("%d", &dim);
            menuBuscarPelicula(dim,acceso);
        } break;
        default:
        {
            /*
            0-sin filtro
            1-por titulo.
            2-por genero.
            3-por pais
            4-por valoracion.
            5-por anio.
            6-por clasificacion para mayores PM.
            */

            int cant = 0;
            char filtro[30] = {0};
            int filtro2 = 0;
            if(dim == 0) dim = nodosArbol(arbolP);
            stPelicula peliculas[dim];

            encabezado("BUSQUEDA PELICULAS","Ver peliculas y series");
            switch(opcion)
            {
                case 1:
                {
                    printf("\nIngrese el titulo que desea buscar: ");
                    fflush(stdin);
                    gets(filtro);
                } break;
                case 2:
                {
                    printf("\nIngrese el genero que desea buscar: ");
                    fflush(stdin);
                    gets(filtro);
                } break;
                case 3:
                {
                    printf("\nIngrese el pais que desea buscar: ");
                    fflush(stdin);
                    gets(filtro);
                } break;
                case 4:
                {
                    printf("\nIngrese la valoracion que desea buscar: ");
                    scanf("%i", &filtro2);
                } break;
                case 5:
                {
                    printf("\nIngrese el anio que desea buscar: ");
                    scanf("%i", &filtro2);
                } break;
                case 6:
                {
                    printf("\nIngrese la clasificacion que desea buscar: ");
                    scanf("%i", &filtro2);
                } break;
            }
            cant = consultaPeliculas(opcion, filtro, filtro2, peliculas, dim);

            encabezado("BUSQUEDA PELICULAS","Ver peliculas y series");
            if(cant > 0)
            {
                printf("\nSe encontraron un total de %i peliculas.\n\n", cant);
                mostrarArregloPeliculas(peliculas,0,cant);
                system("pause");
                menuBuscarPelicula(dim,acceso);
            }
            else
            {
                printf("\nNo se encontraron peliculas con ese filtro de busqueda.\n\n");
                system("pause");
                menuBuscarPelicula(dim,acceso);
            }
        }
    }
}

void menuListarUsuarios(int dim, int acceso)
{
    int opcion = 0;
    encabezado("LISTAR USUARIOS","Ver peliculas y series");
    printf("\n1-Por ID");
    printf("\n2-Por nombre");
    printf("\n3-Por anio de nacimiento");
    printf("\n4-Por pais");

    printf("\n\n7-Cantidad que desea listar (0=Todos): %i", dim);

    printf("\n\n0-Volver hacia atras");
    printf("\n\n\nEsperando opcion: ");

    scanf("%d", &opcion);

    switch(opcion)
    {
        case 0:
        {
            switch(acceso)
            {
                case 0:
                {
                    menuPrincipal();
                    break;
                }
                case 1:
                {
                    menuAdministrarUsuarios();
                    break;
                }
            }
            break;
        }
        case 7:
        {
            encabezado("LISTAR USUARIOS","Ver peliculas y series");
            printf("\nIngrese la cantidad que desea listar: ");
            scanf("%d", &dim);
            menuListarUsuarios(dim,acceso);
        }
        default:
        {
            if(dim == 0) dim = val;
            stUsuario muestra[dim];
            encabezado("LISTAR USUARIOS","Ver peliculas y series");
            listarUsuarios(opcion-1, muestra, dim, usuarios, val);
            mostrarUsuarios(muestra, dim);
            system("pause");
            menuListarUsuarios(dim,acceso);
        }
    }
}

void menuBuscarUsuario(int dim, int acceso)
{
    int opcion = 0;
    encabezado("BUSQUEDA USUARIOS","Ver peliculas y series");
    printf("\n1-Por nombre");
    printf("\n2-Por anio");
    printf("\n3-Por pais");

    printf("\n\n7-Cantidad que desea buscar (0=Todas): %i", dim);

    printf("\n\n0-Volver hacia atras");
    printf("\n\n\nEsperando opcion: ");

    scanf("%d", &opcion);

    switch(opcion)
    {
        case 0:
        {
            switch(acceso)
            {
                case 0:
                {
                    menuPrincipal();
                    break;
                }
                case 1:
                {
                    menuAdministrarUsuarios();
                    break;
                }
            }
            break;
        }
        case 7:
        {
            encabezado("BUSQUEDA USUARIOS","Ver peliculas y series");
            printf("\nIngrese la cantidad que desea buscar: ");
            scanf("%d", &dim);
            menuBuscarUsuario(dim,acceso);
            break;
        }
        default:
        {
            /*
            0-sin filtro
            1-por nombre.
            2-por anio.
            3-por pais
            */

            int cant = 0;
            char filtro[30] = {0};
            int filtro2 = 0;
            if(dim == 0) dim = val;
            stUsuario muestra[dim];

            encabezado("BUSQUEDA USUARIOS","Ver peliculas y series");
            switch(opcion)
            {
                case 1:
                {
                    printf("\nIngrese el nombre que desea buscar: ");
                    fflush(stdin);
                    gets(filtro);
                    break;
                }
				case 2:
                {
                    printf("\nIngrese el anio que desea buscar: ");
                    scanf("%i", &filtro2);
                    break;
                }
                case 3:
                {
                    printf("\nIngrese el pais que desea buscar: ");
                    fflush(stdin);
                    gets(filtro);
                    break;
                }
            }
            cant = consultaUsuarios(opcion, filtro, filtro2, muestra, dim, usuarios, val);

            encabezado("BUSQUEDA USUARIOS","Ver peliculas y series");
            if(cant > 0)
            {
                printf("\nSe encontraron un total de %i usuarios.\n\n", cant);
                mostrarUsuarios(muestra,cant);
                system("pause");
                menuBuscarUsuario(dim,acceso);
            }
            else
            {
                printf("\nNo se encontraron usuarios con ese filtro de busqueda.\n\n");
                system("pause");
                menuBuscarUsuario(dim,acceso);
            }
        }
    }
}

/* Funcion menuAdministracion(): muestra el menu de administracion.

void menuPrincipal()

1 - Administrar usuarios
2 - Administrar peliculas
0 - Salir al menu de inicio
*/
void menuAdministracion()
{
    system("COLOR 0A");

    int opcion = 0;
    encabezado("MENU ADMINISTRACION","ADMINISTRADOR");
    printf("\n1-Administrar usuarios");
    printf("\n2-Administrar peliculas");

    printf("\n\n0-Volver al inicio");
    printf("\n\n\nEsperando opcion: ");

    scanf("%d", &opcion);

    switch(opcion)
    {
        case 1:
        {
            menuAdministrarUsuarios();
            break;
        }
        case 2:
        {
            menuAdministrarPeliculas();
            break;
        }
        case 0:
        {
            menuInicio();
            break;
        }
    }
}

void menuAdministrarUsuarios()
{
    int opcion = 0, idUsuario;
    encabezado("ADMINISTRACION USUARIOS","ADMINISTRADOR");
    printf("\n1-Dar de alta a un usuario");
    printf("\n2-Dar de baja a un usuario");
    printf("\n3-Modificar los datos de un usuario");
    printf("\n4-Buscar usuario");
    printf("\n5-Listar usuarios");
    printf("\n6-Limpiar Arreglo de Listas");
    printf("\n7-Recargar ADL");

    printf("\n\n0-Volver hacia atras");
    printf("\n\n\nEsperando opcion: ");

    scanf("%d", &opcion);

    switch(opcion)
    {
        case 1:
        {
            encabezado("ALTA USUARIO","ADMINISTRADOR");
            altaUsuario();
            menuAdministrarUsuarios();
            break;
        }
        case 2:
        {
            encabezado("BAJA USUARIO","ADMINISTRADOR");
            printf("\nIngrese el ID del usuario que desea eliminar: ");
            scanf("%i", &idUsuario);
            while(idUsuario > val)
            {
                printf("\nIngrese el ID del usuario que desea eliminar (Error: El usuario no existe): ");
                scanf("%i", &idUsuario);
            }
            eliminarUsuario(idUsuario,usuarios,val);
            menuAdministrarUsuarios();
            break;
        }
        case 3:
        {
            encabezado("MODIFICAR USUARIO","ADMINISTRADOR");
            printf("\nIngrese el ID del usuario que desea modificar: ");
            scanf("%i", &idUsuario);
            while(idUsuario > val)
            {
                printf("\nIngrese el ID del usuario que desea modificar (Error: El usuario no existe): ");
                scanf("%i", &idUsuario);
            }
            modificarUsuario(idUsuario, 1, usuarios, val);
            break;
        }
        case 4:
        {
            encabezado("BUSQUEDA USUARIOS","Ver peliculas y series");
            menuBuscarUsuario(0,1);
        }
        case 5:
        {
            encabezado("LISTA USUARIOS","Ver peliculas y series");
            menuListarUsuarios(0,1);
        }
        case 6:
        {
            encabezado("LISTA USUARIOS","Ver peliculas y series");
            limpiarArregloDeListas();
            menuAdministrarUsuarios();
        }
        case 7:
        {
            encabezado("LISTA USUARIOS","Ver peliculas y series");
            archivoUsuariosToADL(ARCHIVO_USUARIOS);
            menuAdministrarUsuarios();
        }
        case 0:
        {
            menuAdministracion();
            break;
        }
    }
}

void menuAdministrarPeliculas()
{
    int opcion, idPelicula, cantidad = nodosArbol(arbolP);
    encabezado("ADMINISTRACION PELICULAS","ADMINISTRADOR");
    printf("\n1-Dar de alta una pelicula");
    printf("\n2-Dar de baja una pelicula");
    printf("\n3-Modificar los datos de una pelicula");
    printf("\n4-Buscar pelicula");
    printf("\n5-Listar peliculas");
    printf("\n6-Arbol de peliculas");

    printf("\n\n0-Volver hacia atras");
    printf("\n\n\nEsperando opcion: ");

    scanf("%d", &opcion);

    switch(opcion)
    {
        case 1:
        {
            encabezado("ALTA PELICULA","ADMINISTRADOR");
            altaPelicula();
            menuAdministrarPeliculas();
            break;
        }
        case 2:
        {
            encabezado("BAJA PELICULA","ADMINISTRADOR");
            printf("\nIngrese el ID de la pelicula que desea eliminar:\n");
            scanf("%i", &idPelicula);
            while(idPelicula > cantidad)
            {
                printf("\nIngrese el ID de la pelicula que desea eliminar (Error: La pelicula no existe): ");
                scanf("%i", &idPelicula);
            }
            eliminarPelicula(arbolP, idPelicula);
            menuAdministrarPeliculas();
            break;
        }
        case 3:
        {
            encabezado("MODIFICAR PELICULA","ADMINISTRADOR");
            printf("\nIngrese el ID de la pelicula que desea modificar:\n");
            scanf("%i", &idPelicula);
            while(!buscarPelicula(arbolP,idPelicula))
            {
                printf("\nIngrese el ID de la pelicula que desea modificar (Error: La pelicula no existe): ");
                scanf("%i", &idPelicula);
            }
            modificarPelicula(idPelicula);
            break;
        }
        case 4:
        {
            encabezado("BUSQUEDA PELICULAS","Ver peliculas y series");
            menuBuscarPelicula(0,1);
            break;
        }
        case 5:
        {
            menuListarPeliculas(0,1);
            break;
        }
        case 6:
        {
            menuArbolPeliculas();
            break;
        }
        case 0:
        {
            menuAdministracion();
            break;
        }
    }
}

void menuArbolPeliculas()
{
    int opcion = 0;
    encabezado("ARBOL DE PELICULAS","ADMINISTRADOR");
    printf("\n1-Insertar nodo en arbol");
    printf("\n2-Mostrar arbol");
    printf("\n3-Borrar nodo por ID");
    printf("\n4-Borrar todo el arbol");
    printf("\n5-Recargar arbol");
    printf("\n6-Balancear arbol");

    printf("\n\n0-Volver hacia atras");
    printf("\n\n\nEsperando opcion: ");

    scanf("%d", &opcion);

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
                encabezado("ARBOL PELICULAS","ADMINISTRADOR");
                stPelicula aux = cargaPelicula();
                nodoArbolPelicula * nuevo = crearNodoArbolPelicula(aux);
                insertarNodoArbol(arbolP,nuevo);
                printf("\n\nEl nodo se ha insertado satisfactoriamente.\n\n");
                break;
            }
            case 2:
            {
                if(nodosArbol(arbolP) != 0) menuMostrarArbol();
                else printf("Todavia no se han cargado peliculas.\n\n");
                break;
            }
            case 3:
            {
                encabezado("BORRAR UN NODO POR ID","ADMINISTRADOR");
                if(nodosArbol(arbolP) != 0)
                {
                    int idPelicula;
                    printf("\nIngresa la ID del nodo que desea borrar: ");
                    scanf("%i", &idPelicula);
                    while(!buscarPelicula(arbolP,idPelicula) && idPelicula != 0)
                    {
                        printf("\nIngresa la ID del nodo que desea borrar (Error: La pelicula no existe): ");
                        scanf("%i", &idPelicula);
                    }
                    arbolP = borrarNodoArbol(arbolP,idPelicula);
                    printf("\n\nLa pelicula ha sido borrada satisfactoriamente.\n\n");
                }
                else printf("Todavia no se han creado peliculas.\n\n");
                break;
            }
            case 4:
            {
                encabezado("BORRAR ARBOL PELICULAS","ADMINISTRADOR");
                arbolP = borrarArbol(arbolP);
                if(nodosArbol(arbolP) == 0) printf("\n\nEl arbol ha sido vaciado satisfactoriamente.\n\n");
                else printf("Error al vaciar el arbol.\n\n");
                break;
            }
            case 5:
            {
                encabezado("RECARGAR ARBOL PELICULAS","ADMINISTRADOR");
                if(nodosArbol(arbolP) == 0)
                {
                    arbolP = inicArbol();
                    arbolP = archivoAArbolPelis(ARCHIVO_PELICULAS, arbolP, 0);
                    printf("\n\nEl arbol ha sido recargado satisfactoriamente.\n\n");
                }
                else printf("El arbol ya tiene peliculas.\n\n");
                break;
            }
            case 6:
            {
                encabezado("BALANCEAR ARBOL PELICULAS","ADMINISTRADOR");
                arbolP = borrarArbol(arbolP);
                arbolP = inicArbol();
                arbolP = archivoAArbolPelis(ARCHIVO_PELICULAS, arbolP, 1);
                if(nodosArbol(arbolP) != 0) printf("\n\nEl arbol ha sido balanceado satisfactoriamente.\n\n");
                else printf("Todavia no se han creado peliculas.\n\n");
                break;
            }
        }
        system("pause");
        menuArbolPeliculas();
    }
}

void menuMostrarArbol()
{
    int opcion = 0;
    encabezado("MOSTRAR ARBOL","ADMINISTRADOR");
    printf("\n1-PRE-ORDER");
    printf("\n2-IN-ORDER");
    printf("\n3-POST-ORDER");
    printf("\n4-2D");

    printf("\n\n0-Volver hacia atras");
    printf("\n\n\nEsperando opcion: ");

    scanf("%d", &opcion);
    while(opcion < 0 && opcion >= 5)
    {
        printf("\nEsperando opcion (Error: La opcion debe ser entre 0 y 4 inclusive): ");
        scanf("%d", &opcion);
    }

    if(opcion == 0)
    {
        menuArbolPeliculas();
    }
    else
    {
        encabezado("MOSTRAR ARBOL","ADMINISTRADOR");
        MostrarArbol(arbolP,opcion);
    }
}

void salir()
{
    ADLToArchivoUsuarios(ARCHIVO_USUARIOS);
    arbolPelisAArchivo(ARCHIVO_PELICULAS, arbolP);
    pelisVistasTOArchivo(ARCHIVO_PELISVISTAS);
    system("cls");
    printf("Saliendo a Windows, gracias por utilizar UTN-etflix...");
    exit(EXIT_SUCCESS);
}
