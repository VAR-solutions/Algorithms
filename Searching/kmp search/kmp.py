def piFunc(pattern): # calculating longest prefix suffix array for pattern

    lenPattern = len(pattern)
    piArr = [0]*lenPattern    
    piArr[0] = 0
    j=0
    i=1
        
    while(i<lenPattern):
            
        if(pattern[i] == pattern[j]):

            j+=1
            piArr[i] = j
            i+=1
                
        else:
                
            if(j!=0):
                    
                j = piArr[j-1]
                    
            else:
                    
                piArr[i] = 0
                i+=1

    return piArr
    
    #print(piArr) # print the longest prefix suffix array
def kmp(text,pattern):

    lenText = len(text)
    lenPattern = len(pattern)

    count=0
    indexList=[]

    piArr = piFunc(pattern) # call function to create the pi array
    i=0
    j=0
    
    while(i<lenText):
        
        if(pattern[j] == text[i]):
            
            j+=1
            i+=1
            
            if(j == lenPattern):
                
                count+=1
                indexList.append(i-j) # add matching index to list
                
                j = piArr[j-1]
        else:
            
            if(j!=0):
                
                j = piArr[j-1]
                
            else:
                
                i+=1

    print("Matching indices : ",indexList)
        
text = str(input('Enter Text: '))

pattern = str(input('Enter Pattern: '))

kmp(text,pattern)

