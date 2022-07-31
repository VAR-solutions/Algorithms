open System

// based on http://rosettacode.org/wiki/Sorting_algorithms/Quicksort#F.23
let rec qsortBy (compareFn) = function
    head :: tail ->
        let less, greater = List.partition (compareFn head) tail
        List.concat [qsortBy compareFn less; [head]; qsortBy compareFn greater]
    | _ -> []

// default behaviour for quicksort
let qsort = qsortBy (>=)

// example record type we can use to sort
// because sorting ints isn't always the most fun
type Product =
    {
        Id: int
        Name: string
        Price: double
    }

// takes a list of products and sorts them by price
// DESCENDING
// WITHOUT modifying the original list
let sortProductsByPrice = qsortBy (fun p1 p2 -> p1.Price <= p2.Price)

[<EntryPoint>]
let main _ =
  let items = [ 46; -12; 58; 102; 11; -65 ]
  let products = [
    { Id = 101; Name = "Cereal"; Price = 2.99 };
    { Id = 209; Name = "Nintendo Switch"; Price = 299.99 };
    { Id = 100; Name = "Soap"; Price = 3.00 };
  ]
  printfn "items: %A" items
  printfn "sorted items: %A" <| qsort items
  
  printfn "products: %A" products
  printfn "sorted products: %A" <| sortProductsByPrice products
  printfn "is it really sorted? %A"
    <| (
        List.map (fun p -> p.Price) <| sortProductsByPrice products
        =
        [ 299.99; 3.00; 2.99 ]
       )
  0