//Implemented by Anand,Mayank,Rohit.
#include<bits/stdc++.h>
using namespace std;
//Class for the Charging Station
class EVS{  
 public:
    int station_number;
    int charging_port;
    map<int,int>waiting;
    EVS(int a,int charging_port){
        station_number=a;
        this->charging_port=charging_port;
    }
   
// This function is to keep updated the waiting map. 
map<int,int>NATS;//This will store the next time slot availabale.
void update_the_waiting(int current_time){
     auto it=waiting.begin();
     while(it->second<current_time&&it!=waiting.end()){
         waiting.erase(it->first);
         it++;
     }
     NATS=this->UTNTS();
}

map<int,int> UTNTS(){   //this function is used to update the next available time slot in the charging station.
       map<int,int>ar;
       auto it=waiting.begin();
       auto it2=waiting.begin();
       it2++;
       while(it2!=waiting.end()){
           if((it->second)-((it2)->first)>0){
                 ar.insert({it->second,it2->first});
           }
           it++;
           it2++;
       }ar.insert({it->second,-1});
       return ar;
}

pair<int,int> check_the_waiting_queue(int start_time,int end_time){    
        for(auto it=NATS.begin();it!=NATS.end();it++){
            if(it->first<start_time&&it->second>end_time){
                return pair<int,int>(start_time,end_time);
            }
            if(it->first>end_time){
                if((it->second-it->first)>(end_time-start_time)){
                    return pair<int,int>(it->first,it->second);
                }
            }
        }
        
}
void book_the_cs(pair<int,int>value){
          this->waiting.insert(value);
          cout<<"Your booking has been done"<<endl;
}
 


};

class node{
    public:
    unordered_map<int,int>nbrs;
};

vector<int> BFS(unordered_map<int,node>&arru,int start_node){
    queue<int>arrui;
    arrui.push(start_node);
    vector<int>arruiya;
    arruiya.push_back(start_node);
    while(!arrui.empty()){
         int value2=arrui.front();
         arruiya.push_back(value2);
         arrui.pop();
         for(auto it=arru[value2].nbrs.begin();it!=arru[value2].nbrs.end();it++){
             arrui.push(it->first);
         }
    }

return arruiya;
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
do{
   cout<<"Press 1 if you want to add some new Charging Station"<<endl;
   cout<<"Press 2 if you want to do travel some from one point to the other"<<endl;
   cout<<"Press 3 for just Charging the EV in nearby Places according to your EV's remaining charge"<<endl;
   cin>>i;
   if(i==1){
   cout<<"In Order to add some Charging Station you should provide the number of charging ports will be present there"<<endl;
   int ports;
   cin>>ports;
   EVS newer_node(arru.size(),ports);
   arru.push_back(newer_node);
   node n1;
   network.insert({arru.size(),n1});
   cout<<"Enter the number of vertices which are adjacent to the given vertices"<<endl;
   int nv;
   cin>>nv;
   while(nv--){
       cout<<"Enter the nodes nearby value and then the weight associated with it"<<endl;
       int node,weight;
       cin>>node>>weight;
        network[arru.size()].nbrs.insert({node,weight});
   }
   cout<<"Nodes have been succesfully inserted"<<endl;
   
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
            unordered_map<int,pair<int,int>>available_slots;
            if(nearest_distance_CS.size()==0){
                  cout<<"Sorry we cannot help you beacuse you remaining charge cannot take you to any CS"<<endl;
            }else{
                  time_t now = time(0);
                  tm *ltm = localtime(&now);
                  int current_time=ltm->tm_hour;
                  int end_time=((100-charge_percent)/100)*4;
                  
                  for(auto it=nearest_distance_CS.begin();it!=nearest_distance_CS.end();it++){
                       arru[it->second].update_the_waiting(current_time);
                       pair<int,int>hen=arru[it->second].check_the_waiting_queue(current_time,end_time);
                       available_slots[it->second]=hen;
                    }
            cout<<"These are the available time slots in the graph"<<endl;
            for(auto it=available_slots.begin();it!=available_slots.end();it++){
            pair<int,int>runa=it->second;
            cout<<"Charging station number: "<<it->first<<"availabale time slot: "<<it->second.first<<it->second.second<<endl;
            }
            cout<<"Now enter the time station number in which you want to book the slot"<<endl;
            int sn;
            cin>>sn;
            arru[sn].book_the_cs(available_slots[sn]);


            }
              



      }
}while(i==1||i==2||i==3);



return 0;
}