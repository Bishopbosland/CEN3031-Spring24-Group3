#ifndef PARKINGOFFICER_HPP
#define PARKINGOFFICER_HPP

using namespace std;

#include <string>
#include"ParkingSpace.hpp"
//#include "ParkingAuthorization.hpp"

class ParkingOfficer {
    private:
        int officerID;
        ParkingSpace assignedSpaces[];
        //ParkingAuthorization parkingAuth[];
        //TODO: Finish after ParkingAuthorization class has been made

    public:
        ParkingOfficer(int officerID, ParkingSpace assignedSpaces[]);
        void issueAuthorization(string vehicleLicense);
        void assignSpace(int spaceID);
        bool checkSpaceStatus(int spaceID);
        void issueFine(string vehicleLicense);
};

#endif //PARKINGOFFICER_HPP