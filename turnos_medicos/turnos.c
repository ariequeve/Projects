#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NOMBRE 50
#define MAX_ESPECIALIDAD 30
#define MAX_FECHA 11

typedef struct {
    char especialidad[MAX_ESPECIALIDAD];
    char fecha[MAX_FECHA];
    int tipoPrestacion; // 1 = Consulta, 2 = Estudios, 3 = Vacunación
} Turno;

typedef struct {
    int nroAfiliado;
    char nombre[MAX_NOMBRE];
    int edad;
    char genero;
    Turno* turno; // NULL me permite indicar que un paciente no tiene turno asignado.
} Paciente;

/**
 * Esta función carga un número específico de pacientes en memoria.
 * 
 * @param n El parámetro "n" representa la cantidad de pacientes que el usuario desea cargar en el sistema.
 */
Paciente* cargarPacientes(int n) {
    Paciente* pacientes = (Paciente*)malloc(n * sizeof(Paciente));
    if (pacientes == NULL) {
        printf("Error al asignar memoria\n");
        exit(1);
    }

    for (int i = 0; i < n; i++) {
        printf("\nPaciente %d\n", i + 1);
        printf("Número de afiliado: ");
        scanf("%d", &pacientes[i].nroAfiliado);
        getchar();
        printf("Nombre: ");
        fgets(pacientes[i].nombre, MAX_NOMBRE, stdin);
        pacientes[i].nombre[strcspn(pacientes[i].nombre, "\n")] = '\0';
        printf("Edad: ");
        scanf("%d", &pacientes[i].edad);
        printf("Género (M/F/X): ");
        scanf(" %c", &pacientes[i].genero);
        pacientes[i].turno = NULL;
    }
    return pacientes;
}

/**
 * La función asignarTurnos() asigna turnos al paciente.
 * 
 * @param pacientes Puntero al array de pacientes.
 * @param n El parámetro "n" representa el número de pacientes en el array pacientes. Este valor
 *  indica el tamaño del array y ayuda a iterar a través de la lista de pacienters para asignar los turnos a cada paciente
 */
void asignarTurnos(Paciente* pacientes, int n) {
    for (int i = 0; i < n; i++) {
        char opcion;
        printf("\n¿Desea asignar turno al paciente %s (Afiliado %d)? (s/n): ", pacientes[i].nombre, pacientes[i].nroAfiliado);
        scanf(" %c", &opcion);

        if (opcion == 's' || opcion == 'S') {
            pacientes[i].turno = (Turno*)malloc(sizeof(Turno));
            if (pacientes[i].turno == NULL) {
                printf("Error al asignar memoria para el turno\n");
                exit(1);
            }

            printf("Especialidad: ");
            getchar();
            fgets(pacientes[i].turno->especialidad, MAX_ESPECIALIDAD, stdin);
            pacientes[i].turno->especialidad[strcspn(pacientes[i].turno->especialidad, "\n")] = '\0';

            printf("Fecha (dd/mm/aaaa): ");
            fgets(pacientes[i].turno->fecha, MAX_FECHA, stdin);
            pacientes[i].turno->fecha[strcspn(pacientes[i].turno->fecha, "\n")] = '\0';

            printf("Tipo de prestación (1=Consulta, 2=Estudios, 3=Vacunación): ");
            scanf("%d", &pacientes[i].turno->tipoPrestacion);
        }
    }
}

/**
 * Esta función enumera los turnos de los pacientes en una lista determinada.
 * 
 * @param pacientes El parámetro "pacientes" es un puntero a un array de tipo Paciente, que representa una * lista de pacientes.
 * 
 * @param n El parámetro `n` representa el número de elementos en el array `lista` de tipo
 * `Paciente`. Este parámetro se utiliza para determinar el tamaño del array e iterar sobre cada elemento
 * para listar los turnos.
 */
void listarTurnos(Paciente* pacientes, int n) {
    printf("\n--- Listado de turnos asignados ---\n");
    for (int i = 0; i < n; i++) {
        if (pacientes[i].turno != NULL) {
            printf("Afiliado %d - %s\n", pacientes[i].nroAfiliado, pacientes[i].nombre);
            printf("  Especialidad: %s\n", pacientes[i].turno->especialidad);
            printf("  Fecha: %s\n", pacientes[i].turno->fecha);
            printf("  Prestación: ");
            switch (pacientes[i].turno->tipoPrestacion) {
                case 1: printf("Consulta\n"); break;
                case 2: printf("Estudios\n"); break;
                case 3: printf("Vacunación\n"); break;
                default: printf("Desconocida\n"); break;
            }
        }
    }
}

/**
 * The function "mostrarEstadisticas" muestra estadísticas para un conjunto de pacientes.
 * 
 * @param pacientesEl parámetro "pacientes" apunta a una array de tipo "Paciente", que  
 * representa una colección de registros o datos de pacientes.
 * 
 * @param n El parámetro `n` representa el número de elementos en la matriz de objetos `Paciente`.
 * Este parámetro se utiliza para determinar el tamaño de la matriz e iterar sobre cada elemento para mostrar
 * las estadísticas de cada paciente.
 */
void mostrarEstadisticas(Paciente* pacientes, int n) {
    int total = 0, consultas = 0, estudios = 0, vacunaciones = 0;
    int maxEdad = -1;
    char* nombreMayor = NULL;

    for (int i = 0; i < n; i++) {
        if (pacientes[i].turno != NULL) {
            total++;
            switch (pacientes[i].turno->tipoPrestacion) {
                case 1: consultas++; break;
                case 2: estudios++; break;
                case 3: vacunaciones++; break;
            }
            if (pacientes[i].edad > maxEdad) {
                maxEdad = pacientes[i].edad;
                nombreMayor = pacientes[i].nombre;
            }
        }
    }

    printf("\n--- Estadísticas ---\n");
    printf("Total de turnos: %d\n", total);
    if (total > 0) {
        printf("%% Consulta: %.2f%%\n", (consultas * 100.0) / total);
        printf("%% Estudios: %.2f%%\n", (estudios * 100.0) / total);
        printf("%% Vacunación: %.2f%%\n", (vacunaciones * 100.0) / total);
        printf("Paciente de mayor edad con turno: %s (%d años)\n", nombreMayor, maxEdad);
    }
}

/**
* Esta función busca un paciente con un número de afiliación específico en un array de pacientes.
*
* @param pacientes El parámetro "pacientes" apunta a un array de tipo "Paciente", que 
* representa una colección de pacientes.
* @param n El parámetro `n` representa el número de elementos del array de pacientes (`Paciente*
* pacientes`). Este valor indica el tamaño del array en el que se debe buscar para encontrar un
* paciente con el `nroAfiliado` especificado.
* @param nroAfiliado El parámetro `nroAfiliado` es un entero que representa el número de afiliación del
* paciente. Se utiliza para buscar un paciente específico en un array de pacientes según su
* número de afiliación.
 */
void buscarPaciente(Paciente* pacientes, int n, int nroAfiliado) {
    for (int i = 0; i < n; i++) {
        if (pacientes[i].nroAfiliado == nroAfiliado) {
            printf("\nNombre: %s\nEdad: %d\nGénero: %c\n", pacientes[i].nombre, pacientes[i].edad, pacientes[i].genero);
            if (pacientes[i].turno != NULL) {
                printf("Turno asignado - Especialidad: %s, Fecha: %s, Prestación: ",
                       pacientes[i].turno->especialidad, pacientes[i].turno->fecha);
                switch (pacientes[i].turno->tipoPrestacion) {
                    case 1: printf("Consulta\n"); break;
                    case 2: printf("Estudios\n"); break;
                    case 3: printf("Vacunación\n"); break;
                }
            } else {
                printf("No tiene turno asignado.\n");
            }
            return;
        }
    }
    printf("Paciente no encontrado.\n");
}

/**
* Esta función se utiliza para liberar memoria asignada a un array de estructuras de Paciente.
*
* @param pacientes Un puntero a un array de estructuras de Paciente.
* @param n El parámetro `n` representa el número de elementos del array de Paciente
* para los que se desea liberar memoria. Este parámetro ayuda a determinar el tamaño del bloque de memoria
* que debe liberarse.
*/
void liberarMemoria(Paciente* pacientes, int n) {
    for (int i = 0; i < n; i++) {
        if (pacientes[i].turno != NULL) {
            free(pacientes[i].turno);
        }
    }
    free(pacientes);
}

/**
* Enunciado - Sistema de Gestión de Turnos y Prestaciones Médicas
*
* La obra social Salud Total S.A. necesita una aplicación en C que permita registrar 
* información básica de pacientes, asignarles turnos médicos, y calcular algunas estadísticas 
* sobre los servicios prestados. La aplicación será utilizada por operadores administrativos desde una terminal (cmd).
*/
int main() {
    int cantidad;
    printf("Ingrese la cantidad de pacientes a cargar: ");
    scanf("%d", &cantidad);

    Paciente* pacientes = cargarPacientes(cantidad);

    int opcion;
    do {
        printf("\nMenu:\n");
        printf("1. Asignar turnos\n");
        printf("2. Listar turnos\n");
        printf("3. Mostrar estadísticas\n");
        printf("4. Buscar paciente\n");
        printf("5. Salir\n");
        printf("Opción: ");
        scanf("%d", &opcion);

        switch(opcion) {
            case 1: asignarTurnos(pacientes, cantidad); break;
            case 2: listarTurnos(pacientes, cantidad); break;
            case 3: mostrarEstadisticas(pacientes, cantidad); break;
            case 4: {
                int nro;
                printf("Ingrese número de afiliado: ");
                scanf("%d", &nro);
                buscarPaciente(pacientes, cantidad, nro);
                break;
            }
            case 5: printf("Saliendo del sistema.\n"); break;
            default: printf("Opción inválida.\n");
        }
    } while(opcion != 5);

    liberarMemoria(pacientes, cantidad);
    return 0;
}