class Solution {
public:
    bool isReflected(vector<pair<int, int>>& points) {
        if (points.empty()) return true;
        set<pair<int, int>> pts;
        double y = 0;
        for (auto a : points) {
            pts.insert(a);
            y += a.first;
        }
        y /= points.size();
        for (auto a : pts) {
            if (!pts.count({y * 2 - a.first, a.second})) {
                return false;
            }
        }
        return true;
    }
};
