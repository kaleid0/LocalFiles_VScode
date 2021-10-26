#include"Graph.h"

template<class T,class E>
class Graphmtx:public Graph<T,E>{
    friend istream &operator>>(istream &in, Graphmtx<T, E> &G);
    friend ostream &operator<<(ostream &in, Graphmtx<T, E> &G);
public:
    Graphmtx(int sc = DefaultVertices);
    ~Graphmtx(){
        delete[] VerticesList;
        delete[] Edge;
    }
    T getValue(int i){
        return i >= 0 && i <= numVertices ? VerticesList[i] : NULL;
    }
    E getWeight(int v1,int v2){
        return v1 != -1 && v2 != -1 ? Edge[v1][v2] : 0;
    }
    int getFirstNeighbor(int v);
    int getNextNeighbor(int v, int w);
    bool insertVertex(const T &vertex);
    bool insertEdge(int v1, int v2, E cost);
    bool removeVertex(int v);
    bool removeEdge(int v1, int v2);
private:
    T *VerticesList;
    E **Edge;
    int getVertexPos(T vertex){
        for (int i = 0; i < numVertices;i++){
            if(VerticesList[i]==Vertix)
                return i;
            return -1;
        }
    }
};

