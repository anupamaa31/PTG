#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstdlib> // For srand and rand
#include <ctime>   // For time
using namespace std;

// Define Control struct
struct Control {
    int id;
    string type;  // "button" or "slider"
    string state; // "visible", "invisible", "disabled"

    void print() const {
        cout << "ID: " << id << ", Type: " << type << ", State: " << state << endl;
    }
};

int main() {

    // Initialize sample controls
    vector<Control> controls = {
        {1, "button", "visible"}, {2, "slider", "invisible"},
        {3, "button", "disabled"}, {4, "slider", "visible"},
        {5, "button", "visible"}, {6, "slider", "disabled"},
        {7, "button", "visible"}, {8, "slider", "visible"},
        {9, "button", "invisible"}, {10, "slider", "visible"}
    };

    // 1. Create a backup using std::copy
    vector<Control> backup(controls.size());
    copy(controls.begin(), controls.end(), backup.begin());
    cout << "Backup of controls:" << endl;
    for (const auto& c : backup) c.print();
    cout << endl;
    

    // 2. Temporarily disable all controls using std::fill
    fill(controls.begin(), controls.end(), Control{0, "any", "disabled"});
    cout << "All controls temporarily disabled:" << endl;
    for (const auto& c : controls) c.print();
    cout << endl;
    
    // Initialize random seed
    srand(static_cast<unsigned>(time(0)));

    // 3. Generate random states and types using std::generate
    vector<string> states = {"visible", "invisible", "disabled"};
    vector<string> types = {"button", "slider"};

    generate(controls.begin(), controls.end(), [&states, &types]() {
        static int id = 1;
        return Control{
            id++, 
            types[rand() % types.size()],     // Random type: "button" or "slider"
            states[rand() % states.size()]   // Random state: "visible", "invisible", "disabled"
        };
    });
    cout << "Controls with random states and types:" << endl;
    for (const auto& c : controls) c.print();
    cout << endl;
    
    // 4. Change all sliders' state to "invisible" using std::transform
    transform(controls.begin(), controls.end(), controls.begin(), [](Control& c) {
        if (c.type == "slider") c.state = "invisible";
        return c;
    });
    cout << "After setting all sliders to invisible:" << endl;
    for (const auto& c : controls) c.print();
    cout << endl;

    // 5. Replace "disabled" with "enabled" using a loop
    for (auto& c : controls) {
        if (c.state == "disabled") {
            c.state = "enabled";
        }
    }
    cout << "After replacing 'disabled' with 'enabled':" << endl;
    for (const auto& c : controls) c.print();
    cout << endl;
    
    // 6. Remove all invisible controls using std::remove_if
    controls.erase(remove_if(controls.begin(), controls.end(), [](const Control& c) {
        return c.state == "invisible";
    }), controls.end());
    cout << "After removing invisible controls:" << endl;
    for (const auto& c : controls) c.print();
    cout << endl;
    
    // 7. Reverse the control order using std::reverse
    reverse(controls.begin(), controls.end());
    cout << "After reversing the control order:" << endl;
    for (const auto& c : controls) c.print();
    cout << endl;
    
    // 8. Group visible controls together using std::partition
    partition(controls.begin(), controls.end(), [](const Control& c) {
        return c.state == "visible";
    });
    cout << "After grouping visible controls together:" << endl;
    for (const auto& c : controls) c.print();
    cout << endl;
    
    return 0;
    
}
