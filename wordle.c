/* wordle.txt */
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


/* 
    Definicion de valores de resultado segun color
        Como no se crea una variable en memoria,
        no hay costos asociados a la asignación de espacio ni al acceso a esa variable.
    buscar porque 4 y no 3 (Flag)
*/
#define ResultadoVerde 1
#define ResultadoAmarillo 2
#define ResultadoRojo 4
#define max 5504

/* STRUCTS*/

struct s_palabras{
    char* *arr;
    int n;
};

/* Renombrando Tipos DE DATOS */
typedef struct s_palabras Palabras;
typedef char Resultado;


/* DECLARACION DE FUNCIONES*/
Palabras leerArchivo(char*);
bool seEncuentraEnPalabra(char, char*);
void ejemploPrinteoResultados(Resultado[]);
Resultado* chequeoDePalabra(char*, char*);
Resultado chequeoDeCaracter(char,int,char*);
int main(int, char**);




/* DEFINICÓN DE FUNCIONES*/

/* 
    leerArchivo
*/
Palabras leerArchivo(char* nombreArchivo){

    char buf[8];
    int i, size;
    FILE* archivo;
    static char retorno[max][5];

    archivo = fopen(nombreArchivo, "r");
    if (!archivo){    
        Palabras palabras = {
            .arr = (char**)0,
            .n = 0
        };
        return palabras;
        perror("fopen");
    }


    i=0;
    memset(buf, 0,8);

    while (fgets(buf, 7, archivo)){
        size = strlen(buf);
        if (size < 1){
            memset(buf,0,8);
            continue;}
        size--;
        buf[size] = 0;

        if(size != 5){
            memset(buf,0,8);
            continue;
        }

        retorno[i][0] = buf[0];
        retorno[i][1] = buf[1];
        retorno[i][2] = buf[2];
        retorno[i][3] = buf[3];
        retorno[i][4] = buf[4];

        memset(buf, 0,8);
        i++;
        
        if(max <= i){
            break;
        }
    }
    
    fclose(archivo);

    Palabras palabras = {
        .arr = (char**)&retorno,
        .n = i
    };
    return palabras;
   

}

/* 
    seEncuentraEnPalabra
*/

bool seEncuentraEnPalabra(char c, char *str){

    bool retorno;
    int i, size;

    retorno = false;
    size =strlen(str);

    for (i=0; i<size; i++){
        if(str[i] == c){
            retorno = true;
            break;
        }
    }

    return retorno;

}

/* 
    ejemploPrinteoResultados
*/

void ejemploPrinteoResultados(Resultado* resultado){

    int i;

    for(i = 0; i<5; i++){
        switch (resultado[i]){
            case ResultadoVerde:
                printf("%s\n", "Verde");
                break;
            
            case ResultadoAmarillo:
                printf("%s\n", "Amarillo");
                break;

            case ResultadoRojo:
                printf("%s\n", "Rojo");
                break;
            
            default:
                printf("Desconocido: %d\n", resultado[i]);
                break;
        }
    }

    return;

}


/* 
    chequeoDePalabra
*/

Resultado* chequeoDePalabra(char* intento, char* palabra){

    static Resultado resultado[5];
    int i;

    for(i = 0; i < 5; i++){
        resultado[i] = chequeoDeCaracter(intento[i], i, palabra);
    }
    return resultado;
}

/* 
    chequeoDeCaracter
- Para una funcion en C, si se quiere pasar un string como parametro, se suele usar un puntero char
- Función auxiliar para chequeo 
*/
Resultado chequeoDeCaracter(char intento, int index, char *palabra){
    char valido;

    valido = palabra[index];

    if (intento == valido) {return ResultadoVerde;} 
    else if (seEncuentraEnPalabra(intento, palabra)){ return ResultadoAmarillo;}

    return ResultadoRojo;

}


/* 
    chequeoDeCaracter
- Para una funcion en C, si se quiere pasar un string como parametro, se suele usar un puntero char
- Función auxiliar para chequeo 
*/
int main(int argc, char* argv[]){

    char *valido, *intento;
    Resultado *resultado;

    if (argc < 3){
        fprintf(stderr, "Uso: %s PALABRAVALIDA PALABRAINTENTO\n", argv[0]);
        return -1;
    }


    valido = argv[1];
    intento = argv[2];

    resultado = chequeoDePalabra(intento, valido);

    ejemploPrinteoResultados(resultado);

    return 0;
};

