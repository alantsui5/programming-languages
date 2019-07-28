//NodeJS ES6
const readline = require('readline')
const fs = require('fs');

const reverse_string = (str)=>{
    return [...str].reverse().join("")
}

const string_scanner = ()=>{
    const rl = readline.createInterface({
        input: process.stdin,
        output: process.stdout
      });
    rl.question('Enter name of a file you wish to see: ', (file_name) => {
        resolve(file_name)
        rl.close()
    });
}
/*
rl.question('Enter name of a file you wish to see: ', (file_name) => {
// TODO: Log the answer in a database
    
    fs.open(file_name, 'r', (err, fd) => {
        if (err) throw err;
        console.log(file_name);
        fs.close(fd, (err) => {
          if (err) throw err;
        });
      });
    console.log(`(${reverse_string(answer)})`)

    rl.close();
});
*/
const main = async () =>{
    const file_name = await string_scanner();
    console.log(file_name)
}