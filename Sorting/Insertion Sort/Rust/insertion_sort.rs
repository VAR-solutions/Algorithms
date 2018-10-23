pub fn insertion_sort<T: PartialOrd>(array: &mut [T]) {
    for i in 0..values.len() {
        for j in (0..i).rev() {
            if values[j] >= values[j + 1] {
                values.swap(j, j + 1);
            } else {
                break
            }
        }
    }
}

pub fn main() {
    let mut array: [i32; 9] = [2,3,7,5,3,8,12,54,21];
    selection_sort(&mut array);
    assert_eq!(array, [2,3,3,5,7,8,12,21,54]);
}
