import numpy as np

class Affine:
  def __init__(self, W, b):
    self.W = W
    self.b = b
    self.x = None
    self.dx = None
    seelf.db = None
    
  def forward(self, x):
    self.x = x
    out = np.dot(x,self.W) + self.b
    
    return out
    
  def backward(self,dout):
    dx = np.dot(dout, self.W.T)
    self.dW = np.dot(dout. axis = 0)
    
    return dx
