/* wordle.txt */
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#define ResultadoVerde 1
#define ResultadoAmarillo 2
// buscar porque 4 y no 3 (Flag)
#define ResultadoRojo 4

struct  s_resultado {
    // Se quiere saber si el resultado del intento es verde, amarillo o rojo
    char color[5];
};

typedef struct  s_resultado Resultado;


// DECLARACION DE FUNCIONES
Resultado chequeoDeCaracter(char,char,int,char*);
int main();
/* 
    Chequeo de un caracter
- Para una funcion en C, si se quiere pasar un string como parametro, se suele usar un puntero char

*/
Resultado chequeoDeCaracter(char valido, char intento, int index, char *palabra){

}

int main(){
    printf("abc\n");
    return 0;
};

