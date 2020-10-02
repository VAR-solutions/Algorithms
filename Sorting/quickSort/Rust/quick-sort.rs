pub fn quick_sort<T: Ord>(arr: &mut [T]) {
    let len = arr.len();
    _quick_sort(arr, 0, (len - 1) as isize);
}

fn _quick_sort<T: Ord>(arr: &mut [T], low: isize, high: isize) {
    if low < high {
        let p = partition(arr, low, high);
        _quick_sort(arr, low, p - 1);
        _quick_sort(arr, p + 1, high);
    }
}

fn partition<T: Ord>(arr: &mut [T], low: isize, high: isize) -> isize {
    let pivot = high as usize;
    let mut store_index = low - 1;
    let mut last_index = high;

    loop {
        store_index += 1;
        while arr[store_index as usize] < arr[pivot] {
            store_index += 1;
        }
        last_index -= 1;
        while last_index >= 0 && arr[last_index as usize] > arr[pivot] {
            last_index -= 1;
        }
        if store_index >= last_index {
            break;
        } else {
            arr.swap(store_index as usize, last_index as usize);
        }
    }
    arr.swap(store_index as usize, pivot as usize);
    store_index
}
fn main() {
    println!("Sort numbers ascending");
    let mut numbers = [4, 65, 2, -31, 0, 99, 2, 83, 782, 1];
    println!("Before: {:?}", numbers);
    quick_sort(&mut numbers);
    println!("After:  {:?}\n", numbers);
}
