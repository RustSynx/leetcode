struct Solution;

impl Solution {
    pub fn count_commas(n: i64) -> i64 {
        (n - 999).max(0)
            .saturating_add((n - 999999).max(0))
            .saturating_add((n - 999999999).max(0))
            .saturating_add((n - 999999999999).max(0))
            .saturating_add((n - 999999999999999).max(0))
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_example_1() {
        assert_eq!(Solution::count_commas(1002), 3, "Test case 1 Failed");
    }

    #[test]
    fn test_example_2() {
        assert_eq!(Solution::count_commas(998), 0, "Test case 2 Failed");
    }
}
