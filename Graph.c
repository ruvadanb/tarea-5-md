#include <stdio.h>
#include <stdlib.h>
#include "Graph.h"

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
		newGraph->array = (Node*)malloc(sizeof(Node));
	}
	return newGraph;
}

void graph_destroy(Graph g){
	int i=0;
	while(g->array[i]->next!=NULL){
		free(g->array[i]);
		i++;
	}
	free(g->array[i]);
	free(g);
}

boolean graph_addVertex(Graph g, Type data){ //No supe hacer esta
	if(g!=NULL){
		Node nuevo;
		nuevo=newNode(data, &contador);
		g->array=(Node*)realloc(g->array, sizeof(Node)*(contador+1));
		g->array[g->vertices]=nuevo;
		g->vertices++;
		return true;
	}
	else
		return false;
}

boolean graph_addEdge(Graph g, Type source, Type skin){
	int i=0, inicial=-1, final=-1;
	for(i=0; i<g->vertices; i++){
		if(comparar(g->array[i]->Data, source)==1){
			inicial=i;
		}
		if(comparar(g->array[i]->Data, skin)==1){
			final=i;
		}
	}
	if(inicial!=-1&&final!=-1){
		g->array[inicial]->next=&g->array[final];
		g->aristas++;
		return true;
	} else {
		return false;
	}
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
	int i=0, contador=0;
	Node temp;
	while(comparar(g->array[i]->Data, source)!=1)
		i++;
	temp = g->array[i];
	while(temp->next!=NULL){
		contador++;
	}
	return contador;
}

boolean buscarDatoEnGrafo(Node inicio, Type datoFinal){
	if(comparar(inicio->Data, datoFinal)==1){
		return true;
	} else {
		return buscarDatoEnGrafo(inicio->next, datoFinal);
	}
}

boolean graph_hasEdge(Graph g, Type source, Type skin){
	int i=0, inicial=-1, final=-1;
	for(i=0; i<g->vertices; i++){
		if(comparar(g->array[i]->Data, source)==1){
			inicial=i;
		}
		if(comparar(g->array[i]->Data, skin)==1){
			final=i;
		}
	}
	if(inicial!=-1&&final!=-1){
		if(buscarDatoEnGrafo(g->array[inicial], skin)==false)
			return false;
		else
			return true;
	} else {
		return false;
	}
}

boolean graph_print(Graph g, Print p){

}
