/**
 * The read4 API is defined in the parent class Reader4.
 *     int read4(char *buf4);
 */

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Number of characters to read
     * @return    The number of actual characters read
     */
    int read(char *buf, int n) {
        char buff4[4];
        int count = 0;
        int current_buffer;
        do{
            current_buffer = read4(buf+count);
            count += current_buffer;
        }while(count<n&&current_buffer==4);
        return min(n,count);
    }
};
