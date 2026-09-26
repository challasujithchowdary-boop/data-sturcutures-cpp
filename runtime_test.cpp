
#include <iostream>
#include <vector>
#include <chrono>
#include <algorithm>
#include <cstdlib>
using namespace std;
using namespace chrono;

// Merge Sort
void merge(vector<int>& a, int l, int m, int r) {
    vector<int> temp;
    int i = l, j = m + 1;

    while (i <= m && j <= r) {
        if (a[i] <= a[j])
            temp.push_back(a[i++]);
        else
            temp.push_back(a[j++]);
    }

    while (i <= m) temp.push_back(a[i++]);
    while (j <= r) temp.push_back(a[j++]);

    for (int k = 0; k < temp.size(); k++)
        a[l + k] = temp[k];
}

void mergeSort(vector<int>& a, int l, int r) {
    if (l >= r) return;

    int m = (l + r) / 2;

    mergeSort(a, l, m);
    mergeSort(a, m + 1, r);
    merge(a, l, m, r);
}

// Binary Search
int binarySearch(vector<int>& a, int x) {
    int l = 0, r = a.size() - 1;

    while (l <= r) {
        int m = (l + r) / 2;

        if (a[m] == x) return m;
        else if (a[m] < x) l = m + 1;
        else r = m - 1;
    }

    return -1;
}

int main() {

    vector<int> sizes = {100, 1000, 5000, 10000};

    cout << "============================================\n";
    cout << " RUNTIME ANALYSIS FOR DIFFERENT INPUT SIZES\n";
    cout << "============================================\n\n";

    cout << "Input Size\tMerge Sort(ns)\tBinary Search(ns)\n";
    cout << "--------------------------------------------------\n";

    for (int n : sizes) {

        vector<int> arr(n);

        for (int i = 0; i < n; i++)
            arr[i] = rand() % 100000;

        // Merge Sort Runtime
        vector<int> temp = arr;

        auto start = high_resolution_clock::now();

        mergeSort(temp, 0, n - 1);

        auto end = high_resolution_clock::now();

        long long mergeTime =
            duration_cast<nanoseconds>(end - start).count();


        // Binary Search Runtime
        sort(arr.begin(), arr.end());

        start = high_resolution_clock::now();

        binarySearch(arr, arr[n / 2]);

        end = high_resolution_clock::now();

        long long searchTime =
            duration_cast<nanoseconds>(end - start).count();


        cout << n << "\t\t"
             << mergeTime << "\t\t"
             << searchTime << endl;
    }

    cout << "\nComplexities:\n";
    cout << "Merge Sort    : O(n log n)\n";
    cout << "Binary Search : O(log n)\n";

    return 0;
}
