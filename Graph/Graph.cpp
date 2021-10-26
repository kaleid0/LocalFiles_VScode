#pragma once
#include"Graph.h"

MGraph::MGraph(char V[], int E[][MaxVertexNum], int n){
    vexnum = n;
    edgenum = 0;
    for (int i = 0; i < n; i++){
        vex[i] = V[i];
        for (int j = 0; j < n; j++){
            Edge[i][j] = E[i][j];
            if(E[i][j]==1)
                edgenum++;
        }
    }
    edgenum /= 2;
}

MGraph::MGraph(const MGraph &MG){
    vexnum = MG.vexnum;
    edgenum = MG.edgenum;
    for (int i = 0; i < MG.vexnum; i++){
        for (int j = 0; j < MG.vexnum; j++)
            Edge[i][j] = MG.Edge[i][j];
    }
}

int MGraph::cEdge(char a) const{
    for (int i = 0; i < vexnum; i++){
        if(vex[i]==a)
            return i;
    }
    return -1;
}

void MGraph::InsertEdge(char a, char b, int weight){
    int v1 = -1, v2 = -1;
    for (int i = 0; i < vexnum; i++){
        if(vex[i]==a)
            v1 = i;
        if(vex[i]==b)
            v2 = i;
        if(v1>0&&v2>0)
            break;
    }
    Edge[v1][v2] = Edge[v2][v1] = weight;
    edgenum++;
}

void MGraph::InsertVertex(char x){
    vex[vexnum++] = x;
}

MGraph MGraph::power(int n) const{
    MGraph G(*this);
    for (int i = 0; i < n; i++){
        G = G * (*this);
    }
    return G;
}

MGraph MGraph::operator*(const MGraph MG) const{
    MGraph G;
    int n = this->vexnum;
    G.vexnum = n;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            int sum = 0;
            for (int k = 0; k < n; k++){
                sum += this->Edge[i][k] * MG.Edge[k][j];
            }
            G.Edge[i][j] = sum;
            if(sum!=0)
                G.edgenum++;
        }
    }
    G.edgenum /= 2;
    return G;
}

bool MGraph::Adjacent(char a, char b) const{
    int v1 = cEdge(a), v2 = cEdge(b);
    if(v1!=-1&&v2!=-1&&Edge[v1][v2])
        return true;
    else
        return false;
}
    
void MGraph::Neighbors(char x) const{
    int v1 = cEdge(x);
    for (int i = 0; i < vexnum; i++)
        if(Edge[v1][i])
            cout << vex[i] << ',';
}

void MGraph::DeleteVertex(char x){
    int v1 = cEdge(x);
    for (int i = v1; i < vexnum; i++)
        for (int j = 0; j < vexnum; j++){
            if (Edge[i][j] == 1)
                edgenum--;
            Edge[i][j] = Edge[i + 1][j];
        }
    for (int i = v1; i < vexnum; i++)
        for (int j = 0; j < vexnum; j++)
            Edge[j][i] = Edge[j][i + 1];
    for (int i = v1; i < vexnum; i++)
        vex[i] = vex[i + 1];
    vexnum--;
}

void MGraph::DeleteEdge(char a, char b){
    edgenum--;
    int v1 = cEdge(a), v2 = cEdge(b);
    Edge[v1][v2] = Edge[v2][v1] = 0;
}

int MGraph::FirstNeighbor(char a) const{
    int v1 = cEdge(a);
    for (int i = 0; i < vexnum; i++){
        if(Edge[v1][i]==1)
            return i;
    }
    return -1;
}

int MGraph::FirstNeighbor(int x) const{
    for (int i = 1; i < vexnum; i++){
        if(Edge[x][i]==1)
            return i;
    }
    return -1;
}

int MGraph::NextNeighbor(char a, char b) const{
    int v1 = cEdge(a), v2 = cEdge(b);
    for (int i = v2+1; i < vexnum; i++)
        if(Edge[v1][i]!=0)
            return i;
    return -1;
}

int MGraph::NextNeighbor(int a, int b) const{
    for (int i = b+1; i < vexnum; i++)
        if(Edge[a][i]!=0)
            return i;
    return -1;
}

int MGraph::GetEdgeValue(char a, char b) const{
    int v1 = cEdge(a), v2 = cEdge(b);
    return Edge[v1][v2];
}

void MGraph::SetEdgeValue(char a, char b, int weight){
    int v1 = cEdge(a), v2 = cEdge(b);
    Edge[v1][v2] = Edge[v2][v1] = weight;
}



DMGraph::DMGraph(char V[], int E[][MaxVertexNum], int n){
    vexnum = n;
    edgenum = 0;
    for (int i = 0; i < n; i++){
        vex[i] = V[i];
        for (int j = 0; j < n; j++){
            Edge[i][j] = E[i][j];
            if(E[i][j]==1)
                edgenum++;
        }
    }
}

DMGraph::DMGraph(const DMGraph &MG){
    vexnum = MG.vexnum;
    edgenum = MG.edgenum;
    for (int i = 0; i < MG.vexnum; i++){
        for (int j = 0; j < MG.vexnum; j++)
            Edge[i][j] = MG.Edge[i][j];
    }
}

void DMGraph::InsertEdge(char a, char b, int weight){
    int v1 = -1, v2 = -1;
    for (int i = 0; i < vexnum; i++){
        if(vex[i]==a)
            v1 = i;
        if(vex[i]==b)
            v2 = i;
        if(v1>0&&v2>0)
            break;
    }
    Edge[v1][v2] = weight;
    edgenum++;
}

void DMGraph::DeleteVertex(char x){
    int v1 = cEdge(x);
    for (int i = v1; i < vexnum; i++)
        for (int j = 0; j < vexnum; j++){
            if (Edge[i][j] == 1)
                edgenum--;
            Edge[i][j] = Edge[i + 1][j];
        }
    for (int i = v1; i < vexnum; i++)
        for (int j = 0; j < vexnum; j++){
            if(Edge[i][j]==1)
                edgenum--;
            Edge[j][i] = Edge[j][i + 1];
        }
    vexnum--;
}

void DMGraph::DeleteEdge(char a, char b){
    edgenum--;
    int v1 = cEdge(a), v2 = cEdge(b);
    Edge[v1][v2] = 0;
}

void DMGraph::SetEdgeValue(char a, char b, int weight){
    int v1 = cEdge(a), v2 = cEdge(b);
    Edge[v1][v2] = weight;
}



AlGraph::AlGraph(const MGraph &MG){
    vexnum = MG.vexnum;
    edgenum = MG.edgenum;
    for (int i = 0; i < vexnum; i++){
        VertexNode *v = new VertexNode(MG.vex[i]);
        adjlist[i] = *v;
    }
    for (int i = 0; i < vexnum; i++){
        int j = 0;
        while(j < vexnum && MG.Edge[i][j] == 0)
            j++;
        if(j==vexnum)
            continue;
        EdgeNode *e = new EdgeNode(MG.Edge[i][j], j);
        j++;
        adjlist[i].first = e;
        while (j < vexnum){
            if (MG.Edge[i][j] != 0){
                EdgeNode *p = new EdgeNode(MG.Edge[i][j], j);
                e->next = p;
                e = p;
            }
            j++;
        }
        e->next = nullptr;
    }
}

int AlGraph::cEdge(char a) const{
    for (int i = 0; i < vexnum; i++){
        if(adjlist[i].name==a)
            return i;
    }
    return -1;
}

void AlGraph::InsertEdge(char a, char b, int weight){
    int v1 = cEdge(a), v2 = cEdge(b);
    EdgeNode *e = new EdgeNode(weight, v2);
    adjlist[v1].insertEdge(e);
    e = new EdgeNode(weight, v1);
    adjlist[v2].insertEdge(e);
    edgenum++;
}

void AlGraph::InsertVertex(char x){
    VertexNode *v = new VertexNode(x);
    adjlist[vexnum++] = *v;
}

bool AlGraph::Adjacent(char a, char b) const{
    int v1 = cEdge(a), v2 = cEdge(b);
    EdgeNode *e = adjlist[v1].first;
    while(e!=nullptr){
        if(e->adjvex==v2)
            return true;
        e = e->next;
    }
    return false;
}
    
void AlGraph::Neighbors(char x) const{
    int v1 = cEdge(x);
    EdgeNode *e = adjlist[v1].first;
    while(e!=nullptr){
        cout << adjlist[e->adjvex].name << ',';
        e = e->next;
    }    
}

void AlGraph::DeleteVertex(char x){
    int v1 = cEdge(x);
    for (int i = 0; i < vexnum; i++)
        adjlist[i] = adjlist[i + 1];
    vexnum--;
    for (int i = 0; i < vexnum; i++){
        EdgeNode *e = adjlist[i].first;
        if(e->adjvex==v1){
            edgenum--;
            adjlist[i].first = e->next;
            delete e;
            continue;
        }
        EdgeNode *pre = e;
        e = e->next;
        while(e!=nullptr){
            if(e->adjvex==v1){
                edgenum--;
                pre->next = e->next;
                delete e;
            }
        }
    }
}

void AlGraph::DeleteEdge(char a, char b){
    int v1 = cEdge(a), v2 = cEdge(b);
    EdgeNode *e = adjlist[v1].first;
    if(e->adjvex=v2){
        adjlist[v1].first = e->next;
        delete e;
    }
    else{
        EdgeNode *pre = e;
        e = e->next;
        while (e->adjvex != v2){
            pre = e;
            e = e->next;
        }
        pre->next = e->next;
        delete e;
    }
    e = adjlist[v2].first;
    if(e->adjvex=v2){
        adjlist[v1].first = e->next;
        delete e;
    }
    else{
        EdgeNode *pre = e;
        e = e->next;
        while (e->adjvex != v2){
            pre = e;
            e = e->next;
        }
        pre->next = e->next;
        delete e;
    }
}

int AlGraph::FirstNeighbor(char a) const{
    int v1 = cEdge(a);
    return adjlist[v1].first == nullptr ? -1 : adjlist[v1].first->adjvex;
}

int AlGraph::FirstNeighbor(int i) const{
    return adjlist[i].first == nullptr ? -1 : adjlist[i].first->adjvex;
}

int AlGraph::NextNeighbor(char a, char b) const{
    int v1 = cEdge(a), v2 = cEdge(b);
    EdgeNode *e = adjlist[v1].first;
    while(e!=nullptr&&e->adjvex!=v2)
        e = e->next;
    return e != nullptr && e->next != nullptr ? e->next->adjvex : -1;
}

int AlGraph::NextNeighbor(int a, int b) const{
    EdgeNode *e = adjlist[a].first;
    while(e!=nullptr&&e->adjvex!=b)
        e = e->next;
    return e != nullptr && e->next != nullptr ? e->next->adjvex : -1;
}

int AlGraph::GetEdgeValue(char a, char b) const{
    int v1 = cEdge(a), v2 = cEdge(b);
    EdgeNode *e = adjlist[v1].first;
    while(e!=nullptr&&e->adjvex!=v2)
        e = e->next;
    return e == nullptr ? -1 : e->weight;
}

void AlGraph::SetEdgeValue(char a, char b, int weight){
    int v1 = cEdge(a), v2 = cEdge(b);
    EdgeNode *e = adjlist[v1].first;
    while(e!=nullptr&&e->adjvex!=v2)
        e = e->next;
    if(e!=nullptr)
        e->weight = weight;
    e = adjlist[v2].first;
    while(e!=nullptr&&e->adjvex!=v1)
        e = e->next;
    if(e!=nullptr)
        e->weight = weight;
}



DAlGraph::DAlGraph(const DMGraph &MG){
    vexnum = MG.vexnum;
    edgenum = MG.edgenum;
    for (int i = 0; i < vexnum; i++){
        VertexNode *v = new VertexNode(MG.vex[i]);
        adjlist[i] = *v;
    }
    for (int i = 0; i < vexnum; i++){
        int j = 0;
        while(j < vexnum && MG.Edge[i][j] == 0)
            j++;
        EdgeNode *e = new EdgeNode(MG.Edge[i][j], j);
        j++;
        adjlist[i].first = e;
        while (j < vexnum){
            if (MG.Edge[i][j] != 0){
                EdgeNode *p = new EdgeNode(MG.Edge[i][j], j);
                e->next = p;
                e = p;
            }
            j++;
        }
        e->next = nullptr;
    }
}

void DAlGraph::InsertEdge(char a, char b, int weight){
    int v1 = cEdge(a), v2 = cEdge(b);
    EdgeNode *e = new EdgeNode(weight, v2);
    adjlist[v1].insertEdge(e);
    edgenum++;
}

void DAlGraph::DeleteVertex(char x){
    int v1 = cEdge(x);
    EdgeNode *e = adjlist[v1].first;
    while(e!=nullptr){
        edgenum--;
        e = e->next;
    }
    for (int i = 0; i < vexnum; i++)
        adjlist[i] = adjlist[i + 1];
    vexnum--;
    for (int i = 0; i < vexnum; i++){
        EdgeNode *e = adjlist[i].first;
        if(e->adjvex==v1){
            edgenum--;
            adjlist[i].first = e->next;
            delete e;
            continue;
        }
        EdgeNode *pre = e;
        e = e->next;
        while(e!=nullptr){
            if(e->adjvex==v1){
                edgenum--;
                pre->next = e->next;
                delete e;
            }
        }
    }
}

void DAlGraph::DeleteEdge(char a, char b){
    int v1 = cEdge(a), v2 = cEdge(b);
    EdgeNode *e = adjlist[v1].first;
    if(e->adjvex=v2){
        adjlist[v1].first = e->next;
        delete e;
    }
    else{
        EdgeNode *pre = e;
        e = e->next;
        while (e->adjvex != v2){
            pre = e;
            e = e->next;
        }
        pre->next = e->next;
        delete e;
    }
}

void DAlGraph::SetEdgeValue(char a, char b, int weight){
    int v1 = cEdge(a), v2 = cEdge(b);
    EdgeNode *e = adjlist[v1].first;
    while(e!=nullptr&&e->adjvex!=v2)
        e = e->next;
    if(e!=nullptr)
        e->weight = weight;
}