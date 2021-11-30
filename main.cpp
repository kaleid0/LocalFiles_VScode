#include <iostream>
using namespace std;

class ZeroExcep{
	string message;
public:
	ZeroExcep():message("±»0³ıÒì³£"){}
	string what(){return message;}
};
double divide(double num1,double num2){
	if(num2==0) throw ZeroExcep();
	return num1/num2;
}
int main(){
	try{
		cout<<"5.0/2.0="<<divide(5.0,2.0)<<endl;
		cout<<"7.0/0.0="<<divide(7.0,0.0)<<endl;
		cout<<"9.0/2.0="<<divide(9.0,2.0)<<endl;
	}
	catch(ZeroExcep ze){
	cout<<ze.what()<<endl;
	}
	return 0;
}
