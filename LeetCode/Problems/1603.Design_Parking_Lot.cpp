class ParkingSystem {
public:
    int _b, _m, _s;
    ParkingSystem(int big, int medium, int small) {
        _b = big;
        _m = medium;
        _s = small;
    }

    bool addCar(int carType) {
        if (carType == 1){
            if (_b > 0){
                _b--;
                return true;
            }
            return false;
        }else if (carType == 2){
            if (_m > 0){
                _m--;
                return true;
            }
            return false;
        }else if (carType == 3){
            if (_s > 0){
                _s--;
                return true;
            }
            return false;
        }
        return false;
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */
