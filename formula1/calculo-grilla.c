#include <stdio.h>
#include <string.h>

//#define NUM_PILOTOS 5

// Estructura para almacenar la información de un piloto
struct Piloto {
    char nombre[50];
    char apellido[50];
    char escuderia[50];
    char circuito[50];
    float tiempos[3];  // Q1, Q2, Q3
    float mejorTiempo; // Mejor tiempo entre Q1, Q2, Q3
};

// Función para la carga de los datos
void cargarDatosPiloto(struct Piloto pilotos[], int num_pilotos) {
        for (int i = 0; i < num_pilotos; i++) {
            printf("Ingrese el nombre del piloto %d: ", i + 1);
            scanf("%s", pilotos[i].nombre);

            printf("Ingrese el apellido del piloto %d: ", i + 1);
            scanf("%s", pilotos[i].apellido);

            printf("Ingrese la escudería del piloto %d: ", i + 1);
            scanf("%s", pilotos[i].escuderia);

            printf("Ingrese el circuito donde corrió el piloto %d: ", i + 1);
            scanf("%s", pilotos[i].circuito);

            printf("Ingrese los tiempos del piloto %d en Q1, Q2 y Q3 (en segundos):\n", i + 1);
            for (int j = 0; j < 3; j++) {
                printf("Tiempo Q%d: ", j + 1);
                scanf("%f", &pilotos[i].tiempos[j]);
            }
        }
}

// Función para calcular el mejor tiempo de un piloto
float calcularMejorTiempo(float tiempos[]) {
    float mejor = tiempos[0];
    for (int i = 1; i < 3; i++) {
        if (tiempos[i] < mejor) {
            mejor = tiempos[i];
        }
    }
    return mejor;
}

// Función para ordenar los pilotos por mejor tiempo (Alg de ordenamiento burbuja)
void ordenarPilotos(struct Piloto pilotos[], int n) {
    struct Piloto temp;
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (pilotos[j].mejorTiempo > pilotos[j+1].mejorTiempo) {
                temp = pilotos[j];
                pilotos[j] = pilotos[j+1];
                pilotos[j+1] = temp;
            }
        }
    }
}

// Funcion para mostrar en pantalla la Grilla de salida
void muestroGrilla(struct Piloto pilotos[], int num_pilotos) {
    printf("Grilla de salida:\n");
    for (int i = 0; i < num_pilotos; i++) {
        printf("Posicion %d: %s %s, Escudería: %s, Circuito: %s, Mejor tiempo: %.2f segundos\n",
               i + 1, pilotos[i].nombre, pilotos[i].apellido, pilotos[i].escuderia, pilotos[i].circuito, pilotos[i].mejorTiempo);
    }
}

//Aplicacion que calcula la Grilla de partida en funcion de los tiempos de clasificacion de los piolotos
int main() {
    const int num_pilotos = 3;
    struct Piloto pilotos[num_pilotos];

    // Cargo los datos de los pilotos con la funcion cargarDatosPiloto()
    cargarDatosPiloto(pilotos, num_pilotos);

    // Calculo el mejor tiempo del piloto ejecutando la función calcularMejorTiempo()
    for (int i = 0; i < num_pilotos; i++){
        pilotos[i].mejorTiempo = calcularMejorTiempo(pilotos[i].tiempos);
        printf("\n");   
    }
    
    // Ordeno los pilotos por el mejor tiempo con la funcion ordenarPilotos()
    ordenarPilotos(pilotos, num_pilotos);

    // Mostrar la grilla de salid:
    muestroGrilla(pilotos, num_pilotos);

    return 0;
}