class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        queue<int> qu;
        for(int i=0; i<students.size(); i++){
            qu.push(students[i]);
        }
        int i=0; //traversing the sandwiches array
        int count=0; //for checking the repetition pushes in queue
        while(qu.empty()!=1 and count!=qu.size()){
            if(qu.front()==sandwiches[i]){
                count=0;
                qu.pop();
                i++;
            }
            else{
                count++;
                qu.push(qu.front());
                qu.pop();
            }
        }
        return qu.size();
    }
};