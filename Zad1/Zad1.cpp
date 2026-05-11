#include <iostream>
#include <vector>
enum colors {WHITE, GRAY, BLACK};

class NeighbourMatrix {
    int vertexes;
    std::vector<std::vector<int>> matrix;
    bool directed;

    bool DFS_flag;

    void build_matrix() {
        matrix.resize(vertexes, std::vector<int>(vertexes, 0));
    }
public:
    NeighbourMatrix(int n, int m, bool directed = true) : vertexes(n), directed(directed) { build_matrix(); }
    NeighbourMatrix(int n, bool directed = true) : vertexes(n), directed(directed) { build_matrix(); }
    void add_incidence(int predecessor, int successor) {
        predecessor--;
        successor--;
        matrix[predecessor][successor]++;
        if (!directed)
            matrix[successor][predecessor]++;
    }
    void display() {
        for (int i = 0; i < vertexes; i++) {
            for (int j = 0; j < vertexes; j++) {
                std::cout << matrix[i][j] << ' ';
            }
            std::cout << '\n';
        }
    }
    int get_vertexes_number() { return vertexes; }
    int at(int n, int m) { return matrix[n][m]; }
    void DFS() {
        std::vector<colors> V(vertexes, WHITE);
        DFS_flag = false;
        DFS_visit(0, V);
        for (int i = 0; i < vertexes; i++)
            if (V[i] == WHITE)
                DFS_flag = true;
        std::cout << (DFS_flag ? "NO" : "YES");
    }
protected:
    void DFS_visit(int v, std::vector<colors>& V, int parent = -1) {
        V[v] = GRAY;
        for (int i = 0; i < vertexes; i++) {
            if (matrix[v][i] && i != parent)
                if (V[i] == WHITE && matrix[v][i] == 1) {
                    DFS_visit(i, V, v);
                    if (DFS_flag) break;
                }
                else {
                    DFS_flag = true;
                    break;
                }

        }
        V[v] = BLACK;
    }
    //void display_as_AList() {
    //    for (int i = 0; i < vertexes; i++) {
    //        std::cout << i << ':';
    //        for (int j = 0; j < vertexes; j++)
    //            if (matrix[i][j])
    //                std::cout << ' ' << j;
    //        std::cout << '\n';
    //    }
    //}
};

class AdjacencyList {
    std::vector<std::vector<int>> list;
    int vertexes;

    bool DFS_flag;

public:
    AdjacencyList(NeighbourMatrix& matrix) : vertexes(matrix.get_vertexes_number()){
        list.resize(vertexes);
        for (int i = 0; i < vertexes; i++) {
            for (int j = 0; j < vertexes; j++) {
                if (matrix.at(i, j))
                    for (int k = 0; k < matrix.at(i, j); k++)
                        list.at(i).push_back(j);
            }
        }
    }
    AdjacencyList(int v) :vertexes(v) { list.resize(vertexes); }
    void add_edge(int n, int m) {
        n--, m--;
        list.at(n).push_back(m);
        list.at(m).push_back(n);
    }
    void display() {
        for (int i = 0; i < list.size(); i++) {
            std::cout << i << ':';
            for (int j = 0; j < list.at(i).size(); j++)
                std::cout << ' ' << list.at(i).at(j);
            std::cout << '\n';
        }
    }
    void DFS() {
        std::vector<colors> V(vertexes, WHITE);
        DFS_flag = false;
        DFS_visit(0, V);
        for (int i = 0; i < vertexes; i++)
            if (V[i] == WHITE)
                DFS_flag = true;
        std::cout << (DFS_flag ? "NO" : "YES");
    }
protected:
    void DFS_visit(int v, std::vector<colors>& V, int parent = -1) {
        V[v] = GRAY;
        for (int i = 0; i < list.at(v).size(); i++) {
            if (list[v][i] != parent)
                if (V[list[v][i]] == WHITE) {
                    DFS_visit(list[v][i], V, v);
                    if (DFS_flag) break;
                }
                else {
                    DFS_flag = true;
                    break;
                }

        }
        V[v] = BLACK;
    }

};



int main()
{
    int n, m;
    std::cin >> n >> m;
    NeighbourMatrix matrix(n, m, false);
    //AdjacencyList Alist(n);
    while (std::cin >> n >> m) {
        matrix.add_incidence(n, m);
        //Alist.add_edge(n, m);
    }
    //AdjacencyList Alist(matrix);
    //Alist.DFS();
    matrix.DFS();
    //Alist.display();
    //std::cout << '\n';
    //matrix.display();
}

