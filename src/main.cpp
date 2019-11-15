#include "flowsolver.h"


int main(void){

    FlowSolver fs;

    fs.addNode(1);
    fs.addNode(2);
    fs.addEdge(1, 2);


    return 0;
}