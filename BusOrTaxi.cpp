#include <cmath>
#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main() {
  int busMin, taxiMin, walkMin; // Minutes needed for each tansport
  int busFee, taxiFee;          // Fee per minute for each transport
  int budget;
  int numFriends;
  int currHour,
      currMin; // ex. Current time 10:15 -> currHour = 10, currMin = 15
  int endMin, endHour;
  // get input values (DO NOT change order)
  cin >> busMin >> taxiMin >> walkMin;
  cin >> busFee >> taxiFee;
  cin >> numFriends >> budget;
  cin >> currHour >> currMin;

  int real_bus_Fee = busFee * busMin; 
  int real_taxi_Fee = round((double)taxiFee * taxiMin /(numFriends+1));
  cout << "Bus Fee: " << real_bus_Fee << endl;
  cout << "Taxi Fee: " << real_taxi_Fee << endl;

  if(real_taxi_Fee > budget && (real_bus_Fee < budget || (real_taxi_Fee <= real_bus_Fee) )) {
    cout << "\"Going home by taxi\"" << endl;
    endMin = (currMin + taxiMin)%60;
    endHour = (currHour + (currMin+taxiMin)/60)%24;
  }

  else if (real_bus_Fee > budget && (real_taxi_Fee < budget || (real_taxi_Fee > real_bus_Fee))){
    cout << "\"Going home by bus\"" << endl;
    endMin = (currMin + busMin)%60;
    endHour = (currHour + (currMin+busMin)/60)%24;
  }

  else{
        cout << "\"Going home by foot\"" << endl;
        endMin = (currMin + walkMin)%60;
        endHour = (currHour + (currMin+walkMin)/60)%24;
  }

  //printing output
  
  cout << "ETA: ";
    if (endHour <10){
        cout << "0" << endHour;
    }
    else{
        cout << endHour;
    }
    cout << ":";
    if (endMin < 10){
        cout << "0" << endMin;
    }
    else{
        cout << endMin;
    }

  return 0;
}
