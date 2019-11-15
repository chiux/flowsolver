#include </work/LEDA/graph/graph.h>
#include <map>


class FlowSolver{

    public:
        FlowSolver(){
            _Cap.init(&_G);
            _Cost.init(&_G);
            _Flow.init(&_G);
        }
        void addNode(int i);
        void addEdge(int s, int t);
        void addEdgeCost(int s, int t, double cost);
        void addEdgeCapacity(int s, int t, int capacity);
        bool solveMinCostFlow(int s, int t);

    
    private:
        graph _G;
        map <int, node> _Node;
        map < <int, int>, edge > _Edge;
        edge_array<int> _Cap;
        edge_array<double> _Cost;
        edge_array<int> _Flow;

}