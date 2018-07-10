struct strNode{
	Type Data;
	struct strNode *first, *next;
	int id;
};

typedef struct strNode Node;
 
struct strGraph{ //No sé si esté bien esta estructura
	Node *array=(Type)malloc(sizeof(Type));  //Como tiene que ser un arreglo de vertices mejor usar Node
	int vertices, aristas;
	CMP cmpFunction;
	Print printFunction;
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

Graph graph_create(CMP comparar, Print printFunction){
	Graph newGraph=(Graph)malloc(sizeof(struct strGraph));
	if(newGraph!=NULL){
		newGraph->aristas=0;
		newGraph->vertices=0;
		newGraph->cmpFunction=comparar;
		newGraph->printFunction=printFunction;
	}
	return newGraph;
}

void graph_destroy(Graph g){
	free(g);
}

boolean graph_addVertex(Graph g, Type data){ //No supe hacer esta
	if(g!=NULL){
		Node newNode;
		g->array[g->vertices]=data;
		g->vertices++;
		newNode->first=g;
		newNode->next=NULL;
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
