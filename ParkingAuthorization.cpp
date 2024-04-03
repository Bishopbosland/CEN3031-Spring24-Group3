#include "ParkingAuthorization.hpp"

ParkingAuthorization::ParkingAuthorization() {}

void ParkingAuthorization::authorize(const std::string& vehicleLicense) {
    authorizedVehicles.insert(vehicleLicense);
}

bool ParkingAuthorization::isAuthorized(const std::string& vehicleLicense) const {
    return authorizedVehicles.count(vehicleLicense) > 0;
}

void ParkingAuthorization::revokeAuthorization(const std::string& vehicleLicense) {
    authorizedVehicles.erase(vehicleLicense);
}
