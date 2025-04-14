//Taller Grupal Semana 3
//INTEGRANTES:
//Aguirre Remigio
//Hidalgo Mateo
//MAcias Isaac

#include <stdio.h>
#define ESTUDIANTES 5
#define ASIGNATURAS 3

int main() {
    
    float calificaciones[ESTUDIANTES][ASIGNATURAS];

    int aprobados = 0;
    int reprobados = 0;
    float sumaAsignatura = 0;
    float sumaEstudiante = 0;
    // INGRESO DE CALIFICACIONES USANDO UN VECTOR BIDIMENSIONAL
    for (int i = 0; i < ESTUDIANTES; i++) {
        printf("Estudiante %d:\n", i + 1);
        for (int j = 0; j < ASIGNATURAS; j++) {
    //VALIDACION        
            do {        
                printf("  Asignatura %d: ", j + 1);
                scanf("%f", &calificaciones[i][j]);
                if (calificaciones[i][j] < 0 || calificaciones[i][j] > 10)
                    printf("    La calificacion debe estar entre 0 y 10, intente de nuevo\n");
            } while (calificaciones[i][j] < 0 || calificaciones[i][j] > 10);
        }
    }

    //PROMEDIOS
    
    //ESTUDIANTES
    printf("\n--- Promedio por estudiante ---\n");
    for (int i = 0; i < ESTUDIANTES; i++) {
        for (int j = 0; j < ASIGNATURAS; j++) {
            sumaEstudiante += calificaciones[i][j];
        }
        printf("Promedio estudiante %d: %.2f\n", i + 1, sumaEstudiante / ASIGNATURAS);
    }

    //ASIGNATURAS
    printf("\n--- Promedio por asignatura ---\n");
    for (int j = 0; j < ASIGNATURAS; j++) {
        for (int i = 0; i < ESTUDIANTES; i++) {
            sumaAsignatura += calificaciones[i][j];
        }
        printf("Asignatura %d: %.2f\n", j + 1, sumaAsignatura / ESTUDIANTES);
    }

    //NOTAS MAXIMAS Y MINIMAS
    
    //ESTUDIANTES
    printf("\n--- Nota máxima y mínima por estudiante ---\n");
    for (int i = 0; i < ESTUDIANTES; i++) {
        float notaMax = calificaciones[i][0];
            float notaMin = calificaciones[i][0];
        for (int j = 1; j < ASIGNATURAS; j++) {
            
            if (calificaciones[i][j] > notaMax) notaMax = calificaciones[i][j];
            if (calificaciones[i][j] < notaMin) notaMin = calificaciones[i][j];
        }
        printf("Estudiante %d: Nota máxima = %.2f, Nota mínima = %.2f\n", i + 1, notaMax, notaMin);
    }

    //ASIGNATURA
    printf("\n--- Nota máxima y mínima por asignatura ---\n");
    for (int j = 0; j < ASIGNATURAS; j++) {
        float notaMax = calificaciones[0][j];
            float notaMin = calificaciones[0][j];
        for (int i = 1; i < ESTUDIANTES; i++) {
            if (calificaciones[i][j] > notaMax) notaMax = calificaciones[i][j];
            if (calificaciones[i][j] < notaMin) notaMin = calificaciones[i][j];
        }
        printf("Asignatura %d: Nota máxima = %.2f, Nota mínima = %.2f\n", j + 1, notaMax, notaMin);
    }

    //APROBADOS Y REPROBADOS POR CADA ASIGNATURA
    printf("\n--- Estudiantes aprobados y reprobados por asignatura ---\n");
    for (int j = 0; j < ASIGNATURAS; j++) {
        for (int i = 0; i < ESTUDIANTES; i++) {
            if (calificaciones[i][j] >= 6)
                aprobados++;
            else
                reprobados++;    
        }
        printf("Asignatura %d: %d Aprobados, %d Reprobados\n", j + 1, aprobados, reprobados);
    }

    return 0;
}
