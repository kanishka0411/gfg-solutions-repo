class Solution {
  public:
    // Function to find the maximum number of meetings that can
    // be performed in a meeting room.
    static bool comparator(const pair<int,int>&a,const pair<int,int>&b){
        return a.second<b.second;
    }
    int maxMeetings(vector<int>& start, vector<int>& end) {
        vector<pair<int,int>>meet;
        int n=start.size();
        for(int i=0;i<n;i++){
            meet.push_back({start[i],end[i]});
        }
        sort(meet.begin(),meet.end(),comparator);
        int count=1;
        int endTime=meet[0].second;
        for(int i=1;i<n;i++){
            if(meet[i].first>endTime){
                count++;
                endTime=meet[i].second;
            }
        }
        return count;
        
    }
};