/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    vector<Node*> nodeRegister;

    void dfs(Node* actual,Node* clone){
        for(auto neighbour:actual->neighbors){
            if(not nodeRegister[neighbour->val]) { //jo neighbour register nhi hai usko 
            //create krna hoga
            //create the neighbour for the first time
            Node* newNode=new Node(neighbour->val); //yha neighbour and newNode ki value same
            //hai bs new Node create krke usko push_back kiya ja rha hai neighbour me
            nodeRegister[newNode->val]=newNode;
            clone->neighbors.push_back(newNode);
            dfs(neighbour,newNode); //neighbour pr jana and neighbour ka clone node newNode
            //hai mtlb copied node
                }
            else{ //else mtlb node already create ho chuka hai newNode create krne ki jarurat 
                  //nhi hai bs neighbour ko hi pushback krna hai 
                clone->neighbors.push_back(nodeRegister[neighbour->val]);//here not newNode neighbour is pushback means already marked hai node thats why neighbour ke index se 
//uske address ko pick krke neighbors me add kiya ja rha hai
                }
        }
    }
    
    Node* cloneGraph(Node* node) {
        if(node==NULL) return NULL;
        Node* clone=new Node(node->val);
        nodeRegister.resize(110,NULL); //this array contains ref to the created nodes
        nodeRegister[clone->val]=clone;
        dfs(node,clone);
        return clone;
    }
};