#include "ParkingOfficer.hpp"

ParkingOfficer::ParkingOfficer(int officerID, ParkingSpace assignedSpaces[], int count) {
    this->officerID = officerID;
    
    for (int i = 0; i < count; ++i) {
        this->assignedSpaces[i] = assignedSpaces[i];
    }
    this->count = count;
}

void ParkingOfficer::issueAuthorization(string vehicleLicense) {
    parkingAuth.authorize(vehicleLicense);
}

void ParkingOfficer::assignSpace(int spaceID, string vehicleLicense) {
    assignedSpaces[spaceID].occupySpace(vehicleLicense);
}

bool ParkingOfficer::checkSpaceStatus(int spaceID) {
    if (assignedSpaces[spaceID].getStatus() == "Available") return true;
    else return false;
}

void ParkingOfficer::issueFine(string vehicleLicense) {
    //TODO: What is this supposed to do? Figure out how it is supposed to interact with rest of program?
}