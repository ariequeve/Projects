#include <stdio.h>

/*
* Aplicacion que toma los datos de vendedores de una tienda de cafe y registra sus ventas.  La aplicacion brindara los datos del 
* vendedor que haya generado mayores ingresos (monto) por un lado, y por otro indicara el producto mas vendido a traves de su
* nombre y cantidad vendida.
*/

// Estructura para almacenar ventas
struct Ventas{
    char nombre_producto[50];
    int cantidad;
    float monto;
};

// Estructura para almacenar vendedores
struct Vendedor{
    char nombre[50];
    char apellido[50];
    struct Ventas ventas;
    float total_ventas;
};

// Estructura para almacenar datos
struct Producto {
    char nombre[50];
    float precio;
    //int cantidad_vendido;
};

const int cant_vendedores = 3;
const int cant_productos = 3;

// Almaceno los datos de vendedores y ventas realizadas
void registroDatosVentas(struct Vendedor vendedores[], struct Ventas ventas[]){

    int num_productos = 0;
    for (int i = 0; i < cant_vendedores; i++)
    {
        /* NOMBRE VENDEDOR */
        printf("Nombre Vendedor: \n");
        scanf("%s", vendedores[i].nombre);

         /* APELLIDO VENDEDOR */
        printf("Apellido Vendedor: \n");
        scanf("%s", vendedores[i].apellido);

        for (int j = 0; i < cant_productos; j++)
        {
            /* NOMBRE PRODUCTO */
            printf("Nombre PRODUCTO: \n");
            scanf("%s", vendedores[i].ventas.nombre_producto);

            /* CANTIDAD PRODUCTO */
            printf("Cantidad PRODUCTO: \n");
            scanf("%d", vendedores[i].ventas.cantidad);     

            /* MONTO VENTA */
            printf("MONTO PRODUCTO: \n");
            scanf("%f", vendedores[i].ventas.monto);

             // Verificar si el producto ya está en la lista de productos vendidos
            int producto_existe = 0;
            for (int z = 0; z < cant_productos; z++) {
                if (strcmp(vendedores[i].ventas.nombre_producto, ventas[z].nombre_producto) == 0) {
                    ventas[z].cantidad+= vendedores[i].ventas.cantidad;
                    producto_existe = 1;
                    break;
                }
            }

            // Si el equipo no existe, lo agregamos
            if (!producto_existe) {
                strcpy(ventas[num_productos].nombre_producto, vendedores[i].ventas.nombre_producto);
                ventas[num_productos].cantidad = vendedores[i].ventas.cantidad;
                num_productos++;
            }


        }
               

    }
    

};

// Venta total por vendedor
void ventaTotalVendedor(){

};

// Identifico el producto mas vendido
void productoMasVendido(struct Ventas ventas[], int cant_productos){

    struct Ventas max_venta;
    max_venta.cantidad = 0;
    //int maxCantProducto = 0;
    for (int i = 0; i < cant_productos; i++)
    {
        /* code */
        if (ventas[i].cantidad > max_venta.cantidad){
            max_venta.cantidad = ventas[i].cantidad;
            strcpy(max_venta.nombre_producto,ventas[i].nombre_producto);
        }
    }
    printf("\nEl Producto mas vendido es: %s con %d u vendidas: \n", max_venta.nombre_producto, max_venta.cantidad);

};

// Muestro resultados en terminal
void resultadoVentas(){

};

int main(){

    const int num_ventas = 3, num_vendedores = 2;
    struct Vendedor vendedores[num_vendedores];
    struct Ventas ventas[num_ventas];

    registroDatosVentas(vendedores,ventas);
    ventaTotalVendedor();
    productoMasVendido();
    resultadoVentas();

    return 0;
}