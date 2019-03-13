/*
Faaiz Ul Haque
21503527
CS 201 - HW1
Section 1
*/
#include "subscribers.h"

subscribers::subscribers()
{
    numOfMovs = 0;
    movieIDs = new int *[0];
}

subscribers::~subscribers()
{
    for ( int i = 0; i < numOfMovs; i++ )
    {
        delete []movieIDs[i];
    }
    delete []movieIDs;
}

int subscribers :: getMovieNum()
{
    return numOfMovs;
}
void subscribers :: updateArraySub( int ID, int m )
{
        numOfMovs++;
        int **temp = movieIDs;
        movieIDs = new int*[numOfMovs];
        for ( int i = 0; i < numOfMovs; i++ )
        {
            movieIDs[i] = new int[13];
        }

        for ( int i = 0; i < numOfMovs - 1; i++ )
        {
            for ( int j = 0; j <= 12; j++ )
            {
                movieIDs[i][j] = temp[i][j];
            }
        }
        for ( int i = 0; i <= 12; i++ )
        {
            movieIDs[numOfMovs - 1][i] = 0;
        }
        movieIDs[numOfMovs - 1][m] = m;
        movieIDs[numOfMovs - 1][0] = ID;

        for ( int i = 0; i < numOfMovs - 1; i++ )
        {
            delete []temp[i];
        }
        delete []temp;
        temp = NULL;
}

int subscribers:: getSubID()
{
    return subscriberID;
}

int subscribers:: getSubType()
{
    return subscriberType;
}

void subscribers :: setSubID( const int ID)
{
    subscriberID = ID;
}

void subscribers :: setSubType( const int num )
{
    subscriberType = num;
}

int ** subscribers :: getMovieIDs()
{
    return movieIDs;
}
