#include "MovieRentalSystem.h"
#include <iostream>
#include "movies.h"
using namespace::std;
int main()
{
    /*subscribers mySub;
    mySub.updateArraySub( 800, 2 );
    mySub.updateArraySub( 100, 2 );
    mySub.updateArraySub( 20000, 4 );



    int **temp = mySub.getMovieIDs();
    for ( int i = 0; i < myMovie.getSubNum(); i++ )
    {
        for ( int j = 0; j <= 12; j++ )
        {
            cout << temp[i][j] << " ";
        }
        cout << endl;
    }*/
MovieRentalSystem firstMovieRentalSystem( "my_movies.txt", "subscribers.txt" );
cout << endl;
MovieRentalSystem myMovieRentalSystem( "movies.txt", "subscribers.txt" );
myMovieRentalSystem.deleteMovie( 600 );
myMovieRentalSystem.deleteMovie( 600 );
myMovieRentalSystem.deleteMovie( 70 );
cout << endl;
myMovieRentalSystem.rentMovie( 1111, 10, MovieRentalSystem::JANUARY );
myMovieRentalSystem.rentMovie( 1111, 20, MovieRentalSystem::JANUARY );
myMovieRentalSystem.rentMovie( 7777, 10, MovieRentalSystem::JANUARY );
myMovieRentalSystem.rentMovie( 6666, 10, MovieRentalSystem::JANUARY );
myMovieRentalSystem.rentMovie( 7777, 80, MovieRentalSystem::JANUARY );
myMovieRentalSystem.rentMovie( 6666, 100, MovieRentalSystem::JANUARY );
myMovieRentalSystem.rentMovie( 4444, 40, MovieRentalSystem::JANUARY );
myMovieRentalSystem.rentMovie( 4444, 50, MovieRentalSystem::JANUARY );
myMovieRentalSystem.rentMovie( 1234, 30, MovieRentalSystem::JANUARY );
myMovieRentalSystem.rentMovie( 1111, 33, MovieRentalSystem::JANUARY );
myMovieRentalSystem.rentMovie( 1234, 33, MovieRentalSystem::JANUARY );
cout << endl;
myMovieRentalSystem.returnMovie( 7777, 80, MovieRentalSystem::JANUARY );
myMovieRentalSystem.returnMovie( 6666, 100, MovieRentalSystem::JANUARY );
myMovieRentalSystem.returnMovie( 1111, 20, MovieRentalSystem::JANUARY );
myMovieRentalSystem.returnMovie( 1111, 10, MovieRentalSystem::MARCH );
cout << endl;
myMovieRentalSystem.rentMovie( 3333, 80, MovieRentalSystem::FEBRUARY );
myMovieRentalSystem.rentMovie( 8888, 100, MovieRentalSystem::FEBRUARY );
myMovieRentalSystem.rentMovie( 1111, 100, MovieRentalSystem::FEBRUARY );
cout << endl;
myMovieRentalSystem.showMoviesRentedBy( 1111 );
myMovieRentalSystem.showMoviesRentedBy( 8888 );
myMovieRentalSystem.showMoviesRentedBy( 2222 );
myMovieRentalSystem.showMoviesRentedBy( 1234 );
cout << endl;
myMovieRentalSystem.showSubscribersWhoRentedMovie( 10 );
myMovieRentalSystem.showSubscribersWhoRentedMovie( 100 );
myMovieRentalSystem.showSubscribersWhoRentedMovie( 30 );
myMovieRentalSystem.showSubscribersWhoRentedMovie( 70 );
myMovieRentalSystem.showBalance( MovieRentalSystem::JANUARY );
myMovieRentalSystem.showBalance( MovieRentalSystem::FEBRUARY );
myMovieRentalSystem.showBalance( MovieRentalSystem::MARCH );
cout << endl;
myMovieRentalSystem.deleteMovie( 100 );
cout << endl;
return 0;

}

