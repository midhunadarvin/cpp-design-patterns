#include <iostream>
#include "model/Graph.h"
#include "model/DAG.h"
#include "model/Tree.h"
#include "parser/XmlTreeParser.h"
#include "commands/CommandAttributes.h"
#include "parser/XmlWorkflowParser.h"
#include "execution-engine/WorkflowExecutor.h"

template class Vertex<int>;
template class Graph<int>;

int main(int argc, char * argv[]) {
    DAG<int> graph;

    // Add vertices
    graph.insertVertex(0);
    graph.insertVertex(1);
    graph.insertVertex(2);
    graph.insertVertex(3);
    graph.insertVertex(4);

    // Add directed edges to the graph
    graph.insertEdge(0, 1);
    graph.insertEdge(0, 4);
    graph.insertEdge(1, 2);
    graph.insertEdge(1, 3);
    graph.insertEdge(1, 4);
    graph.insertEdge(2, 3 );
    graph.insertEdge(3, 4);

    graph.printGraph();

    DAG<int> dag;

    // Add vertices
    dag.insertVertex(0);
    dag.insertVertex(1);
    dag.insertVertex(2);
    dag.insertVertex(3);
    dag.insertVertex(4);
    dag.insertVertex(5);

    // Add directed edges to the DAG
    dag.insertEdge(0, 1);
    dag.insertEdge(0, 2);
    dag.insertEdge(1, 3);
    dag.insertEdge(2, 3);
    dag.insertEdge(2, 4);
    dag.insertEdge(3, 5);
    dag.insertEdge(4, 5);

    // Perform a topological sort and print the order
    dag.topologicalSort();

    // Example usage
    Tree<std::string> myTree("Root");

    TreeNode<std::string>* child1 = myTree.addChild(myTree.getRoot(), "Child 1");
    myTree.addChild(child1, "Grandchild 1");
    myTree.addChild(child1, "Grandchild 2");

    TreeNode<std::string>* child2 = myTree.addChild(myTree.getRoot(), "Child 2");

    // Print the tree
    std::cout << "Tree: " << std::endl;
    myTree.printTree();

    XmlTreeParser xmlTreeParser;
    Tree<std::string> *sampleTree = xmlTreeParser.parse("../sample-tree.xml");
    std::cout << "Tree: " << std::endl;
    sampleTree->printTree();

    // Workflow Execution

    XmlWorkflowParser xmlWorkflowParser;
    std::vector<std::vector<CommandAttributes> > result = xmlWorkflowParser.parse("../sample-workflow.xml");
    WorkflowExecutor workflowExecutor(result);
    workflowExecutor.execute();

}
