class Solution {
public:
    string addStrings(string num1, string num2) {
        string ans="";
        int sum=0,carry=0;
        int n=num1.size();
        int m=num2.size();
        int i=n-1;
        int j=m-1;
        while(i>=0 && j>=0){
            int d1=num1[i]-'0';
            int d2=num2[j]-'0';
            sum=d1+d2+carry;
            char c=(sum%10)+'0';
            carry=sum/10;
            ans+=c;
            i--;
            j--;
        }
        while(i>=0){
            int d1=num1[i]-'0';
            sum=d1+carry;
            char c=(sum%10)+'0';
            carry=sum/10;
            ans+=c;
            i--;
        }
        while(j>=0){
            int d2=num2[j]-'0';
            sum=d2+carry;
            char c=(sum%10)+'0';
            carry=sum/10;
            ans+=c;
            j--;
        }
        if(carry!=0) ans+=(carry+'0');
        reverse(ans.begin(),ans.end());
        return ans;
    }
};