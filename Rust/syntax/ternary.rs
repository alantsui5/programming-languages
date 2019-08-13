fn main(){
    for i in 1..5{
        let even_odd = if i%2==0{"even"}else{"odd"};
        println!("{} is {}",i,even_odd);
    }
}

