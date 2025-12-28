#include "ArcGraph.h"

ArcGraph::ArcGraph(int vertices_count) : vertices_count_(vertices_count) {}

ArcGraph::ArcGraph(const IGraph& other) : vertices_count_(other.VerticesCount()) {
    for (int i = 0; i < other.VerticesCount(); ++i) {
        for (int next : other.GetNextVertices(i)) {
            AddEdge(i, next);
        }
    }
}

void ArcGraph::AddEdge(int from, int to) {
    edges_.push_back({from, to});
}

int ArcGraph::VerticesCount() const {
    return vertices_count_;
}

std::vector<int> ArcGraph::GetNextVertices(int vertex) const {
    std::vector<int> result;
    for (const auto& edge : edges_) {
        if (edge.from == vertex) result.push_back(edge.to);
    }
    return result;
}

std::vector<int> ArcGraph::GetPrevVertices(int vertex) const {
    std::vector<int> result;
    for (const auto& edge : edges_) {
        if (edge.to == vertex) result.push_back(edge.from);
    }
    return result;
}
