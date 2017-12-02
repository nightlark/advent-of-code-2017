fn main() {
    let captcha = "912219";
    let captcha: Vec<u8> = captcha.bytes().collect();
    let digits = captcha.iter().enumerate();
    let digits = digits.filter(|&(i, e)| captcha[(i+1)%captcha.len()] == *e);
    let digits = digits.map(|(_, e)| (e-b'0') as u32);
    let digits = digits.collect::<Vec<_>>();
    let sum: u32 = digits.iter().sum();
    println!("{}", sum);
}
