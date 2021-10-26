#include <iostream>
#include"Graph.h"

template<class T,class E>
Graphmtx<T,E>::Graphmtx(int sz){
    maxVertices = sz;
    numVertices = 0;
    numEdges = 0;
    int i, j;
    VerticesList = new T[maxVertices];
    Edge = (E **)new E *[maxVertices];//邻接矩阵数组
    for (int i = 0; i < maxVertices;i++)
        Edge[i] = new E *[maxVertices];
    for (int i = 0; i < maxVertices;i++)
        for (int j = 0; j < maxVertices;j++)
            Edge[i][j] == (i == j) ? 0 : maxWeight;
}

template<class T,class E>
int Graphmtx<T,E>::getFirstNeighbor(int v){
    if(v!=-1){
        for (int col = 0; col < numVertices; col++)
            if(Edge[v][col]>0&&Edge[v][col]<maxWeight)
                return col;
    }
    return -1;
}

template<class T,class E>
int Graphmtx<T,E>::getNextNeighbor(int v, int w){
    if(v!=-1&&w!=-1){
        for (int col = w + 1; col < numVertices; col++)
            if(Edge[v][col]>0&&Edge[v][col]<maxWeight)
                return col;
    }
    return -1;
}

template<class T,class E>
bool Graphmtx<T,E>::insertVertex(const T &vertex){
    if(numVertices==maxVertices)
        return false;
    VerticesList[numVertices++] = vertex;
    return true;
}

template<class T,class E>
bool Graphmtx<T,E>::insertEdge(int v1, int v2, E cost){
    if(v1>-1&&v2>-1&&v1<numVertices&&v2<numVertices&&Edge[v1][v2]==maxWeight){
        Edge[v1][v2] = Edge[v2][v1] = cost;
        numEdges++;
        return true;
    }
    else
        return false;
}

template<class T,class E>
bool Graphmtx<T,E>::removeVertex(int v){
    if(v<0||v>=numVertices)
        return false;
    if(numVertices==1)
        return false;
    int i, j;
    VerticesList[v] = VerticesList[numVertices - 1];
    for (i = 0; i < numVertices;i++){
        if(Edge[i][v]>0&&Edge[i][v]<maxWeight)
            numEdges--;
    }
    for (i = 0; i < numVertices;i++){
        Edge[i][v] = Edge[i][numVertices--];
    }
    numVertices--;
    for (j = 0; j < numVertices;j++){
        Edge[v][j] = Edge[numVertices][j];
    }
    return true;
}

template<class T,class E>
bool Graphmtx<T,E>::removeEdge(int v1, int v2){
    if(v1>-1&&v1<numVertices&&v2>-1&&v2<numVertices&&Edge[v1][v2]>0&&Edge[v1][v2]<maxWeight){
        Edge[v1][v2] = Edge[v2][v1] = maxWeight;
        numEdges--;
        return true;
    }
    return false;
}

template<class T,class E>
istream &operator>>(istream &in, Graphmtx<T, E> &G){
    int i, j, k, m, n;
    T e1, e2;
    E weight;
    in >> n >> m;
    for (i = 0; i < n;i++){
        in >> el;
        G.insertVertex(e1);
    }
    i = 0;
    while(i<m){
        in >> e1 >> e2 >> weight;
        j = G.getVertexPos(e1);
        k = G.getVertexPos(e2);
        if(j==-1||k==-1)
            cout << "端点信息错误" << endl;
        else{
            G.insertEdge(j, k, weight);
            i++;
        }
    }
    return in;
}

template<class T,class E>
ostream& operator<<(ostream& out,Graphmtx<T,E>&G){
    int i, j, k, n, m;
    T e1, e2;
    E weight;
    n = G.getVertices();
    m = G.getEdges();
    out << n << "," << m << endl;
    for (j = i + 1; j < n;j++){
        w = G.getWeight(i, j);
        if(w>0&&w<maxWeight){
            e1 = G.getValue(i);
            e2 = G.getValue(j);
            out << "(" << e1 << "," << e2 << "," << w << ")" << endl;
        }
    }
    return out;
}