fn main() {
    let captcha = "12131415";
    
    // Turn the string into an array of bytes, and add indices
    let captcha: Vec<u8> = captcha.bytes().collect();
    let digits = captcha.iter().enumerate();
    
    // Keep digit if the digit halfway around the (circular) array matches
    let digits = digits.filter(|&(i, e)| captcha[(i+captcha.len()/2)%captcha.len()] == *e);
    
    // Convert from ascii digit to value of the digit (u32 to avoid overflow final sum)
    let digits = digits.map(|(_, e)| (e-b'0') as u32);
    
    // Get the result
    let digits = digits.collect::<Vec<_>>();
    let sum: u32 = digits.iter().sum();
    println!("{}", sum);
}
