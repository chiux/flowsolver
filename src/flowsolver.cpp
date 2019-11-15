#include "flowsolver.h"


void FlowSolver::addNode(int i){

    node n = _G.add_node();
    _Node[i] = n;

    return;
}

void FlowSolver::addEdge(int s, int t){

    node source = _Node[s];
    node target = _Node[t];
    edge e = _G.new_edge(source, target);

    _Edge[std::pair<int, int>(s, t)] = e;
    _Cost[e] = 0.0;
    _Capacity[e] = 0;

    return;
}


void FlowSolver::addEdgeCost(int s, int t, double cost){

    edge e = _Edge[std::pair<int, int>(s, t)];
    _Cost[e] += cost;

    return;
}



void FlowSolver::addEdgeCapacity(int s, int t, int capacity){

    edge e = _Edge[std::pair<int, int>(s, t)];
    _Capacity[e] += capacity;

    return;
}


bool FlowSolver::solveMinCostFlow(int s, int t){

    node source = _Node[s];
    node target = _Node[t];

    return MIN_COST_MAX_FLOW(&_G, source, target, &_Cap, &_Cost, &_Flow);
}