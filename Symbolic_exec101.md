## 符号执行

符号执行的目的就是 **确定会导致程序执行结果为某个特定向量的输入向量**， 如果结果向量时bug或漏洞，我们就可以利用符号执行来生成触发漏洞的测试用例了。

#### 约束规划求解

https://en.wikipedia.org/wiki/Constraint_programming

SMT，SAT

#### 处理与外设交互的系统调用

**[LLVM KLEE](https://github.com/klee/klee)** : 将一系列输入函数重写，使符号状态可以传递

open,read,write,stat,lseek,ioctl....



#### 原理

**把输入变为符号值，那么程序计算的输出值就是一个符号输入值的函数。**

1. 符号状态 $\sigma$:  表示从变量到符号表达式的映射
2. 符号化路径约束$PC$:  表示路径条件
3. $\sigma$ 和$PC$ 在符号执行的过程中会不断更新。在符号执行结束时，$PC$ 就会用约束求解器进行求解，以生成实际输入。
4. 当符号执行遇到了exit或者错误，符号执行终止。

#### 动态符号执行 (Concrete and symbolic, concolic)

动态符号执行是以**具体的值作为输入来模拟执行程序代码**。**动态符号执行相对于静态符号执行的优点是每次都是具体输入的执行**，在模拟执行这个过程中**，符号化的模拟执行比具体化的模拟执行的开销大很多**；并且模拟执行过程中所有的变量都为具体值，而不必使用复杂的数据结构来表达符号值，使得模拟执行的花销进一步减少。**但是动态符号执行的结果是对程序的所有路径的一个下逼近，即其最后产生路径的集合应该比所有路径集合小**。

类似于**我们将公式中的变量套具体数值**理解。
