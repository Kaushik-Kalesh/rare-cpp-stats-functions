#include <bits/stdc++.h>
using namespace std;
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
int main() {
    vector<float> v;
    float n,x;
    cout << "Enter the No.of.Numbers: "; cin >> n;
    cout << "Enter the Numbers;\n";
    for (int i=0;i<n;++i) {
        cin >> x;
        v.push_back(x);
    }
    vector<float> v2 = mode(v);
    if (v2.size() != 1) {
        cout << "The Mode of the numbers are [";
        for (int i=0;i<v2.size()-1;++i) {
            cout << v2[i] << "," ;
        }
        cout << v2[v2.size()-1] << "]\n";
    }
    else {
        cout << "The Mode of the numbers is " << v2[0] << endl;
    }
}
