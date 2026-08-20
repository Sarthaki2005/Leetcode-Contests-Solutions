Question D: Elevator 3
Problem

An elevator starts at a given floor. Each request contains:

[arrivalTime, floor]

A request can only be fulfilled at or after its arrival time.

The elevator can move one floor per second, and the goal is to determine the minimum time required to fulfill all requests.

The number of requests is at most 16, which makes a bitmask DP solution feasible.

Approach

We use bitmask dynamic programming.

Let: dp[mask][i] represent the minimum time needed to fulfill all requests represented by mask, with request i being the last request visited.

For every state, we try every request j that has not yet been fulfilled.

If the elevator is currently at floor[i] at time t, then traveling to floor[j] takes:

abs(floor[i] - floor[j])

seconds.

However, request j may not have arrived yet, so the earliest time it can be fulfilled is:

max( t + abs(floor[i] - floor[j]), arrival[j])

The transition is therefore:
newMask = mask | (1 << j)
dp[newMask][j] = min(dp[newMask][j], newTime)
