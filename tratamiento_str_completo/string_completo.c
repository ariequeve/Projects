#include <stdio.h>
#include <string.h>

/*
El programa debe solicitar al usuario:
- su nombre, 
- apellido, 
- edad
- 3 calificaciones obtenida en su cursada. 

A partir de esa información, el programa debe realizar lo siguiente:
    1.A. Unir el nombre y el apellido en una sola variable llamada nombre_completo.
    1.B. Mostrar un saludo personalizado usando nombre_completo, por ejemplo: "Hola, Juan Pérez".
    2.A. Calcular el promedio de tres calificaciones ingresadas por el usuario y mostrarlo.
    3.A. Determinar si el estudiante es mayor de edad (18 años o más) y mostrar un mensaje indicando si es
            adulto o no.
    3.B. Determinar si el promedio de las calificaciones es mayor o igual a 6.0 y, en ese caso, mostrar un mensaje
            que indique si el estudiante aprobó o reprobó el curso.
*/

int main() {
    
    // Declaro variables
    char nombreAlumno[30];
    char apellidoAlumno[30];
    char nombre_completo[60] = "";
    int edadAlumno, i;
    
    // Utilizo un array de calificaciones y declaro la constante cantCalificaciones para calcular el promedio
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

    // 1.A. Unir el nombre y el apellido en una sola variable llamada nombre_completo.
    strcat(nombre_completo, nombreAlumno);
    strcat(nombre_completo," ");
    strcat(nombre_completo, apellidoAlumno);

    // 1.B. Mostrar un saludo personalizado usando nombre_completo, por ejemplo: "Hola, Juan Pérez".
    printf("Hola:  %s\n", nombre_completo);

    // 2.A. Calcular el promedio de tres calificaciones ingresadas por el usuario y mostrarlo.
    int total_calificaciones, promedio;
    for (i = 0; i < cantCalificaciones; i++)
    {
        /* code */
        total_calificaciones += calificaciohnes[i];
    }
    promedio = total_calificaciones/i;
    printf("El Promedio de Calificaciones es:  %d\n", promedio);

    // 3.A. Determinar si el estudiante es mayor de edad (18 años o más) y mostrar un mensaje indicando si es adulto o no.
    if (edadAlumno >= 18){
        printf("El Alumno es Mayor de edad \n");
    } else {
        printf("El Alumno es Menor de edad \n");
    }

    /*3.B. Determinar si el promedio de las calificaciones es mayor o igual a 6.0 y, en ese caso, mostrar un mensaje
            que indique si el estudiante aprobó o reprobó el curso. */
    if (promedio > 6) {
        printf("El Alumno APROBO la materia \n");
    } else {
        printf("El Alumno NO APROBO la materia \n");
    }
    
    return 0;
}