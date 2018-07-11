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
	char Tagline[40];
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



