//practica final 
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
void seleccionarOpcion(int, FILE *);
int contarCaracteres(FILE *);
int numeroTotalFilas(FILE *);
int filaMasLarga(FILE *);

/*función principal*/
int main(void){

    FILE *archivo = fopen("DatosTelefonosMoviles.csv", "r");

    int opcionValida = solicitarOpcionMenu();

   if (archivo == NULL){
        printf("No se abrió correctamente el archivo :/ o saliste del programa, ¡vuelva pronto! :D\n");
    }
    else{
        printf("Se abrió correctamente el fichero :D, espere a que su opción se ejecute.\n");
    }

    
    seleccionarOpcion(opcionValida, archivo);


 
    fclose(archivo);
    
    return 0;
}

/** solicitarOpcionMenu
 * @brief 
 * 
 * @return int 
 */
int solicitarOpcionMenu(){
   
    FILE *archivo;
    int opcionSolicitud = 0;
    int quieresContinuar = 0;

    do{
        printf("1. Numero total de caracteres alfanumericos (solo numeros y letras)\n"
               "2. Numero total de filas (sin contar la cabecera)\n"
               "3. Fila más larga (con el mayor número de caracteres)\n"
               "0. Salir\n");

        printf("Selecciona una opción: ");
        scanf("%d",&opcionSolicitud);

        //si el número introducido es válido
        if(opcionSolicitud < 4 && opcionSolicitud > -1){
            printf("El caso introducido del menú es un caso válido, \n");
            seleccionarOpcion(opcionSolicitud, archivo);

        }
        //si el numero introducido no esta en el rango entre <4 >-1
        else{
            printf("La opción que introduciste no es válida, por favor, introduce una opción válida \n");
            while(opcionSolicitud > 3 && opcionSolicitud < 0){
                printf("Introduce un número válido: ");
                scanf("%d", &opcionSolicitud);
            }
        }
    printf("Para continuar, pulse 1, para salir pulsa cualquier otra tecla:  ");
    scanf("%d", &quieresContinuar);
    }
   
    while(quieresContinuar == 1);

    return opcionSolicitud;
}

/** seleccionarOpcion
 * @brief Lo que realiza la funcion es coger la opción que hemos seleccionado y dependiendo el caso
 * realiza una función u otra o directamente sale del programa.
 * 
 * @param opcionMenu 
 *
 */
void seleccionarOpcion(int opcionMenu, FILE* archivo){

    

    switch (opcionMenu) {

        case 1:
            //comprobamos y abrimos el archivo DatosTelefonosMoviles.csv
            //lo abrimos
            archivo=fopen("DatosTelefonosMobiles.csv","r");
            if(archivo==NULL){
                printf("Error al abrir el archivo\n");
            }
            else{
                contarCaracteres(archivo);
            }
            break;
        case 2:
          archivo=fopen("DatosTelefonosMobiles.csv","r");
            if(archivo==NULL){
                printf("Error al abrir el archivo\n");
            }
            else{
                numeroTotalFilas(archivo);
            }
            break;
        
        case 3:
            archivo=fopen("DatosTelefonosMobiles.csv","r");
            if(archivo==NULL){
                printf("Error al abrir el archivo\n");
            }
            else{
                filaMasLarga(archivo);
            }
            break;
        case 0:
            printf("Saliste del programa con éxito\n");
            break;
        default:
            break;
    }
}



/*Funciones que leen el archivo*/

int contarCaracteres(FILE *archivo){

        int contadorCC = 0;
        char CaracterYaContado;

        CaracterYaContado = fgetc(archivo);

         while(!feof(archivo)){
            contadorCC++;
            
            if(CaracterYaContado=='\n' && CaracterYaContado=='\r'){
                contadorCC--;
            }
            
            CaracterYaContado=fgetc(archivo);
        }
        printf("El archivo contiene %d carácteres\n", contadorCC);

return 1;
}

int numeroTotalFilas(FILE *archivo){

    int contadorNTF = 0;
    char punterolinea;
    
    punterolinea=fgetc(archivo);
    
    while(!feof(archivo)){
        if(punterolinea=='\n'){
            contadorNTF++;
        }
        punterolinea=fgetc(archivo);
            
        }
         
        
return 1;
}






int filaMasLarga(FILE *archivo){
    int lector = 0;
    int caracteresFilaMasLarga = 0;
    int caracteresFilaActualLeida = 0;
    int filaContada = 0;
    int filaMasLarga;
    char caracterActual;
    
    caracterActual=fgetc(archivo);
    
    while(!feof(archivo)){
        if(caracterActual!='\n'){
            lector++;
        }
        else{
            filaContada++;
            caracteresFilaActualLeida = lector - 1;
            if(caracteresFilaActualLeida > caracteresFilaMasLarga){
                filaMasLarga = filaContada;
                caracteresFilaMasLarga = caracteresFilaActualLeida;
            }
            lector=0;
        }
        caracterActual = fgetc(archivo);
    }
    
    printf("la fial mas larga es la %d y contiene %d caracteres", filaMasLarga,caracteresFilaMasLarga);

return 1;
}