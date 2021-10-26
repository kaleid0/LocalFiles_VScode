#pragma once
#include<queue>
#include<stack>
#include"Graph.h"
#include"Graph.cpp"

MGraph AltoM(const AlGraph &A);
void DFStraverse(const Graph &G);
void DFS(const Graph &G, int i, bool visited[]);
void BFStraverse(const Graph &G);
void BFS(const Graph &G, int i, bool visited[]);
bool isTree(const Graph &G);
void DFStree(const Graph &G, int i, int &vnum, int &edgenum, bool visited[]);
void DFStraverse2(const Graph &G);//非递归
void DFS2(const Graph &G, int i, bool visited[]);
bool pathDFS(const Graph &G, int a, int b);
bool DFSp(const Graph &G, int a, int b, bool visited[]);
bool pathBFS(const Graph &G, int a, int b);
bool BFSp(const Graph &G, int a, int b, bool visited[]);
bool pathDFS(const Graph &G, char a, char b);
bool pathBFS(const Graph &G, char a, char b);
void printpath(const MGraph &G, char a, char b);
void printpath(const MGraph &G, int a, int b);
void DFSprint(const MGraph &G, int a, int b, int d, int path[], bool visited[]);
void printpath(const AlGraph &G, char a, char b);
void printpath(const AlGraph &G, int a, int b);
void DFSprint(const AlGraph &G, int a, int b, int d, int path[], bool visited[]);
void toposort(const DMGraph &G);
void component(const Graph &G);//连通分量
void DFS_c(const Graph &G, int k, int A[], int &n, bool visited[]);
bool isCircle(const MGraph &G);
bool isCircle(const AlGraph &G);
bool topoCircle(const Graph &G, int indegree[]);
void indegree(const MGraph &G, int A[]);
void indegree(const AlGraph &G, int A[]);

MGraph AltoM(const AlGraph &A)
{
    MGraph M;
    int n = A.vexnum;
    M.edgenum = A.edgenum;
    M.vexnum = n;
    EdgeNode *e;
    for (int i = 0; i < n; i++){
        M.vex[i] = A.adjlist[i].name;
        e = A.adjlist[i].first;
        for (int j = 0; j < n; j++)
            M.Edge[i][j] = 0;
        while(e != nullptr){
            M.Edge[i][e->adjvex] = e->weight;
            e = e->next;
        }
    }
    return M;
}

void DFStraverse(const Graph &G){
    bool visited[MaxVertexNum];
    for (int i = 0; i < G.getvnum(); i++)
        visited[i] = false;
    for (int i = 0; i < G.getvnum(); i++){
        if(!visited[i])
            DFS(G, i, visited);
    }
}

void DFS(const Graph &G, int i, bool visited[]){
    visited[i] = true;
    G.visit(i);
    for (int w = G.FirstNeighbor(i); w >= 0; w = G.NextNeighbor(i,w)){
        if(!visited[w])
            DFS(G, w, visited);
    }
}

void BFStraverse(const Graph &G){
    bool visited[MaxVertexNum];
    for (int i = 0; i < G.getvnum(); i++)
        visited[i] = false;
    for (int i = 0; i < G.getvnum(); i++){
        if (!visited[i])
            BFS(G, i, visited);
    }
}

void BFS(const Graph &G, int i, bool visited[]){
    visited[i] = true;
    G.visit(i);
    queue<int> Q;
    Q.push(i);
    while(!Q.empty()){
        int vertex = Q.front();
        Q.pop();
        for (int w = G.FirstNeighbor(vertex); w >= 0; w = G.NextNeighbor(vertex, w)){
            if(!visited[w]){
                G.visit(w);
                visited[w] = true;
                Q.push(w);
            }
        }
    }
}

bool isTree(const Graph &G){
    bool visited[MaxVertexNum];
    for (int i = 0; i < G.getvnum(); i++)
        visited[i] = false;
    int vnum = 0, edgenum = 0;
    DFStree(G, 0, vnum, edgenum, visited);
    if(vnum==G.getvnum()&&edgenum==(vnum-1)*2)
        return true;
    return false;
}

void DFStree(const Graph &G, int i, int &vnum, int &edgenum, bool visited[]){
    visited[i] = true;
    vnum++;
    for (int w = G.FirstNeighbor(i); w >= 0; w = G.NextNeighbor(i,w)){
        edgenum++;
        if(!visited[w]){
            
            DFStree(G, w, vnum, edgenum, visited);
        }
    }
}

void DFStraverse2(const Graph &G){
    bool visited[MaxVertexNum];
    for (int i = 0; i < G.getvnum(); i++)
        visited[i] = false;
    for (int i = 0; i < G.getvnum(); i++){
        if(!visited[i])
            DFS2(G, i, visited);
    }
}

void DFS2(const Graph &G, int i, bool visited[]){
    stack<int> s;
    s.push(i);
    while(!s.empty()){
        int t = s.top();
        s.pop();
        G.visit(t);
        visited[t] = true;
        for (int w = G.FirstNeighbor(t); w >= 0; w = G.NextNeighbor(t, w)){
            if(!visited[w]){
                s.push(w);
                visited[w] = true;
            }
        }
    }
}

bool pathDFS(const Graph &G, int a, int b){
    bool visited[MaxVertexNum];
    for (int i = 0; i < G.getvnum(); i++)
        visited[i] = false;
    return DFSp(G, a, b, visited);
}

bool DFSp(const Graph &G, int a, int b, bool visited[]){
    visited[a] = true;
    if(a==b)
        return true;
    else{
        for (int w = G.FirstNeighbor(a); w >= 0; w=G.NextNeighbor(a,w)){
            if(!visited[w]){
                if(DFSp(G, w, b, visited))
                    return true;
            }
        }
    }
    return false;
}

bool pathBFS(const Graph &G, int a, int b){
    bool visited[MaxVertexNum];
    for (int i = 0; i < G.getvnum(); i++)
        visited[i] = false;
    return BFSp(G, a, b, visited);
}

bool BFSp(const Graph &G, int a, int b, bool visited[]){
    queue<int> q;
    q.push(a);
    int k;
    while(!q.empty()){
        k = q.front();
        q.pop();
        visited[k] = true;
        if (k == b)
            return true;
        else{
            for (int w = G.FirstNeighbor(k); w >= 0; w = G.NextNeighbor(k, w)){
                if(!visited[w]){
                    q.push(w);
                    visited[w] = true;
                }
            }
        }
    }
    return false;
}

bool pathDFS(const Graph &G, char a, char b){
    int u = G.cEdge(a), v = G.cEdge(b);
    return pathDFS(G, u, v);
}

bool pathBFS(const Graph &G, char a, char b){
    int u = G.cEdge(a), v = G.cEdge(b);
    return pathBFS(G, u, v);
}

void printpath(const MGraph &G, char a, char b){
    int u = G.cEdge(a), v = G.cEdge(b);
    printpath(G, u, v);
}

void printpath(const MGraph &G, int a, int b){
    bool visited[MaxVertexNum];
    for (int i = 0; i < G.getvnum(); i++)
        visited[i] = false;
    int path[MaxVertexNum];
    DFSprint(G, a, b, 0, path, visited);
}

void DFSprint(const MGraph &G, int a, int b, int d, int path[], bool visited[]){
    path[d] = a;
    visited[a] = true;
    if(a==b){
        for (int i = 0; i <= d; i++)
            cout << G.vex[path[i]];
        cout << endl;
    }
    int i = G.FirstNeighbor(a);
    while(i!=-1){
        if(!visited[i]){
            visited[i] = true;
            DFSprint(G, i, b, d + 1, path, visited);
        }
        i = G.NextNeighbor(a, i);
    }
    visited[a] = false;
}

void printpath(const AlGraph &G, char a, char b){
    int u = G.cEdge(a), v = G.cEdge(b);
    printpath(G, u, v);
}

void printpath(const AlGraph &G, int a, int b){
    bool visited[MaxVertexNum];
    for (int i = 0; i < G.getvnum(); i++)
        visited[i] = false;
    int path[MaxVertexNum];
    DFSprint(G, a, b, 0, path, visited);
}

void DFSprint(const AlGraph &G, int a, int b, int d, int path[], bool visited[]){
    path[d] = a;
    visited[a] = true;
    if(a==b){
        for (int i = 0; i <= d; i++)
            G.visit(i);
        cout << endl;
    }
    int i = G.FirstNeighbor(a);
    while(i!=-1){
        if(!visited[i]){
            visited[i] = true;
            DFSprint(G, i, b, d + 1, path, visited);
        }
        i = G.NextNeighbor(a, i);
    }
    visited[a] = false;
}

void toposort(const DMGraph &G){
    queue<int> q;
    int indegree[MaxVertexNum];
    int n = 0;
    for (int i = 0; i < G.vexnum; i++){
        indegree[i] = 0;
        for (int j = 0; j < G.vexnum; j++){
            if(G.Edge[j][i]!=0)
                indegree[i]++;
        }
        if(indegree[i]==0)
            q.push(i);
    }
    while(!q.empty()){
        int k = q.front();
        q.pop();
        cout << G.vex[k];
        n++;
        for (int w = G.FirstNeighbor(k); w >= 0; w = G.NextNeighbor(k, w)){
            indegree[w]--;
            if(indegree[w]==0)
                q.push(w);
        }
    }
    if(n<G.vexnum)
        cout << "无拓扑排序" << endl;
}

void component(const Graph &G){
    bool visited[MaxVertexNum];
    int A[MaxVertexNum];
    for (int i = 0; i < G.getvnum(); i++)
        visited[i] = false;
    for (int i = 0; i < G.getvnum(); i++){
        int n = 0;
        if(!visited[i])
            DFS_c(G, i, A, n, visited);
        for (int j = 0; j < n; j++){
            cout << G.getname(A[j]);
            if(j==n-1)
                cout << endl;
        }
            
    }
}

void DFS_c(const Graph &G, int k, int A[], int &n, bool visited[]){
    A[n++] = k;
    visited[k] = true;
    for (int w = G.FirstNeighbor(k); w >= 0; w = G.NextNeighbor(k, w)){
        if(!visited[w]){
            visited[w] = true;
            DFS_c(G, w, A, n, visited);
        }
    }
}

bool isCircle(const MGraph &G){
    int inde[MaxVertexNum];
    indegree(G, inde);
    return topoCircle(G, inde);
}

bool isCircle(const AlGraph &G){
    int inde[MaxVertexNum];
    indegree(G, inde);
    return topoCircle(G, inde);
}

bool topoCircle(const Graph &G, int indegree[]){
    queue<int> q;
    for (int i = 0; i < G.getvnum(); i++)
        if(indegree[i]==0)
            q.push(i);
    while(!q.empty()){
        int k = q.front();
        q.pop();
        for (int w = G.FirstNeighbor(k); w >= 0; w = G.NextNeighbor(k, w)){
            indegree[w]--;
            if(indegree[w]==0)
                q.push(w);
        }
    }
    for (int i = 0; i < G.getvnum(); i++){
        cout << indegree[i]<<i;
        if(indegree[i]>0)
            return true;
    }
    return false;
}

void indegree(const MGraph &G, int A[]){
    for (int i = 0; i < G.getvnum(); i++){
        int degr = 0;
        for (int j = 0; j < G.getvnum(); j++)
            if(G.Edge[j][i]!=0)
                degr++;
        A[i] = degr;
    }
}

void indegree(const AlGraph &G, int A[]){
    EdgeNode *e;
    for (int i = 0; i < G.vexnum; i++)
        A[i] = 0;
    for (int i = 0; i < G.vexnum; i++){
        e = G.adjlist[i].first;
        while (e != nullptr){
            A[e->adjvex]++;
            e = e->next;
        }
    }    
}





