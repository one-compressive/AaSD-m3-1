#include "IGraph.h"

class MatrixGraph : public IGraph {
public:
    explicit MatrixGraph(int vertices_count);
    explicit MatrixGraph(const IGraph& other);
    virtual ~MatrixGraph() override = default;
    MatrixGraph(const MatrixGraph& other) = default;
    MatrixGraph& operator=(const MatrixGraph& other) = default;

    void AddEdge(int from, int to) override;
    int VerticesCount() const override;
    std::vector<int> GetNextVertices(int vertex) const override;
    std::vector<int> GetPrevVertices(int vertex) const override;

private:
    std::vector<std::vector<bool>> matrix_;
};
