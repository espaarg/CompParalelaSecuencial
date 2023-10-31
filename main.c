//
// Created by cami on 9/10/2023.
//
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <stdbool.h>

//PROCEDIMIENTOS Y FUNCIONES


// Combinar dos arreglos (parteBAJA y parteALTA) en el espacio del arreglo original
void combinarArreglos(int arregloRecibido[], int baseArray, int valorMedio, int techoArray) {

    // Crear parteBAJA ← A[baseArray..valorMedio] y parteALTA ← A[valorMedio+1..techoArray]

    int tamanioParteBAJA = valorMedio - baseArray + 1; // SE CALCULA EL TAMAÑO DE LA PARTE BAJA DEL ARREGLO RECIBIDO
    int tamanioParteAltaArreglo = techoArray - valorMedio; // SE CALCULA EL TAMAÑO DE LA PARTE ALTA DEL ARREGLO RECIBIDO

    int parteBAJA[tamanioParteBAJA], parteALTA[tamanioParteAltaArreglo]; // SE ASIGNA A CADA PARTE SU CORRESPONDIENTE TAMAÑO

    for (int i = 0; i < tamanioParteBAJA; i++)
        parteBAJA[i] = arregloRecibido[baseArray + i];
    for (int j = 0; j < tamanioParteAltaArreglo; j++)
        parteALTA[j] = arregloRecibido[valorMedio + 1 + j];


    int i, j, posicionAsignacion;

    i = 0; //ELEMENTO USADO PARA EL BUCLE
    j = 0; //ELEMENTO USADO PARA EL BUCLE
    posicionAsignacion = baseArray; // SE COMIENZA ASIGNANDO EN EL ARRAY POR EL VALOR QUE RECIBIMOS DE BASE

    while (i < tamanioParteBAJA && j < tamanioParteAltaArreglo) { //COMPARAMOS QUE LA REPETECIÓN DEL BUCLE SEA MENOR AL TAMAÑO DE LAS DOS PARTES

        if (parteBAJA[i] <= parteALTA[j]) { // SI EL VALOR EN LA PARTE BAJA ES MENOR O IGUAL AL DE LA ALTA, SE ASIGNA ESTE AL ARREGLO QUE ESTAMOS UNIENDO, Y SE INCREMENTA EL CONTADOR DE i (PARTE BAJA)
            arregloRecibido[posicionAsignacion] = parteBAJA[i];
            i++;
        } else { // SI EL VALOR EN LA PARTE ALTA ES MENOR AL DE LA BAJA, SE ASIGNA ESTE AL ARREGLO QUE ESTAMOS UNIENDO, Y SE INCREMENTA EL CONTADOR DE j (PARTE ALTA)
            arregloRecibido[posicionAsignacion] = parteALTA[j];
            j++;
        }
        posicionAsignacion++; // SE INCREMENTA EL VALOR DEL ARRAY QUE ESTAMOS UNIENDO PARA USAR LA SIGUIENTE POSICION
    }

    while (i < tamanioParteBAJA) {
        arregloRecibido[posicionAsignacion] = parteBAJA[i]; // CUANDO SE LLEGA AL LIMITE DE TAMAÑO DE LA PARTE ALTA, LOS VALORES DE LA BAJA SE ASIGNAN DIRECTAMENTE AL ARREGLO
        i++;
        posicionAsignacion++;
    }

    while (j < tamanioParteAltaArreglo) {
        arregloRecibido[posicionAsignacion] = parteALTA[j]; // CUANDO SE LLEGA AL LIMITE DE TAMAÑO DE LA PARTE BAJA, LOS VALORES DE LA BAJA SE ASIGNAN DIRECTAMENTE AL ARREGLO
        j++;
        posicionAsignacion++;
    }
}

//---------------------------------------------------------------------------------//

// DIVIDE EL ARREGLO EN DOS SUBARREGLOS
void dividirArreglo(int arregloRecibido[], int baseArreglo, int techoArreglo) {
    if (baseArreglo < techoArreglo) {

        // valorMedioArreglo ES EL EL PUNTO DONDE SE DIVIDE EN DOS EL ARREGLO
        int valorMedioArreglo = baseArreglo + (techoArreglo - baseArreglo) / 2;

        // SE HACE UNA LLAMADA RECURSIVA PASANDO LAS DOS MITADES DEL ARREGLO PARA QUE SE VUELVA A DIVIDIR
        dividirArreglo(arregloRecibido, baseArreglo, valorMedioArreglo);
        dividirArreglo(arregloRecibido, valorMedioArreglo + 1, techoArreglo);

        // UNE LOS ARREGLOS
        combinarArreglos(arregloRecibido, baseArreglo, valorMedioArreglo, techoArreglo);
    }
}

//---------------------------------------------------------------------------------//

// IMPRIME EL ARREGLO ORDENADO
void imprimirArregloOrdenado(int arr[], int tamanioArray) {
    for (int i = 0; i < tamanioArray; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
//---------------------------------------------------------------------------------//

// IMPRIME EL ARREGLO ORIGINAL
void imprimirArregloOriginal(int arr[], int tamanioArray) {
    for (int i = 0; i < tamanioArray; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
//---------------------------------------------------------------------------------//

// SE ENCARGA DE VER SI EL NUMERO QUE SE LE PASA ES PRIMO
bool esPrimo(int num) {

    if (num <= 1) {
        return 0; // Los números menores o iguales a 1 no son primos.
    }

    for (int i = 2; i < num; i++) {
        if (num % i == 0) {
            return 0; // Si es divisible por algún número distinto de 1 y sí mismo, no es primo.
        }
    }

    return 1;
}
//---------------------------------------------------------------------------------//




// COMIENZA EL PROGRAMA PRINCIPAL
int main(int tamanio_arreglo, char **argv) {



// VARIABLES
    int   cantPrimos=0, j=0;
    long long sumaPrimos= 0, sumaTotal = 0;
    double time_spent = 0.0;



// CODIGO

// SOLICITA AL USUARIO QUE INGRESE EL TAMAÑO DEL ARREGLO
//    printf("Ingrese la cantidad de elementos en el arreglo: ");
//    scanf("%d", &tamanio_arreglo);

// EMPIEZA A CONTAR EL RELOJ
    clock_t begin = clock();

// SE CREA EL ARREGLO DINAMICO DEL TAMAÑO INGRESADO
    int *arreglo = (int *)malloc(tamanio_arreglo * sizeof(int));
    int *arregloPrimos = (int *)malloc(tamanio_arreglo * sizeof(int));


// SE RELLENA EL ARREGLO CON NUMEROS ALEATORIOS
    srand(time(NULL)); //inicializar la semilla aleatoria

    for (int i = 0; i < tamanio_arreglo; i++){
        arreglo[i] = rand() % 100000; //GENERA NUMEROS ALEATORIOS DEL 0 AL 99
        sumaTotal=sumaTotal+ arreglo[i];
    }


    for (int i = 0; i < tamanio_arreglo; i++){
        sumaTotal=sumaTotal+ arreglo[i];
    }

//IMPRIME EL ARREGLO GENERADO ALEATORIAMENTE, QUE SE ENCUENTRA DESORDENADO
//    printf("Arreglo original: \n");
//    imprimirArregloOriginal(arreglo, tamanio_arreglo);

//LLAMA A LA FUNCION QUE SE ENCARGA DE DIVIDIR EL ARREGLO
    dividirArreglo(arreglo, 0, tamanio_arreglo - 1); /**/

// BUSCA E IMPRIME LOS NUMEROS PRIMOS DEL ARREGLO // TAMBIEN SUMA EL VALOR DE TODOS LOS ELEMENTOS
    printf("Numeros primos en el arreglo: ");
    for (int i = 0; i < tamanio_arreglo; i++) {
        if (esPrimo(arreglo[i])) {
            cantPrimos++;
//            printf("%d ", arreglo[i]);
            arregloPrimos[j]=arreglo[i];
            j++;
        }
    }
    printf("\n");



    for (int i = 0; i < j; i++) {
        sumaPrimos=sumaPrimos + arregloPrimos[i];
    }


// IMPRIME EL VALOR TOTAL DE LA SUMA
    printf("El valor de todos los elementos sumados es de: ");
    printf("%I64d",sumaTotal);
    printf("\n");
    printf("\n");

// IMPRIME EL VALOR TOTAL DE LA SUMA DE PRIMOS
    printf("El valor de todos los elementos primos sumados es de: ");
    printf("%I64d",sumaPrimos);
    printf("\n");
    printf("\n");

// IMPRIME EL VALOR TOTAL DE LA SUMA
    printf("La cantidad de primos es de: ");
    printf("%d",cantPrimos);
    printf("\n");
    printf("\n");

// IMPRIME EL ARREGLO ORDENADO
//    printf("Arreglo ordenado: \n");
//    imprimirArregloOrdenado(arreglo, tamanio_arreglo);
//    printf("\n");


// TERMINA DE CONTAR Y MUESTRA EL TIEMPO DEMORADO
    clock_t end = clock();

    time_spent += (double)(end-begin) / CLOCKS_PER_SEC;
    printf("La ejecucion demoro:  ");
    printf("%f", time_spent);

    free(arreglo);

}