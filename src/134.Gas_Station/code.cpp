#include "code.h"
using namespace std;

namespace Gas_Station{
    int can_complete_circuit(vector<int>& gas, vector<int>& cost) {
        int survived;
        size_t begin {};
        bool begin_set {false};
        size_t end {};
        vector<int> gain(gas.size());
        for (size_t i = 0; i < gas.size(); i++) {
            gain[i] = gas[i] - cost[i];
            if (!begin_set && gain[i] >= 0) {
                begin = i;
                begin_set = true;
            }
        }
        if (!begin_set) {
            return -1;
        }
        end = begin;
        survived = gain[begin];
        while (begin < gas.size()) {
            while (end - begin < gas.size()) {
                if (survived >= 0) {
                    end++;
                    survived = survived + gain[end % gas.size()];
                }
                else {
                    if (end >= gas.size() - 1) {
                        return -1;
                    }
                    begin = end + 1;
                    end = begin;
                    survived = gain[begin];
                }
            }
            if (survived >= 0) {
                return begin;
            }
        }
        return -1;
    }

    int Solution::canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        return can_complete_circuit(gas, cost);
    }
}