# 프렌드, 예외, 기타 사항

## 프렌드

클래스도 프렌드 가능

프렌드 클래스의 모든 메서드는 오리지널 클래스의 private, protected 멤버에 접근 가능.

특정 멤버 함수들만 다른 클래스의 프렌드가 되도록 저장 가능.



### 프렌드 클래스

tv, 리모콘 생각하면 편함

is a, has a,는 아니지만, 리모콘은 tv의 상태 변경가능

Remote를 Tv클래스의 프렌드로 해야 됨을 암시

friend class Remote; //Tv클래스 안에 선언

Remote클래스는 Tv클래스 이용.

-> 컴파일러는 Tv클래스에 대해 알아야 함.

Tv클래스 먼저 정의하면 됨.




### 프렌드 멤버 함수

클래스 전체를 프렌드로 만드는 대신, 원하는 메서드만 다른 클래스에 대해 프렌드로 만드는 것이 가능



선언들과 정의들을 배치하는 순서에 신경 써야 됨.

class Tv{

...

friend void Remote::set_chan(Tv &t, int c);

...

};

컴파일러는 Remote정의 미리 알아야 함.

하지만 Remote 메서드들이 Tv객체 이용.

이를 해결하기 위해 사전선언 사용.

Remote 정의 위에 삽입.

class Tv; //사전 선언

class Remote{,.};

class Tv{...};



그러나 

class Remote;

class Tv{..};

class Remote{...};

는 불가능.

set_chan()메서드 선언을 알 수 없어서

Remote안에 

void onoff(Tv &t){t.onoff();}

가 있음(인라인)



Tv가 어떤 메서드 가져야 되는 지도 알아야 함.

이를 위해, Remote를 메서드 선언으로 제한, 실제 정의들은 Tv클래스 뒤에 옴.



class Tv; //사전

class Remote{...}; //Tv사용하는 Remote메서드 원형

class Tv{,,,};

inline bool Remote::onoff(Tv &t){t.onoff()}



Remote클래스 전체를 프렌드로 만드는 것은 사전 선언 필요 x

friend class Remote;

구문 자체가 클래스로 인식함



### 그 밖의 프렌드

서로서로 영향을 줄 수 있음.

-> 상호 프렌드 관계이용



### 공유 프렌드

프렌드 또 다른 용도는

하나의 함수가 서로 다른 두 클래스에 들어있는 

private 멤버에 접근해야 할 때,

class Tv;

class Remote{

friend ~~~; 

};

class Tv{

friend ~~;// 동일

};


~~~ 정의



## 내포 클래스

클래스 선언을 다른 클래스 안에 내포 가능

다른 클래스 안에 선언된 클래스를 내포 클래스라고 함.



클래스 선언을 내포하고 있는 클래스의 멤버함수들은 내포 클래스의 객체들을 생성하여 사용 가능.



내포클래스는 컨테인먼트와 다름.

컨테인먼트는 클래스 객체를 멤버로 가짐.



클래스 내포 이유는,

1. 다른 클래스의 구현 지원,

2. 이름 충돌 막음



예를 들면, 전에 구현한 큐.

Node를 일일히 생성 했음.

-> 생성자로 생성하면 더 편리



class Queue{

class Node{

public:

Item item;

Node *next;

Node(const Item &i):item(i), next(0){}

};

...

};

Node *add = new Node(item);



Queue::Node::Node ~~~

로 정의 가능.



### 내포 클래스, 접근

2종류 접근 형태

1. 내포 클래스가 선언된 장소가 내포 클래스의 사용 범위 제한

(선언된 장소가 어느 부분에서 내포클래스 객체 생성 할 수 있는 지 결정)

2. 내포 클래스의 priavte, public, protected 부분들도 그 클래스 멤버에 대한 접근 제한



사용 범위

내포 클래스가 2클래스 private에 선언,

내포 클래스는 2클래스에만 알려짐.

아까 Queue에서 그리 함.

Queue로부터 하나의 클래스 파생,

그 클래스는 Node 안 보임 (파생은 기초 private에 직접 접근 불가)


public 에 선언, 파생 클래스, 외부 전부 접근 가능, ::이용해야 함.

~::내포 클래스 tmp;



protected에 선언, 파생에서만 접근 가능



## 예외

최근에 추가된 기능

예외 알아보기 전에, 프로그래머가 사용 할 수 있는 사항 부터 알아봄

### abort()

cstdlib에 있음.

호출 되었을 때 표준 에러 스트림에 "abnormal program temination" 메세지 보냄, 종료 시킴



그 프로크램이 다른 프로그램에 의해 기동되었을 경우, 기동시킨 부모 프로세스나 운영체제에 컴파일레어 종속적인 어떤 값 리턴



### 예외 메커니즘

c++의 예왼느 프로그램을 싱행하는 도중에 발생하는 예외적인 상황에 대한 응답.

예외들은, 프로그램의 어느 부분에서 다른 부분으로 제어를 넘기는 방법 제공.



3단계로 이루어짐

1. 예외 발생

2. 핸들러 사용하여 예외 포착

3. try 블록 사용

throw는 예외의 발생 나타 냄.

뒤에 그 예외의 특징 나타내는 하나의 값(문자열, 객체 등)이 뒤따름.



catch는 예외의 포착 나타냄

예외 핸들러는 catch로 시작함

뒤에 예외 핸들러 응답하게 만든, 그 예외의 데이터형 선언이 ()안에 나타남.

또 그 뒤에, 조치할 상황을 {}로 묶어서 나타냄.



try블록은 특별한 예외들이 발생할 수 있는 하나의 코드 블록, 그 뒤에 하나 이상 catch블록 나옴



ex)

int p_sum(int a, int b){

if(a<0 || b<0)
 
  throw "음수 안됨";

return a+b;

}



int main(){

...

int z,x,y;

...

while(~~){

...

try{

  z= p_sum(x,y);

}

catch(const char *s){

cout << s << endl;

continue;

}

~~

}

try구문 밖에서 p_sum()호출하면 예외처리할 기회 못 얻음.



throw에서 발생하는 예외는 "음수 안됨"이라는 문자열.

다른 데이터형도 가능

try 블록이 있는 함수 발견 시 까지 거슬러 올라감.

const char *s는 이 핸들러가 문자열로 된 예외 받아들인 다는 것 의미

예외가 이 한들러와 일치, 중괄호 안의 코드 실행



프로그램이 예외 발생 x

-> catch 블록 건너 뜀.



어떤 함수가 예외 발생시키면,

try블록 없거나 데이터형이 일치하는 예외핸들러 없으면 abort()호출



### 예외로 객체 사용

일반적으로, 예외를 발생시키는 함수들은 객체 발생

장점:

서로 다른 예외 데이터형 사용 가능

_> 예외 발생시키는 상황 구별 가능.

객체 자체에 정보 전달 가능.

사용자는 이 정보 사용하여 예외 발생하는 조건들을 알 수 있음.



class bad_sum{

priavte:

int v1; int v2;

public:

bad_sum(int a= 0, int b= 0):v1(a),v2(b){}

void mesg();

};

inline void bad_sum::mesg(){

cout << "음수 안됨" << endl << a<< "," b<< endl;

}



if(a<0 || b<0)
  
  throw bad_sum(a,b);



이걸로 객체 초기화
