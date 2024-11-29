#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <iterator>

using namespace std;

int main() {
    // Step 1: Initialize Containers
    vector<string> dynamicWidgets = {"Speedometer", "Tachometer", "FuelGauge"};
    set<string> staticWidgets = {"Logo", "WarningLights"};

    // Step 2: Print all dynamic widgets using an iterator
    cout << "DYNAMIC WIDGETS:" << endl;
    for (auto it = dynamicWidgets.begin(); it != dynamicWidgets.end(); ++it) {
        cout << *it << endl;
    }
    cout << endl;
    
    // Step 3: Print all static widgets using an iterator
    cout << "STATIC WIDGETS:" << endl;
    for (auto it1 = staticWidgets.begin(); it1 != staticWidgets.end(); ++it1) {
        cout << *it1 << endl;
    }
    cout << endl;
    
    // Step 4: Check if "WarningLights" is in the set
    string searchWidget = "WarningLights";
    auto found = staticWidgets.find(searchWidget);
    if (found != staticWidgets.end()) {
        cout << searchWidget << " is in the static widgets set." << endl;
    } else {
        cout << searchWidget << " is not in the static widgets set." << endl;
    }
    cout << endl;
    
    // Step 5: Combine both containers into a single vector
    vector<string> combinedWidgets;
    copy(dynamicWidgets.begin(), dynamicWidgets.end(), back_inserter(combinedWidgets));
    copy(staticWidgets.begin(), staticWidgets.end(), back_inserter(combinedWidgets));
    
    // Step 6: Print all combined widgets
    cout << "Combined Widgets:" << endl;
    for (const auto& widget : combinedWidgets) {
        cout << widget << endl;
    }
    cout << endl;
    
    // Step 7: Find a specific widget in the combined container
    string searchCombined = "Tachometer";
    auto it = find(combinedWidgets.begin(), combinedWidgets.end(), searchCombined);
    if (it != combinedWidgets.end()) {
        cout << searchCombined << " found in the combined widget list." << endl;
    } else {
        cout << searchCombined << " not found in the combined widget list." << endl;
    }

    

    return 0;
}
