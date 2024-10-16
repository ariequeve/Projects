#include <stdio.h>
#include <string.h>

/*
* Aplicación que permite procesar los goles convertidos por jugadores en distintos equipos de futbol.  La aplicación recibe datos del
* jugador a través de terminal para luego de procesar estos datos exponer la tabla de goleadores y el nombre del equipo con mayor
* cantidad de goles.
* Los datos que recibe por terminal son:
* Nombre y apllido del jugador
* Nombre del equipo al que pertenece
* Cantidad de goles en la temporada
*/

// Estructura para almacenar la información de los equipos
struct Equipo {
    char nombre_equipo[50];
    int cantidad_goles;
};

// Estructura para almacenar la información de un jugador
struct Jugador {
    char nombre[50];
    char apellido[50];
    char equipo[50];
    //struct Equipo equipo;
    int cant_goles;
};

// Función para la carga de los datos del jugador
void cargarDatosJugadores(struct Jugador jugadores[], int num_jugador, struct Equipo equipos[]) {

        /* data */
        int num_equipos = 0;    
        for (int i = 0; i < num_jugador; i++) {
            printf("\nIngrese el nombre del jugador %d: ", i + 1);
            scanf("%s", jugadores[i].nombre);

            printf("Ingrese el apellido del jugador %d: ", i + 1);
            scanf("%s", jugadores[i].apellido);

            printf("Ingrese el equiop  del jugador %d: ", i + 1);
            scanf("%s", jugadores[i].equipo);

            printf("Ingrese cantidad de goles %d: ", i + 1);
            scanf("%d", &jugadores[i].cant_goles);

            // Verificar si el equipo ya está en la lista de equipos
            int equipo_existe = 0;
            for (int j = 0; j < num_equipos; j++) {
                if (strcmp(equipos[j].nombre_equipo, jugadores[i].equipo) == 0) {
                    equipos[j].cantidad_goles += jugadores[i].cant_goles;
                    equipo_existe = 1;
                    break;
                }
            }

            // Si el equipo no existe, lo agregamos
            if (!equipo_existe) {
                strcpy(equipos[num_equipos].nombre_equipo, jugadores[i].equipo);
                equipos[num_equipos].cantidad_goles = jugadores[i].cant_goles;
                num_equipos++;
            }
        }


};

// Función para la obtencion del equipo goleador
void equipoGoleador (struct Equipo equipos[], int num_equipos){
    
    // Determinar el equipo con más goles
    int max_goles = 0;
    struct Equipo equipo_mayor_goles;
    for (int i = 0; i < num_equipos; i++) {
        if (equipos[i].cantidad_goles > max_goles) {
            max_goles = equipos[i].cantidad_goles;
            strcpy(equipo_mayor_goles.nombre_equipo,equipos[i].nombre_equipo);
            equipo_mayor_goles.cantidad_goles = equipos[i].cantidad_goles;
        }
    }
    printf("\nEl Equipo Golador es: %s con %d goles: \n", equipo_mayor_goles.nombre_equipo, equipo_mayor_goles.cantidad_goles);
}

// Función para ordenar jugador segun cantidad de goles
void ordenarGoleadores(struct Jugador jugadores[], int n){


    struct Jugador temp;
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (jugadores[j].cant_goles < jugadores[j+1].cant_goles) {
                temp = jugadores[j];
                jugadores[j] = jugadores[j+1];
                jugadores[j+1] = temp;
            }
        }
    }
}

// Función para presentar tabla de goleadores
void generarTablaPosiciones (struct Jugador jugadores[], int num_jugador){
    
    printf("\nTABLA DE GOLEADORES:\n");
    for (int i = 0; i < num_jugador; i++) {
        printf("%d.: %s %s, %s, Cantidad de Goles: %d\n",
               i + 1, jugadores[i].nombre, jugadores[i].apellido, jugadores[i].equipo, jugadores[i].cant_goles);      
    }
    
};

int main () {

    const int num_jugadores = 5, num_equipos = 5;
    struct Jugador jugadores[num_jugadores];
    struct Equipo equipos[num_equipos];

    cargarDatosJugadores(jugadores, num_jugadores, equipos);
    ordenarGoleadores(jugadores, num_jugadores);
    generarTablaPosiciones(jugadores, num_jugadores);
    equipoGoleador(equipos, num_equipos);

    return 0;

}