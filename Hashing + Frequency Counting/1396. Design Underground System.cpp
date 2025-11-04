class UndergroundSystem {
private:
    unordered_map<int,pair<string,int>> mp1;
    unordered_map<string,pair<long long, int>> mp2;
    string getRoute(const string& a,const string& b){
        return a+"_"+b;
    }
public:
    UndergroundSystem() {}
    void checkIn(int id, string stationName, int t) {
        mp1[id]={stationName,t};
    }
    void checkOut(int id, string stationName, int t) {
        auto it=mp1.find(id);
        if(it==mp1.end()) return;
        string startStation=it.second.first;
        int checkIn=it.second.second;
        mp1.erase(it);
        string routekey=getRoute(startStation,stationName);
        int travelTime=t-checkIn;
        mp2[routekey].first+=travelTime;
        mp2[routekey].second+=1;
    }
    double getAverageTime(string startStation, string endStation) {
        string routekey=getRoute(startStation,endStation);
        long long totalTime=mp2[routekey].first;
        int count=mp2[routekey].second;
        return (double)totalTime/count;
    }
};

