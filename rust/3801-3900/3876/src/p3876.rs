struct Solution;

impl Solution {
    pub fn uniform_array(nums1: Vec<i32>) -> bool {
        let min_val = nums1.iter().min().unwrap();
        if min_val % 2 != 0 {
            return true;
        }
        nums1.iter().all(|&n| n % 2 == 0)
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_example_1() {
        assert_eq!(
            Solution::uniform_array(vec![1, 4, 7]),
            true,
            "Test case 1 Failed"
        );
    }

    #[test]
    fn test_example_2() {
        assert_eq!(
            Solution::uniform_array(vec![2, 3]),
            false,
            "Test case 2 Failed"
        );
    }

    #[test]
    fn test_example_3() {
        assert_eq!(
            Solution::uniform_array(vec![4, 6]),
            true,
            "Test case 3 Failed"
        );
    }
}
