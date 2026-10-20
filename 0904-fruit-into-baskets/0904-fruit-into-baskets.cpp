class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int firstType = -1;
        int secondType = -1;

        int firstTypeIndex = -1;
        int secondTypeIndex = -1;

        int left = 0;

        int maxCount = 0;

        for(int right = 0; right< fruits.size(); right++){
            int currentType = fruits[right];
            if(firstType == -1){
                firstType = currentType;
            }else if(secondType == -1){
                secondType = currentType;
            }

            if(currentType == firstType){
                firstTypeIndex = right;
            }else if(currentType == secondType){
                secondTypeIndex = right;
            }else{
                if(firstTypeIndex<secondTypeIndex){
                    left = firstTypeIndex + 1;
                }else{
                    left = secondTypeIndex + 1;
                }

                firstTypeIndex = right - 1;
                secondTypeIndex = right;

                firstType = fruits[firstTypeIndex];
                secondType = fruits[secondTypeIndex];
            }

            maxCount = max(maxCount, right - left + 1);
        }

        return maxCount;
    }
};