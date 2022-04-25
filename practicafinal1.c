// practica final
/**
 * @file practicafinal1.c
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2022-04-19
 *
 * @copyright Copyright (c) 2022
 *
 */

/*llamadas a biblioteca*/
#include <stdio.h>
#include <math.h>
#include <ctype.h>

/*Prototiplos de las funciones*/
int solicitarOpcionMenu();
void seleccionarOpcion(int);
int contarCaracteres(FILE *);
int numeroTotalFilas(FILE *);
int filaMasLarga(FILE *);

/*función principal*/
int main(void)
{
    
    solicitarOpcionMenu();

    
    return 0;
}

/** solicitarOpcionMenu
 * @brief
 *
 * @return int
 */
int solicitarOpcionMenu()
{

    int opcionSolicitud = 0;
    int quieresContinuar = 0;

    do
    {
        printf("1. Numero total de caracteres alfanumericos (solo numeros y letras)\n"
               "2. Numero total de filas (sin contar la cabecera)\n"
               "3. Fila más larga (con el mayor número de caracteres)\n"
               "0. Salir\n");

        printf("Selecciona una opción: ");
        scanf("%d", &opcionSolicitud);

        // si el número introducido es válido
        if (opcionSolicitud < 4 && opcionSolicitud > -1)
        {
            printf("El caso introducido del menú es un caso válido, \n");
            seleccionarOpcion(opcionSolicitud);
        }
        // si el numero introducido no esta en el rango entre <4 >-1
        else
        {
            printf("La opción que introduciste no es válida, por favor, introduce una opción válida \n");
            
                printf("Introduce un número válido: ");
                scanf("%d", &opcionSolicitud);
            
        }
        printf("-Para continuar --> pulse 1\n"
               "-Para salir definitivamente del programa --> pulse cualquier otro número (ej: 0) ");
        scanf("%d", &quieresContinuar);
        
    
    }
    while(quieresContinuar == 1);
    
    

    return 0;
}

/** seleccionarOpcion
 * @brief Lo que realiza la funcion es coger la opción que hemos seleccionado y dependiendo el caso
 * realiza una función u otra o directamente sale del programa.
 *
 * @param opcionMenu
 *
 */
void seleccionarOpcion(int opcionMenu)
{
    FILE *ftp;
    ftp = fopen("DatosTelefonosMoviles.csv", "r");

    if (ftp == NULL)
    {
        printf("No se abrió correctamente el archivo :/ o saliste del programa, ¡vuelva pronto! :D\n");
    }
    else
    {
        printf("Se abrió correctamente el fichero :D, espere a que su opción se ejecute.\n");
    }


    switch (opcionMenu)
    {
    case 1:
        contarCaracteres(ftp);
        break;
    case 2:
        numeroTotalFilas(ftp);
        break;

    case 3:
        filaMasLarga(ftp);
        break;
    case 0:
        printf("Saliste del programa con éxito\n");
        break;
    }
}

/*Funciones que leen el archivo*/

int contarCaracteres(FILE *ftp)
{

 





   /* int contadorCC = 0;
    char caracteresNumericos = '1' && '2' && '3' && '4' && '5' && '6' && '7' && '8' && '9' && '0';
    char caracteresAlfabeticosm= 'a' && 'b' && 'c' && 'd' && 'f' && 'g' && 'h' && 'i' && 'j' && 'k' && 'l' && 'm' && 'n' && 'o' && 'p' && 'q' && 'r' && 's' && 't' && 'u' && 'v' && 'w' && 'x' && 'y' && 'z';
    char caracteresAlfabeticosM= 'A' && 'B' && 'C' && 'D' && 'E' && 'F' && 'H' && 'I' && 'J' && 'K' && 'L' && 'M' && 'N' && 'O' && 'P' && 'Q' && 'R' && 'S' && 'T' && 'U' && 'V' && 'W' && 'X' && 'Y' && 'Z';


    if(isalpha(caracteresNumericos && caracteresAlfabeticosm && caracteresAlfabeticosM))
        contadorCC++; */
    

   
 /* int charNum=0;
  fgetc(ftp);
  while (!feof(ftp)) {
    ++charNum;
    fgetc(ftp);
  } */
    

    /*while (!feof(ftp))
    {
        CaracterYaContado = fgetc(ftp);
        contadorCC++;
        
        if (CaracterYaContado == '\n' && CaracterYaContado == '\r' )
        {
            contadorCC--;
        }

    }*/
    printf("El archivo contiene %d carácteres\n", contadorCC);
    fclose(ftp);

return 0;
}

int numeroTotalFilas(FILE *ftp)
{

    int contadorNTF = 0;
    char recorreCaracter;

    // Darle el primer caracter a un char.

    while (!feof(ftp))
    { // Recorrer el archivo.
        recorreCaracter = fgetc(ftp);
        if (recorreCaracter == '\n')
        { // Siempre tiene el mismo valor.
            contadorNTF++;
        }
    }
    printf("Numero de lineas es : %i\n", contadorNTF - 1); //-1 ya que no queremos contar la fila de la cabecera

    fclose(ftp);
    return 0;
}

int filaMasLarga(FILE *ftp)
{
    int lector = 0;
    int caracteresFilaMasLarga = 0;
    int caracteresFilaActualLeida = 0;
    int filaContada = 0;
    int filaMasLarga;
    char caracterActual;

    caracterActual = fgetc(ftp);

    while (!feof(ftp))
    {
        if (caracterActual != '\n')
        {
            lector++;
        }
        else
        {
            filaContada++;
            caracteresFilaActualLeida = lector - 1;
            if (caracteresFilaActualLeida > caracteresFilaMasLarga)
            {
                filaMasLarga = filaContada;
                caracteresFilaMasLarga = caracteresFilaActualLeida;
            }
            lector = 0;
        }
        caracterActual = fgetc(ftp);
    }

    printf("la fila mas larga es la %d y contiene %d caracteres\n", filaMasLarga, caracteresFilaMasLarga);
    fclose(ftp);
    return 0;
}