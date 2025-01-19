class RandomizedCollection {
public:
    vector<int> vec;
    unordered_map<int, set<int> > mp;
    RandomizedCollection() {
        
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        
        vec.push_back(val);
        mp[val].insert(vec.size()-1);

        if(mp[val].size()==1) return true; //if the val gets inserted first time then its set size 
        //is == 1
        return false;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        auto it = mp.find(val);

        if(it!=mp.end()){
            auto idx = *it->second.begin(); //dereferencing , it gives the first element of val set
            //here first element is index in fact every val set element are indexex 
            it->second.erase(it->second.begin());

            vec[idx]=vec.back();

            mp[vec.back()].insert(idx); //now the last element gets the new index

            mp[vec.back()].erase(vec.size()-1);

            vec.pop_back();

            if(it->second.size()==0) mp.erase(it);

            return true;
        }

        return false;

    }
    
    /** Get a random element from the set. */
    int getRandom() {
        int idx = rand() % vec.size();
        return vec[idx];
    }

};


/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */