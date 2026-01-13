class Solution {
public:
    double separateSquares(vector<vector<int>>& squares) {
        vector<pair<double, double>> events;
        double totalArea = 0.0;

        // Create events
        for (auto &sq : squares) {
            double y = sq[1];
            double l = sq[2];
            totalArea += l * l;
            events.push_back({y, l});        // square starts
            events.push_back({y + l, -l});   // square ends
        }

        sort(events.begin(), events.end());

        double halfArea = totalArea / 2.0;
        double currentWidth = 0.0;
        double accumulatedArea = 0.0;

        for (int i = 0; i < events.size() - 1; i++) {
            currentWidth += events[i].second;
            double deltaY = events[i + 1].first - events[i].first;

            double areaHere = currentWidth * deltaY;

            if (accumulatedArea + areaHere >= halfArea) {
                double remaining = halfArea - accumulatedArea;
                return events[i].first + remaining / currentWidth;
            }

            accumulatedArea += areaHere;
        }

        return 0.0; // should never reach
    }
};
