string findSum(string str1, string str2)
{
    // Before proceeding further, make sure length
    // of str2 is larger.
    if (str1.length() > str2.length())
        swap(str1, str2);
 
    // Take an empty string for storing result
    string str = "";
 
    // Calculate length of both string
    int n1 = str1.length(), n2 = str2.length();
 
    // Reverse both of strings
    reverse(str1.begin(), str1.end());
    reverse(str2.begin(), str2.end());
 
    int carry = 0;
    for (int i=0; i<n1; i++)
    {
        // Do school mathematics, compute sum of
        // current digits and carry
        int sum = ((str1[i]-'0')+(str2[i]-'0')+carry);
        str.push_back(sum%10 + '0');
 
        // Calculate carry for next step
        carry = sum/10;
    }
 
    // Add remaining digits of larger number
    for (int i=n1; i<n2; i++)
    {
        int sum = ((str2[i]-'0')+carry);
        str.push_back(sum%10 + '0');
        carry = sum/10;
    }
 
    // Add remaining carry
    if (carry)
        str.push_back(carry+'0');
 
    // reverse resultant string
    reverse(str.begin(), str.end());
 
    return str;
}
char* multiply(char* num1, char* num2) {
    int* sum = (int*)calloc(220, sizeof(int));
    if(num1 == NULL || num2 == NULL || num1[0] == '0' || num2[0] == '0') {
        char* result = (char*)calloc(2, sizeof(char));
        result[0] = '0';
        return result;
    }
    int l1 = strlen(num1);
    int l2 = strlen(num2);
    int i = 0, j = 0, t = 0, index = 0;
    for(i = 0; i < l1; i++) {
        for(j = 0; j < l2; j++) {
            sum[i + j] += (num1[i] - '0') * (num2[j] - '0');
        }
    }
    for(i = l1 + l2 - 2; i >= 0; i--) {
        sum[i] += t;
        if(sum[i] >= 10) {
            t = sum[i] / 10;
            sum[i] = sum[i] % 10;
        }
        else
            t = 0;
    }
    int len = 2 + (t ? l1 + l2 - 1 : l1 + l2 - 2);
    char* result = (char*)malloc(len * sizeof(char));
    if(t)
        result[index++] = '0' + t;
    for(i = 0; i <= l1 + l2 - 2; i++)
        result[index++] = sum[i] + '0';
    result[index] = 0;
    free(sum);
    return result;
}