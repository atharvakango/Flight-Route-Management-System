#include<stdio.h>
#include<stdlib.h>


static int count=0;
char *name[100];

typedef struct node
{
    int data;
    struct node *next;
}node;

typedef struct snode
{
    int data;
    struct snode *snext;
}stack;

typedef struct vertex
{
    struct vertex *vnext;
    int datav;
    node *nnext;
   //static int c;
}vertex;

stack * check(stack *stop);
vertex* addvertex(vertex *top,int d);
void addedge(vertex *top,int x,int y);
node * vertexSearch(vertex *top,stack *stop,int d,int des);
void path(vertex *top,stack *stop,node *a,int des);
stack* pops(stack *stop,int *n);
void display(stack *stop);
int pop(stack *t);
stack* push(stack *stop,int dat);
void pathFound();



stack* check(stack *stop)
{

    stack *a=stop;
    int c=a->data;
    int n;
    a=a->snext;
    while(a->data!=c )
    {
       a=a->snext;
       if(!a)break;

    }
    if(a!=NULL)
        stop=pops(stop,&n);

    return stop;
}


vertex* addvertex(vertex *top,int d)
{
    vertex *a=top;

    vertex *new1=(vertex *)malloc(sizeof(vertex));
    new1->vnext=NULL;
    new1->nnext=NULL;
    new1->datav=d;

    if(top==NULL)
    {
            top=new1;
            return top;
    }
    else
    {
        while(a->vnext!=NULL)
        {
            a=a->vnext;
        }
        a->vnext=new1;

    }
    return top;
}

void addedge(vertex *top,int x,int y)
{
    vertex *a=top;

    node * new2=(node *)malloc(sizeof(node));
    new2->next=NULL;
    new2->data=y;



    while(a)
    {
        if(a->datav==x){
            break;
        }
        a=a->vnext;
    }

    if(a==NULL)
    {
        printf("\nInvalid node");
        return;

    }
    else
    {

        if(a->nnext==NULL)
        {
            a->nnext=new2;
        }
        else
        {
            node *a1=a->nnext;
            while(a1->next!=NULL)
                    a1=a1->next;

                        a1->next=new2;

        }
    }
}

node * vertexSearch(vertex *top,stack *stop,int d,int des)
{
     vertex *a=top;
     while(d==des)
     {
         display(stop);
         printf("\n");
         int n;
         if(stop==NULL)
            exit(0);
         stop=pops(stop,&n);
         d=stop->data;
     }

     while(a!=NULL)
     {
         if(a->datav==d)
         {
             path(top,stop, a->nnext, des);

         }

            a=a->vnext;
     }
}

void path(vertex *top,stack *stop,node *a,int des)
{
    stack *h;
    node *b=a;
    int y=b->data;
    a=a->next;
    while(a!=NULL)
    {
        if(a->data==0)
            stop=push(stop,-100);
        else
            stop=push(stop, - a->data);
        a=a->next;
    }
    stop=push(stop,b->data);
   stop= check(stop);
    if(stop!=NULL)
    {
        h=stop;
        y=h->data;
    }
    vertexSearch( top,stop,y,des);
}


stack* pops(stack *stop,int *n)
{
    stack *a=stop;

    while(stop)
    {
        if(stop->data < 0)
            break;
        stop=stop->snext;
    }
    if(stop==NULL)
    {
        exit(0);
    }
    if(stop->data==-100)
        stop->data+=100;
        else
    stop->data= -stop->data;
    stop=check(stop);
    *n=stop->data;
    return stop;
}



void display(stack *stop)
{
    stack *tmp;//new stack
    stack *a=stop;
    int arr[100];
    int i=0;
    int j;

    while(a!=NULL)
    {

         arr[i]=a->data;

        a=a->snext;
        i++;
    }

    for( j=i-1;j>=0;j--)
    {

        if(arr[j]>=0)
        printf("%s ",name[arr[j]]);
    }

}

int pop(stack *t)
{
    int a=t->data;
    t=t->snext;
    return a;
}

stack* push(stack *stop,int dat)
{
    stack *a=(stack *)malloc(sizeof(stack));
    a->data=dat;
    a->snext=NULL;
    if(stop==NULL)
    {
        stop=a;
        return stop;
    }
    a->snext=stop;
    stop=a;
    return stop;
}



void pathFound()
{
    exit(0);
}


void input (vertex *top,char *s)
{
    name[count]=s;

    top=addvertex(top,count);

    count++;
}

void inputedge( vertex *top,char *s,char *t)
{
    int i;
    int j;
    int x;
    int y;


    for(i=0;i<count;i++)
    {
        if(strcmp(s,name[i])==0)
        {
            x=i;

            break;
        }
    }
    if(i==count)
    {
        printf("\nInvalid edge");
        return;
    }



     for(j=0;j<count;j++)
    {
        if(strcmp(t,name[j])==0)
         {
             y=j;

             break;
         }
    }

   if(j==count)
    {
        printf("\nInvalid edge");
        return;
    }

        addedge(top,x,y);
    return;
}

void displayinput(vertex *top)
{
    vertex *a=top;
    while(a!=NULL)
    {
        printf("%s->",name[a->datav]);
        node *b=a->nnext;
        while(b!=NULL)
        {
            printf("-%s",name[b->data]);
            b=b->next;
        }
        a=a->vnext;
        printf("\n");
    }
}


int srcdst(char *t)
{
    int i;
    for(i=0;i<count;i++)
    {
            if(strcmp(t,name[i])==0)
            {
                return i;
            }
    }

}


FromFile()
{
    FILE *fp;
    fp=fopen("TC1.txt","r");
    int opt,i,v,NoVrtx,NoEdg,source,destination,p,q;
    char *CName,*s,*d,*src,*des;
    stack *stop=NULL;
    vertex *top=NULL;
    fscanf(fp,"%d",&opt);
    for(i=0;i<opt;i++)
    {
        CName=(char*)malloc(100*sizeof(char));
        fscanf(fp,"%s",CName);
        name[count]=CName;
        top=addvertex(top,count);
        count++;
    }
    fscanf(fp,"%d",&v);
    for(i=0;i<v;i++)
    {
        s=(char*)malloc(100*sizeof(char));
        d=(char*)malloc(100*sizeof(char));
        fscanf(fp,"%s %s",s,d);
        inputedge(top,s,d);
    }
    src=(char*)malloc(100*sizeof(char));
    des=(char*)malloc(100*sizeof(char));
    fscanf(fp,"%s %s",src,des);

    source=srcdst(src);
    destination=srcdst(des);
    stack* a=(stack*)malloc(sizeof(stack));
    a->data=source;
    a->snext=NULL;
    stop=a;
    displayinput(top);
    vertexSearch(top,stop,source,destination);
    fclose(fp);
}


int main()
{
    int opt,i,v,NoVrtx,NoEdg,source,destination;
    char *CName,*s,*d,*src,*des;
    stack *stop=NULL;
    vertex *top=NULL;
    while(1)
    {
        printf("\nMenu\n1.Add Vertex\n2.Add Edges\n3.Enter Source And Destination to find paths\n4.Get Input From File\nOption : ");
        scanf("%d",&opt);
        if(opt>5 || opt<1)
            break;
        switch(opt)
        {
        case 1:
            printf("Enter City : ");
            CName=(char*)malloc(100*sizeof(char));
            scanf("%s",CName);
            name[count]=CName;
            top=addvertex(top,count);
            count++;
            break;
        case 2:
            printf("Enter edges");
            s=(char*)malloc(100*sizeof(char));
            d=(char*)malloc(100*sizeof(char));
            scanf("%s %s",s,d);
            inputedge(top,s,d);
            break;
        case 3:
            printf("Enter source & destination : ");
            src=(char*)malloc(100*sizeof(char));
            des=(char*)malloc(100*sizeof(char));
            scanf("%s %s",src,des);
            source=srcdst(src);
            destination=srcdst(des);
            stack* a=(stack*)malloc(sizeof(stack));
            a->data=source;
            a->snext=NULL;
            stop=a;
            vertexSearch(top,stop,source,destination);
            break;
        case 4:
            FromFile();
        case 5:
            displayinput(top);


        }
    }
        return 0;

}
