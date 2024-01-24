#include <stdio.h>
#include <stdlib.h>

// Declarar el nodo
struct Canciones {
  char titulo[50];
  struct Canciones *next;
};

struct Canciones *agregarCanciones(struct Canciones *head,
                                   const char tituloCancion[]) {
  struct Canciones *cancion =
      (struct Canciones *)malloc(sizeof(struct Canciones));
  // Error Handling -> Prepararnos por si hay algun error.
  if (cancion == NULL) {
    fprintf(stderr, "Error: No se pudo asignar memoria para el nodo. \n");
    exit(EXIT_FAILURE);
  }
  snprintf(cancion->titulo, sizeof(cancion->titulo), "%s", tituloCancion);
  cancion->next = NULL;

  if (head == NULL) {
    // Si no hay head inicialmente, la cancion que acabamos de crear se
    // convierte en head (la lista es solo de 1 de longitud)
    return cancion;
  } else {
    struct Canciones *actual = head;
    while (actual->next != NULL) {
      actual = actual->next;
    }
    actual->next = cancion;
    return head;
  }
}
void imprimirLista(struct Canciones *head) {
  struct Canciones *actual = head;
  int i = 1;
  while (actual != NULL) {
    printf("%d. %s\n", i, actual->titulo);
    actual = actual->next;
    i++;
  }
}
void liberarLista(struct Canciones *head) {
  struct Canciones *actual = head;
  while (actual != NULL) {
    struct Canciones *next = actual->next;
    free(actual);
    actual = next;
  }
}
int main(int argc, char *argv[]) {
  struct Canciones *listaReproducción = NULL;

  // Agregar titulos a la lista
  listaReproducción =
      agregarCanciones(listaReproducción, "Everlong - Foo Fighters");
  listaReproducción =
      agregarCanciones(listaReproducción, "Another Love - Tom Odell");
  listaReproducción =
      agregarCanciones(listaReproducción, "Silence Speaks - While She Sleeps");
  listaReproducción = agregarCanciones(listaReproducción, "Creep - Radiohead");
  listaReproducción =
      agregarCanciones(listaReproducción, "Imagine - John Lennon");

  // Imprimir la lista
  printf("Lista de Reproducción\n");
  imprimirLista(listaReproducción);

  // liberar memoria
  liberarLista(listaReproducción);
  return 0;
}
