class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int current = 0;
        int bill5 = 0;
        int bill10 = 0;
        int bill20 = 0;

        while(current < bills.size()){
            int bill = bills[current++];
            if(bill == 5){
                bill5++;
            }else if(bill == 10 && bill5 > 0){
                bill5--;
                bill10++;
            }else if(bill == 20 && bill5 > 0 && bill10 > 0){
                bill5--;
                bill10--;
                bill20++;
            }else if(bill == 20 && bill5 > 2){
                bill5 -= 3;
                bill20++;
            }else{
                return false;
            }
        }

        return true;
    }
};