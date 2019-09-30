def toBinary a
  b = ""
  until a == 0
    b = (a % 2).to_s + b
    a = (a / 2).floor
  end
  return b
end
