#include <stdlib.h>
#include <stdio.h>

#include "Test Network 1.c"
#include "Functions.c"

int main (void)
{
    int first_node, second_node, final_distance;

    printf("Insert one node of network\n");
    scanf("%d",first_node);

    printf("Insert other node of network\n");
    scanf("%d", second_node);

    final_distance = distance(network, first_node, second_node);
    printf("The distance between node %d and node %d is %d\n", first_node, second_node, final_distance);

    return 0;

}
