
#include <iostream>
#include <vector>
#include <chrono>
#include <cstdlib>
using namespace std;
using namespace chrono;

// ==================== MERGE SORT ====================

void merge(vector<int>& arr, int left, int mid, int right) {

    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<int> L(n1);
    vector<int> R(n2);

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];

    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {

        if (L[i] <= R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }

    while (i < n1)
        arr[k++] = L[i++];

    while (j < n2)
        arr[k++] = R[j++];
}

void mergeSort(vector<int>& arr, int left, int right) {

    if (left < right) {

        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

// ==================== BINARY SEARCH ====================

int binarySearch(vector<int>& arr, int target) {

    int left = 0;
    int right = arr.size() - 1;

    while (left <= right) {

        int mid = left + (right - left) / 2;

        if (arr[mid] == target)
            return mid;

        if (arr[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }

    return -1;
}

// ==================== 0/1 KNAPSACK ====================

int knapsack(int capacity, vector<int>& weights,
             vector<int>& values, int n) {

    vector<vector<int>> dp(n + 1,
                           vector<int>(capacity + 1, 0));

    for (int i = 1; i <= n; i++) {

        for (int w = 1; w <= capacity; w++) {

            if (weights[i - 1] <= w) {

                dp[i][w] = max(
                    values[i - 1] +
                    dp[i - 1][w - weights[i - 1]],

                    dp[i - 1][w]
                );
            }
            else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    return dp[n][capacity];
}

// ==================== MAIN ====================

int main() {

    cout << "====================================\n";
    cout << " ALGORITHMS PROJECT\n";
    cout << "====================================\n\n";


    // ---------- MERGE SORT TEST ----------

    cout << "1. MERGE SORT\n";

    vector<int> arr = {38, 27, 43, 3, 9, 82, 10};

    cout << "Before sorting: ";

    for (int x : arr)
        cout << x << " ";

    cout << endl;

    auto start = high_resolution_clock::now();

    mergeSort(arr, 0, arr.size() - 1);

    auto end = high_resolution_clock::now();

    cout << "After sorting:  ";

    for (int x : arr)
        cout << x << " ";

    cout << endl;

    cout << "Runtime: "
         << duration_cast<nanoseconds>(end - start).count()
         << " ns\n\n";


    // ---------- BINARY SEARCH TEST ----------

    cout << "2. BINARY SEARCH\n";

    vector<int> searchArray =
        {10, 20, 30, 40, 50, 60, 70, 80, 90};

    int target = 60;

    start = high_resolution_clock::now();

    int result = binarySearch(searchArray, target);

    end = high_resolution_clock::now();

    if (result != -1)
        cout << target << " found at index "
             << result << endl;
    else
        cout << target << " not found\n";

    cout << "Runtime: "
         << duration_cast<nanoseconds>(end - start).count()
         << " ns\n\n";


    // ---------- KNAPSACK TEST ----------

    cout << "3. 0/1 KNAPSACK\n";

    vector<int> weights = {2, 3, 4, 5};
    vector<int> values = {3, 4, 5, 6};

    int capacity = 5;

    start = high_resolution_clock::now();

    int maximumValue =
        knapsack(capacity, weights, values,
                 weights.size());

    end = high_resolution_clock::now();

    cout << "Maximum value: "
         << maximumValue << endl;

    cout << "Runtime: "
         << duration_cast<nanoseconds>(end - start).count()
         << " ns\n\n";


    // ---------- COMPLEXITY ----------

    cout << "====================================\n";
    cout << "COMPLEXITY ANALYSIS\n";
    cout << "====================================\n";

    cout << "Merge Sort: O(n log n)\n";
    cout << "Binary Search: O(log n)\n";
    cout << "0/1 Knapsack: O(nW)\n";

    return 0;
}
