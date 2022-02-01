def is_prime(x):
    if x < 2:
        return False
    if x > 2 and x % 2 == 0:
        return False
    for i in range(3, int(x ** 0.5), 2):
        if x % i == 0:
            return False
    return True


def main():
    x = int(input())
    print(str(x) + " is prime: " + str(is_prime(x)))


if __name__ == '__main__':
    main()
