#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

typedef struct 
{
    int dd;
    int mm;
    int yy;
}dob;
	
typedef struct 
{
	char name[20];
	char usn[10];
	dob db;
	char adr[50];
}student;
 
void listrec(student std)
{
   	FILE *fp;
	fp=fopen("stdbase1.dat","rb+");
        //student std;
	if(fp==NULL)
	{
	   printf("Cannot open a file\n");
	   exit(0);
	}	

	printf("Student details are as follows\n");
    printf("\nName\t\tUSN\t\tDate of Birth\t\tAddress\n");
    printf("-------------------------------------------------------------------------------------------\n");
    while(fread(&std,sizeof(std),1,fp)==1)
      printf("%s\t\t%s\t\t%d/%d/%d\t\t%s\n",std.name,std.usn,std.db.dd,std.db.mm,std.db.yy,std.adr);

    fclose(fp);

}

void writerec(student std)
{
	FILE *fp;

	fp=fopen("stdbase1.dat","ab+");
	if(fp==NULL)
	{
	   printf("Cannot open a file\n");
	   exit(0);
	}
	fwrite(&std,sizeof(std),1,fp);
	
    fclose(fp);
}



void modifyrec(char *argv,student std1)
{
    FILE *fp;
    int flag=1;
    student std;
	fp=fopen("stdbase1.dat","rb+");

	if(fp==NULL)
	{
	   printf("Cannot open a file\n");
	   exit(0);
	}	
	fflush(stdin);
	rewind(fp);
    
    while(fread(&std,sizeof(std),1,fp)==1)
    {
    	if(strcmp(std.usn,argv)==0)
    	{
    	  flag=0;
    	  fseek(fp,-sizeof(std),SEEK_CUR);
          fwrite(&std1,sizeof(std1),1,fp);
        
	    }
	    //else
          //fwrite(&std1,sizeof(std1),1,fp);
    }
    if(flag==1)
    	printf("Requested USN Not found");
    else
    	printf("Modified");
   

    fclose(fp);
}

void delerec(char *argv)
{
    FILE *fp,*ft;
    int flag=1;
    student std;
	fp=fopen("stdbase1.dat","rb+");
	if(fp==NULL)
	{
	   printf("Cannot open a file\n");
	   exit(0);
	}
	ft=fopen("temp.dat","wb+");
	if(fp==NULL)
	{
	   printf("Cannot open a file\n");
	   exit(0);
	}

    rewind(fp);

	while(fread(&std,sizeof(std),1,fp)==1)
	{
		if(strcmp(std.usn,argv)!=0)
		{
			
			fwrite(&std,sizeof(std),1,ft);
		}

	}

	rewind(fp);
	while(fread(&std,sizeof(std),1,fp)==1)
	{
		if(strcmp(std.usn,argv)==0)
		{
			
			flag=0;
		}

	}	

	
	fclose(ft);
	fclose(fp);
	system("rm stdbase1.dat");
	system("mv temp.dat stdbase1.dat");
	
	if(flag==0)
 		printf("Deleted successfuly");
    else
    	printf("Enter the correct USN");
	
	
	
}

void Searchrec(char *argv)
{
	FILE *fp;
	int flag=1;
        student std;
	
	fp=fopen("stdbase1.dat","rb+");

	if(fp==NULL)
	{
		printf("cannot open a file\n");
		exit(0);
	}

	rewind(fp);
	printf("\nYour requested Search is:\n");
	printf("\nName\t\tUSN\t\tDate of Birth\t\tPlace\n");
	printf("----------------------------------------------------------------------------------------------------------\n");
	
	while(fread(&std,sizeof(std),1,fp))
	{
	    if((strstr(std.usn,argv)))
	    {
	    	flag=0;
			printf("%s\t\t%s\t\t%d/%d/%d\t\t%s\n",std.name,std.usn,std.db.dd,std.db.mm,std.db.yy,std.adr);
	    }

		else if((strstr(std.name,argv)))
		{
			flag=0;
      		printf("%s\t\t%s\t\t%d/%d/%d\t\t%s\n",std.name,std.usn,std.db.dd,std.db.mm,std.db.yy,std.adr);
		}

		else if((strstr(std.adr,argv)))
		{
			flag=0;
			printf("%s\t\t%s\t\t%d/%d/%d\t\t%s\n",std.name,std.usn,std.db.dd,std.db.mm,std.db.yy,std.adr);
		}
	    
	}
	if(flag==1)
		printf("Not Found");
	
	
    fclose(fp);

}

int convert(char *s)
{
    int num=0,i=0;
    while(s[i])
    {
       num=num*10+s[i]-'0';
       i++;
    }
    return (num);
}

int main(int argc, char *argv[])
{
    student std,std1;
        if(!strcmp(argv[1],"-a"))
        {
    		    strcpy(std.name,argv[2]);
    		    strcpy(std.usn,argv[3]);
    		    std.db.dd=convert(argv[4]);
    		    std.db.mm=convert(argv[5]);
    		    std.db.yy=convert(argv[6]);
    		 	strcpy(std.adr,argv[7]);
    		 	writerec(std);
        }
        else if(!strcmp(argv[1],"-l"))
    	    listrec(std);
    	   		
    	else if(!strcmp(argv[1],"-m") )           
    	{
    	        
                strcpy(std1.name,argv[3]);
    		    strcpy(std1.usn,argv[4]);
    		 	std1.db.dd=convert(argv[5]);
    		    std1.db.mm=convert(argv[6]);
    		    std1.db.yy=convert(argv[7]);
    		 	strcpy(std1.adr,argv[8]);
				modifyrec(argv[2],std1);
	    }
    	 else if(!strcmp(argv[1],"-d"))  

    	    delerec(argv[2]);
    	      
        else if(!strcmp(argv[1],"-s"))
    	    Searchrec(argv[2]);
    	        

    	
    

    return (0);

}
