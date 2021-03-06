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

typedef struct {
	char retweet_id[20]; //edge entre source
	char tweet_id[20];	//skin
}Vertex;

int main(void) {
	setvbuf(stderr, NULL, _IONBF, 0);
	setvbuf(stdout, NULL, _IONBF, 0);
	puts("!!!Graph Retweets!!!");
	FILE *vertex_tweets = fopen("RETWEETS.csv", "r");

	if(vertex_tweets == NULL){
		printf("Error al abrir archivo.");
		return 0;
	}
	printf("Comenzando...\n");
	Vertex tweets_data;

	short i = 0, k = 0;
	char aux;
	Graph g1 = graph_create(compareValues, printValue, indexValue);
	while(!feof(vertex_tweets)){
		char buff_retweet[20]="";
		char buff_tweet[20]="";
		i = 0;
		while((aux = fgetc(vertex_tweets)!=',') && i < 20 && aux != EOF){
			buff_retweet[i] = aux;
			i++;
		}
		i = 0;
		while((aux = fgetc(vertex_tweets)!=',') && i < 20 && aux != EOF){
			buff_tweet[i] = aux;
			i++;
		}
		strcpy(tweets_data.retweet_id,buff_retweet);
		strcpy(tweets_data.tweet_id,buff_tweet);
		if(graph_addVertex(g1,&tweets_data.retweet_id))printf("V�rtice agregado.\t");
		if(graph_addVertex(g1,&tweets_data.tweet_id))printf("V�rtice tweet agregado.\t");
		if(graph_addEdge(g1,&tweets_data.retweet_id, &tweets_data.tweet_id))printf("Edge agregado. \n");
	}

	printf("End...\n");
	return EXIT_SUCCESS;
}
int compareValues(Type data1, Type data2){
	char *d1 = (char*)data1;
	char *d2 = (char*)data2;
	return strcmp(d1,d2);
}
void printValue(Type data){
	Vertex aux = *(Vertex *)data;
	printf("Retweet: %s\tTweet: %s\n",aux.retweet_id, aux.tweet_id);
}
unsigned indexValue(Type data , unsigned size){
	Vertex aux = *(Vertex * )data;
	unsigned index;
	short i;
	for(i= 0; i<4; i++){
		index += aux.retweet_id[i];
	}
	return index%size;
}
