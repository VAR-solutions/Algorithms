/// Counting sort

/// * `arr` - Collection of value to be sorted in place.

/// * `min` - Lower bound of the integer range.

/// * `max` - Upper bound of the integer range.

/// * `key` - Function extracting key witn the integer range from elements.

pub fn counting_sort<F, T>(arr: &mut [T], min: usize, max: usize, key: F)
where
    F: Fn(&T) -> usize,
    T: Clone,
{
    let mut prefix_sums = {
        // 1. Initialize the count array with default value 0.
        let len = max - min;
        let mut count_arr = Vec::with_capacity(len);
        count_arr.resize(len, 0);

        // 2. Scan elements to collect counts.
        for value in arr.iter() {
            count_arr[key(value)] += 1;
        }

        // 3. Calculate prefix sum.
        count_arr
            .into_iter()
            .scan(0, |state, x| {
                *state += x;
                Some(*state - x)
            })
            .collect::<Vec<usize>>()
    };

    // 4. Use prefix sum as index position of output element.
    for value in arr.to_vec().iter() {
        let index = key(value);
        arr[prefix_sums[index]] = value.clone();
        prefix_sums[index] += 1;
    }
}

#[cfg(test)]

mod base {
    use super::*;
    fn counting_sort_(arr: &mut [i32]) {
        counting_sort(arr, 1, 10, |int| *int as usize);
    }
    base_cases!(counting_sort_);
}

#[cfg(test)]

mod stability {
    use super::*;
    fn counting_sort_(arr: &mut [(i32, i32)]) {
        counting_sort(arr, 1, 10, |t| t.0 as usize);
    }
    stability_cases!(counting_sort_);
}
