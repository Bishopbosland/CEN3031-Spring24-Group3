#ifndef PARKINGSPACE_HPP
#define PARKINGSPACE_HPP

#include <string>

class ParkingSpace {
private:
    int spaceID;
    bool isOccupied;
    bool isUnderMaintenance;
    std::string vehicleLicense; // License number of the vehicle parked (if any)

public:
    ParkingSpace();
    ParkingSpace(int id);
    void occupySpace(const std::string& license);
    void freeSpace();
    void markUnderMaintenance();
    void markAvailable();
    bool checkOccupied() const;
    int getSpaceID() const;
    std::string getStatus() const;
};

#endif // PARKINGSPACE_HPP
