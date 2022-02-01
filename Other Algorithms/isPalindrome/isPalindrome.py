def is_palindrome(x):
    s = str(x)
    if s == s[::-1]:
        return True
    return False


def main():
    x = int(input())
    print(str(x) + " is palindrome: " + str(is_palindrome(x)))


if __name__ == '__main__':
    main()
