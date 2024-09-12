#include<stdio.h>   
#include<string.h>  
                    
int main(){

char primCadena[50];
char segCadena[50];
int longCad1;
int longCad2;
int longCadConcat;


printf("Escriba la primera palabra:");
scanf("%s", primCadena);
printf("escriba la segunda palabra:");
scanf("%s", segCadena);


//indique cadena mayor longitud
/*
longCad1 = strlen(primCadena);
longCad2 = strlen(segCadena);


if (longCad1>longCad2){
    printf("La primera cadena es la mas larga\n");
}else{
    printf("La segunda cadena es la mas larga\n");
}
*/

if (strlen(primCadena)>strlen(segCadena)){
    printf("La primera palabra %s es la mas larga\n", primCadena);
} else {
    printf("La primera palabra %s es la mas larga\n", segCadena);
}

//concatene ambas cadenas e indique la longitud total
strcat (primCadena, segCadena);  
longCadConcat = strlen(primCadena);                //el compilador concatena y deja la palabra concatenada en string1
printf("La longitud total es %d caracteres\n", longCadConcat);


//Copie el valor de la segunda cadena en la primera y muestre su valor
strcpy(primCadena, segCadena);                     // el compilador copia y deja la info en string1
printf("La cadena copiada es %s \n", primCadena);

return 0;
}