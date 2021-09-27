#include<iostream>
#include<iomanip>
#include<cstring>
#include<string>
#include"StringHead.h"
using namespace std;

str_class::str_class(const char* pname){
	name = new char[sizeof(pname)+1];
	strcpy(name,pname);
	cout<<"Constructing an object: "<<name<<"\n";
}

str_class::str_class(int n,char c){
	name = new char [n+1];
	for(int i =0;i<n;i++){
		name[i]=c;
	}
	name[n]='\0';
	cout<<"Constructing an object: "<<name<<"\n";
}
	
str_class::str_class(const str_class& pname){
	name = new char[sizeof(pname)+1];
	strcpy(name,pname.name);
	cout<<"Copy constructing an object: "<<name<<"\n";
}

str_class::~str_class(){
	cout<<"\nDestructing constructing an object: "<<name<<"\n";
	if(name!=NULL){
		delete[]name;
	}
}

str_class& str_class::operator = (const str_class& pn){
	cout<<"Assigning anobject: "<<pn.name<<"\n";
	if(&pn!=this){
		delete[]name;
		name = new char[sizeof(pn.name) + 1];
		strcpy(name,pn.name);
	}
	return *this;
}


void str_class::Show()const{
	cout<<setw(4)<<name<<endl;
}

void str_class::find(char& c, int& pos)const{
	for(;pos<sizeof(name);pos++){
		if(c==name[pos])
			cout<<"�ַ�"<<c<<"�ڵ�"<<pos<<"λ\n";
		else
			cout<<"��"<<pos<<"λ�ú�û�и��ַ�\n";
	}
}

void str_class::find2(const char* s)const{
	unsigned char* p = (unsigned char*)s;	
	unsigned char* q = (unsigned char*)name;
	int k;
	while (*p && *q && *p != *q&&*(p+1) != *(q+1)){				
		p++, q++;
		if(*p=' ')
			k++;
		if(*p=='\0')
			p=p-sizeof(s);
	}
	cout<<"�ַ���"<<s<<"���ַ���"<<name<<"�ĵ�"<<k<<"������\n";
}
	


void str_class::Count() const
{
	char* str = name;
	int a=0,b=0,c=0,d=0;
	while(*str!='\0')
	{
		if((*str>='a'&&*str<='z')||(*str>='A'&&*str<='Z'))
			a++;
		else if(*str>='0'&&*str<='9')
			b++;
		else if(*str==' ')
			c++;
		else d++;
		str++;
	}
	cout<<"��ĸ "<<a<<"�������� "<<b<<"�����ո�"<<c<<"����������"<<d<<"��\n";
}
	
int str_class::StrLen()const
{
	int n;
	for (n = 0; name[n] != '\0'; n++)
		;
	return n;
}


int str_class::StrCmp(const char* s)const
{
	unsigned char* p = (unsigned char*)s;	
	unsigned char* q = (unsigned char*)name;
	while (*p && *q && *p == *q)				
		p++, q++;
	return *p > * q ? 1 : (*p < *q ? -1 : 0);
}
	

char* str_class::StrCat(char* s)
{
	char* temp = name;
	while (*name)								
		name++;
	while (*name++ = *s++)
		;
	return temp;
}










