#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MaxVertexNum 1000


typedef int Vertex;
typedef bool WeightType;


/* ADT - Graph: DataObjects and Operations */

typedef struct GNode * PtrToGNode;
struct GNode {
    int Nv;
    int Ne;
    WeightType G[MaxVertexNum][MaxVertexNum];
};
typedef PtrToGNode MGraph;

typedef struct ENode * PtrToENode;
struct ENode {
    Vertex V, W;
};
typedef PtrToENode Edge;


MGraph CreateGraph(int VertexNum);
void InsertEdge(MGraph Graph, Edge E);
int BFS(MGraph Graph, Vertex V, bool Visited[], int CL, int ML);


typedef Vertex ElementType;

/* ADT - Queue: DataObjects and Operations */

typedef struct Node * PtrToNode;
struct Node {
    ElementType Data;
    PtrToNode Next;
};

typedef PtrToNode Position;
typedef struct QNode * PtrToQNode;
struct QNode {
    Position Front, Rear;
};
typedef PtrToQNode Queue;


Queue CreateQueue();
bool IsEmpty(Queue Q);
bool Push(Queue Q, ElementType X);
ElementType Pop(Queue Q);


int main()
{
    int N, L;
    scanf("%d %d", &N, &L);

    MGraph Graph = CreateGraph(N);

    for(int i = 0, mi; i < N; i++) {
        Edge E = (Edge)malloc(sizeof(struct ENode));
        E->V = i;
        scanf("%d", &mi);
        for(int j = 0; j < mi; j++) {
            scanf("%d", &E->W);
            E->W -= 1;
            InsertEdge(Graph, E);
        }
    }

    int K;
    scanf("%d", &K);
    for(int i = 0; i < K; i++) {
        Vertex T;
        bool Visited[MaxVertexNum] = {false};
        scanf("%d", &T);
        printf("%d\n", BFS(Graph, T - 1, Visited, 0, L));
    }
    return 0;
}


MGraph CreateGraph(int VertexNum)
{
    MGraph Graph = (MGraph)malloc(sizeof(struct GNode));
    Graph->Nv = VertexNum;
    Graph->Ne = 0;
    for(int i = 0; i < VertexNum; i++)
        for(int j = 0; j < VertexNum; j++)
            Graph->G[i][j] = false;
    return Graph;
}

void InsertEdge(MGraph Graph, Edge E)
{
    Graph->G[E->V][E->W] = true;
    Graph->Ne++;
}

int BFS(MGraph Graph, Vertex V, bool Visited[], int CL, int ML)
{
    int cnt = 0;
    Queue Q = CreateQueue();
    Push(Q, V);
    Visited[V] = true;

    int last = V, tail = V;
    while (!IsEmpty(Q)) {
        V = Pop(Q);
        for(int i = 0; i < Graph->Nv; i++) {
            if(!Visited[i] && Graph->G[i][V]) {
                Push(Q, i); Visited[i] = true;
                tail = i;
                cnt++;
            }
        }
        if(V == last) {
            last = tail;
            CL++;
        }
        if(CL == ML) break;
    }
    return cnt;
}


Queue CreateQueue()
{
    Queue Q = (Queue)malloc(sizeof(struct QNode));
    Q->Front = (Position)malloc(sizeof(struct Node));
    Q->Rear = (Position)malloc(sizeof(struct Node));
    Q->Front = Q->Rear = NULL;
    return Q;
}

bool IsEmpty(Queue Q) {
    return (Q->Front == NULL);
}

bool Push(Queue Q, ElementType X)
{
    Position PushCell = (Position)malloc(sizeof(struct Node));
    PushCell->Data = X; PushCell->Next = NULL;
    if(IsEmpty(Q))
        Q->Front = Q->Rear = PushCell;
    else {
        Q->Rear->Next = PushCell;
        Q->Rear = PushCell;
    }
    return true;
}

ElementType Pop(Queue Q)
{
    Position PopCell = Q->Front;
    ElementType PopElem = PopCell->Data;
    Q->Front = PopCell->Next;
    free(PopCell);
    return PopElem;
}