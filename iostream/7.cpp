#include<iostream>
#include<fstream>

using namespace std;

int main(){
    fstream file("text6.txt", ios::in | ios::out);
    char c;
    while(c=file.get()!=EOF)
        cout << c << endl;
    file.seekp(0, ios::end);
    for (int i = 0; i < 10;i++)
        file << i;
    return 0;
}
