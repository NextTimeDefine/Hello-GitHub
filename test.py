
'''
>>> import keyword	#保留关键字
['False', 'None', 'True', 'and', 'as', 'assert', 
 'break', 'class', 'continue', 'def', 'del', 'elif', 
 'else', 'except', 'finally', 'for', 'from', 'global', 
 'if', 'import', 'in', 'is', 'lambda', 'nonlocal', 'not', 
 'or', 'pass', 'raise', 'return', 'try', 'while', 'with', 'yield']
'''


#可以使用反斜杠 \ 来实现多行语句，在 [], {}, 或 () 中的多行语句，不需要使用反斜杠 \
str1 = '12345';
Temp_Data = True
if Temp_Data:
	print("Hello World!")
	print(str1[0:-1:2])	# 输出第一个到倒数第二个每间隔一个字符(步长2)输出一次
	print('True')
else:
	print('False')


import sys;
x = 'runoob';
sys.stdout.write(x + '\n')


x = 'a';y = 'b'
# print输出默认换行，不需要换行则在变量末尾添加 end=""
print('*************')		# 默认换行
print(x,end="")		# 不换行
print(y)    #换行输出
print('*************')

'''
 import 或者 from...import 导入相应的模块。
 将整个模块(somemodule)导入，格式为： import somemodule
 从某个模块中导入某个函数,格式为： from somemodule import somefunction
 从某个模块中导入多个函数,格式为： from somemodule import firstfunc, secondfunc, thirdfunc
 将某个模块中的全部函数导入，格式为： from somemodule import *
'''

# 导入系统模块
import sys
print('================Python import mode==========================')
print ('命令行参数为:')
for i in sys.argv:
    print (i)
#print ('\n python 路径为',sys.path)



a = 110;
if isinstance(a, int):	# 判断'a'是否为int类型数据
    print(True)
else:
    print(False)

'''
isinstance 和 type 的区别在于：
    type()不会认为子类是一种父类类型。
    type()不会认为子类是一种父类类型。
'''

'''
 列表(list)写在[]中间，元素用逗号隔开
 列表与字符串一样可以被索引与切片
 列表可用'+'来进行拼接操作可用'*'进行重复操作
 列表中的元素是可以改变的
'''
list_ = [ 'abcd', 786 , 2.23, 'runoob', 70.2 ]
tinylist = [123, 'runoob']

print (list_)        # 输出完整列表
print (list_[0])     # 输出abcd
print (list_[1:3])   # 输出[786,2.23]
print (list_[2:])    # 输出[2.23，runoob，70.2]
print (tinylist * 2)    # 输出两次列表
print (list_ + tinylist) # 拼接列表


def reverseWords(input1): 
	# 通过空格将字符串分隔符，把各个单词分隔为列表
	inputWords = input1.split(" ") 
	# 翻转字符串
	# 假设列表 list = [1,2,3,4], 
	# list[0]=1, list[1]=2 ，而 -1 表示最后一个元素 list[-1]=4 ( 与 list[3]=4 一样)  
	# inputWords[-1::-1] 有三个参数
	# 第一个参数 -1 表示最后一个元素
	# 第二个参数为空，表示移动到列表末尾
	# 第三个参数为步长，-1 表示逆向
	inputWords=inputWords[-1::-1] 

	# 重新组合字符串
	output = ' '.join(inputWords) 
	 
	return output 

if __name__ == "__main__": 
    input1 = 'I like runoob'	 # 初始化字符串
    rw = reverseWords(input1) # 翻转字符串
    print(rw)    # 输出 runoob like I

'''
 元组(Tuple)：与列表类似，但是元素不能被修改
 元组元素虽不可修改，但可包含可变对象，例如列表
 元组写在()中，元素之间用逗号隔开
 元组中的类型可以不想同

 特殊元组包含 0 或 1 个元素的元组的特殊语法规则
 tup1 = ()    # 空元组
 tup2 = (20,) # 一个元素，需要在元素后添加逗号
 元组也可使用'+'拼接
'''

tuple1 = ( 'abcd', 786 , 2.23, 'runoob', 70.2 )
tinytuple = (123, 'runoob')

print (tuple1)         # 输出完整元组
print (tuple1[0])      # 输出abcd
print (tuple1[1:3])    # 输出(786, 2.23)
print (tuple1[2:])     # 输出(2.23, 'runoob', 70.2)
print (tinytuple * 2) # 输出两次元组
print (tuple1 + tinytuple) # 拼接元组


'''
 集合(Set):无序、可变用于储存唯一的元素
 在集合中元素不会重复，并且可以进行交集、并集、差集等常见的集合操作。
 集合用{}表示，元素之间用逗号隔开
 也可使用set()函数创建集合
 创建空集合必须使用set()
'''
sites = {'Google', 'Taobao', 'Runoob', 'Facebook', 'Zhihu', 'Baidu'}
print(sites)   # 输出集合，重复的元素被自动去掉

if 'Taobao' in sites: # 判断元素'Taobao'是否在集合中
    print("Taobao在sites集合中")
else :
	print("Taobao不在集合中")

# set可以进行集合运算
a = set('abracadabra')
b = set('alacazam')

print(a)		 # 输出 {'a','b','c','d','r'} 集合会自动过滤重复的元素
print(b)		 # 输出 {'a','l','c','z','m'} 
print(a - b)     # a 和 b 的差集(除去与b相同的元素还剩下的)
print(a | b)     # a 和 b 的并集(合并)
print(a & b)     # a 和 b 的交集(共同拥有的)
print(a ^ b)     # a 和 b 中不同时存在的元素(相互没有的)


'''
字典(Dictionary)
字典是无序的对象集合。
字典当中的元素是通过键来存取的，而不是通过偏移存取。
字典是一种映射类型，字典用 { } 标识，它是一个无序的 键(key) : 值(value) 的集合。
键(key)必须使用不可变类型。
在同一个字典中，键(key)必须是唯一的。
'''
dict1 = {}		#创建空字典
dict1['one'] = "1 - 菜鸟教程"		# 键命名 写入值
dict1[2]     = "2 - 菜鸟工具"		

#创建字典 {'键'：'值'，...}
tinydict = {'name': 'runoob','code':1, 'site': 'www.runoob.com'} 

print (dict1['one'])       # 输出键为 'one' 的值
print (dict1[2])           # 输出键为 2 的值
print (tinydict)          # 输出完整的字典
print (tinydict.keys())   # 输出所有键
print (tinydict.values()) # 输出所有值


'''
bytes 类型表示的是不可变的二进制序列
创建 bytes 对象常见的方式是使用 b 前缀
也可以使用 bytes() 函数将其他类型的对象转换为 bytes 类型。
bytes() 函数的第一个参数是要转换的对象，第二个参数是编码方式
如果省略第二个参数，则默认使用 UTF-8 编码：
	x = bytes("hello", encoding="utf-8")
'''
x = b"hello"
y = x[1:3]         # 切片操作，得到 b"el"
z = x + b"world"   # 拼接操作，得到 b"helloworld"

# 注意，bytes 类型中的元素是整数值，因此在进行比较操作时需要使用相应的整数值。
x = b"hello"
if x[0] == ord("h"): # ord() 函数用于将字符转换为相应的整数值。
    print("The first element is 'h'")
else :
	print("The first element isn't 'h'")


Data1 = 10
Data2 = 21
# 取模，返回除法的余数(取余)
print('Data1 % Data2 = ',Data1%Data2)
print('Data2 % Data1 = ',Data2%Data1)

# 比较运算，符合条件则返回True,不符合则返回False
if (Data1 > Data2):
	print("Data1 大于 Data2")
else :
	print("Data1 小于 Data2")

# 取整除运算：往小的方向取整数
print("Data2 // Data1 = ",Data2//Data1)	# 相当于21/10=2.1，取整数所以输出2

# 赋值运算
# **= 幂赋值运算 a **= b 等效于 a = a**b(a的b次方)
# //= 取整除赋值运算 a //= b 等效于 a = a//b

# := 海象运算，在表达式中同时进行赋值和返回赋值的值

if (n:= 10) > 5:
	print(n)
else :
	print('小于')

# 成员运算
# in:如果在指定的序列中找到值则返回 True 否则返回 False
Temp = 1
list_ = [1,2,3,4,5]
if (Temp in list_):
	print("True")
else :
	print("Flase")
# not in:如果在指定的序列中没有找到值则返回 True 否则返回 False
if (Temp not in list_):
	print("Temp不在指定序列中")
else :
	print("Temp在指定序列中")

# 自身运算符
# is:判断两个标识符是不是引用自一个对象 x is y 类似与 id(x) == id(y) #id():用于获取对象的内存地址
Temp1 = 10
Temp2 = 10
if (Temp1 is Temp2): 
# if(id(Temp1) == id(Temp2))
	print('相同的标识符')
else :
	print('不同的表示符号')

# 数字类型转换
# complex(x) 将x转换到一个复数，实数部分为 x，虚数部分为 0。
# complex(x, y) 将 x 和 y 转换到一个复数，实数部分为 x，虚数部分为 y。x 和 y 是数字表达式。

'''
 数字函数：
 abs(x):返回数字的绝对值    abs(-10) 返回 10
 ceil(x):返回数字的上入整数 ceil(4.1) 返回 5
 已弃用cmp(x,y):如果x<y返回-1，如果x==y返回0，如果x>y返回1
 exp(x):返回e的x次幂,如math.exp(1) 返回2.718281828459045
 fabs(x):以浮点数形式返回数字的绝对值  fabs(-10) 返回 10.0
 floor(x):返回数字的下舍整数 floor(4.9) 返回 4
 log(x):如math.log(math.e)返回1.0,math.log(100,10)返回2.0
 log10(x):返回以10为基数的x的对数，如math.log10(100)返回 2.0
 max(x1,x2,...):返回给定参数的最大值，参数可以为序列
 min(x1,x2,...):返回给定参数的最小值，参数可以为序列
 modf(x):返回X的整数部分与小数部分，两部分的数值符号与x相同，整数部分以浮点型表示
 pow(x,y):返回x**y
 round(x,[,n]):返回浮点数 x 的四舍五入值，如给出 n 值，则代表舍入到小数点后的位数
 			  其实准确的说是保留值将保留到离上一位更近的一端。
 sqrt(x):返回数字x的平方根
'''

'''
 随机数函数
 choice(seq):从序列的元素中随机挑选一个函数
 		    例如比如random.choice(range(10))，从0到9中随机挑选一个整数。
 randrange([start,]stop[,step]):从指定范围内，按指定基数递增的集合中获取一个随机数，基数默认值为1
 random():随机生成下一个实数，它在[0,1)范围内 
 seed([x]):改变随机数生成器的种子seed,不了解的情况下不必特别去设定
 shuffle(list):将序列的所有元素随机排序
 uniform(x,y):随机生成下一个实数，范围在[x,y]之间
'''


'''
 三角函数
 acos(x):返回x的反余弦弧度值
 asin(x):返回x的反正弦弧度值
 atan(x):返回x的反正切弧度值
 atan2(y,x):返回给定的x及y坐标的反正切值
 cos(x):返回x的余弦值
 hypot(x,y);返回欧几里德范数sqrt(x*x + y*y)。
 sin(x):返回x弧度度的正弦值
 tan(x):返回x弧度度的正切值
 degrees(x):将弧度转化为角度 degrees(math.pi/2) ， 返回90.0
 radians(x):将角度转化为弧度
'''


# 数字常量
# pi:数字常量pi(圆周率，一般用 π 表示)
# e: 自然常数

'''
 转义符
 \'：单引号'
 \"：双引号"
 \a：响铃 print("\a")# 执行后电脑会有响声
 \b:退格符号 print("Hello \b World!") # Hello World!
 \000:空
 \n:换行
 \v:纵向制表
 \t:横向制表
 \r:回车, \r 后面的内容移到字符串开头，并逐一替换开头部分的字符，直至将 \r 后面的内容完全替换完成。
'''

print("Hello World!\b") # Hello World
print("Hello\000World!") # Hello World!
print("Hello\vWorld!") # Hello
					   #	  World!

print("Hello \t World!") # Hello     World!
print("Hello\rWorld!") # World!

# 添加列表项
list_ = [1,2,3]
list_.append(4) # 在列表末尾添加元素‘4’
print(list_) #[1,2,3,4]

# 删除列表元素
del list_[0]	# 删除低0位元素
print(list_) # [2,3,4]

# data in list 判断data是否存在于list中

for x in list_:	#相当与遍历列表并将里面的值赋值给x
	print(x,end="")  # 不换行打印x的值
	if x == list_[2]: # 判断是否遍历完成
		print('\n')  # 遍历完成自动添加空行
# 列表比较
Test_List1 = [1,2]
Test_List2 = [3,4]
Test_List3 = [1,2]
import operator	# 导入 operator 模块
# operator 模块的 eq 用法，比较两个数据是否一样，一样则返回True,否则返回False
print("operator.eq(a,b): ", operator.eq(Test_List1,Test_List2))
print("operator.eq(a,b): ", operator.eq(Test_List1,Test_List3))


# len(list) 获取列表元素个数
print("列表元素的个数：",len(list_))	# 3
# max(list)返回列表最大值 min(list)返回列表最小值
print("列表元素最大值：",max(list_))	# 4
print("列表元素最小值：",min(list_))	# 2
# list(seq) 将元组转为列表
aTuple = (123, 'Google', 'Runoob', 'Taobao')
print("元组元素：",aTuple)
list_1 = list(aTuple)
print ("列表元素 : ", list_1)


Temp_List_ = [1,'2',3]
#list.append(obj) 在list尾部添加obj
Temp_List_.append('123')
print(Temp_List_)	# [1,'2',3,'123']

# list.count(obj) 统计某个元素在列表中出现的次数
print('元素1出现次数:',Temp_List_.count(1))	# 元素1出现1次

# list.extend(seq)在列表末尾一次性追加另一个序列的多个值 
list2 = [3,'4',5]
Temp_List_.extend(list2)  # 扩展列表
print ("扩展后的列表：", Temp_List_)

# list.index(obj) 从列表中找出某个值第一个匹配项的索引位置
print("3 的第一个匹配索引值为：",Temp_List_.index(3))	# 2

# list.insert(index, obj) 将对象(obj)插入索引(index)位置列表
Temp_List_.insert(3,'4')
print('列表插入元素后为 : ', Temp_List_) # [1, '2', 3, '4', '123', 3, '4', 5]

# list.pop([index=-1]) 移除列表中的一个元素（默认最后一个元素），并且返回该元素的值
Temp_List_.pop(4)
print("移除列表第4位元素后：",Temp_List_) # [1, '2', 3, '4', 3, '4', 5]

# list.remove(obj)移除列表中某个值的第一个匹配项
Temp_List_.remove('4')
print("移除列表中3：",Temp_List_) # [1, '2', 3, 3, '4', 5]

# list.reverse() 反向列表中元素
Temp_List_.reverse()
print ("列表反转后: ", Temp_List_) # [5, '4', 3, 3, '2', 1]

# list.sort( key=None, reverse=False)对原列表进行排序 只能相同类型数据进行排序
aList = [3, 1, 0, 2]
aList.sort()
print( "升序排序 : ", aList) # [0, 1, 2, 3]
aList.sort(reverse=True)
print( "降序排序 : ", aList) # [3, 2, 1, 0]

# list.clear() 清空列表
aList.clear()
print('清空列表：',aList)	# []

# list.copy() 复制列表
aList = [1,2]
列表 = aList.copy()
print('复制列表：',列表)

# 元组 元组中只有一个元素时需在元素后添加逗号
tup1 = (10)
print(type(tup1)) # <class 'int'>不加逗号为整形
tup2 = (10,)
print(type(tup2)) # <class 'tuple'>加逗号类型为元组

# 元组中的元素值是不允许删除的，但我们可以使用del语句来删除整个元组
print("删除前的元组",tup2)
del tup2
# print("删除后的元组", end="")
# print(tup2) 元组被删除后，输出变量会有异常信息NameError

# 字典：可变容器模型，且可存储任意类型对象
# 字典的每个键值 key=>value 对用冒号 : 分割，每个对之间用逗号(,)分割，整个字典包括在花括号 {}
# 字典的键必须是唯一的，但值可以不是
dict1 = {'key1':'value1','key2':'value2','key3':'value1'}

# 空字典可以使用‘{}’来创建或dict()函数来创建字典

# 访问字典 需把相应的键放在‘[]’中
Temp_Dict = {'Name':'Python','Age':24,'Class':'IT'}
print('Temp_Dict[Name]:',Temp_Dict['Name'])

# 删除字典元素
del Temp_Dict['Class']     # 删除字典中 Class键值
# print(Temp_List_[Class]) # 已删除键值，会报错
Temp_Dict.clear()          # 清空字典
del Temp_Dict              # 删除字典

# 创建时字典同一个键出现两次，键值会被赋值为靠后的值
Temp_Dict = {'1':1,'2':2,'1':'IT'}
print("Temp_Dict['1']:",Temp_Dict['1']) # Temp_Dict['1']:IT

# 输出字典 str(dict)
# 会报错，TypeError: 'str' object is not callable
# print(str(Temp_Dict)) # 在IED上可以打印{'1':1,'2':2,'1':'IT'}


 # dict.clear() 删除字典
 # dict.copy()  返回复制的字典
 # dict.get(key, default=None) 返回指定键的值，如果键不在字典中返回 default 设置的默认值
tinydict = {'Name': 'Runoob', 'Age': 27}
print ("Age : ", tinydict.get('Age'))   # Age : 27
# 没有设置 Sex，也没有设置默认的值，输出 None
print ("Sex : ", tinydict.get('Sex'))	# Sex : None
# 没有设置 Salary，输出默认的值 0.0
print ('Salary: ', tinydict.get('Salary', 0.0)) # Salary: 0.0

# key in dict  判断key是否在dict中，是则返回true
# dict.items() 以列表返回一个视图对象
tinydict = {'Name': 'Runoob', 'Age': 27}
print ("Value : %s" %  tinydict.items()) 
# Value : dict_items([('Age', 7), ('Name', 'Runoob')])

# dict.keys()返回一个视图对象
dishes = {'eggs': 2, 'sausage': 1, 'bacon': 1, 'spam': 500}
keys = dishes.keys()
values = dishes.values()
n = 0
for val in values:	# 遍历值
	n += val     #值累加
print(n) # 值累加结果为 504

# keys 和 values 以相同顺序（插入顺序）进行迭代
# 使用 list()
list(keys) # 转换为列表['eggs', 'sausage', 'bacon', 'spam']
list(values) # 转换为列表[2, 1, 1, 500]
# 视图对象是动态的，受字典变化的影响，以下删除了字典的 key，视图对象转为列表后也跟着变化
del dishes['eggs']     # 删除键“eggs”
del dishes['sausage']  # 删除键“sausage”
print("字典(dishes)转换为列表：",list(keys)) # 字典(dishes)转换为列表:['bacon', 'spam']

# dict.setdefault(key, default=None)和get()类似, 但如果键不存在于字典中，将会添加键并将值设为default
# dict.update(dict2) 把字典dict2的键/值对更新到dict里
tinydict = {'Name': 'Runoob', 'Age': 7}
tinydict2 = {'Sex': 'female' }

tinydict.update(tinydict2)
print ("更新字典tinydict:", tinydict)
# 更新字典tinydict:{'Name': 'Runoob', 'Age': 7, 'Sex': 'female'}

# dict.values()返回一个视图对象
#dict.keys()、dict.values() 和 dict.items() 返回的都是视图对象，
#提供了字典实体的动态视图，这就意味着字典改变，视图也会跟着变化。
#视图对象不是列表，不支持索引，可以使用 list() 来转换为列表。
#我们不能对视图对象进行任何的修改，因为字典的视图对象都是只读的。

# dict.pop('键')删除字典key(键)所对应的值，返回被删除的值。
# popitem() 返回并删除字典中的最后一对键和值。

'''
 集合（set）是一个无序的不重复元素序列。
 集合中的元素不会重复，并且可以进行交集、并集、差集等常见的集合操作。
 可以使用大括号 { } 创建集合，元素之间用逗号 , 分隔， 或者也可以使用 set() 函数创建集合。
 创建一个空集合必须用 set() 
'''
set1 = {1, 2, 3}        # 直接使用大括号创建集合
set2 = set([4, 5, 6])   # 使用 set() 函数从列表创建集合

# 添加元素set.add( x )
set2.add(7)	# 集合set2添加元素7
print(set2)	#{4,5,6,7}

# set.updata(data) 此方式也可添加元素，且参数可以为列表，元组，字典等
set1.update({4,5})
set1.update([6,7])
set1.update({9:10,11:12})
print(set1) #{1, 2, 3, 4, 5, 6, 7, 9, 11}

#移除元素 set.remove() 若移除的元素不存在则会报错
set1.remove(11)
set1.remove(9)
# set1.remove(10) 移除元素不存在，报错
print(set1) #{1, 2, 3, 4, 5, 6, 7}

# 移除元素set.discard(x)如果元素不存在，不会发生错误
set1.discard(7)
set1.discard(7)
print(set1) # {1, 2, 3, 4, 5, 6}

# 清空集合 set.clear
set1.clear()	# 清空集合
print("清空集合后:",set1) #清空集合后: set()

'''
age = int(input("请输入狗狗的年龄: ")) 
if age <= 0:
    print("你是在逗我吧!")
elif age == 1:
    print("相当于 14 岁的人。")
elif age == 2:
    print("相当于 22 岁的人。")
elif age > 2:
    human = 22 + (age -2)*5
    print("对应人类年龄: ", human)
 
### 退出提示
input("点击 enter 键退出")
'''

Number = 3
User_Num = -1
print("猜数字游戏")
while User_Num != Number:
	User_Num+=2
	# User_Num = int(input("请输入你认为的数字:"))
	if(User_Num > Number):
		print("猜大了")
	elif User_Num < Number :
		print("猜小了")
	elif(User_Num == Number):
		print("猜对了")
	
print("I am alone，but I am not lonely") 

# match...case 的条件判断相当于switch(data)...case
data = 0;
while data < 3:
	data+=1
	match data:
		case 1:
			print('1')
		case 2:
			print('2')
		case _:	# 相当与C语言default
			print('>2')

# while 无线循环可以使用 CTRL+C来退出
# while 可以接 else 当while不成立时则执行else
# 如果while循环体中只有一条语句，则可以将该语句直接写在while后面

# for循环语句，可以遍历任何可迭代对象，例如字典，列表，元组或字符串
# 整数范围值可以配合 range() 函数使用，内置 range() 函数。它会生成数列
# 也可以使用 range() 指定区间的值range(5,9) ：5,6,7,8
# 也可以使 range() 以指定数字开始,结束，步长
# range(0,5,2) # 0 2 4
#  1 到 5 的所有数字：
for number in range(1, 6):
    print(number)

# for...else 语句用于在循环结束后执行一段代码
for x in range(6):
  print(x)
else:
  print("Finally finished!")

# for循环中可以嵌套break跳出循环且不会执行for语句后面的else
# for结合 range() 和 len() 函数以遍历一个序列的索引,如下所示:
a = ['Google', 'Baidu', 'Runoob', 'Taobao', 'QQ']
for i in range(len(a)):
	print(i, a[i])

# break跳出循环 
# continue跳出当前循环，但是不会跳出循环
# pass 不做任何事情，一般用做占位语句
for letter in 'book': 
   if letter == 'o':
      pass
      print ('执行 pass 块')
   print ('当前字母 :', letter)

# end可以用于将结果输出到同一行，或者在输出的末尾添加不同的字符
# 斐波纳契数列
# 两个元素的总和确定了下一个数
a, b = 0, 1
while b < 1000:	# 循环遍历
    print(b, end=',')	# 打印当前数值
    a, b = b, a+b # 斐波纳契数列算法
print()	# 相当于换行符

# 列表推导式
# 滤掉长度小于或等于3的字符串列表，并将剩下的转换成大写字母(list.upper())：
names = ['Bob','Tom','alice','Jerry','Wendy']
new_names = [name.upper()for name in names if len(name)>3]
print(new_names) # ['ALICE', 'JERRY', 'WENDY']

# 字典推导式
# 提供三个数，以内每个数的平方来创建字典
dic = {x: x**2 for x in (2, 4, 6)}
print('显示字典:',dic) # 显示字典:{2: 4, 4: 16, 6: 36}

# 集合推导式
# 给定三个数，以每个数的平方创建集合
setnew = {i**2 for i in (1,2,3)}
print(setnew) # {1, 4, 9}

# 元组推导式
Temp_a = (x for x in range(0,5)) # 创建从0-4(包括)的元组
print(Temp_a)  # <generator object <genexpr> at 0x000002373D004AC0>
print(tuple(Temp_a))#tuple()函数，直接将生成器对象转换成元组(0, 1, 2, 3, 4)

list1 = ['python', 'test1', 'test2']
# 结果值1 if 判断条件 else 结果2  for 变量名 in 原列表
list2 = [word.title() if word.startswith('p') else word.upper() for word in list1]
print(list2)


# 迭代器 
# 迭代器是一个可以记住遍历的位置的对象。
# 对象从集合的第一个元素开始访问，直到所有的元素被访问完结束。迭代器只能往前不会后退。
# 迭代器有两个基本的方法：创建迭代器iter() 和 访问迭代器的下一个元素next()。
# 字符串，列表或元组对象都可用于创建迭代器
list1=[1,2,3,4]
it = iter(list1)    # 创建迭代器对象
print (next(it))   # 输出迭代器的下一个元素“1”
print (next(it))   # 输出记忆位置的下一个元素“2”

print('剩下的元素：',end="")
for x in it:	# 遍历剩下的元素	
	print( x ,end="")	# 剩下的元素 3 4
print()

# 创建一个返回数字的迭代器，初始值为 1，逐步递增 1：
class MyNumbers:	    # 创建类
  def __iter__(self):	# 迭代器类
    self.a = 1          # 设置初始值为 1
    return self
 
  def __next__(self):	# 创建下一个元素
    x = self.a
    self.a += 1         # 下一个元素的值 = 当前元素 + 1
    return x

Temp_MyClass = MyNumbers() # 创建数字迭代器类，初始值为1，逐步增加1
Temp_MyIter = iter(Temp_MyClass) # 创建迭代对象
print(next(Temp_MyIter))    # 1
print(next(Temp_MyIter))    # 2
print(next(Temp_MyIter))    # 3
# ......
# print(next(Temp_MyIter))    # ......
print()

# StopIteration 异常用于标识迭代的完成，防止出现无限循环的情况
# 在__next__()方法中我们可以设置在完成指定循环次数后触发 StopIteration 异常来结束迭代。
class MyNumbers:
  def __iter__(self):
    self.a = 1
    return self
 
  def __next__(self):
    if self.a <= 5:	# 设置循环次数，大于此值则跳出
      x = self.a
      self.a += 1
      return x
    else:
      raise StopIteration	# 结束迭代
 
myclass = MyNumbers()	# 创建类
myiter = iter(myclass)  # 创建迭代对象
 
for x in myiter:
  print(x)

print()

# 生成器：生成器是一个返回迭代器的函数，只能用于迭代操作，更简单点理解生成器就是一个迭代器。
# yield关键字用于定义生成器函数
# 当在生成器函数中使用 yield 语句时，yield 后面的表达式作为当前迭代的值返回
def countdown(n): # countdown 函数是一个生成器函数
    while n > 0:
    	# 调用 yield 时，返回当前的数值，并在下一次调用时从上次返回的地方继续执行
        yield n
        n -= 1  # 算法条件

# 创建生成器对象 从 5 开始
generator = countdown(5)
for data in generator:
	print(data)
print('end')

'''
 定义函数
 代码块以 def 开头 + 函数名称 + ()
 任何传入参数和自变量必须放在括号中，括号之间可以用于定义参数。
 函数的第一行语句可以选择性的使用文档字符串，用于存放函数说明
 函数内容以冒号 : 起始，并且缩进。
 return [表达式] 结束函数，选择性地返回一个值给调用方，不带return 相当于返回 None。
'''
# 比较两个数，返回较大的数函数
def Max_Data(a,b):
	if a > b:
		return a
	else :
		return b
data_1 = 10
data_2 = 20
data_3 = Max_Data(data_1,data_2);
print("输出比较大的数：",data_3)



'''
# 不定长参数 基本语法
def functionname([formal_args,] *var_args_tuple ):
   """函数_文档字符串"""
   function_suite
   return [expression]
加了星号 * 的参数会以元组(tuple)的形式导入，存放所有未命名的变量参数。
'''
def printinfo( arg1, *vartuple ):
   print ("输出: ")
   print (arg1)		# 70
   print (vartuple) # (60,50)
 
# 调用printinfo 函数
printinfo( 70, 60, 50 ) 

print()
# 如果在函数调用时没有指定参数，它就是一个空元组。可以不向函数传递未命名的变量
def printinfo( arg1, *vartuple ):
   print (arg1)
   for var in vartuple:
      print (var)
   return
 
# 调用printinfo 函数
printinfo( 10 )			# 10
print()
printinfo( 70, 60, 50 ) # 70  60  50


'''
参数带两个星号 **基本语法如下：
def functionname([formal_args,] **var_args_dict ):
   "函数_文档字符串"
   function_suite
   return [expression]
'''
def printinfo( arg1, **vardict ):
   "打印任何传入的参数"
   print ("输出: ")
   print (arg1)
   print (vardict)
 
# 调用printinfo 函数
printinfo(1, a=2,b=3)  
# 1
# {'a':2,'b'':3}

# 声明函数时，参数中星号 * 可以单独出现
# 如果单独出现星号 *，则星号 * 后的参数必须用关键字传入
def Test_segdf(a,b,*,c):
    return a+b+c

# 匿名函数 使用 lambda 来创建匿名函数
# lambda 语法格式：
# lambda arguments: expression
# arguments 是参数列表，可以包含零个或多个参数，但必须在冒号(:)前指定。
# expression 是一个表达式，用于计算并返回函数的结果。
x = lambda a : a + 10
print(x(5)) # 15


# 匿名函数设置两个参数
sum_ = lambda arg1, arg2: arg1 + arg2

print ("相加后的值为 : ", sum_( 10, 20 ))
print ("相加后的值为 : ", sum_( 20, 20 ))

numbers = [1, 2, 3, 4, 5]
squared = list(map(lambda x: x**2, numbers))
print(squared)  # 输出: [1, 4, 9, 16, 25]


# 数据结构
'''
 列表
 list.append(x)	把一个元素添加到列表的结尾
 list.extend(L)	通过添加指定列表L的所有元素来扩充列表
 list.insert(i, x) 在指定位置插入一个元素。a.insert(0, x) 会插入到整个列表之前
 list.remove(x)	删除列表中值为 x 的第一个元素。如果没有这样的元素，就会返回一个错误
 ist.clear()	移除列表中的所有项，等于del a[:]。
 list.index(x)	返回列表中第一个值为 x 的元素的索引。如果没有匹配的元素就会返回一个错误。
 list.count(x)	返回 x 在列表中出现的次数。
 list.sort()	对列表中的元素进行排序。
 list.reverse()	倒排列表中的元素。
 list.copy()	返回列表的复制
'''
a = [1, 2, 3, 4, 123.4]
print("出现次数",a.count(1), a.count(2), a.count('x')) # 1 1 0
a.insert(2, -1)
print('指定位置插入',a) # [1, 2, -1, 3, 4, 123.4]
a.append(5)
print('末尾添加',a) # [1, 2, -1, 3, 4, 123.4, 5]
print('返回列表中第一个值为123.4的元素位置',a.index(123.4)) # 5
a.remove(-1)
print('删除值为 -1 的第一个元素',a) # [1, 2, 3, 4, 123.4, 5]
a.reverse()
print('倒序',a) # [5, 123.4, 4, 3, 2, 1]
a.sort()
print('顺序',a) # [1, 2, 3, 4, 5, 123.4]
# 类似 insert, remove 或 sort 等修改列表的方法没有返回值。
print()
# 将列表当做堆栈使用
# 堆栈作为特定的数据结构，最先进入的元素最后一个被释放（后进先出）
# append()将元素添加进堆栈中，pop()将一个元素从堆栈顶释放出来
stack_ = [1,2,3]
print(stack_)
stack_.append(4)	# 将元素添加进堆栈中
print(stack_)
stack_.pop()		# 将堆栈顶元素释放
print(stack_)

# 将列表当做列队使用
from collections import deque
queue = deque(["Eric", "John", "Michael"])
queue.append("Terry")  # 把‘Terry’添加到列表的结尾
queue.append("Graham") # 把‘Graham’添加到列表的结尾
queue.popleft() # 将第一个元素‘Eric’释放出来
queue.popleft() # 紧接着将当前将第一个元素‘John’释放出来
print(queue)    # deque(['Michael', 'Terry', 'Graham'])
print()

# 列表推导式
vec = [2, 3, 4] # 创建列表
print(vec)    # [2, 3, 4]
vec = [3*x for x in vec]
print(vec)    # [6, 9, 12]
vec = [(x,x**2) for x in vec]
print(vec)    # [(6, 36), (9, 81), (12, 144)]

freshfruit = ['banana', 'loganberry', 'passion fruit']
weapon = [weapon.strip() for weapon in freshfruit] # 顺序排序
print(weapon) # ['banana', 'loganberry', 'passion fruit']
print()

vec1 = [1, 3, 5]
vec2 = [2, 4, 6]
Temp_Data = [x*y for x in vec1 for y in vec2]
print(Temp_Data)  # [2, 4, 6, 6, 12, 18, 10, 20, 30]
Temp_Data = [x+y for x in vec1 for y in vec2]
print(Temp_Data)  # [3, 5, 7, 5, 7, 9, 7, 9, 11]
Temp_Data = [vec1[i]*vec2[i] for i in range(len(vec1))]
print(Temp_Data)  # [2, 12, 30]

# 列表推导式可以使用复杂表达式或嵌套函数
Temp_Data = [str(round(355/113, i)) for i in range(1, 6)]
print(Temp_Data)  # ['3.1', '3.14', '3.142', '3.1416', '3.14159']

# 将3X4的矩阵列表转换为4X3列表
matrix = [
	[1, 2, 3, 4],
	[5, 6, 7, 8],
	[9, 10, 11, 12],
]
# 分别将列表内的列表元素的第0,1,2,3放到一起组成新的矩阵列表
matrix = [[row[i] for row in matrix] for i in range(4)]
print(matrix) # [[1, 5, 9], [2, 6, 10], [3, 7, 11], [4, 8, 12]]
print()

# del() 根据索引来删除元素
a = [1,2,3,4,5]
del a[0]	# 删除 1
print(a)	# [2, 3, 4, 5]
del a[0:2]  # 删除2，3，
print(a)	# [4, 5]
print()


# 元组和序列
# 元组在输出时总是有括号的，在输入时可能有或没有括号，不过括号通常是必须的
# 集合是一个无序不重复元素的集，基本功能包括关系测试和消除重复元素。
# 集合使用{}创建，注意创建空集合必须使用set()函数
basket = {'apple', 'orange', 'apple', 'pear', 'orange'} # 创建集合
print(basket)    # 删除重复元素
# {'pear', 'orange', 'apple'}
if('orange' in basket):	# 检查元素是否存在集合中
	print(True)
else :
	print(False)
print()

# 字典
# 字典以关键字为索引，关键字可以是任意不可变类型通常用字符串或数值
# 在同一个字典之内，关键字必须是互不相同
# 使用{}创建空字典
tel = {1:'jack' , 2: 'sape'} # 创建字典tel
print(tel[1]) # jack

# dict()函数创建字典
tel = dict([(1, 'Test1'), (2, 'Test2'), (3, 'Test13')])
print(tel) # {1: 'Test1', 2: 'Test2', 3: 'Test13'}
tel = dict(test1=3, test2=2, test3=1)
print(tel) # {'test1': 3, 'test2': 2, 'test3': 1}
# 推导式创建字典
tel = {x: x**2 for x in (2, 4, 6)}
print(tel) # {2: 4, 4: 16, 6: 36}

# 遍历
# 在字典中遍历时，关键字和对应的值可以使用 items() 方法同时解读出来
tel = {'test1': 3, 'test2': 2, 'test3': 1} # 创建字典
for key, val in tel.items():
	print(key,':',val) # 打印字典中所有的键：值
print()

# 在序列中遍历时，索引位置和对应值可以使用 enumerate() 函数同时得到：
tel = ['test1', 'test2', 'test3']
for i, v in enumerate(tel):
	print('索引：',i,'值：',v) # 打印索引位置：值
print()

# 同时遍历两个或以上的序列(集合)，可以使用zip()组合
tel1 = {1,2,3}
tel2 = {4,5,6}
for T1,T2 in zip(tel1,tel2):
	print('tel1:{0}  tel2:{1}.'.format(T1,T2))
print()

for i in reversed(range(1, 10, 2)):
	print(i)	# 反向打印1-9没间隔1个元素打印一次
else:
	print()

# 使用 sorted() 函数返回一个从小到到排序的序列，并不修改原值：
tel1 = [5,1,8,2,4]
for x in sorted(set(tel1)):
	print(x)
else:
	print()


# import 语句语法：import module1[, module2[,... moduleN]
# 当解释器遇到 import 语句，如果模块在当前的搜索路径就会被导入
# 搜索路径是一个解释器会先进行搜索的所有目录的列表。
# 如想要导入模块 support，需要把命令放在脚本的顶端
# 一个模块只会被导入一次，无论执行了多少 import 
'''
import support  # 导入模块
support.print_func("Runoob") # 调用模块support内部函数
support.fib(10)  # 调用模块support内部函数fib()，输出0-10以内的所有斐波那契数
Test_Data = support.fib2(10) # 调用模块support内部函数fib2(),生成0-10以内的斐波那契数列
print(Test_Data) # 输出模块内部函数生成的斐波那契数列
print()
'''
# 模块中导入一个指定的部分函数到当前命名空间中 
# from modname import name1[, name2[, ... nameN]]
from  support import fib,fib2,print_func # 从模块support中，导入函数fib,fib2,print_func
print(fib(10))
print_func("Runoob") # 调用模块support内部函数

# 大多数情况下都不适用这种方法 from  模块名称 import * 
# 将模块内所有的函数及变量名都导入到当前模块中
# 但是由‘_’开头的函数及变量不在此列


# __name__属性
# 一个模块被另一个程序第一次引入时，其主程序将运行
# 如果想在模块被引入时，模块中的某一程序块不执行
# 可以用__name__属性来使该程序块仅在该模块自身运行时执行
'''
test_procedure 模块中函数
if __name__ == '__main__':
   print('程序自身在运行')
else:
   print('我来自另一模块')
'''
# 每个模块都有一个__name__属性，其为'__main__'时，表明该模块自身在运行，否则是被引入。
import test_procedure # 输出‘我来自另一模块’
print()

# 内置的函数 dir() 可以找到模块内定义的所有名称。以一个字符串列表的形式返回:
# import support
# print(dir(support))
# 如果没有给定参数，那么 dir() 函数会罗列出当前定义的所有名称
# print(dir())





