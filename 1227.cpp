class Solution {
public:
    double nthPersonGetsNthSeat(int n) {
        // looks like they are in-order coming in.. 
        // the first one has: 
        //      1) 1/n to select the first seat (his own)
        //      2) (n-1)/n to select other seat. 
        // the second one: 
        //      1/(n-1) the first one takes his seat, then: 
        //          1/(n-1) random select the first seat
        //          (n-2)/(n-1) to get other seat.. 
        // then.. 
        // (n-1)/n * 1/(n-1) * (n-2)/(n-1) 
        if(n == 1) return 1.0; 
        else return 0.5; 
    }
};

/* 
Maybe there is some even shorter shortcut to arrive at the same conclusion, but for now this is the shortest one I can think of : ) So bear with me...

Let f(n) denote the probability of the n-th person getting correct seat in n-person case, then:

f(1) = 1 (base case, trivial)
f(2) = 1/2 (also trivial)

In n-person case, the first person taking seat 1 results in everyone else taking their correct seats, and the first person taking seat number x > 1 results in persons number 2, ..., x - 1 taking their correct seats, and person number x would either take seat 1 or one of seat (x + 1), ..., n, so person x plays the same role as person 1 in the (n - x + 1)-person case.

So, translating all cases above into probabilities, one has

f(n) = P(first person takes seat 1) * 1 + [ sum(x = 2 to n-1) P(first person takes seat x) * f(n - x + 1) ] + P(first person takes seat n) * 0
= 1/n + [ sum(x = 2 to n-1) (1/n) * f(n - x + 1) ] + 0
= 1/n * sum(x = 1 to n-1) f(x)

and then it's just an easy exercise of proof by induction to show with the linear recurrence above, if f(1) = 1, f(2) = 1/2, then f(n) also has to be 1/2 for any n > 2.

*/
