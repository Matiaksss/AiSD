

#include <iostream>
#include <vector>

class NeighbourMatrix {
    int vertexes;
    int edges;
    int** matrix;
    void build_matrix() {
        matrix = new int* [vertexes];
        for (int i = 0; i < vertexes; i++) {
            matrix[i] = new int[vertexes]();
        }
    }
public:
    NeighbourMatrix(int n, int m) : vertexes(n), edges(m) {
        build_matrix();
    }
    ~NeighbourMatrix() {
        for (int i = 0; i < vertexes; i++)
            delete[] matrix[i];
        delete[] matrix;
    }
    void add_incidence(int predecessor, int successor) { matrix[predecessor][successor] = 1; }
    void display() {
        for (int i = 0; i < vertexes; i++) {
            for (int j = 0; j < vertexes; j++) {
                std::cout << matrix[i][j] << ' ';
            }
            std::cout << '\n';
        }
    }

    void display_as_AList() {
        for (int i = 0; i < vertexes; i++) {
            std::cout << i << ':';
            for (int j = 0; j < vertexes; j++)
                if (matrix[i][j])
                    std::cout << ' ' << j;
            std::cout << '\n';
        }
    }
};

class AdjacencyList {

};


int main()
{
    int n, m;
    std::cin >> n >> m;
    NeighbourMatrix matrix(n, m);
    while (std::cin >> n >> m) {
        matrix.add_incidence(n, m);
    }
    matrix.display_as_AList();
    std::cout << '\n';
    matrix.display();
}

// Uruchomienie programu: Ctrl + F5 lub menu Debugowanie > Uruchom bez debugowania
// Debugowanie programu: F5 lub menu Debugowanie > Rozpocznij debugowanie

// Porady dotyczące rozpoczynania pracy:
//   1. Użyj okna Eksploratora rozwiązań, aby dodać pliki i zarządzać nimi
//   2. Użyj okna programu Team Explorer, aby nawiązać połączenie z kontrolą źródła
//   3. Użyj okna Dane wyjściowe, aby sprawdzić dane wyjściowe kompilacji i inne komunikaty
//   4. Użyj okna Lista błędów, aby zobaczyć błędy
//   5. Wybierz pozycję Projekt > Dodaj nowy element, aby utworzyć nowe pliki kodu, lub wybierz pozycję Projekt > Dodaj istniejący element, aby dodać istniejące pliku kodu do projektu
//   6. Aby w przyszłości ponownie otworzyć ten projekt, przejdź do pozycji Plik > Otwórz > Projekt i wybierz plik sln
