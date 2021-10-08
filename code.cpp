//Implemented by Anand,Mayank,Rohit.
#include<bits/stdc++.h>
#define ll long long 
#define pb push_back
#define all(n) n.begin(),n.end() 
#define vec vector<int>
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define vp(it,arr)  for(auto it:arr){cout<<it<<;}
#define LOOP(i,a,b) for(int i=a;i<b;i++)
using namespace std;
//Class for the Charging Station
class EVS{  
 public:
    int station_number;
    int charging_port;
    deque<pair<int,int>>waiting;
    EVS(int a,int charging_port){
        station_number=a;
        this->charging_port=charging_port;
    }
   

void update_the_waiting(int current_time){
     auto it=waiting.begin();
     while(it->second<current_time){
         waiting.pop_front();
     }
}

bool check_the_waiting_queue(int start_time,int end_time){
    if(check_CS_isempty()){
               for(auto it=waiting.begin();it!=waiting.end();it++){
                   if(it->first>end_time){
                       return true;
                   }
                   if(it->second<start_time){
                       return true;
                   }

               }
               return false;
    }else{
        return false;
    }
}
 
bool book_the_CS(int starting_tinme,int end_time){
    time_t now = time(0);
    tm *ltm = localtime(&now);
    int current_time=ltm->tm_hour;
    update_the_waiting(current_time);
    if(check_the_waiting_queue(current_time,end_time)){

    }
  } 

void booked(int starting_time,int battery_percentage){ 
    int end_time=starting_time+(((100-battery_percentage)/10)*5); //considering that the charging speed
    if(book_the_CS(starting_time,end_time)){
        cout<<"CS is booked for starting_t"<<endl;
    }else{
        cout<<"CS is not having any slot free"<<endl;
    }
}

};

class node{
    public:
    unordered_map<int,int>nbrs;
};

vector<int> BFS(unordered_map<int,node>&arru,int start_node){
    stack<int>arrui;
    arrui.push(start_node);
}
int calculate_remaining_distance(int value){
     if(value==0){
         return 0;
     }else{
     return  (value/100)*9;
     }
}
int dijisktras(unordered_map<int,node>&arru,int starting,int end){

}
vector<int> find_the_nodes(unordered_map<int,node>&arru,int start,int end){



}


int main(){


vector<EVS>arru;//vector of charging station as object
unordered_map<int,node>network;//This is our core graph
int i;
int node_num=0;
do{
      cout<<"Press 1 if you want to add some new Charging Station"<<endl;
      cout<<"Press 2 if you want to do travel some from one point to the other"<<endl;
      cout<<"Press 3 for just Charging the EV in nearby Places according to your EV's remaining charge"<<endl;
      cin>>i;
      if(i==1){
       cout<<"In Order to add some Charging Station you should provide the number of charging ports will be present there"<<endl;
       int ports;
       cin>>ports;
       EVS newer_node(node_num+1,ports);
       arru.push_back(newer_node);
       node_num++;
       cout<<"Enter the other nodes distances from"<<endl;
      }
      if(i==2){
              cout<<"Enter the source point and the destination point"<<endl;
              int sp,dp;
              cin>>sp>>dp;
              vector<int>journey_nodes=find_the_nodes(network,sp,dp);

      }
      if(i==3){
              cout<<"Enter the station number where you are standing"<<endl;
              int cst;//current station  number 
              cin>>cst;
              cout<<"Enter the charging percentage of your EV"<<endl;
              int charge_percent;
              cin>>charge_percent;
              vector<int>nearest_station=BFS(network,cst);
              int RD=calculate_remaining_distance(charge_percent);//This is the remaining distance that we can travel from the remaining charging of the EV
              map<int,int>nearest_distance_CS;
              for(auto it=nearest_station.begin();it!=nearest_station.end();it++){
                    int value2=dijisktras(network,cst,*it);
                    if(value2<=RD){
                    nearest_distance_CS.insert({value2,*it});
                    }
                }
            if(nearest_distance_CS.size()==0){
                  cout<<"Sorry we cannot help you beacuse you remaining charge cannot take you to any CS"<<endl;
            }else{
                  time_t now = time(0);
                  tm *ltm = localtime(&now);
                  int current_time=ltm->tm_hour;
                  int end_time=((100-charge_percent)/100)*4;
                  for(auto it=nearest_distance_CS.begin();it!=nearest_distance_CS.end();it++){
                       arru[it->second].update_the_waiting(current_time);
                       
                  }
            }
              



      }
}while(i==1||i==2||i==3);



return 0;
}