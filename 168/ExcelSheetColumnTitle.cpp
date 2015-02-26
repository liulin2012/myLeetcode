class Solution {
public:
    string convertToTitle(int n) {
            string ans;
            while(n!=0)
            {
                int i=(n-1)%26;
	        n=(n-1)/26;
	        string s1;
	        s1=(char) (i+65);
	        ans.insert(0,s1);
	        cout<<ans<<endl;
	     }
	     return ans;
       }
};
