let rec getHighest list = 
    match list with
    | [x] -> x
    | [x; y] when x > y -> x 
    | [x; y] -> y
    | hd1 :: hd2 :: tl when hd1 > hd2 -> getHighest (hd1 :: tl)
    | hd1 :: tl -> getHighest tl
    | _ -> failwith "unknown pattern"

let bubbleSort list = 
    let rec innerBubbleSort sorted = function
    | [] -> sorted
    | l -> 
        let x = getHighest l
        let (a, b) = List.partition (fun i -> i = x) l
        innerBubbleSort (a @ sorted) b
    innerBubbleSort [] list

[<EntryPoint>]
let main args = 
    let input = [10; 7; 1; 0; -1; 9; 33; 12; 6; 2; 3; 33; 34;]
    let output = bubbleSort input
    printfn "%s" (List.fold (fun acc x -> acc + " " + x.ToString()) "" output)
    0