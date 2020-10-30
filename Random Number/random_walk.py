
import numpy as np
import matplotlib.pyplot as plt

n = int(input('Enter number of random step u want to walk: '))
print("")

np.random.seed(123)
random_walk = [0]

for x in range(n) :
    # Set step: last element in random_walk
    step = random_walk[-1]
    # Roll the dice
    dice = np.random.randint(1,7)

    # Determine next step
    if dice <= 2:
        step = max(0,step - 1)
    elif dice <= 5:
        step = step + 1
    else:
        step = step + np.random.randint(1,7)

    # append next_step to random_walk
    random_walk.append(step)


print(random_walk)


plt.plot(random_walk)
plt.show()