/*
Faaiz Ul Haque
21503527
CS 201 - HW1
Section 1
*/
#ifndef MOVIES_H
#define MOVIES_H
#include "subscribers.h"

class movies
{
    public:
        movies();
        movies ( int ** subIDs, int ID, int num );
        int getRentalNum();
        int getMovieID();
        void setSubIDs( int ** arrayTemp);
        void setMovieID( const int ID );
        void setRentalNum( const int num );
        void addSubID( const int ID, const int month );
        void updateArray( int, int);
        void instantiateArray();
        int ** getSubIDs();
        int getSubNum();
        virtual ~movies();

    protected:

    private:
        int movieID;
        int rentalNum;
        int ** subscriberIDs;
        int numOfSubs;
};

#endif // MOVIES_H
