use std::io::{stdin, stdout, Write};

fn main() {
    let mut input = String::new();
    print!("Please input an integer: ");
    stdout().flush().expect("failed to flush stdout");
    stdin().read_line(&mut input).expect("failed to read stdin");
    let num = input.trim().parse::<i32>().expect("failed to parse input");

    input = String::new();
    print!("Please input another integer: ");
    stdout().flush().expect("failed to flush stdout");
    stdin().read_line(&mut input).expect("failed to read stdin");
    let exp = input.trim().parse::<u32>().expect("failed to parse input");

    println!("{} raised to the {} power is {}.", num, exp, i32::pow(num, exp));
}
