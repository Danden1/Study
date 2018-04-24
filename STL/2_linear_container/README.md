# 순차 컨테이너

원소들을 선형적인 순차열로 저장(정렬 안함)

- array<T,N> 타입 T객체, 고정길이 N으로 된 순차열 정의 원소 추가, 삭제 불가

- vector<T> 타입 T객체, 가변 길이 순차열. 필요할 때 자동으로 길이 늘어남. 끝에서만 원소 추가 삭제 가능

- deque<T> 양쪽끝에 추가 삭제 가능

- list <T> 이중 연결 리스트, 가변길이 순차열. 모든 위치에 추가, 삭제 가능. 이동하면서 원소 찾아야함. 속도 느림

- forward_list<T> 단일 연결리스트. 리스트보다 빠르고 작은 메모리 사용, 접근 시 앞에서만 접근가능.

## array<T.N>

array는 배열과 비슷, 2가지 장점 잇음.

1. at()으로 원소에 접근, 벗어난 인덱스에 접근하는 지 탐지 가능.

2. 함수에 개수 별도로 전달 안해도 됨.



array헤더 파일 필요

std::array<int, 100> data{};//0으로 초기화

~~{1,2,3}; //나머지 0으로

data.fill(3); //모든 원소 3



data.at(0) = data.at(1);

범위 벗어나면, std::out_of_ragne 예외 발생

data.size();//원소 개수


std::array<int,10> val;

std::iota(std::begin(val), std::end(val), 10);// 10~19까지 설정

numeric헤더 파일

## vector<T>

vector헤더 파일 필요

std::vector<int> val;

데이터 추가 시 메모리 자동으로 할당

val.reserve(10);//10개 저장 가능한 메모리 공간 할당

현재 용량 10보다 크면 아무것도 안함.

만약 변하면, 반복자 다시 생성해야함.

std::vector<int> val{2,3,4,5};

메모리 할당은 시간비용 비쌈

std::vector<int> val(5); //원소 5개

기본값 0으로 초기화

추가공간 할당 횟수 최소화해서 좋음

~~(5,10); // 5개 10으로 초기화



std::array<int,5> arr{1,2,3,4,5};

std::vector<int> arr_copy{std::begin(arr), std::end(arr)};



### 벡터 용량 크기

size()는 원소의 개수

capacity()는 용량

타입은 vector<T>::size_type



resize()로 size변경 가능

std::vector<int> v{1,2};

v.resize(3); //1,2,0

v.resize(4,7); //1,2,0,7

v.resize(3); //1,2,0

vector size줄여도 capacity는 그대로.



### 원소에 접근

[]로 접근가능

생성은 반드시 

push_back(), insert(), emplace(), emplace_back() 사용



front(), back()멤버 함수는 1원소, 마지막 원소 반환

참조 반환

v,front() = 3;//가능

### 반복자 사용

vector의 반복자는 랜덤 액세스 반복자.

push_back()함수 있으므로, 새 원소 뒤에 추가할 때,

back_insert_iterator사용가능
