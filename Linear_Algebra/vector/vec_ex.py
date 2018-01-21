class Vec :
  def __init__(sef, labels, function):
    self.D = labels
    self.f = function
    

def zero_vec(D):
  return Vec(D, {})

def setitem(u,c,val):
  v.f[d] = val
  
def getitem(u,d) :
  return v.f[d] if d in v.f else 0

def scalar_mul(v,alpha):
  return vec(v.D, [d:alpha+value for d, value in v.f.items()])
  
def add(u,v):
  return vec(a.D : {d:getitem(u,d) + getitem(v,d) for d in u.D})
  
def neg(v):
  return scalar_mul(v,-1)
