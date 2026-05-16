struct Solution;

impl Solution {
    pub fn minimum_distance(word: String) -> i32 {
        let mut memo = vec![vec![vec![-1; 27]; 27]; 301];
        Self::find_distance(&word, 0, 26, 26, &mut memo)
    }
    pub fn find_distance(
        word: &String,
        curr_idx: usize,
        finger1_idx: usize,
        finger2_idx: usize,
        memo: &mut Vec<Vec<Vec<i32>>>,
    ) -> i32 {
        let letters = word.as_bytes();
        if curr_idx >= word.len() {
            return 0;
        }
        if memo[curr_idx][finger1_idx][finger2_idx] != -1 {
            return memo[curr_idx][finger1_idx][finger2_idx];
        }
        let curr_char_idx = (letters[curr_idx] - b'A') as usize;
        let mut finger1_distance = if finger1_idx == 26 {
            0
        } else {
            ((curr_char_idx / 6).abs_diff(finger1_idx / 6)
                + (curr_char_idx % 6).abs_diff(finger1_idx % 6)) as i32
        };
        let mut finger2_distance = if finger2_idx == 26 {
            0
        } else {
            ((curr_char_idx / 6).abs_diff(finger2_idx / 6)
                + (curr_char_idx % 6).abs_diff(finger2_idx % 6)) as i32
        };
        finger1_distance +=
            Self::find_distance(word, curr_idx + 1, curr_char_idx, finger2_idx, memo);
        finger2_distance +=
            Self::find_distance(word, curr_idx + 1, finger1_idx, curr_char_idx, memo);
        memo[curr_idx][finger1_idx][finger2_idx] = finger1_distance.min(finger2_distance);
        memo[curr_idx][finger1_idx][finger2_idx]
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_example_1() {
        assert_eq!(
            Solution::minimum_distance("CAKE".to_string()),
            3,
            "Test case 1 Failed"
        );
    }

    #[test]
    fn test_example_2() {
        assert_eq!(
            Solution::minimum_distance("HAPPY".to_string()),
            6,
            "Test case 2 Failed"
        );
    }
}
