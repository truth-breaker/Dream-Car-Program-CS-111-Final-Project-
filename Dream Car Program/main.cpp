#include "libary.h"
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
int main() {
  Stats stats;
  const int CAPACITY = 20;         // capacity of array
  Automobile car_object[CAPACITY]; // declaring the array of struct
  int num_car = 0;        // companion variable to save amount of cars processed
  unsigned action_choice; // var that stores users choice
  // string that stores car type of the users choice
  string carr = car_object[num_car].car_type;

  // cout << "Total number of cars processed: " << num_car<< endl;
  cout << " Welcome to the DREAM CAR Program!\n";
  cout << "\nWhere you can compare prices of cars to make a final decison on your dream car.\n";
  do {
    cout << "\nWould you like to\n1\tView Price of cars from lowest to "
            "highest\n2\tRemove car_type \n3\tDisplay all cars\t\n4\tSelect "
            "two cars to compare prices\n5\tDisplay lowest and highest car "
            "price \n6\tCartype Avg price\n7\tHighest Hp of Model Or\n8\tExit "
            "the loop?\n";
            cout << "Please select a Option:"; 
    cin >> action_choice;
    // sorting function
    if (action_choice == 1) {
      if (collect_car_data(car_object, num_car) == false) {
        return 1;
      }
      sort_by_price(car_object, num_car); //
      display_allcars(car_object, num_car);
    }
    // remove function
    if (action_choice == 2) {
      if (collect_car_data(car_object, num_car) == false) {
        return 1;
      }
      remove_car(car_object, num_car, carr);
      display_allcars(car_object, num_car);
      // cout <<"Number of cars:" << num_horsepower;
    }
    // display function
    if (action_choice == 3) {
      if (collect_car_data(car_object, num_car) == false) {
        return 1;
      }
      display_allcars(car_object, num_car);
    }
    // function between two groups
    if (action_choice == 4) {
      if (collect_car_data(car_object, num_car) == false) {
        return 1;
      }
      option_2car(car_object, num_car);
    }
    // function thats displays high and low prices among all cars
    if (action_choice == 5) {
      if (collect_car_data(car_object, num_car) == false) {
        return 1;
      }
      high_lowprices(car_object, stats, num_car);
    }
    // multiple analysis
    if (action_choice == 6) {
      if (collect_car_data(car_object, num_car) == false) {
        return 1;
      }
      multiple_group(car_object, num_car);
    }
    // within group analysis
    if (action_choice == 7) {
      if (collect_car_data(car_object, num_car) == false) {
        return 1;
      }
      within_group(car_object, num_car);
    }
  } while (action_choice != 8);
  cout << "Thank you for using the Program (: \n ";
  return 0;
}