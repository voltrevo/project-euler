"use strict";

var bigint

try
{
  bigint = require("bigint")
}
catch (err) {}

var range = require("euler-range")

module.exports = !bigint ? () => "(missing bigint)" : function p20() {
    // Find the sum of the digits in 100!
    return range
        .fromString(
            range
                .interval(1, 101)
                .fold(bigint(1), function(x, y) {
                    return x.mul(y)
                }).toString())
        .map(parseInt)
        .sum()
}
