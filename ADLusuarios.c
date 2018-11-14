#include "ADLusuarios.h"

/* Funcion cantidad usuarios: devuelve la cantidad de usuarios creados.

int cantidadUsuarios()

Retorna:
Un entero con la cantidad de usuarios existentes en el archivo. */
int cantidadUsuarios(const char archivo[])
{
    int cantidad = 0;
    FILE *archi;
    archi = fopen(archivo,"rb");
    if(archi != NULL)
    {
        fseek(archi,0,SEEK_END);
        cantidad = ftell(archi)/sizeof(stUsuario);
        fclose(archi);
    }
    return cantidad; //Se retorna el contador para luego usarlo en la funcion altaUsuario.
}

int existeUsuario(char nombreUsuario[])
{
    int existe = 0;
    if(val)
    {
        int i = 0;
        while(i < val && !existe)
        {
            if(strcmpi(usuarios[i].usr.nombreUsuario,nombreUsuario) == 0 && usuarios[i].usr.eliminado == 0) existe = usuarios[i].usr.idUsuario;
            i++;
        }
    }
    return existe;
}

int altaUsuario()
{
    stUsuario aux;

    printf("\nIngrese el nombre de usuario:\n");
    fflush(stdin);
    gets(aux.nombreUsuario);

    while(!strlen(aux.nombreUsuario))
    {
        printf("\nIngrese el nombre del nuevo usuario (Error: El campo usuario no puede estar vacio):\n");
        fflush(stdin);
        gets(aux.nombreUsuario);
    }
    while(existeUsuario(aux.nombreUsuario))
    {
        printf("\nIngrese el nombre del nuevo usuario (Error: El nombre de usuario que ingreso ya existe):\n");
        fflush(stdin);
        gets(aux.nombreUsuario);
    }

    char pass[10];
    printf("\nIngrese una password:\n");
    fflush(stdin);
    gets(pass);
    while(!strlen(pass) || strlen(pass) > 10)
    {
        printf("\nIngrese una password (Error: La password debe tener entre 1 y 10 caracteres):\n");
        fflush(stdin);
        gets(pass);
    }
    encriptarPass(pass, aux.pass);

    aux.anioNacimiento=0;
    printf("\n\nInformacion adicional:\n\nIngrese anio de nacimiento:\n");
    fflush(stdin);
    scanf("%i", &aux.anioNacimiento);

    while(aux.anioNacimiento < 1900 || aux.anioNacimiento > 2018)
    {
        printf("\nIngrese anio de nacimiento (Error: El anio de nacimiento no puede ser ese):\n");
        fflush(stdin);
        scanf("%i", &aux.anioNacimiento);
    }

    aux.genero= 'd';
    printf("\nIngrese el genero (m/f):\n");
    fflush(stdin);
    scanf("%c", &aux.genero);

    while(aux.genero != 'm' && aux.genero != 'f')
    {
        printf("\nIngrese el genero (Error: El genero no puede ser ese):\n");
        fflush(stdin);
        scanf("%c", &aux.genero);
    }

    printf("\nIngrese la nacionalidad:\n");
    fflush(stdin);
    gets(aux.pais);
    while(strlen(aux.pais) == 0)
    {
        printf("\nIngrese la nacionalidad (Error: El campo nacionalidad no puede estar vacio):\n");
        fflush(stdin);
        gets(aux.pais);
    }

    aux.eliminado = 0;
    aux.idUsuario = val+1;

    if(aux.idUsuario == 1) aux.admin = 1;
    else aux.admin = 0;

    //Guardamos el usuario en el arreglo luego de redimensionarlo
    val++;
    if(val == 1) usuarios = dimensionarUsuarios(usuarios,val);
    else usuarios = redimensionarUsuarios(usuarios,val);
    usuarios[aux.idUsuario-1].usr = aux;
    usuarios[aux.idUsuario-1].listaPelis = inicLista();
    ADLToArchivoUsuarios(ARCHIVO_USUARIOS);

    encabezado("REGISTRO EXITOSO", 0);
    printf("Tu cuenta ha sido registrada exitosamente. Por favor, inicia sesion...\n\n");
    system("pause");

    return aux.idUsuario;
}

int buscarUsuario(stCelda usuarios[], int val, int idUsuario)
{
    return (idUsuario <= val);
}

/* Funcion esAdministrador(): recorre el archivo de los usuarios y detecta si el nombre utilizado para el nuevo
usuario que intenamos crear ya esta usado.

int esAdministrador(int idUsuario)

Parametros:
int idUsuario - id del usuario que se desea comprobar.

Retorna:
1 - Si el usuario es administrador.
0 - Si el usuario no es administrador. */
int esAdministrador(int idUsuario, stCelda usuarios[], int val)
{
    return (usuarios[idUsuario-1].usr.admin);
}

/* Funcion eliminar usuario: pide el id de el usuario, recorre el archivo hasta encontrarlo y cambia el valor de la variable eliminado a 1.

int eliminarUsuario(int idUsuario)

Parametros:
int idUsuario - id unica del usuario a eliminar

Retorna:
1 - Si el usuario fue eliminado correctamente.
0 - Si el usuario fue restaurado correctamente. */
int eliminarUsuario(int idUsuario, stCelda usuarios[], int val)
{
    usuarios[idUsuario-1].usr.eliminado = !usuarios[idUsuario-1].usr.eliminado;
    return usuarios[idUsuario-1].usr.eliminado;
}

/* Funcion modificarUsuario(): recibe por parametro el id del usuario que el usuario desea modificar. Permite al usuario seleccionar el campo,
ingresa el nuevo dato y lo guarda.

int modificarUsuario(int idUsuario, int acceso)

Parametros:
int idPelicula - el ID de la pelicula que se desea modificar.
int acceso - el lugar desde donde accede el usuario, 0 el menu de usuario, 1 el menu de administracion. */
int modificarUsuario(int idUsuario, int acceso, stCelda usuarios[], int val)
{
    if(idUsuario <= val)
    {
        int opcion = 0;
        stUsuario aux = usuarios[idUsuario-1].usr;
        char pass[10] = {0};
        desencriptarPass(pass, aux.pass);

        encabezado("MODIFICAR USUARIO","ADMINISTRADOR");
        printf("\n1-Nombre de usuario: [%s]", aux.nombreUsuario);
        printf("\n2-Password: [%s]", pass);
        printf("\n3-Anio de nacimiento: [%i]", aux.anioNacimiento);
        printf("\n4-Genero (m/f): [%c]", aux.genero);
        printf("\n5-Nacionalidad: [%s]", aux.pais);
        if(acceso) printf("\n6-Administrador: [%i]", aux.admin);

        printf("\n\nPeliculas vistas:\n");
        mostrarListaPelis(usuarios[idUsuario-1].listaPelis);

        printf("\n\n0-Salir");
        printf("\n\nEsperando opcion: ");
        scanf("%i", &opcion);

        if(opcion == 0)
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
        }
        else
        {
            switch(opcion)
            {
                case 1:
                {
                    printf("\nIngrese el nuevo nombre de usuario: ");
                    fflush(stdin);
                    gets(aux.nombreUsuario);
                    while(existeUsuario(aux.nombreUsuario))
                    {
                        printf("\nIngrese el nuevo nombre del nuevo usuario (Error: El usuario ya existe): ");
                        fflush(stdin);
                        gets(aux.nombreUsuario);
                    }
                    break;
                }
                case 2:
                {
                    char pass[10] = {0};
                    printf("\nIngrese una password: ");
                    fflush(stdin);
                    gets(pass);
                    while(strlen(pass) > 10)
                    {
                        printf("\nIngrese una password (Error: La password puede tener maximo 10 caracteres): ");
                        fflush(stdin);
                        gets(pass);
                    }
                    encriptarPass(pass, aux.pass);
                    break;
                }
                case 3:
                {
                    printf("\nIngrese anio de nacimiento: ");
                    fflush(stdin);
                    scanf("%i", &aux.anioNacimiento);
                    break;
                }
                case 4:
                {
                    printf("\nIngrese el genero (m/f): ");
                    fflush(stdin);
                    scanf("%c", &aux.genero);
                    break;
                }
                case 5:
                {
                    printf("\nIngrese la nacionalidad: ");
                    fflush(stdin);
                    gets(aux.pais);
                    break;
                }
                case 6:
                {
                    if(acceso)
                    {
                        aux.admin = !aux.admin;
                        if(aux.admin) printf("\nEl usuario %s ahora es administrador.", aux.nombreUsuario);
                        else printf("\nEl usuario %s ya no es administrador.", aux.nombreUsuario);
                    }
                    break;
                }
            }

            usuarios[idUsuario-1].usr = aux;
            ADLToArchivoUsuarios(ARCHIVO_USUARIOS);

            printf("\nSe guardo la modificacion realizada.\n\n");
            system("pause");
            modificarUsuario(idUsuario, acceso, usuarios, val);
        }
    }
    return 1;
}

/* Funcion consulta usuarios: busca en el archivo las usuarios que coinciden con los parametros establecidos, modifica arreglo usuarios
con las usuarios encontrados.
int consultaUsuarios(int tipo, char filtro[], int filtro2, stUsuario usuarios[], int dim)

Parametros:
int tipo - tipo de busqueda que queremos.
char filtro - primer filtro, utilizado para las busquedas por nombre y pais.
int filtro2 - segundo filtro, utilizado para las busquedas por anio de nacimiento.
stUsuario usuarios[] - arreglo de usuarios donde se guardan las id de las usuarios encontrados.
int dim - dimension que establece la cantidad de usuarios que podremos buscar.

switch(tipo de busqueda):
    0-sin filtro
    1-por nombre.
    2-por anio de nacimiento.
    3-por pais.

Retorna:
>0 - La cantidad de usuarios encontrados que coinciden con la busqueda.
0 - Si no se encontraron usuarios o no pudo ser abierto el archivo. */
int consultaUsuarios(int tipo, char filtro[], int filtro2, stUsuario muestra[], int dim, stCelda usuarios[], int val)
{
    int i = 0, j = 0; //contador que ira llenando el array
    if(val)
    {
        switch(tipo)
        {
            case 0:
            {
                while(i < dim && j < val) //recorro el archivo de usuarios y corto si llego al maximo de usuarios
                {
                    muestra[i] = usuarios[j].usr;
                    i++;
                    j++;
                }
            }
            case 1:
            {
                while(i < dim && j < val) //recorro el archivo de usuarios y corto si llego al maximo de usuarios
                {
                    if(strstr(usuarios[j].usr.nombreUsuario,filtro) != NULL) //si encuentra la palabra ingresada en el archivo devuelve un puntero, sino NULL
                    {
                        muestra[i] = usuarios[i].usr;
                        i++;
                    }
                    j++;
                }
            }
			case 2:
            {
                while(i < dim && j < val) //recorro el archivo de usuarios y corto si llego al maximo de usuarios
                {
                    if(usuarios[j].usr.anioNacimiento == filtro2) //si encuentra la palabra ingresada en el archivo devuelve un puntero, sino NULL
                    {
                        muestra[i] = usuarios[i].usr;
                        i++;
                    }
                    j++;
                }
            }
            case 3:
            {
                while(i < dim && j < val) //recorro el archivo de usuarios y corto si llego al maximo de usuarios
                {
                    if(strstr(usuarios[j].usr.pais,filtro) != NULL) //si encuentra la palabra ingresada en el archivo devuelve un puntero, sino NULL
                    {
                        muestra[i] = usuarios[i].usr;
                        i++;
                    }
                    j++;
                }
            }
        }
    }
    return i;
}

void mostrarUsuarios(stUsuario muestra[], int dim)
{
	int i = 0;
    printf("\nID\tUsuario\t\tAnio\t\tGenero\t\tPais\n");
    while(i < dim)
    {
        printf("%i\t%s\t\t%i\t\t%c\t\t%s\n",muestra[i].idUsuario,muestra[i].nombreUsuario,muestra[i].anioNacimiento,muestra[i].genero,muestra[i].pais);
        i++;
    }
    printf("\n\n");
}

/* Funcion listar usuarios:
int listarUsuarios(int tipo, stUsuario usuarios[], int dim)

Parametros:
int tipo - tipo de lista que queremos
stUsuario usuarios[] - arreglo donde se cargan y se ordenan los registros
int dim - tamaño del arreglo

switch(tipo):
    0-sin filtro
    1-por nombre. (ordenado por seleccion)
	2-por anio de nacimiento
    3-por pais
*/
void listarUsuarios(int tipo, stUsuario muestra[], int dim, stCelda usuarios[], int val)
{
    if(val)
    {
        int i = 0, j = 0;
        while(i < dim && j < val)
        {
            muestra[i] = usuarios[j].usr;
            i++;
            j++;
        }
        switch(tipo)
        {
            case 1:
            {
                ordenaArregloUsuariosSeleccionNombre(muestra,dim);
                break;
            }
			case 2:
            {
                ordenaArregloUsuariosSeleccionAnio(muestra,dim);
                break;
            }
            case 3:
            {
                ordenaArregloUsuariosSeleccionPais(muestra,dim);
                break;
            }
        }
    }
}

int posMenorNombreUsuarios(stUsuario muestra[], int pos, int cant)
{

    int i = pos+1;
    int posMenor = pos;
    char menor[30];
    strcpy(menor, muestra[pos].nombreUsuario);

    while(i < cant)
    {
        if(strcmpi(menor, muestra[i].nombreUsuario) > 0)
        {
            strcpy(menor, muestra[i].nombreUsuario);
            posMenor = i;
        }
        i++;
    }
    return posMenor;
}

void ordenaArregloUsuariosSeleccionNombre(stUsuario muestra[], int cant)
{
    int i = 0;
    int menor;
    stUsuario aux;

    while(i < cant)
    {
        menor = posMenorNombreUsuarios(muestra, i, cant);
        aux = muestra[menor];
        muestra[menor] = muestra[i];
        muestra[i] = aux;
        i++;
    }
}

int posMenorAnioUsuarios(stUsuario muestra[], int pos, int cant)
{

    int i = pos+1;
    int posMenor = pos;
	int menor = muestra[pos].anioNacimiento;

    while(i < cant)
    {
        if(menor > muestra[i].anioNacimiento)
        {
            menor = muestra[i].anioNacimiento;
            posMenor = i;
        }
        i++;
    }
    return posMenor;
}

void ordenaArregloUsuariosSeleccionAnio(stUsuario muestra[], int cant)
{
    int i = 0;
    int menor;
    stUsuario aux;

    while(i < cant)
    {
        menor = posMenorAnioUsuarios(muestra, i, cant);
        aux = muestra[menor];
        muestra[menor] = muestra[i];
        muestra[i] = aux;
        i++;
    }
}

int posMenorPaisUsuarios(stUsuario muestra[], int pos, int cant)
{

    int i = pos+1;
    int posMenor = pos;
    char menor[30];
    strcpy(menor, muestra[pos].pais);

    while(i < cant)
    {
        if(strcmpi(menor, muestra[i].pais) > 0)
        {
            strcpy(menor, muestra[i].pais);
            posMenor = i;
        }
        i++;
    }
    return posMenor;
}

void ordenaArregloUsuariosSeleccionPais(stUsuario muestra[], int cant)
{
    int i = 0;
    int menor;
    stUsuario aux;

    while(i < cant)
    {
        menor = posMenorPaisUsuarios(muestra, i, cant);
        aux = muestra[menor];
        muestra[menor] = muestra[i];
        muestra[i] = aux;
        i++;
    }
}

/* Funcion loginUsuario(): pide los datos de usuario y password al usuario, valida los datos y retorna el id del usuario logeado. Tambien guarda el acceso en
la variable global sesion.

int loginUsuario()

Retorna:
El id del usuario que inicia sesion. */
int loginUsuario(stCelda usuarios[], int val)
{
    int idUsuario = 0;
    if(!val)
    {
        printf("Error: Aun no se han creado usuarios.");
        system("pause");
        encabezado("REGISTRO USUARIO","USUARIO");
        altaUsuario();
    }
    else
    {
        char nombreUsuario[30];
        stUsuario aux;
        printf("\nIngrese el nombre de usuario:\n");
        fflush(stdin);
        gets(nombreUsuario);
        idUsuario = existeUsuario(nombreUsuario);
        while(!idUsuario)
        {
            printf("\nIngrese el nombre de usuario (Error: El usuario no existe.):\n");
            fflush(stdin);
            gets(nombreUsuario);
            idUsuario = existeUsuario(nombreUsuario);
        }
        aux = usuarios[idUsuario-1].usr;

        char pass[10] = {0}, passdesencriptada[10] = {0};
        printf("\nIngrese la password:\n");
        fflush(stdin);
        gets(pass);
        desencriptarPass(passdesencriptada, aux.pass);
        while(strlen(pass) > 10)
        {
            printf("\nIngrese una password (Error: La password puede tener maximo 10 caracteres):\n");
            fflush(stdin);
            gets(pass);
        }
        int count = 0;
        while(strcmpi(pass,passdesencriptada) && count < INTENTOS_MAXIMOS)
        {
            printf("\nIngrese una password (Error: La password es incorrecta):\n");
            fflush(stdin);
            gets(pass);
            count++;
            if(count == INTENTOS_MAXIMOS)
            {
                printf("\nHas fallado demasiadas veces, vuelve a intentar mas tarde.");
                system("pause");
                menuInicio();
            }
        }
        sesion = idUsuario; //cargo el id del usuario que accedio al sistema como sesion.
    }
    return idUsuario;
}

/* Funcion calcularInversa2x2(): Funcion auxiliar que calcula la inversa de la matriz testigo, utilizada para la desencriptacion de password.

void calcularInversa2x2(int fila, int columna, const int matriz[][columna], float matrizinv[][columna]) */
void calcularInversa2x2(int fila, int columna, const int matriz[][columna], float matrizinv[][columna])
{
    calcularadjunta2x2(fila, columna, matriz, matrizinv);
    calculartransversa2x2flotante(fila, columna, matrizinv);
    matrizinv[0][1] *= -1;
    matrizinv[1][0] *= -1;

    for (int i=0;i<fila;i++)
    {
        for (int j=0;j<columna;j++)
        {
            matrizinv[i][j]=matrizinv[i][j]/(float)determinante2x2(fila, columna, matriz);
        }
    }
    /* DEBUG */
    /*printf("%i | %i\n", matriz[0][0], matriz[0][1]);
    printf("%i | %i\n", matriz[1][0], matriz[1][1]);

    printf("3 | -1\n");
    printf("-5 | 2\n");

    printf("%f | %f\n", matrizinv[0][0], matrizinv[0][1]);
    printf("%f | %f\n", matrizinv[1][0], matrizinv[1][1]);*/
}
void encriptarPass(char pass[], int password[2][5])
{
    int matrizpassword[2][5];
    passwordAMatriz(pass, matrizpassword);
    /* DEBUG */
    /*for(int i = 0; i < 2; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            printf(" %i ", matrizpassword[i][j]);
        }
        printf("\n");
    }*/
    encriptarMatriz(matrizpassword, password);
    /* DEBUG */
    /*for(int i = 0; i < 2; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            printf(" %i ", password[i][j]);
        }
        printf("\n");
    }*/
}
void passwordAMatriz(char pass[], int matriz[2][5])
{
    int row = 0, col = 0, i = 0;
    for(col = 0; col < 5; col++)
    {
        for(row = 0; row < 2; row++)
        {
            matriz[row][col] = (int)pass[i];
            i++;
        }
    }
}

void encriptarMatriz(int matrizpassword[2][5], int password[2][5]) //multiplica la matriz de 2x2 por la matriz de numeros creada a partir del password y el resultado lo pone en otra matriz
{
    int col = 0;
    for(int i = 0; i < 5; i++)
    {
        password[0][col]=((MATRIZ_TESTIGO[0][0] * matrizpassword[0][i]) + (MATRIZ_TESTIGO[0][1] * matrizpassword[1][i]));
        password[1][col]=((MATRIZ_TESTIGO[1][0] * matrizpassword[0][i]) + (MATRIZ_TESTIGO[1][1] * matrizpassword[1][i]));
        /* DEBUG */
        /*printf("%d | ", password[0][col]);
        printf("%d | ", password[1][col]);*/
        col++;
    }
}

/* Funcion desencriptarPass(): recibe la matriz de la password encriptada, desencripta la matriz multiplicandola por la inversa de la matriz testigo. Luego
pasa el resultado de la matriz a el arreglo de caracteres pasado por parametro.

void desencriptarPass(char pass[], int password[2][5])

Parametros:
char pass[]  - string que contiene la password ingresada por el usuario.
int password[2][5] - matriz donde se guardara la password encriptada. */
void desencriptarPass(char pass[], int password[2][5])
{
    float matrizinversa[2][2];
    int matrizpassword[2][5];
    calcularInversa2x2(2, 2, MATRIZ_TESTIGO, matrizinversa); //calcula la inversa de la matriz testigo utilizada para encriptar
    desencriptarMatriz(password, matrizinversa, matrizpassword); //multiplica la inversa de la matriz testigo por la matriz encriptada
    matrizAPassword(pass, matrizpassword); //matriz de numeros a string
}

void desencriptarMatriz(int matrizencriptada[2][5], float matrizinversa[2][2], int password[2][5])
{
    int col = 0;
    for(int i = 0; i < 5; i++)
    {
        password[0][col] = (((int)matrizinversa[0][0] * matrizencriptada[0][i]) + ((int)matrizinversa[0][1]* matrizencriptada[1][i]));
        password[1][col] = (((int)matrizinversa[1][0] * matrizencriptada[0][i]) + ((int)matrizinversa[1][1]* matrizencriptada[1][i]));
        /* DEBUG */
        /*printf("%i | ", password[0][col]);
        printf("%i | ", password[1][col]);*/
        col++;
    }
}

/* Funcion matrizAPassword(): Funcion auxiliar que pasa los datos de la matriz desencriptada a un arreglo de caracteres(string) para poder mostrarlo.

void matrizAPassword(char pass[], int matriz[2][5])

Parametros:
char pass[] - arreglo de caracteres de la password ingresada por el usuario
int matriz[2][5] - matriz donde se guardaran los caracteres de la password
*/
void matrizAPassword(char pass[], int matriz[2][5])
{
    int row = 0, col = 0, i = 0;
    for(col = 0; col < 5; col++)
    {
        for(row = 0; row < 2; row++)
        {
            pass[i] = matriz[row][col];
            i++;
        }
    }
}

int determinante2x2(int fila, int columna, const int matriz[][columna])
{
    int determinante = (matriz[0][0]*matriz[1][1])-(matriz[0][1]*matriz[1][0]);
    return determinante;
}

void calcularadjunta2x2(int fila, int columna, const int matriz[][columna], float matrizinv[][columna])
{
    int m = 1,k = 1;
    for(int i = 0; i < fila; i++)
    {
        for(int j = 0; j < columna; j++)
        {
            matrizinv[i][j]=matriz[m][k];
            k--;
        }
    }
}

void calculartransversa2x2flotante(int fila, int columna, float matriz[][columna])
{
    int m=0,k=0,aux = 0;
    for (int i=0;i<fila;i++)
    {
        for (int j=0;j<columna-1;j++)
        {
            aux=matriz[i][j];
            matriz[i][j]=matriz[m][k];
            matriz[m][k]=aux;
            m++;
        }
        m=0;
        k++;
    }
}

void archivoUsuariosToADL(const char archivo[])
{
    val = cantidadUsuarios(archivo);
    if(val > 0)
    {
        usuarios = dimensionarUsuarios(usuarios,val);
        stUsuario aux;
        int i = 0;
        FILE *archi;
        archi = fopen(archivo,"rb");
        if(archi != NULL)
        {
            while(fread(&aux, sizeof(stUsuario), 1, archi) > 0)
            {
                usuarios[i].usr = aux;
                usuarios[i].listaPelis = inicLista();
                i++;
            }
            fclose(archi);
        }
    }
}

stCelda * dimensionarUsuarios(stCelda usuarios[], int cant)
{
    usuarios = calloc(cant, sizeof(stCelda));
    return usuarios;
}

stCelda * redimensionarUsuarios(stCelda usuarios[], int cant)
{
    usuarios = realloc(usuarios, sizeof(stCelda)*cant);
    return usuarios;
}

void ADLToArchivoUsuarios(const char archivo[])
{
    if(val)
    {
        stUsuario aux;
        FILE *archi;
        archi = fopen(archivo,"wb");
        if(archi != NULL)
        {
            for(int i = 0; i < val; i++)
            {
                aux = usuarios[i].usr;
                fwrite(&aux, sizeof(stUsuario), 1, archi);
            }
            fclose(archi);
        }
    }
}
