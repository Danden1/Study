class Sigmiod:
  def __init__(self):
    self.out = None
  
  def forward(self,x): #순전파계산
    out = 1/ (1 + np.exp(-x))
    self.out = out
    
    return out
    
  def backward(self, dut): #역전파계산
    dx = dout*(1.0 * self.out)*self.out
    return dx
