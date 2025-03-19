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

  let maxLoss = 0
  for (let i = 0; i < len; ++i) {
    if (maxLoss < 1e-9) {
      process.exit(4)
    }

    if (isNaN(useroutArray[i])) {
      process.exit(6)
    }

    const n = useroutArray[i].trim().split(" ").length
    const m = stdoutArray[i].trim().split(" ").length

    if (n !== m) {
      process.exit(6)
    }

    for (let j = 0; j < n; ++j) {
      const u = parseFloat(useroutArray[i].trim().split(" ")[j])
      const a = parseFloat(stdoutArray[i].trim().split(" ")[j])

      if (Math.abs(a) <= 1) {
        if (Math.abs(u - a) > maxLoss) {
          maxLoss = abs(u - a)
        }
      } else {
        if (abs(a) > 1 && abs(u - a) / abs(a) > maxLoss) {
          maxLoss = abs(u - a) / abs(a)
        }
      }
    }
  }

  process.exit(4)
} catch (e) {
  process.exit(15)
}
