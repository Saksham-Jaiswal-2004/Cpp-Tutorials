#include <iostream>
#include <vector>
using namespace std;

void heapify(vector<int> &arr, int n, int i) 
{
    int largest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;
    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) 
    {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(vector<int> &arr) 
{
    int n = arr.size();

    // Build max heap
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // Extract elements one by one
    for (int i = n - 1; i >= 0; i--) 
    {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

int main() 
{
    int n, k;
    cout << "Enter number of students: ";
    cin >> n;

    vector<int> scores(n);
    cout << "Enter scores: ";
    for (int i = 0; i < n; i++)
        cin >> scores[i];

    cout << "Enter k: ";
    cin >> k;

    heapSort(scores);

    cout << "Sorted Scores (Descending): ";
    for (int i = n - 1; i >= 0; i--)
        cout << scores[i] << " ";
    cout << endl;

    cout << "Top " << k << " Scores: ";
    for (int i = n - 1; i >= n - k; i--)
        cout << scores[i] << " ";
    cout << endl;

    return 0;
}