#include "ListGraph.h"

ListGraph::ListGraph(int vertices_count)
    : adjacency_lists_(vertices_count), prev_adjacency_lists_(vertices_count) {}

ListGraph::ListGraph(const IGraph& other)
    : adjacency_lists_(other.VerticesCount()), prev_adjacency_lists_(other.VerticesCount()) {
    for (int i = 0; i < other.VerticesCount(); ++i) {
        for (int next : other.GetNextVertices(i)) {
            AddEdge(i, next);
        }
    }
}

void ListGraph::AddEdge(int from, int to) {
    adjacency_lists_[from].push_back(to);
    prev_adjacency_lists_[to].push_back(from);
}

int ListGraph::VerticesCount() const {
    return static_cast<int>(adjacency_lists_.size());
}

std::vector<int> ListGraph::GetNextVertices(int vertex) const {
    return adjacency_lists_[vertex];
}

std::vector<int> ListGraph::GetPrevVertices(int vertex) const {
    return prev_adjacency_lists_[vertex];
}
