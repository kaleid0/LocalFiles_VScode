#include"Graph.h"


template<class T,class E>
struct Edge{
    int dest; //边的另一节点
    E cost;
    Edge<T, E> *link;
    Edge(){}
    Edge(int num,E weight):dest(num),cost(weight),link(NULL){}
    bool operator!=(Edge<T,E> &R)const{
        return (dest != R.dest) ? true : false;
    }
};

template<class T,class E>
struct Vertex{
    T data;
    Edge<T, E> *adj;
};

template<class T,class E>
class Graphlnk:public Graph<T,E>{
    friend istream &operator>>(istream &in, Graphlnk<T, E> &G);
    friend ostream &operator<<(ostream &out, Graphlnk<T, E> &G);
public:
    Graphlnk(int sz = DefaultVertices);
    ~Graphlnk();
    T getValue(int i){
        return (i >= 0 && i < numVertices) ? Nodetable[i].data : 0;
    }
    E getWeight(int v1, int v2);
    int getFirstNeighbor(int v);
    int getNextNeighbor(int v, int w);
    bool insertVertex(const T &vertex);
    bool insertEdge(int v1, int v2, E cost);
    bool removeVertex(int v);
    bool removeEdge(int v1, int v2);

private:
    Vertex<T, E> *Nodetable;
    int getVertexpos(const T vertex){
        for (int i = 0; i < numVertices;i++)
            if(Nodetable[i].data==Vertex)
                return i;
        return -1;
    }
};

