class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
    
        vector<pair<int, double>> cars;

        const int n = position.size();

        for(int i = 0 ; i < n; ++i){
            double time = (double)(target - position[i]) / speed[i];
            cars.emplace_back(position[i], time);
        }

        sort(cars.rbegin(), cars.rend());
        int ans =0;
        double lastTime = -1.00;
        for(const auto &[_, time] : cars){
            
            if(time > lastTime){
                ans++;
                lastTime = time;
            }


        }
        return ans;


    }
};
