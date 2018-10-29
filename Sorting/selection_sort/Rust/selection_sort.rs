pub fn selection_sort<T: PartialOrd>(array: &mut [T]) {
    let len = array.len();
    for i in 0..len {
        let min = (i..len).min_by_key(|x| array[*x])
                          .unwrap();
        array.swap(min, i);
    }
}

pub fn main() {
    let mut array: [i32; 9] = [2,3,7,5,3,8,12,54,21];
    selection_sort(&mut array);
    assert_eq!(array, [2,3,3,5,7,8,12,21,54]);
}
