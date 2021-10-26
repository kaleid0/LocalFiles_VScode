#include <iostream>
#include"stack.h"

using namespace std;

int main(){
    stack<char> s;
    for (int i = 0; i < 20;i++){
        char y = 'A' + i;
        s.push(y);
    }
    for (int i = 0; i < 10;i++){
        cout << s.gettop() << ',';
        s.pop();
    }
    system("pause");
}