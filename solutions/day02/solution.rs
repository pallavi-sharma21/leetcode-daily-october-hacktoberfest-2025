struct Solution;

impl Solution {
    pub fn max_bottles_drunk(mut num_bottles: i32, mut num_exchange: i32) -> i32 {
        let mut empty_bottles = 0;
        let mut bottles_drunk = 0;
        while (!(num_bottles==0 && empty_bottles<num_exchange)){
            empty_bottles = empty_bottles + num_bottles;
            bottles_drunk = bottles_drunk + num_bottles;
            num_bottles = 0;
            if empty_bottles >= num_exchange{
                num_bottles = num_bottles + 1;
                empty_bottles = empty_bottles - num_exchange;
                num_exchange = num_exchange + 1;
            }
            
        }  
        bottles_drunk 
        
    }
}
