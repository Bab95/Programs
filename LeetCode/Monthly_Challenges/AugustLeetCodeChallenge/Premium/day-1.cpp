class Logger {
public:
    /** Initialize your data structure here. */
    unordered_map<string,int> mmap;
    Logger() {

    }

    /** Returns true if the message should be printed in the given timestamp, otherwise returns false.
        If this method returns false, the message will not be printed.
        The timestamp is in seconds granularity. */
    bool shouldPrintMessage(int timestamp, string message) {
        if(mmap.find(message)==mmap.end()){
            mmap[message] = timestamp;
            return true;
        }else{
            if(timestamp-mmap[message]<10){
                return false;
            }else{
                mmap[message] = timestamp;
                return true;
            }
        }
        return false;
    }
};

/**
 * Your Logger object will be instantiated and called as such:
 * Logger* obj = new Logger();
 * bool param_1 = obj->shouldPrintMessage(timestamp,message);
 */
