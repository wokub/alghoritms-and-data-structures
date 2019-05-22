#include <iostream>
#define N 3

// 5
class UnionFind
{
private:
    int *parent;
    int *rank;

public:
    UnionFind(int n) : parent{new int[n]}, rank{new int[n]}
    {
        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
            rank[i] = 0;
        }
    }

    // Zwracamy reprezentanta i-tego zbioru
    int Find(int i)
    {
        if (parent[i] == i)
            return i; // Zwracamy korzeń

        return parent[i] = Find(parent[i]); // Korzeń -> Ojciec "i"
    }

    void Union(int i, int j)
    {
        if (rank[Find(i)] != Find(j))           // Reprezentanci różni
        {
            parent[Find(i)] = Find(j);          // Łączymy dwie wyspy
        }
        else if (rank[Find(i)] < rank[Find(j)])
        {
            parent[Find(j)] = Find(i);
        }
        else
        { // Rangi takie same
            parent[Find(i)] = Find(j);          // Łączymy dwie wyspy
            rank[Find(j)]++;                    // zwiększamy rangę drugiego reprezentanta
        }
    }

    ~UnionFind()
    {
        delete[] rank;
        delete[] parent;
    }
};

// 6
bool ifExists(const bool t[N][N], int n)
{
    UnionFind unionFind(n * n);     // Obiekt z ilością pól równą kwadratowi n

    // Pętle dla kolumn i wierszy
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (t[i][j])    // Sprawdzamy, czy pole nie jest nullem
            {
                // Sprawdzamy, czy w obrębie danego elementu tablicy są inne elementy, potem je scala
                // Dół
                if (i + 1 < n && t[i + 1][j])
                    unionFind.Union(i * n + j, (i + 1) * n + j);
                // Góra
                if (i - 1 >= 0 && t[i - 1][j])
                    unionFind.Union(i * n + j, (i - 1) * n + j);
                // Na prawo
                if (j + 1 < n && t[i][j + 1])
                    unionFind.Union(i * n + j, i * n + j + 1);
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (t[i][0])            // Sprawdzamy czy element istnieje
        {
            for (int j = 0; j < n; j++)     // Wiersze
            {
                // Sprawdzamy czy ścieżka istnieje
                if (t[j][n - 1] && unionFind.Find(i * (n - 1)) == unionFind.Find(j * (n - 1) + (n - 1)))
                {
                    return 1;
                }
            }
        }
    }

    return 0;
}

// 7
int numOfIslands(const bool t[N][N], int n)
{
    UnionFind unionFind(n * n); // Obiekt równy kwadratowi n

    // Pętla dla kolumn i wierszy
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            // Sprawdzamy występowanie 1 w naszego elementu. Jeśli tak, scalamy wyspę.
            if (!t[i][j])
                continue;
            if (i + 1 < n && t[i + 1][j])
            {
                unionFind.Union(i * n + j, (i + 1) * n + j);
            }
            if (i - 1 >= 0 && t[i - 1][j])
            {
                unionFind.Union(i * n + j, (i - 1) * n + j);
            }

            if (j - 1 >= 0 && t[i][j - 1])
            {
                unionFind.Union(i * n + j, i * n + j - 1);
            }

            if (j + 1 < n && t[i][j + 1])
            {
                unionFind.Union(i * n + j, i * n + j + 1);
            }
        }
    }

    bool islands[n * n] = {0};  // Przechowalnia zliczonych wysp zainicjalizowana zerami
    int temp = 0;               // Ilość wysp

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(t[i][j])
            {
                int r = unionFind.Find(i * n + j);  // Szukamy korzenia i sprawiamy, że jest on parentem "i"
                if(!islands[r])                     // Sprawdzamy, czy wyspa znajduje się w kontenerze
                {
                    temp++;                         // Zwiększamy liczbę wysp
                    islands[r] = 1;                 // "Umieszczamy" wyspę w kontenerze
                }
            }
        }
    }

    return temp;
}

int main()
{
    const bool t[N][N] = {{1, 1, 1}, {0, 1, 0}, {0, 0, 1}};
    const bool t2[N][N] = {{1, 0, 1}, {0, 1, 0}, {1, 0, 1}};

    // 6 cd
    std::cout << ifExists(t, N) << std::endl;
    std::cout << ifExists(t2, N) << std::endl;

    // 7 cd
    std::cout << numOfIslands(t, N) << std::endl;
    std::cout << numOfIslands(t2, N) << std::endl;

    return 0;
}
