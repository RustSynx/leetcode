struct Solution;

impl Solution {
    pub fn max_walls(robots: Vec<i32>, distance: Vec<i32>, walls: Vec<i32>) -> i32 {
        let n = robots.len();
        let mut robot_vec: Vec<(i32, i32)> = robots.into_iter().zip(distance.into_iter()).collect();
        robot_vec.sort_unstable_by_key(|x| x.0);
        let mut sorted_walls = walls;
        sorted_walls.sort_unstable();
        let count_range = |a: i32, b: i32| -> i32 {
            if a > b {
                return 0;
            }
            let start = sorted_walls.partition_point(|&w| w < a);
            let end = sorted_walls.partition_point(|&w| w <= b);
            (end - start) as i32
        };
        let mut memo = vec![vec![0; 2]; n];
        let mut right_limit = if n > 1 { robot_vec[1].0 } else { i32::MAX };
        memo[0][0] = count_range(robot_vec[0].0 - robot_vec[0].1, robot_vec[0].0);
        memo[0][1] = count_range(
            robot_vec[0].0,
            (robot_vec[0].0 + robot_vec[0].1).min(right_limit),
        );
        for i in 1..n {
            right_limit = if i < n - 1 {
                robot_vec[i + 1].0
            } else {
                i32::MAX
            };
            let curr_pos = robot_vec[i].0;
            let curr_dist = robot_vec[i].1;
            let prev_left_limit = (curr_pos - curr_dist).max(robot_vec[i - 1].0 + 1);
            let prev_right_limit = (robot_vec[i - 1].0 + robot_vec[i - 1].1).min(curr_pos);
            let next_limit = (curr_pos + curr_dist).min(right_limit);

            memo[i][0] = (memo[i - 1][1]
                + count_range((curr_pos - curr_dist).max(prev_right_limit + 1), curr_pos))
            .max(memo[i - 1][0] + count_range(prev_left_limit, curr_pos));

            memo[i][1] = (memo[i - 1][1]
                + count_range(curr_pos.max(prev_right_limit + 1), next_limit))
            .max(memo[i - 1][0] + count_range(curr_pos, next_limit));
        }
        memo[n - 1][0].max(memo[n - 1][1])
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_example_1() {
        assert_eq!(
            Solution::max_walls(vec![4], vec![3], vec![1, 10]),
            1,
            "Test case 1 Failed"
        );
    }

    #[test]
    fn test_example_2() {
        assert_eq!(
            Solution::max_walls(vec![10, 2], vec![5, 1], vec![5, 2, 7]),
            3,
            "Test case 2 Failed"
        );
    }

    #[test]
    fn test_example_3() {
        assert_eq!(
            Solution::max_walls(vec![1, 2], vec![100, 1], vec![10]),
            0,
            "Test case 3 Failed"
        );
    }
}
