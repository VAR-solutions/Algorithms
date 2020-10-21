'''
HangMan game is a word Guessing Game.In this game the computer will pick any random word and it will tell the user to guess
the first character of the word,if the character lies inside the word then it will append in the letters list and you will asked to enter another letter of the word,
if the letter didn't lies inside the word then the life variable will decrement.
'''
import random
words=["dog","monkey","cat","book","google","rocket","space","rain","kfc"]
letters=[]
word=words[random.randrange(len(words))]
print("Welcome to HangMan!")
life=5
while life<30:
    guess=input("Enter your first guess: ")
    if word.__contains__(guess):
        print("Wow You guessed this right!!!")
        letters.append(guess)
        if letters.__len__()==word.__len__():
            print("Congratulations!!!!")
            break
        else:
            lettersleft=word.__len__()-letters.__len__()
            print("You have "+ str(lettersleft)+" letters left ")
    else:
        life-=1
        if life==0:
            print("GameOver!!! The word was ---> "+ word)
        else:
            print("OOPS,you have "+ str(life) +" Lives left,TRY AGAIN")
