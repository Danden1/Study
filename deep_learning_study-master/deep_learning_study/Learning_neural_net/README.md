# 신경망 학습

### 손실함수

1. 평균제곱오차(mean squared error, mqe)

  E = 0.5*∑(y-t)^2
  
  y는 신경망 출력, t는 정답 레이블
  
    def mqe(y,t):
      return 0.5*np.sum((y-t)**2)
      
2.  교차 엔트로피 오차(cross entropy error, cee)

  E = -∑(tlny)
  
    def cross_entropy_error(y,t):
      delta = 1e-7
      return -np.sum(t*np.log(y+delta))
      
delta 를 더하는 이유는 0이 입력되면 -inf가 됨.

배치용

    def cross_entropy_error(y,t):
      if y.ndim == 1:
        t = t.reshape(1, t.size)
        y= y.reshape(1, y.size)
      #훈련 데이터가 원-핫 벡터라면 정답 레이블의 인덱스로 반환 
      if t.size == y.size:
        t = t.argmax(axis = 1)
      
      batch_size = y.shape[0]
      return -np.sum(np.log(y[np.arange(batch_size), t])) / batch_size 
      
미니배치는 훈련용데이터 중 일부를 무작위로 뽑아서 하는 것. 속도가 향상됨.

손실 함수 사용 하는 이유는 미분으로 매개변수의 값을 서서히 갱신하기 위해서


### 미분

    def numerical_diff(f,x):
      h = 1e-4
      return (f(x+h)-f(x-h)) / (2*h)
      
f(x)-f(x+h)/h는 x와 x+h사이의 기울기를 구해서, x+h와 x-h를 뺀 값을 쓴다.

### 편미분

변수가 여럿인 함수에 대한 미분

ex) f(x0, x1) = x0^2 + x1^2

    def numerical_gradient_no_batch(f,x):
      h = 1e-4
      grad = np.zeros_like(x) # x와 모양이 같은 0으로 초기화된 배열 생셩
      
      for i in range(x.size):
        tmp_val = x[i]
        
        #f(x+h)
        x[idx] = float(tmp_val)+h
        fxh1 = f(x)
        
        #f(x-h)
        x[i] - tmp_val - h
        fxh2 = f(x)
        
        grad[i] = (fxh1- fxh2)/ (2*h)
        x[idx] = tmp_val
     return grad
     
배치용

    def numerical_gradient(f,x):
      if x.ndim == 1:
        return numerical_gradient_no_batch(f,x)
      else:
        grad = np.zeros_like(x)
        
        for i , x in enumerate(x):
          grad[i] = numerical_gradient_no_batch(f,x)
        return grad
        
다차원 배열용

    def numerical_gradient(f,x):
      h = 1e-4
      grad = np.zeros_like(x)
      
      it = np.nditer(x, falgs = ['multi_index'], op_flags = ['readwrite])
      while not it.finished:
        idx = it.multi_index
        tmp_val = x[idx]
        fxh1 = f(x)
        
        x[idx] = tmp_val -h
        fxh2 = f(x)
        grad[idx] = (fxh1-fxh2)/ (2*h)
        
        x[idx] = tmp_val
        it.iternext()
    reutrn grad

### 경사하강법

현 위치에서 기울어진 방향으로 일정 거리 만틈 이동, 이동한 곳에서도 기울기 구해 다시 이동 하는 것.

x0 = x0 - lr*grad(x0)
x1 = x1 - lr*grad(x1)

학습률이라고 함.

lr의 값이 너무 크거나 작으면 좋은 결과를 얻을 수 없음.

    def gradient_descent(f, init_x, lr = 0.01, step_num = 100):
      #f는 최적화 함수, init_x는 초깃값, lr은 학습률, step_num은 반복 횟수
      x = init_x
      
      for i in range(step_num):
        grad = numerical_gradient(f,x)
        x -= lr*grad
      return x 

학습률은 사람이 직접 정해야 되는 변수. 이런 변수를 하이퍼파라미터 라고 함.

신경망에서의 기울기

    class simpleNet:
      def __init__(self):
        self.W = np.random.randn(2,3)#정규분포로 초기화
      
      def predict(self,x):
        return np.dot(x,self.W)
        
      def loss(self, x, t):
        z = self.predict(x)
        y = softmax(z) #전에 쓰던 code
        loss = cross_entropy_error(y, t)
        
        return loss
        
    net = simpleNet()
    
    def f(W):
      return net.loss(x,t)
    
    dW = numerical_gradient(f,net.W)
   
    print(dw)
   
