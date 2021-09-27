#ifndef STRINGHEAD_H_INCLUDED
#define STRINGHEAD_H_INCLUDED
#include<string>

class str_class{
public:
	str_class(const char* pname = "no_name");
	str_class(int n,char c);
	~str_class();
	str_class(const str_class & pn);
	str_class & operator = (const str_class& pn);
	void Show()const;
	
	void find(char& c, int& pos = 0) const;
	void find2(const char* s)const;
	void Count()const;
	int StrLen()const;
	int StrCmp(const char* s)const;
	char* StrCat(char* s);
	/*char* StrCat(char* s);*/

	
private:
	char* name;
	
	
	
	
	
};

#endif