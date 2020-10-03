fn main() {
    for i in 1..11 {
        if i as usize&1 == 0 {
            println!("{} is even", i);
        }
        else {
            println!("{} is odd", i);
        }
    }
}
