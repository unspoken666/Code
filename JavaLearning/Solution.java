class Solution {

   //两数之和
    public int[] twoSum(int[] nums, int target) {
        int[] tmp = new int[2];
        for(int i = 0;i<nums.length;i++){
            for(int j = i+1;j<nums.length;j++){
                if((nums[i]+nums[j]) == target){
                    tmp[0] = i;
                    tmp[1] = j;
                }
            }
        }
        return tmp;
    }

    //整数反转
    public int reverse(int x) {
        long n = 0;
        while(x!=0){
            n = n*10 + x%10;
            x /=10;
        }
        return (int)n==n? (int)n:0;
    }

    //判断回文数
    public boolean isPalindrome(int x) {

        if(x<0){
            return false;
        }else if(reverse(x)==x){
            return true;
        }else {
            return false;
        }

    }

    //罗马数字转整数
    public int romanToInt(String s) {
        int sum = 0;
        for(int i = 0;i<s.length();i++){
            switch(s.charAt(i)){
                case 'I':
                    sum += 1;
                    break;
                case 'V':
                    sum += 5;
                    break;
                case 'X':
                    sum += 10;
                    break;
                case 'L':
                    sum += 50;
                    break;
                case 'C':
                    sum += 100;
                    break;
                case 'D':
                    sum += 500;
                    break;
                case 'M':
                    sum += 1000;
                    break;
            }
            if(i!=0){
                if(s.charAt(i-1)=='I' && (s.charAt(i)=='V' || s.charAt(i)=='X')){
                    sum -= 2;
                }
                if(s.charAt(i-1)=='X' && (s.charAt(i)=='L' || s.charAt(i)=='C')){
                    sum -= 20;
                }
                if(s.charAt(i-1)=='C' && (s.charAt(i)=='D' || s.charAt(i)=='M')){
                    sum -= 200;
                }
            }
        }
        return sum;

    }



}