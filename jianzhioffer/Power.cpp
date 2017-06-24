class Solution {
public:
    double Power(double base, int exponent) {
   	 	if(exponent < 0) return 1.0/(float)(Power(base, -exponent));
        else if(exponent == 0 ) return 1.0;
        else 
        {
            return base*Power(base, exponent - 1);
        }
    }
};