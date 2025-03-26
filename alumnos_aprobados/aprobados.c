#include <stdio.h>
#include <stdlib.h>

// Definimos una estructura para almacenar los datos de cada alumno
typedef struct {
    char nombre[50];
    float nota;
} Alumno;

// Función para capturar los datos de los alumnos
void capturarDatos(Alumno *alumnos, int cantidad) {
    for (int i = 0; i < cantidad; i++) {
        printf("Ingrese el nombre y apellido del alumno %d: ", i + 1);
        scanf(" %s", alumnos[i].nombre);
        printf("Ingrese la nota del alumno %d: ", i + 1);
        scanf("%f", &alumnos[i].nota);
    }
}

// Función para contar la cantidad de aprobados
int contarAprobados(Alumno *alumnos, int cantidad) {
    int aprobados = 0;
    for (int i = 0; i < cantidad; i++) {
        if (alumnos[i].nota >= 6.0) {
            aprobados++;
        }
    }
    return aprobados;
}

// Función para mostrar los resultados
void mostrarResultados(int aprobados) {
    printf("Cantidad de alumnos aprobados: %d\n", aprobados);
}

int main() {
    int cantidad_alumnos;
    
    printf("Ingrese la cantidad de alumnos: ");
    scanf("%d", &cantidad_alumnos);
    
    // Reservamos memoria dinámicamente para los alumnos
    Alumno *alumnos = (Alumno *) malloc(cantidad_alumnos * sizeof(Alumno));
    if (alumnos == NULL) {
        printf("Error al asignar memoria\n");
        return 1;
    }
    
    // Capturar datos
    capturarDatos(alumnos, cantidad_alumnos);
    
    // Contar aprobados
    int aprobados = contarAprobados(alumnos, cantidad_alumnos);
    
    // Mostrar resultados
    mostrarResultados(aprobados);
    
    // Liberar la memoria dinámica
    free(alumnos);
    
    return 0;
}
