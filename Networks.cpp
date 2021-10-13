
//Program that count distance between two nodes of a network

#include <stdlib.h>
#include <stdio.h>

#include "Functions.cpp"        //Have an example network and a distance calculator

int main (void)
{
    //Inicialization
    int first_node, second_node, final_distance;
    
    //Assign memory
    int **network;
    network = (int**) malloc( 10 * sizeof(int*) );  

    //Build a network
    build_10_nodes_network(network);                
    
    //Insert one node of network
    printf("Insert one node of network\n");
    scanf("%d",&first_node);                        

    //Insert other node of network
    printf("Insert other node of network\n");
    scanf("%d", &second_node);                      

    //Calculate the distance between the two nodes
    final_distance = distance(network, first_node, second_node);

    //Show distance
    printf("The distance between node %d and node %d is %d\n", first_node, second_node, final_distance);
    
    free(network);
   
    return 0;
}
