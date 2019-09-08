fn sqr(x: f64) -> f64 {
    x * x
}

//Recurtion
fn factorial(n: u64) -> u64 {
    if n == 0 {
        1
    } else {
        n * factorial(n-1)
    }
}

fn main() {
    let i = 10;
    let res1 = factorial(10);
    let res2 = sqr(36);
    println!("{} {}", res1,res2);
    
}