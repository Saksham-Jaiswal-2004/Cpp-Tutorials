#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Structure to hold activity details
struct Activity 
{
    int start, finish;
};

// Comparator to sort by finish time
bool activityCompare(Activity a, Activity b) 
{
    return a.finish < b.finish;
}

// Greedy iterative implementation
vector<Activity> activitySelection(vector<Activity> &activities) 
{
    // Step 1: Sort by finish time
    sort(activities.begin(), activities.end(), activityCompare);

    vector<Activity> result;
    int n = activities.size();

    // Step 2: Select the first activity
    result.push_back(activities[0]);
    int lastFinish = activities[0].finish;

    // Step 3: Check for non-overlapping activities
    for (int i = 1; i < n; i++) 
    {
        if (activities[i].start >= lastFinish) 
        {
            result.push_back(activities[i]);
            lastFinish = activities[i].finish;
        }
    }

    return result;
}

int main() 
{
    int N = 6;
    vector<Activity> activities(N);

    cout << "Enter start and finish times of 6 activities:\n";
    for (int i = 0; i < N; i++) 
    {
        cout << "Activity " << i + 1 << " (start finish): ";
        cin >> activities[i].start >> activities[i].finish;
    }

    vector<Activity> selected = activitySelection(activities);

    cout << "\nMaximum number of non-overlapping activities: " << selected.size() << "\n";
    cout << "Selected Activities (start, finish):\n";
    for (auto &a : selected)
        cout << "(" << a.start << ", " << a.finish << ")\n";

    cout << "\n--- Time Complexity Analysis ---\n";
    cout << "Sorting: O(N log N)\n";
    cout << "Selection Loop: O(N)\n";
    cout << "Total Time Complexity: O(N log N)\n";
    cout << "Space Complexity: O(N)\n";

    return 0;
}