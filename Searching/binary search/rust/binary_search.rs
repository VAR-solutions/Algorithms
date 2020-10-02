fn binary_search(v : &Vec<i32>, value : i32) -> i32{
    let mut low = 0;
    let mut high = v.len()-1;

    while low <= high {

        let mid  = (low+high)/2;

        if value > v[mid]{
            low = mid+1;
        }
        else if value < v[mid] {
            high = mid-1;
        }else {
            return mid as i32;
        }
    }
    i32::MAX
}


fn main() {
    let mut v: Vec<i32> = vec![1, 2, 3, 4, 5, 9, 0];
    v.sort();
    let index = binary_search(&v, 9);
    if index != i32::MAX{
        println!("index of element is -> {}", index);
    }
    else {
        println!("Element not found");
    }
}
