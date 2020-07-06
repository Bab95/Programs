/*
Student Attendance Record I
You are given a string representing an attendance record for a student. The record only contains the following three characters:
'A' : Absent.
'L' : Late.
'P' : Present.
A student could be rewarded if his attendance record doesn't contain more than one 'A' (absent) or more than two continuous 'L' (late).

You need to return whether the student could be rewarded according to his attendance record.


*/


class Solution {
public:
    bool checkRecord(string s) {
        int absents = 0;
        int late = 0;
        for(int i=0;i<s.length();++i){
            switch(s[i]){
                case 'A':
                    absents++;
                    late = 0;
                    if(absents==2){
                        return false;
                    }
                    break;
                case 'L':
                    late++;
                    if(late==3){
                        return false;
                    }
                    break;
                case 'P':
                    late = 0;
                    break;
                default:
                    break;
            }
        }
        return true;
    }
};
