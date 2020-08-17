/*
HackerLand National Bank has a simple policy for warning clients about possible fraudulent account activity.
If the amount spent by a client on a particular day is greater than or equal to 2x the client's median spending for a trailing number of days, they send the client a notification about potential fraud. The bank doesn't send the client any notifications until they have at least that trailing number of prior days' transaction data.

Given the number of trailing days d and a client's total daily expenditures for a period of n days, find and print the number of times the client will receive a notification over all n days.

For example, d=3 and expenditure = [10,20,30,40,50]. On the first three days, they just collect spending data. At day 4, we have trailing expenditures of [10,20,30].
The median is 20 and the day's expenditure is 40. Because 40>=2*20, there will be a notice.
The next day, our trailing expenditures are [20,30,40] and the expenditures are 50.
This is less than 2*30,so,no notice will be sent. Over the period, there was one notice sent.

Note: The median of a list of numbers can be found by arranging all the numbers from smallest to greatest. 
If there is an odd number of numbers, the middle one is picked. If there is an even number of numbers, median is then defined to be the average of the two middle values. 

Function Description:
Complete the function activityNotifications in the editor below. It must return an integer representing the number of client notifications.

activityNotifications has the following parameter(s):
expenditure: an array of integers representing daily expenditures
d: an integer, the lookback days for median spending

Input Format:
The first line contains two space-separated integers n and d, the number of days of transaction data, and the number of trailing days' data used to calculate median spending.
The second line contains  space-separated non-negative integers where each integer i denotes expenditures[i].

Output Format:
Print an integer denoting the total number of times the client receives a notification over a period of  days.

Sample Input 0:
9 5
2 3 4 2 3 6 8 4 5

Sample Output 0:
2
*/
#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

int median(int arr[], int d)
{
    int med;
    
    int sum = 0;
    for(int i = 0; i <= 200; i++)
    {
        sum = sum + arr[i];
        if(sum>=d)
        {
            med = i;
            break;
        }
    }
    return med;
}

int activityNotifications(vector<int> expenditure, int d) {
    int count  = 0;
    int n = expenditure.size();
    if(n==d)
    {
        return 0;
    }
    int temp[201]={0};
    for(int i = 0; i < d; i++)
    {
        temp[expenditure[i]]++;
    }
    
    int med = median(temp, d/2+d%2);
    for(int i = d; i < n; i++)
    {
        if(d%2==0)
        {
            int temp_med = median(temp, d/2+1);
            if(expenditure[i]>=med+temp_med)
            {
                count++;
            }
        }
        else
        {
            if(expenditure[i]>=med*2)
            {
                count++;
            }
        }
        
        temp[expenditure[i-d]]--;
        temp[expenditure[i]]++;
        med = median(temp,d/2+d%2);
    }
    return count;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nd_temp;
    getline(cin, nd_temp);

    vector<string> nd = split_string(nd_temp);

    int n = stoi(nd[0]);

    int d = stoi(nd[1]);

    string expenditure_temp_temp;
    getline(cin, expenditure_temp_temp);

    vector<string> expenditure_temp = split_string(expenditure_temp_temp);

    vector<int> expenditure(n);

    for (int i = 0; i < n; i++) {
        int expenditure_item = stoi(expenditure_temp[i]);

        expenditure[i] = expenditure_item;
    }

    int result = activityNotifications(expenditure, d);

    fout << result << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
