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


## priority_queue<T>
  

원소 들을 정렬된 순서로 담아놓는 큐.

순위가 가장 높은 원소가 큐의 앞에 옴.

큐래서 1원소에만 접근 가능.

우선순위는 자기가 결정



세 가지 매개변수 존재. 두 가지는 기본인수

1. 저장할 객체 타입. 2. 원소 저장에 사용할 기반 컨테이너(vector가 기본) 3. 원소의 순서를 결정하는 조건자(함수타입, 기본 less<T>)
  
### 생성

std::priority_queue<int> n;

std::int ar[]{1,2,3,4};

std::priority_queue<int> n {std::begin(ar), std::end(ar)};
  


front(), push_back(), pop_back(), size(), empty()지원하면 컨테이너 사용 가능



std::vector<int> v{1,2,3,4,5};
  
std::priority_queue<int> n {std::less<int>(), v}; //5 4 3 2 1

### 연산

- emplace(), push() : 원소를 적절한 위치에 넣음.

- top() : 첫 번째  객체에 대한 참조

- pop() : 첫 원소 제거

- size(), empty(), swap(priority_queue<T> &other)



## 힙

힙은 컨테이너가 아닌 데이터 구성 방식


### 생성

힙다루는 함수는 algorithm 해더에 템플릿으로 정의되 있음.

max_heap()은 랜덤액세스 반복자로 정의한 원소들을 재배치 해서 힙을 만듬.

std::vector<int> num{2,10,3,6,8,12,1};
  
std::make_heap(std::begin(num), std::end(num)); //12 10 3 6 8 2 1

   12
   
  10  3

6  8 2   1

priority_queue의 인스턴스는 내부에서 힙 생성.


priority_queue의 장점은, 

- 원소 순서가 자동으로 정렬 됨.

- 첫 원소에만 접근간으 해서, 정렬된 상태 유지.



힙도 장점 있음.

- 어떤 원소에도 접근 가능. 순서 망가뜨릴 수 있지만, make_heap()으로 복구 가능.

- 랜덤 액세스 밴복자를 지원하는 컨테이너로 힙 생성 가능.

- 힙 순서 유지하는 힙 함수는 사용 시, 힙을 우선순위 큐로 쓸 수 있음.


### 연산

힙 생성 후, 원소 추가하고 싶으면,

algorithm의 push_heap() 함수가 원소 추가 함.



힙에 원소 추가하려면, 순차열에서 동작하는 메서드를 이용해, 원소를 순차열의 뒤에 추가해야 함



std::vector <int> num{~~};

std::make_heap(std::begin(num), std::end(num));

num.push_back(11);

std::push_heap(std::begin(num), std::end(num));



힙 생성 시 비교 함수 지정 했다면, push_heap()의 3번재 인자로 같은 함수 줘야 됨.


가장 큰 원소 제거 과정은

먼저 pop_heap()호출, 그다음 가장 큰 원소 제거.

std::pop(std::begin(num), std::end(num));

num.pop_back();



is_heap()으로 범위가 힙인지 알 수 있음. 기본함수는 less<>

is_heap_until()은 힙이 아닌 원소의 첫 위치 반환.



## 컨테이너에 포인터 저장.

보통 객체보다 포인터 저장한느 것이 더 좋음.

그리고 스마트 포인터가 대부분 더 좋음.



- 컨테이너에 포인터 저장하는 것은, 포인터가 가리키는 개체가 아니라 포인터가 복제 된다는 것. 빠름.

- 다형성 얻을  수있음. 기반 타입의 원소 가리키는 포인터 저장 가능 하게 컨테이너 정의하면, 파생 타입 객체의 포인터로 저장 가능.

- 정렬 빨라짐.



    std::vector<std::unique_ptr<std::string>> words;
    
    words.push_back(std::make_unique<std::string> ("one"));
    
make_unique<T>()은 객체와 스마트 포인터 한 번에 만듬.
  
unnique_ptr이라서 복제는 안됨.

shared_ptr로 해결 가능.



### 순차열 컨테이너에 퐁니터 저장.



    std::vector<std::shared_ptr<std::string>> words;
    
    std::string word;
    
    while(true){
    
      if((std::cin >> word).eof()){
        std::cin.clear(); //eof초기화
        
        break;
        
      }
      
      words.push_back(std::make_shared<string> (word));
    }
