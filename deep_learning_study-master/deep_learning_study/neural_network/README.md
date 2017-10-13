## 신경망

활성화 함수(h(x)) : 신호의 총합을 출력 신호로 변환하는 함수

![h(x)](https://github.com/Danden1/deep_learning_study/blob/master/neural_network/img/1.png)

활성화 함수 종류

1. 계단형 함수

h(x) = 0 (x <= 0)  or 1 (x>0)

선형함수이다. 그래서 은닉층에서 사용할 때는 의미가 없다.

ex) h(x) = ax,  h(h(h(x))) = a^3x, a^3 =c , h(h(h(x))) = cx

![step_func](https://github.com/Danden1/deep_learning_study/blob/master/neural_network/img/2.png)


2. 시그모이드 함수

h(x) = 1/(1+e^(-x))

비선형함수. 은닉층에 사용하기 좋다. 신경만 분야에서 오래 전 부터 사용해 왔다.

![s_func](https://github.com/Danden1/deep_learning_study/blob/master/neural_network/img/3.png)

3. ReLU함수

h(x) = x (x>0) or 0 (x <=0)

최근에 많이 사용하는 함수.

![ReLU](https://github.com/Danden1/deep_learning_study/blob/master/neural_network/img/4.png)




다차원 배열 계산

1. 행렬의 내적(행렬 곱)

![ca](https://github.com/Danden1/deep_learning_study/blob/master/neural_network/img/5.png)

주의! A의 열 수와 B의 행 수는 같아야 된다!

2. 신경망의 내적

![ca](https://github.com/Danden1/deep_learning_study/blob/master/neural_network/img/6.png)

3. 3층 신경망 구현

![neural_network](https://github.com/Danden1/deep_learning_study/blob/master/neural_network/img/7.png)

(1)신호전달 구현

A = XW + B

A = (a1, a2, a3)  X = (x1, x2)  B = (b1, b2, b3)//편향

W = ([w11, w21, w31], [w12, w22, w32]) //가중치

(2)출력층 설계

회귀에는 항등 함수, 분류에는 소프트맥스 함수 이용.(회귀 : 수치를 예측하는 문제, 선형 : 어느 클래스에 속하는지 분류)

항등 함수 : 입력을 그대로 출력.



소프트맥스 함수

![softmax_func](https://github.com/Danden1/deep_learning_study/blob/master/neural_network/img/8.png)

소프트맥스 함수를 적용해도 각 원소의 대소 관계는 변하지 않는다. 그래서 추론단계에서는 사용하지 않고, 학습시킬 때만 출력층에서 소프트맥스 함수를 사용한다.

출력층 노드(뉴련)의 개수는 분류 하고 싶은 클래스 수로 설정. ex) 0~9를 구별 하고 싶으면 10개를 사용.
