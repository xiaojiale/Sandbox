#!/usr/bin/env python3
# 3.3.2
# 1、2、3、4四个数字组成多少互不相同且无重复数字的三位数，并分别列出
for i in range(4):
    i += 1
    for j in range(4):
      j += 1
      for k in range(4):
          k += 1
          if i != j and i != k and j != k:
              print(i*100+j*10+k)

# 3.4.2
# tuple






# 3.4.1
# list
list = ('A', 'B','C', 'D')








# 3.3.5
# 打印不是15的倍数
list = (range(50))
for x in list:
    x = x + 1
    if x % 15 == 0:
        continue
    print(x)

# 3.3.4
# 从100到1反向打印，直到打印的数字是17的倍数结束
n = 100
list = (range(101))
while list[n] % 17 != 0:
    print(list[n])
    n = n -1

# 3.3.3
# 用while计算100以内所有偶数之和
sum = 0
n = 0
while n < 101:
    if n % 2 == 0:
        sum += n
    n = n + 1
print(sum)

# 3.3.1
# 根据bmi指数判断肥胖
height = 1.75
weight = 80.5
bmi = 80.5/(1.75**2)
if bmi < 18.5:
    print('Too light')
elif bmi >= 18.5 and bmi < 25:
    print('Standard')
elif bmi >= 25 and bmi < 28:
    print('Overweight')
elif bmi >= 28 and bmi < 32:
    print('Fat')
else:
    print('Too fat')


# 3.2.1
# 格式化打印
name = input('Your name:')
subject = input('Your subject:')
salary = float(input('Your salary:'))

print('你好，我叫%s, 我在网上学习了%s, 我希望通过学习找到月薪%.2f的工作。' % (name,subject,salary))

# 3.1.2
# 判断a和b的大小关系
a = int(input('Please input integer a:'))
b = int(input('Please input integer b:'))
if a > b:
    print('Good')
elif a == b:
    print('Equal')
else:
    print('Bad')

# 3.1.1
# 计算平方和立方值
x = int(input('Please input integer:'))
print('x^2 =', x**2)
print('x^3 =', x**3)

# 2.3.1
# IO
x = input('Please input your name:')
print('Hello, %s, how are you' % x)
print('Hello,',x,',how are you')

