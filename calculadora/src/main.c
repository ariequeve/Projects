#include <stdio.h>
#include "operaciones.h"

int main() {
    char operador;
    double num1, num2, resultado;

    printf("Ingrese la operación que desea realizar (+, -, *, /): ");
    scanf(" %c", &operador);

    printf("Ingrese el primer número: ");
    scanf("%lf", &num1);

    printf("Ingrese el segundo número: ");
    scanf("%lf", &num2);

    switch(operador) {
        case '+':
            resultado = sumar(num1, num2);
            break;
        case '-':
            resultado = restar(num1, num2);
            break;
        case '*':
            resultado = multiplicar(num1, num2);
            break;
        case '/':
            resultado = dividir(num1, num2);
            break;
        default:
            printf("Operador no válido.\n");
            return 1;
    }

    printf("El resultado es: %.2lf\n", resultado);

    return 0;
}