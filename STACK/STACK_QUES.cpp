// // BALANCED PARANTHESIS
// #include <iostream>
// #include <stack>
// using namespace std;

// bool isbalanceornot(char arr[])
// {
//     stack<char> s;

//     for (int i = 0; arr[i] != '\0'; i++)
//     {
//         char cha = arr[i];
//         switch (cha)
//         {
//         case '(':
//         case '{':
//         case '[':
//             s.push(cha);
//             break;

//         case ')':
//             if (!s.empty() and s.top() == '(')
//             {
//                 s.pop();
//             }
//             else
//             {
//                 return false;
//             }
//             break;

//         case '}':
//             if (!s.empty() and s.top() == '{')
//             {
//                 s.pop();
//             }
//             else
//             {
//                 return false;
//             }
//             break;

//         case ']':
//             if (!s.empty() and s.top() == '[')
//             {
//                 s.pop();
//             }
//             else
//             {
//                 return false;
//             }
//             break;
//         }
//     }

//     if (!s.empty())
//     {
//         return false;
//     }
//     return true;
// }
// int main()
// {
//     // assume string {} [] ()
//     char arr[] = "[{(a+b)+c}+d]";
//     if (isbalanceornot(arr) == true)
//     {
//         cout << "balanced";
//     }
//     else
//     {
//         cout << "not balanced";
//     }
// }

// // REVERSE A STACK
// #include <iostream>
// #include <stack>
// // #include <vector>
// using namespace std;

// void insertatbottom(stack<int> &s, int topelement)
// {
//     // base case
//     if (s.empty())
//     {
//         s.push(topelement);
//         return;
//     }
//     // recursive case
//     int y = s.top();
//     s.pop();
//     insertatbottom(s, topelement);
//     s.push(y);
// }
// void reversestack(stack<int> &s)
// {
//     // base case
//     if (s.empty())
//     {
//         return;
//     }

//     // recursive case
//     int topelement = s.top();
//     s.pop();
//     reversestack(s);
//     insertatbottom(s, topelement);
// }
// void printsatck(stack<int> s)
// {
//     while (!s.empty())
//     {
//         cout << s.top() << " ";
//         s.pop();
//     }
//     cout << endl;
// }

// int main()
// {
//     stack<int> s;
//     s.push(5);
//     s.push(8);
//     s.push(4);
//     s.push(2);
//     s.push(1);

//     printsatck(s);
//     reversestack(s);
//     printsatck(s);
// }

// MONOTONIC STACK
#include <iostream>
using namespace std;
class solution
{
public:
    vector<int> DailyTemperatures(vector<int> &temperature)
    {
        int size = temperatures.size();
        stack<int> st;
        vector<int> ans(size, 0);
        st.push(size - 1);
        for (int i = size - 2; i >= 0; i--)
        {
            while (!st.empty() and temperatures[i] >= temperatures[st.top()])
            {
                st.pop();
            }
            if (!st.empty())
            {
                ans[i] = st.top() - i;
            }
            st.push(i);
        }
        return ans;
    }
};
