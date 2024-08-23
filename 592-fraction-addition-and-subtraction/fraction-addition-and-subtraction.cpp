class Solution {
public:
    string fractionAddition(string expr) {
        // Intitializig final numerator and denominator as 0 and 1
        int num = 0;
        int deno = 1;
        
        int n = expr.length();
        int i = 0;
        
        while(i < n) {
            int currNum = 0;
            int currDeno = 0;
            
            bool isNeg = (expr[i] == '-');
            
            // Skipping '+' and '-' signs
            if(expr[i] == '+' || expr[i] == '-') {
                i++;
            }
            
            // Forming current numerator
            while(i < n && isdigit(expr[i])) {  // Using isdigit() utility function to check whether it is digit
                int digit = expr[i] - '0';      // Subtracting string char with '0' to convert into int
                currNum = currNum*10+digit;
                i++;
            }
            
            if(isNeg)
                currNum *= -1;
            
            // Skipping '/' sign
            i++;
            
            // Forming current denominator
            while(i < n && isdigit(expr[i])) {  // Using isdigit() utility function to check whether it is digit
                int digit = expr[i] - '0';      // Subtracting string char with '0' to convert into int
                currDeno = currDeno*10+digit;
                i++;
            }
            
            // Adding current numerator and denominator into final numerator and denominator
            num = num*currDeno + deno*currNum;
            deno  = deno * currDeno;
        }
        
        // Calculating GCD of num and deno to simplify them
        // Using __gcd() C++ utility function to find GCD
        // Since __gcd() untility function gives negative result in any of the inputs are negative, 
        // so taking absolute value of the result to get positive gcd always
        int GCD = abs(__gcd(num, deno));    
        // Simplifying num and deno
        num = num/GCD;
        deno = deno/GCD;
        
        return to_string(num) + '/' + to_string(deno);  // Using to_string() to convert int to string 
    }
};