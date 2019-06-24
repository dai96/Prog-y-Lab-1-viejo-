#ifndef Alumno_H_INCLUDED
#define Alumno_H_INCLUDED

typedef struct
{
    int id;
    char nombre[128];
    int nota1;
    int nota2;
    int notaFinal;
    //int isEmpty;
}Alumno;

Alumno* Alumno_new();
Alumno* Alumno_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr, char* otro);
void Alumno_delete();

int Alumno_setId(Alumno* this,int id);
int Alumno_getId(Alumno* this,int* id);

int Alumno_setNombre(Alumno* this,char* nombre);
int Alumno_getNombre(Alumno* this,char* nombre);

int Alumno_setnota1(Alumno* this,int horasTrabajadas);
int Alumno_getnota1(Alumno* this,int* horasTrabajadas);

int Alumno_setnora2(Alumno* this,int sueldo);
int Alumno_getnora2(Alumno* this,int* sueldo);

int Alumno_setnotaF(Alumno* this,int sueldo);
int Alumno_getnotaF(Alumno* this,int* sueldo);

#endif // Alumno_H_INCLUDED
