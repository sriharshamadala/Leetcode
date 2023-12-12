class Solution {
public:
    bool isOneEditDistance(string s, string t) {
               int len1 = s.size();
        int len2 = t.size();

        if( abs(len1 - len2) >1){
            return false;
        }
        else if(len1 == len2){

            // equal size
            //traverse string 
            bool first_difference = false;
            for(int i = 0; i< len1; i++){
                if(s[i] != t[i]){
                    if(first_difference) return false;
                    else first_difference = true;
                }
            }
            if(!first_difference){
                return false;
            }
            else{
                return true;
            }
        }
        else{
            int max_len = max(len1,len2);
            int i = 0;
            int j = 0;
            bool first_difference = false;
            while(1){
                if(s[i] !=  t[j]){
                    if(first_difference) return false;
                    else{
                        first_difference = true;
                        // increase idx of max_string
                        if(max_len == s.size()) i++;
                        else j++;
                    }
                }
                else{
                    i++;
                    j++;
                }
                if(i >= len1 || j >= len2){
                    break;
                }
            }
            //if( i < len1 || j < len2 ){
             //   if(first_difference) return false;
            //}

            return true;
        }

    } 
};