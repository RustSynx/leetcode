struct Solution;

impl Solution {
    pub fn first_stable_index(nums: Vec<i32>, k: i32) -> i32 {
        let mut current_min = i32::MAX;
        let mut right_min: Vec<i32> = nums
            .iter()
            .rev()
            .map(|&num| {
                current_min = current_min.min(num);
                current_min
            })
            .collect();
        right_min.reverse();
        let mut max_val = i32::MIN;
        for (i, (num, r_min)) in nums.into_iter().zip(right_min).enumerate() {
            max_val = max_val.max(num);
            if max_val - r_min <= k {
                return i as i32;
            }
        }
        -1
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_example_1() {
        assert_eq!(
            Solution::first_stable_index(vec![5, 0, 1, 4], 3),
            3,
            "Test case 1 Failed"
        );
    }

    #[test]
    fn test_example_2() {
        assert_eq!(
            Solution::first_stable_index(vec![3, 2, 1], 1),
            -1,
            "Test case 2 Failed"
        );
    }

    #[test]
    fn test_example_3() {
        assert_eq!(
            Solution::first_stable_index(vec![0], 0),
            0,
            "Test case 3 Failed"
        );
    }
}
