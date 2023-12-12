class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string> my_hash;
        for (string email: emails) {
            string temp_string;
            int ii = 0;
            while (ii < email.length()) {
                if ((email[ii] != '.') && (email[ii] != '+')) {
                    temp_string.push_back(email[ii]);
                    ii++;
                } else if (email[ii] == '+') {
                    while (email[ii] != '@') {
                        ii++;
                    }
                    break;
                } else {
                    ii++;
                }
            }
            while (ii < email.length()) {
                temp_string.push_back(email[ii]);
                ii++;
            }
            my_hash.insert(temp_string);
        }
        
        return my_hash.size();
    }
};