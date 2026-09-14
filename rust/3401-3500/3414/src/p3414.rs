struct Solution;

use std::cmp::Ordering;

#[derive(Clone, Copy, Eq, PartialEq, Default)]
struct State {
    weight: i64,
    len: usize,
    indices: [usize; 4],
}

impl State {
    fn add_interval(&self, id: usize, weight: i64) -> Self {
        let mut new_state = *self;
        new_state.weight += weight;
        new_state.indices[new_state.len] = id;
        new_state.len += 1;
        new_state.indices[..new_state.len].sort_unstable();
        new_state
    }
}

impl Ord for State {
    fn cmp(&self, other: &Self) -> Ordering {
        if self.weight != other.weight {
            self.weight.cmp(&other.weight)
        } else {
            for i in 0..std::cmp::min(self.len, other.len) {
                if self.indices[i] != other.indices[i] {
                    return other.indices[i].cmp(&self.indices[i]);
                }
            }
            other.len.cmp(&self.len)
        }
    }
}

impl PartialOrd for State {
    fn partial_cmp(&self, other: &Self) -> Option<Ordering> {
        Some(self.cmp(other))
    }
}

#[derive(Clone, Copy)]
struct Interval {
    start: i32,
    end: i32,
    weight: i64,
    id: usize,
}

impl Solution {
    pub fn maximum_weight(intervals: Vec<Vec<i32>>) -> Vec<i32> {
        let n = intervals.len();
        let mut n_intervals = Vec::with_capacity(n);

        for (i, v) in intervals.into_iter().enumerate() {
            n_intervals.push(Interval {
                start: v[0],
                end: v[1],
                weight: v[2] as i64,
                id: i,
            });
        }
        n_intervals.sort_unstable_by_key(|x| x.start);
        let mut dp = vec![[State::default(); 5]; n + 1];
        for i in (0..n).rev() {
            let next_idx = i + 1 + n_intervals[i + 1..]
                .partition_point(|x| x.start <= n_intervals[i].end);
            for k in 1..=4 {
                let skip = dp[i + 1][k];
                let take = dp[next_idx][k - 1].add_interval(n_intervals[i].id, n_intervals[i].weight);
                dp[i][k] = std::cmp::max(skip, take);
            }
        }
        let best_state = dp[0][4];
        best_state.indices[..best_state.len]
            .iter()
            .map(|&x| x as i32)
            .collect()
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_example_1() {
        assert_eq!(
            Solution::maximum_weight(vec![
                vec![1, 3, 2],
                vec![4, 5, 2],
                vec![1, 5, 5],
                vec![6, 9, 3],
                vec![6, 7, 1],
                vec![8, 9, 1]
            ]),
            vec![2, 3],
            "Test case 1 Failed"
        );
    }

    #[test]
    fn test_example_2() {
        assert_eq!(
            Solution::maximum_weight(vec![
                vec![5, 8, 1],
                vec![6, 7, 7],
                vec![4, 7, 3],
                vec![9, 10, 6],
                vec![7, 8, 2],
                vec![11, 14, 3],
                vec![3, 5, 5]
            ]),
            vec![1, 3, 5, 6],
            "Test case 2 Failed"
        );
    }
}
