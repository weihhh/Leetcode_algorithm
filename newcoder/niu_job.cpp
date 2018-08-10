#include <iostream>
#include<stdio.h>
#include <map>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

void fre() { freopen("input.in", "r", stdin); freopen("output.out", "w", stdout); }
#define MS(x, y) memset(x, y, sizeof(x))




/*------------------------   快速排序    -----------------*/
// 快速排序，如果选择关键值的子列表的最大或最小元素，则会导致最差情况出现
template<typename T>
void partition_sort(T *array,int start_index,int end_index){
    if(start_index>=end_index)
        return;
    int first=start_index;
    int last=end_index;
    T key=array[first];//保存当前作为关键词的元素,默认取第一个
    while(first<last){
        //取第一个，则末尾哨兵先动
        while(first<last&&array[last]>key)
            --last;
        //现在last元素小于等于key
        // array[first]=array[last];
        while (first < last && array[first] <= key) {
            ++first;
        }
        // array[last]=array[first];
        swap(array[first],array[last]);        
    }
    //相遇，则此位置为key最终位置
    // array[first]=key;
    swap(array[start_index],array[first]);
    partition_sort(array,start_index,first-1);
    partition_sort(array,first+1,end_index);

}


template<typename T>
void Quick_sort(T *array,int length){
    partition_sort(array,0,length-1);
}

// template<typename T_first,typename T_second>
// bool pair_cmp(pair<T_first,T_second> a,pair<T_first,T_second> b){
//     return a.first<b.first;//从小到大
// }
bool pair_cmp(pair<int,int> a,pair<int,int> b){
    return a.first<b.first;//从小到大
}

void Pair_sort(std::vector<pair<int,int> > &v){
    sort(v.begin(),v.end(),pair_cmp);
}

void solvecase(){
    int n, m;
    while(cin >> n >> m) {
        vector<pair<int, int> > job(n + 1), guy(m);//用0难度，0工资使得每个人都有一份工作，后面需要使用job[index-1]
        vector<int> map(m);
        int mx = 0, index = 0, left = 0;
        job[0] = make_pair(0, 0);
        for(int i = 1; i <= n; ++ i) {
            cin >> job[i].first >> job[i].second;
        }
        for(int i = 0; i < m; ++ i) {
            cin >> guy[i].first;
            guy[i].second = i;
        }
        sort(job.begin(), job.end(), [&](pair<int, int> a, pair<int, int> b){return a.first < b.first;});
        sort(guy.begin(), guy.end(), [&](pair<int, int> a, pair<int, int> b){return a.first < b.first;});
        for(int i = 0; i <= n; ++ i) {//防止出现难度更低的或者相等工作薪水更高，所以在根据难度从小到大排序后，如果i的薪水小于截至i的最大薪水，用截至i的最大薪水替代i的薪水
            mx = max(mx, job[i].second);
            job[i].second = mx;
        }
        while(left < m && index < n + 1) {
            if(guy[left].first >= job[index].first) ++ index;
            else {
                map[guy[left].second] = job[index - 1].second;
                ++ left;
            }
        }

        // for(int one=0 ;one<people;++one){
        //     int max_salary=0;
        //     for(int job=now_job;job<jobs;++job){
        //         // cout<<"now_guy: "<<one<<endl;
        //         // cout<<"job: "<<job<<endl;
        //         // cout<<"now_job: "<<now_job<<endl;
        //         // cout<<"人员能力： "<<guys[one].first<<"工作难度： "<<job_pair_vector[job].first<<endl;
        //         if(guys[one].first>=job_pair_vector[job].first){
        //             // cout<<"工资： "<<job_pair_vector[job].second<<" "<<"当前： "<<max_salary<<endl;
        //             if(job_pair_vector[job].second>max_salary){
        //                 max_salary=job_pair_vector[job].second;//这里反复赋值可能造成超时
        //                 now_job=job;
        //                 // cout<<"now_max: "<<max_salary<<endl;
        //             }
        //         }
        //         else{
        //             break;
        //         }
        //     }
        //     salarys[guys[one].second]=max_salary;
        // }

        for(int i = left; i < m; ++ i) {
            map[guy[i].second] = job[n].second;
        }
        for(int i = 0; i < m; ++ i) {
            cout << map[i] << endl;
        }
    }
}


//simple
// void solvecase(){
//     int jobs,people;
//     cin>>jobs>>people;

//     int difficulty[jobs];
//     int salary[jobs];
//     int ablity[people];
//     for (int i = 0; i < jobs; ++i)
//     {
//         cin>>difficulty[i]>>salary[i];
//     }
//     for (int i = 0; i < people; ++i)
//     {
//         cin>>ablity[i];
//     }

//     //
//     for(int one=0 ;one<people;++one){
//         int max_salary=0;
//         for(int job=0;job<jobs;++job){
//             if(ablity[one]>=difficulty[job]&&salary[job]>max_salary){
//                 max_salary=salary[job];
//             }
//         }
//         printf("%d\n",max_salary);
//     }
// }


int main() {
    fre();//测试使用
    solvecase();
    return 0;
}