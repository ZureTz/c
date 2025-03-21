const fs = require("fs")
const argv = process.argv

try {
  let stdout = fs.readFileSync(argv[3]).toString().trim()
  let userout = fs.readFileSync(argv[4]).toString().trim()
  let stdoutArray = stdout.split("\n")
  let useroutArray = userout.split("\n")

  const len = stdoutArray.length
  if (len !== useroutArray.length) {
    process.exit(6)
  }

  for (let i = 0; i < len; ++i) {
    const useroutArrayInLineEach = useroutArray[i].trim().split(" ")
    const stdoutArrayInLineEach = stdoutArray[i].trim().split(" ")

    if (useroutArrayInLineEach.length !== stdoutArrayInLineEach.length) {
      process.exit(6)
    }

    for (let j = 0; j < stdoutArrayInLineEach.length; j++) {
      if (isNaN(useroutArrayInLineEach[j])) {
        process.exit(6)
      }

      const eps = 1e-2
      const diff = Math.abs(
        parseFloat(stdoutArrayInLineEach[j]) -
          parseFloat(useroutArrayInLineEach[j])
      )

      if (diff > eps) {
        process.exit(6)
      }
    }
  }

  process.exit(4)
} catch (e) {
  process.exit(15)
}
