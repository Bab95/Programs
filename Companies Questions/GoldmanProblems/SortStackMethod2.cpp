void SortedStack :: sort()
{
   //Your code here
   stack<int> s1;
   int t;
   while(!s.empty()){
       t = s.top();
       s.pop();
       if(s1.empty()){
           s1.push(t);
       }else if(t<s1.top()){
           s1.push(t);
       }else{
           int x;
           while(!s1.empty()&&s1.top()<t){
               x = s1.top();
               s1.pop();
               s.push(x);
           }
           s1.push(t);
       }
   }
   while(!s1.empty()){
       s.push(s1.top());
       s1.pop();
   }
}
