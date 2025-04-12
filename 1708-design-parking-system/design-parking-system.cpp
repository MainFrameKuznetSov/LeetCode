class ParkingSystem {
public:

    int bLim,mLim,sLim;

    ParkingSystem(int big, int medium, int small) {
        bLim=big;
        mLim=medium;
        sLim=small;
    }
    
    bool addCar(int car) {
        if(car==1)
        {
            if(bLim!=0)
            {
                --bLim;
                return 1;
            }
            else
                return 0;
        }
        else if(car==2)
        {
            if(mLim!=0)
            {
                --mLim;
                return 1;
            }
            else
                return 0;
        }
        else
        {
            if(sLim!=0)
            {
                --sLim;
                return 1;
            }
            else
                return 0;
        }
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */