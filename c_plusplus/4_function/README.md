# 함수

### 함수 원형

- 함수 원형이 필요한 이유

함수원형은 컴파일러에게 함수의 인터페이스를 알려줌.


1. 어떤 타입의 매개변수를 갔는지 컴파일러에게 알려줌

2. 리턴 값을(cpu의 레지스터나 메모리)어떤 지정된 위치에 넣는다. 호출한 함수가 그 위치에서 값을 꺼냄.

  타입을 함수원형이 알려주므로, 몇 바이틀르 꺼내고, 처리해야 할 지 알수 있음.


## 함수, 배열


### 배열을 매개변수로 사용한느 것의 의미

int sum_arr(int arr[], int n);

sum_arr(ar,size);

ar배열의 첫 번째 주소와 배열원소 개수를 전달.

배열이 어디에 있는지(주소), 데이터 형을 함수에 전달하는 것임.

함수는 배열의 원본에 접근 가능.

### const로 보호

함수가 배열의 원본을 변형 시킬 수 있음.

배열인 매개변수에 const를 붙이면, 변경이 불가능

### 배열의 범위를 사용하는 함수

매개변수로 배열을 쓸 경우, size도 같이 매겨변수로 준다.

다른 방법은 배열의 시작을 지시하는 포인터와 배열의 끝을 지시하는 포인터를 전달.

### 포인터와 const

int age = 39;

const int * p = &age;

포인터 p를 사용하여 값을 변경 불가.

age를 사용해서는 변경 가능.

const int age = 10;

int *cp = &age; //불가능

사용하려면 포인터도 const사용

그러나 새로운 주소는 대입 가능.

이것을 막으려면,

int *const p2 = &age;

이용, 그러나 값은 변경 가능

const int *const p2 = &age;

둘다 변경 불가능.



## 함수, 2차원 배열

int data[3][4] = {0};

int total = sum(data,3);

int sum(int (*ar2)[4], int size);// int ar2[][4] 도 사용 가능




ar2[r][c] == *(*ar2 +r) +c) //true

ar2 // 첫번째 행(int 4개 배열)을 지시하는 포인터

ar2 +r //r번째 행 지시하는 포인터

*(ar2+r) //  ar2[r], r번째 행의 첫번째 int지시

*(ar2+r)+c // ar2[r]+c

그리고 const를 사용하지 않았음. ar2는 포인터를 지시하는 포인터

기본형을 지시한 포인터에 대해서만 const사용가능

## 재귀 호출


'인공 지능'과 같은 특변할 프로그래밍에서 중요

### 단일 호출

호출의 연쇄를 끝내기 위해 if문 사용

ex)

void recurs(argu){

statement1

if(test)

return recurs(arg)

statement2

}



각각의 함수 호출은 statement1만 수행하고 satement2부분은 수행을 유보함

마지막 함수 호출에서 ssatement2가 실행되고, 거슬러 올라감



### 다중 재귀 호출

하나의 작업을 서로 비슷한 두개의 작은 작업으로 반복적으로 분할해가면서 처리해야 하는 상황에서 유리

ex) 눈금자, 중간지점을 찾아 표시, 왼,오른쪽 구역으로 중간 지역 표시

=>이런 재귀적인 접근을 분할 정복이라고함

## 함수를 지시하는 포인터

함수도 주소가 있음.

함수의 주소는 그 함수에 해당하는 기계어 코드가 저장되어 있는 메모리 블록의 시작주소



### 함수 포인터 기초

-함수 주소 얻기

괄호를 빼고 함수이름만 사용하면 됨

pro(think); 

tho(think());

pro()함수는 내부에서 think() 함수를 불러냄.

tho()함수는 think() 함수가 먼저 실행되고,

리턴 값이 tho()함수에 전달됨.

double pam(int); //함수 원형

double (*pf)(int); //포인터

//(*pf)괄호 필요

pf = pam; //pf는 pam()함수 지시

double y = (*pf)(5); //pf(5)도 가능

### 함수 포인터의 변형

const double *f1(const double ar[], int n);

const double *f2(const double [], int );

const double *f3(const double *, int);

//위의 세 함수는 동일

const double (*p1)(const double ar[], int n); // 포인터 함수

const double (*p1)(const double ar[], int n) = f1; //도 가능

auto p2 = f2 // c++11자동 형 변환



const double *(*pa[3])(const double *, int) = {f1,f2,f3};

3을 넣어야 된느 이유 : pa는 3가지 원소를 가지는 배열

*pa[3]은 세 개의 포인터를 가지는 배열

여기에 auto는 사용 불가능

자동 형 변환은 단일값 초기화 할때 사용

=> 리스트 초기화는 불가

그러나 

auto pb = pa;

는 가능

배열의 이름은 배열의 첫 번재 주소이기 때문

-> pa,pb는 함수를 가리키는 포인터

배열 전체를 가리키게 하느 방법은

auto pc = &pa;

const double *(*(*pa)[3]) (const double *, int) = &pa;

(*pa)[3] 은 3개의 원소를 가지는 포인터

pd는 포인터, 세개의 원소를 가지는 배열을 가리킴

pd가 배열을 가리키는 포인터, *(pd)[i]는 배열의 원소

함수를 호출하기 위해서는 함수를 가리켜야함.

(*(*pd)[i]) (av,3)을 이용해야함.

**&pa == *pa == pa[0]

&pa +1 은 배열 뒤로 12바이트 다음 주소

### typedef 로 단순화

typedef const double *(*p_fun)(const double*, int);

p_funn p1 =f1;


