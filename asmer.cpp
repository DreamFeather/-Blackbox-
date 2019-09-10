#include <iostream>
#include <string>
#include <io.h>
#include<conio.h>
#include<windows.h>
#include<stack>
#include<fstream>
#include<io.h>
using namespace std;
string C="C:";
string D="D:";
string disk[5]={"C:","D:","E:","F:","G:"};
int disknum=0;
const int maxdisk=5;
int number=0;
string de="\\";
string ca="";
string org="";
string p=".";
string dp="..";
bool dire=true;
char st[]="start ";
bool choose=true;
string path,mpath;
string lpath,icon;
fstream fin("黑盒子.ini"),fout("黑盒子.ini");
string makepath;
char pcache[200];
inline void Set_mouse(int x=0,int y=0)
{
	HANDLE h =GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos;
	pos.X=x;pos.Y=y;
	SetConsoleCursorPosition(h,pos);
}

void openf(string & A,string B)
{
	string g=A+de+B;
	char op[200],opn[200];
	strcpy(opn,st);
	int i=0,l=g.length(),b=6,r=0;
	/*while(b!=6)
	{
		op[b]=st[b++];
	}*/

	for(;i<l;i++)
	{
		opn[i+b]=op[i+r]=g[i];
		if(g[i]=='\\'&&g[i+1]!='\\')
		{
			b++;r++;
			opn[i+b]=g[i];
			op[i+r]=g[i];
		}
		if(g[i]=='.'&&g[i+1]=='e')break;
	}
	opn[i+b]=opn[i+b+1]='\0';
	op[i+r]=op[i+r+1]='\0';
	//cout<<op<<endl;
	//cout<<opn<<endl;
	if(g[l-1]!='e'&&g[l-2]!='x'&&g[l-3]!='e')
	{
		system(opn);return ;
	}
	system("cls");
	char o,k;
	if(choose)
	{
		Set_mouse(25,7);	
		cout<<"即将打开.exe文件";
		Set_mouse(27,10);
		cout<<"A ：当前页面打开";
		Set_mouse(27,13);
		cout<<"B ：新建页面打开"<<endl;
		Set_mouse(25,20);
		cout<<"Esc 或者 退格键 ：取消"<<endl;
		
		
		
		l3:
		o=getch();system("cls");
		
		if(o=='O'||o=='o')
		{
			choose=(!choose);
			goto l3;
		}
	}
	l2:
		if(k=='c'||k=='C')system("cls");
		cout<<"\nexe程序运行中\n"<<endl;
	//if(choose)cout<<"en"<<endl;
	//else cout<<"un"<<endl;
	if(choose)
	switch(o)
	{
		case 'a':system(op);break;
		case 'A':system(op);break;
		case 'B':system(opn);break;
		case 'b':system(opn);break;
		case 8:break;
		case 27:break;
	}
	else system(op);
	cout<<"\n\nexe程序结束，按R键再次运行，按其他键返回，"<<endl;
	k=getch();
	if(k=='R'||k=='r'||k=='C'||k=='c')goto l2;
	system("cls");
	return ;
}

int dir(string path)
{
    long hFile = 0;
    struct _finddata_t fileInfo;
    string pathName, exdName;
                // \\* 代表要遍历所有的类型,如改成\\*.jpg表示遍历jpg类型文件
    if ((hFile = _findfirst(pathName.assign(path).append("\\*").c_str(), &fileInfo)) == -1) {
        return 0;
    }
    int i=1,w=0;
    do
    {
    	if(number==i++)
		{
			ca=fileInfo.name;
			cout<<" "<<number<<icon;
			if(fileInfo.attrib&_A_SUBDIR)dire=true;
			else dire=false;
		}
	            //判断文件的属性是文件夹还是文件
		if(i<number-13)continue;
		if(i>number+24)
		{
			if(!w)cout<<"......                                                                      ";
			w=1;
			continue;
		}
        cout << fileInfo.name << (fileInfo.attrib&_A_SUBDIR ? "       [目录]" : "      [文件]") <<"                                        "<< endl;
    } while (_findnext(hFile, &fileInfo) == 0);
    if(i>number+25)Set_mouse(0,i);cout<<"                                                                      "<<endl;
    _findclose(hFile);          
    return i;
}

void minu(string & A,string B)
{
	if(A.length()>B.length())
	{
		int a=A.length(),b=B.length();
		B=A;
		for(int i=0;i<a;i++)
		{
			if(i<a-b)A[i]=B[i];
			else A[i]='\0';
		}
		string f=A;
		A=f;
	}
	return ;
}

void foutput()
{
	fout<<path<<endl;
	fout<<mpath<<endl;
	fout<<makepath<<endl;
	fout<<icon<<endl;
	fout<<choose<<endl;
}

char *transform(string &A)
{
	char *w,*p=w=pcache;
	int i(0),a=A.length();
	while(i++<a)
	{
		*p++=A[i-1];
	}
	*p='\0';
	return w;
}

void EXIT()
{
	int ret=MessageBox(NULL,TEXT("退出黑盒子？"),TEXT("黑盒子"),MB_YESNO|MB_ICONQUESTION);
	if(ret==IDYES)
	{
		foutput();
		exit(0);
	}
}

void makefile(string A)
{
	string sp=" ",apath=makepath+sp+A;
	char x[500];
	int i,l=apath.length(),k=0,y=0;
	for(i=0;i<l;i++)
	{
		if(apath[i]=='.')
		{
			y++;
			if(y==2)
			break;
		}
		x[i+k]=apath[i];
		if(apath[i]=='\\')
		{
			x[i+ ++k]=apath[i];
		}
	}
	x[i+k]='\0';
	system(x);
}

void initial(stack<string> & A, string &S)
{
	while(!A.empty())A.pop();
	string g;
	switch(S[0])
	{
		case 'C':disknum=0;break;
		case 'D':disknum=1;break;
		case 'E':disknum=2;break;
		case 'F':disknum=3;break;
		case 'G':disknum=4;break;
	}
	int i,l=S.length();
	for(i=0;i<l;)
	{
		if(S[i]=='\\')
		{
			g+=S[i++];
		}
		while(S[i]!='\\'&&i<l)
		{
			g+=S[i++];
		}
		//g[i]='\0';
		A.push(g);
	}
	A.pop();
	return ;
}

void finput()
{
	getline(fin,lpath);
	getline(fin,mpath);
	getline(fin,makepath);
	getline(fin,icon);
	fin>>choose;
	fin.close();
}

int main()
{
	system("title 黑盒子 ——梦幻魅羽制作");
	system("mode con cols=120 lines=42");
	system("color f0");
	
	char x;
	int max;
	finput();
	path=mpath;
	stack <string> last;
	stack <int> lnmb;
	initial(last,mpath);
	int l;
    while(1)
    {
    	Set_mouse();
		cout<<path<<" :     ";//if(!last.empty())cout<<last.top();else cout<<"NULL";cout<<endl;
    	if(lpath!=mpath) cout<<"		"<<"  last time path:"<<lpath<<" 按home跳转"<<endl;
		cout<<endl;
    	max=dir(path);
    	Set_mouse(100,1);cout<<" "<<number<<"/"<<max-1<<"   ";
    	
		switch(x=getch())
    	{
    		case	'W':
    		case	'H':
    		case	'w':number--;if(number<0){number+=max,system("cls");} break;
    		case	'S':
    		case	'P':
    		case	's':(++number)%=max;break;
    		case	13:if(!dire){openf(path,ca);break;}					//enter
						if(ca==p)break;
						if(ca==dp){	path=last.top(),last.pop();if(!lnmb.empty())number=lnmb.top(),lnmb.pop();system("cls");break;}
						last.push(path);path+=(de+ca);ca=org;
						lnmb.push(number);
						lpath=mpath;
						number=1;system("cls");break;
    		case	8:if(path.length()<=2)break;						//backspace
						path=last.top(),last.pop();
						if(!lnmb.empty())number=lnmb.top(),lnmb.pop();
						lpath=mpath;system("cls");break;//cout<<path<<"*"<<endl;system("pause");break;
			case	'A':			
			case	'a':
			case	75:(disknum +=(maxdisk-1))%=maxdisk;
						while(access(transform(disk[disknum]),0)==-1)(disknum +=(maxdisk-1))%=maxdisk;
						path=disk[disknum];
						goto L1372;
						//while(!last.empty())last.pop();while(!lnmb.empty())lnmb.pop();number=1;system("cls");break;
			case	'D':
			case	77:
			case	'd':(++disknum)%=maxdisk;
						while(access(transform(disk[disknum]),0)==-1)(++disknum)%=maxdisk;
						path=disk[disknum];
						goto L1372;
			case	27:EXIT();											//esc
			case	71:if(lpath!=mpath){path=lpath;lpath=mpath;}		//home
						else {path=mpath;}
						initial(last,path);system("cls");break;
			case	'E':case  'e':l=ca.length();if(ca[l-1]=='m'&&ca[l-2]=='s'&&ca[l-3]=='a'){makefile(path+de+ca);}
						else 
						{
							system("cls");
							Set_mouse(50,10);
							cout<<ca<< "该文件不支持编译"<<endl;
							x=getch();
						}
						system("cls");
						break;
			case	79:system("cls");lpath=mpath;break;					//end
			case	'o':choose=!choose;break;
			case	1372:L1372:while(!last.empty())last.pop();while(!lnmb.empty())lnmb.pop();number=1;system("cls");break;
		}
	}
    return 0;
}
