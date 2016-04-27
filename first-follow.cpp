#include <iostream>

using namespace std;

#include<string.h>
//产生式
struct css{
	char left;
	char zhuan;//用“-”表示箭头
	char right[20];
};
//空标志
struct kong
{
		int kongzuo;
		int kongyou;
};

struct biaoji//第三步扫描式子的右部标记号
{
	int r[100];
};
struct first//初步求first集合时用
{
    char fjihe[200];
};
struct first2//保存最终的first集合
{
    char fjihe2[200];
};
struct follow//初步求follow集合时用
{
    char fow[200];
};
struct follow2//保存最终的follow集合
{
    char fow2[200];
};
int main()
{	int i,n,k;//产生式条数
	css shizi[100];
	kong kongshi[100];
	cout<<"请输入产生式的条数n(n<100)："<<endl;
	cin>>n;
	cout<<"请从开始符输入产生式(空用“#”表示，产生式由字母组成)："<<endl;

	for(i=0;i<n;i++)
	{
		cin>>shizi[i].left>>shizi[i].zhuan>>shizi[i].right;
	}
//for(k=0;k<n;k++)//输出所输入的产生式
//cout<<shizi[k].left<<shizi[k].zhuan<<shizi[k].right<<endl;

//找到可以推出空的产生式
	int l,m,j,h,g,f;
	for(l=0;l<n;l++)
    for(m=0;m<sizeof(shizi[l].right);m++)
    {
        if(shizi[l].right[m]=='#')
        {
            kongshi[l].kongzuo=1;break;
        }
        else
            while(shizi[l].right[m]>='a' && shizi[l].right[m]<='z' )
            {
                kongshi[l].kongyou=0; break;
            }
	}
//for(f=0;f<n;f++)//输出所输入的产生式左右部的空标记值-1
//cout<<kongshi[f].kongzuo<<"和"<<kongshi[f].kongyou<<endl;

	for(j=0;j<=n;j++)
		for(h=0;h<n;h++)
		{	if(j==h)break;
			if(shizi[j].left==shizi[h].left)
			{if(kongshi[j].kongyou==0 && kongshi[h].kongyou==0)
				kongshi[j].kongzuo=kongshi[h].kongzuo=0;break;
			}
		}
//for(g=0;g<n;g++)//输出所输入的产生式左右部的空标记值-2
//cout<<kongshi[g].kongzuo<<"和"<<kongshi[g].kongyou<<endl;

//书中第三步：扫描每个产生式右部的每个符号，
	int d,s,a,q,w,e;
	char linshi;
	biaoji biaoyou[100];
	for(d=0;d<n;d++)
	{
		if(!(kongshi[d].kongzuo==1||kongshi[d].kongyou==0))
		{
			for(s=0;shizi[d].right[s]!='\0';s++)
				for(a=0;a<=n;a++)
				{	linshi=shizi[d].right[s];
					if(linshi==shizi[a].left && kongshi[a].kongzuo==1)
						{	biaoyou[d].r[s]=1;

						}
					else {
							kongshi[d].kongyou=0;
						}
				}
		}

	}
    int sum,t,y;//第三部-1
	sum=0;
		for(e=0;e<n;e++)
		{
			for(q=0;shizi[e].right[q]!='\0';q++)
			{	t=biaoyou[e].r[q];
				if(t==1)
				{	for(sum;shizi[e].right[q]!='\0';)
					{sum++;
					y=sum-1;
					if(q==y)
						kongshi[e].kongzuo=1;break;
					}
				}
				else break;
			}
		}
    int a1,a2;/*第二次扫描判断转为否的式子*/
	for(a1=0;a1<=n;a1++)
		for(a2=0;a2<n;a2++)
		{
		    if(a1==a2)break;
			if(shizi[a1].left==shizi[a2].left&&kongshi[a1].kongzuo!=1&&kongshi[a2].kongzuo!=1)
			{
			    if(kongshi[a1].kongyou==0 && kongshi[a2].kongyou==0)
				kongshi[a1].kongzuo=kongshi[a2].kongzuo=0;break;
			}
		}

//for(w=0;w<n;w++)//输出所输入的产生式左右部的空标记值-2
//cout<<kongshi[w].kongzuo<<"和"<<kongshi[w].kongyou<<endl;


//计算first集合

    first fji[100];
    int u,a3,a5,a6,a7,a8;//
    char linshi2[2]="-";//
    for(u=0;u<n;u++)
	{
	    fji[u].fjihe[0]='\0';
	}
    for(a3=0;a3<=n;a3++)
    {
        if(shizi[a3].right[0]>='a' && shizi[a3].right[0]<='z')
        {
            linshi2[0]=shizi[a3].right[0];
            strcat(fji[a3].fjihe,linshi2);
        }
		else
        {
            if(kongshi[a3].kongzuo==1)
            {
                strcat(fji[a3].fjihe,"#");
            }
        }
    }
/////////////////////////////////////
//int a9;//输出first-1
//for(a9=0;a9<n;a9++)
	//for(a10=0;fji[a9].fjihe[a10]!='\0';a10++)
	//{cout<<fji[a9].fjihe<<endl;//[a10]a10<strlen(fji[a9]).fjihe
	//}
//////////////////////////////////
    for(a5=0;a5<=n;a5++)
    for(a6=0;shizi[a5].right[a6]!='\0';a6++)
    if(shizi[a5].right[a6]>='A' && shizi[a5].right[a6]<='Z')
    {
        if(shizi[a5].right[0]>='a' && shizi[a5].right[0]<='z')  break;
		for(a7=0;a7<n;a7++)
            if(a5!=a7 && shizi[a5].right[a6]==shizi[a7].left)
            {
                {
                    if(kongshi[a7].kongzuo!=1)  strcat(fji[a5].fjihe,fji[a7].fjihe);
					if(a6==(strlen(shizi[a5].right)-1))
						for(a8=0;a8<n;a8++)
                            if(a5!=a8 && shizi[a5].right[a6]==shizi[a8].left)
                            if(kongshi[a5].kongzuo!=1)
                            {
                                strcat(fji[a5].fjihe,fji[a8].fjihe);
							}
                            else
                                {
                                    strcat(fji[a5].fjihe,fji[a8].fjihe);
                                    strcat(fji[a5].fjihe,"#");
								}
                }
            }

    }
//////////////////////////////////
//int a10;//输出first-2
//for(a10=0;a10<n;a10++)
//{cout<<fji[a10].fjihe<<endl;
//}
/////////////////////////////////

//求follow集合

    follow fw[100];
    int b1,b2,b3,b4,b5,b6,b7,b8,b9,b10;
    char linshi5[2];
    for(b1=0;b1<n;b1++)
	{
	    fw[b1].fow[0]='\0';
	}
    fw[0].fow[0]='#';
    fw[0].fow[1]='\0';
    for(b8=0;b8<n;b8++)
	{
	    if(shizi[b8].left==shizi[0].left)
			fw[b8].fow[0]='#';
			fw[b8].fow[1]='\0';
	}
    int e1;
    for(e1=0;e1<2;e1++)
    for(b2=0;b2<n;b2++)
	for(b3=0;b3<n;b3++)
	{
	    if(shizi[b2].right[b3]>='A'&&shizi[b2].right[b3]<='Z')
        if(shizi[b2].right[b3+1]>='a'&&shizi[b2].right[b3+1]<='z')
        {
            linshi5[0]=shizi[b2].right[b3+1];
            linshi5[1]='\0';
            for(b9=0;b9<n;b9++)
            {
                if(shizi[b2].right[b3]==shizi[b9].left)
                strcat(fw[b9].fow,linshi5);
            }
        }
        if(shizi[b2].right[b3+1]>='A'&&shizi[b2].right[b3+1]<='Z')
        {
            for(b4=0;b4<n;b4++)
            {
                if(shizi[b2].right[b3+1]==shizi[b4].left)
                {
                    if(kongshi[b4].kongzuo!=1)
                    {
                        for(b10=0;b10<n;b10++)
                        {
                            if(shizi[b2].right[b3]==shizi[b10].left)
                            strcat(fw[b10].fow,fji[b4].fjihe);
                        }
                    }
                    else
                    {
                        for(b5=0;b5<n;b5++)
                        if(shizi[b2].right[b3]==shizi[b5].left)
                            strcat(fw[b5].fow,fw[b2].fow);
                    }
                }
            }
        }
        if((b3+1)==strlen(shizi[b2].right))
        {
            for(b7=0;b7<n;b7++)
            if(shizi[b2].right[b3]==shizi[b7].left)
                strcat(fw[b7].fow,fw[b2].fow);
        }
	}
/////////////////////////////////
//输出每个式子左部的follow
//for(b6=0;b6<n;b6++)
//{	cout<<fw[b6].fow<<endl;}
///////////////////////////////////

//合并相同左部的first 集合
    first2 fji2[100];
    int a11,a12,a13;
    for(a11=0;a11<n;a11++)
    {
        fji2[a11].fjihe2[0]='\0';
    }
    for(a12=0;a12<=n;a12++)
    for(a13=0;a13<n;a13++)
    {
        if(a12!=a13 && shizi[a12].left==shizi[a13].left)
            strcat(fji[a12].fjihe,fji[a13].fjihe);
    }
///////////////////////////////////
//int a14;//输出first-3,
//for(a14=0;a14<n;a14++)
//{cout<<fji[a14].fjihe<<endl;
//}
///////////////////////////////////
    char linshi3[100];
    char linshi4[2];
    int a15,a16,a17=0,a19=0,a21,a18;//

	for(a15=0;a15<n;a15++)
	{
	    {
	        for(a21=0;a21<99;a21++)
				linshi3[a21]='\0';
		}
		{
		    for(a16=0;a16<strlen(fji[a15].fjihe);a16++)
			{
			    if(a16==0)
                {
                    linshi4[0]=fji[a15].fjihe[a16];
                    linshi4[1]='\0';
                    strcat(linshi3,linshi4);
                    a16++;
				}
                for(a17=0;a17<=strlen(linshi3);a17++)
                if(linshi3[a17]==fji[a15].fjihe[a16])   break;//
                if(linshi3[a17]=='\0')
                {
                    linshi4[0]=fji[a15].fjihe[a16];
                    linshi4[1]='\0';
                    strcat(linshi3,linshi4);
                }
			}
		}
		strcat(fji2[a15].fjihe2,linshi3);
	}
/////////////////////////////////////////////////
//	cout<<"输出first集合"<<endl;
//	int a20;//输出first-4
//	for(a20=0;a20<n;a20++)
//	{cout<<fji2[a20].fjihe2<<endl;
//	}
////////////////////////////////////////////////
//合并相同左部的folow 集合
    follow2 fw2[100];
    int b11,b12,b13;
    for(b11=0;b11<n;b11++)
    {
        fw2[b11].fow2[0]='\0';
    }
    for(b12=0;b12<=n;b12++)
    for(b13=0;b13<n;b13++)
    {
        if(b12!=b13 && shizi[b12].left==shizi[b13].left)
            strcat(fw[b12].fow,fw[b13].fow);
    }
////////////////////////////////////////////
//	int b14;//输出first-3,
//	for(b14=0;b14<n;b14++)
//	{cout<<fw[b14].fow<<endl;
//	}
///////////////////////////////////////////
    char linshi6[100];
    char linshi7[2];
    int b15,b16,b17,b19=0,b21,b18;//
	for(b15=0;b15<n;b15++)
	{
	    {
	        {
	            for(b21=0;b21<99;b21++)
                    linshi6[b21]='\0';
			}
			{
			    for(b16=0;b16<strlen(fw[b15].fow);b16++)
				{
				    if(b16==0)
					{
					    linshi7[0]=fw[b15].fow[b16];
                        linshi7[1]='\0';
                        strcat(linshi6,linshi7);
                        b16++;

                    }
                    for(b17=0;b17<=strlen(linshi6);b17++)
                    if(linshi6[b17]==fw[b15].fow[b16])  break;//
                    if(linshi6[b17]=='\0')
                    {
                        linshi7[0]=fw[b15].fow[b16];
                        linshi7[1]='\0';
                        strcat(linshi6,linshi7);
                    }
				}
			}
		}
		strcat(fw2[b15].fow2,linshi6);
	}
////////////////////////////////////////
//cout<<"输出follow集合"<<endl;
//int b20;//输出follow-4
//for(b20=0;b20<n;b20++)
//{cout<<fw2[b20].fow2<<endl;
//}
/////////////////////////////////////////
//////输出最终结果：
    int c1,c2;
    cout<<"非终结符"<<"    "<<"first集合"<<endl;
    cout<<"  "<<shizi[0].left<<"          "<<fji2[0].fjihe2<<endl;
    for(c1=1;c1<n;c1++)
    {
        for(c2=0;c2<c1;c2++)
        {
            if(shizi[c1].left!=shizi[c2].left&&c2==(c1-1))
            cout<<"  "<<shizi[c1].left<<"          "<<fji2[c1].fjihe2<<endl;
        }
    }

    int d1,d2;
    cout<<"非终结符"<<"    "<<"follow集合"<<endl;
    cout<<"  "<<shizi[0].left<<"          "<<fw2[0].fow2<<endl;
    for(d1=1;d1<n;d1++)
    {
        for(d2=0;d2<d1;d2++)
        {
            if(shizi[d1].left!=shizi[d2].left&&d2==(d1-1))
            cout<<"  "<<shizi[d1].left<<"          "<<fw2[d1].fow2<<endl;
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

