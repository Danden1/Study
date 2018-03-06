# 복합 데이터 형

## 문자열

cin은 빈칸, 탭 등이 있으면 그 위치에서 문자열이 끝난 것으로 간주함.

ex)

char name[6];

cin >> name; //Ali Dr

Ali\0을 name배열에 저장

Dr은 입력 큐에 남겨짐. 만약 cin이 또 호출되면, Dr이 저장됨.

### 한번에 한 행의 문자열 

1. getline()

Enter키에 의해 전달되는 개행 문자를 입력의 끝으로 간주, 한 행 전체를 읽음.

첫 번째 매개변수는 배열의 이름, 2번 째는 크기(널문자 포함)

cin.getline(name,6);



2. get()

개행문자를 입력 큐에 담아둠.

cin.get(name,6);

cin.get(); //문자열 하나를 읽음(개행문자)

cin.get(namm2,8);

cin도 개행문자를 입력 큐에 담아둠.



## string 클래스

<string>헤더 파일을 포함 시켜야 됨.

sring 클래스는 std이름 공간에 속해 있음.

string str;

cin >> str; // str은 입력에 맞게 크기가 조절 됨.

하나의 string 객체를 다른 string 개체에 간단히 대입 가능

한행을 입력 받으려면, getline(cin,str);



## 공용체

서로 다른 데이터 형을 한 번에 한 가지만 보관 가능한 데이터 형식

ex)

union one4all{

int int_val;

double double_val;

}

ine4all n;

n.int_val = 10;

n.double_val = 1.1; //double형을 저장, int형 값 소실

한 번에 하나의 값만 보관가능. 공용체의 크기는 가장 큰 멤버의 크기

## 열거체

c++의 enum은 const를 사용하여 기호 상수를 만드는 것에 대한 또 다른 방편 제공.


