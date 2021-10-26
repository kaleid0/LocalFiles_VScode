#pragma once
#include<iostream>

using namespace std;

const int MaxVertexNum = 50;

class Graph;//图
class MGraph;//邻接矩阵
class DMGraph;//有向邻接矩阵
class AlGraph;//邻接表
class DAlGraph;//有向邻接表



class Graph{
public:
    virtual char getname(int i) const = 0;
    virtual int cEdge(char a) const = 0;
    virtual int getvnum() const = 0;
    virtual int getenum() const = 0;
    virtual void visit(int i) const = 0;

    virtual bool Adjacent(char a, char b) const = 0;
    virtual void Neighbors(char x) const = 0;
    virtual void InsertVertex(char x) = 0;
    virtual void InsertEdge(char a, char b, int weight) = 0;
    virtual void DeleteVertex(char x) = 0;
    virtual void DeleteEdge(char a, char b) = 0;
    virtual int FirstNeighbor(char a) const = 0;
    virtual int FirstNeighbor(int i) const = 0;
    virtual int NextNeighbor(char a, char b) const = 0;
    virtual int NextNeighbor(int a, int b) const = 0;
    virtual int GetEdgeValue(char a, char b) const = 0;
    virtual void SetEdgeValue(char a, char b, int weight) = 0;
};

class MGraph:public Graph{
public:
	char vex[MaxVertexNum];
	int Edge[MaxVertexNum][MaxVertexNum];
	int vexnum, edgenum;

    MGraph(){
        vexnum = 0;
        edgenum = 0;
    }
    MGraph(int v, int e){
        vexnum = v;
        edgenum = e;
    }
    MGraph(char V[], int E[][MaxVertexNum], int n);
    MGraph(const MGraph &MG);
    virtual char getname(int i) const { return vex[i]; }
    virtual int cEdge(char a) const;
    virtual int getvnum() const { return vexnum; }
    virtual int getenum() const { return edgenum; }
    virtual void visit(int i) const { cout << vex[i]; }

    MGraph power(int n) const;
    MGraph operator*(const MGraph MG) const;

    virtual void InsertEdge(char a, char b, int weight);
    virtual void InsertVertex(char x);
    virtual bool Adjacent(char a, char b) const;
    virtual void Neighbors(char x) const;
    virtual void DeleteVertex(char x);
    virtual void DeleteEdge(char a, char b);
    virtual int FirstNeighbor(char a) const;
    virtual int FirstNeighbor(int i) const;
    virtual int NextNeighbor(char a, char b) const;
    virtual int NextNeighbor(int a, int b) const;
    virtual int GetEdgeValue(char a, char b) const;
    virtual void SetEdgeValue(char a, char b, int weight);
};

class DMGraph:public MGraph{
public:
    DMGraph(){
        vexnum = 0;
        edgenum = 0;
    }
    DMGraph(int v, int e){
        vexnum = v;
        edgenum = e;
    }
    DMGraph(char V[], int E[][MaxVertexNum], int n);
    DMGraph(const DMGraph &MG);

    virtual void InsertEdge(char a, char b, int weight);
    //virtual bool Adjacent(char a, char b) const;
    //virtual void Neighbors(char x) const;
    virtual void DeleteVertex(char x);
    virtual void DeleteEdge(char a, char b);
    //virtual int FirstNeighbor(char a) const;
    //virtual int FirstNeighbor(int i) const;
    //virtual int NextNeighbor(char a, char b) const;
    //virtual int NextNeighbor(int a, int b) const;
    //virtual int GetEdgeValue(char a, char b) const;
    virtual void SetEdgeValue(char a, char b, int weight);
};

typedef struct EdgeNode {
	int adjvex;
	EdgeNode* next;
	int weight;
    EdgeNode(int w, int adj){
        adjvex = adj;
        next = nullptr;
        weight = w;
    }
}EdgeNode;

typedef struct VertexNode {
	char name;
	EdgeNode* first;
    VertexNode(){
        name = '0';
        first = nullptr;
    }
    VertexNode(char x){
        name = x;
        first = nullptr;
    }
    void insertEdge(EdgeNode *e){
        if(first==nullptr)
            this->first = e;
        else{
            EdgeNode *p = first->next;
            while(p!=nullptr)
                p = p->next;
            p->next = e;
        }
    }
}VertexNode;

class AlGraph:public Graph{
public:
	VertexNode adjlist[MaxVertexNum];
	int vexnum, edgenum;

    AlGraph(){
        vexnum = 0;
        edgenum = 0;
    }
    AlGraph(const MGraph &MG);

    virtual char getname(int i) const { return adjlist[i].name; }
    virtual int cEdge(char a) const;
    virtual int getvnum() const { return vexnum; }
    virtual int getenum() const { return edgenum; }
    virtual void visit(int i) const { cout << adjlist[i].name; }

    virtual void InsertEdge(char a, char b, int weight);
    virtual void InsertVertex(char a);
    virtual bool Adjacent(char a, char b) const;
    virtual void Neighbors(char x) const;
    virtual void DeleteVertex(char x);
    virtual void DeleteEdge(char a, char b);
    virtual int FirstNeighbor(char a) const;
    virtual int FirstNeighbor(int i) const;
    virtual int NextNeighbor(char a, char b) const;
    virtual int NextNeighbor(int a, int b) const;
    virtual int GetEdgeValue(char a, char b) const;
    virtual void SetEdgeValue(char a, char b, int weight);
};

class DAlGraph:public AlGraph{
public:
    DAlGraph(){
        vexnum = 0;
        edgenum = 0;
    }
    DAlGraph(const DMGraph &MG);
    // virtual int cEdge(char a) const;
    // virtual int getvnum() const { return vexnum; }
    // virtual int getenum() const { return edgenum; }
    // virtual void visit(int i) const { cout << adjlist[i].name; }

    virtual void InsertEdge(char a, char b, int weight);
    //virtual void InsertVertex(char a);
    //virtual bool Adjacent(char a, char b) const;
    //virtual void Neighbors(char x) const;
    virtual void DeleteVertex(char x);
    virtual void DeleteEdge(char a, char b);
    // virtual int FirstNeighbor(char a) const;
    // virtual int FirstNeighbor(int i) const;
    // virtual int NextNeighbor(char a, char b) const;
    // virtual int NextNeighbor(int a, int b) const;
    // virtual int GetEdgeValue(char a, char b) const;
    virtual void SetEdgeValue(char a, char b, int weight);
};
