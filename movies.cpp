/*
Faaiz Ul Haque
21503527
CS 201 - HW1
Section 1
*/
#include "movies.h"
#include <iostream>
using namespace::std;


movies::movies()
{
    numOfSubs = 0;
    subscriberIDs = new int *[0];
}


movies::~movies()
{
    for ( int i = 0; i < numOfSubs; i++ )
    {
        delete []subscriberIDs[i];
    }
    delete []subscriberIDs;
}

void movies :: updateArray( int ID, int m )
{
        numOfSubs++;
        int **temp = subscriberIDs;
        subscriberIDs = new int*[numOfSubs];
        for ( int i = 0; i < numOfSubs; i++ )
        {
            subscriberIDs[i] = new int[13];
        }

        for ( int i = 0; i < numOfSubs - 1; i++ )
        {
            for ( int j = 0; j <= 12; j++ )
            {
                subscriberIDs[i][j] = temp[i][j];
            }
        }
        for ( int i = 0; i <= 12; i++ )
        {
            subscriberIDs[numOfSubs - 1][i] = 0;
        }
        subscriberIDs[numOfSubs - 1][m] = m;
        subscriberIDs[numOfSubs - 1][0] = ID;

        for ( int i = 0; i < numOfSubs - 1; i++ )
        {
            delete []temp[i];
        }
        delete []temp;
        temp = NULL;
}

int movies :: getSubNum()
{
    return numOfSubs;
}

int movies :: getMovieID()
{
    return movieID;
}

int movies :: getRentalNum()
{
    return rentalNum;
}

void movies :: setMovieID( const int ID )
{
    movieID = ID;
}

void movies :: setRentalNum (const int num )
{
    rentalNum = num;
}

void movies :: addSubID( const int ID, const int month)
{
    /*int i = 0;
    while ( subscriberIDs[i][0] != 0 )
    {
        i++;
    }
    subscriberIDs[i][0] = ID;
    subscriberIDs[i][1] = month;*/
}

int ** movies :: getSubIDs()
{
    return subscriberIDs;
}

void movies :: setSubIDs(  int ** arrayTemp )
{
    subscriberIDs = arrayTemp;
}
