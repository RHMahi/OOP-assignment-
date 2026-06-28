class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        multimap<int, double> cars;
        
        for (int i = 0; i < n; i++) {
            double time = (double)(target - position[i]) / speed[i];
            cars.insert({position[i], time});
        }
        
        int fleets = 0;
        double lastTime = -1.0;
        
        for (auto it = cars.rbegin(); it != cars.rend(); ++it) {
            double currentTime = it->second;
            if (currentTime > lastTime) {
                fleets++;
                lastTime = currentTime;
            }
        }
        
        return fleets;
    }
};