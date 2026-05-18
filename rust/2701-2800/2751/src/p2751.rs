struct Solution;

impl Solution {
    pub fn survived_robots_healths(
        positions: Vec<i32>,
        healths: Vec<i32>,
        directions: String,
    ) -> Vec<i32> {
        let n = positions.len();
        let dirs = directions.as_bytes();
        let mut mut_healths = healths;
        let mut sorted_position: Vec<usize> = (0..n).collect();
        sorted_position.sort_unstable_by_key(|&i| positions[i]);
        let mut robot_line: Vec<usize> = Vec::new();
        for &i in &sorted_position {
            if dirs[i] == b'R' {
                robot_line.push(i);
            } else {
                while let Some(&top) = robot_line.last() {
                    if mut_healths[top] > mut_healths[i] {
                        mut_healths[top] -= 1;
                        mut_healths[i] = 0;
                        break;
                    } else if mut_healths[top] == mut_healths[i] {
                        mut_healths[i] = 0;
                        mut_healths[top] = 0;
                        robot_line.pop();
                        break;
                    } else {
                        mut_healths[i] -= 1;
                        mut_healths[top] = 0;
                        robot_line.pop();
                    }
                }
            }
        }
        mut_healths
            .into_iter()
            .filter(|&health| health > 0)
            .collect()
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_example_1() {
        assert_eq!(
            Solution::survived_robots_healths(
                vec![5, 4, 3, 2, 1],
                vec![2, 17, 9, 15, 10],
                "RRRRR".to_string()
            ),
            vec![2, 17, 9, 15, 10],
            "Test case 1 Failed"
        );
    }

    #[test]
    fn test_example_2() {
        assert_eq!(
            Solution::survived_robots_healths(
                vec![3, 5, 2, 6],
                vec![10, 10, 15, 12],
                "RLRL".to_string()
            ),
            vec![14],
            "Test case 2 Failed"
        );
    }

    #[test]
    fn test_example_3() {
        assert_eq!(
            Solution::survived_robots_healths(
                vec![1, 2, 5, 6],
                vec![10, 10, 11, 11],
                "RLRL".to_string()
            ),
            vec![],
            "Test case 3 Failed"
        );
    }
}
