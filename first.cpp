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

typedef struct FirstOriginal//初步求first集合时用
{
    char firstset[200];
}FirstOriginal;
typedef struct FirstFinal//保存最终的first集合
{
    char firstset[200];
}FirstFinal;
typedef struct follow1//初步求follow集合时用
{
    char fow1[200];
}follow1;
typedef struct follow2//保存最终的follow集合
{
    char fow2[200];
}follow2;
int main()
{   int i,m,pro_num,k,j,p;//产生式条数
	
    Production productions[100];
    EmptyProduction empty_productions[100];
    cout<<"请输入产生式的条数pro_num(pro_num<100)："<<endl;
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
				if(productions[i].right[m] >= 'a' && productions[i].right[m] <= 'z')
				{
					empty_productions[i].emptyright=0; //所有右侧有非终结符的都是一定不为空的
				}
			}
		}
	}
	
	for(i=0;i<pro_num;i++)
	{
		cout<<empty_productions[i].emptyleft<<"||"<<empty_productions[i].emptyright<<endl;
	}
	
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
					empty_productions[m].emptyleft = 0;
					break;
				}
			}
		}
	}
	//合并得到不会产生空产生式的左侧
	cout<<"A"<<endl;
	for(i=0;i<pro_num;i++)
	{
		cout<<empty_productions[i].emptyleft<<"||"<<empty_productions[i].emptyright<<endl;
	}
	//书中第三步：扫描每个产生式右部的每个符号，
	char tempright;
	RightSign right_sign[100];
	for(i=0;i<100;i++)
	{
		for(m=0;m<100;m++)
		{
			right_sign[i].rightsigns[m]=100;
		}
	}//仅仅是初始化
	/*for(i=0;i<pro_num;i++)
	{
		for(m=0;m<pro_num;m++)
		{
			cout<<right_sign[i].rightsigns[m]<<"  ";
		}
		cout<<endl;
	}*/
	for(i = 0 ; i < pro_num ; i ++)
	{
		if(!(empty_productions[i].emptyleft==1||empty_productions[i].emptyright==0))//排除本身产生空的和不可能产生空的
		{
			for(m = 0;productions[i].right[m] != '\0' ; m ++)
			{
				tempright=productions[i].right[m];//取得每个右边的字符
				for(k = 0 ; k <= pro_num ; k++)
				{	
					if(tempright==productions[k].left && empty_productions[k].emptyleft==1)//如果字符相同，而且字符可以产生的是空
					{	
						right_sign[i].rightsigns[m]=1;
						cout<<i<<","<<m<<endl;
					}
					else 
					{
						empty_productions[i].emptyright = 0;//否则，不会产生空
					}
				}
			}
		}
	}//找出，本身产生空的不算某个产生式右边的每个字符有可能是产生空的项，并把这个位置记录下来
		
	cout<<"B"<<endl;
	for(i=0;i<pro_num;i++)
	{
		cout<<empty_productions[i].emptyleft<<"||"<<empty_productions[i].emptyright<<endl;
	}
	
	cout<<"c"<<endl;
	for(i=0;i<pro_num;i++)
	{
		for(m=0;m<pro_num;m++)
		{
			cout<<right_sign[i].rightsigns[m]<<"  ";
		}
		cout<<endl;
	}
	int sum,t;//第三部-1
	sum = 0;
	for(i = 0 ; i < pro_num ; i++)
	{
		sum = 0;
		for(m = 0 ; productions[i].right[m] != '\0' ; m++)
		{	
			t = right_sign[i].rightsigns[m];
			if(t == 1)
			{	
				if(productions[i].right[m] != '\0')
				{
					sum++;
				}
			}
		}
		if(m == sum)	empty_productions[i].emptyleft = 1;
	}
	cout<<"D"<<endl;
	for(i=0;i<pro_num;i++)
	{
		cout<<empty_productions[i].emptyleft<<"||"<<empty_productions[i].emptyright<<endl;
	}
	
	/*第二次扫描判断转为否的式子*/
	for(i=0;i<=pro_num;i++)
	{
		for(m=0;m<pro_num;m++) 
		{	
			if(i==m) break;
			if(productions[i].left==productions[m].left && empty_productions[i].emptyleft!=1 && empty_productions[m].emptyleft!=1)
			{
				if(empty_productions[i].emptyright==0 && empty_productions[m].emptyright==0)
				{
					empty_productions[i].emptyleft = 0;
					empty_productions[m].emptyleft = 0;
					break;	
				}
			}
		}
	}
	cout<<"E"<<endl;
	for(i=0;i<pro_num;i++)
	{
		cout<<empty_productions[i].emptyleft<<"||"<<empty_productions[i].emptyright<<endl;
	}
	
	//计算first集合

	FirstOriginal first_assemble[100];
	
	char temp2[2]="-";//
	for(i=0;i<pro_num;i++)
	{
		first_assemble[i].firstset[0]='\0';
	}
	for(m=0;m<=pro_num;m++)
	{
		if(productions[m].right[0]>='a' && productions[m].right[0]<='z')
		{	
			temp2[0]=productions[m].right[0];
			strcat(first_assemble[m].firstset,temp2);
		}
		else	
		{	
			if(empty_productions[m].emptyleft==1)
			{		
				strcat(first_assemble[m].firstset,"#");
			}	
		}
	}
	for(i=0;i<=pro_num;i++)
	{
		for(m=0;productions[i].right[m]!='\0';m++)
		{	
			if(productions[i].right[m]>='A' && productions[i].right[m]<='Z')
			{	
				if(productions[i].right[0]>='a' && productions[i].right[0]<='z') break;
				for(k=0;k<pro_num;k++)
				{
					if(i!=k && productions[i].right[m]==productions[k].left)
					{
						if(empty_productions[k].emptyleft!=1)
							strcat(first_assemble[i].firstset,first_assemble[k].firstset);
						if(m==(strlen(productions[i].right)-1))
						{
							for(j=0;j<pro_num;j++)
							{
								if(i!=j && productions[i].right[m]==productions[j].left)
								if(empty_productions[i].emptyleft!=1)
								{
									strcat(first_assemble[i].firstset,first_assemble[j].firstset);
								}
								else
								{
									strcat(first_assemble[i].firstset,first_assemble[j].firstset);
									strcat(first_assemble[i].firstset,"#");
								}
							}
						}
							
					}
				}
			}
		}
	}

	FirstFinal first_f[100];
	for(i=0;i<pro_num;i++)
	{
		first_f[i].firstset[0]='\0';		
	}
	for(m=0;m<=pro_num;m++)
	{
		for(k=0;k<pro_num;k++)
		{	
			if(m!=k && productions[m].left==productions[k].left)
				strcat(first_assemble[m].firstset,first_assemble[k].firstset);
		}
	}
	char temp3[100];
	char temp4[2];
	k=0;
	j=0;//

	for(i=0;i<pro_num;i++)
	{
		for(p=0;p<99;p++)
			temp3[p]='\0';
		for(m=0;m < int(strlen(first_assemble[i].firstset));m++)
		{
			if(m==0)
			{
				temp4[0]=first_assemble[i].firstset[m];
				temp4[1]='\0';
				strcat(temp3,temp4);
				m++;
			}
			for(k=0;k<=int(strlen(temp3));k++)
				if(temp3[k]==first_assemble[i].firstset[m])break;//
				if(temp3[k]=='\0')
				{	
					temp4[0]=first_assemble[i].firstset[m];
					temp4[1]='\0'; 
					strcat(temp3,temp4);			
				}	
		}
		
		strcat(first_f[i].firstset,temp3);
	}
	
	cout<<"非终结符"<<"    "<<"first集合"<<endl;
	cout<<"  "<<productions[0].left<<"          "<<first_f[0].firstset<<endl;
	for(i=1;i<pro_num;i++)
	{		
		for(m=0;m<i;m++)
		{	
			if(productions[i].left!=productions[m].left&&m==(i-1))
				cout<<"  "<<productions[i].left<<"          "<<first_f[i].firstset<<endl;
		}
	}
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
请输入产生式的条数pro_num(pro_num<100)：
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
A - i
运行结果：
请输入产生式的条数pro_num(pro_num<100)：
7
请从开始符输入产生式(空用“#”表示，产生式由字母组成)：
S - aH
H - aMd
H - d
M - Ab
M - #
A - aM
A - i
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

