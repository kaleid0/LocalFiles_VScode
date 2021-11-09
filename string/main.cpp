#include<iostream>
#include<cstring>

using namespace std;

int match(char *a, char *b){
    int lena = strlen(a);
    int lenb = strlen(b);
    int T[lena + 1][lenb + 1];
    for (int i = 0; i < lena + 1; i++)
        T[i][0] = 0;
    for (int i = 0; i < lenb + 1; i++)
        T[0][i] = 0;
    for (int i = 1; i <= lena; i++){
        for (int j = 1; j <= lenb; j++){
            if(a[i-1]==b[j-1])
                T[i][j] = T[i - 1][j - 1] + 1;
            else if(T[i-1][j]>=T[i][j-1])
                T[i][j] = T[i - 1][j];
            else
                T[i][j] = T[i][j - 1];
            cout << T[i][j] << ',';

        }
        cout << endl;
    }
    return T[lena][lenb];
}

int match2(char *a, char *b){
    int lena = strlen(a), lenb = strlen(b);
    int max = 0, n;
    for (int i = 0; i < lena; i++){
        n = 1;
        for (int j = 0; (i + j) < lena && j < lenb; j++)
        {
            if(a[i+j]==b[j])
                n++;
            else{
                max = n > max ? n : max;
                n = 0;
            }
        }
    }
    return max;
}

int main(){
    char *a = "3298abcfodk";
    char *b = "324abcfds";
    int len = match2(a, b);
    cout << len << endl;
}