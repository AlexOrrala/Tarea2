#include "estructuras.c"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Estudiante* agregarEstudiante(struct Estudiante* lista, char nombre[], char carrera[], char nivel[], char materiastomadas[][50],int creditos[]) {
  struct Estudiante* nuevoEstudiante = (struct Estudiante*)malloc(sizeof(struct Estudiante));
  strcpy(nuevoEstudiante->nombre, nombre);
  strcpy(nuevoEstudiante->carrera, carrera);
  strcpy(nuevoEstudiante->nivel, nivel);
  memcpy(nuevoEstudiante->materiastomadas, materiastomadas, sizeof(nuevoEstudiante->materiastomadas));
  memcpy(nuevoEstudiante->creditos, creditos, sizeof(nuevoEstudiante->materiastomadas));
  nuevoEstudiante->siguiente = lista;
  return nuevoEstudiante;
}
struct profesor* agregarProfesor(struct profesor* lista, char nombre[], char carrera[], char materiasdictadas[][50], char paralelos[][50]) {
  struct profesor* nuevoProfesor = (struct profesor*)malloc(sizeof(struct profesor));
  strcpy(nuevoProfesor->nombre, nombre);
  strcpy(nuevoProfesor->carrera, carrera);
  memcpy(nuevoProfesor->materiasdictadas, materiasdictadas, sizeof(nuevoProfesor->materiasdictadas));
  memcpy(nuevoProfesor->paralelos, paralelos, sizeof(nuevoProfesor->paralelos));
  nuevoProfesor->siguiente = lista;
  return nuevoProfesor;
}