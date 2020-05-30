class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        // transform the string to all minute starting from 00:00
        // compare all distances and the last -> first one
        
        vector<int> minutes; 
        minutes.reserve(timePoints.size()); 
        
        for(int i = 0; i < timePoints.size(); i++){
            string timestr = timePoints[i]; 
            int hour, minute; 
            sscanf(timestr.c_str(), "%d:%d", &hour, &minute); 
            
            minutes.push_back(hour*60+minute); 
            
            /*
            if(timestr.size() == 5){
                // normal case
            }
            else{
                cout << "bad format" << endl; 
                return 0; 
                
                size_t found = timestr.find_first_of(":");
                if(found == string::npos){
                    return 0; // error
                }
            }
            */
        }
        sort(minutes.begin(), minutes.end()); 
        
        int interval = 13*60; // maximum will be 12 hours 
        for(int i = 0; i < (minutes.size()-1); i++){
            if(interval > (minutes[i+1] - minutes[i]))
                interval = minutes[i+1] - minutes[i]; 
        }
        int last = 24*60 - minutes[minutes.size()-1] + minutes[0]; 
        interval = (interval > last) ? last : interval; 
        
        return interval;
    }
};
