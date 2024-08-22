/*
 * Programa: Cálculo de la circunferencia de un círculo
 * Autor: Ariel Quevedo
 * Fecha: 22 de agosto de 2024
 * Versión: 1.0
 * Descripción: Este programa solicita al usuario el valor del radio de un círculo e imprime la circunferencia
 *              utilizando la fórmula 2 * pi * radio. El programa continúa solicitando radios hasta que el usuario
 *              ingrese 0 (cero) para finalizar. Además, maneja entradas inválidas del usuario.
 * 
 * Histórico de Versiones:
 *  - Versión 1.0: Programa inicial que calcula la circunferencia de un círculo.
 *
 * Notas:
 *  - El programa utiliza una constante para pi y realiza el cálculo de la circunferencia en cada iteración.
 *  - El valor de pi se define con una precisión de hasta 15 decimales.
 *
 */
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