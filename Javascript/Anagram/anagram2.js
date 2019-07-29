//NodeJS ES6
const readline = require('readline')
const fs = require('fs');

const reverse_string = (str)=>{
    return [...str].reverse().join("")
}

const Scanner = (quest)=> new Promise((resolve,reject)=>{
    const rl = readline.createInterface({
        input: process.stdin,
        output: process.stdout
      })
    rl.question(quest, (file_name) => {
        resolve(file_name)
        rl.close()
    })
})

const read_file = (path) => new Promise((resolve,reject) => {
  fs.open(path,'r',(err,fd) => {
    if (err) throw err
    else resolve(fd)
  })
})

const close_file = (file) => new Promise((resolve,reject) => {
  fs.close(file,(err) => {
    if (err) throw err;
    else reject(file)
  })
})
/*  
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
    const file_name = await Scanner('Enter name of a file you wish to see:\n');
    console.log(file_name)
}

main()