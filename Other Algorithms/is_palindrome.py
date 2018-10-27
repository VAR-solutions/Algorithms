"""Determine if a user input word is a palindrome """


def is_palindrome(word):
    """ Returns boolean dependent on if word is palindrome or not """

    word_length = len(word)
    half_word = int(word_length/2)

    # splits word
    first_half_to_compare = word[:half_word:]
    second_half_to_compare = word[:half_word:-1]

    # returns boolean
    return first_half_to_compare == second_half_to_compare


def ask_n_eval(word):
    """ Congradulates or condems if user input palindrome or not """

    converted = word.upper()

    verdict = is_palindrome(converted)

    if verdict == True:
        print (f"Well done, {converted} backwards is {converted}.")
    else:
        print (f"That's not a palindrome you bloody moron. {converted} backwards is {converted[::-1]}.")


print("When finished type \"terminate\" to exit the program")
user_input = input("Enter a palindrome (no spaces please): ")
while user_input != "terminate":
    ask_n_eval(user_input)
    user_input = input("Enter a palindrome (no spaces please): ")
