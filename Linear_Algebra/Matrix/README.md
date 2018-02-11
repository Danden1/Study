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




