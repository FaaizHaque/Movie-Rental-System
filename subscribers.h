/*
Faaiz Ul Haque
21503527
CS 201 - HW1
Section 1
*/
#ifndef SUBSCRIBERS_H
#define SUBSCRIBERS_H
#include <string>
#include <fstream>
using namespace::std;

class subscribers
{
    public:
        subscribers();
        int getSubID();
        int getSubType();
        void setSubID( const int ID );
        void setSubType( const int num);
        int ** getMovieIDs();
        int getMovieNum();
        void updateArraySub( int, int);
        virtual ~subscribers();
    protected:

    private:
        int **movieIDs;
        int subscriberID;
        int subscriberType;
        int numOfMovs;

};

#endif // SUBSCRIBERS_H
