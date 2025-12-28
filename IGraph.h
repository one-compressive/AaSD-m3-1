/*
Задача 1. «Представление графа».
Дан базовый интерфейс для представления ориентированного графа.
Необходимо написать несколько реализаций интерфейса:
ListGraph, MatrixGraph, SetGraph, ArcGraph.
*/

#include <vector>

struct IGraph {
    virtual ~IGraph() {}
    virtual void AddEdge(int from, int to) = 0;
    virtual int VerticesCount() const = 0;
    virtual std::vector<int> GetNextVertices(int vertex) const = 0;
    virtual std::vector<int> GetPrevVertices(int vertex) const = 0;
};
