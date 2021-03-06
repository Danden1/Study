# 메모리 모델과 이름 공간

## 분할 컴파일

헤더 파일에 흔히 들어 가는 것.

- 함수 원형



- #define,const를 사용하여 정의하는 기호 상수

- 구조체 선언, 클래스, 템플릿, 인라인 함수



헤더 파일을 포함 시킬 때 "..." 사용

<>로 묶여 있으면, 컴파일러는 표준 헤더 파일들이 들어 있는 호스트 시스템의 파일 시스템 영역에서 찾음.

""는 현재 작업 디렉토리나 소스코드 디렉토리에서 찾음



헤더 파일을 어떤 파일에 단 한번만 포함 시켜야 됨.

c, c++에서 헤더파일을 이미 포함하는 실수를 피하기 위해, 전처리기 지시자 #ifndef 사용.



#ifndef C_H_

...

#endif

C_H_라는 이름이 전처리기 지시자 #define에 의해 정의되어 있지 않은 경우에만 ...을 처리하라는 뜻

사이에 #define C_H_를 쓰면 됨



##기억 존속시간, 사용범위, 링크



데이터 저장 유형

1. 자동 기억 존속 시간 : 함수 매개변수를 포함, 함수 정의 안에 선언된 변수는 자동 기억 존속 시간을 가짐.

함수나 블록 안으로 들어갈 때 생성됨.

떠날 때 메모리에서 해체됨.



2. 정적 기억 존속 시간 : 함수 정의 밖에 정의된 변수, static을 사용하여 정의된 실수는, 정적 기억 존속시간 가짐.

프로그램이 실행되는 전체 시간 동안 존속.



3. 쓰레드 존속 시간(c++11) : 요즘은 멀티코어 프로세서 많이 사용. 여러 작업 동시에 처리할 수 있는 cpu의미.

연산 작업을 쓰레드 단위로 쪼개서 처리 가능



4. 동적 기억 존속 시간  :new연산자를 사용하여 대입된 메모리는 delete로 해체되거나 프로그램이 종료할 때까지 존속



### 사용 범위와 링크

사용 범위는 어떤 이름이 하나의 파일(번역 단위)안에서 얼마나 널리 알려지는 가 나타 냄.



어떤 파일에서 함수 정의들의 위에 정의된 변수는 아래 모든 함수에서 사용 가능.



링크는 서로 다른 번역 단위들이 이름을 공유하는 것.



외부 링크를 가진 이름은 여러 파일들이 공유 가능.

내부 링크를 가진 이름은 한 파일 안에 있는 함수들만 공유 가능.

자동 변수의 이름은 링크를 갖지 않음.

하나의 c++변수는 범위들 중 하나 가질 수 있음.

지역 사용 범위(블록 사용 범위)를 가진 변수는 그 변수를 정의한 블록 안에서만 알려줌.



전역 사용 범위(파일 사용 범위)를 가지는 변수는 정의된 지점에서 그 아래로 파일 전체에 알려줌.



함수 원형 사용 범위에 사용 되는 이름은 매개변수 리스트를 둘러싸고 있는 괄호 안에만 알려짐(그래서 변수이름 필요 x)



클래스 안에 선언된 멤버는 클래스 사용 범위

어떤 이름 공간 안에 선언된 변수는 이름 공간 사용 범위를 가짐.



함수는 지역 사용범위는 가질 수 없음

다른 함수가 호출을 못하기 때문


### 자동변수

함수 매개변수와 함수 안에서 선언된 변순느 기본적으로 자동 기억 존속시간을 가짐.

지역 사용 범위 가지며 링크 x



어떤 변수를 블록 안에 정의

그 변수의 깅거 존속 시간과 사용범위는 그 블록에만 한정

메모리 일부 예약 해두고, 변수들의 생성과 소멸을 스택으로 관리


### 정적 변수

프로그램이 실행되는 동안 존속.


정적 변수의 개수는 실행 동안 변하지 않음.

-> 스택 같은 장치 필요 x


모든 정적 변수 수용할 만큼, 크기가 정해진 메모리 블록 대입



정적 변수를 명시적으로 초기화 하지 않으면 컴파일러는 모두 0으로 초기화


정젹 배열,구조체는 원소, 멤버 0으로 초기화



...

int global =1 ;//정적, 외부링크

static int g= 2; // 정적, 내부링크

...

void fun(int n){

	static int c = 0; //정적, 없음

}


### 정적 존속 시간, 외부링크

외부 변수는 정적 저장기간과 파일 범위 가짐

전역 변수라고도 불림


외부 변수가 그 변수를 사용하는 모든 파일에서 선언 되어야 함.


c++은 두 종류의 변술르 선언을 함

1. 선언을 정의 또는 단순하고 정의로, 대입되는 변수에 저장소 제공

2. 참조 선언, 단순히 선언한느 것. 기존의 변수의미, 저장소 생성x


만약 여러 파일에서 외부 변수 사용, 오직 한개 파일이 그 변수에 대한 저으이를 가짐.



그 변수를 사용하는 모든 파일들은 extern 이란느 키워드 사용해서 선언 해야함.


//f1.cpp

extern int cats = 20;//정의

int dogs = 22;

int fleas = 21;


f2.cpp

extern int cats; //정의 아님

extern int dogs; //extern에 해당, 초기화 x


모든 파일은 f1.cpp cats,dogs사용.

f2.cpp는 fleas변수 재선언 x, 접속 불가


f1.cpp에 있는 extern 은 그것을 제거 하였을 때의 효과와 동일. 요구되는 사항 x


동일한 이름, 다른 함수에 정의된 자동 변수는 별개의 변수, 각자 고유의 주소 가짐.

::를 붙이면 그 변수의 전역 버전을 사용하라는 뜻



### 정적 존속 기간, 내부 링크

static 제한자 적용 시 내부링크 부여

//f1.cpp

int err = 10;//외부

//f2.cpp

int err= 5;

에러, errㅇ르 2개를 정의 한것으로 간주



f2.cpp에서 static 붙이면, 그 파일에서만 사용 되는 변수로 인식


### 정적 존속 기간, 링크 없음

블록 안에 정의되는 변수에 static붙임.

블록 안에서만 알려짐. 계속 존재 가능



### 제한자

기억공간 제한자,cv제한자 존재



기억 공간 제한자

- auto(c++11은 아님), register, static, extern, mutable, thread_local(c++11)


하나만 사용가능. thread_local만 static 또는 extern 과 함께 사용 가능.

register는 레지스터 기억 공간 지정.

thread_local은 변수의 존속 시간이 변수를 포함하는 쓰레드의 존속 시간



cv제한자

const, volatile

volatile은 코드가 변경하지 않더라도 특정 메모리 위치에 있는 값이 변경 될수 있음.


mutalbe은 특정 구조체(클래스가)const여도, 특정 멤버를 변경 할 수 있음.



### const 보충

c++ 에서는 const가 디폴트 기억 공간을 약간 바꿈



전역 변수는 외부 링크를 갖도록 디폴트로 내정.

const 전역 변수는 내부링크 static 제한자가 사용된 것처럼 취급



다른 파일들이 접근하려면, extern 사용

extern const int cats; //초기화는 불가



### 함수와 링크

함수도 링크 속성 가짐.

하나의 함수 안에 다른 함수 정의 불가

모든 함수는 정적 기억 존속 시간을 가짐.

프로그램이 실행 된느 동안 계속 존재.



기본적으로 외부 링크 가짐. 여러 파일이 함수 공유 가능.

static으로 함수에 내부 링크 부여 가능

함수 원형, 정의 앞에 static 붙임

같은 이름의 함수를 다른 파일에서도 사용 가능.


외부링크를 가지는 함수에 대해 다중 파일 프로그램의 파일 하나만 함수 정의를 가질 수 있음

사용하는 파일은 그 함수의 원형 가져야 함



인라인 함수는 예외. 헤더 파일에 인랑니 함수 정의들을 넣는 것이 허용 됨.

헤더 파일을 포함하는 파일은 인라인 함수 정의를 갖게 됨.


- c++ 어디에서 함수 찾을까

함수 원형이 함수를 정적이라고 알려주면 컴파일러는 그 파일 안에서만 찾음


두 개의 함수 정의 발견시 에러

찾아 내지 못하면 라이브러리 조사

-> 라이브러리 함수와 같은 이름을 가지는 함수 정의 시, 사용자 버전 이용.표준 라이브러리는 불가


### 언어 링크

함수에 영향을 줌



c++컴파일러는 오버로딩된 함수에 대해 서로 다른 기호 이름을 생성하기 위해 이름 맹글링, 이름 장식 과정을 거침



ex)

c++컴파일러는 spiff(int)를 _spiff_i, spiff(double, double)은 _spiff_d_d로 변환가능. 이런 것을 언어 링크라고 함



c++프로그램에서 c라이브러리를 미리 컴파일된 함수 사용 하기 위해서는

extern "C"void spiff(int);//c프로토콜 이용



### 기억 공간, 동적 대입

기억 공간 형식은 동적 메모리에는 적용 x, 그러나 동적 메모리를 추적하는 데 사용되는 자동 및 정적 포인터 변수에는 적용 됨



new연산자 이용 초기화

int *pi = new int(6); //*pi는 6

순차적인 구조체나 변수의 초기화는 c++11에서만 사용 가능

중괄호 이용한 리스트 초기화 사용

int* pi = new int[2]{1,2};



new 실패하는 경우

필요한 메모리의 양을 확보할 수 없는 경우

과거에는 null포인터 반환, 최근에는 new가 std::bad_alloc예외 반환



new : 연산자, 함수, 대체 함수

new , new[]는 두가지 함수 호출

void *operatornew(std::size_t) //new

void *operatornew[](std::size_t)//new[]

대입 함수라고 부름. 전역 이름 공간의 일부임





std::size_t는 typedef형

int* pi = new int;

//int *pi = new(sizeof(int))

delete pi; //delte(pi);



위치 지정 new

사용자가 사용할 위치를 지정할 수 있는 위치 지정 new가 잇음

new헤더 파일 포함



int *pi = new(주소) int; //주소에 놓임





## 이름 공간



### 이름 공간 기능

이름이 명명된 이름 공간을 만들 수 있는 기능 추가됨.

주된 목적은 이름을 선언하는 영역을 따로 제공 하는 것.



하나의 이름 공간에 속한 이름은 동일한 이름으로 다른 이름 공간에 선언된 이름과 충돌 x



이름 공간은 전역 위치 또는 다른 이름 공간 안에 놓을 수 있음. 블록 안에는 선언 불가. 기본적으로 외부 링크 가짐

::을 사용하여 접근



ex)

namespace n{ int n1; int n2;}

n::n1 = 2;



### using선언, 지시자



이름 공간에 속해있는 이름을 간편하게 사용 할 수 있는 using 선언, using지시자 제공



using선언은 하나의 특별한 식별자 사용할 수 있게 함.

using지시자는 이름 공간 전체에 접근가능하게 함.



ex)

int n1;

int main(){

using n ::n1;

int n1; //에러, 지역n1존재

cin >> n1; //n::n1

cin >> ::n1 // 전역

...

}



using 선언은 하나의 이름만 사용 가능

using지시자는 모든 이름 사용 가능



using namespace n; //n에 속한 모든 이름 사용 가능



std에 주로 이용햇엇음.



컴파일러는 두 using 선언 함께 사용 허락 x



using 지시자 vs using 선언

using 지시자와 using 선언 여러번 사용 하는 것은 같지 않음.

using 선언이 놓이는 위치에 그 이름을 선언하는 것과 같음.

이미 이름이 함수 안에 있으면, using선언으로 같은 이름 넣을 수 없음



using지시자는 using선언과 그 이름공간 자체를 둘 다 포함하는  최소한의 선언 영역에 선언하는 것과 같음.



ex)

int n1; //전역

int main(){

using namespace n;

int n1; //허용, n::n1가림

cin >> n1; //지역 n1

cin >> ::n1;

cint >> n::n1 // n::n1

....

}

using선언이 더 안전.

using지시자는 모든 이름을 추가시킴


