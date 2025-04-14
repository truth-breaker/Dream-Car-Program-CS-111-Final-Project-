#include <iostream>
#include <string>
#include "libary.h" 
#include <iomanip>
#include <fstream>
using namespace std;

//a[] very first element which is car type
//pass-by-reference for a copy of the actual parameter is made in memory,
//Goal:Extract data from the input file and store them into the array of struct objects.
bool collect_car_data(Automobile a[], int &i){
   ifstream file("input.dat");
   if(file.is_open()== false){
     cout <<"Sorry file can't be open";
    return false;
   }
    cout << "\nSuccess! File is open!\n";
    i = 0;
    string website;
    getline(file,website);
    
  while(!file.eof()){
    getline(file,a[i].car_type, ',');
    //cout <<"Type of Car Collected: " << a[i].car_type << endl;
    getline(file,a[i].brand, ',');
    // cout << "Type of Brand "<< a[i].brand << endl;
    getline(file,a[i].model, ',');
    // cout << "Type of model "<< a[i].model << endl;
    file >> a[i].year;
    file.ignore();
    file >>  a[i].price;
    file.ignore();
    //to collect data of horse power
     for (int i_horsepower = 0; i_horsepower <4 ;i_horsepower++){
         file >> a[i].horsepower[i_horsepower];
        //  cout << "HP "<< a[i].horsepower[i_horsepower] << endl;
      }//end of for loop for HP
      file.ignore();
      i++;  
  }//end of while loop 
  file.close();
  return true;
}//end of collect function

  //Goal: Displays all  struct objects of the array is a nice tabular format. 
  void display_allcars( Automobile a[], int &i){
    cout << left <<setw(19) << "Type of Car" << setw(30) << " Manufacturers" << setw(22) << "Model"<<setw(18) <<"Year" << setw(12) << "Price" << endl; 
      cout << "====================================================";
      cout << "=================================================\n";
    for (int j = 0; j < i; j++){
      
      cout << left <<setw(15) << a[j].car_type << right <<setw(18)<< a[j].brand << setw(27) << a[j].model <<setw(18)<< a[j]. year<< setw(18)<< a[j].price << endl;
      cout <<"HP: ";
      for (int i_horsepower = 0; i_horsepower < 4; i_horsepower++) {
      cout  <<  a[j].horsepower[i_horsepower];
      cout << " ";
      } //end of the inner loop
      cout << endl;
    }//end of outer for loop that showcases all car info 
 
  }//end of display function

  //sorting car price from lowest to highest (shifting elements to the left to sort low to high prices)
  void sort_by_price(Automobile a[], int i ){
      for (int j = 1; j < i; j++){
       for (int i_h = j; i_h > 0 && a[i_h-1].price > a[i_h].price;i_h-- ){
         swap(a[i_h-1], a[i_h]);
        }
      
      }
     
   }//end of function
  //analysis using the price within one struct object.
  void within_group (Automobile a[], int &i ){
     int indexofmodel =0; 
     string model;
     int lowest_hp = 999999;
     int highest = 0;
     cout << "Please enter a model of your choice to see its Horsepower Min & Max (range): ";
     cin >>model;
    //loop that finds high & low HP of the model that user chose 
     for(int index= 0; index <4; index++){
        //found the model
        if(a[index].model == model ){
            indexofmodel= index;
        }
        if (highest < a[indexofmodel].horsepower[index] ){
          highest = a[indexofmodel].horsepower[index];
         }
         if (lowest_hp > a[indexofmodel].horsepower[index] ){
          lowest_hp = a[indexofmodel].horsepower[index];
         }
      }//end of forloop
      cout<< "\nHighest HP: " << highest;
      cout <<"\nLowest HP: " << lowest_hp;
      cout << "\nRange: " << lowest_hp  <<"-" << highest << endl;
   }  
    //displays the highest HP for each Car
  void high_horsepower(Automobile a[], int &i ){
    for (int j = 0; j < i-1; j++){
      cout << a[j].car_type << ", ";
      cout << a[j].brand << "\t";
      cout <<  "\t" <<a[j].model << "\t";
      cout << "\t" << a[j].year << "\t : ";
      int highest = a[j].horsepower[0];
     
     for (int i_horsepower = 0; i_horsepower < 4; i_horsepower++) {
        if  (highest < a[j].horsepower[i_horsepower]) {
            highest = a[j].horsepower[i_horsepower];
        }//end of if
      } //end of the inner loop
    cout << "The highest HP in this vechile is:" << highest << endl;
    }
  }
  
  
  //pass by reference used b/c its being reduce the # of elements
  //goal to remove a car type of the users choice
   void remove_car(Automobile a[], int &i, string car) {
     cout << "Please enter car_type that you wish to remove: ";//prompting for what user wants to remove
     cin >> car;
     int index = 0;
      while(index < i ){
       // cout << "car type is " << a[index].car_type << endl;
        if (a[index].car_type == car){
         //when match found do loop to move pos 
         for(int c = index;c < i;c++ ){
           a[c] = a[c+1];
           }
           i--;
         } else {
           index++;
         }
      
       }//end of(while-loop) searching for the match
        
     } //end of remove_car function

    
 //The function is to set up the initial values of the data members of the Stats object. 
  void initial(Stats& s){
  s.lowest_carprice = 99999999;
  s.highest_carprice = 0;
  s.highest_car_year =0;
  s.lowestcar_year = 0;
  s.lowest_car_model_price = ""; //the highest car_type price among all the cars
  }
  //multiple group analyis -analysis using the prices among all cars based on a model of a car.
  void high_lowprices (Automobile a[],Stats&s, int i ){
    initial( s);
    for (int t = 0; t <i; t++) {
      if(s.lowest_carprice > a[t].price){
       s.lowest_carprice =a[t].price;
       s.lowest_car_model_price = a[t].model;
       s.lowestcar_year = a[t].year;   
      }
      //cout << "Prices" << s.lowest_carprice;
      if(s.highest_carprice < a[t].price){
       s.highest_carprice = a[t].price;
       s.highest_car_model_price = a[t].model;
       s.highest_car_year = a[t].year;
      }
    }  
     cout << s.lowest_car_model_price <<"(" << s.lowestcar_year << ") has the lowest car model price with a value of $ " << s.lowest_carprice << endl;
     cout << s.highest_car_model_price <<"(" << s.highest_car_year << ") has the highest car model price with a value of $ " << s.highest_carprice << endl;
  }
    //analysis using the price within one struct object.
    //i = tally for # of cars/i is num of cars
    //Goal:function that Displays users car_type choice to see avegerage price of that car_type(Sedan,Suv,etc) 
  void multiple_group (Automobile a[], int &i ){
     int indexofcar1 =0;
     string cartype;
     double averageprice=0;
     double total =0; 
     double numofcars = 0;
     cout << "Please enter a car type of your choice to see its avg price it contains: ";
     cin >>cartype;
     cout << "\nCar Type, "  ;
     cout << "Manufacturers, " << "Model," <<" Year," << " Price" << endl; 
     //loop to find the cartype
    for(int index= 0; index <i; index++){
     if(a[index].car_type == cartype ){
        indexofcar1= index;
        cout << a[index].car_type <<" ,"<< a[index].brand << " ,"<< a[index].model << " ," << a[index]. year << " ,"<< a[index].price << "\n\n";
        numofcars++;
        total += a[index].price;
        }
      }//end of search
      averageprice = total/numofcars;
      cout<<fixed << showpoint << setprecision(2);
      cout << "Car Type(" << a[indexofcar1].car_type  << ")average is $ " << averageprice << endl;   
    
   }//end of function
   //Goal: User enters Two Car models of their choice thats within the struct array to compare prices. Then to showcase which car out of those 2 has the highest price + display difference 
  void option_2car (Automobile a[],int &i ){
    int indexofcar1;
    int indexofcar2;
    string car1;
    string car2;
    cout<< "Please select # 1 car model of your choice " << endl;
    cin >> car1;
    cout<< "Please select # 2 car model of your choice " << endl;
    cin >> car2;
    //searching index of car 1 and car2
      for(int index= 0; index <i; index ++){
        if(a[index].model == car1 ){
            indexofcar1= index;
        }
        if(a[index].model ==car2){
          indexofcar2 = index;
        }
         
      }//end of forloop  
       cout <<"The first car is " << a[indexofcar1].model <<"\nThe second car is "<< a[indexofcar2].model << endl; 
       cout << "The price of the first car is $" << a[indexofcar1].price << "\nThe price of the second car is $ " << a[indexofcar2].price << endl;
       //in case if if the car 1 is bigger; to avoid neg(-)numbers
       if(a[indexofcar1].price > a[indexofcar2].price ){
       cout << "Difference is $ " <<  a[indexofcar1].price - a[indexofcar2].price << endl ;
      }
      else{
        cout << "Difference is $ " <<  a[indexofcar2].price - a[indexofcar1].price << endl ;
      }
}//end of function