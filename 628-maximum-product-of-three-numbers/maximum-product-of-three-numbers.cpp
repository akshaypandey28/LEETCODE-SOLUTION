//OPTIMAL T=O(n) S=O(1)
class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        // Initialize the largest and smallest values
        int m1 = INT_MIN, m2 = INT_MIN, m3 = INT_MIN; 
        int n1 = INT_MAX, n2 = INT_MAX;   
        //m1 is biggest , m2 second , and m3 third      
        //n1 is biggest negative and n2 is second biggest negative
        for (int x : nums) {
            // Update largest three numbers
            if (x > m1) {
                m3 = m2;
                m2 = m1;
                m1 = x;
            } 
            else if (x > m2) {
                m3 = m2;
                m2 = x;
            } 
            else if (x > m3) m3 = x;

            // Update smallest two numbers
            if (x < n1) {
                n2 = n1;
                n1 = x;
            } 
            else if (x < n2) n2 = x;
            
        }

        // Calculate both potential maximum products
        int product1 = m1 * m2 * m3; 
        int product2 = m1 * n1 * n2; 

        return max(product1, product2);
    }
};