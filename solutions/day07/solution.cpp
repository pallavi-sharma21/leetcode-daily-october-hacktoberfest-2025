class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        unordered_map<int, int> last;
        queue<int> q;
        vector<int> res;
        
        for (int i = 0; i < rains.size(); ++i) {
            int lake = rains[i];
            if (lake != 0) {
                if (last.count(lake)) {
                    bool found = false;
                    int sz = q.size();
                    queue<int> temp;
                    
                    while (sz--) {
                        int j = q.front(); q.pop();
                        if (!found && j > last[lake]) {
                            res[j] = lake;
                            found = true;
                        } else {
                            temp.push(j);
                        }
                    }
                    
                    if (!found) return {};
                    q = temp;
                }
                res.push_back(-1);
                last[lake] = i;
            } else {
                res.push_back(1);
                q.push(i);
            }
        }
        
        return res;
    }
};
