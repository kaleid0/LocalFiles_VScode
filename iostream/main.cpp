#include<iostream>
#include<fstream>
#include<iomanip>
#include<vector>

using namespace std;

//添加行号
void addlineNo(char *filename);
//获取文件大小
void getsize(char *filename);
//高精度加法
bool add(char A[], char B[], int lengthA, int lengthB);
void add(vector<int> &A, vector<int> &B);
void add(char *filename);
//进制转换
void dec_bin(int x, char *c, int &n);
void dec_oct(int x, char *c, int &n);
void dec_hex(int x, char *c, int &n);
void converse();

int main() {
    addlineNo("data2.dat");
    getsize("行号.txt");
    add("高精度加法.txt");
    converse();
}









void addlineNo(char *filename){
    ifstream infile(filename);
    ofstream outfile("行号.txt", ios::trunc);//trunc打开时清空
    if(!outfile){
        cout << "文件无法打开" << endl;
        return;
    }
    char c[100];
    int i = 0;
    while(infile.getline(c, 100)){
        outfile << setiosflags(ios::left) << setw(4) << i++ << c << endl;
    }
}

void getsize(char *filename){
    ifstream infile(filename);
    if(!infile){
        cout << "文件无法打开" << endl;
        return;
    }
    streampos begin = infile.tellg();//获取读指针
    infile.seekg(0, ios::end);//定位到末尾
    streampos end = infile.tellg();
    cout << begin << ' ' << end << endl;
    cout << "文件大小为:" << end - begin << "字节" << endl;
}

bool add(char A[],char B[],int lengthA,int lengthB){
    int d = lengthA - lengthB;
    bool r = false;
    int i = lengthA - 1;
    for (; i >= d; i--) {
        int a = r ? A[i] + B[i-d] + 1 - '0' * 2 : A[i] + B[i-d] - '0' * 2;
        if (a > 9) {
            a %= 10;
            r = true;
        }
        else
            r = false;
        A[i] = a + '0';
    }
    while(r&&i>=0){
        int a = A[i] + 1;
        if(a>9)
            A[i] = '0';
        else{
            A[i] = a + '0';
            r = false;
        }
        i--;
    }
    return r;
}

void add(vector<int> &A, vector<int> &B){
    int m = A.size() - 1;
    int n = B.size() - 1;
    bool r = false;
    while(n>=0){
        int temp = r ? A[m] + B[n] + 1 : A[m] + B[n];
        r = temp > 9 ? true : false;
        A[m] = temp % 10;
        m--;
        n--;
    }
    while(r&&m>=0){
        int temp = r ? A[m] + 1 : A[m];
        r = temp > 9 ? true : false;
        A[m] = temp % 10;
        m--;
    }
    if(r){
        m = A.size() - 1;
        A.push_back(A[m]);
        for (int i = m; i > 0; i--)
            A[i] = A[i - 1];
        A[0] = 1;
    }
}


void add(char *filename){
    fstream outfile;
    outfile.open(filename, ios::in | ios::out);
    if(!outfile){
        cout << "无法打开文件" << endl;
        return;
    }
    vector<int> A, B;
    char c;
    while ((c = outfile.get() )&& c != '\n')
        A.push_back(c - '0');
    while ((c = outfile.get() )&& c != EOF&&c!='\n')
        B.push_back(c - '0');
    outfile.close();
    fstream infile;
    infile.open(filename, ios::app);
    infile.seekp(0, ios::end);
    infile << endl;
    if(A.size()>B.size()){
        add(A, B);
        for(auto i:A)
            infile << i;
    }
    else{
        add(B, A);
        for(auto i:B)
            infile << i;
    }
}

void dec_bin(int x,char *c,int &n){
    int i = 0;
    while(x!=0){
        c[i++] = x % 2 + '0';
        x /= 2;
    }
    n = i-1;
}

void dec_oct(int x,char *c,int &n){
    int i = 0;
    while(x!=0){
        c[i++] = x % 8 + '0';
        x /= 8;
    }
    n = i-1;
}

void dec_hex(int x,char *c,int &n){
    int i = 0;
    while(x!=0){
        int t = x % 16;
        if(t<10)
            c[i++] = t + '0';
        else
            c[i++] = t + 'A' - 10;
        x /= 16;
    }
    n = i-1;
}


void converse(){
    cout << "输入一个整数:";
    ofstream file;
    int x;
    cin >> x;
    file.open("进制转换.txt", ios::trunc);
    file << "dec:" << x << endl;
    char c[20];
    int n = 0;
    dec_bin(x, c, n);
    file << "bin:";
    for (int i = n; i >= 0; i--)
        file.put(c[i]);
    file << endl;
    dec_oct(x, c, n);
    file << "oct:";
    for (int i = n; i >= 0; i--)
        file.put(c[i]);
    dec_hex(x, c, n);
    file << endl;
    file << "hex:";
    for (int i = n; i >= 0; i--)
        file.put(c[i]);
    file << endl;
    file.close();
}