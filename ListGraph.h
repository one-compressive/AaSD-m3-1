#include "IGraph.h"

class ListGraph : public IGraph {
public:
    explicit ListGraph(int vertices_count);
    explicit ListGraph(const IGraph& other);
    virtual ~ListGraph() override = default;
    ListGraph(const ListGraph& other) = default;
    ListGraph& operator=(const ListGraph& other) = default;

    void AddEdge(int from, int to) override;
    int VerticesCount() const override;
    std::vector<int> GetNextVertices(int vertex) const override;
    std::vector<int> GetPrevVertices(int vertex) const override;

private:
    std::vector<std::vector<int>> adjacency_lists_;
    std::vector<std::vector<int>> prev_adjacency_lists_;
};
