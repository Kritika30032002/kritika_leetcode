class Solution
{

    public:
        int largestVariance(string s)
        {
            int n = s.length();
            int mx = 0;
            for (int i = 0; i < 26; i++)
            {
                for (int j = 0; j < 26; j++)
                {
                    bool pehle_mila_hai = 0;
                    int a = 0, b = 0;
                    for (int k = 0; k < n; k++)
                    {
                        int c = s[k] - 'a';
                        if (c == i) a++;	// max ka freq
                        if (c == j) b++;	// min ka freq
                        if (b > 0)	//min wala exist to karna pdega
                            mx = max(mx, a - b);
                        else if (!b and pehle_mila_hai)
                            mx = max(mx, a - 1);
                        if (b > a)	//restart our substring
                        {
                            b = 0;
                            a = 0;
                            pehle_mila_hai = 1;
                        }
                    }
                }
            }
            return mx;
        }
};
