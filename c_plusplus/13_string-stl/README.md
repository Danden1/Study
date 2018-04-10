# string 클래스, stl

## string클래스 

string헤더 파일 통해 지원됨

cstring은 c스타일 문자열 처리하는 문자열 함수 지원



### 문자열 생성

nbts : 널바이트 종료 문자



생성자


string(const char *s)     string 객체를 s가 지시하는 nbts로 초기화

stinrg(size_type n, char c) 문자 c로 초기화된 원소 n개의 string객체 생성

string(const string &str) string 객체를 string 객체 str(복사 생성자)로 초기화

string()  크기 0, stirng 객체 생성

string(const char *s, size_type n) string 객체를 s가 지시하는 nbts로 초기화, nbts의 크기 초과하더라도 n개의 문자까지 진행

tempalte<class Iter> string(Iter begin, Iter end) [begin, end) 의 범위에 있는 값들로 초기화.

string(const string &str, size_type pos, size_type n = npos) str로 초기화, pos위치에 시작해서 str끝까지 가거나, n문자를 사용하되 str끝 못넣음



### string 클래스 입력

string str;

getline(cin, str);

getline(str,":"); //:까지 읽고 :은 버림



string 버전들은 입력 문자들을 담을수 있도록 객체의 크기 자동으로 조절

그러나 제한 있음.

1. 상수 string::npos로 나타내는 문자열의 최대 허용 크기.

2. 프로그램이 사용할 수 있는 메모리 크기



getline()은 어느 하나가 일어날 때까지, 입력으로부터 문자을 읽어 하나의 문자열로 저장.

- 파일 끝 만나면, eofbit설정됨. fall(), eof() true리턴

- 구분문자에 도달, 구분문자는 입력스트림으로부터 제고되고 저장 x

- 가능한 최대 문자수 읽을 시, failbit 설정. fail() true 반환



### 그 밖 기능

하나의 문자를 문자열에 추가 할 때 생기는 일

이미 사용 중인 메모리 침범 할  수 있어서, 제자리에서 자라게 못함

새로운 블록 대입하고, 이전의 내용 새로운 위치로 복사.

많이 비효율적

많은 c++ 시스템들은 실제 문자열보다 큰 메모리 블록 대입하여 자랄 수 있는 공간 제공.



capacity()는 현재 블록 크기 리턴

reserve()는 블록 최소 크기를르 사용자가 요청하게 함



## 스마트 포인터 템플릿 클래스

smart pointer는 포인터처럼 행동하는 클래스 객체. 몇가지 추가긴으 가짐.



### 스마트 포인터 사용

3개 스마트 템플릿(auto_ptr, unique_ptr, shared_ptr)은 각각 new를 통해 얻어지는 주소를 대입할 포인터를 정의.

스마트 포인터가 수명 다하면, 파괴잔 delete사용하여 메모리 해제

new가 리턴하는 주소를 위 세 개 객체중 하나에 대입하면, 자동으로 메모리 해제됨.

memory 헤더 파일 필요

std::auto_ptr<string> ps (new string);//string *p대신 사용

### 스마트 포인터 고려 사항

스마트 포인터가 3가지인 이유

auto_ptr<string> ps (new string("new"));

auto_ptr<string> v;

v = ps;

불가능 같은 객체를 2번 해제해서. 

해결 방법

- 복사 수행하도록 대입연산자 정의

- 하나의 스마트 포인터만이 특정 객체 보유하도록 소유권 개념 도입.

스마트 포인터가 그객체를 소유하고 있는 경우에만, 파괴자가 그 객체 삭제, 그리고 대입 통해 소유권 넘김

(auto_ptr(실행 시 오류), unique_ptr(컴파일 불가능하게 함))

- 하나의 특정한 객체 참조한느 스마트 포인터들이 몇 개인지 추측하는 포인터 생성

(참조카운팅) 대입할 때마다 1증가, 수명 다하면 1감소

(shared_ptr)
