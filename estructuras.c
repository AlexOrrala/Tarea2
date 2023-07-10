
struct profesor{
  char nombre[30];
  char carrera[30];
  char materiasdictadas [4][50];
  char paralelos [4][50];
  struct profesor* siguiente;
};

struct Estudiante{
  char nombre[30];
  char carrera[30];
  char nivel[30];
 char materiastomadas [8][50];
  int creditos[8];
struct Estudiante* siguiente;
};