#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

// Definiciones de estructuras
typedef struct {
    int dia;
    int mes;
    int anio;
} Fecha;

typedef struct {
    Fecha fecha;
    char tipo[30];
    float monto;
} Infraccion;

typedef struct {
    char patente[10];
    char marcaModelo[50];
    Infraccion* infracciones;
    int cantidadInfracciones;
} Vehiculo;

typedef struct {
    char nombreApellido[50];
    int dni;
    Vehiculo vehiculo;
} Conductor;

// Funciones auxiliares
Fecha cargarFecha() {
    Fecha fecha;
    printf("Ingrese fecha (dd mm aaaa): ");
    scanf("%d %d %d", &fecha.dia, &fecha.mes, &fecha.anio);
    return fecha;
}

/**
 * This function compares two dates and returns a value indicating their relationship.
 * 
 * @param fecha1 Fecha fecha1: Represents the first date to be compared.
 * @param fecha2 It seems like the description of the `fecha2` parameter is missing. Could you please
 * provide more information about `fecha2` so that I can assist you further with the `compararFechas`
 * function?
 */
int compararFechas(Fecha fecha1, Fecha fecha2) {
    if (fecha1.anio != fecha2.anio)
        return fecha1.anio - fecha2.anio;
    if (fecha1.mes != fecha2.mes)
        return fecha1.mes - fecha2.mes;
    return fecha1.dia - fecha2.dia;
}

/**
 * The function cargarConductor loads information about a driver into a Conductor struct.
 * 
 * @param conductor A pointer to a Conductor object, which is used to store information about a driver
 * or operator.
 */
void cargarConductor(Conductor* conductor) {
    printf("\n--- Carga de Conductor ---\n");
    printf("Nombre y Apellido: ");
    getchar(); // limpiar buffer
    fgets(conductor->nombreApellido, sizeof(conductor->nombreApellido), stdin);
    conductor->nombreApellido[strcspn(conductor->nombreApellido, "\n")] = '\0';

    printf("DNI: ");
    scanf("%d", &conductor->dni);

    printf("\n--- Carga de Vehículo ---\n");
    printf("Patente: ");
    scanf("%s", conductor->vehiculo.patente);

    printf("Marca y Modelo: ");
    getchar();
    fgets(conductor->vehiculo.marcaModelo, sizeof(conductor->vehiculo.marcaModelo), stdin);
    conductor->vehiculo.marcaModelo[strcspn(conductor->vehiculo.marcaModelo, "\n")] = '\0';

    conductor->vehiculo.infracciones = NULL;
    conductor->vehiculo.cantidadInfracciones = 0;

    char opcion;
    do {
        conductor->vehiculo.infracciones = realloc(conductor->vehiculo.infracciones, 
            (conductor->vehiculo.cantidadInfracciones + 1) * sizeof(Infraccion));

        Infraccion* nueva = &conductor->vehiculo.infracciones[conductor->vehiculo.cantidadInfracciones];

        printf("\n--- Infracción %d ---\n", conductor->vehiculo.cantidadInfracciones + 1);
        nueva->fecha = cargarFecha();
        printf("Tipo de infracción (Velocidad, Estacionamiento, Semaforo): ");
        getchar();
        fgets(nueva->tipo, sizeof(nueva->tipo), stdin);
        nueva->tipo[strcspn(nueva->tipo, "\n")] = '\0';

        printf("Monto: ");
        scanf("%f", &nueva->monto);

        conductor->vehiculo.cantidadInfracciones++;

        printf("¿Desea ingresar otra infracción? (s/n): ");
        scanf(" %c", &opcion);
    } while (opcion == 's' || opcion == 'S');
}

/**
 * This function is used to display information about a driver.
 * 
 * @param conductor It seems like the code snippet you provided is incomplete. Could you please provide
 * more context or details about the `Conductor` struct or class so that I can assist you better?
 */
void mostrarConductor(const Conductor* conductor) {
    printf("\n--- Datos del Conductor ---\n");
    printf("Nombre y Apellido: %s\n", conductor->nombreApellido);
    printf("DNI: %d\n", conductor->dni);
    printf("Patente: %s\n", conductor->vehiculo.patente);
    printf("Marca y Modelo: %s\n", conductor->vehiculo.marcaModelo);
    float total = 0;

    if (conductor->vehiculo.cantidadInfracciones == 0) {
        printf("No hay infracciones registradas.\n");
        return;
    }

    for (int i = 0; i < conductor->vehiculo.cantidadInfracciones; i++) {
        Infraccion infraccion = conductor->vehiculo.infracciones[i];
        printf("Infracción %d - Fecha: %02d/%02d/%04d - Tipo: %s - Monto: $%.2f\n", 
            i + 1, infraccion.fecha.dia, infraccion.fecha.mes, infraccion.fecha.anio, infraccion.tipo, infraccion.monto);
        total += infraccion.monto;
    }

    printf("Total de infracciones: %d\n", conductor->vehiculo.cantidadInfracciones);
    printf("Monto total acumulado: $%.2f\n", total);
}

/**
 * This function displays the infractions of a driver within a specified date range.
 * 
 * @param conductor A pointer to a structure representing a driver or conductor.
 * @param FechaDesde The parameter `FechaDesde` represents the starting date from which you want to
 * filter the infractions for a specific driver. This function `mostrarInfraccionesEntreFechas` is
 * designed to display the infractions of a driver within a specified date range, starting from
 * `FechaDesde` and
 * @param fechaHasta The parameter `fechaHasta` represents the end date until which you want to display
 * the infractions for the given driver.
 */
void mostrarInfraccionesEntreFechas(const Conductor* conductor, Fecha FechaDesde, Fecha fechaHasta) {
    int encontrados = 0;
    for (int i = 0; i < conductor->vehiculo.cantidadInfracciones; i++) {
        Infraccion infraccion = conductor->vehiculo.infracciones[i];
        if (compararFechas(infraccion.fecha, FechaDesde) >= 0 && compararFechas(infraccion.fecha, fechaHasta) <= 0) {
            if (!encontrados) {
                printf("\n--- Resultados ---\n");
                printf("Conductor: %s - Patente: %s\n", conductor->nombreApellido, conductor->vehiculo.patente);
            }
            printf("Fecha: %02d/%02d/%04d - Tipo: %s - Monto: $%.2f\n",
                   infraccion.fecha.dia, infraccion.fecha.mes, infraccion.fecha.anio, infraccion.tipo, infraccion.monto);
            encontrados++;
        }
    }

    if (!encontrados) {
        printf("\nNo se encontraron infracciones en el rango indicado.\n");
    }
}

int main() {
    Conductor conductor;
    int opcion;
    int dniBusqueda;

    cargarConductor(&conductor);

    do {
        printf("\n--- Menú ---\n");
        printf("1. Mostrar datos del conductor por DNI\n");
        printf("2. Mostrar infracciones entre fechas\n");
        printf("0. Salir\n");
        printf("Opción: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                printf("Ingrese DNI: ");
                scanf("%d", &dniBusqueda);
                if (dniBusqueda == conductor.dni) {
                    mostrarConductor(&conductor);
                } else {
                    printf("No se encontró conductor con ese DNI.\n");
                }
                break;
            case 2: {
                Fecha desde, hasta;
                printf("Ingrese fecha DESDE:\n");
                desde = cargarFecha();
                printf("Ingrese fecha HASTA:\n");
                hasta = cargarFecha();
                mostrarInfraccionesEntreFechas(&conductor, desde, hasta);
                break;
            }
            case 0:
                printf("Saliendo del programa...\n");
                break;
            default:
                printf("Opción inválida.\n");
        }
    } while (opcion != 0);

    // Liberar memoria
    free(conductor.vehiculo.infracciones);
    return 0;
}
