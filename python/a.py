#!/usr/bin/env python3
import math

n1 = 255
n2 = 1000
print(hex(n1),hex(n2))

def my_abs(x):
    if not isinstance(x, (int, float)):
        raise TypeError('bad operand type')
    if x >= 0:
        return x
    else:
        return -x

print(my_abs(10), my_abs(-10))

def move(x, y, step, angle):
    nx = x + step * math.cos(angle)
    ny = y + step * math.sin(angle)
    return nx, ny

def quadratic(a,b,c):
    if not (isinstance(a, (int,float)) & isinstance(b, (int,float)) & isinstance(c, (int,float))):
        raise TypeError('bad operand type')
    delta = b*b-4*a*c
    if delta < 0:
        print('ERROR:delta lt 0!')
    elif delta == 0:
        x = (-b)/(2*a)
        print('x =',x)
    else:
        x1 = (-b+math.sqrt(delta))/(2*a)
        x2 = (-b-math.sqrt(delta))/(2*a)
        print('x1 =',x1,';','x2 =',x2)

def power(x, n=2):
    s = 1
    while n > 0:
        s = s * x
        n = n - 1
    return s

def enroll(name, gender, age=6, city='Beijing'):
    print('name:', name)
    print('gender:', gender) 
    print('age:', age)
    print('city:', city)

def add_end(L=None):
    if L is None:
        L = []
    L.append('End')
    return L

def calc(*numbers):
    sum = 0
    for n in numbers:
        sum += n*n
    return sum

def person(name, age, **kw):
    if 'city' in kw:
        pass
    if 'job' in kw:
        pass
    print('Name:', name, 'Age:', age, 'Other:', kw)

def person1(name, age, *args, city, job):
    print(name, age, args, city, job)

def f1(a, b, c=0, *args, **kw):
    print('a=', a, 'b=', b, 'c=', c, 'args=', args, 'kw=', kw)

def f2(a, b, c=0, *, d, **kw):
    print('a=', a, 'b=', b, 'c=', c, 'd=', d, 'kw=', kw)

def product(*numbers):
    product = 1
    if numbers == ():
        raise TypeError('Empty input!')
    else:
        for i in numbers:
            if not isinstance(i, (int,float)):
                print('Type Error!')  
#            raise TypeError('Type error!')
            product *= i
        return product 

print('product(5) =', product(5))
print('product(5, 6) =', product(5, 6))
print('product(5, 6, 7) =', product(5, 6, 7))
print('product(5, 6, 7, 9) =', product(5, 6, 7, 9))
if product(5) != 5:
    print('测试失败!')
elif product(5, 6) != 30:
    print('测试失败!')
elif product(5, 6, 7) != 210:
    print('测试失败!')
elif product(5, 6, 7, 9) != 1890:
    print('测试失败!')
else:
    try:
        product()
#        product(5, 6, 7, 9, 'a') & product()
        print('测试失败!')
    except TypeError:
        print('测试成功!')
