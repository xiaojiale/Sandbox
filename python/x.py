#!/usr/bin/python
# coding: utf-8
def main():
    print('xxx')
if __name__ == "__main__":
    main();

class objA:
    pass

A = objA()
B = 'a','v'
C = 'a string'

basestring = (str, bytes)

print (isinstance(A, objA))
print (isinstance(B, tuple))
print (isinstance(C, basestring))
