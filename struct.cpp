#include <iostream>

using namespace std;

struct Time {
  int hour; // 1-12
  int minute; // 0-59
  int second; // 0-59
  string period; // AM or PM
};

void printTime(Time currentTime) {
  cout << currentTime.hour << ":";
  if (currentTime.minute < 10) cout << "0";
  cout << currentTime.minute << ":";
  if (currentTime.second < 10) cout << "0";
  cout << currentTime.second << " " << currentTime.period << "\n";
}

void changePeriod(Time &currentTime) {
  if (currentTime.period == "AM") {
    currentTime.period = "PM";
  } else if (currentTime.period == "PM") {
    currentTime.period = "AM";
  }
}

void addHour(Time &currentTime) {
  cout << "Adding one hour...\n";
  currentTime.hour++;
  if (currentTime.hour > 12) currentTime.hour = 1;
  if (currentTime.hour == 12) changePeriod(currentTime);
}

Time getEastern(Time pacificTime) {
  for (int i=0; i<3; i++) {
    addHour(pacificTime);
  }
  return pacificTime;
}

int main(int argc, char** argv) {
  Time time1 = {6, 0, 0, "AM"};
  Time time2 = {11, 30, 0, "PM"};

  Time pacificTime = {9, 0, 0, "AM"};

  printTime(time1);
  addHour(time1);
  printTime(time1);

  printTime(time2);
  addHour(time2);
  printTime(time2);

  printTime(pacificTime);
  printTime(getEastern(pacificTime));
}



