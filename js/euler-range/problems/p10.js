"use strict";

var range = require("euler-range")

module.exports = function p10() {
    // Find the sum of all primes below 2,000,000.
    return range
        .primes()
        .while(function(p) { return p < 2000000 })
        .sum()
}
