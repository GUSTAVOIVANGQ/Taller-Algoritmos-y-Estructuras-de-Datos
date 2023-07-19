#include <stdio.h>
#include <string.h>
#define LONGITUD 1000

void burbuja(char array[][LONGITUD], int N);
void imprimearreglo(char array[][LONGITUD], int N);
int main()
{
    char palabras[][LONGITUD] = {
        "zapato de color cafe",
        "tequila reposado",
        "Agua Fria",
        "huarache de tinga",
        "flores del paraiso",
    };
    int longitud = sizeof(palabras) / sizeof(palabras[0]);
    printf("\n\nArreglo sin ordenar \n\n");
    imprimearreglo(palabras, longitud);
    burbuja(palabras, longitud);
    printf("\n\nArreglo ordenado \n\n");
    imprimearreglo(palabras, longitud);
    printf("\n\nHecho por BrayAM");
    return 0;
}
void burbuja(char array[][LONGITUD], int N)
{
    int i, pasada, aux;
    char auxiliar[LONGITUD];
    int indiceSiguiente; 

    for (pasada = 1; pasada <= N - 1; pasada++) /*pasadas*/
    {
        for (i = 0; i <= N - 2; i++)
        {
            indiceSiguiente = i + 1;
            if (strcmp(array[i], array[indiceSiguiente]) > 0) /*comparacion */
            {
                /*intercambio*/
                memcpy(auxiliar, array[i], LONGITUD);
                memcpy(array[i],array[indiceSiguiente], LONGITUD);
                memcpy(array[indiceSiguiente], auxiliar, LONGITUD);
            }
        }
    }
}

void imprimearreglo(char array[][LONGITUD], int N){
    for (int i = 0; i < N; i++)
    {
        printf("%s\n", array[i]);
    }
}