use std::fs::File;
use std::io;
use std::io::prelude::*;

fn reverse(word:&str) -> String {
    return word.chars().rev().collect::<String>();
}

fn read_file() -> io::Result<()>{
    let mut filename = String::new();
    io::stdin().read_to_string(&mut filename)?;


    let file = File::open(&filename)?;

    let reader = io::BufReader::new(file);

    for line in reader.lines(){
        let line = line?;
        println!("{}", line);
        let line_str = &String::from(line);
        println!("({})",reverse(line_str));
    }

    Ok(())
}


fn main() {
    let word = "String";
    assert_eq!("gnirtS", reverse(word));
    println!("{}", word.chars().rev().collect::<String>());
    println!("Hello, world!");

    let result = read_file();
    
}
