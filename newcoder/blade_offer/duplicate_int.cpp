#include<iostream>
#include<algorithm>
#include<vector>
#define GET_ARRAY_LEN(array,len) {len = (sizeof(array) / sizeof(array[0]));}
using namespace std;

class Solution {
public:
    // Parameters:
    //        numbers:     an array of integers
    //        length:      the length of array numbers
    //        duplication: (Output) the duplicated number in the array number
    // Return value:       true if the input is valid, and there are some duplications in the array number
    //                     otherwise false
    bool duplicate(int numbers[], int length, int* duplication) {
        //限定了数字小于n，所以可以用数组本身作为标志位
        for(int i=0;i<length;++i){
            int index=numbers[i];
            if(index>=length){
                index-=length;
            }//因为有可能当前位已经被加上n，即设置了标志
            if(numbers[index]>=length){
                *duplication=index;
                return true;
            }
            else
                numbers[index]+=length;//这个数字对应位上加上n，而不是当前位，若两个数相等，则会发现它所指向的位的数已经大于n
            cout<<"numbers i: "<<numbers[i]<<endl;

        }
        return false;
    }
};

int main(){
    Solution st;
    int v1[7]={2,3,1,0,2,5,3};
    int arraysize;
    GET_ARRAY_LEN(v1,arraysize);
    for(int i=0;i<arraysize;++i)
        cout<<v1[i]<<endl;
    bool result=false;
    int number=0;
    result=st.duplicate(v1,arraysize,&number);
    cout<<"#############"<<endl;
    cout<<"result: "<<result<<endl;
    cout<<"after change: "<<number<<endl;

}