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
    if (isNaN(useroutArray[i])) {
      process.exit(6)
    }

    const eps = 1e-4
    const diff = Math.abs(
      parseFloat(stdoutArray[i]) - parseFloat(useroutArray[i])
    )

    if (diff > eps) {
      process.exit(6)
    }
  }

  process.exit(4)
} catch (e) {
  process.exit(15)
}
