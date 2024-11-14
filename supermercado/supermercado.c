/*
    Desarrollar un programa en lenguaje C que permita realizar la siguiente operación:
    Al iniciar el programa, el sistema debe solicitar el nombre y apellido del cliente.
    A continuación, el sistema mostrará un menú con 3 productos disponibles, cada uno identificado con un número y acompañado de su precio.
    El cliente podrá seleccionar un producto ingresando el número correspondiente y luego la cantidad que desea comprar.
    El cliente puede seguir eligiendo productos hasta que ingrese 0 para salir del menú.
    Una vez finalizada la selección de productos, el sistema preguntará al cliente por el método de pago:
    A: Efectivo (con un 10% de descuento).
    B: Crédito (sin descuento).
    El sistema mostrará en pantalla un resumen con:
    Datos del cliente.
    Lista de productos seleccionados.
    Monto total de la compra (aplicando el descuento si corresponde).
    Método de pago elegido.

*/

/*
    FEcha:
    Author: @author Ariel Quevedo
    Descripción: 
    Paramentros: 
    Retorno


*/

#include <stdio.h>

int main() {

    // declaro variable nombre del cliente c[50]
    // declaro variable nombre del cliente nombre_cliente[50]
    char nombre_cliente[50], metodoPago;
    int producto, cantidad, totalProductos = 0;
    float total = 0, descuento = 0, totalFinal = 0;
    
    // Defino las variables para Precios de los productos y cantidades
    float precios[] = {100.0, 200.0, 150.0, 350.0};
    int cantidades[] = {0, 0, 0, 0};

    // Defino la constante para el pago en efectivo
    float const descuento_efectivo = 0.10;

    // Pido nombre del cliente
    printf("Ingrese el nombre del cliente: ");
    scanf("%s", nombre_cliente);

    // Muestro menú y proceso la selección de productos
    do {
        printf("\nSeleccione un producto:\n");
        printf("1. Producto A - $100\n");
        printf("2. Producto B - $200\n");
        printf("3. Producto C - $150\n");
        printf("4. Producto C - $350\n");
        printf("0. Salir\n");
        printf("Ingrese el número del producto: ");
        scanf("%d", &producto);

        if (producto >= 1 && producto <= 4) {
            printf("Ingrese la cantidad: ");
            scanf("%d", &cantidad);
            total += precios[producto - 1] * cantidad;
            cantidades[producto - 1] += cantidad;
            totalProductos++;
        }
    } while (producto != 0);

    // Si no se seleccionaron productos, terminar el programa
    if (totalProductos == 0) {
        printf("No se seleccionaron productos. Fin del programa.\n");
        return 0;
    }

    // Selección de método de pago
    printf("\nElija el método de pago:\n");
    printf("A. Efectivo incluye 10%% de descuento\n");
    printf("B. Crédito\n");
    printf("Seleccione el método de pago (A/B): ");
    scanf(" %c", &metodoPago);

    // Calculo descuento si aplica
    if (metodoPago == 'A' || metodoPago == 'a') {
        //descuento = total * 0.10;
        //descuento = total * 0.10; // Debo siempre evitar el HARDCODING
        descuento = total * descuento_efectivo;
    }
    
    totalFinal = total - descuento;

    // Muestro el resumen de compra
    printf("\n--- RESUMEN DE COMPRA ---\n");
    printf("Cliente: %s", nombre_cliente);
    printf("Productos comprados:\n");

    int tamanioArray = sizeof(cantidades) / sizeof(cantidades[0]);
    for (int i = 0; i < tamanioArray; i++)
    {
        /* Itero en la lista (array) de productos */
        if (cantidades[i] > 0){
            printf("Producto: %d - Cantidad: %d - Subtotal: $%.2f\n", i + 1 ,cantidades[i], cantidades[i] * precios[i]);
        }
    }
    
/*
    if (cantidades[0] > 0) {
        printf("Producto A - Cantidad: %d - Subtotal: $%.2f\n", cantidades[0], cantidades[0] * precios[0]);
    }
    if (cantidades[1] > 0) {
        printf("Producto B - Cantidad: %d - Subtotal: $%.2f\n", cantidades[1], cantidades[1] * precios[1]);
    }
    if (cantidades[2] > 0) {
        printf("Producto C - Cantidad: %d - Subtotal: $%.2f\n", cantidades[2], cantidades[2] * precios[2]);
    }
*/
    // Muestro resultados de la operación
    printf("Total sin descuento: $%.2f\n", total);
    printf("Descuento: $%.2f\n", descuento);
    printf("Total a pagar: $%.2f\n", totalFinal);
    printf("Método de pago: %s\n", (metodoPago == 'A' || metodoPago == 'a') ? "Efectivo" : "Crédito");

    return 0;
}
