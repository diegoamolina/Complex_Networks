    //Test network 2

    network = malloc( 20 * sizeof(int*) );
    network[0] = (int*) malloc( 3 * sizeof(int) );  //node 1
    network[1] = (int*) malloc( 3 * sizeof(int) );  //node 2
    network[2] = (int*) malloc( 4 * sizeof(int) );  //node 3
    network[3] = (int*) malloc( 5 * sizeof(int) );  //node 4
    network[4] = (int*) malloc( 4 * sizeof(int) );  //node 5
    network[5] = (int*) malloc( 2 * sizeof(int) );  //node 6
    network[6] = (int*) malloc( 3 * sizeof(int) );  //node 7
    network[7] = (int*) malloc( 3 * sizeof(int) );  //node 8
    network[8] = (int*) malloc( 3 * sizeof(int) );  //node 9
    network[9] = (int*) malloc( 3 * sizeof(int) );  //node 10
    network[10] = (int*) malloc( 3 * sizeof(int) );  //node 11
    network[11] = (int*) malloc( 2 * sizeof(int) );  //node 12
    network[12] = (int*) malloc( 2 * sizeof(int) );  //node 13
    network[13] = (int*) malloc( 4 * sizeof(int) );  //node 14
    network[14] = (int*) malloc( 2 * sizeof(int) );  //node 15
    network[15] = (int*) malloc( 3 * sizeof(int) );  //node 16
    network[16] = (int*) malloc( 4 * sizeof(int) );  //node 17
    network[17] = (int*) malloc( 2 * sizeof(int) );  //node 18
    network[18] = (int*) malloc( 2 * sizeof(int) );  //node 19
    network[19] = (int*) malloc( 2 * sizeof(int) );  //node 20

    //node 1
    network[0][0] = 3;  //degre
    network[0][1] = 2;
    network[0][2] = 3;
    network[0][3] = 4;
    //node 2
    network[1][0] = 3;  //degre
    network[1][1] = 1;
    network[1][2] = 4;
    network[1][3] = 5;
    //node 3
    network[2][0] = 4;  //degre
    network[2][1] = 1;
    network[2][2] = 4;
    network[2][3] = 9;
    network[2][4] = 14;
    //node 4
    network[3][0] = 5;  //degre
    network[3][1] = 1;
    network[3][2] = 2;
    network[3][3] = 3;
    network[3][4] = 7;
    network[3][5] = 9;
    //node 5
    network[4][0] = 4;  //degre
    network[4][1] = 2;
    network[4][2] = 6;
    network[4][3] = 7;
    network[4][4] = 10;
    //node 6
    network[5][0] = 2;  //degre
    network[5][1] = 5;
    network[5][2] = 8;
    //node 7
    network[6][0] = 3;  //degre
    network[6][1] = 4;
    network[6][2] = 5;
    network[6][3] = 8;
    //node 8
    network[7][0] = 3;  //degre
    network[7][1] = 6;
    network[7][2] = 7;
    network[7][3] = 17;
    //node 9
    network[8][0] = 4;  //degre
    network[8][1] = 3;
    network[8][2] = 4;
    network[8][3] = 10;
    network[8][4] = 11;
    //node 10
    network[9][0] = 3;  //degre
    network[9][1] = 5;
    network[9][2] = 9;
    network[9][3] = 12;
    //node 11
    network[10][0] = 3;  //degre
    network[10][1] = 9;
    network[10][2] = 12;
    network[10][3] = 14;
    //node 12
    network[11][0] = 2;  //degre
    network[11][1] = 10;
    network[11][2] = 11;
    //node 13
    network[12][0] = 2;  //degre
    network[12][1] = 14;
    network[12][2] = 15;
    //node 14
    network[13][0] = 4;  //degre
    network[13][1] = 3;
    network[13][2] = 11;
    network[13][3] = 13;
    network[13][4] = 16;
    //node 15
    network[14][0] = 2;  //degre
    network[14][1] = 13;
    network[14][2] = 16;
    //node 16
    network[15][0] = 3;  //degre
    network[15][1] = 14;
    network[15][2] = 15;
    network[16][3] = 17;
    //node 17
    network[16][0] = 4;  //degre
    network[16][1] = 8;
    network[16][2] = 16;
    network[16][3] = 18;
    network[16][4] = 19;
    //node 18
    network[17][0] = 2;  //degre
    network[17][1] = 17;
    network[17][2] = 20;
    //node 19
    network[18][0] = 2;  //degre
    network[18][1] = 17;
    network[18][2] = 20;
    //node 20
    network[19][0] = 2;  //degre
    network[19][1] = 19;
    network[19][2] = 18;