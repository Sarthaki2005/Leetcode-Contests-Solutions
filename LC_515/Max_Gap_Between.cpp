class Solution {
public:
    int maximumGap(string skill, string station) {
        int n=skill.size();
        if(n<=1) return 0;
        int m=station.size();
        vector<int> left(n),right(n);
        int i=0,j=0;
        while(i<n){
            if(skill[i]==station[j]){
                left[i]=j;
                i++;
                j++;
            }else{
                j++;
            }
        }
        i=n-1;
        j=m-1;
        while(i>=0){
            if(skill[i]==station[j]){
                right[i]=j;
                i--;
                j--;
            }else{
                j--;
            }
        }
        int max_g=0;
        for(int i=0;i<n-1;i++){
            max_g=max(max_g,right[i+1]-left[i]);
        }
        return max_g;
    }
};
