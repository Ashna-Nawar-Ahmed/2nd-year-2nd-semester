#include<iostream>
#include<queue>
using namespace std;
struct student
{
    string name;
    float cgpa;
    student(string _name,float _cgpa)
    {
        name=_name;
        cgpa=_cgpa;
    }
    bool operator<(student a) const
    {
        return name>a.name;
    }
};
int main()
{
    priority_queue<student> pq;
    pq.push(student("ashna",3.83));
    pq.push(student("mayeesha",3.85));
    //pq.push((student)"mayisha",3.5);
    //student curr;
    while(!pq.empty())
    {
        student curr=pq.top();
        pq.pop();
        cout<<curr.name<<endl;
    }
    /*priority_queue<int> pq;
    pq.push(10);
    pq.push(100);
    pq.push(106);
    pq.push(210);
    pq.push(150);
    pq.push(1087);

    while(!pq.empty())
    {
        int curr=pq.top();
        pq.pop();
        cout<<curr<<endl;
    }*/
}
