class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(begin(folder), end(folder));
        vector<string> result;

        result.push_back(folder[0]); //sorted hai islie folder[0] ka koi parent nahi hoga
        //so it can never be a sub-folder

        for(int i = 1; i < folder.size(); i++) {

            string currFolder = folder[i];
            string lastFolder = result.back();
            lastFolder += '/';

            if(currFolder.find(lastFolder) != 0)  result.push_back(currFolder);
        }
        return result;
    }
};

/* 
//Approach-1 (Using set and substring find)
//T.C : O(n*L^2)
//S.C : O(n) //You can consider the length of each character as well - O(n*L)
unordered_set<string> st(begin(folder), end(folder));
        vector<string> result;

        for(string& currFolder : folder) { O(n)
            bool isSubFolder = false;
            string tempFolder = currFolder;
            while(!currFolder.empty()) {  O(L)
                size_t position = currFolder.find_last_of('/'); O(L)

                currFolder = currFolder.substr(0, position); O(L)

                if(st.find(currFolder) != st.end()) {
                    //it means currFolder is a sub-folder
                    isSubFolder = true;
                    break;
                }
            }

            if(!isSubFolder) {
                result.push_back(tempFolder);
            }

        }

        return result;

*/