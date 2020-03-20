class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        int low=0;
        int high = arr.size()-1;
        while(low<high){
            int pivot = partition(arr,low,high);
            if(pivot > k) high = pivot - 1;
            if(pivot < k) low = pivot + 1;
            if(pivot == k) break;
        }
       return vector<int>(arr.begin(),arr.begin()+k);
    }

    int partition(vector<int>& arr,int low,int high){
        int pivot = arr[low];
        while(low<high){
            while(low<high && arr[high]>=pivot)
                high--;
            arr[low] = arr[high];
            while(low<high && arr[low] <=pivot){
                low++;
            }
            arr[high] = arr[low];

        }
        arr[low] = pivot;
        return low;
    }
};