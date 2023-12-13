impl Solution {
    pub fn to_hexspeak(num: String) -> String {
        const RADIX: u32 = 10;
        let mut num_dec: u64 = num.chars().fold(0, |acc, c| acc * (RADIX as u64) + c.to_digit(RADIX).unwrap() as u64);
        
        let mut num_hex = String::new();
        const HEX_RADIX: u64 = 16;
        while (num_dec != 0) {
            let rem: u8 = (num_dec % HEX_RADIX) as u8;
            num_dec /= HEX_RADIX;
            match rem {
                0 => num_hex.push('O'),
                1 => num_hex.push('I'),
                2..=9 => return String::from("ERROR"),
                10 => num_hex.push('A'),
                11 => num_hex.push('B'),
                12 => num_hex.push('C'),
                13 => num_hex.push('D'),
                14 => num_hex.push('E'),
                15 => num_hex.push('F'),
                _ => unreachable!(),
            }
        }

        num_hex.chars().rev().collect()
    }
}