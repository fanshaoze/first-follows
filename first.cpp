#include <iostream>

using namespace std;

#include<string.h>
//����ʽ
typedef struct Production
{
    char left;//����ʽ���
    char trans;//��ͷ����
    char right[20];//����ʽ�Ҳ�
} Production;
typedef struct EmptyProduction
{
    int emptyleft;//
    int emptyright;//
} EmptyProduction;
typedef struct RightSign//������ɨ��ʽ�ӵ��Ҳ���Ǻ�
{
    int rightsigns[100];
}RightSign;

typedef struct FirstOriginal//������first����ʱ��
{
    char firstset[200];
}FirstOriginal;
typedef struct FirstFinal//�������յ�first����
{
    char firstset[200];
}FirstFinal;
typedef struct follow1//������follow����ʱ��
{
    char fow1[200];
}follow1;
typedef struct follow2//�������յ�follow����
{
    char fow2[200];
}follow2;
int main()
{   int i,m,pro_num,k,j,p;//����ʽ����
	
    Production productions[100];
    EmptyProduction empty_productions[100];
    cout<<"���������ʽ������pro_num(pro_num<100)��"<<endl;
    cin>>pro_num;
    cout<<"��ӿ�ʼ���������ʽ(���á�#����ʾ������ʽ����ĸ���)��"<<endl;

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
					empty_productions[i].emptyright=0; //�����Ҳ��з��ս���Ķ���һ����Ϊ�յ�
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
	//�ϲ��õ���������ղ���ʽ�����
	cout<<"A"<<endl;
	for(i=0;i<pro_num;i++)
	{
		cout<<empty_productions[i].emptyleft<<"||"<<empty_productions[i].emptyright<<endl;
	}
	//���е�������ɨ��ÿ������ʽ�Ҳ���ÿ�����ţ�
	char tempright;
	RightSign right_sign[100];
	for(i=0;i<100;i++)
	{
		for(m=0;m<100;m++)
		{
			right_sign[i].rightsigns[m]=100;
		}
	}//�����ǳ�ʼ��
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
		if(!(empty_productions[i].emptyleft==1||empty_productions[i].emptyright==0))//�ų���������յĺͲ����ܲ����յ�
		{
			for(m = 0;productions[i].right[m] != '\0' ; m ++)
			{
				tempright=productions[i].right[m];//ȡ��ÿ���ұߵ��ַ�
				for(k = 0 ; k <= pro_num ; k++)
				{	
					if(tempright==productions[k].left && empty_productions[k].emptyleft==1)//����ַ���ͬ�������ַ����Բ������ǿ�
					{	
						right_sign[i].rightsigns[m]=1;
						cout<<i<<","<<m<<endl;
					}
					else 
					{
						empty_productions[i].emptyright = 0;//���򣬲��������
					}
				}
			}
		}
	}//�ҳ�����������յĲ���ĳ������ʽ�ұߵ�ÿ���ַ��п����ǲ����յ���������λ�ü�¼����
		
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
	int sum,t;//������-1
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
	
	/*�ڶ���ɨ���ж�תΪ���ʽ��*/
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
	
	//����first����

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
	
	cout<<"���ս��"<<"    "<<"first����"<<endl;
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
���н����
���������ʽ������pro_num(pro_num<100)��
10
��ӿ�ʼ���������ʽ(���á�#����ʾ������ʽ����ĸ���)��
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
���ս��    first����
  S          #ba
  A          #b
  B          #a
  C          bac
  D          ac
���ս��    follow����
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
���н����
���������ʽ������pro_num(pro_num<100)��
7
��ӿ�ʼ���������ʽ(���á�#����ʾ������ʽ����ĸ���)��
S - aH
H - aMd
H - d
M - Ab
M - #
A - aM
A - i
���ս��    first����
  S          a
  H          ad
  M          ae#
  A          ae
���ս��    follow����
  S          #
  H          #
  M          db
  A          b
Press any key to continue
  */

