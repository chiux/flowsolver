#include "flowsolver.h"
using namespace std;


void FlowSolver::addNode(int i){

    node n = _G.new_node();
    _Node[i] = &n;

    return;
}

void FlowSolver::addEdge(int s, int t){

    node* source = _Node[s];
    node* target = _Node[t];
    edge e = _G.new_edge(*source, *target);

    _Cap.init(_G);
    _Cost.init(_G);
    _Flow.init(_G);

    _Edge[std::pair<int, int>(s, t)] = &e;
    _Cost[e] = 0;
    _Cap[e] = 0;

    return;
}


void FlowSolver::addEdgeCost(int s, int t, int cost){

    edge* e = _Edge[std::pair<int, int>(s, t)];
    _Cost[*e] += cost;

    return;
}



void FlowSolver::addEdgeCapacity(int s, int t, int capacity){

    edge* e = _Edge[std::pair<int, int>(s, t)];
    _Cap[*e] += capacity;

    return;
}

int FlowSolver::getEdgeCapacity(int s, int t){

    edge* e = _Edge[std::pair<int, int>(s, t)];
    
    return _Cap[*e];
}


bool FlowSolver::solveMinCostFlow(int s, int t){

    node* source = _Node[s];
    node* target = _Node[t];

    int flow = leda::MIN_COST_MAX_FLOW(_G, *source, *target, _Cap, _Cost, _Flow);

    return true;

}