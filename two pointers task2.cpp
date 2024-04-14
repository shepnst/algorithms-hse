

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void seq(vector <int>& A, vector <int>& B, vector <int>& C) {
    int i = 0;
    int j = 0;
    int k = 0;
    int max_el = 0;
    int min_el = 0;
    int res_start = 0;
    int min_res = 10000000;
    int close_a = 0;
    int close_b = 0;
    int close_c = 0;
    vector <int> result;
    while (i < A.size() && j < B.size() && k < C.size()) {
        vector <int> curr = { A[i], B[j], C[k] };
        max_el = *max_element(curr.begin(), curr.end());
        min_el = *min_element(curr.begin(), curr.end());
        res_start = max_el - min_el;


        if (min_res > res_start) {
            min_res = res_start;
            result={A[i], B[j], C[k]};
            
        }

        if (min_el== A[i]) {
            i++;
        }
        else if (min_el== B[j]) {
            j++;
        }
        else if (min_el == C[k]) {
            k++;
        }
        
    }
    cout << "Numbers = ";
    for (int r = 0; r < result.size(); r++) {
        cout << result[r]<<" ";
    }
    cout << endl;
    cout << "Result = " << min_res;
}





int main()
{
    int nA=0;
    int nB = 0;
    int nC = 0;
    
    
    
    cin >> nA;
    vector <int> A(nA);
    for (int i = 0; i < nA; i++) {
        cin >> A[i];
    }
    cin >> nB;
    vector <int> B(nB);
    for (int j = 0; j < nB; j++) {
        cin >> B[j];
    }
    cin >> nC;
    vector <int> C(nC);
    for (int k = 0; k < nC; k++) {
        cin >> C[k];
    }
    seq(A, B, C);
}

