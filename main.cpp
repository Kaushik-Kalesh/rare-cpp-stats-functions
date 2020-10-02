#include <bits/stdc++.h>

using namespace std;

namespace stats {
    
        float average(vector<float> iarr) {
            int i; int n = iarr.size();
            float sum,avg; 
            avg=accumulate(iarr.begin(),iarr.end(),0)/n;
            return avg;
        }

        vector<float> median(vector<float> iarr) {
            float i,j,k,l; int n = iarr.size();
            float med,med2,med3,val;
            for (i=0;i<n;++i){
                j=i;
                j=(n-1)/2;
                med=iarr[j];
            }
            for (j=0;j<n;++j){
                med2=iarr[j];
                k=i;
                k=(n-2)/2;
                med2=iarr[k];
                l=k+1;
                med3=iarr[l];
            }
            val=n%2;
            if (val!=0){
                return {med};
            }
            else{
                return {med2,med3};
            }
        }

        vector<float> mode(vector<float> v) {
            sort(v.begin(),v.end());
            vector<int> v2; int temp=0;
            for (int i=0;i<v.size();++i) {
                temp = 0;
                for (int j=i;j<v.size();++j) {
                    if (v[i] == v[j]) {
                        temp++;
                    }
                }
                v2.push_back(temp);
            }
            vector<int> v3;
            int max = *max_element(v2.begin(),v2.end());
            for (int i=0;i<v2.size();++i) {
                if (max == v2[i]) {
                    v3.push_back(i);
                    continue;
                }
            }
            vector<float> v4;
            for (int i=0;i<v3.size();++i) {
                v4.push_back(v[v3[i]]);
            }
            return v4;
        }
    
}

using namespace stats;

int main() {
    //code
}

//namespace is used here for better cross-platform performance
//You can just copy and paste this, and use the namespace stats anywhere and anytime you want (as C++ doesn't have in-built median or mode functions)
//eg: stats::average() can be used to call average() function
