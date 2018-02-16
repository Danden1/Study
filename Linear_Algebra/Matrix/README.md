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

## 스파스(sparse)행렬 벡터 곱셈


Def: M이 RxC행렬, u가 C-벡터, M*u는 r<R에 대해 다음을 만족하는 R-벡터 v

v[r] = sigma c<C, M[r,c]u[c]



## 행렬과 함수의 만남

fM= FC->FR

fM(x) == M*x

## 함수에서 행렬로

fM= fA->fB

fM의 정의역은 fA, x는 A-벡터.

M의 열-라벨 집합은 A가 되어야됨.

fM의 공역은 fB M을 x에 곱한 결과는 B-벡터

M은 BxA행렬



## 선형함수

### 정의와 예



Def: U와 V를 필드 F상의 벡터공간. f:U->V은 다음 두조건을 만족 할 경우 선형함수라고 함.

a는 스칼라


1. f(aU) = af(U)

2. f(U*V) = f(U)*f(V)



### 선형함수와 영벡터

Def: 행렬의 영공간과 마찬가지로 선형함수 f의 커널을 {v:f(v) = 0}라고 정의. f의 커널은 Ker f라고 함



### 선형함수와 직선의 관계

f:U->V 는 선형 함수. u1, u2는 U 내 두가지 벡터. a1v1+a2v2는 선형결합

f(a1v1+a2v2)=a1f(v1)+a2f(v2)

{a1f(u1)+a2f(u2) : a1+a2 = 1}

f(u1), f(u2)의 모든 아핀결합들의 집합

즉 직선을 나타냄


### 대각 행렬

f([x1...xn])= [d1x1...dnxn]

d1

  .

   dn

이러한 행렬을 대각행렬이라고 함.

대각을 구성하는 엔트리들이 0이 아닐수 있기 때문

Def: 정의역 D에 대해 DxD행렬 M은 r!=c인 모든쌍 r,c <D

에 대해 M[r,c] = 0이면 대각 행렬


    def diag(D, entries):
    
    	return Mat((D,D), {(d,d) :entries[d] for d in D})


## 행렬 곱셈

RxS, SxT의 행렬을 곱하면 결과는 RxT

교환 법칙 x

Def: AB의 엔트리 rc는 A의행 r과 B의 열 c의 도트곱


### 행렬 곱의 전치

(AB).T = B.TA.T


