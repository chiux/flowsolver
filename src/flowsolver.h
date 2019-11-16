#include <map>
#include <LEDA/graph/graph.h>
#include <LEDA/graph/min_cost_flow.h>
using namespace leda;


class FlowSolver{

    public:
        FlowSolver(){
            _Cap.init(_G);
            _Cost.init(_G);
            _Flow.init(_G);
        }
        void addNode(int i);
        void addEdge(int s, int t);
        void addEdgeCost(int s, int t, int cost);
        void addEdgeCapacity(int s, int t, int capacity);
        bool solveMinCostFlow(int s, int t);

    
    private:
        graph _G;
        std::map < int, node* > _Node;
        std::map < std::pair<int, int>, edge* > _Edge;
        edge_array<int> _Cap;
        edge_array<int> _Cost;
        edge_array<int> _Flow;

};