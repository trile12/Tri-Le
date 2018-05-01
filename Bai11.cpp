#include<iostream>
#include<cmath>
using namespace std;

class fraction{
	private:
		int num;
		int den;
	public:
		fraction(int ,int );
		fraction();
		void lowterms();
		void dislay();
		void sum(fraction,fraction);
		void sub(fraction,fraction);
		void mul(fraction,fraction);
		void div(fraction,fraction);
};

fraction::fraction(int tnum, int tden){
	if(tden==0){
		cout<<"Illegal fraction: division by 0"<<endl;
		exit(1);
	}
	this->num=tnum;
	this->den=tden;
}
fraction::fraction(){
	this->num=1;
	this->den=1;
}
void fraction::lowterms(){
	long tnum, tden, temp, gcd;
	tnum = labs(num); 
	tden = labs(den); 
	if(tden==0){ 
		cout<< "Illegal fraction: division by 0"<<endl; 
		exit(1);
	}
	else if( tnum==0 ) { 
		num=0; den = 1; 
		return; 
	}
	while(tnum != 0){
		if(tnum < tden){ 	
		temp=tnum; tnum=tden; tden=temp;
		}
		tnum = tnum - tden;
	}
	gcd = tden;
	num = num / gcd;
	den = den / gcd; 
}

void fraction::sum(fraction one,fraction two){
	this->num=two.den*one.num+two.num*one.den;
	this->den=one.den*two.den;
	this->lowterms();
}
void fraction::sub(fraction one,fraction two){
	this->num=two.den*one.num-two.num*one.den;
	this->den=one.den*two.den;
	this->lowterms();
}


void fraction::mul(fraction one,fraction two){
	this->num=two.num*one.num;
	this->den=one.den*two.den;
	this->lowterms();
}

void fraction::div(fraction one,fraction two){
	this->num=one.num*one.den;
	this->den=one.den*two.num;
	this->lowterms();
}

void fraction::dislay(){
	cout<<num<<" / "<<den;
}


