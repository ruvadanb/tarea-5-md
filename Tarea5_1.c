/*
 ============================================================================
 Name        : Tarea5_2.c
 Author      :
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Graph.h"

int compareValues(Type, Type);
void printValue(Type);
unsigned indexValue(Type, unsigned);

typedef struct{
	char Name[25];
	char Date[4];
	char Age[10];
}Person;
typedef struct{
	char Tittle[25];
	char Date[4];
	char Tagline[100];
}Movies;
typedef struct{
	char Name[25];
	char Tittle[25];
}Edge;
int main(){
	FILE *v_person = fopen("vertex_person.csv","r");
	FILE *v_movies = fopen("vertex_movies.csv","r");
	FILE *edges = fopen("edges_PersonMovies.csv","r");
	if(!v_person || !v_movies || !edges) {
		printf("Failed opening files...\n");
		return 0;
	}else{
		Graph g_Person = graph_create(compareValues, printValue, indexValue);
		Graph g_Movies = graph_create(compareValues, printValue, indexValue);
		Person aux_person;
		Movies aux_movies;
		Edge aux_edge;
		//Lectura y guardado de Person
		char aux;
		short i;
		while(!feof(v_person)){
			char buff_name[25]="", buff_age[10]="", buff_date[4]="";
			while((aux = fgetc(v_person)!=',') && i < 25 && aux != EOF){
				buff_name[i] = aux;
				i++;
			}
			strcpy(aux_person.Name, buff_name);
			while((aux = fgetc(v_person)!=',') && i < 10 && aux != EOF){
				buff_age[i] = aux;
				i++;
			}
			strcpy(aux_person.Age, buff_age);
			while((aux = fgetc(v_person)!=',') && i < 4 && aux != EOF){
				buff_date[i] = aux;
				i++;
			}
			strcpy(aux_person.Date, buff_date);
			if(graph_addVertex(g_Person, &aux_person))printf("Vértice agregado.\t");
		}
		//Lectura y guardado de Movies
		while(!feof(v_movies)){
			char buff_tittle[25]="", buff_tagline[100]="", buff_date[4]="";
			while((aux = fgetc(v_movies)!=',') && i < 25 && aux != EOF){
				buff_tittle[i] = aux;
				i++;
			}
			strcpy(aux_movies.Tittle, buff_tittle);
			while((aux = fgetc(v_movies)!=',') && i < 4 && aux != EOF){
				buff_date[i] = aux;
				i++;
			}
			strcpy(aux_movies.Date, buff_date);
			while((aux = fgetc(v_movies)!=',') && i < 100 && aux != EOF){
				buff_tagline[i] = aux;
				i++;
			}
			strcpy(aux_movies.Tagline, buff_tagline);

			if(graph_addVertex(g_Movies, &aux_movies))printf("Vértice agregado.\t");
		}
		//Lectura y guardado de Edges
		while(!feof(edges)){
			char buff_tittle[25]="", buff_name[25]="";
			while((aux = fgetc(edges)!=',') && i < 25 && aux != EOF){
				buff_name[i] = aux;
				i++;
			}
			strcpy(aux_edge.Name, buff_name);
			while((aux = fgetc(edges)!=',') && i < 25 && aux != EOF){
				buff_tittle[i] = aux;
				i++;
			}
			strcpy(aux_edge.Tittle, buff_tittle);

		}
	}
	return 0;
}
int compareValues(Type data1, Type data2){
	return 0;
}
void printValue(Type data){

}
unsigned indexValue(Type data, unsigned size){
	return 0;
}



