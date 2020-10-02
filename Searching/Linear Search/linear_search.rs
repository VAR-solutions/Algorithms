fn linear_search(v : &Vec<i32>, value : i32) -> i32{
    for (i, &j ) in v.iter().enumerate() {
        if j == value{
            return i as i32;
        }
    }
    return i32::MAX;
}


fn main() {
    println!("Hello, world!");
    let v : Vec<i32> = vec![1,2,3,4,5,9,0];
    let index = linear_search(&v, 4);
    if index != i32::MAX{
        println!("index of element is -> {}", index);
    }
    else {
        println!("Element not found");
    }
}
