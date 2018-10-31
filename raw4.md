 largest = None 
  smallest = None 
  while True: 
      try: 
          num = input("Enter a number: ") 
          if num == "done" : 
              break 
          elif smallest is None and largest is None: 
              smallest =int(num) 
              largest = int(num) 
          elif int(num)<smallest : 
              smallest=int(num) 
  
 
          elif largest<int(num): 
              largest=int(num) 
  
 
      except: 
          continue 
  print("Invalid input") 
  print("Maximum", largest) 
  print("Minimum", smallest) 
