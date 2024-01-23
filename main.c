#include <stdio.h>
#include <stdlib.h>

// Definición del nodo (en este caso canciones)
struct Canciones {
    char titulo[50];       // Nombre de la canción
    struct Canciones* siguiente;  // Referencia al la siguiente canción en la lista
};

// Función para agregar una nueva canción al final de la lista
struct Canciones* agregarCanciones(struct Canciones* head, const char nombresCanciones[]) {
    struct Canciones* nuevaCancion = (struct Canciones*)malloc(sizeof(struct Canciones));
    if (nuevaCancion == NULL) {
        fprintf(stderr, "Error: No se pudo asignar memoria para el nuevo nodo.\n");
        exit(EXIT_FAILURE);
    }
    snprintf(nuevaCancion->titulo, sizeof(nuevaCancion->titulo), "%s", nombresCanciones);

    nuevaCancion->siguiente = NULL;

    if (head == NULL) {
        return nuevaCancion;
    } else {
        struct Canciones* actual = head;
        while (actual->siguiente != NULL) {
            actual = actual->siguiente;
        }
        actual->siguiente = nuevaCancion;
        return head;
    }
}

// Función para imprimir la lista de reproducción
void imprimirLista(struct Canciones* head) {
    struct Canciones* actual = head;
    int contador = 1;
    while (actual != NULL) {
        printf("%d. %s\n", contador, actual->titulo);
        actual = actual->siguiente;
        contador++;
    }
}

// Función para liberar la memoria utilizada por la lista
void liberarLista(struct Canciones* head) {
    struct Canciones* actual = head;
    while (actual != NULL) {
        struct Canciones* siguiente = actual->siguiente;
        free(actual);
        actual = siguiente;
    }
}

int main() {
    struct Canciones* listaReproduccion = NULL;

    // Agregar titulos a la lista
    listaReproduccion = agregarCanciones(listaReproduccion, "Everlong - Foo Fighters");
    listaReproduccion = agregarCanciones(listaReproduccion, "Another Love - Tom Odell");
    listaReproduccion = agregarCanciones(listaReproduccion, "Silence Speaks - Whle She Sleeps");
    listaReproduccion = agregarCanciones(listaReproduccion, "Creep - Radiohead");

    // Imprimir la lista de reproducción
    printf("Lista de Reproduccion:\n");
    imprimirLista(listaReproduccion);

    // Liberar memoria al finalizar
    liberarLista(listaReproduccion);

    return 0;
}