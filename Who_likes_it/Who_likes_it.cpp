//You probably know the "like" system from Facebook and other pages.People can "like" blog posts, 
//pictures or other items.We want to create the text that should be displayed next to such an item.
//likes{} // must be "no one likes this"
//likes{ "Peter" } // must be "Peter likes this"
//likes{ "Jacob", "Alex" } // must be "Jacob and Alex like this"

#include <iostream>
#include <vector>
#include <string>
using namespace std;


std::string likes(const std::vector<std::string>& names) {
    switch (names.size()) {
    case 0: return "no one likes this";
    case 1: return names[0] + " likes this";
    case 2: return names[0] + " and " + names[1] + " like this";
    case 3: return names[0] + ", " + names[1] + " and " + names[2] + " like this";
    default: return names[0] + ", " + names[1] + " and " + std::to_string(names.size() - 2) + " others like this";
    }
}

int main()
{
    vector<string> input = { "Alex", "Jacob", "Mark", "Max" };
    vector<string> input1 = { "Jacob", "Alex" };
    cout << likes(input);
    cout << likes(input1);
}
