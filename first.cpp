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

typedef struct first//������first����ʱ��
{
    char firstset1[200];
}first;
typedef struct first2//�������յ�first����
{
    char firstset2[200];
}first2;
typedef struct follow1//������follow����ʱ��
{
    char fow1[200];
}follow1;
typedef struct follow2//�������յ�follow����
{
    char fow2[200];
}follow2;
int main()
{   int i,m,pro_num,k;//����ʽ����
	
    Production productions[100];
    EmptyProduction empty_productions[100];
    cout<<"���������ʽ������n(n<100)��"<<endl;
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
				if(productions[i].right[m]>='a' && productions[i].right[m]<='z' )
				{
					empty_productions[i].emptyright=0; //�����Ҳ��з��ս���Ķ���һ����Ϊ�յ�
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
���н����
���������ʽ������n(n<100)��
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
A - e
���н����
���������ʽ������n(n<100)��
7
��ӿ�ʼ���������ʽ(���á�#����ʾ������ʽ����ĸ���)��
S - aH
H - aMd
H - d
M - Ab
M - #
A - aM
A - e
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

