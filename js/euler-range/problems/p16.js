"use strict";

var bigint

try
{
  bigint = require("bigint")
}
catch (err) {}

var range = require("euler-range")

module.exports = !bigint ? () => "(missing bigint)" : function p16() {
    // Find the sum of the digits of 2^1000.
    return range
        .fromString(
            bigint(2)
            .pow(1000)
            .toString())
        .map(parseInt)
        .sum()
}
