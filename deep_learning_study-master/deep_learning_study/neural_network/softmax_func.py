import numpy as np

def softmax(a): #c는 상수
    c = np.max(a)
    exp_a = np.exp(a-c)#오버플로 막음
    sum_exp_a = np.sum(exp_a)
    y = exp_a/ sum_exp_a

    return y
a = np.array([0.3, 2.0, 4.0])
print(softmax(a))
