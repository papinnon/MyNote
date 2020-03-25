# C++ Specialization

### class template explicit specialization

* **C++标准**要求，即便特化之后 __模板类(class template)__ 没有模板参数，也要在头部加上template<>  

  如：  

  ```c++
  template <class Key> struct hash {};
  template <> struct hash< char>{};  // ---> correct
  struct hash<char> {}; //----> Wrong, but allow in gcc?
  ```

* 我的思考：

   模板特化相当于 __类/结构体__ 的 重载(overload) ，在指定不同模板参数的情况下编译不同的代码。  

  

### Class template partial specialization

如果**模板类(class template)**拥有一个及以上的**模板参数(template argument)**, 可以针对**其中某个(或数个)**模板参数 **进行特化工作**。 **《泛型技术》一书中做如下解释**: ”针对任何模板参数更进一步的条件限制所设计出来的特化版本“。

如：

```c++
template <class I>
iterator_traits
{
    typedef typename I::value_type value_type; //这里使用的巢状型别声明，见后文.
}
//接下来进行偏特化设计
template <class I>
iterator_traits<const T *>//既然traits是用来提取iterator的相关型别的，提取一个const 的临时变量并没有什么卵用(如果不进行偏特化，则提取 const T)
{
    typedef T value_type;
}
```



在 **<<STL 源码分析>>** 3.4 章中， 介绍了 __iterator__ 的 **相关型别( associated types)**。 在**Iterator** 中，相关型别被编译器用于决定 __所指物件__ 之型别 ,  采用的方法是**巢状声明(nested type)**如：

```c++
template <typename T>
class RawIter
{
  T * ptr;
  RawIter(T * p=0):ptr(p){}
  T & operator *() const {return *ptr;}
    ...
};
//和--------------------------------------------
template <typename T>
class ATIter
{
  typedef T value_type; //巢状类型宣告(nested type) 
  T * ptr;
  ATIter(T * p=0):ptr(p){}
  T & operator *() const {return *ptr;}
    ...
};
//当有一个函数如下
template <typename I>
func()
{
    typename (*I)  variable1;
    typename (*I)  variable2;
    ...
}
如果没有 巢状型别声明 ，需要如下改写函数:
template <typename I , typename T>
func_implicit(T )
{
    T variable1;
    T variable2;
}
template <typename I>
func()
{
    func_implicit(*I);//即通过编译器推导
}
//而有巢状声明的iterator只需-------------------------------------------
template <typename I>
func()
{
    I::value_type variable1;
}
```



