(x_train, t_train), (x_test, t_test) = load_mnist(normalize = True, one_hot_label = True)
#https://github.com/WegraLee/deep-learning-from-scratch/blob/master/dataset/mnist.py 참고 

train_loss_list = []

#하이퍼파라미터
iters_num = 10000 #반복횟수
train_size = x_train.shape[0]
batch_size = 100 #미니배치 크기
learning_rate = 0.1 #학습률

network = TwoLayerNet(input_size = 784, hidden_size = 50, output_size = 10)

for i in range(iters_num):
  #미니배치
  batch_mask = np.random.choice(train_size, batch_size)#0~train_size -1의 수 중에 batch_size개수를 랜덤으로 뽑음.
  x_batch = x_train[batch_mask]
  t_batch = t_train[batch_mask]
  
  grad = newtwork.numerical_gradient(x_batch, t_batch)
  
  for key in ('W1', 'b1', 'W2', 'b2'):
    #매개변수 갱신
    network.params[key] -= learning_rate*grad[key]
    
  #학습경과
  loss = network.loss(x_batch, t_batch)
  train_loss_list.append(loss)
