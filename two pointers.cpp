
#include <iostream>
#include <vector>
using namespace std;

void seq(vector<int>& arr, int k) {
    int left = 0;
    int right = 0;
    int right_point;
    int sum = 0;
    int max_sum = 0;
    int length = arr.size()+1;
    int left_point = 0;
    int min_lenght = 10000000000;
    while (right < arr.size()) {
        while (sum < k && right<arr.size()) {
            sum += arr[right];
            right++;
        }
        while (sum >= k && left < arr.size()) {
            if ((right - left < length || sum > max_sum || (sum == k && right - left < min_lenght))) { 
                length = right - left;
                left_point = left;
                right_point = right - 1;
                max_sum = sum;
                min_lenght = right - left; 
            }
            sum -= arr[left];
            left++;
        }
    }


    if (max_sum<k) {
        cout << "No summ" << endl;
    }
    else {

        cout << "Length = " << length << endl;
        cout << "Sum = " << max_sum << endl;
        cout << "Start = " << left_point << endl;
        cout << "Finish = " << right_point << endl;
    }
    
}




int main(){
    int n,k;
    cin >> n >> k;
    int summ = 0;
    vector <int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    seq(arr, k);
}
