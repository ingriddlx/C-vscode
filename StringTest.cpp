#include<iostream>
#include<cstring>
#include<iomanip>
#include<conio.h>
#include<string>
#include"StringHead.h"
using namespace std;

void Choice1(){
	cout<<"1.���\n";
	int i;
	str_class array[4]={"ABcde","f","058h",str_class(4,'a')};
	for(i=0;i<3;i++)
		array[i].Show();
}

void Choice4(){
	char c;int pos;
	str_class s("abcdefghijklmn123456789@#$%^&*");
	cout<<"��������Ҫ���ҵ��ַ���";
	cin>>c;
	cout<<"��ӵڼ�λ��ʼ���ң�";
	cin>>pos;
	s.find(c,pos);
}

void Choice5(){
	string word;
	str_class s2("Hello,everyone.I'm a student of CES college of Shanghai University.");
	cout<<"\n����ҵ���: ";
	cin>>word;
	const char *w=word.c_str();
	s2.find2(w);
}


void Choice6(){
	str_class s("abcdefghijklmn 123456789 @#$%^&*");
	s.Count();
}

void Choice8(){
	str_class str[4]= {"", "abc", "abcd", "�Ϻ���ѧ"};
	int n = sizeof(str) / sizeof(*str);
	char s0[10]="yes";

	cout << "\n�Զ�����ַ���������";
	for (int i = 0; i < n; i++)
	{
		cout << "\n����: " << str[i].StrLen();
		cout<<endl;
		cout << "\nճ��: " << str[i].StrCat(s0) ;
		cout << "\n��abcyes�Ƚ�: "  << str[i].StrCmp("abcyes")<<"[-1ΪС�ڣ�0Ϊ���ڣ�1Ϊ����]\n";
	}
}

int main(){
	char choice;
	while(1==1){
		cout<<"\n�Զ����ַ�����\n"
		<<"1 ���\n"
		<<"2 ��Сдת��\n"
		<<"3 �ַ�������\n"
		<<"4 �����ַ�\n"
		<<"5 �����ַ���\n"
		<<"6 ͳ��������ĸ���Ÿ���\n"
		<<"7 �ַ����滻\n"
		<<"8 �ַ���������\n"
		<<"0 �˳�\n" 
		<<"��ѡ�� ";
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