#include <stdio.h>
#include <stdlib.h>

#define MAX_NOMBRE 50
#define MAX_NO_APROBADOS 100  // Límite arbitrario para almacenar alumnos no aprobados

// Estructura para almacenar datos de los alumnos desaprobados
typedef struct {
    char nombre[MAX_NOMBRE];
    float nota;
} AlumnoNoAprobado;



int main() {
    int n = 5;
    int *arr = (int *) calloc(n, sizeof(int)); // Reservamos memoria inicializada en 0

    if (arr == NULL) {
        printf("Error: No se pudo asignar memoria\n");
        return 1;
    }

    // Llenamos el array con valores
    for (int i = 0; i < n; i++) {
        arr[i] = i + 1;
    }

    // Expandimos el array a 10 elementos
    arr = (int *) realloc(arr, 10 * sizeof(int));
    if (arr == NULL) {
        printf("Error: No se pudo redimensionar la memoria\n");
        return 1;
    }

    // Mostramos los valores
    printf("Array después de realloc:\n");
    for (int i = 0; i < 10; i++) {
        printf("%d ", arr[i]);
    }

    // Liberamos memoria
    free(arr);
    arr = NULL; // Evitar punteros colgantes

    return 0;
}
