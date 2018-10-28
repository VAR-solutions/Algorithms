import sys
number=int(sys.stdin.readline())

if(number & 0x1):
    print(str(number),"is ODD")
else:
    print(str(number),"is EVEN")


