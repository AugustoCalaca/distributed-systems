#include <bits/stdc++.h> 

#define pb push_back
#define dash cout << "------------------------------------------------\n"
using namespace std;

typedef pair<int, int> pii;

int parseInt(string s) {
  int parse = (s[0] - '0') * 10 + (s[1] - '0');
  if(parse > 60) {
    cout << "Error hour\n";
    dash;
    exit(0); 
  }

  return parse;
}

int main() {
  string timeStr = "01:20";
  vector<int> times;

  int n, h, m, sum = 0;
  dash;
  cout << "Clients number: ";
  cin >> n;
  dash;
  
  cout << "Server hour (HH:MM): ";
  cin >> timeStr;
  dash;
  
  h = parseInt(timeStr.substr(0, 2));
  m = parseInt(timeStr.substr(3, timeStr.size()));

  int serverTime = h * 60 + m;
  sum += serverTime;
  times.pb(serverTime);

  for(int i = 0; i < n; i++) {
    cout << "Client " << i + 1 << " hour (HH:MM): ";
    cin >> timeStr;
    dash;

    h = parseInt(timeStr.substr(0, 2));
    m = parseInt(timeStr.substr(3, timeStr.size()));

    int clientTime = h * 60 + m;
    sum += clientTime;
    times.pb(clientTime);
  }

  int avg = sum / times.size();

  int newServer = avg - times[0];
  int newH = (times[0] + newServer) / 60;
  int newM = (times[0] + newServer) % 60;
  
  cout << "\n\n";
  dash;

  cout.fill('0');
  cout << "Set server to: " << setw(2) << showpos << newServer
       << " Min. ---> " << noshowpos << setw(2) << newH << ':' << setw(2) << newM << '\n';
  dash;

  for(size_t i = 1; i < times.size(); i++) {
    int adjust = avg - times[i];
    cout << "Set Client " << i << " to: " << showpos << setw(2) << adjust
         << " Min. --> " << noshowpos << setw(2) << newH << ':' << setw(2) << newM << '\n';
    dash;
  }

  return 0;
}