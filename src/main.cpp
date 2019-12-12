#include "flowsolver.h"
using namespace std;

void testsolver(FlowSolver &fs){


    // construct graph
    for(int i = 1; i <= 6; ++i){
        fs.addNode(i);
    }
    fs.addEdge(1, 2);
    fs.addEdge(1, 3);
    fs.addEdge(2, 3);
    fs.addEdge(2, 4);
    fs.addEdge(3, 4);
    fs.addEdge(3, 5);
    fs.addEdge(4, 5);
    fs.addEdge(4, 6);
    fs.addEdge(5, 4);
    fs.addEdge(5, 6);

    // intialize edge arrays for capacity, cost and flow
    fs.initEdgeArrays();


    // add capacity 
    fs.addEdgeCapacity(1, 2, 9);
    fs.addEdgeCapacity(1, 3, 9);
    fs.addEdgeCapacity(2, 3, 8);
    fs.addEdgeCapacity(2, 4, 3);
    fs.addEdgeCapacity(3, 4, 7);
    fs.addEdgeCapacity(3, 5, 7);
    fs.addEdgeCapacity(4, 5, 2);
    fs.addEdgeCapacity(4, 6, 9);
    fs.addEdgeCapacity(5, 4, 4);
    fs.addEdgeCapacity(5, 6, 8);

    int golden = 17;
    int ans = fs.solveMinCostFlow(1,6);

    if(ans==golden){
        cout << "[Success] maximum flow correct!" << endl;
    }

    return;

}

int main(void){

    FlowSolver fs;

    testsolver(fs);
    fs.printEdge();

    return 0;
}