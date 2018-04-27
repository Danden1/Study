# 컨테이너 어댑터

문자열 컨테이너를 다른 기능을 제공하는 순차열 커넽이너로 정의하기 위해 래핑하는 클래스 템플릿.

- stack<T>는 deque<T>를 스택으로 저장하는 방식으로 변환하는 어댑터 클래스 템플릿. stack 헤더 필요

- queue<T>는 deque<T>를 큐로 저장하는 방식

일정 조건 만족 시, 기반 컨테이너를 다른 컨테이너로 바꿀 수 있음. queue헤더 필요

- priority_queue는 vector<T>를 가장 큰 원소가 항상 앞에 오도록 원소들의 순서를 관리한느 큐로 변환. queue헤더 필요



## stack<T>

stack 컨테이너

std::satck<std::string> st; //string객체 저장하는 stack 컨테이너

stack 어댑터 템플릿은 매개변수 2개

1. 저장할 객체 타입. 2. 기반 컨테이너 타입

back(), push_back(), pop_back(), empty(), size() 지원하면 기반 컨테이너로 지정 가능.

std::stack<int, std::list<int>> f;

stack 생성 시, 초기화 리스트에 있는 개체로 초기화 불가.

복제해서 생성은 가능.

std::list<int> v{1,2,3};

std::stack<int,std::list<int>> st(v);



### 연산

- top() : top에 있는 원소에 대한 타입 T&의 참조 반환. 비어 있는 경우, 반환 값 정의 x

- push(const T& obj) : 상위에 obj의 복제본 넣음.

- push(T&& obj) " obj를 이동해서 넣음.

- pop() : 상위 원소 삭제

- size() : 개수

- empty()

- emplace() : 상위에 객체 추가

- swqp(stack<T> &other_stack)



## queue<T>

첫, 마지막 원소만 접근 가능


새 원소는 큐 뒤에섬나 추가 가능. 제거는 앞에

- pop() : 첫 원소 제거

- push(new_obj) : 새 원소 뒤에 추가

- front() : 첫 원소에 접근.

- back() 마지막 원소에 접근

생성은 스택이랑 비슷



기반 컨테이너 타입은 front(), back() push_back(), pop_front(), empty(), size()제공 해야 함


stack처럼 반복자 없음.

원소에 접근하는 유일한 방법은 첫 원소 하나씩 제거한느 것 뿐.
