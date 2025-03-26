#include <stdio.h>
#include <string.h>

// Definimos el struct Cliente para almacenar la información de cada cliente
typedef struct {
    char nombre[50];
    char apellido[50];
    char destino[50];
    int paquete;
    int dias_estadia;
    float costo_total;
} Cliente;

const int num_clientes = 5;

// Prototipos de las funciones
float calcularCostoTotal(int paquete, int dias_estadia);
void ordenarClientesPorCosto(Cliente clientes[], int num_clientes);
void imprimirInforme(Cliente clientes[], int num_clientes);

int main() {
    Cliente clientes[num_clientes];

    // Captura de datos
    for (int i = 0; i < num_clientes; i++) {
        printf("Ingrese el nombre del cliente %d: ", i + 1);
        scanf("%s", clientes[i].nombre);
        printf("Ingrese el apellido del cliente %d: ", i + 1);
        scanf("%s", clientes[i].apellido);
        printf("Ingrese el destino del cliente %d: ", i + 1);
        scanf("%s", clientes[i].destino);
        printf("Seleccione el paquete (1: Básico, 2: Premium, 3: VIP): ");
        scanf("%d", &clientes[i].paquete);
        printf("Ingrese los días de estadía: ");
        scanf("%d", &clientes[i].dias_estadia);

        // Calcula el costo total con el paquete y días seleccionados
        clientes[i].costo_total = calcularCostoTotal(clientes[i].paquete, clientes[i].dias_estadia);
    }

    // Ordenamos los clientes por costo total
    ordenarClientesPorCosto(clientes, num_clientes);

    // Imprimimos el informe de clientes ordenados
    imprimirInforme(clientes, num_clientes);

    return 0;
}

// Función para calcular el costo total en función del paquete y días de estadía
float calcularCostoTotal(int paquete, int dias_estadia) {
    float costo_base;
    float descuento = 0;

    switch (paquete) {
        case 1:  // Paquete Básico
            costo_base = 100.0;
            break;
        case 2:  // Paquete Premium
            costo_base = 200.0;
            if (dias_estadia > 7) {
                descuento = 0.10;  // 10% de descuento
            }
            break;
        case 3:  // Paquete VIP
            costo_base = 400.0;
            if (dias_estadia > 5) {
                descuento = 0.15;  // 15% de descuento
            }
            break;
        default:
            printf("Paquete inválido.\n");
            return 0;
    }

    float costo_total = costo_base * dias_estadia * (1 - descuento);
    return costo_total;
}

// Función para ordenar clientes por costo total (de menor a mayor)
void ordenarClientesPorCosto(Cliente clientes[], int num_clientes) {
    for (int i = 0; i < num_clientes - 1; i++) {
        for (int j = i + 1; j < num_clientes; j++) {
            if (clientes[i].costo_total > clientes[j].costo_total) {
                Cliente temp = clientes[i];
                clientes[i] = clientes[j];
                clientes[j] = temp;
            }
        }
    }
}

// Función para imprimir el informe de clientes
void imprimirInforme(Cliente clientes[], int num_clientes) {
    printf("\n--- Informe de Clientes Ordenados por Costo Total ---\n");

    for (int i = 0; i < num_clientes; i++) {
        printf("Cliente: %s %s\n", clientes[i].nombre, clientes[i].apellido);
        printf("Destino: %s\n", clientes[i].destino);
        printf("Paquete: ");
        switch (clientes[i].paquete) {
            case 1:
                printf("Básico\n");
                break;
            case 2:
                printf("Premium\n");
                break;
            case 3:
                printf("VIP\n");
                break;
            default:
                printf("Desconocido\n");
                break;
        }
        printf("Días de estadía: %d\n", clientes[i].dias_estadia);
        printf("Costo Total: $%.2f\n", clientes[i].costo_total);
        printf("---------------------------------\n");
    }

    printf("\nCliente con el paquete más económico: %s %s\n", clientes[0].nombre, clientes[0].apellido);
    printf("Cliente con el paquete más costoso: %s %s\n", clientes[num_clientes - 1].nombre, clientes[num_clientes - 1].apellido);
}
