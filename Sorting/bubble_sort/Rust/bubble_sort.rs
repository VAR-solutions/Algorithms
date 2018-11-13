pub fn bubble_sort<T: PartialOrd>(array: &mut [T]) {
    for i in 0..array.len() {
    let mut swapped: bool = false;
        for j in 0..array.len() {
            if array[j] > array[i] {
                array.swap(j,i);
                swapped = true;
            }
        }

        if !swapped {
            break
        }
    }
}

pub fn main() {
    let mut array: [i32; 9] = [2,4,7,3,9,23,1,56,12];
    bubble_sort(&mut array);
    assert_eq!(array, [1,2,3,4,7,9,12,23,56]);
}
