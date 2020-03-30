# STL Algorithms

[reference](https://oi-wiki.org/lang/csl/algorithm/)

容器去重:

```c++
deque<int> vec  = {1,2,2,3,3,11,9,6,5,5,7,2,11,8};
sort(vec.begin(), vec.end());
std::deque<int>::iterator res =  unique(vec.begin(),vec.end());
// template <class ForwardIterator>
// ForwardIterator unique( F.I. first, F.I. last) ;以(第一个)非重复元素替换连续的重复元素,返回一个pass-the-end 迭代器。
```

nth_element (Iterator first , Iterator nth, iterator last)	: 快排的pivot

merge(I first1, I last1, I first2,I last2)									: 合并两个有序序列(归并排序的merge)

random_shuffle(I first, I last)												: 随机打乱容器

binary_search(I first, I last, T & value)									: 二分查找value

find(I first, I last, T& value )													: 顺序查找value