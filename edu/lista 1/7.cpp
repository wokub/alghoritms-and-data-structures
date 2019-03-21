#include <iostream>
#include <fstream>
#include <string>
#include <vector>

// Funkcja zwracająca wektor double zawierający dane z pliku
std::vector<double> loadFile(std::string file) {
    std::vector<double> fileData;
    std::ifstream textFile(file);

    if(textFile.is_open()) {
        std::string num;
        std::string::size_type len;

        while(getline(textFile, num)){
            len = num.length();
            if(len != 0) {
                double _num = stod(num);
                fileData.push_back(_num);
            }
        }

        textFile.close();
    }
    return fileData;
}

std::vector<double> factor(std::vector<double> & v1, std::vector<double> & v2) {
    int len;
    std::vector<double> container;

    if(v1.size() > v2.size()) {
        len = v2.size();
    } else
        len = v1.size();

    for(int i = 0; i < len; i++){
        container.push_back(v1[i] * v2[i]); // c(x)=a(x)b(x)
    }
    return container;
}

int main() {
    std::vector<double> a = loadFile("a.txt");
    std::vector<double> b = loadFile("b.txt");
    std::vector<double> c = factor(a, b);
    std::ofstream saveFile;

    saveFile.open("c.txt");

    for(int i = 0; i < c.size(); i++) {
        saveFile << c[i] << std::endl;
    }

    saveFile.close();
}
