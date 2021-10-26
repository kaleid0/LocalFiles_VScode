#include<climits>
#include<iostream>

using namespace std;

const int DefaultVertices = 30;

template<class T,class E>
class Graph{
public:
    const E maxWeight = INT_MAX;
    Graph(int sz = DefaultVertices);
    ~Graph();
    bool isEmpty(){
        if(numEdges==0)
            return true;
        else
            return false;
    }
    bool isFull(){
        if(numVertices==maxVertices||numEdges==maxVertices*(maxVertices-1)/2)
            return true;
        else
            return false;
    }
    int getVertices() { return numVertices; }//返回定点数
    int getEdges() { return numEdges; }//返回边数
    virtual T getValue(int i) = 0;//返回顶点i的值
    virtual E getWeight(int v1, int v2) = 0;//返回边的权值
    virtual int getFirstNeighbor(int v) = 0;//取顶点v的第一个邻接点
    virtual int getNextNeighbor(int v, int w) = 0;//取邻接顶点W的下一个邻接点
    virtual bool insertVertex(const T &vertex) = 0;//插入一个顶点
    virtual bool insertEdge(int v1, int v2, E cost) = 0;//插入两顶点之间的边
    virtual bool removeVertex(int v) = 0;//删除顶点以及相关边
    virtual bool removeEdge(int v1, int v2) = 0;//删除边

protected:
    int maxVertices;
    int numEdges;
    int numVertices;
    virtual int getVertexPos(T vertex) = 0;//给出顶点在图中的位置
};





template<class T,class E>
class Graphmtx:virtual public Graph<T,E>{
    friend istream &operator>>(istream &in, Graphmtx<T, E> &G);
    friend ostream &operator<<(ostream &in, Graphmtx<T, E> &G);
public:
    Graphmtx(int sc = DefaultVertices);
    ~Graphmtx(){
        delete[] VerticesList;
        delete[] Edge;
    }
    T getValue(int i){
        return i >= 0 && i <= Graph<T,E>::numVertices ? VerticesList[i] : NULL;
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
        for (int i = 0; i < Graph<T,E>::numVertices;i++){
            if(VerticesList[i]==vertex)
                return i;
            return -1;
        }
    }
};





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

template<typename T,typename E>
struct Vertex{
    T data;
    Edge<T, E> *adj;
};

template<typename T,typename E>
class Graphlnk:virtual public Graph<T,E>{
    friend istream &operator>>(istream &in, Graphlnk<T, E> &G);
    friend ostream &operator<<(ostream &out, Graphlnk<T, E> &G);
public:
    Graphlnk(int sz = DefaultVertices);
    ~Graphlnk();
    T getValue(int i){
        return (i >= 0 && i < Graph<T,E>::numVertices) ? Nodetable[i].data : 0;
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
        for (int i = 0; i < Graph<T,E>::numVertices;i++)
            if(Nodetable[i].data==vertex)
                return i;
        return -1;
    }
};


