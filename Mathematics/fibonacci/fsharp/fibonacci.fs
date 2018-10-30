let fib n =
  let rec loop acc1 acc2 = function
    | n when n = 0I -> acc1
    | n -> loop acc2 (acc1 + acc2) (n - 1I)

  loop 0I 1I n

