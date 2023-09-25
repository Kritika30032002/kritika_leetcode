class Solution {
public:
	char findTheDifference(string s, string t) {
		sort(s.begin(), s.end());
		sort(t.begin(), t.end());
		int i = 0;
		while(i < s.size()){
			if(s[i] != t[i]){
				return t[i];
			}
			i++;
		}
		return t[s.size()];
	 }
};


// class Solution {
// public:
// 	char findTheDifference(string s, string t) {
// 		int sum1 = 0;
// 		int sum2 = t[s.size()];
// 		for(int i = 0; i < s.length(); i++){
// 			sum1 += s[i];
// 			sum2 += t[i];
// 		}
// 		return char(abs(sum2 - sum1));
// 	}
// };