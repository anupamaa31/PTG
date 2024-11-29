#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

// Observer Interface
class ModeObserver {
public:
    virtual void update(const string& mode) = 0;
    virtual ~ModeObserver() {}
};

// Concrete Observer: Button
class Button : public ModeObserver {
public:
    void update(const string& mode) override {
        if (mode == "Night") {
            cout << "Button: Switching to Night Mode visuals." << endl;
        } else {
            cout << "Button: Switching to Day Mode visuals." << endl;
        }
    }
};

// Subject: HMISystem
class HMISystem {
private:
    vector<ModeObserver*> observers;
    string mode = "Day";

public:
    void attach(ModeObserver* observer) {
        observers.push_back(observer);
    }

    void detach(ModeObserver* observer) {
        observers.erase(
            remove(observers.begin(), observers.end(), observer),
            observers.end()
        );
    }

    void notify() {
        for (ModeObserver* observer : observers) {
            observer->update(mode);
        }
    }

    void setMode(const string& newMode) {
        mode = newMode;
        cout << "HMISystem: Mode changed to " << mode << ". Notifying observers..." << endl;
        notify();
    }
};

int main() {
    HMISystem hmiSystem;

    Button button;

    hmiSystem.attach(&button);

    hmiSystem.setMode("Night");
    hmiSystem.detach(&button);
    hmiSystem.setMode("Day");


    return 0;
}
