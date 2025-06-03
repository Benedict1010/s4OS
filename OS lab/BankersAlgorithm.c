#include<stdio.h>

int main()
{
    int i,j,n,m,k,y,ind=0,alloc[30][30],max[30][30],avail[30];
    
    printf("Enter the no of processes:");
    scanf("%d",&n);
    
    printf("Enter the no of resources:");
    scanf("%d",&m);
    
    printf("Enter the allocation matrix:\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            scanf("%d",&alloc[i][j]);
        }
    }
    
    printf("Enter the max matrix:\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            scanf("%d",&max[i][j]);
        }
    }
    
    printf("Enter the available:\n");
    for(i=0;i<m;i++)
    {
        scanf("%d",&avail[i]);
    }
    
    int work[m],need[n][m],finish[n],safesequence[n];
    
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            need[i][j]=max[i][j]-alloc[i][j];
        }
    }
    
    printf("Need matrix:\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            printf("%d\t",need[i][j]);
        }
        printf("\n");
    }
    
    for(i=0;i<m;i++)
    {
        work[i]=avail[i];
    }
    
    for(i=0;i<n;i++)
    {
        finish[i]=0;
    }
    
    for(k=0;k<n;k++)
    {
        for(i=0;i<n;i++)
        {
            if(finish[i]==0)
            {
                int flag=0;
                for(j=0;j<m;j++)
                {
                    if(need[i][j]>work[j])
                    {
                        flag=1;
                        break;
                    }
                }
                if(flag==0)
                {
                    safesequence[ind++]=i;
                    for(y=0;y<m;y++)
                    {
                        work[y]=work[y]+alloc[i][y];
                        finish[i]=1;
                    }
                }
            }
        }
    }
    
    printf("Then The Safesequence of processes :\n");
    for(i=0;i<n;i++)
    {
        printf("P%d",safesequence[i]);
    }
    
    return 0;
}
