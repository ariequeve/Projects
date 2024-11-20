#include <stdio.h>
/*
 * Ejercicio para la práctica de desarrollo de software para la materia Introducción a la Programación 
 * de la Universidad del Salvador

*/

// Definición de los precios de los servicios utilizando define (obsoleto)
/*
  #define PRECIO_CONSULTA 50
  #define PRECIO_ANALISIS 30
  #define PRECIO_RADIOGRAFIA 80
*/

// Estructura para almacenar la información de cada servicio. Variable Global
struct Servicio {
    char nombre[30];
    float precio;
};

int main() {

    // Variables locales a funcion Main()
    char nombre[50], apellido[50];
    int opcion, cantidadServicios = 0;
    char tieneSeguro;
    float total = 0;
    const float precio_consulta = 50000;
    const float precio_analisis = 30000;
    const float precio_radiografia = 80000;

    struct Servicio servicios[3] = {
        {"Consulta General", precio_consulta},
        {"Análisis de Laboratorio", precio_analisis},
        {"Radiografía", precio_radiografia}
    };
    int serviciosSeleccionados[3] = {0, 0, 0};

    // Solicito nombre del paciente al usuario por terminal
    printf("Ingrese el nombre del paciente: ");
    scanf("%s", nombre);
    printf("Ingrese el apellido del paciente: ");
    scanf("%s", apellido);

    // Muestro menú de servicios y para la selección de servicios de salud
    printf("\n--- Selección de Servicios ---\n");
    do {
        printf("\nSeleccione un servicio:\n");
        for (int i = 0; i < 3; i++) {
            printf("%d. %s - $%.2f\n", i + 1, servicios[i].nombre, servicios[i].precio);
        }
        printf("0. Finalizar selección\n");
        printf("Opción: ");
        scanf("%d", &opcion);

        if (opcion >= 1 && opcion <= 3) {
            serviciosSeleccionados[opcion - 1]++;
            total += servicios[opcion - 1].precio;
            cantidadServicios++;
        } else if (opcion != 0) {
            printf("Opción inválida. Por favor, intente de nuevo.\n");
        }
    } while (opcion != 0);

    // Consulto si el paciente cuenta con seguro de salud o no para la aplicacion del Descuento
    printf("\n¿El paciente tiene seguro de salud? (S/N): ");
    scanf(" %c", &tieneSeguro);

    if (tieneSeguro == 'S' || tieneSeguro == 's') {
        total *= 0.85;
    }

    // Muestro los resultados en funci'on de los servicios seleccionados y el descuento aplicado correspondiente
    printf("\n--- Resumen de la Consulta ---\n");
    printf("Paciente: %s %s\n", nombre, apellido);
    printf("Servicios seleccionados:\n");
    for (int i = 0; i < 3; i++) {
        if (serviciosSeleccionados[i] > 0) {
            printf("- %s: %d veces ($%.2f cada uno)\n", servicios[i].nombre, serviciosSeleccionados[i], servicios[i].precio);
        }
    }
    printf("Total a pagar: $%.2f\n", total);
    if (tieneSeguro == 'S' || tieneSeguro == 's') {
        printf("Descuento aplicado por seguro de salud: 15%%\n");
    } else {
        printf("No se aplicó descuento.\n");
    }

    return 0;
}
