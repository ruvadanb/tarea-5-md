#include <stdio.h>
#include <stdlib.h>
#include "grafo.h"

int contador=0;

struct strNode{
	Type Data;
	struct strNode *first, *next;
	int id;
};

typedef struct strNode *Node;

Node newNode(Type data, int* contador){
	Node new=(Node)malloc(sizeof(Node));
	if(new!=NULL){
		new->first=NULL;
		new->next=NULL;
		new->id=*contador;
		new->Data=data;
	}
	(*contador)++;
	return new;
}

struct strGraph{ //No sé si esté bien esta estructura
	Node *array;
	//Como tiene que ser un arreglo de vertices mejor usar Node
	int vertices, aristas;
	CMP cmpFunction;
	Print printFunction;
};


Graph graph_create(CMP comparar, Print printFunction){
	Graph newGraph=(Graph)malloc(sizeof(struct strGraph));
	if(newGraph!=NULL){
		newGraph->aristas=0;
		newGraph->vertices=0;
		newGraph->cmpFunction=comparar;
		newGraph->printFunction=printFunction;
		newGraph->array = (Node)malloc(sizeof(Node));
	}
	return newGraph;
}

void graph_destroy(Graph g){
	int i;
	while(g->array[i]->next!=NULL){
		free(g->array[i]);
		i++;
	}
	free(g);
}

boolean graph_addVertex(Graph g, Type data){ //No supe hacer esta
	if(g!=NULL){
		Node nuevo;
		nuevo=newNode(data, &contador);
		g->array[g->vertices]=data;
		g->vertices++;
	}
}

boolean graph_addEdge(Graph g, Type source, Type skin){

}

unsigned long graph_vertexCount(Graph g){
	if(g!=NULL)
		return g->vertices;
	else
		return -1;
}

unsigned long graph_edgeCount(Graph g){
	if(g!=NULL)
		return g->aristas;
	else
		return -1;
}

unsigned long graph_outDegree(Graph g, Type source){

}

boolean graph_hasEdge(Graph g, Type source, Type skin){

}

boolean graph_print(Graph g, Print p){

}
