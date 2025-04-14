#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

struct Automobile{
  string car_type;
  string brand, model;
  int year, price;
  int horsepower[4];
  int num_horsepower; //keep track # cars
  //track num of cars thats in the list
};
 struct Stats {
  int lowest_carprice;//variable that will store lowest carprice
  int highest_carprice;
  int lowestcar_year;
  int highest_car_year;
  string lowest_car_model_price;
  string highest_car_model_price;// the highest car_type price among all the cars
 };
bool collect_car_data(Automobile a[], int &i);


void display_allcars( Automobile a[], int &i);
void high_horsepower(Automobile a[], int &i);
void remove_car(Automobile a[], int &i, string car);
void sort_by_price(Automobile a[], int i );
void option_2car  (Automobile a[],int &i);
void high_lowprices (Automobile a[],Stats&s, int i );
void within_group (Automobile a[],int &i );
void multiple_group (Automobile a[], int &i );
 void initial(Stats& s);