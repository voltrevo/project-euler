'use strict'

function IsPrime(n)
{
    for (var i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            return false
        }
    }

    return true
}

function GetPrimeFactors(n)
{
    var factors = []

    for (var i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            if (IsPrime(i))
            {
                factors.push(i)
            }
            
            var ii = n / i
            if (IsPrime(ii))
            {
                factors.push(ii)
            }
        }
    }

    return factors.sort(function(a, b) { return a - b })
}

function GetLast(arr)
{
    return arr[arr.length - 1]
}

function LargestPrimeFactor(n)
{
    var i = 2
    while (i * i <= n)
    {
        while (n % i == 0)
        {
            n /= i
        }

        i++
    }

    return n
}

//console.log(GetPrimeFactors(13195))
//console.log(GetPrimeFactors(600851475143))

console.log(LargestPrimeFactor(13195))
console.log(LargestPrimeFactor(600851475143))
