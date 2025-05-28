#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char ingrediente[50];
    float monto;
} Compra;

typedef struct {
    char nombre[100];
    int cantidadCompras;
    Compra* compras;
    float totalGastado;
    float saldo; // positivo si debe recibir, negativo si debe pagar
} Participante;

void cargarDatosJuntada(char* fecha, char* menu, char* lugar, int* cantidadParticipantes);
Participante* cargarParticipantes(int cantidad);
void calcularGastos(Participante* participantes, int cantidad, float* totalGasto);
void calcularSaldos(Participante* participantes, int cantidad, float totalGasto);
void mostrarCompensaciones(Participante* participantes, int cantidad);
void liberarMemoria(Participante* participantes, int cantidad);

int main() {
    char fecha[20], menu[100], lugar[100];
    int cantidadParticipantes;
    float totalGasto;

    cargarDatosJuntada(fecha, menu, lugar, &cantidadParticipantes);

    Participante* participantes = cargarParticipantes(cantidadParticipantes);

    calcularGastos(participantes, cantidadParticipantes, &totalGasto);
    calcularSaldos(participantes, cantidadParticipantes, totalGasto);

    printf("\n--- COMPENSACIONES ---\n");
    mostrarCompensaciones(participantes, cantidadParticipantes);

    liberarMemoria(participantes, cantidadParticipantes);
    return 0;
}

// Funciones
void cargarDatosJuntada(char* fecha, char* menu, char* lugar, int* cantidadParticipantes) {
    printf("Ingrese la fecha de la juntada: ");
    fgets(fecha, 20, stdin);
    fecha[strcspn(fecha, "\n")] = 0;

    printf("Ingrese el menu: ");
    fgets(menu, 100, stdin);
    menu[strcspn(menu, "\n")] = 0;

    printf("Ingrese el lugar: ");
    fgets(lugar, 100, stdin);
    lugar[strcspn(lugar, "\n")] = 0;

    printf("Ingrese la cantidad de participantes: ");
    scanf("%d", cantidadParticipantes);
    getchar(); // limpiar buffer
}

Participante* cargarParticipantes(int cantidad) {
    Participante* participantes = malloc(sizeof(Participante) * cantidad);

    for (int i = 0; i < cantidad; i++) {
        printf("\n--- Participante %d ---\n", i + 1);
        printf("Nombre y apellido: ");
        fgets(participantes[i].nombre, 100, stdin);
        participantes[i].nombre[strcspn(participantes[i].nombre, "\n")] = 0;

        printf("Cantidad de compras realizadas: ");
        scanf("%d", &participantes[i].cantidadCompras);
        getchar();

        participantes[i].compras = malloc(sizeof(Compra) * participantes[i].cantidadCompras);
        participantes[i].totalGastado = 0;

        for (int j = 0; j < participantes[i].cantidadCompras; j++) {
            printf("Ingrediente %d: ", j + 1);
            fgets(participantes[i].compras[j].ingrediente, 50, stdin);
            participantes[i].compras[j].ingrediente[strcspn(participantes[i].compras[j].ingrediente, "\n")] = 0;

            printf("Monto: ");
            scanf("%f", &participantes[i].compras[j].monto);
            getchar();

            participantes[i].totalGastado += participantes[i].compras[j].monto;
        }
    }

    return participantes;
}

void calcularGastos(Participante* participantes, int cantidad, float* totalGasto) {
    *totalGasto = 0;
    for (int i = 0; i < cantidad; i++) {
        *totalGasto += participantes[i].totalGastado;
    }
}

void calcularSaldos(Participante* participantes, int cantidad, float totalGasto) {
    float promedio = totalGasto / cantidad;
    for (int i = 0; i < cantidad; i++) {
        participantes[i].saldo = participantes[i].totalGastado - promedio;
    }
}

void mostrarCompensaciones(Participante* participantes, int cantidad) {
    for (int i = 0; i < cantidad; i++) {
        if (participantes[i].saldo < 0) {
            for (int j = 0; j < cantidad; j++) {
                if (participantes[j].saldo > 0) {
                    float deuda = (participantes[i].saldo * -1 < participantes[j].saldo) ? (participantes[i].saldo * -1) : participantes[j].saldo;
                    if (deuda > 0) {
                        printf("%s debe pagar $%.2f a %s\n", participantes[i].nombre, deuda, participantes[j].nombre);
                        participantes[i].saldo += deuda;
                        participantes[j].saldo -= deuda;
                    }
                }
            }
        }
    }
}

void liberarMemoria(Participante* participantes, int cantidad) {
    for (int i = 0; i < cantidad; i++) {
        free(participantes[i].compras);
    }
    free(participantes);
}
