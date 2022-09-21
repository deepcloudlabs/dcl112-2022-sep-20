#ifndef PRACTICE_SESSION_VEHICLE_H
#define PRACTICE_SESSION_VEHICLE_H

namespace logistics {
    // declaration
    class Vehicle {
        double load;
        const double maxLoad;
    public:
        // declaration + definition -> inlined
        //region constructors
        explicit Vehicle(const double maxLoad)
             : maxLoad(kiloToNews(maxLoad)), load(0.0) {}
        explicit Vehicle(const double maxLoad,const double load)
             : maxLoad(kiloToNews(maxLoad)), load(kiloToNews(load)) {}
        //endregion

        //region getters
        double getMaxLoad() const {
            return newsToKilo(maxLoad);
        }
        double getLoad() const {
            return newsToKilo(load);
        }
        //endregion

        //region business methods
        bool addBox(const double weight);
        //endregion
    private:
        //region conversion methods: Newton <==> Kilogram
        double newsToKilo(double amount) const;
        double kiloToNews(double amount) const;
        //endregion
    };

} // logistics

#endif //PRACTICE_SESSION_VEHICLE_H
