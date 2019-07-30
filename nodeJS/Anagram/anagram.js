//ES6 nodeJS
const readline = require('readline')

var reverse_string = (str)=>{
  return [...str].reverse().join("")
}

const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
  });
  
rl.question('Enter a string of text:  ', (answer) => {
// TODO: Log the answer in a database
    console.log(`${answer}`);
    console.log(`(${reverse_string(answer)})`)

    rl.close();
});
