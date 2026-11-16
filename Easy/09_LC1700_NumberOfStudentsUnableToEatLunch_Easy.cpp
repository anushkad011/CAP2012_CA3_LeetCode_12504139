//1700-Number of students unable to eat lunch
class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches){
        queue<int> q;
        stack<int> s;

        for(int i = 0; i < students.size(); i++) {
            q.push(students[i]);
        }
        for(int i = sandwiches.size() - 1; i >= 0; i--) {
            s.push(sandwiches[i]);
        }
        int count = 0;

        while(!q.empty() && count < q.size()) {
            if(q.front() == s.top()) {
                q.pop();
                s.pop();
                count = 0;
            }
            else {
                int x = q.front();
                q.pop();
                q.push(x);
                count++;
            }
        }
        return q.size();
    }
};
