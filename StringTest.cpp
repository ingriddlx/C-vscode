#include<iostream>
#include<cstring>
#include<iomanip>
#include<conio.h>
#include<string>
#include"StringHead.h"
using namespace std;

void Choice1(){
	cout<<"1.输出\n";
	int i;
	str_class array[4]={"ABcde","f","058h",str_class(4,'a')};
	for(i=0;i<3;i++)
		array[i].Show();
}

void Choice4(){
	char c;int pos;
	str_class s("abcdefghijklmn123456789@#$%^&*");
	cout<<"请输入想要查找的字符：";
	cin>>c;
	cout<<"想从第几位开始查找：";
	cin>>pos;
	s.find(c,pos);
}

void Choice5(){
	string word;
	str_class s2("Hello,everyone.I'm a student of CES college of Shanghai University.");
	cout<<"\n请查找单词: ";
	cin>>word;
	const char *w=word.c_str();
	s2.find2(w);
}


void Choice6(){
	str_class s("abcdefghijklmn 123456789 @#$%^&*");
	s.Count();
}

void Choice8(){
	str_class str[4]= {"", "abc", "abcd", "上海大学"};
	int n = sizeof(str) / sizeof(*str);
	char s0[10]="yes";

	cout << "\n自定义版字符串处理函数";
	for (int i = 0; i < n; i++)
	{
		cout << "\n长度: " << str[i].StrLen();
		cout<<endl;
		cout << "\n粘贴: " << str[i].StrCat(s0) ;
		cout << "\n和abcyes比较: "  << str[i].StrCmp("abcyes")<<"[-1为小于，0为等于，1为大于]\n";
	}
}

int main(){
	char choice;
	while(1==1){
		cout<<"\n自定义字符串类\n"
		<<"1 输出\n"
		<<"2 大小写转换\n"
		<<"3 字符串倒序\n"
		<<"4 查找字符\n"
		<<"5 查找字符串\n"
		<<"6 统计数字字母符号个数\n"
		<<"7 字符串替换\n"
		<<"8 字符串处理函数\n"
		<<"0 退出\n" 
		<<"请选择： ";
		choice=getche();
		cout<<endl;
		if(choice<='0')break;
		
		switch(choice){
		case '1':Choice1();    break;
	    case '4':Choice4();    break;
	    case '5':Choice5();    break;
		case '6':Choice6();    break;
	    case '8':Choice8();    break;
		}
		
	}
	return 0;
}	