class Solution {
public:
    int reversePairs(vector<int>& nums) {
        int len = nums.size();

        if(len<2) return 0;
        vector<int> copy(nums),temp(len);
        // temp作用 临时数组，copy用于保存每一次归并后
        return reversePairs(copy, 0, len - 1 , temp);
    }


    //返回[left,right] 区间内的逆序数
    int reversePairs(vector<int>& nums,int left,int right,vector<int>& temp){
        if(left >= right) return 0;

        int mid = left + (right - left)/2;

        //左半部分逆序数
        int left_pairs = reversePairs(nums, left, mid ,temp);
        //右半部分逆序数
        int right_pairs = reversePairs(nums, mid+1, right, temp);

        //合并并统计两侧整体逆序数
        int crossPairs = mergeAndCount(nums,left,mid,right,temp);

        //整体逆序数
        return left_pairs + right_pairs + crossPairs;
    }


    //归并排序并统计逆序数
    int mergeAndCount(vector<int>& nums,int left,int mid ,int right,vector<int>& temp){
        for(int i=left;i<=right;i++){
            temp[i] = nums[i];
        }

        int i=left;
        int j=mid+1;

        int cnt = 0;
        for(int k=left;k<=right;k++){
            if(i==mid+1){
                nums[k] = temp[j];j++;
            }else if(j==right+1){
                nums[k] = temp[i];i++;
            }

            else  if(temp[i]<=temp[j]){
                nums[k] = temp[i];i++;
            }else{
                nums[k] = temp[j];
                cnt += mid - i+1;j++;
            }
        }
//cout<<cnt<<endl;
        return cnt;

    }


};