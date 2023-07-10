#include <stdio.h>
#include "metodos.c"
#include "regDatosOpciones.c"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct profesor* listaProfesores = NULL;
struct Estudiante* listaEstudiantes = NULL;

void registrarprofesores(int cantidad){
  int contador = 0;
  
  do{
    int cantidadmat = 0;
    struct profesor p1;
    printf("Ingrese el nombre del profesor: ");
    scanf("%s", p1.nombre);

    printf("Ingrese la carrera del profesor: ");
    scanf("%s", p1.carrera);

    do{
    printf("Ingrese la cantidad de materias dictadas:(máximo 5)");
    scanf("%d", cantidadmat);
    }while(cantidadmat>5);
    printf("Ingrese las materias que dicta (máximo 5):");
    for (int i = 0; i < cantidadmat; i++) {
        printf("Materia %d: ", i + 1);
        scanf("%s", p1.materiasdictadas[i]);
      }
    for (int i = 0; i < cantidadmat; i++) {
        printf("Paralelo: ");
        scanf("%s", p1.paralelos[i]);
      }
    listaProfesores = agregarProfesor(listaProfesores,p1.nombre, p1.carrera,p1.materiasdictadas,p1.paralelos);
    }while(contador<cantidad);
  
}
void registrarEstudiantes(int cantidad){
  int contador = 0;
  
  do{
    int cantidadmat = 0;
    struct Estudiante e1;

    printf("Ingrese el nombre del estudiante: ");
    scanf("%s", e1.nombre);
    printf("Ingrese la carrera del estudiante: ");
    scanf("%s",  e1.carrera);
    printf("Ingrese el nivel del estudiante: ");
    scanf("%s",  e1.nivel);
    
        
    do{
        printf("Ingrese la cantidad de materias Tomadas(máximo 5):");
        scanf("%d", cantidadmat);
        }while(cantidadmat>5);
    
    for (int i = 0; i < cantidadmat; i++) {
        printf("Nombre Materia: ");
        scanf("%s",  e1.materiastomadas[i]);
      printf("Nombre Creditos: ");
        scanf("%d",  e1.creditos[i]);
      }
    listaEstudiantes = agregarEstudiante(listaEstudiantes,e1.nombre, e1.carrera, e1.nivel, e1.materiastomadas,e1.creditos);
    }while(contador<cantidad);
  
}

void imprimirdatos(){
  printf("Lista de estudiantes:\n");
  while (listaEstudiantes != NULL) {
    printf("Nombre: %s\n", listaEstudiantes->nombre);
    printf("Carrera: %s\n", listaEstudiantes->carrera);
    printf("Nivel: %s\n", listaEstudiantes->nivel);
    printf("Materias tomadas:\n");
    for (int i = 0; i < 5; i++) {
      printf("Materia: %s\n", listaEstudiantes->materiastomadas[i]);
    }
    printf("--------------------\n");
    listaEstudiantes = listaEstudiantes->siguiente;
  }
  printf("Lista de profesores:\n");
  while (listaProfesores != NULL) {
    printf("Nombre: %s\n", listaProfesores->nombre);
    printf("Carrera: %s\n", listaProfesores->carrera);
    printf("Materias dictadas:\n");
    for (int i = 0; i < 5; i++) {
      printf("Materia: %s\n", listaProfesores->materiasdictadas[i]);
      printf("Paralelo: %s\n", listaProfesores->paralelos[i]);
    }
    printf("--------------------\n");
    listaProfesores = listaProfesores->siguiente;
  }
  
}


void liberarprofesores(){
  struct profesor* profesorActual = listaProfesores;
  while (profesorActual != NULL) {
    struct profesor* siguienteProfesor = profesorActual->siguiente;
    free(profesorActual);
    profesorActual = siguienteProfesor;
  }
}

void liberarestudiantes(){
  struct Estudiante* estudianteActual = listaEstudiantes;
  while (estudianteActual != NULL) {
    struct Estudiante* siguienteEstudiante = estudianteActual->siguiente;
    free(estudianteActual);
    estudianteActual = siguienteEstudiante;
  }
}
