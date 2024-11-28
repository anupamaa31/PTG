#include <iostream> 

#include <thread> 

#include <mutex> 

#include <chrono> 

#include <cstdlib> 

#include <ctime> 

#include <random> 

  

#ifdef _WIN32 

#include <windows.h> 

#else 

#include <unistd.h> 

#endif 

  

using namespace std; 

  

class VehicleData { 

private: 

    int speed;  

    int fuelLevel;  

    int temperature;  

    mutable mutex dataMutex;  

  

    // Using random device and Mersenne Twister engine for thread-safe random numbers 

    random_device rd; 

    mt19937 gen{rd()}; 

  

public: 

    VehicleData() : speed(0), fuelLevel(100), temperature(70) {} 

  

    void updateData() { 

        lock_guard<mutex> lock(dataMutex); 

  

        uniform_int_distribution<> speedDist(0, 120); 

        uniform_int_distribution<> fuelDist(0, 4); // Fuel decrease between 0 to 4 

        uniform_int_distribution<> tempDist(70, 110); // Temperature between 70 and 110 degrees 

  

        speed = speedDist(gen); 

        fuelLevel = max(0, fuelLevel - fuelDist(gen)); 

        temperature = tempDist(gen); 

    } 

  

    int getSpeed() const { 

        lock_guard<mutex> lock(dataMutex); 

        return speed; 

    } 

  

    int getFuelLevel() const { 

        lock_guard<mutex> lock(dataMutex); 

        return fuelLevel; 

    } 

  

    int getTemperature() const { 

        lock_guard<mutex> lock(dataMutex); 

        return temperature; 

    } 

}; 

  

class Display { 

public: 

    static void showData(const VehicleData& data) { 

        // Clear console screen depending on platform 

        #ifdef _WIN32 

            system("cls"); 

        #else 

            system("clear"); 

        #endif 

  

        int speed = data.getSpeed(); 

        int fuel = data.getFuelLevel(); 

        int temp = data.getTemperature(); 

  

        cout << "================ Instrument Cluster ================" << endl; 

        cout << "Speed       : " << speed << " km/h" << endl; 

        cout << "Fuel Level  : " << fuel << "%" << endl; 

        cout << "Temperature : " << temp << "°C" << endl; 

  

        if (temp > 100) 

            cout << "WARNING: Engine overheating! " << endl; 

        if (fuel < 10) 

            cout << "WARNING: Low fuel level!" << endl; 

        cout << "===================================================" << endl; 

    } 

}; 

  

void dataUpdater(VehicleData& data) { 

    while (true) { 

        data.updateData(); 

        this_thread::sleep_for(chrono::seconds(1)); // Update every second 

    } 

} 

  

void dataDisplayer(VehicleData& data) { 

    while (true) { 

        Display::showData(data); 

        this_thread::sleep_for(chrono::seconds(2)); // Display every two seconds 

    } 

} 

  

int main() { 

    srand(static_cast<unsigned int>(time(0))); // Seed random number generator 

  

    VehicleData vehicleData; 

  

    // Start updater and displayer threads 

    thread updater(dataUpdater, ref(vehicleData)); 

    thread displayer(dataDisplayer, ref(vehicleData)); 

  

    // Join threads so main thread waits for both to finish 

    updater.join(); 

    displayer.join(); 

  

    return 0; 
