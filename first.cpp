#include <iostream>

using namespace std;

#include<string.h>
//产生式
typedef struct Production
{
    char left;//产生式左侧
    char trans;//箭头符号
    char right[20];//产生式右侧
} Production;
typedef struct EmptyProduction
{
    int emptyleft;//
    int emptyright;//
} EmptyProduction;
typedef struct RightSign//第三步扫描式子的右部标记号
{
    int rightsigns[100];
}RightSign;

typedef struct first//初步求first集合时用
{
    char firstset1[200];
}first;
typedef struct first2//保存最终的first集合
{
    char firstset2[200];
}first2;
typedef struct follow1//初步求follow集合时用
{
    char fow1[200];
}follow1;
typedef struct follow2//保存最终的follow集合
{
    char fow2[200];
}follow2;
int main()
{   int i,m,pro_num,k;//产生式条数
	
    Production productions[100];
    EmptyProduction empty_productions[100];
    cout<<"请输入产生式的条数n(n<100)："<<endl;
    cin>>pro_num;
    cout<<"请从开始符输入产生式(空用“#”表示，产生式由字母组成)："<<endl;

    for(i=0;i<pro_num;i++)
    {
        cin>>productions[i].left>>productions[i].trans>>productions[i].right;
    }
	/*
	for(i=0;i<pro_num;i++)
    {
        cout<<productions[i].left<<productions[i].trans<<productions[i].right<<endl;
    }
	*/
	for(i=0;i<pro_num;i++)
	{
		for(m=0;m<sizeof(productions[i].right);m++)
		{
			if(productions[i].right[m]=='#')
			{
				empty_productions[i].emptyleft=1;
				break;
			}
			else
			{
				if(productions[i].right[m]>='a' && productions[i].right[m]<='z' )
				{
					empty_productions[i].emptyright=0; //所有右侧有非终结符的都是一定不为空的
				}
			}
		}
	}
	/*
	for(i=0;i<pro_num;i++)
	{
		cout<<empty_productions[i].emptyleft<<"||"<<empty_productions[i].emptyright<<endl;
	}
	*/
	for(i=0;i<=pro_num;i++)
	{
		for(m=0;m<pro_num;m++)
		{	
			if(i==m)	break;
			if(productions[i].left==productions[m].left)
			{
				if(empty_productions[i].emptyright==0 && empty_productions[m].emptyright==0)
				{
					empty_productions[i].emptyleft = 0;
					empty_productions[m].emptyleft=0;
					break;
				}
			}
		}
	}
	/*
	cout<<"A"<<endl;
	for(i=0;i<pro_num;i++)
	{
		cout<<empty_productions[i].emptyleft<<"||"<<empty_productions[i].emptyright<<endl;
	}*/
	






    return 0;
}

/*
test1:
10
S - AB
S - bC
A - #
A - b
B - #
B - aD
C - AD
C - b
D - aS
D - c
运行结果：
请输入产生式的条数n(n<100)：
10
请从开始符输入产生式(空用“#”表示，产生式由字母组成)：
S - AB
S - bC
A - #
A - b
B - #
B - aD
C - AD
C - b
D - aS
D - c
非终结符    first集合
  S          #ba
  A          #b
  B          #a
  C          bac
  D          ac
非终结符    follow集合
  S          #
  A          #ac
  B          #
  C          #
  D          #
Press any key to continue


test2
7
S - aH
H - aMd
H - d
M - Ab
M - #
A - aM
A - e
运行结果：
请输入产生式的条数n(n<100)：
7
请从开始符输入产生式(空用“#”表示，产生式由字母组成)：
S - aH
H - aMd
H - d
M - Ab
M - #
A - aM
A - e
非终结符    first集合
  S          a
  H          ad
  M          ae#
  A          ae
非终结符    follow集合
  S          #
  H          #
  M          db
  A          b
Press any key to continue
  */

