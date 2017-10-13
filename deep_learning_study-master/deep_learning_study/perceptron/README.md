## 퍼셉트론(perceptron)

![perceptron](https://github.com/Danden1/deep_learning_study/blob/master/perceptron/1.jpg)

    y = 0 (b + x1*w1 + x2*w2 <= 0)

    1 (b + x1*w1 + x2*w2 > 0)

이 식을 이용해서 and, or, nand 식을 만들 수 있다.


and 같은 경우는 둘다 참이여야 되니까 

-0.7 + x1*0.5 + x2*0.5를 한다면 둘 다 1이여야지 y가 1이 된다.

다른 나머지 식들도 이런 식으로 표현할 수 있다.

하지만 xor은 표현이 불가능하다. 하지만 퍼셉트론을 적절히 조합하면, 표현가능하다.

![xor](https://github.com/Danden1/deep_learning_study/blob/master/perceptron/3.jpg)

![erceptron](https://github.com/Danden1/deep_learning_study/blob/master/perceptron/2.jpg)


이러한 것을 다층 퍼셉트론이라고 한다. 소스는 perceptron 폴더 안에 들어있다.
