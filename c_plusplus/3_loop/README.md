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

### 시간 지연 루프
