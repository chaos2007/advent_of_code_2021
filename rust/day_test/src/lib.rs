pub fn add_two(a: i32, b: i32) -> i32 {
    a + b
}

#[cfg(test)]
mod tests {
    #[test]
    fn it_works() {
        assert_eq!(super::add_two(2, 2), 4);
    }
}
