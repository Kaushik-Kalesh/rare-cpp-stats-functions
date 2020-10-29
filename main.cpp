#include <bits/stdc++.h>
using namespace std;
namespace stats {
        float mean(vector<float> v) {return (accumulate(v.begin(),v.end(),0.0))/(v.size());}

        float median(vector<float> v) {
            sort(v.begin(),v.end());
            float i,j,k,l; int n = v.size();
            float med,med2,med3,val;
            for (i=0;i<n;++i){
                j=i;
                j=(n-1)/2;
                med=v[j];
            }
            for (j=0;j<n;++j){
                med2=v[j];
                k=i;
                k=(n-2)/2;
                med2=v[k];
                l=k+1;
                med3=v[l];
            }
            val=n%2;
            if (val!=0) return med;
            else return (med2+med3)/2;
        }
    
        //crown jewel (You can't find SUCH a way to calculate mode using C++ in the entire internet!)
        vector<float> mode(vector<float> v) {
            sort(v.begin(),v.end());
            vector<int> v2; int temp=0;
            for (int i=0;i<v.size();++i) {
                temp = 0;
                for (int j=i;j<v.size();++j) {
                    if (v[i] == v[j]) temp++;
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
            for (int i=0;i<v3.size();++i) v4.push_back(v[v3[i]]);
            return v4;
        }
}

using namespace stats;
int main() {
    //sample code
    vector<float> v {12,4,48,53,23,54,21,32,13,54,23,4};
    cout << mean(v) << endl; //returns (28.4167)
    cout << median(v) << endl; //returns a vector {54,21}
    cout << endl;
    for (auto i : mode(v)) cout << i << " "; //returns a vector {4,23,54}
}

//namespace is used here for better cross-platform performance
//You can just copy and paste this, and use the namespace "stats" anywhere and anytime you want (as C++ doesn't have built-in mean or median or mode functions)
