# 코드 재활용

## 객체 멤버를 가지는 클래스

c++에서 has a 관계를 모델링 하는 기본적인 테크닉은 컴포지션(컨테인먼트) 사용. 다른 클래스의 객체를 멤버로 가지는 클래스 만드는 것.

ex)

class Student{

private:

  string name; //string객체

  valarray<double> scores; //valarray 객체

...

};

내포된 종속 객체의 인터페이슬르 자동으로 획득 x

string operator== () 함수 사용하는 능력 가지고 있지 않음



내포된 객체의 인터페이스 사용

내포된 객체의 인터페이스 사용는 public x

그러나, 클래스 메서드 안에서 사용 가능

double Student::Average() const{

  return scores.sum()/scores.size();

}



## private 상속

has a 관계 구현하는 수단으로 private 상속 제공

기초 클래스 public 멤버, protected 멤버가 파생클래스의 private 멤버 됨.



public 상속은 기초 public 메서드가 파생 public 메서드 됨.

기초 클래스의 인터페이스 상속(is a)

class Student : private std::string, private std::valarray<double>{

...

};

private 데이터 필요 없음

상속되는 두 기초 클래스가 필요한 데이터 멤버 제공

이것이 컨테인먼트와 차이



멤버 이름 대신, 클래스 이름으로 생성자 식별

Student(char *str, double *pd, int n) : string(str), valarray<double>(pd, n)(){...}

2번째 차이점



private상속은 기초 클래스 메서드를 파생 클래스 메서드 안에서만 사용 가능.

기초 클래스 기능을 public으로 사용하고 싶은 경우 있음.

컨테인먼트는 public 함수 안에 valarray 클래스의 size(),sum()사용 가능



private 상속에서는 :: 를 사용하여 기초클래스의 메서드 호 출 가능

valarray<double> :: sum();



기초 클래스 객체에 접근

private 상속에서는 string 객체가 이름 없음.

내부의 string 객체에 접근 하려면 데이터형 변환 사용

student가 string 으로부터 상속

-> string 객체로 형 변환 가능



const string &student ::Name() const 

  return (const string&) *this;



### 컨테인먼트 ,private 상속

대부분 컨테인먼트 사용

1. 컨테인먼트가 사용하기 쉬움.

2. 하나 이상 기초 클래스로부터 상속할 때, 상속이 문제 일으킬 수 있음.



private상속 장점

1. 컨테인 먼트가 제공하는 것 이상의 기능 제공.

어떤 클래스가 protected 멤버 가지고 있으면, 여기에 접근 가능.

2. 가상 함수 다시 정의할 필요 있을 경우



### protected 상속

class Student : protected std::string, protected std::valarray<double>{...}

기초 public,protected멤버가 파생클래스의 protected멤버가 됨

private 상속, protected 상속 주된 차이점은 파생 클래스로부터 또 다른 클래스 파생시킬 때 드러남.

rpivate상속에서는 이 3세대 클래스가 기초 클래스 인터페이스의 내부적인 사용권 얻지 못함.

이유 : public 기초 클래스 메서드들은 파생클래스에서 private되고, private 멤버와 메서드들은 그 다음 단계에서 직접 접근 불가능.

pritected상속에서는, public 기초 메서드들이 2세대에서 protected가 됨



## 다중 상속

직계 인접한 기초 클래스를 하나 이상 가지는 클래스 public 다중 상속은 is a 관계나타내야 함.

public 다중 상속은 is a 관계나타내야 함.

class SingingWaiter : public Waiter, public Singer{...};

public안 쓰면, private 파생으로 간주



문제를 일으킬 수 있음.

별개의 두 기초 클래스로부터 이름은 같지만 서로 다른 메서드들을 상속하는 문제, 둘 이상의 서로 관련된 인접 기초 클래스들로부터 어떤 클래스의 다중 인스턴스를 상속하는 문제

다중상속은 절제하여 사용하는 것이 좋음.
