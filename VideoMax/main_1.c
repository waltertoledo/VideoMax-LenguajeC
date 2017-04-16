/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Walter Toledo
 *
 * Created on 14 de abril de 2017, 20:15
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define dim_fila 10
#define dim_columna 35
#define dim_char 25

//DEFINICION DE ESTRUCTURAS
struct TPELICULA {
    int codigoPelicula;
    char nombre_pelicula[dim_char];
    int genero;
    float precio;
    int estado;
};
typedef struct TPELICULA PELICULA;

struct TRANKING {
    int codigo_pelicula;
    char nombre_pelicula[dim_char];
    int genero;
    int alquiler;
};
typedef struct TRANKING RANKING;

//DEFINICION DE MODULOS
void menu(PELICULA P[], int dimP, int A[][dim_columna], int dimF, int dimC,RANKING R[],int dimR);
void cargar_alquiler(int A[][dim_columna], int *dimF, int *dimC);
void mostrar_alquiler(int A[][dim_columna], int dimF, int dimC);
void cargar_peliculas(PELICULA P[], int *dimP);
void mostrar_peliculas(PELICULA P[], int dimP);
void consulta1(PELICULA P[], int dimP);
int buscar_pelicula(PELICULA P[], int dimP, int cod, int *pos, int *estado);
void consulta2(PELICULA P[], int dimP);
void consulta3(PELICULA P[], int dimP, int A[][dim_columna], int dimF, int dimC);
void calcular_alquiler(int A[][dim_columna], int dimF, int dimC, int codigo, int *diasAlq, int *diasNoAlq, int *cantAlq);
void informe_alquiler_rubro(PELICULA P[], int dimP, int A[][dim_columna], int dimF, int dimC);
void ordenar_rubro(PELICULA P[], int dimP);
void ranking_pelicula(PELICULA P[],int dimP, RANKING R[],int dimR,int A[][dim_columna],int dimF,int dimC);
void mostrar_ranking(RANKING R[],int dimR);


int main(int argc, char** argv) {

    int A[dim_fila][dim_columna];
    int dimF = 0, dimC = 0, dimP = 0,dimR=0;
    PELICULA P[5];
    RANKING R[5];
    menu(P, dimP, A, dimF, dimC, R, dimR);

    return (EXIT_SUCCESS);
}

void menu(PELICULA P[], int dimP, int A[][dim_columna], int dimF, int dimC,RANKING R[],int dimR) {
    cargar_alquiler(A, &dimF, &dimC);
    //mostrar_alquiler(A, dimF, dimC);
    cargar_peliculas(P, &dimP);
    //mostrar_peliculas(P, dimP);
    int opcion = -1;
    do {
        printf("\n\n------------------------------------");
        printf("\n           MENU DE OPCIONES");
        printf("\n------------------------------------");
        printf("\n1_ Consulta 1");
        printf("\n2_ Consulta 2");
        printf("\n3_ Consulta 3");
        printf("\n4_ Informe de Alquileres por Rubro");
        printf("\n5_ Ranking de Peliculas");
        printf("\n0_ Salir");
        printf("\n  Ingrese una opcion...");
        scanf("%d", &opcion);
        printf("\n\n-----------------------------------\n");
        switch (opcion) {
            case 1:consulta1(P, dimP);
                break;
            case 2:consulta2(P, dimP);
                break;
            case 3:consulta3(P, dimP, A, dimF, dimC);
                break;
            case 4:informe_alquiler_rubro(P, dimP, A, dimF, dimC);
                break;
            case 5:ranking_pelicula(P,dimP,R,dimR,A,dimF,dimC);break;
            case 0:opcion = 0;
                break;
            default:printf("\nLa opcion ingresada es incorrecta!!!");
                break;
        }
    } while (opcion != 0);
}

void cargar_alquiler(int A[][dim_columna], int *dimF, int *dimC) {
    int aux[dim_fila][dim_columna] = {
        {101, 0, 4, 2, 3, 3, 5, 3, 1, 2, 0, 5, 0, 4, 1, 5, 0, 2, 3, 5, 3, 0, 3, 4, 4, 1, 4, 1, 2, 5, 5},
        {102, 2, 2, 4, 4, 0, 4, 3, 4, 3, 4, 0, 4, 0, 3, 0, 1, 1, 0, 3, 5, 4, 1, 3, 4, 3, 4, 5, 0, 4, 3},
        {103, 3, 5, 2, 0, 4, 4, 1, 4, 3, 4, 4, 5, 5, 2, 0, 2, 4, 3, 3, 3, 2, 0, 4, 5, 3, 3, 3, 1, 2, 0},
        {104, 3, 3, 0, 3, 3, 0, 4, 5, 2, 2, 1, 1, 4, 0, 4, 4, 0, 1, 1, 0, 5, 0, 0, 5, 0, 0, 2, 3, 4, 1},
        {201, 0, 5, 0, 4, 5, 5, 4, 5, 4, 2, 3, 2, 0, 3, 3, 4, 4, 3, 5, 4, 4, 4, 1, 3, 1, 3, 0, 2, 2, 1},
    };
    *dimF = 5;
    *dimC = 31;
    int i, j;
    for (i = 0; i < (*dimF); i++) {
        for (j = 0; j < (*dimC); j++) {
            A[i][j] = aux[i][j];
        }
    }
}

void mostrar_alquiler(int A[][dim_columna], int dimF, int dimC) {
    int i, j;
    for (i = 0; i < dimF; i++) {
        for (j = 0; j < dimC; j++) {
            printf(" %d ", A[i][j]);
        }
        printf("\n");
    }
}

void cargar_peliculas(PELICULA P[], int *dimP) {
    PELICULA aux[] = {
        {101, "matrix", 5, 10, 1},
        {102, "batman", 5, 15, 1},
        {201, "amor", 1, 10, 0},
    };
    *dimP = 3;
    int i;
    for (i = 0; i < (*dimP); i++) {
        P[i] = aux[i];
    }
}

void mostrar_peliculas(PELICULA P[], int dimP) {
    int i;
    for (i = 0; i < dimP; i++) {
        printf("Codigo de Pelicula: %d\n", P[i].codigoPelicula);
        printf("Nombre de Pelicula: %s\n", P[i].nombre_pelicula);
        printf("Genero: %d\n", P[i].genero);
        printf("Precio: %.2f\n", P[i].precio);
        printf("Estado: %d\n", P[i].estado);
        printf("\n");
    }

}

void consulta1(PELICULA P[], int dimP) {
    int codigo, pos = -1, estado = 0;
    printf("Ingrese un Codigo de Pelicula a Buscar :");
    scanf("%d", &codigo);
    buscar_pelicula(P, dimP, codigo, &pos, &estado);
    if (estado == 1) {
        //printf("\t\tposicion %d",P[pos].codigoPelicula);
        printf("El codigo %d corresponde a la pelicula %s", codigo, P[pos].nombre_pelicula);
    } else {
        printf("La pelicula %s no esta disponible", P[pos].nombre_pelicula);
    }
}

int buscar_pelicula(PELICULA P[], int dimP, int cod, int *pos, int *estado) {
    int i;
    for (i = 0; i < dimP; i++) {
        if (P[i].codigoPelicula == cod) {
            *pos = i;
            if (P[i].estado == 1) {
                *estado = P[i].estado;
            }
            i = dimP;
        }
    }
}

void consulta2(PELICULA P[], int dimP) {
    int codigo, pos = -1, estado = 0;
    printf("\n\n Ingrese un Codigo de Pelicula a Buscar :");
    scanf("%d", &codigo);
    buscar_pelicula(P, dimP, codigo, &pos, &estado);
    if (estado == 1) {
        printf("\nLa pelicula %s esta disponible para su alquiler y cuesta $%.2f", P[pos].nombre_pelicula, P[pos].precio);
    } else {
        printf("\nLa pelicula %s no esta disponible", P[pos].nombre_pelicula);
    }
}

void consulta3(PELICULA P[], int dimP, int A[][dim_columna], int dimF, int dimC) {
    int codigo, pos = -1, estado = 0;
    int diasAlquilados = 0, diasNoAlquilados = 0, vecesAlquiladasMensuales = 0;
    float recaudacion = 0;
    printf("\n\n Ingrese un Codigo de Pelicula a Buscar :");
    scanf("%d", &codigo);
    buscar_pelicula(P, dimP, codigo, &pos, &estado);
    if (pos != -1) {
        calcular_alquiler(A, dimF, dimC, codigo, &diasAlquilados, &diasNoAlquilados, &vecesAlquiladasMensuales);
        recaudacion = vecesAlquiladasMensuales * P[pos].precio;
        printf("\nCodigo de Pelicula: %d\t\t\tNombre de Pelicula: %s", P[pos].codigoPelicula, P[pos].nombre_pelicula);
        printf("\nGenero: %d\t\t\t\tPrecio por Dia: $%.2f", P[pos].genero, P[pos].precio);
        printf("\nTotal Dias Alquilados: %d\t\tTotal Dias No Alquilados: %d", diasAlquilados, diasNoAlquilados);
        printf("\nTotal Alquilado Mensual: %d\t\tRecaudacion Mensual por la pelicula: $%.2f", vecesAlquiladasMensuales, recaudacion);
    } else {
        printf("\nLa pelicula %s no esta disponible", P[pos].nombre_pelicula);
    }
}

void calcular_alquiler(int A[][dim_columna], int dimF, int dimC, int codigo, int *diasAlq, int *diasNoAlq, int *cantAlq) {
    int i, j;
    for (i = 0; i < dimF; i++) {
        if (A[i][0] == codigo) {
            for (j = 1; j < dimC; j++) {
                if (A[i][j] > 0) {
                    (*diasAlq) = (*diasAlq) + 1;
                    (*cantAlq) = (*cantAlq) + A[i][j];
                } else {
                    (*diasNoAlq) = (*diasNoAlq) + 1;
                }
            }
        }
    }
}

void informe_alquiler_rubro(PELICULA P[], int dimP, int A[][dim_columna], int dimF, int dimC) {
    ordenar_rubro(P, dimP);
    mostrar_peliculas(P, dimP);
    int i = 0, cod, diasAlq = 0, diasNoAlq = 0, cantAlq = 0;
    float recaudacion = 0, recaudacionGral = 0, mayor = 0;
    int genero;
    while (i < dimP) {
        cod = P[i].genero;
        diasAlq = 0;
        diasNoAlq = 0;
        cantAlq = 0;
        recaudacion = 0;
        printf("\n\nCodigo de Genero: %d", cod);
        printf("\nCod Pelicula\t Nombre de Pelicula\t\tTotal Alquilado\t\tMonto");
        while ((cod == P[i].genero)&&(i < dimP)) {
            diasAlq = 0;
            diasNoAlq = 0;
            cantAlq = 0;
            recaudacion = 0;
            calcular_alquiler(A, dimF, dimC, P[i].codigoPelicula, &diasAlq, &diasNoAlq, &cantAlq);
            recaudacion = cantAlq * P[i].precio;
            printf("\n %d \t\t %s \t\t\t\t\t %d \t\t $%.2f", P[i].codigoPelicula, P[i].nombre_pelicula, cantAlq, recaudacion);
            i++;
            recaudacionGral = recaudacionGral + recaudacion;
        }
        if (recaudacion > mayor) {
            mayor = recaudacion;
            genero = P[i-1].genero;
        }
    }
    char genero1[dim_char];
    switch (genero) {
        case 1:strcpy(genero1, "Drama");
            break;
        case 2:strcpy(genero1, "Comedia");
            break;
        case 3:strcpy(genero1, "Policial");
            break;
        case 4:strcpy(genero1, "Infantil");
            break;
        case 5:strcpy(genero1, "Ciencia Ficcion");
            break;
    }
    printf("\n\nTotal General Recaudado: $%.2f\n", recaudacionGral);
    printf("El Genero mas recaudado fue %s", genero1);


}

void ordenar_rubro(PELICULA P[], int dimP) {
    int b, i, j;
    PELICULA tmp;
    i = dimP;
    do {
        j = 0, b = 0;
        while (j < i - 1) {
            if (P[j].genero > P[j + 1].genero) {
                tmp = P[j];
                P[j] = P[j + 1];
                P[j + 1] = tmp;
                b = 1;
            }
            j++;
        }
        i--;
    } while (b != 0);
}

void ranking_pelicula(PELICULA P[],int dimP, RANKING R[],int dimR,int A[][dim_columna],int dimF,int dimC){
    int i,diasAlq=0,diasNoAlq,cant=0;
    for (i = 0; i < dimP; i++) {
        calcular_alquiler(A,dimF,dimC,P[i].codigoPelicula,&diasAlq,&diasNoAlq,&cant);
        R[i].codigo_pelicula=P[i].codigoPelicula;
        R[i].genero=P[i].genero;
        R[i].alquiler=cant;
        strcpy(R[i].nombre_pelicula,P[i].nombre_pelicula);
    }
    dimR=3;  
    mostrar_ranking(R,dimR);
}

void mostrar_ranking(RANKING R[],int dimR){
    int i;
    for (i = 0; i < dimR; i++) {
        printf(" %d \t %d \t %s \t %d \t %d\n",i+1,R[i].codigo_pelicula,R[i].nombre_pelicula,R[i].genero,R[i].alquiler);
    }
}
