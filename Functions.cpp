
//DISTANCE CALCULATOR
//Input: network, node 1, node 2 (both nodes must be in network, or the function never ends)
//Output: Distance between node 1 and node 2

int distance(int **network,int initial_node, int final_node)
{
    //Definitions:
    int i,j,distance, node, degree, neighbour;          //Integers
    int next_neighborhood_size ,inspector,path_length;  
    int ring_node,length_ring,next_length_ring;         

    bool must_continue, unknown;                        //Booleans
    int *path,*ring, *next_ring;                        //Integers Pointers

    //Initialize
    must_continue = unknown = true;
    distance = 0;


    //First neighborhood loop:

    if(initial_node != final_node)      //Are both nodes the same?
    {
        distance++;

        node = initial_node - 1;        //Chosen node
        degree = network[node][0];           //Degree

        path = (int*) malloc( sizeof(int*) );      //Allocate memory to save node
        path[0] = node;                     //Save node
        path_length = 1;                    //Save path size

        ring = (int*) malloc( degree * sizeof(int*) );         //Allocate memory. it´s just temporary
        next_ring = (int*) malloc( degree * sizeof(int*) );
        length_ring = next_length_ring = degree;        //Save size of next ring


        for(neighbour = 1;neighbour <= degree;neighbour++ )
        {
            if(network[node][neighbour] == final_node)
            {
                //Condition to finish program
                must_continue = false;
                neighbour = degree + 1;
            }
            else
            {
                ring[neighbour - 1] = network[node][neighbour];
                next_ring[neighbour - 1] = network[node][neighbour];
            }
        }

        //UMPTEENTH NEIGHBORHOOD LOOP:

        while(must_continue)
        {
            distance++;

            //Upgrade ring to inspect:

            //Save nodes from old ring in path:

            path = (int*) realloc(path,(path_length + length_ring) * sizeof(int));

            for(ring_node=0;ring_node < length_ring;ring_node++)
            {
                path[path_length + ring_node] = ring[ring_node];
            }

            path_length = path_length + length_ring;

            //Reset old ring:
            free(ring);
            ring = (int*) malloc((next_length_ring) * sizeof(int*));

            //Turn next ring into ring 
            for(ring_node=0;ring_node<next_length_ring;ring_node++)
            {
                ring[ring_node] = next_ring[ring_node];
            }
            length_ring = next_length_ring;

            //Reset next ring:
            next_length_ring = 0;
            free(next_ring);
            next_ring = (int*) malloc( sizeof(int*));

            //INSPECT THE RING:
            for(ring_node=0;ring_node<length_ring;ring_node++)
            {

                node = ring[ring_node]-1;
                degree = network[node][0];
                for(neighbour = 1; neighbour <= degree; neighbour ++)   //inspect neighbours of node
                {
                    //Is node already in path?
                    unknown = true;
                    for(inspector = 0; inspector < path_length; inspector++)
                    {
                        if(path[inspector] == network[node][neighbour])  //
                        {
                           unknown = false;
                           inspector = path_length;
                        }
                    }

                    if(unknown)     //When node is unknown:
                    {
                        if(network[node][neighbour] == final_node)      //Is this node the searched node? 
                        {
                            //Pongo condiciones para terminar programa
                            inspector = path_length;
                            neighbour = degree + 1;
                            ring_node = length_ring;
                            must_continue = false;
                        }
                        else
                        {
                            //Add this node´s neighbour to next ring:
                            next_ring = (int*) realloc(next_ring,(next_length_ring + 1) * sizeof(int));
                            next_ring[next_length_ring] = network[node][neighbour];
                            next_length_ring++;
                        }
                    }
                }
            }
        }

    }
    else
    {
        must_continue = false;
    }

    //Warning message when nodes are not linked:
    if(must_continue)
    {
        printf("Warning: The nodes are not linked");
        distance = -10;
    }

    free(path);
    free(ring);
    free(next_ring);

    return distance;
}

//EXAMPLE NETWORK BUILDER
void build_10_nodes_network(int **network)
    {
    network[0] = (int*) malloc( 3 * sizeof(int) );  //node 1
    network[1] = (int*) malloc( 2 * sizeof(int) );  //node 2
    network[2] = (int*) malloc( 3 * sizeof(int) );  //node 3
    network[3] = (int*) malloc( 3 * sizeof(int) );  //node 4
    network[4] = (int*) malloc( 4 * sizeof(int) );  //node 5
    network[5] = (int*) malloc( 3 * sizeof(int) );  //node 6
    network[6] = (int*) malloc( 2 * sizeof(int) );  //node 7
    network[7] = (int*) malloc( 3 * sizeof(int) );  //node 8
    network[8] = (int*) malloc( 3 * sizeof(int) );  //node 9
    network[9] = (int*) malloc( 2 * sizeof(int) );  //node 10

    //node 1
    network[0][0] = 2;  //degree
    network[0][1] = 2;
    network[0][2] = 3;
    //node 2
    network[1][0] = 1;  //degree
    network[1][1] = 1;
    //node 3
    network[2][0] = 2;  //degree
    network[2][1] = 1;
    network[2][2] = 4;
    //node 4
    network[3][0] = 2;  //degree
    network[3][1] = 3;
    network[3][2] = 5;
    //node 5
    network[4][0] = 3;  //degree
    network[4][1] = 4;
    network[4][2] = 6;
    network[4][3] = 8;
    //node 6
    network[5][0] = 2;  //degree
    network[5][1] = 5;
    network[5][2] = 7;
    //node 7
    network[6][0] = 1;  //degree
    network[6][1] = 6;
    //node 8
    network[7][0] = 2;  //degree
    network[7][1] = 5;
    network[7][2] = 9;
    //node 9
    network[8][0] = 2;  //degree
    network[8][1] = 8;
    network[8][2] = 10;
    //node 10
    network[9][0] = 1;  //degree
    network[9][1] = 9;

    }


//FUNCTION TO NOW IF TWO NODES ARE NEIGHBOURS
bool distance_equal_one(int **network, int initial_node, int final_node)
{
    //Definitions:
    int node, degree, neighbour;    //Integers
    bool are_neighbours;                  //Booleans

    //Initialize
    are_neighbours = false;

    //First neighborhood loop:

    if(initial_node != final_node)      //Are both nodes the same?
    {
        node = initial_node - 1;        //node to check
        degree = network[node][0];           //degree

        for(neighbour = 1;neighbour <= degree;neighbour++ )
        {
            if(network[node][neighbour] == final_node)
            {
                //Condition to finish program
                are_neighbours = true;
                neighbour = degree + 1;
            }
        }

    }
    return are_neighbours;
}
