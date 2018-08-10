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


int answer=-1;

void solvecase(){
    int hp,atk,cd;
    int time=1;
    cin>>hp>>atk>>cd;//当前生命值，攻击力，技能冷却
    std::vector<int> skills(3);
    std::vector<int> skills_cooldown(3);
    
    for (int i = 0; i < 3; ++i)
    {
        cin>>skills[i];
    }
    std::vector<int> monster_hp(3);
    std::vector<int> monster_atk(3);
    for(int i=0;i<3;++i){
        cin>>monster_hp[i];
        cin>>monster_atk[i];
    }
    //根据怪物攻击力确认攻击顺序
    int max_atk_index=-1;
    double max_atk=0;
    int max_skill_index=-1,max_skill=0;
    int hp_down,atk_hp;
    while(hp>0){
        cout<<"轮数："<<time<<endl;
        cout<<"血量："<<hp<<endl;
        for(int i=0;i<3;++i)
            cout<<"怪物: "<<monster_hp[i]<<endl;
        for(int i=0;i<3;++i)
            cout<<"冷却: "<<skills_cooldown[i]<<endl;
        hp_down=0,atk_hp=0;
        //选择怪物
        max_atk=0;
        max_atk_index=-1;
        for(int i=0;i<3;++i){
            if(monster_hp[i]>0){
                hp_down+=monster_atk[i];//计算此回合收到攻击
                // cout<<(double(monster_atk[i])/monster_hp[i])<<endl;
                if((double(monster_atk[i])/monster_hp[i])>max_atk){//使用攻击力与血量比值来决定攻击顺序
                    max_atk=(double(monster_atk[i])/monster_hp[i]);
                    max_atk_index=i;
                }
            }
        }
        cout<<"收到伤害："<<hp_down<<endl;
        cout<<"选择怪物： "<<max_atk_index<<endl;        
        if(max_atk_index==-1){
            time-=1;
            answer=time;
            return;//怪物杀光
        }
        //选择技能
        max_skill_index=-1;
        max_skill=atk;//找比普攻大的技能
        for(int i=0;i<3;++i){
            if(skills_cooldown[i]%cd==0&&skills[i]>max_skill){
                max_skill_index=i;
                max_skill=skills[i];
            }
        }
        cout<<"选择技能： "<<max_skill_index<<"伤害："<<max_skill<<endl;
        if(max_skill_index!=-1)
            skills_cooldown[max_skill_index]=cd;
        //攻击
        atk_hp+=max_skill;

        //结算伤害
        hp-=hp_down;
        monster_hp[max_atk_index]-=atk_hp;
        if(monster_hp[max_atk_index]<0){
            //刷新技能冷却
            for(int i=0;i<3;++i){
                skills_cooldown[i]=0;
            }
        }
        else{
            for(int i=0;i<3;++i){
                skills_cooldown[i]=(skills_cooldown[i]==0)?0:(skills_cooldown[i]-1);
            }
        }
        ++time;
    }
}

int main() {
    fre();//测试使用
    int casenum,casei;
    scanf("%d",&casenum);
    // cout<<casenum<<endl;
    for(casei=1;casei<=casenum;++casei){
        answer=-1;
        solvecase();
        cout<<answer<<endl;
    }
    return 0;
//     int a,b;
//     while(cin >> a >> b)//注意while处理多个case
//         cout << a+b << endl;
}