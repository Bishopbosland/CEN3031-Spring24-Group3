#ifndef PARKINGAUTHORIZATION_HPP
#define PARKINGAUTHORIZATION_HPP

#include <string>
#include <unordered_set>

class ParkingAuthorization {
private:
    std::unordered_set<std::string> authorizedVehicles;

public:
    ParkingAuthorization();
    void authorize(const std::string& vehicleLicense);
    bool isAuthorized(const std::string& vehicleLicense) const;
    void revokeAuthorization(const std::string& vehicleLicense);
};

#endif // PARKINGAUTHORIZATION_HPP
