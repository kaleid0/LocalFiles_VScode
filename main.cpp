#include <iostream>
using namespace std;
class Tree{
public:
virtual void fa(){cout<<"Tree:higher"<<endl;}
virtual void fb(){cout<<"Tree:lower"<<endl;}
virtual int fc(int m){ return 3*m; }
};
class Grass:public Tree{
public:
void fa(){cout<<"Grass:wide"<<endl;}
void fc(){cout<<"Grass:thin"<<endl;}
};
class Leaf:public Grass{
public:
void fa(){cout<<"Leaf:green"<<endl;}
void fb(int i=0){cout<<"Leaf_age:"<<i<<endl;}
int fc(int n=1){cout<<"Leaf_num="<<n<<endl;return 0;}
};
int main(void)
{
Grass a;
Leaf b;
Tree c,*p=&b;
a.fc();
p->fa();
p->fb();
b.fb(c.fc(6));
b.fc(p->fc(6));
}
