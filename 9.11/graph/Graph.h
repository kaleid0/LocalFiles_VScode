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
    int getVertices() { return numVertices; }//���ض�����
    int getEdges() { return numEdges; }//���ر���
    virtual T getValue(int i) = 0;//���ض���i��ֵ
    virtual E getWeight(int v1, int v2) = 0;//���رߵ�Ȩֵ
    virtual int getFirstNeighbor(int v) = 0;//ȡ����v�ĵ�һ���ڽӵ�
    virtual int getNextNeighbor(int v, int w) = 0;//ȡ�ڽӶ���W����һ���ڽӵ�
    virtual bool insertVertex(const T &vertex) = 0;//����һ������
    virtual bool insertEdge(int v1, int v2, E cost) = 0;//����������֮��ı�
    virtual bool removeVertex(int v) = 0;//ɾ�������Լ���ر�
    virtual bool removeEdge(int v1, int v2) = 0;//ɾ����

protected:
    int maxVertices;
    int numEdges;
    int numVertices;
    virtual int getVertexPos(T vertex) = 0;//����������ͼ�е�λ��
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
    int dest; //�ߵ���һ�ڵ�
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


