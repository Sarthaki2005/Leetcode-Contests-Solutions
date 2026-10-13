class Solution {
public:
    int divide(int dividend, int divisor) {
        long ans=0;
        bool sign=true;
        if((dividend<0 && divisor>0) || (dividend>=0 && divisor<0)) sign=false;
        long div=abs((long)dividend);
        long d=abs((long)divisor);
        while(div>=d){
            long power=0;
            while(div>=(d<<power)){
                power++;
            }
            power-=1;
            ans+=(1LL<<power);
            div-=(d<<power);

        }
        if(ans>INT_MAX && sign) return INT_MAX;
        if(ans>INT_MAX && !sign) return INT_MIN;
        if(sign) return ans;

        return -ans;
    }
};