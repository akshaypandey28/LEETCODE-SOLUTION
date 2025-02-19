//code with mik
class RandomizedSet {
public:
    /** Initialize your data structure here. */
    vector<int> vec;
    unordered_map<int, int> mp;
    RandomizedSet() {
        
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(mp.find(val) != mp.end()) return false;
        
        vec.push_back(val);
        mp[val] = vec.size()-1;
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if(mp.find(val) == mp.end())  return false;
        
        int idx       = mp[val];
        vec[idx]      = vec.back();
        mp[vec.back()] = idx;
        vec.pop_back();
        mp.erase(val);
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        int idx = rand()%vec.size();
        return vec[idx];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */