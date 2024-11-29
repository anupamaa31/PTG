#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

// Define Control struct
struct Control {
    int id;
    string type;  // "button" or "slider"
    string state; // "visible", "invisible", "disabled"

    void print() const {
        cout << "ID: " << id << ", Type: " << type << ", State: " << state << endl;
    }

    // Overload < operator for sorting
    bool operator<(const Control& other) const {
        return id < other.id;
    }

    // Overload == operator for set operations
    bool operator==(const Control& other) const {
        return id == other.id && type == other.type && state == other.state;
    }
};

int main() {
    // Sample controls
    vector<Control> controls1 = {
        {3, "button", "visible"}, {1, "slider", "invisible"}, {5, "button", "disabled"}};
    vector<Control> controls2 = {
        {1, "slider", "invisible"}, {2, "button", "visible"}, {6, "slider", "disabled"}};

    // 1. Sort the controls by ID using std::sort
    sort(controls1.begin(), controls1.end());
    sort(controls2.begin(), controls2.end());

    cout << "Controls 1 after sorting:" << endl;
    for (const auto& c : controls1) c.print();

    cout << "Controls 2 after sorting:" << endl;
    for (const auto& c : controls2) c.print();
    cout << endl;
     

    // 2. Binary search for a control by ID using std::lower_bound and std::upper_bound
    int searchId = 3;
    auto it = lower_bound(controls1.begin(), controls1.end(), Control{searchId, "", ""});
    if (it != controls1.end() && it->id == searchId) {
        cout << "Control with ID " << searchId << " found in Controls 1:" << endl;
        it->print();
    } else {
        cout << "Control with ID " << searchId << " not found in Controls 1." << endl;
    }
    cout << endl;
    
    // 3. Merge two sorted lists into a single sorted list using std::merge
    vector<Control> mergedControls(controls1.size() + controls2.size());
    merge(controls1.begin(), controls1.end(), controls2.begin(), controls2.end(), mergedControls.begin());

    cout << "Merged controls:" << endl;
    for (const auto& c : mergedControls) c.print();
    cout << endl;
    
    
    // 4. Inplace merge two segments of the same list
    vector<Control> inplaceList = {
        {1, "slider", "visible"}, {4, "button", "invisible"}, {6, "button", "disabled"}, 
        {2, "button", "visible"}, {5, "slider", "visible"}, {8, "slider", "disabled"}};

    inplace_merge(inplaceList.begin(), inplaceList.begin() + 3, inplaceList.end());

    cout << "List after inplace merging:" << endl;
    for (const auto& c : inplaceList) c.print();
    cout << endl;
    
    // 5. Set operations: Union and Intersection
    vector<Control> setUnion, setIntersection;

    set_union(
        controls1.begin(), controls1.end(),
        controls2.begin(), controls2.end(),
        back_inserter(setUnion));

    set_intersection(
        controls1.begin(), controls1.end(),
        controls2.begin(), controls2.end(),
        back_inserter(setIntersection));

    cout << "Set union of Controls 1 and Controls 2:" << endl;
    for (const auto& c : setUnion) c.print();
    cout << endl;

    cout << "Set intersection of Controls 1 and Controls 2:" << endl;
    if (setIntersection.empty()) {
        cout << "No common elements." << endl;
    } else {
        for (const auto& c : setIntersection) c.print();
    }

    return 0;
}
