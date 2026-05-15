use std::collections::HashMap;

struct Solution;

impl Solution {
    pub fn can_partition_grid(grid: Vec<Vec<i32>>) -> bool {
        let m = grid.len();
        let n = grid[0].len();
        let mut total_sum: i64 = 0;
        let mut prefix_row: Vec<i64> = vec![0; m];
        let mut prefix_col: Vec<i64> = vec![0; n];
        let mut del_num_row: HashMap<i64, (i32, i32)> = HashMap::new();
        let mut del_num_col: HashMap<i64, (i32, i32)> = HashMap::new();
        for (i, row) in grid.iter().enumerate() {
            for (j, col) in row.iter().enumerate() {
                prefix_row[i] += i64::from(*col);
                prefix_col[j] += i64::from(*col);
                let col_idx: i32 = j.try_into().unwrap();
                let row_idx: i32 = i.try_into().unwrap();
                total_sum += i64::from(*col);
                del_num_row
                    .entry(i64::from(*col))
                    .and_modify(|v| *v = (std::cmp::min(v.0, row_idx), std::cmp::max(v.1, row_idx)))
                    .or_insert((row_idx, row_idx));
                del_num_col
                    .entry(i64::from(*col))
                    .and_modify(|v| *v = (std::cmp::min(v.0, col_idx), std::cmp::max(v.1, col_idx)))
                    .or_insert((col_idx, col_idx));
            }
        }
        let mut prefix_sum: i64 = 0;
        for i in 0..(n - 1) {
            prefix_sum += i64::from(prefix_col[i]);
            if total_sum == prefix_sum * 2 {
                return true;
            }
            let left_target = prefix_sum * 2 - total_sum;
            let right_target = total_sum - prefix_sum * 2;
            if left_target > 0 {
                let left_size = m * (i + 1);
                if left_size > 1 {
                    if m == 1 {
                        if left_target == i64::from(grid[0][0])
                            || left_target == i64::from(grid[0][i])
                        {
                            return true;
                        }
                    } else if i == 0 {
                        if left_target == i64::from(grid[0][0])
                            || left_target == i64::from(grid[m - 1][0])
                        {
                            return true;
                        }
                    } else {
                        if let Some(idx) = del_num_col.get(&left_target) {
                            if idx.0 <= i.try_into().unwrap() {
                                return true;
                            }
                        }
                    }
                }
            }

            if right_target > 0 {
                let right_size = m * (n - 1 - i);
                if right_size > 1 {
                    if m == 1 {
                        if right_target == i64::from(grid[0][i + 1])
                            || right_target == i64::from(grid[0][n - 1])
                        {
                            return true;
                        }
                    } else if i == n - 2 {
                        if right_target == i64::from(grid[0][n - 1])
                            || right_target == i64::from(grid[m - 1][n - 1])
                        {
                            return true;
                        }
                    } else {
                        if let Some(idx) = del_num_col.get(&right_target) {
                            if idx.1 > i.try_into().unwrap() {
                                return true;
                            }
                        }
                    }
                }
            }
        }
        prefix_sum = 0;
        for i in 0..(m - 1) {
            prefix_sum += i64::from(prefix_row[i]);
            if total_sum == prefix_sum * 2 {
                return true;
            }
            let left_target = prefix_sum * 2 - total_sum;
            let right_target = total_sum - prefix_sum * 2;
            if left_target > 0 {
                let left_size = n * (i + 1);
                if left_size > 1 {
                    if n == 1 {
                        if left_target == i64::from(grid[0][0])
                            || left_target == i64::from(grid[i][0])
                        {
                            return true;
                        }
                    } else if i == 0 {
                        if left_target == i64::from(grid[0][0])
                            || left_target == i64::from(grid[0][n - 1])
                        {
                            return true;
                        }
                    } else {
                        if let Some(idx) = del_num_row.get(&left_target) {
                            if idx.0 <= i.try_into().unwrap() {
                                return true;
                            }
                        }
                    }
                }
            }

            if right_target > 0 {
                let right_size = n * (m - 1 - i);
                if right_size > 1 {
                    if n == 1 {
                        if right_target == i64::from(grid[i + 1][0])
                            || right_target == i64::from(grid[m - 1][0])
                        {
                            return true;
                        }
                    } else if i == m - 2 {
                        if right_target == i64::from(grid[m - 1][0])
                            || right_target == i64::from(grid[m - 1][n - 1])
                        {
                            return true;
                        }
                    } else {
                        if let Some(idx) = del_num_row.get(&right_target) {
                            if idx.1 > i.try_into().unwrap() {
                                return true;
                            }
                        }
                    }
                }
            }
        }
        return false;
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_example_1() {
        assert_eq!(
            Solution::can_partition_grid(vec![vec![1, 4], vec![2, 3]]),
            true,
            "Test case 1 Failed"
        );
    }

    #[test]
    fn test_example_2() {
        assert_eq!(
            Solution::can_partition_grid(vec![vec![1, 2], vec![3, 4]]),
            true,
            "Test case 2 Failed"
        );
    }

    #[test]
    fn test_example_3() {
        assert_eq!(
            Solution::can_partition_grid(vec![vec![1, 2, 4], vec![2, 3, 5]]),
            false,
            "Test case 3 Failed"
        );
    }

    #[test]
    fn test_example_4() {
        assert_eq!(
            Solution::can_partition_grid(vec![vec![4, 1, 8], vec![3, 2, 6]]),
            false,
            "Test case 4 Failed"
        );
    }
}
