#include <stdio.h>

int main() {
    int nota;
    int valor_ingresado;
    const int aprobado = 4;

    //Solicitar al usuario el ingreso de la nota
    printf("Ingrese la nota a validar APROBACION o 0 (cero) para terminar: ");
    valor_ingresado = scanf("%d", &nota);

    while (nota != 0 && valor_ingresado == 1){
         if (nota >= aprobado){
            printf("La nota Ingresada esta APROBADA\n");
        } else {
            printf("la nota Ingreesada esta DESAPROBADA\n");
        }
        printf("Ingrese la nota a validar o 0 (cero) para terminar: ");
        valor_ingresado = scanf("%d", &nota);
    }
    printf("Que tengas un buen dia!");
    return 0;
}