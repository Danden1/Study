# 루프, 관계 표현식

## for

for문이 실행되기 전에 3번째 인자의 계산식이 먼저 실행이 됨

### c스타일 문자열 비교

문자배열의 이름 word 

word == "mate";

는 안됨

<cstring>의 strcmp함수로 비교 해야됨.

wrod는 주소이기 때문


### string 클래스 비교

word != "mate"; //word는 string

사용 가능. 오버로딩 때문


for루프는 루프를 카운터 할대 주소 사용

while는 얼마만큼 루프를 해야 할지 모를 때 사용

## do while 루프

탈출조건 루프임

루프 몸체를 먼저 시행, 조건은 나중에 검사

do   
  
  body

while(조건);

## range 기반의 for 루프 c++11

c++11에 새롭게 추가됨.

for(int x :{1,2,3,4})    cout << x << endl;

1,2,3,4를 출력함

### 파일 끝 (End Of File) 조건

1.많은 운영체제들이 리디렉션 기능을 제공 

-> 키보드 입력을 파일로 대체 가능

ex)

play.exe, fit.txt파일이 있으면,

play <fit

fit파일로부터 입력을 받음. <는 리디렉션 연산자

2. 많은 운영체제들이 eof 조건을 키보드 입력으로 시뮬레이션 함

unix는 ctrl + d, dos 는 ctrl+z+enter

cin은 eof 탐지시, eofbit, failbit를 1로 설정

eof()함수로 eofbit가 설정되어있는지 확인 가능

cin.clear()은 eof플래그를 지움.

cin.get(char)이 리턴하는 값은 cin 객체

istream 클래스는 istream 객체를bool값으로 변환하는 함수 제공

bool 값으로 반환된 결과는 마지막으로 시도한 읽기가 성공하면 true, 실패 false

### cin.get() 다른 버전

매개변수 없는  cin.get()함수는 입력으로부터 그 다음 문자를 읽어 리턴

ch= cin.get();

문자코드를 int형 값으로 리턴

이 함수는 eof에 도달 했을 때에는 더 이상 리턴할 문자가 없음. 대신 cin.get()은 eof로 나타내는 특별한 값 리턴.

iostream에는 정의되어 있음.

일반적으로 -1

그냥 ch!=EOF도 가능




## 중첩 루프, 2차원배열
int mat[4][5];

4개의 원소를 갖는 배열, 그 배열의 각 원소는 5개의 정수를 저장할 수 있는 또다른 배열





