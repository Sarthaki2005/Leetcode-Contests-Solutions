class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int sum=0;
        int maxSum=0;
        int n=cardPoints.size();
        for(int i=0;i<k;i++){
           maxSum+=cardPoints[i];
           
        }
        sum=maxSum;
        int i=0;
        int j=k-1;
        while(j!=n-1){
            sum-=cardPoints[j];
            j=(j-1+n)%n;
            i=(i-1+n)%n;
            sum+=cardPoints[i];
            maxSum=max(maxSum,sum);
        }
return maxSum;

    }
};