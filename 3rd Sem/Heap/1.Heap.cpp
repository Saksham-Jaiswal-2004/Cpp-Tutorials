#include <iostream>

using namespace std;

class heap
{
public:
    int arr[100];
    int size = 0;

    heap()
    {
        arr[0] = -1;
        size = 0;
    }

    void insert(int val)
    {
        size++;
        int index = size;
        arr[index] = val;

        while (index > 1)
        {
            int parent = index / 2;
            if (arr[parent] < arr[index])
            {
                swap(arr[index], arr[parent]);
                index = parent;
            }
            else
                return;
        }
    }

    void deleteRoot()
    {
        if (size == 0)
            return;

        arr[1] = arr[size];
        size--;

        int i = 1;
        while (i < size)
        {
            int leftIndex = 2 * i;
            int rightIndex = 2 * i + 1;

            if (leftIndex < size && arr[i] < arr[leftIndex])
            {
                swap(arr[leftIndex], arr[i]);
                i = leftIndex;
            }
            else if (rightIndex < size && arr[i] < arr[rightIndex])
            {
                swap(arr[rightIndex], arr[i]);
                i = rightIndex;
            }
            else
            {
                return;
            }
        }
    }

    void print()
    {
        for (int i = 1; i <= size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

void heapify(int arr[], int n, int i)
{
    int largest = i;
    int leftChild = 2 * i;
    int rightChild = 2 * i + 1;

    if (leftChild < n && arr[largest] < arr[leftChild])
        largest = leftChild;
    if (rightChild < n && arr[largest] < arr[rightChild])
        largest = rightChild;

    if (largest != i)
    {
        swap(arr[largest], arr[i]);
        heapify(arr, n, largest);
    }
}

int main()
{
    heap h;
    h.insert(30);
    h.insert(50);
    h.insert(55);
    h.insert(40);
    h.insert(70);
    h.insert(20);
    h.insert(60);
    h.print();

    h.deleteRoot();
    h.print();

    int arr[] = {-1, 54, 53, 55, 52, 50};
    int n = 5;
    for (int i = n / 2; i > 0; i--)
    {
        heapify(arr, n, i);
    }

    for (int i = 1; i <= n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}