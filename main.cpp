#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    int A_FISH = -1;
    int A_SHARK = 5;
    int IS_EMPTY = 0;
    int ARRAY_X_SIZE = 10;
    int ARRAY_Y_SIZE = 5;


    int RIGHT = 0;
    int LEFT = 1;
    int DOWN = 2;
    int UP = 3;
    int RFISH = 2; //reproduction
    int RSHARK = 0; //reproduction


  int xSize;
  int ySize;
  int ocean [ARRAY_X_SIZE][ARRAY_Y_SIZE];
  int nextocean [ARRAY_X_SIZE][ARRAY_Y_SIZE];
  int months = 20;



  // assign array of dots
  for (ySize= 0;ySize< ARRAY_Y_SIZE;ySize++)
  {
    for (xSize= 0; xSize < ARRAY_X_SIZE; xSize++)
   {
      ocean [xSize][ySize] = IS_EMPTY;

   }
  }

  srand(time(0));
  int cfish; //column fish
  int rfish; // row fish
  int cshark; //column shark
  int rshark; //row shark


  int x;
  int y;
  int z;
  int numfish = 0;
  int numshark = 0;
  int numofCellsContainingaShark;
  int numofCellsContainingaFish;
  numofCellsContainingaFish = rand() % (ARRAY_X_SIZE * ARRAY_Y_SIZE); //generates the random number of fishes to put in the array
  numofCellsContainingaShark = rand() % (ARRAY_X_SIZE * ARRAY_Y_SIZE); //generates the random number of sharks to put in the array


  //assign the placement of the fishes
  for (x=0; x<numofCellsContainingaFish; x++)
  {
      cfish= rand() % ARRAY_X_SIZE;
      rfish = rand() % ARRAY_Y_SIZE;
      ocean [cfish][rfish] = A_FISH;
  }



  //assign the placement of the sharks
  for (y=0; y<numofCellsContainingaShark; y++)
  {
      cshark = rand() % ARRAY_X_SIZE;
      rshark = rand() % ARRAY_Y_SIZE;
      ocean [cshark][rshark] = A_SHARK;

  }

  //print out the ocean array with fish and dots and sharks
  for (ySize=0;ySize< ARRAY_Y_SIZE;ySize++)
  {
    for (xSize=0; xSize < ARRAY_X_SIZE; xSize++)
      {
          if(ocean [xSize][ySize]  == A_FISH)
          {
              cout << 'f';
              numfish++;
          }
          if(ocean [xSize][ySize] > 0)
          {
              cout << 'S';
              numshark++;
          }
          if(ocean [xSize][ySize] == IS_EMPTY)
              cout << '.';
      }
       cout<< endl;
  }

cout << endl;

//months for loop
for (z=0; z < months; z++)
{
    //cout <<"Ocean state, Month" << z << " "<< numfish<< "Fish, " << numshark << "Shark" << endl;

//NEXT OCEAN ARRAY


// copies contents of ocean to next ocean
for (ySize=0;ySize< ARRAY_Y_SIZE;ySize++)
{
  for (xSize=0; xSize < ARRAY_X_SIZE; xSize++)
 {
    nextocean [xSize][ySize] = ocean [xSize][ySize];

 }
}

/*
//prints out the  nextocean array with fish and dots and sharks
for (ySize=0;ySize<ARRAY_Y_SIZE;ySize++)
{
  for (xSize=0; xSize < ARRAY_X_SIZE; xSize++)
            {
                if(nextocean [xSize][ySize]  == A_FISH)
                    cout << 'f';
                if(nextocean [xSize][ySize] >= A_SHARK)
                     cout << 'S';
                if(nextocean [xSize][ySize] == IS_EMPTY)
                    cout << '.';
            }
            cout<< endl;
  }

*/


int direction;


//this whole entire double for loop moves the fishes and sharks
for (ySize=0; ySize < ARRAY_Y_SIZE; ySize++)
{
  for (xSize=0; xSize < ARRAY_X_SIZE; xSize++)
  {
        direction = rand() % 4;

        if (ocean [xSize][ySize]  == A_FISH && xSize < (ARRAY_X_SIZE - 1) && direction == RIGHT)
        {
            if ( nextocean[xSize + 1][ySize] == IS_EMPTY)
         {
                nextocean [xSize + 1][ySize] = nextocean [xSize][ySize];
                if (rand() % RFISH == 0)
                //if(rand()%100 >= RFISH)
                nextocean [xSize][ySize] = IS_EMPTY;

                else nextocean[xSize][ySize] = A_FISH;
         xSize++;
         }

        }

        if (ocean [xSize][ySize]  == A_FISH && xSize != 0 && direction == LEFT)
        {
            if (nextocean[xSize - 1][ySize] == IS_EMPTY)
        {
            nextocean [xSize - 1][ySize] = nextocean [xSize][ySize];
            if (rand() % RFISH == 0)
            //if(rand()%100>=RFISH)
            nextocean [xSize][ySize] = IS_EMPTY;

            else nextocean[xSize][ySize] = A_FISH;
        }

        }


        if (ocean [xSize][ySize]  == A_FISH && ySize < (ARRAY_Y_SIZE - 1) && direction == DOWN)
        {
            if (nextocean[xSize][ySize + 1] == IS_EMPTY)
        {

            nextocean [xSize][ySize + 1] = nextocean [xSize][ySize];
            if (rand() % RFISH == 0)
            //if(rand()%100>=RFISH)
            nextocean [xSize][ySize] = IS_EMPTY;

            else nextocean[xSize][ySize] = A_FISH;

        }

        }


        if (ocean [xSize][ySize]  == A_FISH && ySize != 0 && direction == UP)
        {
            if (nextocean[xSize][ySize - 1] == IS_EMPTY)
        {

            nextocean [xSize][ySize - 1] = nextocean [xSize][ySize];
            if (rand() % RFISH == 0)
            //if(rand()%100>=RFISH)
            nextocean [xSize][ySize] = IS_EMPTY;

            else nextocean[xSize][ySize] = A_FISH;
        }

        }
        if (ocean [xSize][ySize] > 0 )
        {
                ocean [xSize][ySize]--;
                nextocean [xSize][ySize]--;
        }
        //RIGHT
        if (ocean [xSize][ySize]  > 0 && xSize < (ARRAY_X_SIZE - 1) && direction == RIGHT) //done
        {
            if ( nextocean[xSize + 1][ySize] == A_FISH)
         {
                nextocean [xSize][ySize] = A_SHARK;
                nextocean [xSize + 1][ySize] = nextocean [xSize][ySize];
                //if (rand() % RSHARK == 0)
                if(rand() % 100 >= RSHARK)
                nextocean [xSize][ySize] = IS_EMPTY;
         }
            if ( nextocean[xSize + 1][ySize] == IS_EMPTY)
         {
                nextocean [xSize + 1][ySize] = nextocean [xSize][ySize];
                //if (rand() % RSHARK == 0)
                if(rand() % 100 == RSHARK)
                nextocean [xSize][ySize] = IS_EMPTY;

         }

        }

        //LEFT
        if (ocean [xSize][ySize] > 0 && xSize != 0 && direction == LEFT)
        {
            if (nextocean[xSize - 1][ySize] == A_FISH)
        {
            nextocean[xSize][ySize] = A_SHARK;
            nextocean [xSize - 1][ySize] = nextocean [xSize][ySize];
            //if (rand() % RSHARK == 0)
            if(rand() % 100 >= RSHARK)
            nextocean [xSize][ySize] = IS_EMPTY;

         }

            if ( nextocean[xSize - 1][ySize] == IS_EMPTY)
         {
                nextocean [xSize - 1][ySize] = nextocean [xSize][ySize];
                //if (rand() % RSHARK == 0)
                if(rand() % 100 == RSHARK)
                nextocean [xSize][ySize] = IS_EMPTY;

         }

         }

        //DOWN
        if (ocean [xSize][ySize]  > 0 && ySize < (ARRAY_Y_SIZE - 1) && direction == DOWN)
        {
            if (nextocean[xSize][ySize + 1] == A_FISH)
        {
            nextocean [xSize][ySize] = A_SHARK;
            nextocean [xSize][ySize + 1] = nextocean[xSize][ySize];
            //if (rand() % RSHARK == 0)
            if(rand() % 100 >= RSHARK)
            nextocean [xSize][ySize] = IS_EMPTY;
        }

            if ( nextocean[xSize][ySize + 1] == IS_EMPTY)
         {
                nextocean [xSize][ySize + 1] = nextocean [xSize][ySize];
                //if (rand() % RSHARK == 0)
                if(rand() % 100 == RSHARK)
                nextocean [xSize][ySize] = IS_EMPTY;

         }

        }
        //UP
        if (ocean [xSize][ySize]  > 0 && ySize < (ARRAY_Y_SIZE - 1) && direction == UP)
        {
            if (nextocean[xSize][ySize - 1] == A_FISH)
        {
            nextocean [xSize][ySize] = A_SHARK;
            nextocean [xSize][ySize - 1] = nextocean[xSize][ySize];
            //if (rand() % RSHARK == 0)
            if(rand() % 100 >= RSHARK)
            nextocean [xSize][ySize] = IS_EMPTY;
        }

            if ( nextocean[xSize][ySize - 1] == IS_EMPTY)
         {
                nextocean [xSize][ySize - 1] = nextocean [xSize][ySize];
                //if (rand() % RSHARK == 0)
                if(rand() % 100 == RSHARK)
                nextocean [xSize][ySize] = IS_EMPTY;

         }
        }

  }

}

cout << endl;

for (ySize=0; ySize < ARRAY_Y_SIZE; ySize++)
        {
            for(xSize=0; xSize < ARRAY_X_SIZE;xSize++)
            {
                if(nextocean [xSize][ySize]  == A_FISH)
                    cout << 'f';
                if(nextocean [xSize][ySize] > 0)
                    cout << 'S';
                if(nextocean [xSize][ySize] == IS_EMPTY)
                    cout << '.';
            }
             cout<< endl;

        }


// copies contents of nextocean to ocean
for (ySize=0;ySize< ARRAY_Y_SIZE;ySize++)
{
  for (xSize=0; xSize < ARRAY_X_SIZE; xSize++)
 {
   ocean [xSize][ySize] = nextocean [xSize][ySize];

 }
}


}

  return 0;
  }











