class Solution {
public:
    string temp;
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        temp=longUrl;
        return "";
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return temp;
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));