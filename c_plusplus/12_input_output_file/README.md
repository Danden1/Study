# 입력, 출력, 파일

## 스트림,버퍼

c++프로그램은 입력과 출력을 바이트의 흐름(스트림)이라고 간주

입력 시 프로그램은 입력 스트림으로부터 바이트 추출, 출력시 스트림에 바이트 삽입

텍스트 기반을 바이트는 문자 나타냄



입력 스트림의 바이트는 키보드, 저장장치, 다른 프로그램으로부터 올 수 있음.

스트림은 매개자 역할



입력 다루려면 2가지 절차 필요

- 하나의 스트림을 입력에 연결

- 그 스트림을 파일에 연결

버퍼 이용시 효율적으로 처리 가능

정보 전송하기 위해 임시 저장 장치로 활용하는 메모리 블록

파일은 1바이트 씩 다룸

버퍼는 한 번에 많은 데이터 읽어, 저장 해둠

프로그램은 버퍼로부터 1문자씩 읽음. 메모리로부터 읽는 것이 더 빠름

다음 번 출력 위해 버퍼 비움



c++프로그램은 개행문자 전달 받으면 버퍼 비움