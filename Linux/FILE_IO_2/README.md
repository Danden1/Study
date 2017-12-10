## 벡터 입출력

### readv(),  writev()

    #include <sys/uio.h>
    
    ssszie_t readv(int fd, const struct iovec *iov, int cout);

fd 에서 데이터를 읽어서 count 개수 만큼의 iov 버퍼에 저장.

    #include <sys/uio.h>
    
    ssize_t writev (int fd, const struct iovec *iov, int count);

count 개수 만큼의 iov버퍼에 있는 데이터를 fd에 기록.

read()와 write()와 동일하게 작동 하지만, 여러개의 버퍼를 사용 한다는 점에서 구분됨.


    #include <sys/uio.h>
    
    struct iovec{
    
    void *iov_base; /* 버퍼의 시작 포인터 */
    
    size_t iov_len; /* 버퍼크기*/
    
    };

호출이 성공 했을 때 읽거나 쓴 바이트 개수를 반환. 반환값은 반드시 count * iov_len 값과 같아야됨. 에러 -1 반환



## 메모리에 파일 맵핑하기

리눅스 커널은 표준 파일 입출력의 대안으로 애플리케이션이 파일을 메모리에 맵핑할 수 있는 인터페이스 제공.

개발자는 메모리에 상주하는 데이터처럼 메모리를 통해 파일에 직접 접근 가능.

맵핑된 메모리 주소에 직접 쓴느 것만으로 디스크에 있는 파일에 기록 가능.

### mmap()


    #include <sys/mman.h>;                    
    
    void *mmap(void *addr, size_t len, int prot, int falgs, int fd, off_t offset);
    
    
fd가 가리키는 파일의 offset 위치에서 len바이트 만큼 메모리에 맵핑하도록 커널에 요청.

addr이 포함되면 메모리에서 해당 주소를 선호한다고 커널에 알려줌.

접근 권한은 prot에 지정, 추가적인 동작은 flag에 명시

addr인자는 대부분 0을 넘김.

메모리 맵핑의 실제 시작 주소를 반환함. 실패시 MAP_FAILED 반환

prot

PROT_NONE : 접근이 불가능한 페이지.

PROT_READ : 읽기가 가능한 페이지.

PROT_WRITE : 쓰기가 가능한 페이지.

PROT_EXEC : 실행이 가능한 페이지.

flag

MAP_FIXED : mmap()의 addr인자를 요구사항으로 취급.(0 안됨.) 해당 주소를 확보하지 못하면 실패. 기존 맵핑과 겹칠 경우, 중첩된 페이지는 새로운 맵핑으로 대체.

MAP_PRIVATE : 맵핑이 공유되지 않음을 명시. 

MAP_SHARED : 같은 파일을 맵핑한 모든 프로세스와 맵핑을 공유. 맵핑된 페이지에 쓰기를 하면, 실제 파일에도 동일한 내용을 기록.

MAP_SAHRED 와 MAP_PRIVATE를 함께 지정하면 안 됨.

파일을 맵핑 한 후에 파일 디스크립터를 닫더라도 프로세스는 여전히 맵핑된 주소에 접근 가능.


### 페이지 크기

페이지는 메모리 관리 유닛에서 사용하는 최소 단위.

mmap은 페이지를 다룸.

len인자가 페이지 크그 단위로 정렬되지 않았다면 다음 크기의 페이지 정수배로 확장됨.

### mmunmap()

    #include <sys/mman.h>
    
    int munmap(void *addr, size_t len);

mmap()으로 생성한 맵핑을 헤제.

성공시 0반환, 실패시 -1
    
    
    
 
