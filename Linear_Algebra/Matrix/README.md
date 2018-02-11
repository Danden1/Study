# 행렬

## 행렬이란?

### 전통적인 행렬

F상의 행렬은 엔트리들이 F의 원소인 2차원 배열

ex) R상의 행렬

[1 2 3]

[4 5 6]

2개의 행과 3개의 열을 가짐. 2x3행렬

행-리스트(row-list)들로 구성된 리스트로 표현

[[1,2,3],[4,5,6]]

ex)

[0 0 0 0]

[0 0 0 0]

[0 0 0 0]

[[0 for j in range(4)] for i in range(3)]

열 - 리스트(colum-list)들로 리스트를 표현

[[1,4], [2,5],[3,6]]

F상의 RxC 행렬을 카테시안 곱 Rx C로의 함수로 정의

R의 원소가 행 라벨, C의 원소를 열 라벨이라고 함.



### 행 열 엔트리

행과 열은 벡터로 해석 가능

ex)

! @ #

a 1 2 3

b 4 5 6

행 'a' : Vec({'!', '@', '#'}, {'!' : 1, '@' : 2, '#' : 3})

행들로 구성된 딕셔너리 표현

{'a' : Vec({'!', '@', '#'}, {'!' : 1, '@' : 2, '#' : 3}),

'b' : Vec({'!', '@', '#'}, {'!' : 4, '@' : 6, '#' : 6})}

### 파이썬 구현

벡터와 다른 점은



행렬에서 D값은 집합들의 쌍 (R,C)임

키들은 이 집합의 원소들

    class Mat:         
    
    def __init__(self, labels, func):
    
        self.D = labels
        
        self.f = func

### 단위 행렬



Def : 엔트리 (d,d)는 1, 다른 엔트리는 전부 0인 행렬



    Mat(({'a','b','c'},{'a','b','c'}), {('a','a') : 1, ('b','b') : 1, ('c','c'):1})

    def identity(D) :
    
        return Mat((D,D), {(d,d) : 1 for d in D})

### 행렬 표현의 변환

    def mat2rowdict(A):
        
        return {r:Vec(A.D[1],{r:A[r,c] for r in A.D[0]}) for c in A.D[0]}
        
    
    def mat2coldict(A):
    
        return {c:Vec(A.D[0], {r:a[r,c] for r in A.D[0]}) for c in A.D[1]}


## 열 공간(column space), 행 공간(row space)

Def: 행렬 M, 

M의 열공간 col M, M의 열들에 의해 생성된 벡터공간

M의 행공간 row M, M의 행들에 의해 생성된 벡터공간



## 벡터로서의 행렬


    def mat2vec(M):
    
        return Vec({(r,x( for i in M.D[0] for s in M.D[1]}, M.f)

## 전치(transpose)


Def: PxQ행렬의 전치는 M.T, QxP행렬



    def transpose(M):
    
        return Mat((M.D[1],M.D[0]), {(q,p):v for (p,q),v in M.F.items()})

## 선형결합의 행렬-벡터 곱셈과 벡터-행렬 곱셈

### 선형결합의 행렬 벡터 곱셈

Def: M을 F상의 RxC행렬, v는 F상의 C-벡터, M*v 는 선형결합

sigma c<C, v[c](M의 열 c)

v가 C-벡터가 아니면 성립 x

ex)

1  2  3         *     [7,0,4] = 7[1,10]+0[2,20]+4*[3,30] = [19,190]

10 20 30



### 선형결합의 벡터 행렬 곱셈

Def; M을 RxC행렬, w는 R-벡터, w*M은 선형결합



sigam r<R, w[r](M의 행 R)

w는 반드시 R-벡터

ex) 

    [3,4]  *  1  2  3    =   3[1,2,3]+4[10,20,30] = [43,86,129]                 

              10 20 30



## 도트곱의 행렬 벡터 곱셈

Def: M은 RxC행렬, u는 C-벡터, M*u는 R-벡터 v, v[r] 은 M의 행과 u의 도트곱

ex) 

1  2          * [3,-1] = [[1,2][3,-1],[3,4][3,-1],[10,0][3,-1]] = [1,5,30] 

3  4

10 0



Def: M은 RxC행렬, u는 R-벡터, M*u는 C-벡터 v, v[c] 은 M의 열과 u의 도트곱



### 선형방정식들의 시스템을 행렬 벡터 방정식으로

a1x = b1, ...amx=bm

=> A는 행들이 a1...am인 행렬,

b는 [b1...bm]인 벡터

Ax= b



### 삼각시스템, 삼각행렬

Def: nxn 상삼각(upper-triangular)행렬 A는 i>j에 대해 Aij = 0 인 행렬

ex 

1 2 3

0 4 5

0 0 6



Def: R,C는 유한집함. LR은 R의 원소들로 구성된 리스트

LC는 C의 원소들로 구성된 리스트 

RxC 행렬 A는 i>j에 대해 다음 조건이 만족하면 LR과 LC에대한 삼각행렬 임.

A[LR[i],LC[j]]= 0

ex)

  !  @  #                  !  @  #

a 0  2  3                b 10 30 20

b 10 20 30         =>    a 0  3  2

c 0  35  0               c 0  0  35



### 행렬-벡터 곱셈의 산술적 성질

M은 RxC행렬

- C-벡터v, 스칼라 a

M*(av)= a(M*v)



- C-벡터 u ,v

M*(u+v) = M*u+ M*v

## 영 공간(Null space)

### 동차 선형시스템과 행렬 방정식

Def: 행렬 A의 영공간은 집합 {V:A*v= 0}임

Null A로 나타냄

### 에러 정정코드

해밍이 발견한 첫 번째 에러정정코드는 해밍코드라 불림

오늘날 성형 이진 블럭 코드라고 함

데이터의 전송과 저장은 잡음 채널(noisy channel)에 의해 모델링 됨

잡음 채널에서 데이터의 비트가 가끔 반대로 됨.

비트들의 블럭은 GF(2)상의 벡터로 표현

이진 블럭코드는 함수 f: GF(2)m - >GF(2)n을 정의(해밍코드는 m은4,n은7)




