class Robot {
public:

    int valX,valY,width,height;
    string dirn;

    Robot(int width, int height) {
        valX=valY=0;
        dirn="East";
        this->width=width;
        this->height=height;
    }
    
    void step(int num) {
        int len=(width+height)*2-4;
        num%=len;
        if(num==0)
        {
            if(valX==0 && valY==0)
                dirn="South";
            return ;
        }
        while(num>0)
        {
            if(dirn=="East")
            {
                int del=min(num,width-valX-1);
                valX+=del;
                num-=del;
                if(del==0)
                    dirn="North";
            }
            else if(dirn=="North")
            {
                int del=min(num,height-valY-1);
                valY+=del;
                num-=del;
                if(del==0)
                    dirn="West";
            }
            else if(dirn=="West")
            {
                int del=min(num,valX);
                valX-=del;
                num-=del;
                if(del==0)
                    dirn="South";
            }
            else
            {
                int del=min(num,valY);
                valY-=del;
                num-=del;
                if(del==0)
                    dirn="East";
            }
        }
    }
    
    vector<int> getPos() {
        return {valX,valY};
    }
    
    string getDir() {
        return dirn;
    }
};

/**
 * Your Robot object will be instantiated and called as such:
 * Robot* obj = new Robot(width, height);
 * obj->step(num);
 * vector<int> param_2 = obj->getPos();
 * string param_3 = obj->getDir();
 */