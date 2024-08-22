#include <stdio.h>

int main() {
    double radio, circunferencia;
    const double pi = 3.141592653589793;

     // Solicitar al usuario que ingrese el radio o 0 (cero) para finalizar
    printf("Ingrese el valor del radio o 0 (cero) para finalizar: ");

    do
    {
        if (scanf(" %lf", &radio) != 1) {
            printf("Por favor, ingrese un valor correcto!\n");

            while(getchar() != '\n');
            continue; // Reintentar la solicitud de entrada
        } 
        if (radio > 0) {
            circunferencia = 2 * pi * radio;
            printf("La circunferencia de un círculo con radio = %.2f es: %.2f\n", radio, circunferencia);
        }
    } while (radio > 0);
    printf("Muchas Gracias");
    return 0;
}