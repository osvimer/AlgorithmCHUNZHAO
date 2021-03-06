学习笔记

布隆过滤器 (Bloom Filter)
一个很长的二进制向量和一系列随机映射函数。
布隆过滤器可以用于检索一个元素是否在一个集合当中。
优点是空间效率和查询时间都远远超过一般的算法。
缺点是有一定的误识别率和删除困难。

布隆过滤器的原理：为每个元素准备若干的二进制位；如果分配给某个
元素的二进制位只要有一个为零，可以确定该元素不在过滤器中。但是
如果都为1，并不能说明该元素一定在过滤器中。（可能存在哈希冲突）

布隆过滤器的应用领域
1. 比特币网络
2. 分布式系统 (Map-Reduce) - Hadoop, SearchEngine
3. Redis 缓存
4. 垃圾邮件、评论等的过滤

缓存淘汰算法：
LRU（最近最少使用）
LFU（最近最频繁使用）

LRU Cache
两个要素：大小，替换策略
Hash Table + Double LinkedList
查询、修改、更新的时间复杂度都是 O(1)

排序算法：
复杂度 O(n^2) 的排序：选择，插入，冒泡
复杂度 O(nlogn) 的排序：堆排序，快速排序，归并排序
负责度 O(n) 的特殊排序: 计数排序，基数排序，桶排序

计数排序（Counting Sort)
计数排序要求输入的数据必须是具有确定范围的整数。将输入的数据值转换为键
存储在额外开辟的数组空间中；然后依次把计数大于 1 的填充回原数组中。

桶排序 (Bucket Sort)
桶排序的工作原理：假设数据的数据服从均匀分部，将数据分到有限数量的桶里；
每个桶再分别排序（有可能再使用别的排序算法或者是以递归方式继续使用桶排序。

基数排序 (Radix Sort)
基数排序是按照低位先排序，然后收集；再按照高位排序，然后再收集；以此类推，
直到最高位。有时候有些属性是有优先级的，先按低优先级排序，再按高优先级排序。

特殊的排序都是可以线性时间来完成的。

字符串匹配算法
1. 暴力法（brute force)
2. Rabin-Karp 算法 (RK）
在朴素算法中，我们需要挨个比较所有字符，才知道目标字符串中是否包含字串。
那么，是否有别的方法可以用来判断目标字符串是否包含字串呢？
答案是肯定的。确实存在一种更快的方法。为了避免挨个字符串对目标字符串和
字串进行比较，我们可以尝试一次性判断两者是否相等。因此我们需要一个好的
哈希函数 (hash function)。通过哈希函数，我们可以算出字串的哈希值，然后
将它和目标字符串中的字串的哈希值进行比较。这个新方法在速度上比暴力法有
显著提升。
3. KMP 算法
Boyer-Moore 算法：
Sunday 算法

字符串相关算法只要阐述清楚原理即可，不一定要求在白板上实现
