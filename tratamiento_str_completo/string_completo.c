#include <stdio.h>

/*
El programa debe solicitar al usuario:
- su nombre, 
- apellido, 
- edad
- 3 calificaciones 
obtenida en su cursada. A partir de esa información, el programa debe realizar lo siguiente:
*/

int main() {
    
    // Declaro variables
    char nombreAlumno[30];
    char apellidoAlumno[30];
    int edadAlumno;
    const int cantCalificaciones = 3;
    int calificaciohnes[3];

    // Solicito datos al usuario por teclado en terminal
    printf("Ingrese NOMMBRE del Alumno: \n");
    scanf("%s", nombreAlumno);

    printf("Ingrese APELLIDO del Alumno: \n");
    scanf("%s", apellidoAlumno);

    printf("Ingrese EDAD del Alumno: \n");
    scanf("%d", &edadAlumno);

    
    printf("Ingrese 3 CALIFICACIONES del Alumno: \n");

    // Bucle para la carga de 3 calificaciones
    for (int i = 0; i < cantCalificaciones; i++)
    {
        /* code */
        printf("Calificacion %d: \n", i + 1);
        scanf("%d", &calificaciohnes[i]);
    }
    
    printf("Los datos del Alumno son Nombre:  %s - Apellido: %s - Edad: %d \n", nombreAlumno, apellidoAlumno, edadAlumno);
    printf("Sus calificaciones son: Nota 1: %d / Nota 2: %d / Nota 3: %d \n", calificaciohnes[0], calificaciohnes[1], calificaciohnes[2]);
    
    return 0;
}