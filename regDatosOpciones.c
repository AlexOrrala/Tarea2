#include <stdio.h>
#include "metodos.c"
#include "estructuras.c"
#include "regDatos.c"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Estudiante;

int main(int argc, char* argv[]) {
    if (argc != 3) {
        printf("Uso: %s <cantidad> <opción>\n", argv[0]);
        return 1;
    }

    int cantidad = atoi(argv[1]);
    char* opcion = argv[2];

    if (strcmp(opcion, "-p") == 0) {
        registrarProfesores(cantidad);
    } else if (strcmp(opcion, "-e") == 0) {
        registrarEstudiantes(cantidad);
    } else if (strcmp(opcion, "-a") == 0) {
        registrarProfesores(cantidad);
        registrarEstudiantes(cantidad);
    } else {
        printf("Opción inválida.\n");
        return 1;
    }
    liberarprofesores();
    liberarestudiantes();
}