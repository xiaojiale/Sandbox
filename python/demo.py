#!/usr/bin/env python3

l = [3,2,1,5,2,6]
print(l)
s1 = set([1, 1, 2, 5, 2, 3, 1])
print(s1)
s2 = set([2, 4, 3])
print(s2)
s3 = set([1, 3, 8, -2, 99, 98, 77, 1, 5, 3, 77, 12])
print(s3)
print(s1 & s2)
print(s1 | s2)

dict = {
    'Micheal': 1,
    'Bob': 2,
    'Tracy': 3
}
print('Micheal:', dict['Micheal'])
print('dict.get(\'Thomas\', -1) =', dict.get('Thomas'))

n = 0
while n < 4:
    n += 1
    print(n)
print('---')

while n > 0:
    n -= 1
    if n % 2 == 0:
        continue
    print(n)
print('END')

L = ['Bart', 'Lisa', 'Adam']
for name in L:
    print('Hello,', name)

sum = 0
n = 99
while n > 0:
    sum += n
    n -= 2
print(sum)

for x in range(101):
    sum += x
print(sum)
num = [1, 2, 3, 4, 5]
for x in num:
    sum += x
print(sum)

names = ['Michael', 'Bob', 'Tracy']
for name in names:
    print(name)

classmates = ['michael', 'bob', 'tracy']
print('classmates =', classmates)
print('len(classmates)=', len(classmates))
print('classmates[0] =', classmates[0])
print('classmates[1] =', classmates[1])
print('classmates[-1] =', classmates[-1])
classmates.pop()
print('classmates =', classmates)


classmates = ('michael', 'bob', 'tracy')
print('classmates =', classmates)
print('len(classmates)=', len(classmates))
print('classmates[0] =', classmates[0])
print('classmates[1] =', classmates[1])
print('classmates[-1] =', classmates[-1])
print('classmates =', classmates)

L = [
    ['apple', 'google', 'microsoft'],
    ['java', 'python', 'ruby', 'php'],
    ['adam', 'bart', 'lisa']
]

print(L[0][0])
print(L[1][1])
print(L[2][2])

height = 1.75
weight = 80.5
bmi = 80.5/(1.75**2)
if bmi < 18.5:
    print('Too light')
elif bmi >= 18.5 and  bmi < 25:
    print('Normal')
elif bmi >= 25 and bmi < 32:
    print('Fat')
    print(bmi)
else:
    print('Too fat')


age = int(input('your age is:'))
if age >= 18:
    print('adult')
elif age >= 6:
    print('teenager')
else:
    print('kid')

s1 = 72
s2 = 85

r = (s2-s1)/72*100
n = '小明'
print('hi %s, your grade grow %.1f %%' % (n,r))

n = 123
f = 456.789
s1 = 'Hello, world'
s2 = 'Hello, \'Adam\''
s3 = r'Hello, "Bart"'
s4 = r'''Hello,
Lisa!'''
print(n,'\n',f,'\n',s1,'\n',s2,'\n',s3,'\n',s4)
name = input('Please input your name:')
print('Hello,', name, ', how are you')

print("Your name is:" + name)
l = len(name)
print("Length of your Chinese name in UTF-8 is:" + str(l))

temp = ascii(name)
l = len(temp)
print("Length of your Chinese name in ASCII is:" + str(l))
