#include<iostream>
#include<vector>

using namespace std;
int findmidnum(int a[], int b[], int n);
vector<int> minthree(int a[], int b[], int c[], int l, int m, int n);
int main(int argc,char* argv[]){
    for (int i = 0; i < argc;i++){
        cout << argv[i] << endl;
    }
        return 0; 
}

vector<int> minthree(int a[],int b[],int c[],int l,int m,int n){
    int i=0,j=0,k=0;
    int r = abs(a[i] - b[j]), s = abs(a[i] - c[k]), t = abs(b[j] - c[k]);
    int sum = r + s + t;
    vector<int> v{0, 0, 0};
    while(i<n && j<m && k<n){
        if(r>s&&r>t)
            a[i] > b[j] ? j++ : i++;
        else if(s>r&&s>t)
            a[i] > c[k] ? k++ : i++;
        else
            b[j] > c[k] ? k++ : j++;
        if(i==l||j==m||k==n)
            break;
        r = abs(a[i] - b[j]), s = abs(a[i] - c[k]), t = abs(b[j] - c[k]);
        if((r+s+t)<sum){
            sum = r + s + t;
            v[0] = a[i];
            v[1] = b[j];
            v[2] = c[k];
        }
    }
    return v;
}

int findmidnum(int a[],int b[],int n){
    int s1 = 0, s2 = 0;
    int d1 = n - 1, d2 = n - 2;
    int m1, m2;
    while(s1!=d1||s2!=d2){
        m1 = (s1 + d1) / 2;
        m2 = (s2 + d2) / 2;
        if(a[m1]==b[m2])
            return a[m1];
        if(a[m1]<b[m2]){
            if((s1+d1)%2==0){
                s1 = m1;
                d2 = m2;
            }
            else{
                s1 = m1 + 1;
                d2 = m2;
            }
        }
        else{
            if((s1+d1)%2==0){
                d1 = m1;
                s2 = m2;
            }
            else{
                d1 = m1 + 1;
                s2 = m2;
            }
        }
    }
    return a[s1] < b[s2] ? a[s1] : b[s2];
}