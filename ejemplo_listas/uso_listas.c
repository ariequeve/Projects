#include <stdio.h>
#include <stdlib.h>

struct Nodo {
    int dato;
    struct Nodo* siguiente;
};

void insertarInicio(struct Nodo** cabeza, int valor);
void imprimirLista(struct Nodo* cabeza);
void eliminarNodo(struct Nodo** cabeza, int valor);
void liberarLista(struct Nodo* cabeza);

int main() {
    struct Nodo* lista = NULL;

    insertarInicio(&lista, 10);
    insertarInicio(&lista, 20);
    insertarInicio(&lista, 30);

    printf("Lista actual: ");
    imprimirLista(lista);

    eliminarNodo(&lista, 20);
    printf("Después de eliminar 20: ");
    imprimirLista(lista);

    liberarLista(lista);
    return 0;
}

// Funciones implementadas aquí abajo...



/**
 * The function `insertarInicio` inserts a new node with a given value at the beginning of a linked
 * list.
 * 
 * @param cabeza The parameter `cabeza` in the `insertarInicio` function is a pointer to a pointer to a
 * struct `Nodo`. It is used to keep track of the head or the first node of a linked list. By passing a
 * pointer to a pointer, changes made to `cabe
 * @param valor The `valor` parameter in the `insertarInicio` function represents the integer value
 * that you want to insert at the beginning of the linked list. This value will be stored in the new
 * node that is being created and inserted at the beginning of the linked list.
 */
void insertarInicio(struct Nodo** cabeza, int valor) {
    struct Nodo* nuevo = (struct Nodo*) malloc(sizeof(struct Nodo));
    nuevo->dato = valor;
    nuevo->siguiente = *cabeza;
    *cabeza = nuevo;
}


/**
 * The function "imprimirLista" prints the data stored in a linked list starting from the head node.
 * 
 * @param cabeza The parameter `cabeza` in the `imprimirLista` function is a pointer to the head of a
 * linked list. It points to the first node in the linked list from where the printing of the list will
 * start.
 */
void imprimirLista(struct Nodo* cabeza) {
    struct Nodo* actual = cabeza;
    while (actual != NULL) {
        printf("%d -> ", actual->dato);
        actual = actual->siguiente;
    }
    printf("NULL\n");
}

/**
 * The function `eliminarNodo` is used to remove a node with a specific value from a linked list.
 * 
 * @param cabeza The parameter `cabeza` in the `eliminarNodo` function is a pointer to a pointer to a
 * struct `Nodo`. This means that it is a double pointer that points to the head of a linked list. By
 * using a double pointer, changes made to `*cabeza
 * @param valor The `valor` parameter in the `eliminarNodo` function represents the value that you want
 * to remove from the linked list. The function will search for a node with this specific value and
 * delete that node from the linked list if it exists.
 * 
 * @return The function `eliminarNodo` returns `void`, which means it does not return any value.
 */
void eliminarNodo(struct Nodo** cabeza, int valor) {
    struct Nodo* actual = *cabeza;
    struct Nodo* anterior = NULL;

    while (actual != NULL && actual->dato != valor) {
        anterior = actual;
        actual = actual->siguiente;
    }

    if (actual == NULL) return;

    if (anterior == NULL) {
        *cabeza = actual->siguiente;
    } else {
        anterior->siguiente = actual->siguiente;
    }

    free(actual);
}

/**
 * The function `liberarLista` frees the memory allocated for each node in a linked list.
 * 
 * @param cabeza The parameter `cabeza` in the `liberarLista` function is a pointer to the head of a
 * linked list. This function is responsible for freeing the memory allocated for each node in the
 * linked list starting from the head (`cabeza`) until the end of the list.
 */
void liberarLista(struct Nodo* cabeza) {
    struct Nodo* actual = cabeza;
    while (actual != NULL) {
        struct Nodo* temp = actual;
        actual = actual->siguiente;
        free(temp);
    }
}
