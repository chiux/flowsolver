#include "flowsolver.h"
using namespace std;

int main(void){

    FlowSolver fs;

    fs.addNode(1);
    fs.addNode(2);
    fs.addEdge(1, 2);
    fs.addEdgeCapacity(1, 2, 8);



    return 0;
}