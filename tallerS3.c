//Taller Grupal Semana 3
//INTEGRANTES:
//Aguirre Remigio
//Hidalgo Mateo
//MAcias Isaac

#include <stdio.h>
int main() {
    
    float calificaciones[ESTUDIANTES][ASIGNATURAS];

    int aprobados = 0;
    int reprobados = 0;
    float sumaAsignatura = 0;
    float sumaEstudiante = 0;
    // INGRESO DE CALIFICACIONES USANDO UN VECTOR BIDIMENSIONAL
    for (int i = 0; i < 5; i++) {
        printf("Estudiante %d:\n", i + 1);
        for (int j = 0; j < 3; j++) {
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
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 3; j++) {
            sumaEstudiante += calificaciones[i][j];
        }
        printf("Promedio estudiante %d: %.2f\n", i + 1, sumaEstudiante / 3);
        sumaEstudiante = 0;
    }

    //ASIGNATURAS
    printf("\n--- Promedio por asignatura ---\n");
    for (int j = 0; j < 3; j++) {
        for (int i = 0; i < 5; i++) {
            sumaAsignatura += calificaciones[i][j];
        }
        printf("Asignatura %d: %.2f\n", j + 1, sumaAsignatura / 5);
        sumaAsignatura = 0;
    }

    //NOTAS MAXIMAS Y MINIMAS
    
    //ESTUDIANTES
    printf("\n--- Nota máxima y mínima por estudiante ---\n");
    for (int i = 0; i < 5; i++) {
        float notaMax = calificaciones[i][0];
            float notaMin = calificaciones[i][0];
        for (int j = 1; j < 3; j++) {
            
            if (calificaciones[i][j] > notaMax) notaMax = calificaciones[i][j];
            if (calificaciones[i][j] < notaMin) notaMin = calificaciones[i][j];
        }
        printf("Estudiante %d: Nota máxima = %.2f, Nota mínima = %.2f\n", i + 1, notaMax, notaMin);
    }

    //ASIGNATURA
    printf("\n--- Nota máxima y mínima por asignatura ---\n");
    for (int j = 0; j < 3; j++) {
        float notaMax = calificaciones[0][j];
            float notaMin = calificaciones[0][j];
        for (int i = 1; i < 5; i++) {
            if (calificaciones[i][j] > notaMax) notaMax = calificaciones[i][j];
            if (calificaciones[i][j] < notaMin) notaMin = calificaciones[i][j];
        }
        printf("Asignatura %d: Nota máxima = %.2f, Nota mínima = %.2f\n", j + 1, notaMax, notaMin);
    }

    //APROBADOS Y REPROBADOS POR CADA ASIGNATURA
    printf("\n--- Estudiantes aprobados y reprobados por asignatura ---\n");
    for (int j = 0; j < 3; j++) {
        for (int i = 0; i < 5; i++) {
            if (calificaciones[i][j] >= 6)
                aprobados++;
            else
                reprobados++;    
        }
        printf("Asignatura %d: %d Aprobados, %d Reprobados\n", j + 1, aprobados, reprobados);
        aprobados = 0;
        reprobados = 0;
    }
    
    return 0;
}

import java.util.Locale;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
    /**Creación de los Objetos Juegos*/
        Juego j1 = new Juego("","",0.0,0.0,0,0);
        //Juego j2 = new Juego("","",0.0,0.0,0,0);
        //Juego j3 = new Juego("","",0.0,0.0,0,0);
        //Juego j4 = new Juego("","",0.0,0.0,0,0);
        //Creación del Scanner para leer los datos
        Scanner sc = new Scanner(System.in);
        sc.useLocale(Locale.US);
        /**Leer los datos de Cada Juego*/
        //Juego 1
        System.out.println("---------------------------------------");
        System.out.println("----Ingresar los Datos del Juego #1----" );
        System.out.println("---------------------------------------");
        System.out.println("Ingrese el nombre: ");
        j1.setNombre(sc.nextLine());
        int op=0;
        int opMenu=0;
        do{
        System.out.println("Seleccione la categoria:");
        System.out.println("Opciones:");
        System.out.println("1)Rompecabezas\n2)Accion\n3)Deporte");
        op=sc.nextInt();
        sc.nextLine();
        switch (op) {
            case 1:
                j1.setNombre("Rompecabezas");
                break;
            case 2:
                j1.setNombre("Accion");
                break;
            case 3:
                j1.setNombre("Deporte");
                break;
            default:
                System.out.println("Opcion Invalida");
                System.out.println("Seleccione de nuevo");
                System.out.println("---------------------------------------");
        }
        }while(op < 1|| op > 3);
        op=0;
        do{
            System.out.println("Ingrese el tamanio en kB: ");
            j1.setTamanio(sc.nextDouble());
            sc.nextLine();
            if (j1.getTamanio()<0){
                System.out.println("El tamaño no puede ser negativo: ");
            }}while(j1.getTamanio()<0);
        do{
            System.out.println("Ingrese el precio en Pesos: ");
            j1.setPrecio(sc.nextDouble());
            sc.nextLine();
            if (j1.getPrecio()<0){
                System.out.println("El precio no puede ser negativo");
            }}while(j1.getPrecio()<0);
        do{
        System.out.println("Ingrese la cantidad de licencias vendidas: ");
        j1.setLicenciasVendidas(sc.nextInt());
        sc.nextLine();
        if (j1.getLicenciasVendidas()<0){
            System.out.println("La licencia no debe ser menor a 0");
        }}while(j1.getLicenciasVendidas()<0);
        do{
            System.out.println("Ingrese la cantidad de licencias disponibles: ");
            j1.setLicenciasDisponibles(sc.nextInt());
            sc.nextLine();
            if (j1.getLicenciasDisponibles()<0){
                System.out.println("La licencia no debe ser menor a 0");
            }}while(j1.getLicenciasDisponibles()<0);
        System.out.println("---------------------------------------");
        do{
        System.out.println("---------------------------------------");
        System.out.println("------------Menu de Opciones-----------");
        System.out.println("---------------------------------------");
        System.out.println("1) Detalle de los Juegos");
        System.out.println("2) Comprar licencias de los Juegos");
        System.out.println("3) Vender licencias de los Juegos");
        System.out.println("4) Consultar el Juego mas vendido");
        System.out.println("5) Consultar los descuentos aplicados por un volumen de compra");
        System.out.println("6) Salir");
        System.out.println("Seleccione la opcion: ");
        opMenu=sc.nextInt();
        sc.nextLine();
        switch (opMenu) {
            case 1:
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                break;
            case 6:
                System.out.println("Fin del Programa");
                break;
            default:
                System.out.println("Opcion Invalida");
        }
        }while(opMenu!=6);
        }
    }
