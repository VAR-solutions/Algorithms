#Uses Euclidean algorithm to calculate GCD
#Takes two numbers
def gcd a, b
  if a % b == 0
    return b
  else
    gcd(b, a % b)
  end
end

#Uses formula to calculate LCM by using GCD
def lcm c, d
  return (c * d) / (gcd(c, d))
end
