class pair{
        int index;
        int value;
        public pair(int index,int value){
            this.index = index;
            this.value = value;
        }
    }
    class Compare{
        static void compare(pair arr[]){
            Arrays.sort(arr,new Comparator<pair>(){
                public int compare(pair p1,pair p2){
                    return  p1.value-p2.value;
                }
            });
        }
    }
class Solution {

    public int[] twoSum(int[] nums, int target) {
        pair arr[] = new pair[nums.length];
        for(int i=0;i<nums.length;++i){
            arr[i] = new pair(i,nums[i]);
        }
        Compare obj = new Compare();
        obj.compare(arr);
        for(pair p:arr){
            System.out.println(p.index+" "+p.value);
        }
        int l = 0;
        int r = nums.length-1;
        int ans[] = new int[2];
        while(l<r){
            if(arr[l].value+arr[r].value==target){
                ans[0] = arr[l].index;
                ans[1] = arr[r].index;
                break;
            }else if(arr[l].value+arr[r].value<target){
                l = l+1;
            }else{
                r = r-1;
            }
        }
        return ans;
    }
}
