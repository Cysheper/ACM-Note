## Python语法
### $1.$ 排序函数
#### (1) `sorted()`
返回一个新的排序后的列表
```py
arr1 = [3, 4, 9, 1, 2]
arr2 = sorted(arr1)
print(arr1) #输出[3, 4, 9, 1, 2]
print(arr2) #输出[1, 2, 3, 4, 9]
```
#### (2)`.sort()`
它会修改原列表,是在原地排序,不会创建新的列表
```py
arr1 = [3, 4, 9, 1, 2]
arr1.sort()
print(arr1) #输出[1, 2, 3, 4, 9]
```
### $2.$ 幂运算
#### (1)`a ** b`
返回a ^ b
```py
a = 2
b = 3
print(a**b) #输出 2^3=8
```
#### (2)`pow(a, b, mod)`
返回 a ^ b % mod, 默认mod为1
```py
a = 2
b = 3
print(pow(a, b))    #输出8
print(pow(a, b, 2)) #输出0
```
### $3.$ 集合`set()`
#### (1) 创建集合
```py
st = set() #创建一个空集合
st1 = {1, 2, 3} #创建一个有元素的集合
```
#### (2) 插入元素
```py
st.add(10) #添加一个元素
st.update([5, 6]) #添加多个元素
```
#### (3) 删除元素
```py
st.remove(5) #删除元素5,如果元素不存在会报错
st.discard(7)#删除元素7,元素不存在不会报错
```
#### (4) 集合的运算(也适用于字典)
```py
a = {1, 2, 3, 4}
b = {3, 4, 5, 6}
# 并集
c = a | b #合并1
print(c) #输出{1, 2, 3, 4, 5, 6}
c = a.union(b) #合并2
print(c) #输出{1, 2, 3, 4, 5, 6}
# 交集
c = a & b #交集1
print(c) #输出{3, 4}
c = a.intersection(b) #交集2
print(c) #输出{3, 4}
# 差集
c = a - b
print(c)  #输出{1, 2}
c = a.difference(b)
print(c)  #输出{1, 2}
c = b - a
print(c)  #输出{5, 6}
c = b.difference(a)
print(c)  #输出{5, 6}
# 对称差集
c = a ^ b
print(c)  #输出: {1, 2, 5, 6}
c = a.symmetric_difference(b)
print(c)  #输出: {1, 2, 5, 6}
```
### $4.$ 列表 `list()`
#### (1) 创建列表
```py
lis = [1, 2, 3] #创建有元素的列表
lis = list([1,2,3]) #创建有元素的列表
lis = []        #创建空列表
lis = list()    #创建空列表
```
#### (2) 访问列表元素
```py
arr = [10, 20, 30, 40, 50]
# 访问第一个元素
print(arr[0])   #输出: 10
# 访问最后一个元素
print(arr[-1])  #输出: 50
# 访问倒数第二个元素
print(arr[-2])  #输出: 40
```
#### (3) 修改元素值
```py
arr = [10, 20, 30, 40, 50]
# 修改第一个元素
arr[0] = 100
print(arr)  # 输出: [100, 20, 30, 40, 50]
# 修改最后一个元素
arr[-1] = 500
print(arr)  # 输出: [100, 20, 30, 40, 500]
```
#### (4) 切片 
语法为: `lis[start:end:step]`
`start:起使下标 end:终点下标(不包括end) step:步长`
```py
arr = [10, 20, 30, 40, 50]
# 提取前 3 个元素
print(arr[:3])    #输出: [10, 20, 30]
# 提取第 2 到第 4 个元素(不包括第 4 个)
print(arr[1:4])   #输出: [20, 30, 40]
# 提取每隔一个元素
print(arr[::2])   #输出: [10, 30, 50]
# 逆序(从末尾开始,-1步长)
print(arr[-1::-1])#输出: [50, 40, 30, 20, 10]
```
#### (5) 添加元素
```py
arr = [10, 20, 30]
# append: 在列表末尾添加元素
arr.append(40)
print(arr)  #输出:[10, 20, 30, 40]
# insert: 在指定位置插入元素
arr.insert(1, 15)  #在索引 1 位置插入元素 15
print(arr)  #输出:[10, 15, 20, 30, 40]
# extend: 将另一个列表的元素添加到当前列表
arr.extend([50, 60])
print(arr)  #输出:[10, 15, 20, 30, 40, 50, 60]
```
#### (6) 删除元素
```py
arr = [10, 20, 30, 40, 50]
# remove: 删除第一个匹配的元素
arr.remove(30)
print(arr)  # 输出: [10, 20, 40, 50]
# pop: 删除并返回指定索引的元素
popped = arr.pop(1)
print(popped)  # 输出: 20
print(arr)  # 输出: [10, 40, 50]
# del: 删除指定索引的元素
del arr[0]
print(arr)  # 输出: [40, 50]
```
#### (7) 列表反转
```py
arr = [10, 20, 30, 40, 50]
# reverse: 原地反转
arr.reverse()
print(arr)  # 输出: [50, 40, 30, 20, 10]
# 切片反转: 返回一个新的反转列表
arr2 = arr[::-1]
print(arr2)  # 输出: [10, 20, 30, 40, 50]
```
#### (8) 列表的长度和统计
```py
arr = [10, 20, 30, 20, 40]
# 获取列表的长度
print(len(arr))  # 输出: 5
# 统计某个元素的出现次数
print(arr.count(20))  # 输出: 2
```
#### (9) 列表推导式(直接看示例)
```py
# 创建一个包含 1 到 5 的平方的列表
squares = [x**2 for x in range(1, 6)]
print(squares)  # 输出: [1, 4, 9, 16, 25]
# 生成 1 到 10 中的偶数的平方
even_squares = [x**2 for x in range(1, 11) if x % 2 == 0]
print(even_squares)  # 输出: [4, 16, 36, 64, 100]
# 生成两个列表的所有可能的配对
pairs = [(x, y) for x in range(1, 4) for y in range(1, 4)]
print(pairs)  # 输出: [(1, 1), (1, 2), (1, 3), (2, 1), (2, 2), (2, 3), (3, 1), (3, 2), (3, 3)]
# 将字符串中的每个字符转换成大写
words = ['hello', 'world', 'python']
capitalized_words = [word.upper() for word in words]
print(capitalized_words)  # 输出: ['HELLO', 'WORLD', 'PYTHON']

```
### $5.$ 字典 `dict()`
#### (1) 创建字典
```py
# 使用大括号创建字典
my_dict = {'name': 'Alice', 'age': 25, 'city': 'New York'}
# 使用 dict() 创建空字典
my_dict2 = dict()
print(my_dict)  # 输出: {'name': 'Alice', 'age': 25, 'city': 'New York'}
print(my_dict2) # 输出 {}
```
#### (2) 访问元素
```py
my_dict = {'name': 'Alice', 'age': 25, 'city': 'New York'}
# 使用键直接访问
print(my_dict['name'])  # 输出: Alice
# 使用 get() 方法访问
print(my_dict.get('age'))  # 输出: 25
# 使用 get() 方法时，如果键不存在，可以返回 None 或指定的默认值，避免抛出异常。
print(my_dict.get('address'))  # 输出: None
print(my_dict.get('address', 'Unknown'))  # 输出: Unknown
```
#### (3) 修改元素
```py
my_dict = {'name': 'Alice', 'age': 25, 'city': 'New York'}
# 修改键对应的值
my_dict['age'] = 26
print(my_dict)  # 输出: {'name': 'Alice', 'age': 26, 'city': 'New York'}
# 如果键不存在，会添加新的键值对
my_dict['address'] = '123 Main St'
print(my_dict)  # 输出: {'name': 'Alice', 'age': 26, 'city': 'New York', 'address': '123 Main St'}
```
#### (4) 删除字典中的元素
```py
my_dict = {'name': 'Alice', 'age': 25, 'city': 'New York'}
# 使用 del 删除键值对
del my_dict['age']
print(my_dict)  # 输出: {'name': 'Alice', 'city': 'New York'}
# 使用 pop() 删除键值对并返回值
address = my_dict.pop('city')
print(address)  # 输出: New York
print(my_dict)  # 输出: {'name': 'Alice'}
# 使用 popitem() 删除并返回一对键值
item = my_dict.popitem()
print(item)  # 输出: ('name', 'Alice')
print(my_dict)  # 输出: {}
```
#### (5) 获取字典的键、值和项
```py
my_dict = {'name': 'Alice', 'age': 25, 'city': 'New York'}
# 获取字典的所有键
keys = my_dict.keys()
print(keys)  # 输出: dict_keys(['name', 'age', 'city'])
# 获取字典的所有值
values = my_dict.values()
print(values)  # 输出: dict_values(['Alice', 25, 'New York'])
# 获取字典的所有键值对
items = my_dict.items()
print(items)  # 输出: dict_items([('name', 'Alice'), ('age', 25), ('city', 'New York')])
```

