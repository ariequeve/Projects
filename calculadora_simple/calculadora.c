#include <stdio.h>

int main() {
    char operador;
    double num1, num2, resultado;

    // Solicitar al usuario que ingrese la operación
    printf("Ingrese la operación que desea realizar (+, -, *, /): ");
    scanf(" %c", &operador);

    // Solicitar al usuario que ingrese los dos números
    printf("Ingrese el primer número: ");
    scanf("%lf", &num1);

    printf("Ingrese el segundo número: ");
    scanf("%lf", &num2);

    // Realizar la operación según el operador ingresado
    switch(operador) {
        case '+':
            resultado = num1 + num2;
            printf("El resultado de %.2lf + %.2lf es: %.2lf\n", num1, num2, resultado);
            break;
        case '-':
            resultado = num1 - num2;
            printf("El resultado de %.2lf - %.2lf es: %.2lf\n", num1, num2, resultado);
            break;
        case '*':
            resultado = num1 * num2;
            printf("El resultado de %.2lf * %.2lf es: %.2lf\n", num1, num2, resultado);
            break;
        case '/':
            if (num2 != 0) {
                resultado = num1 / num2;
                printf("El resultado de %.2lf / %.2lf es: %.2lf\n", num1, num2, resultado);
            } else {
                printf("Error: División por cero no permitida.\n");
            }
            break;
        default:
            printf("Operador no válido.\n");
            break;
    }

    return 0;
}
