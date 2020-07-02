class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        long int area1= (abs(C - A) * abs (D -B));  // Find the area of rectangle A.
        long int area2 = (abs(G -E) * abs(H -F));  // Find the area of rectangle B.
        
		
		// Check the condition if both the rectangles overlap or not.
        if ((B >= H) || (C <= E) || (A >= G) || (F >= D)){
			//If two rectangles do not overlap, return the sum of the individual areas.
            return area1 + area2;
        } else {
			// Else return area of rectangle A + area of rectangle B - overlap.
            return area1 + area2 - (min(C, G)-max(A,E)) * (min(H, D) - max(B, F)); 
        }     
    }
};
