#include "Vehicle.h"

namespace logistics {
    // definition
    bool Vehicle::addBox(const double weight) {
        double load = this->load + kiloToNews(weight);
        if (load > maxLoad) return false;
        this->load = load;
        return true;
    }

    double Vehicle::newsToKilo(double amount) const {
        return amount / 9.8;
    }

    double Vehicle::kiloToNews(double amount) const {
        return amount * 9.8;
    }

} // logistics