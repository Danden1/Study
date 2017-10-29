import numpy as np 
from util import im2col, col2im 
class Convolution: 
     def __init__(self, W, b, stride=1, pad=0): 
         self.W = W 
         self.b = b 
         self.stride = stride 
         self.pad = pad 
          
         # 중간 데이터（backward 시 사용） 
         self.x = None    
         self.col = None 
         self.col_W = None 
          
         # 가중치와 편향 매개변수의 기울기 
         self.dW = None 
         self.db = None 
  
     def forward(self, x): 
         FN, C, FH, FW = self.W.shape 
         N, C, H, W = x.shape 

         out_h = 1 + int((H + 2*self.pad - FH) / self.stride) 
         out_w = 1 + int((W + 2*self.pad - FW) / self.stride) 
  
         col = im2col(x, FH, FW, self.stride, self.pad) 
         col_W = self.W.reshape(FN, -1).T  # 내적 하기 위해, -1은 다차원 배열의 원소 수가 변환 후에도 똑같이 유지 되도록 묶어줌.
  
         out = np.dot(col, col_W) + self.b 
         out = out.reshape(N, out_h, out_w, -1).transpose(0, 3, 1, 2) 
 

         self.x = x 
         self.col = col 
         self.col_W = col_W 
  
         return out 
  
     def backward(self, dout): 
         FN, C, FH, FW = self.W.shape 
         dout = dout.transpose(0,2,3,1).reshape(-1, FN) 

 
         self.db = np.sum(dout, axis=0) 
         self.dW = np.dot(self.col.T, dout) 
         self.dW = self.dW.transpose(1, 0).reshape(FN, C, FH, FW)  
 
         dcol = np.dot(dout, self.col_W.T) 
         dx = col2im(dcol, self.x.shape, FH, FW, self.stride, self.pad) 
  
         return dx 
 
 # 전개 후, 행렬 최댓값 구하고, 적절한 형상으로 변형.
 class Pooling: 
     def __init__(self, pool_h, pool_w, stride=1, pad=0): 
         self.pool_h = pool_h 
         self.pool_w = pool_w 
         self.stride = stride 
         self.pad = pad 
          
         self.x = None 
         self.arg_max = None  
 
     def forward(self, x): 
         N, C, H, W = x.shape 
         out_h = int(1 + (H - self.pool_h) / self.stride) 
         out_w = int(1 + (W - self.pool_w) / self.stride) 
  
         col = im2col(x, self.pool_h, self.pool_w, self.stride, self.pad) 
         col = col.reshape(-1, self.pool_h*self.pool_w) 
 
         arg_max = np.argmax(col, axis=1) 
         out = np.max(col, axis=1) 
         out = out.reshape(N, out_h, out_w, C).transpose(0, 3, 1, 2) 

 
         self.x = x 
         self.arg_max = arg_max 
  
         return out 
  
     def backward(self, dout): 
         dout = dout.transpose(0, 2, 3, 1) 
          
         pool_size = self.pool_h * self.pool_w 
         dmax = np.zeros((dout.size, pool_size)) 
         dmax[np.arange(self.arg_max.size), self.arg_max.flatten()] = dout.flatten() 
         dmax = dmax.reshape(dout.shape + (pool_size,))            
         dcol = dmax.reshape(dmax.shape[0] * dmax.shape[1] * dmax.shape[2], -1) 
         dx = col2im(dcol, self.x.shape, self.pool_h, self.pool_w, self.stride, self.pad) 
          
         return dx 
