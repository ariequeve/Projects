#include <stdio.h>
/* Aplicación que calcula el MCD a partir del ingreso de dos números por teclad */
int main() {
    int a, b, mcd;

    printf("Ingrese dos números enteros: ");
    scanf("%d %d", &a, &b);

    // Se aplica función Euclidea para calcular el MCD de dos números
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    mcd = a;

    // Se indica por pantalla el valor MCD obtenido
    printf("El MCD es: %d\n", mcd);

    return 0;
}
