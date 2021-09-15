// const express = require('express')
// const app = express()
// const port = 3000

// app.get('/', (req, res) => res.send('Hi There!'))
// app.listen(port, () => console.log(`TRY_1 app listening on port ${port}!`))

// process.on('SIGTERM', () => {
//     server.close(() => {
//         console.log('process terminated');
//     })
// })

console.log('%o', Number)

const function2 = () => console.trace()
const function1 = () => function2()
function1()

const doSomething = () => console.log('test')
const measureDoingSomething = () => {
  console.time('doSomething()')
  //do something, and measure the time it takes
  doSomething()
  console.timeEnd('doSomething()')
}
measureDoingSomething()



console.log('\x1b[33m%s\x1b[0m', 'hi!')

const chalk = require('chalk')
console.log(chalk.bgBlue.whiteBright('HIII'))



const ProgressBar = require('progress')

const bar = new ProgressBar(':bar', { total: 10 })
const timer = setInterval(() => {
  bar.tick()
  if (bar.complete) {
    clearInterval(timer)
  }
}, 100)
