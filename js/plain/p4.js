'use strict'

function ReverseString(s)
{
    var rev = ''

    for (var i = s.length - 1; i >= 0; i--)
    {
        rev += s[i]
    }

    return rev
}

function IsStringPalindrome(s)
{
    var left = 0
    var right = s.length - 1

    while (left < right)
    {
        if (s[left] != s[right])
        {
            return false
        }

        left++
        right--
    }

    return true
}

function IsPalindrome(n)
{
    return IsStringPalindrome(n + '')
}

var largest = 0

for (var i = 100; i <= 999; i++)
{
    for (var j = i; j <= 999; j++)
    {
        var ij = i * j
        if (IsPalindrome(ij) && ij > largest)
        {
            largest = ij
        }
    }
}

console.log(largest)
