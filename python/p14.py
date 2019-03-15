#!/usr/bin/python

lrecord = [0,0]

for x in range(1,1000000):
    n = x
    length = 0
    while n != 1:
        if n%2 == 0:
            n /= 2
        else:
            n = 3*n + 1
        length += 1
    if length > lrecord[1]:
        lrecord[0] = x
        lrecord[1] = length
print "The longest chain started at",lrecord[0],"and went for",lrecord[1],"iterations."
