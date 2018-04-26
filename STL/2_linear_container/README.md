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

copy() 처음 두 인수는 입력 스트림 반복자.

두 번째 인자는 스트림 반복자의 끝 지정.



### 새 원소 추가

컨테이너에 원소 추가하는 방법은 멤버 함수 호출이 유일


push_back()함수로 순차열 끝에 원소 추가.

std::vector<int> v;
v.push_back(3);

원소 추가에 이동 연산함. 우측 값 참조 매개변수 사용



empalce_back()은 더 효율적


std::vector<std::string> words;

wrods.emplace("HI");

인수는 컨테이너에 추가될 객체의 생성자에 넘길 인수.

-> 컨테이너 내부에서 객체 생성함.

push_back() 실행했을 때 발생하는 객체의 이동 연산 제거 가능.



std::string str{"alleged"};

words.emplace_back(str,2,3); //"leg"

idx 2에서 3문자



emplace()멤버 함수로 vector 내부에 새 원소 추가 가능.

1번재 인수는 개체가 생성될 위치 반복자.

반복자로 지정한 원소 앞에 객체 삽입됨.

2번째 이후는 삽입될 원소의 생성자에 전달.



insert()는 하나 이상 원소 추가 가능.

words.insert(++std::begin(words), "two");

std::string more[]{"five", "six"};

words.insert(--std::end(words), std::begin(more), std::end(more));

words.inset(std::cend(words)-1,2,"seven"); //seven 두 번


vector 끝 아닌 위치에 삽입하는 모든 작업은 부하 있음


### 원소 삭제

clear() 멤버함수로 모두 제거 가능.

pop.back()함수로 vector 마지막 원소 삭제 가능.

용량은 유지됨.

shrink_to_fit()으로 원소에 필요한 크기로 용량 줄임.

erase()로 하나 이상 제거 가능

data.erase(std::begin(data)+1);

//2번 째 제거

data.erase(std::begin(data) +1, std::begin(data)+3);

//2,3 삭제

erase()가 반환하는 반복자는 삭제된 원소의 다음 원소 가리킴.



algorithm에 있는 remove()는 범위에서 지정한 값과 일치하는 원소 제거

auto iter = std::remove(std::begin(words), std::end(words), "nine");



remove는 전역함수, 컨테이너 원소 제거 불가.

세 번째 인수와 일치하는 원소들을 벡터 컨테이너 앞으로 덮어쓰면서 복제

만약 처음 size()가 7, 삭제해도 size는 여전히 7

잉여 원소 제거하려면, erase()호출.

remove() 반환한 반복자 활용

words.erase(iter, std::end(words));

iter는 삭제 후 ,마지막 원소 +1 가리킴.



## deque<T>

deque헤더 파일 필요.

시작이나 끝에 객체 효율적으로 추가, 삭제 가능



### 생성

std::deque<int> data; //원소 없음

std::deque<int> data(10);  //10개 원소, 0으로 초기화



컨테이너의 복제본 생성하는 복제 생성자 존재.

std::deque<int> c_d{data};

std::deque<int> c_d{std::begin(data), std::end(data)};

//범위 지정 가능



### 접근

크기와 용량 항상 같음

### 원소 추가, 삭제

push_back(), pop_back()지원

동작 방식 같음

push_front(), pop_front()도 정의 되 있음.

emplace_back(), empalce_front(), emplace(), insert()있음.

erase(), clear()도 잇음.



### 내용 대체

assign()함수 멤버는 기존 원소들을 모두 대체, 3가지 버전 존재.



std::deque<std::string> words {"one", "two", "three"};

words.assign({"seven", "eigth", "nine"});

words에 있는 원소들을 대체함.



std::vector<std::string> wset{"this", "that"};

words.assign(std::begin(wset), std::end(wset));

범위로 채움

wrods.assign(8, "eight"); //8개

vector에서도 assign 사용 가능.



## list<T>

list헤더 파일 필요

순차열의 어느 위치라도 상수시간에 원소 삽입 삭제 가능

단 특정 위치에 있는 원소에 바로 접근 불가.

### 생성

다른 컨테이너의 복제본 생성 가능.

시작 반복자, 끝 반복자로 다른 순차열의 원소들로 초기화 가능.

list는 양방향 반복자, 정숫값 더하거나 빼기 불가.

++,-- 이용


### 원소 추가

push_front(), push_back(), emplace, emplace_front,emplace_back사용 가능

### 원소 제거

clear(), erase()사용

remove()는 인수와 일치하는 원소 제거

remove_if()는 인수로 단항 조건자 사용

단항 조건자는 원소타입이나, const참조 인수로 받고, bool반환. true반환하는 원소 모두 제거

data.remove_if([] (int n){return n%2==0;});//짝수 제거

함수 객체도 이용 가능

unique()함수는 둘 이상 중복되는 원소중 첫 번째만 남김(인접 중복 원소 제거)

보통 인수 없이 사용

인수로 이항 조건자 가능

true 반환 -> 같은 것으로 간주



### 원소 정렬, 병합

algorithm sort()함수 템플릿은 랜덤 액세스 반복자 필요.

리스트는 양방향이라서 사용 불가



list 템플릿에 sort()함수 멤버 별도로 정의되 있음.

인수 없는 sort()는 오름차순으로 정렬

두 원소 비교하는 조건자를 정의한 람다 표현식이나 함수 객체를 인수로 받음.



name_sort(std::greater<std::string>());

//functional에 있는 greater<>이용. 내림 차순



리스트의 merge()함수는 다른 리스트 컨테이너를 인수로 받음.

두 컨테이너의 원소들은 오름차순 여야 함.

인수 리스트의 원소들은 병합됨.

복제가 아닌 이동

두 번재 매개변수에 비교함수 지정 가능.



리스트 컨테이너의 splice()는 여러가지 오버로드 존재.


원자로 받은 리스트의 원소들을 현재 컨테이너의 특정 위치 앞으로 전송

std::list<std::string> my_w{"three", "six", "eight"};

std::list<std::string> your_w{"seven", "four", "nine"};

my_w.splice(++std::begin(my_w), your_w, ++std::begin(your_w));

첫번 째 인수는 대상 컨테이너의 위치 가리키는 반복자.

2는 잘라붙일 원소들의 원본

3은 원본리스트의 원소 가리키는 포인터

your_w : "seven", "nine"

my_w: "three", "four", "six", "eight"



원본 리스트에서 범위로 잘라 붙이고 싶으면, 3,4번째 인수로 범위 지정하면 됨

모든 원소 잘라붙이고 싶으면,

my_w.splice(std:;begin(my_w), your_w);

## forward_list<T>

forward_list헤더 필요

원소들을 역방향으로 순회 불가.

역방향 반복자 이용 불가.

순방향 반복자로 감소 불가. 증가만 가능.

마지막 원소에 대한 참조 반환하는 back()멤버 없음.

size()멤버 없음.

iterator헤더에 정의된 distance()로 원소 개수 구할 수 있음.



순방향 반복자 둘 이상 증가시킬 경우, iterator 헤더에 정의된 advance()함수가 유용

std::forward_list<int> data{1,2,3,4,5,6,};

auto iter = std::begin(data);

size_t n {3};

std::advance(iter, n); //4

advnace()는 void형, 반복자를 증가시킴.

forward_list 컨테이너 링크는 전부 순방향.

-> 원소 삽입, 잘라붙이기가 원소 뒤에서 일어남.

insert(), splice()대신,

inset_after(), splice_after() 제공

지정 위치 뒤에 원소 삽입하거나 잘라 붙임.

시작 위치에 하고 싶은 경우, 첫번 째 원소 하나 더 앞 가리키는 cbefore_begin(), before_begin()이용

