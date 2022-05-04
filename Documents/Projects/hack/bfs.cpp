#ifndef __linux__
#include<windows.h>
#endif
//#include<cstdlib>
//#include<sys/types.h>
//#include<unistd.h>
#include<dirent.h>
#include<string>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;
string f=__FILE__;int n,l;
typedef std::pair<int,string> p;
vector<p>v;char s[1000];
inline char*rread(int&r,char*s)
{
  r=0;
  while(*s<'0'||*s>'9')s--;
  for(int b=1;*s>='0'&&*s<='9';b*=10,s--)
    r+=b*(*s-'0');
  return s;
}
#include<iostream>
int main()
{
  f=f.substr(0,f.find_last_of('.',f.length()));
#ifdef __linux__
  DIR*dir=opendir(("../../data/"+f).c_str());
  dirent*ptr;
  while((ptr=readdir(dir))!=NULL)
    if((l=strlen(ptr->d_name))>3&&
       (string(ptr->d_name).rfind(".out",l)==l-4||
        string(ptr->d_name).rfind(".ans",l)==l-4))
    {
      rread(n,ptr->d_name+strlen(ptr->d_name));
      v.push_back(p(n,string(ptr->d_name)));
    }
  realpath(".",s);
#else
  f=f.substr(f.find_last_of('\\',f.length())+1,f.length());
  WIN32_FIND_DATA d;
  HANDLE hFind=FindFirstFile(("..\\..\\data\\"+f+"\\*").c_str(), &d);
  do if((l=strlen(d.cFileName))>3&&
       (string(d.cFileName).rfind(".out",l)==l-4||
        string(d.cFileName).rfind(".ans",l)==l-4)){
    rread(n,d.cFileName+strlen(d.cFileName));
    v.push_back(p(n,string(d.cFileName)));
  }while (FindNextFile(hFind, &d) != 0);
  FindClose(hFind);
  GetModuleFileName(NULL,s,1000);
#endif
  rread(n,rread(l,s+strlen(s)));
  sort(v.begin(),v.end());
#ifdef __linux__
  system(("cp -f ../../data/"+f+'/'+v[n].second+" "+f+".out").c_str());
#else
  system(("copy ..\\..\\data\\"+f+'\\'+v[n].second+" "+f+".out").c_str());
#endif
  return 0;
}