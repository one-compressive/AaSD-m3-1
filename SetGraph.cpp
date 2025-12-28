#include "SetGraph.h"

SetGraph::SetGraph(int vertices_count)
    : adjacency_sets_(vertices_count), prev_adjacency_sets_(vertices_count) {}

SetGraph::SetGraph(const IGraph& other)
    : adjacency_sets_(other.VerticesCount()), prev_adjacency_sets_(other.VerticesCount()) {
    for (int i = 0; i < other.VerticesCount(); ++i) {
        for (int next : other.GetNextVertices(i)) {
            AddEdge(i, next);
        }
    }
}

void SetGraph::AddEdge(int from, int to) {
    adjacency_sets_[from].insert(to);
    prev_adjacency_sets_[to].insert(from);
}

int SetGraph::VerticesCount() const {
    return static_cast<int>(adjacency_sets_.size());
}

std::vector<int> SetGraph::GetNextVertices(int vertex) const {
    return std::vector<int>(adjacency_sets_[vertex].begin(), adjacency_sets_[vertex].end());
}

std::vector<int> SetGraph::GetPrevVertices(int vertex) const {
    return std::vector<int>(prev_adjacency_sets_[vertex].begin(), prev_adjacency_sets_[vertex].end());
}
