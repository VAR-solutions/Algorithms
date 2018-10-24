def GradientDescent(inputValue, learningRate, precision, maximumIterations, gradientFunction):
    previousStepSize = 1 
    iterationCounter = 0 
    while previousStepSize > precision and iterationCounter < maximumIterations:
        previousX = inputValue #Storing current x value in previousX
        inputValue = inputValue - learningRate * gradientFunction(previousX) #Grad descent
        previousStepSize = abs(inputValue - previousX) #Change in x
        iterationCounter = iterationCounter+1 #iteration count
        print("Iteration",iterationCounter,"\nX value is",inputValue) #Print iterations
    return inputValue

inputValue = float(input("Initial Value: "))
learningRate = float(input("Learning Rate Alpha: "))
precision = float(input("Precision Needed: "))
maximumIterations = float(input("Maximum Iterations: "))
print(float(input("Trial Number: ")))
gradientFunction = lambda x: 2*(x+5) #Gradient of our function 

minimum = GradientDescent(inputValue, learningRate, precision, maximumIterations, gradientFunction)

print("The local minimum value is", minimum)