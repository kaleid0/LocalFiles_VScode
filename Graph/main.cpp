#include<iostream>
#include"Graph.h"
#include"Graph.cpp"
#include"function.h"


using namespace std;

int main(){
    cout << "hello" << endl;
    char a[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', '\0'};
    int m1[][MaxVertexNum] = {
        {0, 1, 0, 0, 1, 0, 0},
        {1, 0, 1, 0, 1, 1, 0},
        {0, 1, 0, 1, 0, 1, 0},
        {0, 0, 1, 0, 1, 0, 1},
        {1, 1, 0, 1, 0, 0, 0},
        {0, 1, 1, 0, 0, 0, 0},
        {0, 0, 0, 1, 0, 0, 0}
    };
    int m2[][MaxVertexNum] = {
        {0, 1, 0, 0, 1, 0, 0},
        {1, 0, 1, 0, 0, 1, 0},
        {0, 1, 0, 0, 0, 0, 1},
        {0, 0, 0, 0, 1, 0, 0},
        {1, 0, 0, 1, 0, 0, 0},
        {0, 1, 0, 0, 0, 0, 0},
        {0, 0, 1, 0, 0, 0, 0}
    };
    int m3[][MaxVertexNum] = {
        {0, 1, 0, 0, 1, 0, 0},
        {0, 0, 1, 0, 1, 1, 0},
        {0, 0, 0, 1, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 1},
        {0, 0, 0, 1, 0, 0, 0},
        {0, 0, 1, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0}
    };
    int m4[][MaxVertexNum] = {
        {0, 1, 0, 0, 1, 0, 0},
        {0, 0, 1, 0, 1, 1, 0},
        {0, 0, 0, 1, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 1},
        {0, 0, 0, 1, 0, 0, 0},
        {0, 0, 1, 0, 0, 0, 0},
        {1, 0, 0, 0, 0, 0, 0}
    };

    MGraph G1(a, m1, 7);//无向图
    MGraph G2(a, m2, 7);//树
    MGraph G3(a, m3, 7);//无环有向图
    MGraph G4(a, m4, 7);//有环有向图

    AlGraph G5(G1);

    int t=G5.NextNeighbor('A', 'B');

    bool i1 = isCircle(G1);
    bool i2 = isCircle(G2);
    bool i3 = isCircle(G3);
    bool i4 = isCircle(G4);

    printpath(G1, 'A', 'G');
    printpath(G2, 'A', 'G');

    bool b1 = G1.Adjacent('A', 'B');
    bool b2 = G1.Adjacent('A', 'D');
    bool b3 = G2.Adjacent('A', 'B');
    bool b4 = G2.Adjacent('A', 'D');

    int c1 = G1.FirstNeighbor('A');
    int c2 = G2.FirstNeighbor('A');
    int c3 = G1.NextNeighbor('E', 'B');
    int c4 = G2.NextNeighbor('E', 'B');

    int r1 = G1.GetEdgeValue('A', 'B');
    int r2 = G2.GetEdgeValue('A', 'B');

    G2.Neighbors('E');

    cout << "s"<<endl;
}