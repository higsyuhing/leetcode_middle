class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int s = 0, e = arr.size();
        while(s<e){
            int mid = s+(e-s)/2;
            if(arr[mid]<x) s = mid+1;
            else e = mid;
        }
        int i =max(e-k,0), j = min(e+k-1,(int)arr.size()-1);
        vector<int> ret(k);
        while(j-i+1>k){
            if(abs(arr[i]-x)>abs(arr[j]-x)) i++;
            else j--;
        }
        std::copy(arr.begin()+i,arr.begin()+j+1,ret.begin());
        return ret;
    }
};

/*
// but to be honest, I like the one java answer.. smart. 

public class Solution {
	public List<Integer> findClosestElements(List<Integer> arr, int k, int x) {
        // priority queue?? with size k? 
        // sorted array!! then pq is too costly. 
        // 2 pointers.. can give O(n) result, but this one is better.. 
        // this one is better than solution.. 
        
        // Use binary search to find k closest elements
        List<Integer> result = new ArrayList();
        int low = 0;
        int high = arr.size()-k;
        int mid = 0;
        
        // We would adjust the low and high boundaries based on the differences of values wrt to x
        while(low < high)
        {
            mid = low + (high - low)/2;
            if(x - arr[mid] > arr[mid+k] - x ) low = mid+1;
            else high = mid;
        }
        
        for(int i = low ; i < low+k ; i++)
        {
            result.add(arr[i]);
        }
        
        
        return result;
        
	}
}




*/
