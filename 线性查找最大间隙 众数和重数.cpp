/*#include<iostream>
using namespace std;
int main()
{
    float a[100],Max;
    int n,i,j;
    cin>>n;
    for(i=0;i<n;i++)
        cin>>a[i];
    for(i=n-1;i>0;i--)      //��n����ֵ����
        for(j=0;j<i;j++)
        if(a[j]>a[j+1])
           {
             Max=a[j];
             a[j]=a[j+1];
             a[j+1]=Max;
           }
    for(Max=a[1]-a[0],i=1;i<n;i++) //���������������Ĳ��ȡ���ֵ
        if(a[i]-a[i-1]>Max)
            Max=a[i]-a[i-1];
    cout<<Max<<endl;
}*/


//�����㷨ʵ������϶����
/*#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<iomanip>
using namespace std;
double Max(double*,int);
double Min(double*,int);
double Max_Gap(double*,int n,double Max,double Min);
int main()
{
    int n,i;
    double num[100],gap;
    char filename[50];
    FILE *fp=NULL;
    cout<<"�����ļ����ƣ�";
    cin>>filename;
    if((fp=fopen(filename,"r"))==NULL)
    {
        cout<<"Can not open file1";
        exit(0);
    }
    fscanf(fp,"%d",&n);
    cout<<"���ݸ���:"<<n<<endl<<"���ݣ�";
    for(i=1;i<=n;i++)
        {
            fscanf(fp,"%lf",&num[i]);
            cout<<num[i]<<" ";
        }
    gap=Max_Gap(num,n,Max(num,n),Min(num,n));
    cout<<endl<<"����϶�ǣ�"<<gap<<endl;
    if((fp=fopen("output.txt","w"))==NULL)
        cout<<"ERROR"<<endl;
    fprintf(fp,"%lf",gap);
    system("pause");
    return 0;
}
double Max(double *num,int n)
{
    int i;
    double M;
    for(M=num[1],i=2;i<=n;i++)
        if(num[i]>M)
           M=num[i];
    return M;
}
double Min(double *num,int n)
{
    int i;
    double M;
    for(M=num[1],i=2;i<=n;i++)
        if(num[i]<M)
           M=num[i];
    return M;
}
double Max_Gap(double *num,int n,double Max,double Min)
{
    double low[100],high[100],Gap;
    double avg=(Max-Min)/(n-1);        //�����䡾min,max������n-1�����䣬�����乲����n-2����������һ������Ϊ�գ�����϶�ذ���������
    int Count[100],i,j;
    for(i=1;i<=n;i++)
    {
       low[i]=Max;                     //��ʼ��ΪMax��Min,�Ϳ��ǵ�mum[i]=Min��Max
       high[i]=Min;
       Count[i]=0;
    }
    for(i=1;i<=n;i++)
    {
        int index=(num[i]-Min)/avg+1;  //mum[i]���������±�,����ǰ�պ�
        if(index==n) index--;
        Count[index]++;
        if(num[i]<low[index])          //num[i]��Ӧ���������䣬��ÿ���������ֵ
            low[index]=num[i];
        if(num[i]>high[index]);        //����>=,Max����ʼ��Ϊ���ֵ
            high[index]=num[i];
    }
    for(j=1,i=2,Gap=0;i<=n-1;i++)
    {
        if(Count[i])
        {
            if(Gap<low[i]-high[j])
                Gap=low[i]-high[j];
            j=i;
        }
    }
    return Gap;
}*/

//����������
#include<iostream>
using namespace std;
int main()
{
    int n,i,j,Count[2][100]={0},Max;
    cout<<"�������ݸ�����";
    cin>>n;
    cout<<"�������ݣ�";
    for(i=1;i<=n;i++)
        cin>>Count[0][i];
    for(i=1;i<=n;i++)
        for(j=i;j<=n;j++)
        if(Count[0][j]==Count[0][i]&&Count[1][i]!=-1)
        {
            Count[1][i]++;
            if(i!=j)
            Count[1][j]=-1;
        }
    for(Max=1,i=2;i<=n;i++)
        if(Count[1][Max]<Count[1][i])
            Max=i;
    cout<<"������"<<Count[0][Max]<<endl;
    cout<<"������"<<Count[1][Max]<<endl;
    return 0;
}
