## 500 random numbers with normal distribution
rnorm(500)

#Random number with normal distribution using mean and standard deviation
rnorm(500,mean=10,sd=1);

# 500 random numbers between 0 and 100
runif(500, min=0, max=100);

#Random sample of 3 numbers in the range of 0 to 100 with replacement
sample(1:100, 3, replace=TRUE)

#visualize numbers distribution in a histogram
hist(rnorm(500));

#density
plot(density(runif(500, min=0, max=100)));