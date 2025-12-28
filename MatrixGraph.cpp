#include "MatrixGraph.h"

MatrixGraph::MatrixGraph(int vertices_count)
    : matrix_(vertices_count, std::vector<bool>(vertices_count, false)) {}

MatrixGraph::MatrixGraph(const IGraph& other)
    : matrix_(other.VerticesCount(), std::vector<bool>(other.VerticesCount(), false)) {
    for (int i = 0; i < other.VerticesCount(); ++i) {
        for (int next : other.GetNextVertices(i)) {
            AddEdge(i, next);
        }
    }
}

void MatrixGraph::AddEdge(int from, int to) {
    matrix_[from][to] = true;
}

int MatrixGraph::VerticesCount() const {
    return static_cast<int>(matrix_.size());
}

std::vector<int> MatrixGraph::GetNextVertices(int vertex) const {
    std::vector<int> result;
    for (int i = 0; i < static_cast<int>(matrix_.size()); ++i) {
        if (matrix_[vertex][i]) result.push_back(i);
    }
    return result;
}

std::vector<int> MatrixGraph::GetPrevVertices(int vertex) const {
    std::vector<int> result;
    for (int i = 0; i < static_cast<int>(matrix_.size()); ++i) {
        if (matrix_[i][vertex]) result.push_back(i);
    }
    return result;
}
