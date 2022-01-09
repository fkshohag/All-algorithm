# include <iostream>
using namespace std;
class Distance{
public:
	double Feet;
	double Inch;
	Distance(){};
	void input(){
		cout<<"Enter the exact Feet:"<<endl;
		cin>>Feet;
		cout<<"Enter the exact Inch:"<<endl;
		cin>>Inch;
		cout<<endl<<"Feet is:"<<Feet<<"ft"<<endl<<"Inch is:"<<Inch<<"''"<<endl;
	}
	double getFeet(double inc){//convert inch to feet
		return inc/12;
	}
	Distance(double feet,double inc){
		Feet=feet;
		Inch=inc;
	}
	Distance operator+(Distance obj){
		Distance temp1,temp2,total;
		temp1.Feet=Feet+getFeet(Inch);
		temp2.Feet=obj.Feet+getFeet(obj.Inch);
		total.Feet=temp1.Feet+temp2.Feet;
		return total;
	}
	Distance operator-(Distance obj){
		Distance temp1,temp2,total;
		temp1.Feet=Feet+getFeet(Inch);
		temp2.Feet=obj.Feet+getFeet(obj.Inch);
		total.Feet=temp1.Feet-temp2.Feet;
		return total;
	}
	Distance(double inc){
		Inch=inc;
	}
	Distance operator++(){//Prefix operator overloading
		Distance temp;
		Inch++;
		temp.Inch=Inch;
		return temp;
	}
	Distance operator++(int){//Postfix operator overloading
		Distance temp;
		Inch++;
		temp.Inch=Inch;
		return temp;
	}
    bool operator>(Distance obj){
		Distance temp1,temp2,total;
		temp1.Feet=Feet+getFeet(Inch);
		temp2.Feet=obj.Feet+getFeet(obj.Inch);
		if (temp1.Feet>temp2.Feet)return true;
		else
			return false;
	}

};
int main(){
	Distance user;
	user.input();
	double feet,inc;
	cout<<"Enter first object Feet:"<<endl;
	cin>>feet;
	cout<<"Enter first object inch:"<<endl;
	cin>>inc;
	Distance a(feet,inc);
	cout<<"Enter second object Feet:"<<endl;
	cin>>feet;
	cout<<"Enter second object inch:"<<endl;
	cin>>inc;
	Distance b(feet,inc);
	Distance sum,sub;
	sum=a+b;
	sub=a-b;
	++a;
	b++;
	cout<<"Overloading Action>>>>>>>>"<<endl;
	cout<<"Total Distance two Object after add:"<<sum.Feet<<"ft"<<endl;
	cout<<"Total Distance two Object after Substract:"<<sub.Feet<<"ft"<<endl;
	cout<<"Increment Prefix Object ++a:"<<a.Inch<<"''"<<endl;
	cout<<"Increment Postfix Object b++:"<<b.Inch<<"''"<<endl;
	if(a>b)
		cout<<"Left object has bigger"<<endl;
	else
		cout<<"Right object has bigger"<<endl;
	return 0;
}
