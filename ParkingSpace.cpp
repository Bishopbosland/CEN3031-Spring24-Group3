#include "ParkingSpace.hpp"
#include <iostream>

ParkingSpace::ParkingSpace(int id) : spaceID(id), isOccupied(false), isUnderMaintenance(false), vehicleLicense("") {}

void ParkingSpace::occupySpace(const std::string& license) {
    if (!isOccupied && !isUnderMaintenance) {
        isOccupied = true;
        vehicleLicense = license;
        std::cout << "Parking space " << spaceID << " is now occupied by vehicle with license " << license << ".\n";
    } else {
        std::cout << "Parking space " << spaceID << " is not available.\n";
    }
}

void ParkingSpace::freeSpace() {
    if (isOccupied) {
        isOccupied = false;
        vehicleLicense = "";
        std::cout << "Parking space " << spaceID << " is now free.\n";
    }
}

void ParkingSpace::markUnderMaintenance() {
    if (!isOccupied) {
        isUnderMaintenance = true;
        std::cout << "Parking space " << spaceID << " is under maintenance.\n";
    } else {
        std::cout << "Parking space " << spaceID << " is occupied and cannot be marked under maintenance.\n";
    }
}

void ParkingSpace::markAvailable() {
    isUnderMaintenance = false;
    std::cout << "Parking space " << spaceID << " is available for use.\n";
}

bool ParkingSpace::checkOccupied() const {
    return isOccupied;
}

int ParkingSpace::getSpaceID() const {
    return spaceID;
}

std::string ParkingSpace::getStatus() const {
    if (isUnderMaintenance) {
        return "Under Maintenance";
    } else if (isOccupied) {
        return "Occupied by " + vehicleLicense;
    } else {
        return "Available";
    }
}
