#include <iostream>
#include <vector>
#include <utility> // for pair

using namespace std;
void testWeightedGraph();
void testGraph();

class WeightedGraph{
public:
    vector< vector< pair<int, int> > > adjList;

    WeightedGraph(int numNodes) {
        adjList.resize(numNodes);
    }
    void connect(int fatherNode, int childNode, int weight) {
        adjList[fatherNode].push_back(make_pair(childNode, weight));
    }
    void printWeightedGraph() { // o(n^2) 
        for (int i = 0; i < adjList.size(); i++) {
            cout << "Node " << i << " -> ";

            for (int j = 0; j < adjList[i].size(); j++) {
                cout << adjList[i][j].first << " ";
            }
            cout << endl;
            /*for (pair<int, int> vecino : adjList[i]) { // doesnt work for c++ v<11
                cout << vecino.first << " ";
            }*/
            
        }   
    }
};

class graph {
public:
    vector< vector<int> > adjList;

    graph(int numNodes) {
        adjList.resize(numNodes);
    }

    void connect(int fatherNode, int childNode) {
        adjList[fatherNode].push_back(childNode);
    }

    void printGraph() {
        for (int i = 0; i < adjList.size(); i++) {
            cout << "Node " << i << " -> ";
            for (int j = 0; j < adjList[i].size(); j++) {
                cout << adjList[i][j] << " ";
            }
            cout << endl;
            
            /*for (int vecino : adjList[j]) {
                cout << vecino << " ";
            }*/
            
        }
    }
};

/*void testGraph(){

    //test example
    int numNodes = 5;
    graph graph(numNodes);
    graph.connect(0, 1);
    graph.connect(0, 2);
    graph.connect(1, 3);
    graph.connect(2, 4);
    graph.connect(4, 4);
    graph.printGraph();
    cout<< "-------------------"<<endl;
}*/

/*void  testWeightedGraph(){
    int numNodes = 5;
    WeightedGraph graph(numNodes);
    graph.connect(0, 1, 5); // conn 0 to 1, weight 5
    graph.connect(0, 2, 3); // if you dont want a node to be conect to any other node just dont call the connect method
    graph.connect(1, 3, 2);
    graph.printWeightedGraph();
                            
}*/

void createWeightedGraph(){
    int numNodes;
    cout<< "How many nodes do you want to create?"<<endl;
    cin>> numNodes;
    WeightedGraph graph(numNodes);
    int fatherNode;
    int childNode;
    int weight;
    int option;
    do{
        cout<< "Choose 1 if you want to connect a node to another node "<<endl;
        cout<< "Choose 2 if you want to print the graph "<<endl;
        cout<< "Choose 3 if you want to exit"<<endl;        
        cin>> option;
        if (option == 1){
            cout<< "Choose the father node"<<endl;
            cin>> fatherNode;
            cout<< "Choose the child node"<<endl;
            cin>> childNode;
            cout<< "Choose the weight"<<endl;
            cin>> weight;
            graph.connect(fatherNode, childNode, weight);
        }else if (option == 2){
            graph.printWeightedGraph();
        }
    }while(option != 3);
}

void createGraph(){

    int numNodes;
    cout<< "How many nodes do you want to create?"<<endl;
    cin>> numNodes;
    graph graph(numNodes);
    int fatherNode;
    int childNode;
    int option;
    do{
        cout<< "Choose 1 if you want to connect a node to another node "<<endl;
        cout<< "Choose 2 if you want to print the graph "<<endl;
        cout<< "Choose 3 if you want to exit"<<endl;
        cin>> option;
        if (option == 1){
            cout<< "Choose the father node"<<endl;
            cin>> fatherNode;
            cout<< "Choose the child node"<<endl;
            cin>> childNode;
            graph.connect(fatherNode, childNode);
        }else if (option == 2){
            graph.printGraph();
        }
    }while(option != 3); 
}

int main() {

    //testWeightedGraph();
    //testGraph();
    int option;
    cout<< "Choose 1 if you want to create a weighted graph or 2 if you want to create a normal graph"<<endl;
    cin>> option;
    if (option == 1){
        createWeightedGraph();
    }else if (option == 2){
        createGraph();
    };  
    return 0;
}



