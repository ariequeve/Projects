#include <stdio.h>

/*

    Desarrolla un programa en lenguaje C que permita realizar la siguiente operación:
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


#include <stdio.h>

int main() {
    char nombre[50], metodoPago;
    int producto, cantidad, totalProductos = 0;
    float total = 0, descuento = 0, totalFinal = 0;
    
    // Precios de los productos
    float precios[] = {100.0, 200.0, 150.0};
    int cantidades[] = {0, 0, 0};

    // Descuento pago en efectivo
    int const descuento_efectivo = 0.10;

    // Pedir nombre del cliente
    printf("Ingrese el nombre del cliente: ");
    //fgets(nombre, sizeof(nombre), stdin);
    scanf("%s", nombre);

    // Mostrar menú y procesar selección
    do {
        printf("\nSeleccione un producto:\n");
        printf("1. Producto A - $100\n");
        printf("2. Producto B - $200\n");
        printf("3. Producto C - $150\n");
        printf("0. Salir\n");
        printf("Ingrese el número del producto: ");
        scanf("%d", &producto);

        if (producto >= 1 && producto <= 3) {
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
    printf("A. Efectivo\n");
    printf("B. Crédito\n");
    printf("Seleccione el método de pago (A/B): ");
    scanf(" %c", &metodoPago);

    // Calcular descuento si aplica
    if (metodoPago == 'A' || metodoPago == 'a') {
        //descuento = total * 0.10;
        descuento = total * descuento_efectivo;
    }
    
    totalFinal = total - descuento;

    // Mostrar resumen de compra
    printf("\n--- RESUMEN DE COMPRA ---\n");
    printf("Cliente: %s", nombre);
    printf("Productos comprados:\n");

    if (cantidades[0] > 0) {
        printf("Producto A - Cantidad: %d - Subtotal: $%.2f\n", cantidades[0], cantidades[0] * precios[0]);
    }
    if (cantidades[1] > 0) {
        printf("Producto B - Cantidad: %d - Subtotal: $%.2f\n", cantidades[1], cantidades[1] * precios[1]);
    }
    if (cantidades[2] > 0) {
        printf("Producto C - Cantidad: %d - Subtotal: $%.2f\n", cantidades[2], cantidades[2] * precios[2]);
    }

    printf("Total sin descuento: $%.2f\n", total);
    printf("Descuento: $%.2f\n", descuento);
    printf("Total a pagar: $%.2f\n", totalFinal);
    printf("Método de pago: %s\n", (metodoPago == 'A' || metodoPago == 'a') ? "Efectivo" : "Crédito");

    return 0;
}
