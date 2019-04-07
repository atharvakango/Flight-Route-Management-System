#include<stdio.h>

void main()
{
    FILE *fp;
    int NoVrtx,v,NoEdg,s,d,Co;
    int i;
    char *CName[100];
    char ch[100],sh[100],src[100],des[100];
    fp=fopen("TC1.txt","w");

    printf("Enter Number of cities : ");
    scanf("%d",&Co);
    fprintf(fp,"%d\n",Co);
    for(i=0;i<Co;i++)
    {
        printf("Enter Cities : ");
        scanf("%s",CName);
        fprintf(fp,"%s ",CName);
    }
    printf("Enter Edges number ");
    scanf("%d",&NoEdg);
    fprintf(fp,"\n%d\n",NoEdg);
    for(i=0;i<NoEdg;i++)
    {
        printf("enter paths : ");
        scanf("%s %s",ch,sh);
        fprintf(fp,"%s %s\n",ch,sh);

    }
    printf("Enter Src And Des : ");
    scanf("%s %s",src,des);
    fprintf(fp,"%s %s",src,des);
    fclose(fp);
    return;
}
