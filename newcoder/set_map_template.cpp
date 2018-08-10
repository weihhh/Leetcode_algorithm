#include <iostream>
#include <set>       // set
#include <map>       // map
#include <string>    // string
#include <algorithm> //set_union
#include <iterator>


typedef int KeyType;
typedef std::pair<const KeyType, std::string> Pair;
typedef std::multimap<KeyType, std::string> MapCode;

int main()
{
    using namespace std;
    const int N = 6;
    string s1[N] = {"buffoon", "thinkers", "for", "heavy", "can", "for"};//注意这里有两个相同的for
    string s2[N] = {"metal", "any", "food", "elegant", "deliver", "for"};
 
    set<string> A(s1, s1 + N);//set不仅去重，还按升序排序
    set<string> B(s2, s2 + N);
    ostream_iterator<string, char> out(cout, " ");
    
    cout << "Set A:\n";
    copy(A.begin(), A.end(), out);//buffoon can for heavy thinkers 
    cout << endl;
 
    cout << "Set B:\n";
    copy(B.begin(), B.end(), out);//any deliver elegant food for metal
    cout << endl;
 
    cout << "Union of A and B:\n";
    set_union(A.begin(), A.end(), B.begin(), B.end(), out);
    //any buffoon can deliver elegant food for heavy metal thinkers
    cout << endl;
 
    cout << "Intersection of A and B:\n";
    set_intersection(A.begin(), A.end(), B.begin(), B.end(), out); //for
    cout << endl;
 
    cout << "Difference of A and B:\n";
    set_difference(A.begin(), A.end(), B.begin(), B.end(), out);//buffoon can heavy thinkers
    cout << endl;
 
    set<string> C;
    cout << "Set C:\n";
    set_union(A.begin(), A.end(), B.begin(), B.end(),
        insert_iterator<set<string> >(C, C.begin()));//将A与B的并集放入C集合中,
    copy(C.begin(), C.end(), out); 
    //any buffoon can deliver elegant food for heavy metal thinkers
    cout << endl;
 
    string s3("grungy");
    C.insert(s3);
    cout << "Set C After insert s3:\n";
    copy(C.begin(), C.end(), out);
    //any buffoon can deliver elegant food for grungy heavy metal thinkers
    cout << endl;
 
    cout << "Showing a range:\n";
    //ghost在grungy之后，所以C.lower_bound("ghost")返回heavy的迭代器（第一个大于等于ghost位置），upper_bound返回最后一个小于指定元素
    copy(C.lower_bound("ghost"), C.upper_bound("spook"), out);
    //grungy heavy metal
    cout << endl;

    //multimap
    cout<<"----------------------------------map-----------------------"<<endl;
        MapCode codes;
     
        codes.insert(Pair(415, "San Francisco"));
        codes.insert(Pair(510, "Oakland"));
        codes.insert(Pair(718, "Brooklyn"));
        codes.insert(Pair(718, "Staten Island"));
        codes.insert(Pair(415, "San Rafael"));
        codes.insert(Pair(510, "Berkeley"));
        codes.insert(Pair(510, "Carry"));
        
        // count指出有几个键相同的值
        cout << "key 415: " << codes.count(415) << endl; // 2
        cout << "key 718: " << codes.count(718) << endl; // 2
        cout << "key 510: " << codes.count(510) << endl; // 3
        
        cout << "All codes:\n";
        MapCode::iterator it;
        for (it = codes.begin(); it != codes.end(); ++it)
            cout << (*it).first << " " << (*it).second << endl;
        // All codes:
        // 415 San Francisco
        // 415 San Rafael
        // 510 Oakland 不知道为什么它会在这里？？？
        // 510 Berkeley
        // 510 Carry
        // 718 Brooklyn
        // 718 Staten Island
     
       //找出所有键值相同的
        pair<MapCode::iterator, MapCode::iterator> range = codes.equal_range(718);
        cout << "key 718:\n";
        for (it = range.first; it != range.second; ++it)
            cout << (*it).second << endl;
        // key 718:
        // Brooklyn
        // Staten Island

    return 0;
}

/*
int main() {
    fre();//测试使用
    int casenum,casei;
    bool flag_int=true;
    scanf("%d",&casenum);
    // cout<<casenum<<endl;
    for(casei=1;casei<=casenum;++casei){
        if(casei==casenum){
            flag_int=false;
        }
        solvecase(flag_int);
        // cout<<answer<<endl;
    }
    return 0;
}
*/