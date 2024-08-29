#include <stdio.h>

int main() {
    int nota;
    int valor_ingresado;
    const int aprobado = 4;

    //Solicitar al usuario el ingreso de la nota
    printf("Ingrese la nota a validar (0 a 10) o 0 (cero) para terminar: ");
    valor_ingresado = scanf("%d", &nota);

    // Limpiar el buffer de entrada para evitar problemas con entradas incorrectas
    while (getchar() != '\n');

    while (nota != 0) {
        if (valor_ingresado != 1) {
            printf("Error: Caracter incorrecto. Por favor ingrese un número entero entre 0 y 10.\n");
        } else if (nota < 0 || nota > 10) {
            printf("Error: Nota fuera de rango. Por favor ingrese un número entre 0 y 10.\n");
        } else {
            if (nota >= aprobado) {
                printf("La nota ingresada está APROBADA.\n");
            } else {
                printf("La nota ingresada está DESAPROBADA.\n");
            }
        }
        
        // Solicitar nueva entrada
        printf("Ingrese la nota a validar (0 a 10) o 0 (cero) para terminar: ");
        valor_ingresado = scanf("%d", &nota);

        // Limpiar el buffer de entrada para evitar problemas con entradas incorrectas
        while (getchar() != '\n');
    }
    printf("¡Que tengas un buen día!\n");
    return 0;
}
