#include "IGraph.h"
#include <unordered_set>

class SetGraph : public IGraph {
public:
    explicit SetGraph(int vertices_count);
    explicit SetGraph(const IGraph& other);
    virtual ~SetGraph() override = default;
    SetGraph(const SetGraph& other) = default;
    SetGraph& operator=(const SetGraph& other) = default;

    void AddEdge(int from, int to) override;
    int VerticesCount() const override;
    std::vector<int> GetNextVertices(int vertex) const override;
    std::vector<int> GetPrevVertices(int vertex) const override;

private:
    std::vector<std::unordered_set<int>> adjacency_sets_;
    std::vector<std::unordered_set<int>> prev_adjacency_sets_;
};
