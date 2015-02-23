#include <stdio.h>
#include <stdlib.h>

#define N 10
#define M 0x100
#define FICHERO "hoja.bin"         //Configura nombre del fichero: .txt para archivo de texto o .bin para binario 
#define NOMBRE jugador[i].nombre   
#define FUERZA jugador[i].habilidad.fuerza
#define RESISTENCIA jugador[i].habilidad.resistencia
#define VELOCIDAD jugador[i].habilidad.velocidad
#define DINERO jugador[i].dinero
#define PUNTOS jugador[i].puntos


typedef struct TSkills {
    int fuerza;
    int resistencia;
    int velocidad;
}Skills;

typedef struct TPlayer{
    char nombre[M];
    Skills habilidad;
    int dinero;
    int puntos;
}Player;

void rellenar_datos (struct TPlayer jugador[N]){
    for(int i=0; i<N; i++){
	system("clear");
	printf("Introduce el nombre del jugador %i:\n", i+1);
	scanf("%s", NOMBRE);
	printf("Introduce la fuerza: ");
	scanf("%i", &FUERZA);
	printf("Introduce la resistencia: ");
	scanf("%i", &RESISTENCIA);
	printf("Introduce la velocidad: ");
	scanf("%i", &VELOCIDAD);
	printf("Introduce dinero inicial: ");
	scanf("%i", &DINERO);
	printf("Introduce puntos: ");
	scanf("%i", &PUNTOS);

    }
}

void guardar_datos (struct TPlayer jugador[N],FILE *hoja){
    for(int i=0; i<N; i++){
	
	fwrite(NOMBRE, sizeof(char), M, hoja);
	fwrite(&FUERZA, sizeof(int), 2, hoja);
	fwrite(&RESISTENCIA, sizeof(int), 2, hoja);
	fwrite(&VELOCIDAD, sizeof(int), 2, hoja);
	fwrite(&DINERO, sizeof(int), 2, hoja);
	fwrite(&PUNTOS, sizeof(int), 2, hoja);

	// fprintf para .txt, fwrite para .bin
	// 

	/*
	fprintf(hoja, "%s\t", NOMBRE);
	fprintf(hoja, " %i", FUERZA); 
	fprintf(hoja, " %i", RESISTENCIA); 
	fprintf(hoja, " %i", VELOCIDAD);
	fprintf(hoja, " %i", DINERO);
	fprintf(hoja, " %i\n", PUNTOS); 
	*/
    }
}

int main (int argc, char *argv[]) {
    FILE *hoja;
    Player jugador[N];

    if((hoja = fopen(FICHERO, "rb")) == NULL){  // "r" para .txt o "rb" para .bin
	hoja = fopen(FICHERO, "wb"); //"w" para .txt o "rb" para .bin
	rellenar_datos(jugador);
	guardar_datos(jugador, hoja);

    }else {
	fread(jugador, sizeof(struct TPlayer), N, hoja);

    }
    fclose(hoja);
    return EXIT_SUCCESS;
}
