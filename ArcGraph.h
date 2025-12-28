#include "IGraph.h"

class ArcGraph : public IGraph {
public:
    explicit ArcGraph(int vertices_count);
    explicit ArcGraph(const IGraph& other);
    virtual ~ArcGraph() override = default;
    ArcGraph(const ArcGraph& other) = default;
    ArcGraph& operator=(const ArcGraph& other) = default;

    void AddEdge(int from, int to) override;
    int VerticesCount() const override;
    std::vector<int> GetNextVertices(int vertex) const override;
    std::vector<int> GetPrevVertices(int vertex) const override;

private:
    struct Edge {
        int from;
        int to;
    };
    std::vector<Edge> edges_;
    int vertices_count_;
};
