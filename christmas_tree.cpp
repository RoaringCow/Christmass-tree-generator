#include <iostream>
#include <string>

using namespace std;

string print_line(int spaces, int stars);

int main(int argc, char* argv[]){
    if (argc != 4) {
        cerr << "Wrong amount of arguments. Should be used like: " << argv[0] << " height root_height root_width\n";
        return 1;
    }

    int height, root_height, root_width;

    try {
        height = stoi(argv[1]);
        root_height = stoi(argv[2]);
        root_width = stoi(argv[3]);
    } catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
        cerr << "Please only enter integer values for height, root_height, and root_width.\n";
        return 1;
    }

    // Check if the values are valid
    if (height <= 0) {
        cout << "Invalid height value\n";
        return 1;
    } else if (root_height <= 0) {
        cout << "Invalid root height value\n";
        return 1;
    } else if (root_width <= 0) {
        cout << "Invalid root width value\n";
        return 1;
    }
    if (root_width % 2 == 0 && root_width != 1) {
        cout << "The root width is not appropriate! Must be an odd number.\n";
        return 1;
    } else if (height * 2 - 1 <= root_width) {
        printf("The root can't be thicker than the body itself!, body width: %i, root width: %i\n", height * 2 - 1, root_width);
        return 1;
    }

    for (int x = 0; x < height; x++){
        cout<<print_line(height - x - 1, x * 2 + 1);
    }
    for (int x = 0; x < root_height; x++){
        cout<<print_line(height - 1 - ((root_width - 1) / 2), root_width);
    }
}

string print_line(int spaces, int stars){
    string line;
    for (int x = 0; x < spaces; x++){
        line += " ";
    }
    for (int x = 0; x < stars; x++){ // buradaki x sıkıntı yaratabilir
        line += "*";
    }
    line += "\n";
    return line;
}