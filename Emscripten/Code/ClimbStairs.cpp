#include <iostream>
#include <time.h>

using namespace std;

// It takes n steps to reach the top of a stair.
// Each time you can either climb 1 or 2 steps.
// Calculate distinct ways you can take to climb to the top.
extern "C" {
    int climbStairs(int n) {
        if (n == 1) return 1;
        if (n == 2) return 2;
        
        return climbStairs(n - 1) + climbStairs(n - 2);
    }
}


int main() {
    cout << "Runtime of ClimbStairs Algorithm(Native)" << endl;
    for (int count = 0; count < 1000; count++) {
        clock_t start,end;
        start = clock();

        int n = 30;
        climbStairs(n);

        end = clock();
        cout << (double)(end-start)/CLOCKS_PER_SEC << endl;
    }

    return 0;
}