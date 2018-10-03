var x = -1 ,y = 1, sum = 0;
    
for i in 0..<10 {

sum = x+y;
x   = y;
y   = sum;

print(sum);
	
}
