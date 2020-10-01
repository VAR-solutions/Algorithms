# Program to ecrypt ceaser cipher

text = input("Message > ").upper()
n = int(input("Displacement > "))
abc = "ABCDEFGHIJKLMNÑOPQRSTUVWXYZ"
cipher = ""

for l in text:
    if l in abc:
        pos_let = abc.index(l)
        new_pos = (pos_let + n) % len(abc)
        cipher+= abc[new_pos]
    else:
        cipher+= l

print(cipher)
