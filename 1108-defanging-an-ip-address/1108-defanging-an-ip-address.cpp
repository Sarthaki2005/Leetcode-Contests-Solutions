class Solution {
public:
    string defangIPaddr(string address) {
        string res="";
        int n=address.size();
        for(int i=0;i<n;i++){
            res+=address[i];
            if(i+1<n && address[i+1]=='.'){
                res+='[';
            }
            if(address[i]=='.'){
                res+=']';
            }
        }
return res;
    }
};