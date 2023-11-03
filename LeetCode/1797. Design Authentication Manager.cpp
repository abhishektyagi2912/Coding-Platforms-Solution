class AuthenticationManager {
public:
unordered_map<string,int> mp;
int timestamp = 0;
    AuthenticationManager(int timeToLive) {
        timestamp = timeToLive;
    }
    
    void generate(string tokenId, int currentTime) {
        mp[tokenId] = currentTime + timestamp;
    }
    
    void renew(string tokenId, int currentTime) {
        if(mp.find(tokenId) == mp.end()) return;
        else{
            if(mp[tokenId] > currentTime) mp[tokenId] = currentTime + timestamp;
        }
    }
    
    int countUnexpiredTokens(int currentTime) {
        int count =0;
        for(auto x: mp){
            if(x.second > currentTime) count++;
        }
        return count;
    }
};

/**
 * Your AuthenticationManager object will be instantiated and called as such:
 * AuthenticationManager* obj = new AuthenticationManager(timeToLive);
 * obj->generate(tokenId,currentTime);
 * obj->renew(tokenId,currentTime);
 * int param_3 = obj->countUnexpiredTokens(currentTime);
 */
