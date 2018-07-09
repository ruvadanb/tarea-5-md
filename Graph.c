struct strNode{
	Type Data;
	struct strNode *first, *next;
	int id;
};

typedef struct strNode Node;

struct strGraph{
	Type *array=(Type)malloc(sizeof(Type));
	int vertices, aristas;
	CMP cmpFunction;
};

Node* newNode(Type data){
	Node *new=(Node*)malloc(sizeof(Node));
	if(new!=NULL){
		new->first=NULL;
		new->next=NULL;
		new->id=0;
		new->Data=data;
	}
	return new;
}

Graph graph_create(CMP comparar){
	Graph newGraph=(Graph)malloc(sizeof(struct strGraph));
	if(newGraph!=NULL){
		newGraph->aristas=0;
		newGraph->vertices=0;
		newGraph->cmpFunction=comparar;
	}
	return newGraph;
}

void graph_destroy(Graph g){
	free(g);
}

boolean graph_addVertex(Graph g, Type data){
	if(g!=NULL){
		Node newNode;
		g->array[g->vertices]=data;
		g->vertices++;
		newNode->id;
	}
}
