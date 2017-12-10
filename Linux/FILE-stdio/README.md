### 파일 포인터

표준 입출력 루틴은 파일 디스크립터를 직접 다루지 않음.

파일 포인터라는 독자적인 식별자 이용.

<stdio.h>에 정의된 FILE typedef를 가리키는 포인터.

열린 파일은 스트림이라고 부르기도 함. 읽기, 쓰기, 읽기/쓰기 모드로 열 수 있음.


## 파일 열기

    #include <stdio.h>
    
    FILE *fopen (const char* path, const char *mode);



### 모드

r 읽기 목적으로 파일 염. 스트림은 시작 지점.

r+ 읽기/쓰기, 스트림은 시작 지점

w 쓰기 목적. 파일이 이미 존재하면 길이를 0 으로 자름. 존재하지 않으면 새로 만듬.

w+ 읽기/쓰기. 파일이 이미 존재하면 길이를 0으로 자름. 파일 없으면 새로 만듬.

a 덧붙이기 상태에서 쓰기로 염. 존재하지 않으면 새로 만듬.

a+ 덧붙이기 상태, 읽기/ 쓰기. 파일이 존재하지 않으면 새로 만듬.


성공 시 유요한 파일 포인터를 반환. 실패시 NULL



## 파일 디스크립터로 스트림 열기.



이미 열린 파일 디스크립터를 통해 스트림을 만듬.


    #include <stdio.h>
    
    FILE* fdopen (int fd, const char *mode);



파일 디스크립터는 새로운 스트림과 연결될 뿐.


성공 시 유요한 파일 포인터 반환. 실패시 NULL



## 스트림 닫기


    #include <stdio.h>
    
    int fclose (FILE *stream);


버퍼에 쌓여 있지만 아직 스트림에 쓰지 않은 데이터를 먼저 처리함. 성공시 0, 실패시 EOF



### 모든 스트림 닫기.


    #define _GNU_SOURCE
    
    #include <stdio.h>
    
    int fcloseall(void);



표준 입력, 출력, 에러를 포함하여 현재 프로세스와 관련된 모든 스트림 닫음.

언제나 0 반환. 리눅스에서만 사용 가능.


## 스트림에서 읽기


### 한 번에 한 문자씩 읽기


    #include <stdio.h>
    
    int fgetc(FILE* stream);



unsigned char 타입을 int 타입으로 변환해서 반환.

파일 끝이나 에러를 알려주기 위해서 이런 에러 상황 일 때 EOF반환.

반드시 int 타입으로 저장 해야됨. char타입으로 저장 시 에러 확인 불가.



### 한 줄 씩 읽기

    #include <stdio.h>
    
    char* fgets(char *str, int size, FILE *stream);


stream에서 size 보다 하나 적은 내용을 읽어서 결과를str에 저장함. 마지막 바이트 읽은 후, 버퍼 마지막에 null문자 저장.

EOF나 개행문자를 만나면 읽기를 중단함.

개행문자를 읽으면 \n을 저장.

성공 시 str반환, 실패 시 NULL반환


fgetc()로 fgets()대체 가능.

    char *s;
    
    int c;
    
    s =str;
    
    while(--n > 0 && (c = fgetc (stream)) != EOF) //n-1 바이트만큼 읽음.
        
        *s++ = c;
    
    *s = '\0';
    

### 바이너리 데이터 읽기


    #include <stdio.h>
    
    size_t fread(void *buf, size_t size, size_t nr, FILE* stream);


stream에서 각각 크기가 size바이트인 엘리먼트를 nr개 읽어서 buf가 가리키는 버퍼에저장.

읽어들인 엘리먼트 개수를 반환. nr보다 적은값 반환 하여 실패나 EOF를 알려줌.



변수의 크기나 정렬, 채워넣기, 바이트 순서가 다르기 때문에 어떤 애플리케이션에서 기록한 바이너리 데이터를 다른

애플리케이션에서는 못 읽을 수 있음.



## 스트림에 쓰기


### 한 번에 문자 하나만 기록.

    

    #include <stdio.h>
    
    int fputc (int c, FILE *stream);


### 문자열 기록



    #include <stdio.h>
    
    int fputs( const char *str, FILE *stream);

성공 시 음수가 아닌 값 반환, 실패시 EOF반환.



### 바이너리 데이터 기록




    #include <stdio.h>
    
    size_t fwrite(void* buf, size_t size, size_t nr, FILE *stream);




## 스트림 탐색



    #include <stdio.h>
    
    int fseek(FILE *stream, long offset, int whence);


whence를 SEEK_SET로 설정지 파일 위치를 offset으로 설정.

SEEK_CUR이라면 현재위치 + offset 값으로 설정.

성공시 0, EOF지시자 초기화, 실패 시 -1



    #include <stdio.h>
    
    int fsetpos(FILE *stream, fpos_t *pos);


stream의 위치를 pos로 설정.

성공시 0, 실패 시 -1


    #include <stdio.h>
    
    void rewind(FILE *stream);


stream의 위치를 시작 위치로 되돌림.




### 현재 스트림 위치 알아내기.



    #include <stdio.h>
    
    long ftell(FILE *stream);


에러시 -1

    #include <stdio.h>
    
    int fgetpos(FILE *stream, fpos_t *pos);


성공 시 0, 현재 스트림 위치를 pos에 기록. 실패 시 -1



## 스트림 비우기


사용자 버퍼를 커널로 비워서 스트림에 쓴 모든 데이터가 write()를 통해 실제로 디스크에 기록되도록 만드는 인터페이스 제공.


    #include <stdio.h>
    
    int fflush(FILE *stream);


stream에 있는 쓰지 않은 데이터를 커널로 비움.

stream이 NULL이면, 모든 입력 스트림이 비워짐.

성공시 0 , 실패 시 EOF



fflush는 사용자 버퍼에 있는 데이터를 커널 버퍼로 쓰기만 함.

write()를 사용하는 효과와 동일.

데이터가 매체에 바로 기록되려면 fflush호출 후, 바로 fsyn() 호출 해야함.


## 에러와 EOF

    #include <stdio.h>
    
    int ferror(FILE *stream);

에러 지시자가 설정되어 있을 경웅에는 0이 아닌 값 반환, 그렇지 않은 경우에는 0 반환

    #include <stdio.h>
    
    int feof(FILE *stream);

eof 지시자가 설정 되어 있는 경우에는 0이 아닌 값 반환, 그렇지 않은 경우에는 0 반환

    #include <stdio.h>
    
    void clearerr(FILE *stream);


에러지시자와 eof를 초기화함.

반환값이 없고, 항상 성공함.

## 파일 디스크립터 얻어오기

    #include <stdio.h>
    
    int fileno(FLE *stream);


성공시 stream과 관련된 파일 디스크립터 반환, 실패시 -1

스트림이 유효하지 않은 경우에만 실패.

파일 디스크립터와 스트림 기반의 표준 입출력 연산을 섞어서 쓰면 안 좋음.

## 스레드 세이프

스레드는 개별 프로세스 내에 존재하는 여러개의 실행 단위.

멀티코어 시스템에서는 둘 이상의 스레드가 같은 프로세스에서 동시에 실황 될 수 도 있음.

스레드에서 데이터에 접근할 때 동기화에 대한 주의를 기울이지 않거나 스레드 로컬로 만들지 않으면 스레드가 공유 데이터를 덮을 수 잇음.

이러한 것을 막기 위해 락 메커니즘 제공

두 스레드가 서로 동시에 쓰기 요청을 하더라도, 락 메커니즘으로 인해 하나가 먼저 완료되고 난 다음에 다른 요청이 실행됨.

### 수동으로 파일 락 걸기
    
    #include <stdio.h>
    
    void flockfile(FILE *stream);


stream의 락이 헤제될 때까지 기다린 후에 락 카운터를 올리고 락을 얻은 다음, 스레드가 stream을 소유하도록 만든 후에 반환.
    
    #include <stdio.h>
    
    void funlockfile(FILE *stream);

락 카운터를 하나 제거.

락 카운터가 0이 되면 현재 스레드는 stream의 소유권을 포기해서 다른 스레드가 락을 얻을 수 있도록 함.

    #include <stdio.h>
    
    int ftrylockfile (FILE *stream);

락이 걸려 있다면, 아무것도 하지 않고 즉시 0이 아닌 값 반환. 

락이 안 걸려 있다면, 락을 걸고 락 카운터를 하나 올린다음 그 stream을 소유하도록 만들고 0을 반환.

ex) 

    flockfile(stream);

    fputs("ssss\n", stream);
    
    fputs("ssss\n", stream);
    
    fputs("ssss\n", stream);
    
    funlockfile(stream);


