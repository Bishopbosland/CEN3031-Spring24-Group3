#ifndef PARKINGOFFICER_HPP
#define PARKINGOFFICER_HPP

using namespace std;

#include <string>
#include"ParkingSpace.hpp"
#include"ParkingAuthorization.hpp"

class ParkingOfficer {
    private:
        int officerID;
        static const int SIZE = 100;
        int count = 0;
        ParkingSpace assignedSpaces[SIZE];
        ParkingAuthorization parkingAuth;
        //TODO: Finish after ParkingAuthorization class has been made

    public:
        ParkingOfficer(int officerID, ParkingSpace assignedSpaces[], int count);
        void issueAuthorization(string vehicleLicense);
        void assignSpace(int spaceID, string vehicleLicense);
        bool checkSpaceStatus(int spaceID);
        void issueFine(string vehicleLicense);
};

#endif //PARKINGOFFICER_HPP