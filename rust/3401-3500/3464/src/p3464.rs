struct Solution;

impl Solution {
    pub fn max_distance(side: i32, points: Vec<Vec<i32>>, k: i32) -> i32 {
        let n = points.len();
        let mut dist_vec: Vec<i64> = Vec::with_capacity(n * 2);
        let side64 = side as i64;
        for i in 0..n {
            let x = points[i][0] as i64;
            let y = points[i][1] as i64;
            let dist = if x == 0 {
                y
            } else if y == side64 {
                (side64 + x)
            } else if x == side64 {
                side64 * 3 - y
            } else {
                side64 * 4 - x
            };
            dist_vec.push(dist);
        }
        dist_vec.sort_unstable();
        for i in 0..n {
            dist_vec.push(dist_vec[i] + (side64 * 4));
        }
        let mut low = 0;
        let mut high = side64 + 1;
        let mut result = 0;
        while low < high {
            let target = low + (high - low) / 2;
            let mut found = false;
            for i in 0..n {
                let mut dist = dist_vec[i];
                let mut count = 1;
                let mut curr_idx = i;
                for _ in 1..k {
                    let search_area = &dist_vec[(curr_idx + 1)..(n + i)];
                    let next_target = dist + target;
                    curr_idx = curr_idx + search_area.partition_point(|&x| x < next_target) + 1;
                    if curr_idx >= n + i {
                        break;
                    }
                    dist = dist_vec[curr_idx];
                    count += 1;
                }
                if count == k && (dist_vec[i] + side64 * 4 - dist) >= target {
                    found = true;
                    break;
                }
            }
            if found {
                result = target;
                low = target + 1;
            } else {
                high = target;
            }
        }
        result as i32
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_example_1() {
        assert_eq!(
            Solution::max_distance(2, vec![vec![0, 2], vec![2, 0], vec![2, 2], vec![0, 0]], 4),
            2,
            "Test case 1 Failed"
        );
    }

    #[test]
    fn test_example_2() {
        assert_eq!(
            Solution::max_distance(
                2,
                vec![vec![0, 0], vec![1, 2], vec![2, 0], vec![2, 2], vec![2, 1]],
                4
            ),
            1,
            "Test case 2 Failed"
        );
    }

    #[test]
    fn test_example_3() {
        assert_eq!(
            Solution::max_distance(
                2,
                vec![
                    vec![0, 0],
                    vec![0, 1],
                    vec![0, 2],
                    vec![1, 2],
                    vec![2, 0],
                    vec![2, 2],
                    vec![2, 1]
                ],
                5
            ),
            1,
            "Test case 3 Failed"
        );
    }
}
