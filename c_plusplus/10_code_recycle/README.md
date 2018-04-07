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


class Singer : public Worker {...};

class Waiter : public Worker {...};

class SingingWaiter : public Singer, public Waiter{...};

SingingWaiter는 Worker 객체를 두 개 가짐.

하나의 이름과 번호만 필요,2개는 필요 없음

이것을 가능하게 하는 가상 기초 클래스 추가.



가상 기초 클래스

하나의 공통 조상을 공유하는 여러 개의 기초 클래스로부터 공통 조상의 유일 객체를 상속하는 방식으로 객체를 파생시키는 것 허용

class Singer : virtual public Worker{...};

//public virtual



SingingWaiter객체는 Worker객체의 복사본을 하나만 내포함

SingerWaiter 객체가 하나의 Worker객체를 공유



새로윤 생성자 규칙

가상 기초 클래스 사용은 클래스 생성자에 새로운 접근 방식 요구

SingingWaiter(const Worker &wk, int n = 0, int v = Singer::other) :Waiter(wk,p), Singer(wk,v)()//안됨

컴파일러는 파생 객체들을 생산하기 전에 기초 성분 생성해야 함.

디폴트 Worker 생성자 이용함.



아니면 기초 생성자를 명시적으로 호출.

~~~:Woker(wk), ~~~~~

가상이 아닌 기초 클래스에 대해서는 부적절



### 어느 매서드?

가장 가까운 조상의 정의가 사용 됨.

둘 다 가지고 있을 경우는 모호해짐.

::이용하면 어느 것을 말하는지 알 수 있음.



아니면 그 함수 다시 정의

void SingingWaiter ::show() 

  Singer:;show();

파생 메서드가 기초 메서드를 호출하는 방법은 단일 상속에서는 잘 작동

그러나 다중에서 실패(Waiter 성분 무시해서)

void ~~~{

~~~

Waiter::show();

}//가능

그러나 Worker::show()두번 호출



해결

Worker ,Singer, Waiter 만 출력하는 메서드 각각 제공



## 클래스 템플릿



### 정의

템플릿 함수처럼 앞에 template <class T>

쓰면 됨.



클래스 메서드들을 템플릿 멤버 함수로 대체 가능

각각의 함수 머리에 동일한 템플릿 표시 적음

::사용범 바뀜

~~<T> :: ~~



템플릿들은 함수가 아니라서 개별적으로 컴파일 불가

간단한 방법은 모든 템플릿 관련 정보를 헤더 파일에 넣고, 그 템플릿들을 사용하는 파일에 그 헤더 파일을 포함 시키는 것.



### 사용

단순히 포함시키는 것만으로는 템플릿 클래스 생성 x

구체화 요청하려면, 객체 선언하되 구체적인 데이터형 명시

~~<int> tmp;

T를 모두 int로 대체

모든 데이터형에 일관된 알고리즘 사용해야함.



### 더 자세히

Stack<string> st;

대신

Stack<char*> st;

사용시 실패

포인터의 단순한 생성은 입력 문자열들의 공간을 생성 x



포인터 들의 스택을 사용하려면, 호출한 프로그램이 포인터들의 배열을 제공 하는 것.



각각의 포인터는 서로 다른 문자열 지시.

T item; 을 T* item; 으로 변경

new T[size]; 로 item 메모리 공간 할당



template <class T, int n>

n을 int형으로 인식하게 함(수식 매개변수)

~~ <~,10> ~; //n을 10으로 대체

정수형, 열거형, 참조, 포인터가 수식 매개변수 될 수 있음.

double m 은 x, double &rm, double *pm은 가능

수식 매개변수의 값 변경 불가, 주소 얻을 수 없음.



생성자 접근 방식은 힙 메모리 사용.

수식 매개변수 접근방식은 스택 메모리 사용

크기가 작은 배열 많이 사용, 빠른 실행 속도



단점

각 배열 크기가 자신만의 템플릿을 각각 생성



### 용통성

보통의 클래스에 적용하는 것과 동일한 테크닉 적용가능

재귀적으로 사용 가능

ex>

ArrayTp<ArrayTp<int,5>, 10> t;

//int t[10][5];

하나 이상의 데이터형 매개변수 사용하는 템플릿 만들 수 있음

데이터형 매개변수에 디폴트 값 제공 가능

template <class T1, class T2 =int>



### 템플릿 특수화

암시적 구체화

사용하기를 원하는 데이터형을 나타내는 하나 또는 그 이상의 객체를 선언

ArrayTp<int, 100> st; //암시적



명시적 구체화

template 사용하여 클래스 선언, 사용하려는 데이터 형을 나타 냈을때, 컴파일러는 명시적 구체화 생성

template class ArrayTp<string, 10> //클래스 생성




명시적 구체화

포괄적인 템플릿 대신, 사용하려는 특정 데이터형들을 위한 정의

template <> class name<special-type-name> {...};



부분적인 특수화

템플릿의 포괄성 일부 제한

ex) 데이터형 매개변수들 중 제공 가능. 구체적인 데이터형

//포괄

template <class T1, class T2> class Pair{..};

//T2를 int로 부분적은 특수화

template <class T1> class Pair<T1, int> {...};



데이터형 모두 지정하면, 명시적인 특수화



포인터들을 위한 특별한 버전도 가능

template <class T*> class tmp {...};



### 멤버 템플릿

템플릿은 구조체, 클래스, 템플릿 클래스의 멤버 될 수 있음.(최근)



### 매개변수 템플릿

그 자체가 템플릿인 매개변수 가질 수 있음.

template <template<class T> class Ting> class Crab

template <class T> class가 데이터 형,

Thing은 매개변수

Crab<King> legs;

King은 템플릿 클래스여야 함.

그 템플릿 클래스의 선언이 템플릿 매개변수 Thing의 선언과 일치 해야 함.



### 템플릿 클래스, 프렌드 함수

템플릿의 프렌드 3가지로 분류 가능.

- 템플릿이 아닌 프렌드

- 바운드 템플릿 프렌드, 클래스가 구체화 될 때, 클래스 데이터형에 의해 프렌드 데이터형 결정됨.

- 언바운드 템플릿, 프렌드의 모든 특수화가 그 클래스의 각 특수화에 대해 프렌드들.



템플릿 클래스에 대한 템플릿이 아닌 프렌드 함수

template <class T>

class HasF{

...

friend void counts();

...

}

모든 HasF구제화에 대해 프렌드



HasF<int>, HasF<char>클래스에 대해서도 프렌드.

counts()함수는 객체에 의해 호출 안 됨.

객체 매개변수들 가지지 않음.



전역 객체에 접근 가능

전역 포인터 사용하여 전역이 아닌 객체에 접근 가능.

템플릿 클래스 static데이터 멤버에 접근 가능.

friend void Report(HasF &);//불가

friend void Report(HasF<T> &)//가능



템플릿 클래스에 대한 바운드 템플릿 프렌드 함수 

프렌드 함수들을 템플릿 자체로 만들 수 있음.

1. 클래스 정의 앞에 템플릿 함수 선언

template <class T> void counts();

template <class T> void Reports(T &);

2. 그 함수 안에서 다지 템플릿들을 프렌드로 선언

template <class TT>

class HasF{

...

friend void counts <TT> ();

friend void Report<>(HasF<TT> &);

.//

}

3. 그 프렌드들을 위한 정의 제공



템플릿 클래스에 대한 언바운드 템플릿 프렌드 함수 

템플릿을 클래스 안에 선언 함으로 써, 언바운드 프렌드 함수 생성가능.

모든 함수 특수화는 모든 클래스 특수화에 대해 프렌드.

template <class TT>

class ManyF{

...

template <class C,class D> friend void show2(C&, D&);

};


모든 특수화들에 대해 프렌드

//소드 코드 답지 참조
