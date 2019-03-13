/*
Faaiz Ul Haque
21503527
CS 201 - HW1
Section 1
*/
#include "MovieRentalSystem.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <stdlib.h>
using namespace::std;

MovieRentalSystem::MovieRentalSystem( const string movieFileName, const string subscriberFileName )
{
    //Open the files and test if they open correctly using the if function
    ifstream file( movieFileName.c_str() );
    stringstream buffer;
    if ( file )
        movieFlag = true;
    else
        movieFlag = false;

    string line = "";
    if ( movieFlag )
    {
        if ( file )
        {
            buffer << file.rdbuf();
            file.close();
        }
        buffer >> line;
        numOfMovies = atoi( line.c_str());
        movieArray = new movies[numOfMovies];
        int index = 0;

        while ( index < numOfMovies ){
            buffer >> line;
            movieArray[index].setMovieID( atoi( line.c_str() ) );
            buffer >> line;
            movieArray[index].setRentalNum( atoi(line.c_str() ) );
            index++;
        }
    }
    else
    {
       cout << " Movie input file " << movieFileName << " does not exist " << endl;
    }

    //Open the files and test if they open correctly using the if function
    ifstream file2( subscriberFileName.c_str() );
    stringstream buffer2;
    if ( file2 )
        subsFlag = true;
    else
        subsFlag = false;

    string line2 = "";
    if ( subsFlag )
    {
        if ( file2 )
        {
            buffer2 << file2.rdbuf();
            file2.close();
        }
        buffer2 >> line2;
        numOfSubscribers = atoi( line2.c_str());
        subsArray = new subscribers[numOfSubscribers];
        int index2 = 0;

        while ( index2 < numOfSubscribers ){
            buffer2 >> line2;
            subsArray[index2].setSubID( atoi( line2.c_str() ) );
            buffer2 >> line2;
            subsArray[index2].setSubType( atoi(line2.c_str() ) );
            index2++;
        }
    }
    else
    {
       cout << " Subscriber input file " << subscriberFileName << " does not exist " << endl;
    }
        if ( subsFlag && movieFlag )
        {
            checkMonthly = new int*[numOfSubscribers];
            for ( int i = 0; i < numOfSubscribers; i++ )
            {
                checkMonthly[i] = new int[MONTHS];
            }

           for ( int i = 0; i < numOfSubscribers; i++ )
            {
                checkMonthly[i][0] = subsArray[i].getSubID();
            }

            for ( int i = 0; i < numOfSubscribers; i++ )
                for ( int j = 1; j < MONTHS; j++ )
                        checkMonthly[i][j] = 0;

            balance = new int[MONTHS];

            int countMonthlySubs = 0;
            for ( int i = 0; i < numOfSubscribers; i++ )
            {
                if ( subsArray[i].getSubType() == 0 )
                {
                    countMonthlySubs++;
                }
            }
            for ( int i = 0; i < 12; i++ )
            {
                balance[i] = 0;
            }
            for ( int i = 0; i < 12; i++ )
            {
                balance[i] += countMonthlySubs * ALLYOUCANWATCH_COST;
            }
        }
}


MovieRentalSystem::~MovieRentalSystem()
{
    if ( movieFlag )
    {
        delete []movieArray;
    }
    if ( subsFlag )
    {
        delete []subsArray;
    }
    if ( subsFlag && movieFlag )
    {
        delete []balance;
        for ( int i = 0; i < numOfSubscribers; i++ )
        {
            delete []checkMonthly[i];
        }
        delete []checkMonthly;
    }
}

void MovieRentalSystem :: showMovies()
{
    for ( int i = 0; i < numOfMovies; i++ )
    {
        cout << movieArray[i].getMovieID() << " " << movieArray[i].getRentalNum() << endl;
    }
}

void MovieRentalSystem :: showSubscribers()
{
    for ( int i = 0; i < numOfSubscribers; i++ )
    {
        cout << subsArray[i].getSubID() << " " << subsArray[i].getSubType() << endl;
    }
}

void MovieRentalSystem :: deleteMovie( const int movieID )
{
    bool flag = false;
    bool returnFlag = true;
    for ( int i = 0; i < numOfMovies; i++ )
    {
        if ( movieArray[i].getMovieID() == movieID )
        {
            flag = true;
            if ( movieArray[i].getRentalNum() == 0 )
            {
                returnFlag = false;
            }
        }
    }
    if ( flag && returnFlag )
    {
        numOfMovies--;
        movies *temp = movieArray;
        movieArray = new movies[numOfMovies];
        int j = 0;
        for ( int i = 0; i < numOfMovies + 1; i++ )
        {
           if ( temp[i].getMovieID() != movieID )
           {
               movieArray[j].setMovieID( temp[i].getMovieID() );
               movieArray[j].setRentalNum( temp[i].getRentalNum() );
               //movieArray[j].setSubIDs( temp[i].getSubIDs() );
               j++;
           }
        }
        delete []temp;
        temp = NULL;

        cout << " Movie " << movieID << " has been deleted " << endl;
    }
    else if ( !flag )
    {
        cout << " Movie " << movieID << " does not exist " << endl;
    }
    else if ( !returnFlag )
    {
        cout << "Movie " << movieID << " cannot be deleted -- at least one copy has not been returned " << endl;
    }
}

void MovieRentalSystem :: rentMovie( const int subID, const int movieID, Months month )
{
    bool flagSub = false;
    bool flagMovie = false;
    bool flagRental = true;

    for ( int i = 0; i < numOfSubscribers; i++ )
    {
        if ( subsArray[i].getSubID() == subID )
            flagSub = true;
    }
    for ( int i = 0; i < numOfMovies; i++ )
    {
        if ( movieArray[i].getMovieID() == movieID )
        {
            flagMovie = true;
            if ( movieArray[i].getRentalNum() == 0 )
                flagRental = false;
        }
    }
    if ( flagMovie && flagSub && flagRental)
    {

        int subType = 0;
        int tempID = 0;
        for ( int i = 0; i < numOfSubscribers; i++ )
        {
            if ( subsArray[i].getSubID() == subID )
            {
                subType = subsArray[i].getSubType();
                tempID = subsArray[i].getSubID();
            }
        }
        for ( int i = 0; i < numOfSubscribers; i++ )
        {
            if ( checkMonthly[i][0] == tempID )
            {
                if ( subType == 1 )
                {
                    balance[month-1] += PAYPERMOVIE_COST;
                }
            }
        }


        for ( int i = 0; i < numOfMovies; i++ )
        {
            if ( movieArray[i].getMovieID() == movieID )
            {
                if ( movieArray[i].getRentalNum() == 0 )
                    cout << "Movie " << movieID << " has no available copy for renting " << endl;
                else
                {
                    movieArray[i].setRentalNum( movieArray[i].getRentalNum() - 1 );

                    movieArray[i].updateArray( subID, month );

                     cout << "Movie " << movieID << " has been rented by subscriber " << subID << " in ";
                     printMonth(month);
                     cout << endl;
                }
            }
        }

        for ( int i = 0; i < numOfSubscribers; i++ )
        {
            if ( subsArray[i].getSubID() == subID )
            {
                subsArray[i].updateArraySub(movieID, month);
            }
        }
    }

    else if ( !flagSub && !flagMovie )
        cout << "Subscriber " << subID << " and movie " << movieID << " do not exist " << endl;
    else if ( !flagMovie )
        cout << "Movie " << movieID << " does not exist " << endl;
    else if ( !flagSub )
        cout << "Subscriber " << subID << " does not exist " << endl;
    else if ( !flagRental )
        cout << "Movie " << movieID << " has no available copy for renting " << endl;
}

void MovieRentalSystem :: returnMovie( const int subID, const int movieID, Months month )
{
    bool flagSub = false;
    bool flagMovie = false;
    bool flagTrans = false;
    int ** temp;
    for ( int i = 0; i < numOfSubscribers; i++ )
    {
        if ( subsArray[i].getSubID() == subID )
            flagSub = true;
    }
    for ( int i = 0; i < numOfMovies; i++ )
    {
        if ( movieArray[i].getMovieID() == movieID )
            flagMovie = true;
    }

    for ( int i = 0; i < numOfMovies; i++ )
    {
        if ( movieArray[i].getMovieID() == movieID )
        {
            temp = movieArray[i].getSubIDs();
            for ( int i = 0; i < movieArray[i].getSubNum(); i++ )
            {
                if ( temp[i][0] == subID )
                {
                    for ( int j = 1; j <= 12; j++ )
                    {
                        if ( temp[i][j] == month )
                        {
                            flagTrans = true;
                        }
                    }
                }
            }
        }
    }

    if ( flagMovie && flagSub && flagTrans )
    {
        for ( int i = 0; i < numOfMovies; i++ )
        {
            if ( movieArray[i].getMovieID() == movieID )
            {
                movieArray[i].setRentalNum( movieArray[i].getRentalNum() + 1 );
            }
        }
        cout << "Movie " << movieID << " has been returned by subscriber " << subID << " in ";
        printMonth(month);
        cout << endl;
    }
    else if ( !flagTrans )
    {
        cout << " No transaction for subscriber " << subID << " and movie " << movieID << " in ";
        printMonth(month);
        cout << endl;
    }
    else if ( !flagSub && !flagMovie )
        cout << "Subscriber " << subID << " and movie " << movieID << " do not exist " << endl;
    else if ( !flagMovie )
        cout << "Movie " << movieID << " does not exist " << endl;
    else if ( !flagSub )
        cout << "Subscriber " << subID << " does not exist " << endl;
}

void MovieRentalSystem :: showMoviesRentedBy( const int subscriberID )
{
    int ** temp;
    bool flag = false;
    bool flag2 = false;
    /*for ( int i = 0; i < numOfSubscribers; i++ )
    {
        if ( subsArray[i].getSubID() == subscriberID )
        {
            temp = subsArray[i].getMovieIDs();
            for ( int k = 0; k < subsArray[i].getMovieNum(); k++ )
            {
                for ( int j = 0; j <= 12; j++ )
                {
                    cout << temp[k][j] << "   ";
                }
                cout << endl;
            }
        }
    }*/

    for ( int i = 0; i < numOfSubscribers; i++ )
    {
        if ( subsArray[i].getSubID() == subscriberID )
        {
            flag = true;
            if ( subsArray[i].getMovieNum() != 0 )
                flag2 = true;
        }
    }
    if ( !flag )
    {
        cout << "Subscriber " << subscriberID << " does not exist " << endl;
    }
    else if ( !flag2 )
    {
        cout << "Subscriber " << subscriberID << " has not rented any movies " << endl;
    }
    else
    {
        cout << " Subscriber " << subscriberID << " has rented the following movies: " << endl;

        for ( int i = 0; i < numOfSubscribers; i++ )
        {
            if ( subsArray[i].getSubID() == subscriberID )
            {
                temp = subsArray[i].getMovieIDs();
                for ( int k = 0; k < subsArray[i].getMovieNum(); k++ )
                {
                    cout << temp[k][0] << " in ";
                    for ( int j = 1; j <= 12; j++ )
                    {
                        if ( temp[k][j] > 0 )
                            printMonth(temp[k][j]);
                    }
                    cout << endl;
                }
            }
        }
    }
}


void MovieRentalSystem :: showSubscribersWhoRentedMovie( const int movieID )
{
    int ** temp;
    bool flag = false;
    bool flag2 = false;
    for ( int i = 0; i < numOfMovies; i++ )
    {
        if ( movieArray[i].getMovieID() == movieID )
        {
            temp = movieArray[i].getSubIDs();
        }
    }
    for ( int i = 0; i < numOfMovies; i++ )
    {
        if ( movieArray[i].getMovieID() == movieID )
        {
            flag = true;
            if ( movieArray[i].getSubNum() != 0 )
                flag2 = true;
        }
    }
    if ( !flag )
    {
        cout << "Movie " << movieID << " does not exist " << endl;
    }
    else if ( !flag2 )
    {
        cout << "Movie " << movieID << " has not been rented by any subscriber " << endl;
    }
    else
    {
        cout << " Movie " << movieID << " has been rented by the following subscribers: " << endl;

        for ( int i = 0; i < numOfMovies; i++ )
        {
            if ( movieArray[i].getMovieID() == movieID )
            {
                for ( int k = 0; k < movieArray[i].getSubNum(); k++ )
                {
                    cout << temp[k][0] << " in ";
                    for ( int j = 1; j <= 12; j ++ )
                    {
                        if ( temp[k][j] > 0 )
                        {
                            printMonth(temp[k][j]);
                            cout << endl;
                        }
                    }
                }
            }
        }
    }
}

void MovieRentalSystem :: showBalance( Months month )
{
    cout << " The total balance for ";
    printMonth(month);
    cout << " is " << balance[month - 1] << endl;
}
void MovieRentalSystem :: printMonth ( int m ) {
  switch (m) {
  case 1:
    cout << "JANUARY";
    break;
  case 2:
    cout << "FEBRUARY";
    break;
  case 3:
    cout << "MARCH";
    break;
  case 4:
    cout << "APRIL";
    break;
  case 5:
    cout << "MAY";
    break;
  case 6:
    cout << "JUNE";
    break;
  case 7:
    cout << "JULY";
    break;
  case 8:
    cout << "AUGUST";
    break;
  case 9:
    cout << "SEPTEMBER";
    break;
  case 10:
    cout << "OCTOBER";
    break;
  case 11:
    cout << "NOVEMBER";
    break;
  case 12:
    cout << "DECEMBER";
    break;
  }
}
