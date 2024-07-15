#include <bits/stdc++.h>
using namespace std;

int minimumCost(int m, int n, vector<int> &horizontalCut, vector<int> &verticalCut){
    if(m == 1 && n == 1){
        return 0;
    }
    int horiSum = 0;
    int vertSum = 0;
    for (int i = 0; i < m; i++)
        horiSum += horizontalCut[i];
    for (int j = 0; j < n; j++)
        vertSum += verticalCut[j];
    if(m == 1 && n>1){
        return vertSum;
    }
    else if(m>1 && n==1){
        return horiSum;
    }
    else if(m ==2 && n == 2)
        return horiSum;
}

int main() {
}