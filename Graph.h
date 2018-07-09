typedef enum {false,true} boolean;
typedef void* Type;
typedef struct strGraph *Graph;
typedef void (*Print) (void *);

typedef int (*CMP)(void *, void *);
typedef Type (*Clone)(Type);
typedef void (*MyFree)(Type);
typedef void (*Print)(Type);

void graph_destroy(Graph g);
boolean graph_addVertex(Graph g, Type data);
boolean graph_addEdge(Graph g, Type source, Type skin);
unsigned long graph_vertexCount(Graph g);
unsigned long graph_edgeCount(Graph g);
unsigned long graph_outDegree(Graph g, Type source);
boolean graph_hasEdge(Graph g, Type source, Type skin);
boolean graph_print(Graph g, Print p);
