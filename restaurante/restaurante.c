#include <stdio.h>

/*

    Desarrolla un programa en lenguaje C que permita simular el proceso de reserva en un restaurante. El sistema debe seguir los siguientes pasos:

    Solicitar el nombre y apellido del cliente para comenzar.
    Mostrar un menú con tres tipos de platos y sus respectivos precios:
    Plato A - $250
    Plato B - $300
    Plato C - $200
    El cliente podrá seleccionar los platos que desee, especificando la cantidad de cada uno. Puede continuar seleccionando hasta que elija 0 para finalizar la selección.
    Luego de seleccionar los platos, el sistema le preguntará al cliente si desea agregar una propina. Las opciones serán:
    A: No dejar propina.
    B: Dejar una propina del 5% del total.
    C: Dejar una propina del 10% del total.
    Finalmente, el sistema mostrará un resumen con:
    Datos del cliente.
    Lista de platos seleccionados.
    Monto total.
    Monto de la propina (si se eligió dejarla).
    Monto final a pagar (incluyendo la propina).

*/
    // Declaro estructura Cliente (nombre, apellido y m'etido de pago)
    struct Cliente {
        char nomCliente[50];
        char apeCliente[50];
        char metodoPago;
    };
    
    // Declaro estructura Producto (nombre y precio)
    struct Producto {
        char nombre[50];
        float precio;
        int cantidad;
    };


/**
 * The function `MontoPlatosSeleccionados` calculates the total amount for selected products based on
 * user input.
 * 
 * @param productos The function `MontoPlatosSeleccionados` takes an array of `Producto` structures
 * named `productos` and the total number of products `cantidadProductos` as input parameters. The
 * `Producto` structure likely contains information about a product such as its name, price, and
 * quantity.
 * @param cantidadProductos The parameter `cantidadProductos` in the function
 * `MontoPlatosSeleccionados` represents the total number of products available in the `productos`
 * array. It is used to determine the range of products that can be selected by the user from the menu
 * displayed within the function.
 * 
 * @return The function `MontoPlatosSeleccionados` returns the total amount (MontoTotalProductos) of
 * the selected products based on the user's input.
 */
float MontoPlatosSeleccionados(struct Producto productos[], int cantidadProductos){

    int seleccionProducto, cantidadProducto;
    float MontoTotalProductos = 0;

    // Mostrar menú y procesar selección
    do {
        printf("\nSeleccione un producto (Ingrese 0 para salir):\n");
        for (int i = 0; i < cantidadProductos ; i++) {
            printf("%d. %s - $%.2f\n", i + 1, productos[i].nombre, productos[i].precio);
        }
        printf("Selección: ");
        scanf("%d", &seleccionProducto);

        if (seleccionProducto > 0 && seleccionProducto <= 3) {
            printf("Ingrese la cantidad: ");
            scanf("%d", &cantidadProducto);
            productos[seleccionProducto-1].cantidad += cantidadProducto;  // Sumar a la cantidad del producto seleccionado
            MontoTotalProductos += productos[seleccionProducto-1].cantidad * productos[seleccionProducto-1].precio;
        }
    } while (seleccionProducto != 0);

    return MontoTotalProductos;
}

// Funci'on que permite la entrada de datos del cliente
struct Cliente CargarDatosCliente(){

    struct Cliente cliente;
    printf("Ingrese el nombre del cliente: ");
    scanf("%s", cliente.nomCliente);
    printf("Ingrese el apellido del cliente: ");
    scanf("%s", cliente.apeCliente);
    return cliente;
};

// Funcion que calcula el total en funcion del metodo de pago (Efectivo o Tarjeta)
int CalculaDescuentoMetodoPago(float total, struct Cliente persona_cliente){

    // Preguntar método de pago
    
    printf("\nSeleccione el método de pago:\nA. Efectivo (10%% de descuento)\nB. Crédito\n");
    printf("Método de pago: ");
    scanf(" %c", &persona_cliente.metodoPago);  // El espacio antes de %c es para evitar problemas con el buffer de entrada

    // Aplicar descuento si paga en efectivo
    float descuento = 0;
    if (persona_cliente.metodoPago == 'A' || persona_cliente.metodoPago == 'a') {
        descuento = total * 0.10;
    }
    
    return descuento;
}

// Funcion que muestra en terminal el resumen de compra con platos y cantidades, descuentos y total de la compra
void MostrarResumenCompra(struct Cliente cliente, struct Producto productos[], float subtotalMonto, int cantidadProductos, float descuento){

    printf("\n----------- RESUMEN DE COMPRA---------");
    printf("\nCLIENTE: %s %s", cliente.apeCliente, cliente.nomCliente);
    printf("\nProductos Seleccionados:\n");
    for (int i = 0; i < cantidadProductos ; i++) {
        printf("%d. %s cantidad: %d - Precio u. $%.2f\n", i + 1, productos[i].nombre, productos[i].cantidad, productos[i].precio);
    }
    printf("\nDescuento aplicado: %.2f: ", descuento);
    float totalMontoMenu = subtotalMonto - descuento;
    printf("\nMonto a Pagar: $%.2f\n\n", totalMontoMenu); 

}

/**
 * The main function initializes data structures, prompts the user for input, processes product
 * selection, calculates discounts based on payment method, and displays a summary of the purchase.
 * 
 * @return The `main` function is returning an integer value of 0.
 */
int main(){

    struct Cliente cliente = {" "," ",' '};
    struct Producto productos[] = {
        {"Producto 1", 100.0, 0},
        {"Producto 2", 200.0, 0},
        {"Producto 3", 150.0, 0}
    };
    float descuento, montoPlatos;
    int cantidadProductos;

    /* Llamada a la funcion CargarDatosCliente() que solicita datos al usurio y los almacena en mi struct Cliente
        params: @param cliente
    */
    cliente = CargarDatosCliente();

    // Función para la generación de menu y Selección de productos
    cantidadProductos = sizeof(productos) / sizeof(productos[0]);
    montoPlatos = MontoPlatosSeleccionados(productos, cantidadProductos); 
    
    if (!montoPlatos){
        printf("No se seleccionaron productos. Fin del programa.\n");
        return 0;
    }else {
        
        descuento = CalculaDescuentoMetodoPago(montoPlatos,cliente);
        MostrarResumenCompra(cliente, productos, montoPlatos,cantidadProductos, descuento);
    }

    return 0;
}