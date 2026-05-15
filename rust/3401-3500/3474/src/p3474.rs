struct Solution;

impl Solution {
    pub fn generate_string(str1: String, str2: String) -> String {
        let n = str1.len();
        let m = str2.len();
        let s1 = str1.as_bytes();
        let s2 = str2.as_bytes();

        let mut res = vec![0u8; n + m - 1];
        let mut fixed = vec![false; n + m - 1];

        for i in 0..n {
            if s1[i] == b'T' {
                for j in 0..m {
                    let idx = i + j;
                    if res[idx] != 0 && res[idx] != s2[j] {
                        return "".to_string();
                    }
                    res[idx] = s2[j];
                    fixed[idx] = true;
                }
            }
        }

        for i in 0..(n + m - 1) {
            if res[i] == 0 {
                res[i] = b'a';
            }
        }

        for i in 0..n {
            if s1[i] == b'F' {
                while &res[i..i + m] == s2 {
                    let mut changed = false;
                    for j in (0..m).rev() {
                        if !fixed[i + j] {
                            res[i + j] = if s2[j] == b'a' { b'b' } else { b'a' };
                            changed = true;
                            break;
                        }
                    }
                    if !changed { return "".to_string(); }
                }
            } else if s1[i] == b'T' {
                if &res[i..i + m] != s2 { return "".to_string(); }
            }
        }
        String::from_utf8(res).unwrap_or_else(|_| "".to_string())
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_example_1() {
        assert_eq!(
            Solution::generate_string("TFTF".to_string(), "ab".to_string()),
            "ababa",
            "Test case 1 Failed"
        );
    }

    #[test]
    fn test_example_2() {
        assert_eq!(
            Solution::generate_string("TFTF".to_string(), "abc".to_string()),
            "",
            "Test case 2 Failed"
        );
    }

    #[test]
    fn test_example_3() {
        assert_eq!(
            Solution::generate_string("F".to_string(), "d".to_string()),
            "a",
            "Test case 3 Failed"
        );
    }
}
