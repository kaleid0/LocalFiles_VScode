#include<iostream>
#include<string.h>

using namespace std;

class A{
public:
    char name[12];
    char *p;
    A(char *a,char *b){
        strcpy(name, a);
        p = b;
    }
    void set(char*a,char*b){
        strcpy(name, a);
        p = b;
    }
};

int main(void)
{	
	int a[4][4]={1,2,3,4,2,2,5,6,3,5,2,7,4,6,4,7};
	int i,j,flag=0,sum=0;
    for(j=0;j<4;j++) 
    	for(i=0;i<=j;i++){
    		if(a[j][i]==a[i][j])
{	sum+=a[i][j];
continue;
				}
   		 	flag=1;
    	}
    	if(flag)cout<<"No!"<<endl;
    	else cout<<"All Right!"<<endl;
		cout<<"sum="<<sum<<endl;
}
