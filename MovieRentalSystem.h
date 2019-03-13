/*
Faaiz Ul Haque
21503527
CS 201 - HW1
Section 1
*/
#ifndef MOVIERENTALSYSTEM_H
#define MOVIERENTALSYSTEM_H
#include "movies.h"
#include "subscribers.h"
#include <string>
#include <fstream>
using namespace::std;

class MovieRentalSystem
{
    public:
        enum Months {JANUARY = 1, FEBRUARY, MARCH, APRIL, MAY, JUNE, JULY,
        AUGUST, SEPTEMBER, OCTOBER, NOVEMBER, DECEMBER};
        enum SubscriptionType {ALLYOUCANWATCH = 0, PAYPERMOVIE};
        // You are not allowed to change the values of these constants
        const static int ALLYOUCANWATCH_COST = 30;
        const static int PAYPERMOVIE_COST = 4;
        const static int MONTHS = 12;
        MovieRentalSystem( const string movieInfoFileName, const string subscriberInfoFileName );
        ~MovieRentalSystem( );
        void deleteMovie( const int movieId );
        void rentMovie( const int subscriberId, const int movieId, Months month );
        void returnMovie( const int subscriberId, const int movieId, Months month );
        void showMoviesRentedBy( const int subscriberId );
        void showSubscribersWhoRentedMovie( const int movieId );
        void showBalance( Months month );
        void printMonth( int m );
        void showMovies();
        void showSubscribers();

    private:
        int numOfMovies;
        int numOfSubscribers;
        bool subsFlag;
        bool movieFlag;
        int *balance;
        int **checkMonthly;
        //int ***transactions;
        movies * movieArray;
        subscribers * subsArray;

};

#endif // MOVIERENTALSYSTEM_H
