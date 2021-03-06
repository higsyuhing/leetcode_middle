class Solution {
public:
    double r, xc, yc;
    Solution(double rad, double x_c, double y_c) : r(rad), xc(x_c), yc(y_c) {}    
    vector<double> randPoint() {
        while (true) {
            auto x = 2.0 * rand() / RAND_MAX - 1, y = 2.0 * rand() / RAND_MAX - 1;
            if (x * x + y * y <= 1)
                return { xc + x * r, yc + y * r };
        }
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(radius, x_center, y_center);
 * vector<double> param_1 = obj->randPoint();
 */
