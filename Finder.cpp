#include "Finder.h"

    using namespace std;

    vector<int> Finder::findSubstrings(string s1, string s2) {
        const size_t m = s2.size();

        vector<int> result(m, -1);
        if (m == 0) return result;  // empty s2 check

        // for each prefix length i, search starting from earliest index
        // where previous (shorter) prefix was found rather than from the start again
        size_t start = 0;

        for (size_t i = 1; i <= m; ++i) {
            if (i == 1) {
                start = 0;  // first prefix - search entire s1
            } else {
                // if failed to find previous prefix, larger one can't exist
                if (result[i-2] == -1) {
                    // fill remaning with -1 (already initialised to -1)
                    break;
                }
                // earliest start for longer prefix can't be before the one for shorter prefix
                start = static_cast<size_t>(result[i-2]);
            }

            // now use find function to search only first i chars of s2
            // avoids building a substring every loop
            size_t found = s1.find(s2.c_str(), start, i);
            if (found != string::npos) {
                result[i-1] = static_cast<int>(found);
            } else {
                result[i-1] = -1;
                // no longer prefix can be found either, stop early
                break;
            }
        }

       return result; 
    }