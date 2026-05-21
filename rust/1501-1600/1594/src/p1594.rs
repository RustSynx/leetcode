use std::cmp;

struct Solution;

impl Solution {
    pub fn max_product_path(grid: Vec<Vec<i32>>) -> i32 {
        let m = grid.len();
        let n = grid[0].len();
        let mod_val = 1e9 as i64 + 7;
        let mut memo_max = [[i64::MIN; 16]; 16];
        let mut memo_min = [[i64::MAX; 16]; 16];
        memo_max[0][0] = grid[0][0] as i64;
        memo_min[0][0] = grid[0][0] as i64;
        for i in 0..m {
            for j in 0..n {
                if i == 0 && j == 0 { continue; }
                let curr_val = grid[i][j] as i64;
                let mut max_val = i64::MIN;
                let mut min_val = i64::MAX;
                if i > 0 {
                    max_val = cmp::max(max_val, cmp::max(memo_max[i-1][j] * curr_val, memo_min[i-1][j] * curr_val));
                    min_val = cmp::min(min_val, cmp::min(memo_max[i-1][j] * curr_val, memo_min[i-1][j] * curr_val));
                }
                if j > 0 {
                    max_val = cmp::max(max_val, cmp::max(memo_max[i][j - 1] * curr_val, memo_min[i][j - 1] * curr_val));
                    min_val = cmp::min(min_val, cmp::min(memo_max[i][j - 1] * curr_val, memo_min[i][j - 1] * curr_val));
                }
                memo_max[i][j] = max_val;
                memo_min[i][j] = min_val;
            }
        }
        let result = memo_max[m-1][n-1];
        if result < 0 { -1 } else { (result % mod_val) as i32 }
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_example_1() {
        assert_eq!(
            Solution::max_product_path(vec![vec![-1, -2, -3], vec![-2, -3, -3], vec![-3,-3,-2]]),
            -1,
            "Test case 1 Failed"
        );
    }

    #[test]
    fn test_example_2() {
        assert_eq!(
            Solution::max_product_path(vec![vec![1, -2, 1], vec![1, -2, 1], vec![3, -4, 1]]),
            8,
            "Test case 2 Failed"
        );
    }

    #[test]
    fn test_example_3() {
        assert_eq!(
            Solution::max_product_path(vec![vec![1, 3], vec![0, -4]]),
            0,
            "Test case 3 Failed"
        );
    }
}
