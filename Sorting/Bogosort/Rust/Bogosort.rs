extern crate rand;
use rand::Rng;
 
fn bogosort_by<T,F>(order: F, coll: &mut [T])
    where F: Fn(&T, &T) -> bool
{
    let mut rng = rand::thread_rng();
    while !is_sorted_by(&order, coll) {
        rng.shuffle(coll);
    }
}
 
#[inline]
fn is_sorted_by<T,F>(order: F, coll: &[T]) -> bool
    where F: Fn(&T,&T) -> bool,
{
    coll[..].iter().zip(&coll[1..]).all(|(x,y)| order(x,y))
}
 
 
fn main() {
    let mut testlist = [1,55,88,24,990876,312,67,0,854,13,4,7];
    bogosort_by(|x,y| x < y, &mut testlist);
    println!("{:?}", testlist);
    bogosort_by(|x,y| x > y, &mut testlist);
    println!("{:?}", testlist);
}
