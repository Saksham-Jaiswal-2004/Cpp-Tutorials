#include <iostream>
#include <vector>

using namespace std;

bool isPossible(const vector<int>& bookPages, int books, int students, int mid) 
{
    int studentCount = 1;
    int pageSum = 0;

    for (int i = 0; i < books; i++) 
    {
        if (pageSum + bookPages[i] <= mid) 
        {
            pageSum += bookPages[i];
        } 
        else 
        {
            studentCount++;
            if (studentCount > students || bookPages[i] > mid) 
            {
                return false;
            }
            pageSum = bookPages[i];
        }
    }
    return true;
}

int allocateBooks(int students, int books, const vector<int>& bookPages) 
{
    int start = 0;
    int ans = -1;
    int sum = 0;

    for (int i = 0; i < books; i++) 
    {
        sum += bookPages[i];
    }

    int end = sum;
    int mid = start + (end - start) / 2;

    while (start <= end) 
    {
        if (isPossible(bookPages, books, students, mid)) 
        {
            ans = mid;
            end = mid - 1;
        } 
        else 
        {
            start = mid + 1;
        }

        mid = start + (end - start) / 2;
    }
    return ans;
}

int main() {
    int books, students;

    cout << "Enter the number of books you want to allocate: ";
    cin >> books;
    cout << "Enter the number of students you want to allocate books to: ";
    cin >> students;

    if (students > books) 
    {
        cout << "Number of students cannot exceed the number of books.\n";
        return 0;
    }

    vector<int> bookPages(books);

    for (int i = 0; i < books; i++) 
    {
        cout << "Enter number of pages in book " << i + 1 << ": ";
        cin >> bookPages[i];
    }

    cout << "\n**** Data ****" << endl;
    cout << "Number of books: " << books << endl;
    cout << "Number of students: " << students << endl;

    int totalPages = 0;
    for (int i = 0; i < books; i++) 
    {
        totalPages += bookPages[i];
        cout << "Number of pages in book " << i + 1 << ": " << bookPages[i] << endl;
    }
    cout << "Total Number of pages: " << totalPages << endl;

    int result = allocateBooks(students, books, bookPages);

    cout << "\nAllocation Data (Minimum Maximum Pages): " << result << endl;

    return 0;
}