#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node *next;
};

struct Node *CreateNode(int data) {
  // Crear Head
  //(struct Node*) => Casteo ej. int ejemplo = 3; double ejemploDouble =
  //(double) ejemplo; malloc -> memory allocation -> Reserva un espacio en la
  // memoria para la variable sizeof(struct Node)) => devuelve el tamaño en
  // memoria del Nodo.
  struct Node *node = (struct Node *)malloc(sizeof(struct Node));
  node->data = data;
  node->next = NULL;
  return node;
}

void PrintList(struct Node *head) {
  struct Node *current = head;
  while (current != NULL) {
    printf("%d", current->data);
    current = current->next;
    printf("\n");
  }
}

int main(int argc, char *argv[]) {
  // creamos los nodos
  struct Node *head = CreateNode(1);
  struct Node *node = CreateNode(2);
  struct Node *tail = CreateNode(3);

  head->next = node;
  node->next = tail;

  PrintList(head);
  // Importante, liberar la memoria reservada para los nodos
  free(head);
  free(node);
  free(tail);

  return 0;
}
