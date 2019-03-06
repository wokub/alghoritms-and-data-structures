#include <iostream>
#include <fstream>
#include <string>
#include <vector>


// Funkcja zwracająca wektor double zawierający dane z pliku
std::vector<double> loadFile(std::string file) {
    vector<double> fileData;
    ifstream textFile(file);
    
    if(newTextFile.is_open()) {
        string num;
        string::size_type size;
        
        do {
            double _num = stod(num); // stod - parse string na double'a
            fileData.push_back(_num);
        } while (getline(newTextFile, num));

        textFile.close();
    }
    return fileData;
}

std:::vector<double> factor(std::vector<double> & v1, std::vector<dobuel> & v2) {
    int len;
    std::vector<double> container;
    
    if(v1.size() > v2.size()) {
        len = v2.size();
    } else 
        len = v1.size();

    for(int i = 0; i < length; i++){
        container.push_back(v1[i] * v2[i]); // c(x)=a(x)b(x)
    }
    return container;
}

int main() {
    std::vector<double> a = loadFile("a.txt");
    std::vector<double> b = loadFile("b.txt");
    std::vector<double> c = factor(a, b);
    ofstream saveFile("c.txt");
    for(int i = 0; i < c.size(); i++) {
        saveFile << c[i] << std::endl;
    }
    saveFile.close();
}
