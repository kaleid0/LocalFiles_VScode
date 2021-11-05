#include<iostream>
#include<fstream>
<<<<<<< HEAD
#include<cmath>

using namespace std;

int main(){
    
=======


using namespace std;

int main(){
    fstream a, b;
    a.open("file1.txt");
    a.write("123", 3);
    b.open("file.txt");
    for (int i = 1; i < 1000;i++)
        a << i ;
    int x;
    while(a>>x){
        b << x;
    }
    system("pause");
>>>>>>> 8dcb53244467235b84155ef47c2eb236035b450a
}