#include <iostream> 

#include <map> 

#include <string> 

  

using namespace std; 

  

class Theme { 

public: 

    string backgroundColor; 

    string fontColor; 

    int fontSize; 

    string iconStyle; 

  

  

    Theme() : backgroundColor("DefaultBG"), fontColor("DefaultFont"), fontSize(12), iconStyle("DefaultIcon") {} 

  

  

    Theme(const string& bg, const string& font, int size, const string& icon) 

        : backgroundColor(bg), fontColor(font), fontSize(size), iconStyle(icon) {} 

  

    void apply() const { 

        cout << "Applying Theme: " << backgroundColor << ", " << fontColor << ", " 

             << fontSize << "px Font Size, " << iconStyle << " Icons." << endl; 

    } 

  

    void display() const { 

        cout << "Theme Preview: " << backgroundColor << " Background, " << fontColor 

             << " Font, " << fontSize << "px Font Size, " << iconStyle << " Icons." << endl; 

    } 

}; 

  

int main() { 

  

    map<string, Theme> themes; 

  

  

    themes["classic"] = Theme("White", "Black", 14, "Square"); 

    themes["sport"] = Theme("Red", "White", 16, "Bold"); 

    themes["eco"] = Theme("Green", "Brown", 12, "Leaf"); 

  

    string choice; 

  

  

    while (true) { 

        cout << "\nAvailable Themes: classic, sport, eco, exit" << endl; 

        cout << "Enter theme name to apply: "; 

        cin >> choice; 

  

        if (choice == "exit"  ) { 

            break; 

        } 

  

        auto it = themes.find(choice); 

        if (it != themes.end()) { 

            cout << "\n" << choice << " Theme selected: " << endl; 

            it->second.display();  

            it->second.apply();    

        } else { 

            cout << "Theme not found. Please try again." << endl; 

        } 

    } 

  

    return 0; 

} 

//this is fourth task 

 
