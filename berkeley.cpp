#include <bits/stdc++.h> 

#define pb push_back
#define f first
#define s second
#define dash cout << "------------------------------------------------\n"
using namespace std;

typedef pair<int, int> pii;
typedef pair<string, int> psi;
typedef pair<pii, string> pps;

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
  string timeStr = "";
  vector<psi> times;
  vector<pps> timesOrder;

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
  times.pb({ timeStr, serverTime});

  for(int i = 0; i < n; i++) {
    cout << "Client " << i + 1 << " hour (HH:MM): ";
    cin >> timeStr;
    dash;

    h = parseInt(timeStr.substr(0, 2));
    m = parseInt(timeStr.substr(3, timeStr.size()));

    int clientTime = h * 60 + m;
    sum += clientTime;
    times.pb({ timeStr, clientTime });
  }

  int avg = sum / times.size();

  int newServer = avg - times[0].s;
  int newH = (times[0].s + newServer) / 60;
  int newM = (times[0].s + newServer) % 60; 
  
  cout << "\n\n";
  dash;

  cout.fill('0');
  cout << "Set server to: " << setw(2) << showpos << newServer
       << " Min. " << times[0].f << " --> " << noshowpos << setw(2) << newH << ':' << setw(2) << newM << '\n';
  dash;

  for(size_t i = 1; i < times.size(); i++) {
    int adjust = avg - times[i].s;
    timesOrder.pb({{ adjust, i }, times[i].f});
  }
	
  cout << "\nClients ordered...\n";
  dash;

  sort(timesOrder.begin(), timesOrder.end());
  for(auto it: timesOrder) {
    int adjust = avg - it.f.f;
    cout << "Set Client " << it.f.s << " to: " << showpos << setw(2) << it.f.f
         << " Min. " << it.s << " --> " << noshowpos << setw(2) << newH << ':' << setw(2) << newM << '\n';
    dash;
  }

  return 0;
}
