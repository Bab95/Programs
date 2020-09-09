#include <bits/stdc++.h>
using namespace std;
enum RideStatus {IDLE, CREATED, WITHDRAWN, COMPLETED};
class Ride{
    public:
        static const int AMT_PER_KM = 20;
        Ride();
        int calculateFare(bool);
        int getId()const;
        void setId(int id);
        void setDest(int dest);
        void setOrigin(int origin);
        RideStatus getRideStatus()const;
        void setRideStatus(RideStatus rideStatus);
        void setSeats(int seats);
    private:
        int id;
        int origin,dest;
        int seat;
        RideStatus rideStatus;

};
class Person{
    public:
        string name;
};
class Driver: private Person{
    public:
        Driver(string);
};
class Rider: private Person{
    public: 
        Rider(string);
        void createRide(int,int,int,int);
        void updateRide(int,int,int,int);
        void withdrawRide(int);
        int closeRide();
    private:
        vector<Ride> completedRides;
        Ride currentRide;
};

Driver::Driver(string name){
    this->name = name;
}
Ride::Ride(){
    id = origin = dest = seat = 0;
    rideStatus = RideStatus::IDLE;
}
int Ride::getId()const{
    return id;
}
void Ride::setId(int id){
    this->id = id;
}
void Ride::setDest(int dest){
    this->dest = dest;
}
void Ride::setSeats(int seat){
    this->seat = seat;
}
void Ride::setOrigin(int origin){
    this->origin = origin;
}
RideStatus Ride::getRideStatus()const{
    return rideStatus;
}
void Ride::setRideStatus(RideStatus rideStatus){
    this->rideStatus = rideStatus;
}
int Ride::calculateFare(bool priorityRider){
    int dist = abs(dest-origin);
    if(seat<2){
        return dist*AMT_PER_KM*(priorityRider?0.75:1);
    }
    return dist*seat*AMT_PER_KM*(priorityRider?0.5:0.75);
}

Rider::Rider(string name){
    this->name = name;
}
void Rider::createRide(int id,int origin,int dest,int seats){
    currentRide.setId(id);
    currentRide.setOrigin(origin);
    currentRide.setDest(dest);
    currentRide.setSeats(seats);
    currentRide.setRideStatus(RideStatus::CREATED);
}
void Rider::updateRide(int id,int origin,int dest,int seats){
    if(currentRide.getRideStatus()==RideStatus::WITHDRAWN){
        cout<<"Can't update withdrawn ride\n";
        return;
    }
    if(currentRide.getRideStatus()==RideStatus::COMPLETED){
        cout<<"Ride already completed\n";
        return;
    }
    currentRide.setId(id);
    currentRide.setOrigin(origin);
    currentRide.setDest(dest);
    currentRide.setSeats(seats);
    currentRide.setRideStatus(RideStatus::CREATED);
}
void Rider::withdrawRide(int id){
    if(currentRide.getId()!=id){
        cout<<"Wrong ride id\n";
        return;
    }
    if(currentRide.getRideStatus()!=RideStatus::CREATED){
        cout<<"Can't withdraw ride which was not created\n";
        return;
    }
    currentRide.setRideStatus(RideStatus::WITHDRAWN);
}
int Rider::closeRide(){
    if(currentRide.getRideStatus()!=CREATED){
        cout<<"Ride wasn't created you fool and trying to close it\n";
        return -1;
    }
    currentRide.setRideStatus(RideStatus::COMPLETED);
    completedRides.push_back(currentRide);
    return currentRide.calculateFare(completedRides.size()>=10);
}

int main(){
    cout<<"-----------Car sharing app-------------\n";
    Rider rider("Abdul");
    Driver driver("Rakeshwa");
    rider.createRide(1,50,60,1);
    rider.updateRide(1,50,60,2);
    cout<<rider.closeRide()<<endl;
    cout<<"**************************************"<<endl;
    rider.createRide(1,50,60,1);
    rider.withdrawRide(1);
    rider.updateRide(1,50,60,2);
    cout<<rider.closeRide()<<endl;
    return 0;
}