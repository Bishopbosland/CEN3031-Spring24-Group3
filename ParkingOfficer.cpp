#include "ParkingOfficer.hpp"

ParkingOfficer::ParkingOfficer(int officerID, ParkingSpace assignedSpaces[]) {
    this->officerID = officerID;
    //this->assignedSpaces = assignedSpaces;
    //TODO: Figure out how data will be passed to array
}

void ParkingOfficer::issueAuthorization(string vehicleLicense) {
    //parkingAuth[].authorize(vehicleLicense);
    //TODO: Finish after ParkingAuthorization class has been made
}

void ParkingOfficer::assignSpace(int spaceID) {
    //assignedSpaces[spaceID].occupySpace();
    //TODO: Figure out best way to pass license
}

bool ParkingOfficer::checkSpaceStatus(int spaceID) {
    if (assignedSpaces[spaceID].getStatus() == "Available") return true;
    else return false;
}

void ParkingOfficer::issueFine(string vehicleLicense) {
    //TODO: What is this supposed to do? Figure out how it is supposed to interact with rest of program?
}