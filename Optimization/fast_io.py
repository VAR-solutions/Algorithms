import atexit, io, sys 
  
buffer = io.BytesIO() 
sys.stdout = buffer
  

@atexit.register 
def write(): 
    sys.__stdout__.write(buffer.getvalue()) 

def raw_inputt():
	var = sys.stdin.readline()
	return var

def printt(var):
	sys.stdout.write(str(var) + "\n")


ar = map(int, raw_inputt().split())
for num in ar:
	printt(num)
