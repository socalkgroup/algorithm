# Cow Jog

The cows are out exercising their hooves again!  There are N cows jogging on an infinitely-long single-lane track (1 <= N <= 100,000). Each cow starts at a distinct position on the track, and some cows jog at different speeds.

With only one lane in the track, cows cannot pass each other.  When a faster cow catches up to another cow, she has to slow down to avoid running into the other cow, becoming part of the same running group.

Eventually, no more cows will run into each other.  Farmer John wonders how many groups will be left when this happens.  Please help him compute this number.

Position is a nonnegative integer and speed is a positive integer; both numbers are at most 1 billion.  All cows start at distinct positions, and these will be given in increasing order in the input.

```
SAMPLE INPUT:

0 1
1 2
2 3
3 2
6 1

SAMPLE OUTPUT:

2 (A single integer indicating how many groups remain.)

```

