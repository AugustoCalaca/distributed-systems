#include <bits/stdc++.h> 

#define pb push_back
#define f first
#define s second
#define dash cout << "---------------------------------------------------------\n"
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

void verify(int hourSend, int hourSync) {
  if(hourSend < hourSync) {
    cout << "Invalid hour!\nHour send less sync hour!\n";
    dash;
    exit(0);
  }
}

int main() {
  string timeStr = "";
  vector<psi> timeSync, timeSend;
  vector<pps> timesOrder;

  int n, h, m;
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
  timeSync.pb({ timeStr, serverTime});

  for(int i = 0; i < n; i++) {
    cout << "Client " << i + 1 << " sync hour (HH:MM): ";
    cin >> timeStr;
    dash;

    h = parseInt(timeStr.substr(0, 2));
    m = parseInt(timeStr.substr(3, timeStr.size()));

    int clientTime = h * 60 + m;
    timeSync.pb({ timeStr, clientTime });
  }

  cout << "\n\n";
  dash;
  
  for(int i = 0; i < n; i++) {
    cout << "Client " << i + 1 << " send message hour (HH:MM): ";
    cin >> timeStr;
    dash;

    h = parseInt(timeStr.substr(0, 2));
    m = parseInt(timeStr.substr(3, timeStr.size()));

    int clientTime = h * 60 + m;
    verify(clientTime, timeSync[i + 1].s);
    timeSend.pb({ timeStr, clientTime });
  }

  cout.fill('0');
  cout << "\n\n";
  dash;
  cout << "Server: " << setw(2) << timeSync[0].f << '\n';
  dash;

  for(size_t i = 0; i < n; i++) {
    int diff = timeSend[i].s - timeSync[i + 1].s;
    timesOrder.pb({{ diff, i + 1 }, timeSync[i + 1].f});
  }
	
  cout << "\nClients ordered...\n";
  dash;

  sort(timesOrder.begin(), timesOrder.end());
  for(auto it: timesOrder) {
    cout << "Set Client " << it.f.s << " send message " 
         << setw(2) << it.f.f << " Min. after\n";
    dash;
  }

  return 0;
}
