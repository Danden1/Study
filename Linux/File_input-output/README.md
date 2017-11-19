## 시스템 콜
운영체제에서 리소스나 서비시를 요쳥하려고 사용자 역역에서 시작해서 내부로 들어가는 함수 호출

보안과 안정성 때문에 사용자 영역의 어플리케이션을 커널 여역으로 직접 연결하는 것은 불가능
대신, 시스템 콜을 실행하여 한다는 시그널을 커널로 보냄

## 파일
파일은 연속으로 나열된 바이트 배열에 저장된 데이터.

바이트를 읽고 쓰는 것이 가능.

파일 내부의 위치는 지정해서 수행가능

=> 파일 위치 또는 파일 오프셋이라고 함.

파일이 처음 열리면 파일 오프셋은 0, 파일 오프셋은 바이트 단위로 증가하거나 감소함.

파일 끝을 넘길 수도 있는데, 넘어가는 위치에서 바이트를 기록 하면 파일 끝~ 지정한 위치까지 0으로 채워짐

파일 오프셋은 음수 불가능.

파일 중간에 데이털르 기록하면 전에 있던 데이터를 덮어씀.


## 파일 열기

    #include <sys/types.h> 
    
    #include <sys/stat.h>    
    
    #include <fcntl.h> //flag
    
    int open(const char *name, int flags);    
    
    int open(const char *name, int flags, mode_t mode);

경로 이름이 name인 파일을 파일 디스크립터에 맵핑.

성공시 fd를 반환

오프셋은 0



### flag

O_RDONLY, O_WRONLY, O_RDWR 중 하나는 포함 해야됨.



### creat
    #include <sys/types.h>    

    #include <sys/stat.h>    
    
    #include <fcntl.h>
    
    int creat (const char *name, mode_t mode);    
    
    //open(name, O_WRONLY || O_CRAT || O_TRUNC, mode);

## read()로 읽기
    
    #include <unistd.h>
    
    sszie_t read(int fd, void *buf, size_t len);

현재 파일 오프셋에서 len만큼 buf로 읽어들인다. 성공시 buf에 쓴 바이트 숫자 반환.

실패시 -1 반환, errno을 설정함.
errno은 errno.h에 있음
오프셋은 읽은 바이트 크기 만큼 전진.
    
    
    unsigned long word;    
    
    sszie_t nr;
    
    nr = read(fd, &word, sizeof(unsiged long));    
    
    if (nr == -1)    //error

2가지

문제 존재.

1. len만큼 모든 데이터를 읽지 못할 가능성

2. 점검 후 처리 과정이 없음.


### 반환값
    - 호출이 len과 같은 값을 반환. len 바이트 전체를 읽어서 buf에 저장해음. 성공적임

    - 호출이 len보다 작지만 0보단 큼. 읽은 바이트 만큼 저장. len 바이트 읽기전에 eof 도달 햇거나, 읽는 도중 에러 발생.      - 0 반환. EOF를 나타냄.
    
    - 현재 사용 가능한 데이터가 없어서 호출이 불록됨. 논블록 모드에서는 해결가능.
    
    - 호출 -1, errno은 EINTR. 바이트를 읽기 전에 시그널이 도착햇음. 다시 호출하면 해결가능.     
    
    - errno이 EAGAIN. 현재 읽을 데이터가 없음. 블록된 상태임. 나중에 다시 읽기 요청 해야됨.
    
    - 둘 다 아닌 경우는 심각한 에러


### 전체 바이트 읽기

    sszie_t ret;
    
    while (len != 0 && (ret = read(fd, buf, len) != 0){
    
    if (ret == -1){
    
        if(errno == EINTR)
        
            continue;
        
        perror("read");
        
        break;
       
       }
       
       len -= ret;
       
       buf +=ret;
       
       }

### 논블록 읽기

블록되는 대신 읽을 데이터가 없다는 사실을 알려줌. 

=> 논블록 입출력

open flag를 O_NONBLOCK을 넘기면 됨.

읽을 데이터가 없으면 -1, EAGAIN으로 설정

EAGAIN을 점검해야됨. 데이터 부족 상황이 심각한 에러 발생으로 오인 가능함.


## write()

    #include <unistd.h>

    sszie_t write(int fd, const void *buf, size_t count);


성공 시 성공한 바이트 수 반환, 에러는 -1.  0은 0바이트를 씀.


### 부분 쓰기

    sszie_t ret, nr;

    while (len != 0 && (ret = write(fd, buf, len) != 0){
    
        if (ret == -1){
        
            if(errno == EINTR)
            
                continue;
            
            perror("write");
           
            break;    
            
            }
        
        len -= ret;
        
        buf +=ret;
        
        }

### 덧붙이기 모드

O_APPEND 옵션 이용하면 , 파일 끝에서부터 쓰기 연산 일어남.

### 동작 방식

write를 호출하면 리눅스 커널은 몇가지 점검 후, 단순이 데이터를 버퍼로 복사함.

나중에 커널은 모든 병견된 버퍼 수집 후, 최적 수준으로 정렬 후, 디스크에 씀(저장)


방금 쓴 데이터를 읽도록 요청한 순간, 데이터가 아직 저장이 안됬고, 아직 버퍼에 있으면, 버퍼에 들어있는 데이터를 가져옴.(실제로 아직 저장이 안된 상
태)

파일 버퍼의 쓰기 저장 기능을 강제로 켜거나, 모든 쓰기를 동기식으로 만드는 방식 가능.






## 동기식 입출력


### fsync(), fdatasync()

    #include <unistd.h>       

    int fsync(int fd);
    
    

    #include <unistd.h>        
    
    int fdatasync(int fd);

fsync()는 데이터를 디스크에 기록하는 작업과 inode의 파일 변경 시점을 갱신작업함.

inode와 파일 데이터는 디스크 상에서 인접해있지 않기 때문에 탐색 연산에 시간이 소요되며 변경된 날짜와 같은 메타데이터는 나중에 파일에 접근할 때 꼭 필요하지는 않으므로 fdatasync()를 사용 하는 편이 성능상 이득.

### sync()
    
    #include <unistd.h>
  
    void sync(void);

최적화에는 부족. 활용 범위는 넓음.

sync는 모든 버퍼 내용을 디스크에 동기화 함.

항상 성공.


### O_SYNC()

open()호출시 플래그로 넒기면 모든 파일 입출력을 동기화 함.

읽기는 언제나 동기화 됨. write()의 동기화를 도와줌.


### O_DSYNC

쓰기 작업 후에 메타데애ㅣ터를 제외한 일반 데이텀나 동기화 함. fdatasync()라고 보면됨.






## 파일 닫기

close() 시스템 콜을 이용해서 파일 맵핑을 끊어야 됨.

    #include <unistd.h>
    
    int close(int fd);

성공시 0 ,실패시 -1


파일을 닫더라도 디스크에 강제로 쓰지 않음.

확실히 기록 하려면 동기식 입출력 해야 됨.



## lseek()로 탐색


파일 오프셋은 특정 값으로 지정 가능.

    #include <sys/types.h>

    #include <unistd.h>
    
    off_t lseek(int fd, off_t len, int origin);


origin 인자는

SEEK_CUR : 현재 오프셋에서 pos를 더한 값으로 설정.pos가 0 이면 현재 파일 오프셋 반환.

SEEK_END : 현재 파일 크기에서 pos를 더한 값으로 설정. pos가 0 이면 파일 오프셋을 파일 끝으로 설정

SEEK_SET : 파일 오프셋을 pos를 설정.   

    off_t ret;
   
    ret = lseek(fd, 0, SEEK_END);        // 파일 끝

    int pos;     
    
    pos = lseek(fd,0,SEEK_CUR);      //현재 파일 오프셋

### 파일 끝을 넘어서 탐색하기.

파일 오프셋을 파일 끝을 넘길 수도 있음.

    int ret;
    
    ret = lssek(fd, (off_t) 1688, SEEK_END);
    

갱신된 오프셋에서 데이터 읽으면 eof 반환. 쓰기 요청이 들어오면 새로운 공간이 만들어지며, 0으로 채워짐.

0으로 채운 공간을 구멍이라고 함. 유닉스 계열에서는 물리적인 디스크 공간을 차지하지 않음.


물리적인 입출력이 필요없음.

=> 공간을 상당히 절약, 효율 높일 수 잇음.

구멍에 읽기 요청하면, 적절한 개수 만큼 0으로 채워진 값 반환.
