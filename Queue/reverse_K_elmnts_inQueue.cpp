#include <queue>
#include <iostream>
#include <stack>
using namespace std;


queue<int> modifyQueue(queue<int> q, int k) {
    stack<int> st;
    queue<int> ans;
    int element=0;
    while(!q.empty())
    {
        if(q.size()>=k)
        {
            for(int i=0;i<k;i++)
            {
                element = q.front();
                q.pop();
                st.push(element);
            }
            while(!st.empty())
            {
                element = st.top();
                st.pop();
                ans.push(element);
            }
        }
        else
        {
            element = q.front();
            q.pop();
            ans.push(element);
        }
    }
    
    return ans;
    
}