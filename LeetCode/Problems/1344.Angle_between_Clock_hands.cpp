class Solution {
public:
    double angleClock(int hour, int minutes) {
        //angle with vertical......
        double h_angle = 0;
        if(hour!=12){
            h_angle = (double)(hour*30.0);
        }
        cout<<"without minutes "<<h_angle<<endl;
        h_angle += (double)minutes/(double)2;

        double m_angle = (double)minutes*(double)6;

        double angle = abs(h_angle-m_angle);

        cout<<h_angle<<endl;
        cout<<m_angle<<endl;

        if(angle>180){
            angle = (double)360-angle;
        }
        return angle;
    }
};
