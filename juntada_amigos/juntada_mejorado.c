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
    float totalGastado;
    float saldo;
    Compra* compras;
} Participante;

typedef struct {
    char fecha[20];
    char menu[100];
    char lugar[100];
    int cantidadParticipantes;
    Participante* participantes;
} Juntada;

// Prototipos
void cargarDatosJuntada(Juntada* juntada);
void cargarParticipantes(Juntada* juntada);
void calcularGastosYPromedio(Juntada* juntada, float* promedio);
void calcularSaldos(Juntada* juntada, float promedio);
void mostrarCompensaciones(Juntada* juntada);
void liberarMemoria(Juntada* juntada);

/**
 * Un grupo de amigos se reúne a comer, y cada uno realiza una o varias compras para preparar el evento. 
 * Al finalizar, desean repartir los gastos de forma equitativa. Para esto, cada uno informa lo que 
 * compró (ingredientes y montos), y luego el sistema calcula cuánto debería aportar cada uno para que 
 * todos paguen la misma cantidad.
 */
int main() {
    Juntada juntada;
    float totalGastado, promedio;

    cargarDatosJuntada(&juntada);
    cargarParticipantes(&juntada);

    calcularGastosYPromedio(&juntada, &promedio);
    calcularSaldos(&juntada, promedio);

    printf("\n--- RESUMEN DE COMPENSACIONES ---\n");
    mostrarCompensaciones(&juntada);
    liberarMemoria(&juntada);
    return 0;
}

// Implementación de las funciones


/**
 * This function is used to load data for a gathering.
 * 
 * @param juntada A pointer to a structure representing a gathering or event.
 */
void cargarDatosJuntada(Juntada* juntada) {
    printf("Ingrese la fecha de la juntada: ");
    fgets(juntada->fecha, sizeof(juntada->fecha), stdin);
    juntada->fecha[strcspn(juntada->fecha, "\n")] = 0;

    printf("Ingrese el menú: ");
    fgets(juntada->menu, sizeof(juntada->menu), stdin);
    juntada->menu[strcspn(juntada->menu, "\n")] = 0;

    printf("Ingrese el lugar: ");
    fgets(juntada->lugar, sizeof(juntada->lugar), stdin);
    juntada->lugar[strcspn(juntada->lugar, "\n")] = 0;

    printf("Ingrese la cantidad de participantes: ");
    scanf("%d", &juntada->cantidadParticipantes);
    getchar(); // limpiar buffer
}

/**
 * The function "cargarParticipantes" loads participants into a gathering structure.
 * 
 * @param juntada Juntada is a pointer to a structure or object that represents a gathering or event.
 */
void cargarParticipantes(Juntada* juntada) {

    // Asigno dinámicamente la memoria en función a la cantidad de Participantes indicada por el usuario.
    juntada->participantes = malloc(juntada->cantidadParticipantes * sizeof(Participante));

    for (int i = 0; i < juntada->cantidadParticipantes; i++) {
        Participante* participantes = &juntada->participantes[i];

        printf("\n--- Participante %d ---\n", i + 1);
        printf("Nombre y apellido: ");
        fgets(participantes->nombre, sizeof(participantes->nombre), stdin);
        participantes->nombre[strcspn(participantes->nombre, "\n")] = 0;

        printf("Cantidad de compras: ");
        scanf("%d", &participantes->cantidadCompras);
        getchar();

        // Asigno dinámicamente la memoria en función a la cantidad de Compras realizadas por el participante.
        participantes->compras = malloc(participantes->cantidadCompras * sizeof(Compra));
        participantes->totalGastado = 0;

        for (int j = 0; j < participantes->cantidadCompras; j++) {
            printf("Ingrediente %d: ", j + 1);
            fgets(participantes->compras[j].ingrediente, sizeof(participantes->compras[j].ingrediente), stdin);
            participantes->compras[j].ingrediente[strcspn(participantes->compras[j].ingrediente, "\n")] = 0;

            printf("Monto: ");
            scanf("%f", &participantes->compras[j].monto);
            getchar();

            // Aprovecho el flujo para ya registrar el total gastado por el participante
            participantes->totalGastado += participantes->compras[j].monto;
        }
    }
}

/**
 * This function calculates the total expenses of a gathering and the average expense per person.
 * 
 * @param juntada Juntada is a struct or class that likely contains information about a gathering or
 * event, such as expenses incurred by participants.
 * @param promedio The `calcularGastosYPromedio` function takes a pointer to a `Juntada` struct and a
 * pointer to a float variable `promedio`. The function is likely designed to calculate the total
 * expenses of the `Juntada` and then calculate the average expense per person, storing
 */
void calcularGastosYPromedio(Juntada* juntada, float* promedio) {
    float total = 0;
    for (int i = 0; i < juntada->cantidadParticipantes; i++) {
        total += juntada->participantes[i].totalGastado;
    }
    // Promedio: representa lo que cada participante debe pagar por la junatada
    *promedio = total / juntada->cantidadParticipantes;
}

/**
 * This function calculates the balances for a group based on a given average amount.
 * 
 * @param juntada The parameter `juntada` is a pointer to a structure or object of type `Juntada`.
 * @param promedio The parameter `promedio` is a float value representing the average amount of money
 * each participant should contribute to the Juntada.
 */
void calcularSaldos(Juntada* juntada, float promedio) {
    for (int i = 0; i < juntada->cantidadParticipantes; i++) {
        juntada->participantes[i].saldo = juntada->participantes[i].totalGastado - promedio;
    }
}

/**
 * The function "mostrarCompensaciones" displays compensations for a gathering.
 * 
 * @param juntada A pointer to a struct representing a gathering or event.
 */
void mostrarCompensaciones(Juntada* juntada) {
    Participante* participantes = juntada->participantes;
    int n = juntada->cantidadParticipantes;

    for (int i = 0; i < n; i++) {
        if (participantes[i].saldo < 0) { //Deudores
            for (int j = 0; j < n; j++) {
                if (participantes[j].saldo > 0) { //Acreedores
                    float deuda = (participantes[i].saldo * -1 < participantes[j].saldo) ? -participantes[i].saldo : participantes[j].saldo;
                    if (deuda > 0.01) { // evitar decimales mínimos
                        printf("%s debe pagar $%.2f a %s\n", participantes[i].nombre, deuda, participantes[j].nombre);
                        participantes[i].saldo += deuda;
                        participantes[j].saldo -= deuda;
                    }
                }
            }
        }
    }
}

void liberarMemoria(Juntada* juntada) {
    for (int i = 0; i < juntada->cantidadParticipantes; i++) {
        free(juntada->participantes[i].compras);
    }
    free(juntada->participantes);
}
