def gen_permutations(a, n):
 if len(a)==n:
     print(a)
     return
 else:
     for i in range(1,n+1):
         if i not in a:
             a.append(i)
             gen_permutations(a,n)
             a.pop()

gen_permutations(a=[], n=int(input('Enter size of array: ')))
