def main():
    zeros = 0
    power_of_five = 5
    x = int(input("Number: "))

    while power_of_five < x:
        zeros += x // power_of_five
        power_of_five *= 5
    print("Number of zeros: " + str(zeros))


if __name__ == '__main__':
    main()

