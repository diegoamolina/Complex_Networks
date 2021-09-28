//FUNCION CALCULADORA DE distanceS
//Los nodes inicial y final deben estar en la red o se ejecuta indefinidamente

//Distance Calculator 
//Input: network, node 1, node 2 (both nodes must be in network, or the function never ends)
//Output: Distance between node 1 and node 2

int distance(int **IN,int initial_node, int final_node, int N)
{
    //Definitions:
    int i,j,distance, node, degree, neighbour,next_neighborhood_size ,inspector,path_length;  //Integers
    int ring_node,length_ring,next_length_ring;    //Integers
    bool must_continue, unknown;             //Booleans
    int *path,*ring, *next_ring;   //Integers Pointers

    //Initialize
    must_continue = unknown = true;
    distance = 0;


    //First Neighborhood loop:

    if(initial_node != final_node)      //Are both nodes the same?
    {
        distance++;

        node = initial_node - 1;        //chosen node
        degree = IN[node][0];     //degree

        path = malloc( sizeof(int*) );    //allocate memory to save node
        path[0] = node;       //save node
        path_length = 1;        //save path size

        ring = malloc( degree * sizeof(int*) );     //allocate memory. it´s just temporary
        next_ring = malloc( degree * sizeof(int*) );
        length_ring = next_length_ring = degree;       //save size of next ring length guardo el tama�o del pr�ximo vecindario


        for(neighbour = 1;neighbour <= degree;neighbour++ )
        {
            if(IN[node][neighbour] == final_node)
            {
                //pongo condiciones para terminar programa
                must_continue = false;
                neighbour = degree + 1;
            }
            else
            {
                ring[neighbour - 1] = IN[node][neighbour];
                next_ring[neighbour - 1] = IN[node][neighbour];
            }
        }

        //BUCLE PARA EL VECINDARIO N-ESIMO:

        while(must_continue)
        {
            distance++;

            //actualizo el anillo a recorrer:

            //guardo nodes del anillo viejo en path:

            path = realloc(path,(path_length + length_ring) * sizeof(int));

            for(ring_node=0;ring_node < length_ring;ring_node++)
            {
                path[path_length + ring_node] = ring[ring_node];
            }


            path_length = path_length + length_ring;

            //reinicio anillo viejo:
            free(ring);
            ring = malloc((next_length_ring) * sizeof(int*));

            //convierto next_ring en anillo:
            for(ring_node=0;ring_node<next_length_ring;ring_node++)
            {
                ring[ring_node] = next_ring[ring_node];
            }
            length_ring = next_length_ring;

            //reinicio next_ring
            next_length_ring = 0;
            free(next_ring);
            next_ring = malloc( sizeof(int*));

            //RECORRO EL ANILLO
            for(ring_node=0;ring_node<length_ring;ring_node++)
            {

                node = ring[ring_node]-1;
                degree = IN[node][0];
                for(neighbour = 1; neighbour <= degree; neighbour ++)   //recorro los neighbours de node
                {
                    //Reviso si ya pas� antes por node:
                    unknown = true;
                    for(inspector = 0; inspector < path_length; inspector++)
                    {
                        if(path[inspector] == IN[node][neighbour])  //
                        {
                           unknown = false;
                           inspector = path_length;
                        }
                    }

                    if(unknown)     //Si node no est� en path:
                    {
                        if(IN[node][neighbour] == final_node)      //verifico si es el node que busco
                        {
                            //Pongo condiciones para terminar programa
                            inspector = path_length;
                            neighbour = degree + 1;
                            ring_node = length_ring;
                            must_continue = false;
                        }
                        else
                        {
                            //Agrego este neighbour de node al pr�ximo anillo:

                            next_ring = realloc(next_ring,(next_length_ring + 1) * sizeof(int));
                            next_ring[next_length_ring] = IN[node][neighbour];
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

    //Mensaje de error cuando los nodes no est�n conectados:
    if(must_continue)
    {
        printf("Advertencia: Los nodes no est�n conectados");
        distance = -10;
    }


    return distance;
}

bool distance_igual_uno(int **IN,int initial_node, int final_node)
{
    //Definiciones:
    int node, degree, neighbour;  //Enteros
    bool distance;             //Booleanos

    //Inicializar
    distance = false;

    //BUCLE PARA EL PRIMER VECINDARIO:

    if(initial_node != final_node)      //verifico si son el mismo node
    {
        node = initial_node - 1;        //node a recorrer
        degree = IN[node][0];     //vecindario

        for(neighbour = 1;neighbour <= degree;neighbour++ )
        {
            if(IN[node][neighbour] == final_node)
            {
                //pongo condiciones para terminar programa
                distance = true;
                neighbour = degree + 1;
            }
        }

    }
    return distance;
}
