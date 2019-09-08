var Nightmare = require('nightmare');
const nightmare = Nightmare();

nightmare.goto('http://cnn.com')
  .evaluate(() => {
    return document.title;
  })
  .end()
  .then((title) => {
    console.log(title);
  })
