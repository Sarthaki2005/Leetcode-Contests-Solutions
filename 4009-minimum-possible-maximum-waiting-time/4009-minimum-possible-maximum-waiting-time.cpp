// class Solution {
// public:
//     int n;
//     vector<int> demand;
//     map<long long, pair<int, int>> memo;

//     long long encode (int i, int fuel0, int fuel1, int busy0, int busy1) {
//         long long a = (i * 51 + fuel0);
//         long long b = (a * 51 + fuel1);
//         long long c = (b * 21 + busy0);
//         long long d = (c * 21 + busy1);
//         return d;
//     }

//     // 50 * 50 * 50 * 20 * 20 = 5 * 10^7
//     pair<int, int> solve (int i, int fuel0, int fuel1, int busy0, int busy1) {
//         if (i == n) {
//             // carsServed = 0, maxWaitTime = 0
//             return {0, 0};
//         }

//         int curr_demand = demand[i];
//         if (curr_demand > max(fuel0, fuel1)) {
//             // process terminates if required fuel is greater than
//             // the amount of fuel dispensers contain.
//             return {0, 0};
//         }

//         long long key = encode(i, fuel0, fuel1, busy0, busy1);
//         if (memo.count(key)) {
//             return memo[key];
//         }

//         int maxServedCars = 0, maxWaitTime = INT_MAX;

//         if (curr_demand <= fuel0) {
//             int currWaitTime = busy0;
//             int newBusy0 = curr_demand;
//             int newBusy1 = max(0, busy1 - busy0);

//             auto [nextServedCars, nextWaitTime] = solve(i + 1, fuel0 - curr_demand, fuel1, newBusy0, newBusy1);

//             nextServedCars += 1;
//             nextWaitTime = max(nextWaitTime, currWaitTime);

//             if (nextServedCars > maxServedCars) {
//                 maxServedCars = nextServedCars;
//                 maxWaitTime = nextWaitTime;
//             } else if (nextServedCars == maxServedCars && nextWaitTime < maxWaitTime) {
//                 maxWaitTime = nextWaitTime;
//             }
//         }   

//         if (curr_demand <= fuel1) {
//             int currWaitTime = busy1;
//             int newBusy1 = curr_demand;
//             int newBusy0 = max(0, busy0 - busy1);

//             auto [nextServedCars, nextWaitTime] = solve(i + 1, fuel0, fuel1 - curr_demand, newBusy0, newBusy1);

//             nextServedCars += 1;
//             nextWaitTime = max(nextWaitTime, currWaitTime);

//             if (nextServedCars > maxServedCars) {
//                 maxServedCars = nextServedCars;
//                 maxWaitTime = nextWaitTime;
//             } else if (nextServedCars == maxServedCars && nextWaitTime < maxWaitTime) {
//                 maxWaitTime = nextWaitTime;
//             }
//         }

//         return memo[key] = {maxServedCars, maxWaitTime};
//     }

//     int minMaxWaitingTime(vector<int>& demand, vector<int>& fuel) {
//         this -> demand = demand;
//         n = demand.size();

//         // solve(current_car_idx, fuel0_remaining, fuel1_remaining, busy0, busy1)
        
//         // busy0 => after this time dispenser0 will be free to use
//         // busy1 => after this time dispenser1 will be free to use

//         // Car 'i' becomes available exactly when Car 'i - 1' starts

//         auto [maxCars, maxWait] = solve(0, fuel[0], fuel[1], 0, 0);
//         if (maxCars == 0) {
//             return -1;
//         }

//         return maxWait;
//     }
// };

#include <vector>
#include <algorithm>
#include <map>
#include <tuple>

using namespace std;

class Solution {
public:
    int minMaxWaitingTime(vector<int>& demand, vector<int>& fuel) {
        int n = demand.size();
        
        // DP state map:
        // Key: tuple<f0, b0, b1> representing (remaining fuel in 0, busy time 0, busy time 1)
        // Value: pair<cars_served, min_max_wait>
        map<tuple<int, int, int>, pair<int, int>> dp;
        
        // Base state: Car 0 arrives at time 0 with initial fuel and 0 busy times
        dp[{fuel[0], 0, 0}] = {0, 0};
        
        int best_cars = 0;
        int min_peak_wait = 0;

        for (int i = 0; i < n; ++i) {
            int d = demand[i];
            map<tuple<int, int, int>, pair<int, int>> next_dp;
            
            for (const auto& [state, res] : dp) {
                auto [f0, b0, b1] = state;
                auto [cars_served, current_max_wait] = res;

                // Total fuel spent so far across both dispensers
                // Sum of all demands up to car i-1 minus current remaining f0 gives f1 spent
                int f0_spent = fuel[0] - f0;
                int total_spent = 0;
                for (int k = 0; k < i; ++k) total_spent += demand[k];
                int f1_spent = total_spent - f0_spent;
                int f1 = fuel[1] - f1_spent;

                // Track global best result encountered so far
                if (cars_served > best_cars) {
                    best_cars = cars_served;
                    min_peak_wait = current_max_wait;
                } else if (cars_served == best_cars) {
                    min_peak_wait = min(min_peak_wait, current_max_wait);
                }

                // --- Option 0: Assign car i to Dispenser 0 ---
                if (f0 >= d) {
                    int wait = b0;
                    int new_b0 = d;
                    int new_b1 = max(0, b1 - wait);
                    int new_f0 = f0 - d;
                    int new_max_wait = max(current_max_wait, wait);
                    
                    tuple<int, int, int> next_state = {new_f0, new_b0, new_b1};
                    pair<int, int> next_res = {cars_served + 1, new_max_wait};
                    
                    if (!next_dp.count(next_state)) {
                        next_dp[next_state] = next_res;
                    } else {
                        // Maximize cars served, then minimize max wait time
                        if (next_res.first > next_dp[next_state].first) {
                            next_dp[next_state] = next_res;
                        } else if (next_res.first == next_dp[next_state].first) {
                            next_dp[next_state].second = min(next_dp[next_state].second, next_res.second);
                        }
                    }
                }

                // --- Option 1: Assign car i to Dispenser 1 ---
                if (f1 >= d) {
                    int wait = b1;
                    int new_b0 = max(0, b0 - wait);
                    int new_b1 = d;
                    int new_f0 = f0;
                    int new_max_wait = max(current_max_wait, wait);
                    
                    tuple<int, int, int> next_state = {new_f0, new_b0, new_b1};
                    pair<int, int> next_res = {cars_served + 1, new_max_wait};
                    
                    if (!next_dp.count(next_state)) {
                        next_dp[next_state] = next_res;
                    } else {
                        if (next_res.first > next_dp[next_state].first) {
                            next_dp[next_state] = next_res;
                        } else if (next_res.first == next_dp[next_state].first) {
                            next_dp[next_state].second = min(next_dp[next_state].second, next_res.second);
                        }
                    }
                }
            }

            if (next_dp.empty()) break; // Cannot serve car i on any dispenser
            dp = std::move(next_dp);
        }

        // Final check for end of array states
        for (const auto& [state, res] : dp) {
            auto [cars_served, current_max_wait] = res;
            if (cars_served > best_cars) {
                best_cars = cars_served;
                min_peak_wait = current_max_wait;
            } else if (cars_served == best_cars) {
                min_peak_wait = min(min_peak_wait, current_max_wait);
            }
        }

        return (best_cars == 0) ? -1 : min_peak_wait;
    }
};