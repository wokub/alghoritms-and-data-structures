#include <fstream>
#include <iostream>
#include <string>
#include <vector>

std::vector<int> countASCII(std::string file) {
    std::vector<int> tab(255);
    std::string line;
    std::ifstream loadFile(file);

    if (loadFile) {
        while (getline( loadFile, line )){
            for(int i = 0; i < line.length(); i++) {
                tab[(int)line[i]] += 1;
            }
        }
        loadFile.close();
    }
    return tab;
}

void showResult(std::vector<int> tab) {
    for(int i = 0; i < tab.size(); i++) {
        if(tab[i]!=0) {
            std::cout << (char)i << ": " << tab[i] << std::endl;
        }
    }
}

int main() {
    showResult(countASCII("9.txt"));

    return 0;
}
