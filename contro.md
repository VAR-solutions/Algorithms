print ("fibonacci series upto a range input by the user")
x=int(input("enter the lower bound"))
y=int(input("enter the upper bound:"))
a = 0
b = 1
if x==1 and y>1:
    print(a,"\n",b)
if x==1 and y==1:
    print(a)

while(1):
    c=a+b
    if(x<c and c<y):
       print(c)
    a=b
    b=c
    if(c>y):
        break
