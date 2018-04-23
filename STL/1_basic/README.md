## 반복자

포인터와 비슷하게 동작하는 클래스 템플릿 타입의 객체

반복자 iter가 유효한 객체 가리키면,

*iter로 객체에 대한 참조 얻을 수 있음.

-> 포인터처럼 쓰면 됨.

### 반복자 얻기

컨테이너 객체에서 begin() 멤버함수는 첫5 원소, end()는 마지막 +1위치 반환

end()가 반환하는 반복자는 유효객체 가리키지 않아서 역참조하거나 증가 불가능



const 반복자 반환하는 cbegin(), cend() 전역함수 존대.


### 카테고리

1. 읽기 반복자

객체에 대한 읽기 권한 가짐

*iter 지원. 한 번만 읽을 수 있음.

감소 연산자 없음.


2. 출력 반복자

객체에 대한 쓰기 권한 가짐

새로운 값 할당 가능. 출력 반복자 한번만 사용가능

감소 연산자 없음

3. 순방향 반복자

입력 반복자 + 출력반복자 기능에 몇번 쓸수 있는 기능 더한 것. 재사용 가능

4. 양방향 반복자

 순방향 반복자 같은 기능에 역방향으로 이동 가능.

5. 랜덤 액세스 반복자

양방향 반복자 + 마음대로 접근 할 수 있는 긴으 더한 것.

iter +n, *(iter+n), iter1- iter2



### 역방향 반복자

rbegin(), rend()는 마지막 원소와 첫번째 원소에 하나 더 앞 위치 가리킴

rbegin ++하면, <- 방향으로 이동

거꾸로 이동한다고 보면 됨.

### 삽입 연산자

어느위치든 새 원소들을 범위로 추가 가능.

- back_insert_iterator는 push_back()멤버함수로 컨테이너 끝에 새 원소 추가. vector, list, deque

- front_insert_iterator는 push_front()멤버 함수로 컨테이너 앞에 새 원소 추가. list, forwrd_list, deque

- insert_iterator는 insert()멤버가 있는 컨테이너에 새 원소 삽입

첫 번째 인수로 지정된 컨테이너용 insert_iterator객체 반환.

두 번째 인수는 컨테이너에 원소를 삽입할 위치 가리키는 반복자



### 연산

- advance()첫 번째 인수로 받은 반복잘르 두번째 인수로 지정한 숫자만큼 증가시킴. 반환값 x

int data[] {1,2,3,4};

auto iter = std::begin(data);

std::advance(iter, 3); //4


- distance()는 지정한 범위에 있는 원소들 개수 반환

- next()는 첫번째 인수로 받은 반복자를 두번째 인수로 지정한 숫자만큼 증가시킨 반복자 반환. 기본값은 1

- prev()는 next반대로 감소시킴


## 함수를 인수로 전달

- 함수 포인터 이용

- 함수 객체

- 람다 표현식



### 함수 객체

operator()()를 오버로딩한 클래스의 객체

ex)

class V{

  public:
  
  double operator()(double x){return x*x;}

  double operator()(const Box &box){return box.getH()*box.getW();}

};

Box box {1.0, 2.0};

V vol;

vol(box);

V객체를 함수에 인수로 전달하고 싶다면 함수 매개변수의 타입을 V&로 지정.



### 람다 표현식

익명함수를 정의함

[](double val){return val*val;}

[]는 람다 소개자. 람다표현식의  시작

()는 람다 매개변수 목록. {}은 본문

반환타입은 반환되는 값의 타입이 기본으로 정해짐

위는 반환타입 지정 안햇음.

지정하려면

[](double val) ->double ~~~

auto cube = [] ~~~;

쓰면 cube는 함수포인터처럼 이용 가능.



템플릿 이용 전달

template <typename F>

void V(F fun){

  int x = 3;
  
  fun(x);

}

다른 방법은,

functional헤더에 std::function<>정의되 있음.

함수포인터에 대한 래퍼(람다표현식 포함)

템플릿 타입 인수는

<반환하는 값(매개변수 타입 목록)>

std::function<double(double)> op {[](double val){return val*val;}};

op변수는 타입만 같으면 재정의 가능



캠처 절

밖범위에 있는 변수를 본문에 어떻게 접근할지 지정

아무것도 없으면, 람ㄹ다 내부에서 로컬로 정의한 변수와 인수만 사용 가능.

[=] 은 모든 자동 변수를 값으로 캡처해서 접근 가능

원래 값은 변경 불가

매개변수 목록 다음 mutable 쓰면 밖 변수의 복제본 수정 가능

복제본은 static이라 볼 수 있음.

[&]는 밖의 모든 변수를 참조로 접근

mutable필요 없음.



[=,&factor]  은 factor를 참조로, 나머지 값으로

[&,factor] 는 factor를 값, 나머지 참조
