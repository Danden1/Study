import numpy as np
from SoftmaxWithLoss import *
from cross_entropy_error import *
from collectionis import OrderDict
from ReLu import ReLu
from Affine import Affine

class TwoLayerNet:
  def __init__(self, input_size, hidden_size, output_size, weight_init_std = 0.01):
    self.params = {}
    self.params['W1'] = weight_init_std * np.random.randn(input_size, hidden_size)
    self.params['b1'] = np.zeros(hidden_size)
    self.params['W2'] = weight_init_std * np.random.randn(hidden_size, output_size)
    self.params['b2'] = np.zeros(output_size)
    
    #Layers
    self.layers = OrderDict()
    self.layers['Affine1'] = Affine(self.params['W1'], self.params['b1'])
    self.layers['ReLu1'] = ReLu()
    self.layers['Affine2'] = Affine(self.params['W2'], self.params['b2'])
    
    self.lastlayer = SoftmaxWithLoss()
    
  def predict(self, x):
    for layer in self.layers.values():
      x = layer.forward(x)
      
    return x
    
  def loss(self, x, t):
    y = self.predict(x)
    return self.lastLayer.forward(y,t)
    
  def accuracy(self, x, t):
    y = self.predict(x)
    y = np.argmax(y, axis = 1)
    if t.ndim != 1 : t = np.argmax(t,axis = 1)
    
    accuracy = np.sum(y==t)/ float(x.shape[0])
    return accuracy
    
  def gradient(self, x, t):
    #순전파
    self.loss(x,t)
    
    #역전파
    dout = 1
    dout = self.lastLayer.backward(dout)
    
    layers = list(self.layers.values())
    layers.reverse()
    for layer in layers:
      dout = layer.backward(dout)
      
    grads = {}
    grads['W1'] = self.layers['Affine1'].dW
    grads['b1'] = self.layers['Affine1'].db
    grads['W2'] = self.layers['Affine2'].dW
    grads['b2'] = self.layers['Affine2'].db
    
    return grads
