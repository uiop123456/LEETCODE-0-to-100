class Solution {
public:
    int trap(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        int left_max = 0, right_max = 0;
        int add = 0;

        while(left<right){
            /* 
              going up from forward (left++)
                                        ->
                                   ->
                               ->
                          ->
                      ->
                  ->
              ->
            */
            if(nums[left]<nums[right]){
                // while going up if getting any left max so update current left hight with left_max
                if(nums[left]>=left_max) left_max=nums[left];
                // if you didn't find any upper value of left max so it's mean it's a dip while going up water can be stored here, so add the dip value to add water += left max value - nijer hight
                /* 
                  going up from forward (left++)
                                      dip                  ->
                                       |               ->
                                       v            ->
                              ->                ->
                          ->  |    ->       ->
                      ->      |        ->
                  ->          |         |
               ->         left_max   nijer hight
                */
                else add += left_max - nums[left];
                // going forward
                left++;
            }
            /* 
              going up from backwards (right--) 
              <-
                  <-
                       <-
                            <-
                                 <-
                                      <-
                                           <-
            */
            else{
                // while going up from back it we get any bigger right index value from right_max then update it
                if(nums[right]>=right_max) right_max=nums[right];
                // so if I didn't encounter any upper value so it's mean it's a dip, so here water can store, add water += right max what I get - nijer hight
                else add += right_max - nums[right];
                // going backward 
                right--;
            }
        }
        return add;
    }
};
