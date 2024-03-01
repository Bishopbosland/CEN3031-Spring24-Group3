#include "ParkingSpace.hpp"
#include <vector>
#include <iostream>

int main() {
    std::vector<ParkingSpace> parkingLot;
    for (int i = 1; i <= 10; ++i) {
        parkingLot.emplace_back(i);
    }

    
    parkingLot[0].occupySpace("ABC123");
    parkingLot[1].markUnderMaintenance();
    parkingLot[0].freeSpace();
    parkingLot[1].markAvailable();

   // Occupy some spaces with different vehicles
    parkingLot[2].occupySpace("XYZ789");
    parkingLot[3].occupySpace("LMN456");

    // Free a space that was previously occupied
    parkingLot[2].freeSpace();

    // Mark some spaces for maintenance
    parkingLot[4].markUnderMaintenance();
    parkingLot[5].markUnderMaintenance();

    // Simulate spaces coming out of maintenance and being occupied
    parkingLot[4].markAvailable();
    parkingLot[4].occupySpace("QRS012");
    parkingLot[5].markAvailable();
    parkingLot[5].occupySpace("TUV345");

    // Print the status of all parking spaces
    std::cout << "\n\n";
    for (const auto& space : parkingLot) {
        std::cout << "Parking Space " << space.getSpaceID() << " is " << space.getStatus() << ".\n";
    }

    return 0;
}
