require 'securerandom'
i = 0
while i < 5 do
  randomNum = SecureRandom.random_number(100)  
  p randomNum
  i = i+1
  end
