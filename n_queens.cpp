//ultimate
#include<bits/stdc++.h>
using namespace std;
int arr[100][100]={(0,0)};
int n;
int count1=0;
int out=0;
int check(int posx,int posy)
{
    for(int i=0;i<n;i++)
    {
        if(arr[posx][i]==1)
        {
            return 0;
        }
    }
    for(int i=0;i<n;i++)
    {
        if(arr[i][posy]==1)
        {
            return 0;
        }
    }
    for(int i=0;posx+i<n;i++)
    {
        if(arr[posx+i][posy+i]==1)
        {
            return 0;
        }
    }
    for(int i=0;posx+i<n;i++)
    {
        if(arr[posx+i][posy-i]==1)
        {
            return 0;
        }
    }
    for(int i=0;posx-i>=0;i++)
    {
        if(arr[posx-i][posy+i]==1)
        {
            return 0;
        }
    }
    for(int i=0;posx-i>=0;i++)
    {
        if(arr[posx-i][posy-i]==1)
        {
            return 0;
        }
    }
    return 1;
}
void show_queens()
{
	cout<<endl;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(arr[i][j]==0)
			{
				cout<<"* ";
			}
			else
			{
				cout<<"Q ";
			}
		}
		cout<<endl;
	}

}
void print()
{
    cout<<"\n[";
for(int i=0;i<n;i++)
{
    for(int j=0 ;j<n;j++)
    {
        if(arr[i][j]==1)
        {
            cout<<"("<<i+1<<","<<j+1<<")"<<" ";
        }
    }
}
cout<<"]\n";
show_queens();
}
int goin(int row)
{
    int flag=0;
    for(int i=0;i<n;i++)
    {
        
        if(check(row,i))
        {
            
            count1++;
            arr[row][i]=1;
            if(count1==n)
            {
                print();
                arr[row][i]=0;
                count1--;
                out=1;
                return 1;
            }
            
            
            flag=1;
            
            int res=goin(row+1);
            if(res==0)
            {
                count1--;
                flag=0;
                arr[row][i]=0;
            }
            else
            {
                 count1--;
                arr[row][i]=0;
                
            }
            
        }
    }
    if(flag==0)
    {
        return 0;
    }
}




int main()
 {
	int t,p;
	cout<<"Enter the number of test cases : ";
        cin>>t;
        while(t--)
        {
          cout<<"Enter the size of chess board : ";
          cin>>n;
          
          int res=goin(0);
          if(out==0)
          {
              cout<<"N queens not possible for this size\n";
          }
          cout<<endl;
          out=0;
        }

	return 0;
}
