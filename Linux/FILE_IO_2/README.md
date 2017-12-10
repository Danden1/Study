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


