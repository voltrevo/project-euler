'use strict'

var f = 1
var fLast = 1

var sum = 0

while (f < 4000000)
{
    var tmp = f
    f += fLast
    fLast = tmp

    if (f % 2 == 0)
    {
        sum += f
    }
}

console.log(sum)
