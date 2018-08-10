
#include <iostream>
#include <set>
#include <string>
#include<iterator>
 
int main()
{
    using namespace std;
    const int N = 6;
    string s1[N] = {"buffoon", "thinkers", "for", "heavy", "can", "for"};//注意这里有两个相同的for
    set<string> A(s1, s1 + N);//set不仅去重，还按升序排序
    ostream_iterator<string> out(cout, " ");
    copy(A.begin(), A.end(), out);//buffoon can for heavy thinkers 
    cout << endl;
    return 0;
}