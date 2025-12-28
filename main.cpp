#include <iostream>
#include <vector>
#include "ListGraph.h"
#include "MatrixGraph.h"
#include "SetGraph.h"
#include "ArcGraph.h"

void PrintGraph(const IGraph& graph) {
    std::cout << "Vertices count: " << graph.VerticesCount() << std::endl;
    for (int i = 0; i < graph.VerticesCount(); ++i) {
        std::cout << i << " -> ";
        for (int next : graph.GetNextVertices(i)) {
            std::cout << next << " ";
        }
        std::cout << " | prev: ";
        for (int prev : graph.GetPrevVertices(i)) {
            std::cout << prev << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl << std::endl;
}

int main() {
    ListGraph list_graph(4);
    list_graph.AddEdge(0, 1);
    list_graph.AddEdge(1, 2);
    list_graph.AddEdge(2, 3);
    list_graph.AddEdge(3, 0);
    list_graph.AddEdge(0, 2);

    std::cout << "ListGraph:" << std::endl;
    PrintGraph(list_graph);

    MatrixGraph matrix_graph(list_graph);
    std::cout << "MatrixGraph (from ListGraph):" << std::endl;
    PrintGraph(matrix_graph);

    SetGraph set_graph(matrix_graph);
    std::cout << "SetGraph (from MatrixGraph):" << std::endl;
    PrintGraph(set_graph);

    ArcGraph arc_graph(set_graph);
    std::cout << "ArcGraph (from SetGraph):" << std::endl;
    PrintGraph(arc_graph);

    return 0;
}
