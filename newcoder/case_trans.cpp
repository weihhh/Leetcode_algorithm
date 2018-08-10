#include <iostream>
#include <string>    // string
#include <algorithm> //set_union
#include <cctype> //toupper

using namespace std;

int main(){
    string strA = "yasaken@126.com";
    string strB = "LURY@LENOVO.com";
    string blank="ollllllllllllldsfsfsa";
    cout<<strA<<endl;
    transform(strA.begin(), strA.end(), blank.begin(), ::toupper);//在toupper/tolower前面加::，强制指定是C版本的
    cout<<strA<<endl;
    cout<<"blank: "<<blank<<endl;
}
