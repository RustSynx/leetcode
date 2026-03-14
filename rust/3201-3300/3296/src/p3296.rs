struct Solution;

impl Solution {
    pub fn min_number_of_seconds(mountain_height: i32, worker_times: Vec<i32>) -> i64 {
        let h = mountain_height as i64;
        let max_worker_time = *worker_times.iter().max().unwrap() as i64;
        let max_time = max_worker_time * h * (h + 1) / 2;
        let mut left = 0;
        let mut right: i64 = max_time;
        let mut result: i64 = right;
        while left <= right {
            let mid = left + (right - left) / 2;
            if Solution::can_reduce(mid, h, &worker_times) {
                result = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return result;
    }

    pub fn can_reduce(limit_time: i64, target_height: i64, worker_times: &Vec<i32>) -> bool {
        let mut total_height = 0;
        for worker_time in worker_times {
            let mut left = 0;
            let mut right = target_height;
            let mut max_height = 0;
            while left <= right {
                let mid = left + (right - left) / 2;
                let time_needed = (*worker_time as i64) * mid * (mid + 1) / 2;
                if time_needed <= limit_time {
                    max_height = mid;
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
            total_height += max_height;
            if total_height >= target_height {
                return true;
            }
        }
        return total_height >= target_height;
    }
}

#[cfg(test)]
mod tests {
    use super::*; // 위에 있는 Solution 구조체를 가져옴

    #[test]
    fn test_example_1() {
        assert_eq!(
            Solution::min_number_of_seconds(4, vec![2, 1, 1]),
            3,
            "Test case 1 Failed"
        );
    }

    #[test]
    fn test_example_2() {
        assert_eq!(
            Solution::min_number_of_seconds(10, vec![3, 2, 2, 4]),
            12,
            "Test case 2 Failed"
        );
    }

    #[test]
    fn test_example_3() {
        assert_eq!(
            Solution::min_number_of_seconds(5, vec![1]),
            15,
            "Test case 3 Failed"
        );
    }
}
