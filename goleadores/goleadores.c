#include <stdio.h>

/*
* Aplicación que permite procesar los goles convertidos por jugadores en distintos equipos de futol.  La aplicación recibe datos del
* jugador a través de terminal para luego de procesar estos datos exponer la tabla de goleadores y el nombre del equipo con mayor
* cantidad de goles.
* Los datos que recibe por terminal son:
* Nombre y apllido del jugador
* Nombre del equipo al que pertenece
* Cantidad de goles en la temporada
*/

// Estructura para almacenar la información de un piloto
struct Jugador {
    char nombre[50];
    char apellido[50];
    char equipo[50];
    int goles;
};

// Función para la carga de los datos del jugador
void cargarDatosPiloto(struct Jugador jugadores[], int num_jugador) {

        /* data */

        for (int i = 0; i < num_jugador; i++) {
            printf("Ingrese el nombre del jugador %d: ", i + 1);
            scanf("%s", jugadores[i].nombre);

            printf("Ingrese el apellido del jugador %d: ", i + 1);
            scanf("%s", jugadores[i].apellido);

            printf("Ingrese el equiop  del jugador %d: ", i + 1);
            scanf("%s", jugadores[i].equipo);

            printf("Ingrese cantidad de goles %d: ", i + 1);
            scanf("%d", &jugadores[i].goles);
        }
};

void ordenarGoleadores(struct Jugador jugadores[], int n){


    struct Jugador temp;
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (jugadores[j].goles > jugadores[j+1].goles) {
                temp = jugadores[j];
                jugadores[j] = jugadores[j+1];
                jugadores[j+1] = temp;
            }
        }
    }
}



void generarTablaPosiciones (struct Jugador jugadores[], int num_jugador){
    

    for (int i = 0; i < num_jugador; i++)
    {
        /* code */
        printf ("nombre jugador %d: %s \n", i + 1, jugadores[i].nombre);
        printf ("nombre apellido %d: %s \n", i + 1, jugadores[i].apellido);
        printf ("nombre equipo %d: %s \n", i + 1, jugadores[i].equipo);
        printf ("goles jugador %d: %d \n", i + 1, &jugadores[i].goles);
    }
    

};

int main () {
    const int num_jugador = 3;
    struct Jugador jugadores[num_jugador];

    cargarDatosPiloto(jugadores, num_jugador);
    ordenarGoleadores(jugadores, num_jugador);
    generarTablaPosiciones(jugadores, num_jugador);

    return 0;

}