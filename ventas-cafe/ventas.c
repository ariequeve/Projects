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

const int cant_vendedores = 3;
const int cant_productos = 3;

// Almaceno los datos de vendedores y ventas realizadas
void registroDatosVentas(struct Vendedor vendedores[]){

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
                if (strcmp(vendedores[i].ventas.nombre_producto, jugadores[i].equipo) == 0) {
                    equipos[j].cantidad_goles += jugadores[i].goles;
                    equipo_existe = 1;
                    break;
                }
            }

            // Si el equipo no existe, lo agregamos
            if (!equipo_existe) {
                strcpy(equipos[num_equipos].nombre_equipo, jugadores[i].equipo);
                equipos[num_equipos].cantidad_goles = jugadores[i].goles;
                num_equipos++;
            }


        }
               

    }
    

};

// Venta total por vendedor
void ventaTotalVendedor(){

};

// Identifico el producto mas vendido
void productoMasVendido(){

};

// Muestro resultados en terminal
void resultadoVentas(){

};

int main(){

    registroDatosVentas();
    ventaTotalVendedor();
    productoMasVendido();
    resultadoVentas();

    return 0;
}