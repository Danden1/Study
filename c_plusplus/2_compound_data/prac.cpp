#include <iostream>
using namespace std;

struct pizza{
	char name[30];		
	double diameter;	
	double weight;		
};

int main(){
	pizza pizza1;		
	
	cout << "피자 회사의 이름을 입력하십시오: ";
	cin.getline(pizza1.name, 30);

	cout << "피자의 지름을 cm 단위로 입력하십시오: ";
	cin >> pizza1.diameter;

	cout << "피자의 중량을 g 단위로 입력하십시오: ";
	cin >> pizza1.weight;
	
	cout << "제조사 : " << pizza1.name << endl;
	cout << "지  름 : " << pizza1.diameter << " cm" << endl;
	cout << "중  량 : " << pizza1.weight << " g" << endl;
	return 0;
}
