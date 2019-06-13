#include <iostream>

using namespace std;

bool move(int** tab, const int& tab_size, int mv, int x, int y, int& pos_x, int& pos_y)
{
    switch (mv) {
        case 1:
            pos_x = x + 1;
            pos_y = y - 2;
            break;
        case 2:
            pos_x = x + 2;
            pos_y = y - 1;
            break;
        case 3:
            pos_x = x + 2;
            pos_y = y + 1;
            break;
        case 4:
            pos_x = x + 1;
            pos_y = y + 2;
            break;
        case 5:
            pos_x = x - 1;
            pos_y = y + 2;
            break;
        case 6:
            pos_x = x - 2;
            pos_y = y + 1;
            break;
        case 7:
            pos_x = x - 2;
            pos_y = y - 1;
            break;
        case 8:
            pos_x = x - 1;
            pos_y = y - 2;
            break;
    }
    
    // sprawdzamy, kolejno czy nie wykraczamy poza tablicę x z lewej / prawej strony, y z lewej / prawej strony oraz czy pole było już odwiedzone
    if (0 <= pos_x && pos_x < tab_size && 0 <= pos_y && pos_y < tab_size && tab[pos_x][pos_y] == 0)
        return true;
    else
		return false;
}

bool chessHorse(int** tab, const int& tab_size, int x, int y, int n)
{
    int pos_x, pos_y;
    
    tab[x][y] = n; // Ustawiamy element tablicy jako n-ty ruch
    
    // Sprawdzamy czy numer kroku jest równy rozmiarowi tablicy
    if (n == tab_size * tab_size)
    {
		// Wypisanie
        for (int i = 0; i < tab_size; i++)
        {
            for (int j = 0; j < tab_size; j++)
                std::cout << tab[i][j] << "\t";
                
            std::cout << std::endl;
        }
        return 1;
    }
    else
    {
        // Uruchamiamy wszystkie case'y
        for (int mv = 1; mv < 9; mv++)
            if (move(tab, tab_size, mv, x, y, pos_x, pos_y) == true)
                
                // Kontynuujemy rekursję aż do przebycia całej szachownicy
                if (chessHorse(tab, tab_size, pos_x, pos_y, n + 1) == true)
                    return true;
        tab[x][y] = 0; // Jeśli nie ma możliwych ruchów, cofamy do poprzedniego i szukamy kolejnych możliwych
    }
    
    return false;
}

// Wypełniamy tablicę zerami, zapobiegając tablicy z wypełnieniem
void clearTab(int** tab, const int& tab_size)
{
    for (int i = 0; i < tab_size; i++)
        for (int j = 0; j < tab_size; j++)
            tab[i][j] = 0;
}

int main(int argc, const char * argv[]) {
    int max;
    
    std::cout << "Podaj rozmiar: ";
    std::cin >> max;
    // tworzymy szachownicę
    int** tab = new int*[max];

    for (int i = 0; i < max; i++)
    {
        tab[i] = new int[max];
    }
    
    int start_x, start_y;
    
    std::cout << "Wpisz pole startowe (x,y) ";
    std::cin >> start_x >> start_y;
    
    clearTab(tab, max);
    
    std::cout << "\n(" << start_x << ", " << start_y << ")\n";
    
    chessHorse(tab, max, start_x, start_y, 1);
    
    for (int i = 0; i < max; i++) 
    {
        delete[] tab[i];
    }
    delete[] tab;
    
    return 0;
}
