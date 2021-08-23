#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>

typedef struct 
{
	char name[20];
	int number;
	char branch[5];
	int ppsmarks;
	int beemarks;
	int egdmarks;
	int totalmarks;
	// We can also deifne sem wise marks but it will become more complex in this scenario.....>>>>>>>>>>>>>>>>>>>>>

}stu;
//######################################################################################################################



FILE *fp;


//########################################################################################################################



void storedetails(stu *student)
{
	fp=fopen("DATA","a+");
	if(fp==NULL)
	{
		printf("ERROR\n");
		exit(0);
	}
	fprintf(fp,"%s :%d :%s pps:%d bee:%d egd:%d total:%d\n",student->name,student->number,student->branch,student->ppsmarks,student->beemarks,student->egdmarks,student->totalmarks);
	fclose(fp);

}



//#######################################################################################################################



void Registerin(stu *ptr)
{
	printf("Enter the numbers of student that you want to store at this time....\n");
	int n;
	scanf("%d",&n);
	for (int i = 0; i < n; ++i)
	{
		printf("Enter Student name\n");
		fscanf(stdin,"%s",ptr->name);
		printf("Enter Student Roll number\n");
		fscanf(stdin,"%d",&ptr->number);
		printf("Enter Student Branch Name\n");
		fscanf(stdin,"%s",ptr->branch);
		printf("Enter marks in pps\n");
		fscanf(stdin,"%d",&ptr->ppsmarks);
		printf("Enter marks in bee\n");
		fscanf(stdin,"%d",&ptr->beemarks);
		printf("Enter marks in egd\n");
		fscanf(stdin,"%d",&ptr->egdmarks);

		ptr->totalmarks = ptr->ppsmarks + ptr->beemarks + ptr->egdmarks;

		storedetails(ptr);//store input in files
		
	}
}



//########################################################################################################################


void printall()
{
	fp=fopen("DATA","a+");
	rewind(fp);
	int count=0;
	stu all;
	printf("Registrations...\n\n");
	while(!feof(fp))
	{
		count++;
		fscanf(fp,"%s :%d :%s pps:%d bee:%d egd:%d total:%d\n",all.name,&all.number,all.branch,&all.ppsmarks,&all.beemarks,&all.egdmarks,&all.totalmarks);

		fprintf(stdout,"%s :%d :%s pps:%d bee:%d egd:%d total:%d\n",all.name,all.number,all.branch,all.ppsmarks,all.beemarks,all.egdmarks,all.totalmarks);
		
	}
	printf("Total number of registration are %d\n",count);
	fclose(fp);
}


//########################################################################################################################


void countforbranch(char branch[])
{
	fp=fopen("DATA","a+");
	rewind(fp);
	stu ball;
	int count =0;
	printf("Registrations for this branch are given below.....\n\n");
	while(!feof(fp))
	{
		fscanf(fp,"%s :%d :%s pps:%d bee:%d egd:%d total:%d\n",ball.name,&ball.number,ball.branch,&ball.ppsmarks,&ball.beemarks,&ball.egdmarks,&ball.totalmarks);
		if(!strcasecmp(ball.branch,branch))
		{
			count++;
			fprintf(stdout,"%s :%d :%s pps:%d bee:%d egd:%d total:%d\n",ball.name,ball.number,ball.branch,ball.ppsmarks,ball.beemarks,ball.egdmarks,ball.totalmarks);
		}
	}

	printf("Total Number Of Registration For %s Is %d\n",branch,count);
	fclose(fp);
}


//########################################################################################################################


void printnameofhighest(char branch[],int temp)
{
	fp=fopen("DATA","a+");
	rewind(fp);
	stu ball;
	printf("Highest Total Marks holder name in %s Branch are .....\n",branch);
	while(!feof(fp))
	{
		fscanf(fp,"%s :%d :%s pps:%d bee:%d egd:%d total:%d\n",ball.name,&ball.number,ball.branch,&ball.ppsmarks,&ball.beemarks,&ball.egdmarks,&ball.totalmarks);
		if(!strcasecmp(ball.branch,branch))
			if(ball.totalmarks == temp)
			{
				fprintf(stdout,"%s :%d :%s pps:%d bee:%d egd:%d total:%d\n",ball.name,ball.number,ball.branch,ball.ppsmarks,ball.beemarks,ball.egdmarks,ball.totalmarks);
			}
	}

	fclose(fp);
}

//########################################################################################################################


void printhighest(int temp)
{
	fp=fopen("DATA","a+");
	rewind(fp);
	stu ball;
	printf("And That Student Name is...\n\n");
	while(!feof(fp))
	{
		fscanf(fp,"%s :%d :%s pps:%d bee:%d egd:%d total:%d\n",ball.name,&ball.number,ball.branch,&ball.ppsmarks,&ball.beemarks,&ball.egdmarks,&ball.totalmarks);
		if(ball.totalmarks == temp)
			fprintf(stdout,"%s :%d :%s pps:%d bee:%d egd:%d total:%d\n",ball.name,ball.number,ball.branch,ball.ppsmarks,ball.beemarks,ball.egdmarks,ball.totalmarks);
	}
	fclose(fp);
}


//########################################################################################################################


void highest()
{
	fp = fopen("DATA","a+");
	rewind(fp);
	int temp=0;
	stu ball;
	while(!feof(fp))
	{
		fscanf(fp,"%s :%d :%s pps:%d bee:%d egd:%d total:%d\n",ball.name,&ball.number,ball.branch,&ball.ppsmarks,&ball.beemarks,&ball.egdmarks,&ball.totalmarks);
		if(ball.totalmarks > temp)
			temp = ball.totalmarks;
	}
	printf("Highest Marks is %d\n",temp);
	fclose(fp);
	printhighest(temp);
}

//#########################################################################################################################



void highestbranch(char branch[])
{
	fp=fopen("DATA","a+");
	rewind(fp);
	int temp=0;
	stu ball;
		
//	fscanf(fp,"%s :%d :%s pps:%d bee:%d egd:%d total:%d\n",ball.name,&ball.number,ball.branch,&ball.ppsmarks,&ball.beemarks,&ball.egdmarks,&ball.totalmarks);	
//	printf("%d\n", temp);


	while(!feof(fp))
	{
		fscanf(fp,"%s :%d :%s pps:%d bee:%d egd:%d total:%d\n",ball.name,&ball.number,ball.branch,&ball.ppsmarks,&ball.beemarks,&ball.egdmarks,&ball.totalmarks);
		if(!strcasecmp(ball.branch,branch))
			if(ball.totalmarks > temp)
			{
				temp = ball.totalmarks; 
			}
	}
	printf("Highest Marks in %s branch is %d\n",branch,temp);

	fclose(fp);

	printnameofhighest(branch,temp);
/*	while(!feof(fp))
	{
		fscanf(fp,"%s :%d :%s pps:%d bee:%d egd:%d total:%d\n",ball.name,&ball.number,ball.branch,&ball.ppsmarks,&ball.beemarks,&ball.egdmarks,&ball.totalmarks);
		if(!strcasecmp(ball.branch,branch))
			if(ball.totalmarks == temp)
			{
				fprintf(stdout,"%s :%d :%s pps:%d bee:%d egd:%d total:%d\n",ball.name,ball.number,ball.branch,ball.ppsmarks,ball.beemarks,ball.egdmarks,ball.totalmarks);
			}
	}*/
	
//	fclose(fp);
}
//########################################################################################################################


void printname(int temp)
{
	fp = fopen("DATA","a+");
	rewind(fp);
	stu ball;
	printf("And That Student is......\n"); 
	while(!feof(fp))
	{
		fscanf(fp,"%s :%d :%s pps:%d bee:%d egd:%d total:%d\n",ball.name,&ball.number,ball.branch,&ball.ppsmarks,&ball.beemarks,&ball.egdmarks,&ball.totalmarks);
		if(temp == ball.ppsmarks || temp == ball.egdmarks || temp == ball.beemarks)
			fprintf(stdout,"%s :%d :%s pps:%d bee:%d egd:%d total:%d\n",ball.name,ball.number,ball.branch,ball.ppsmarks,ball.beemarks,ball.egdmarks,ball.totalmarks);
			
	}
	fclose(fp);
}

//########################################################################################################################



int subjecthighest()
{
	fp =fopen("DATA","a+");
	rewind(fp);
	printf("Enter Subject name\n1.pps\n2.egd\n3.bee\n");
	char sub[10];
	scanf("%s",sub);
	stu ball;
	
	
	int temp=0;
	while(!feof(fp))
	{
		fscanf(fp,"%s :%d :%s pps:%d bee:%d egd:%d total:%d\n",ball.name,&ball.number,ball.branch,&ball.ppsmarks,&ball.beemarks,&ball.egdmarks,&ball.totalmarks);
		if(strcasecmp(sub,"pps")==0)
		{
			if(ball.ppsmarks > temp)
			{
				temp = ball.ppsmarks;
			}
		}
		else if(strcasecmp(sub,"bee")==0)
		{
			if(ball.beemarks > temp)
			{
				temp = ball.beemarks;
			}
		}
		else if(strcasecmp(sub,"egd")==0)
		{
			if(ball.egdmarks > temp)
			{
				temp = ball.egdmarks;
			}
		}
	}
	printf("Highest Marks in %s is %d\n",sub,temp);
	fclose(fp);
	printname(temp);
}


//########################################################################################################################



int main(int argc, char const *argv[])
{
	stu student;
	int choice;
	printf("1.Register New Entry\n2.Print All Registration\n3.Print Count and print For Branch\n4.Print Highest Marks in university\n5.Print Highest Marks in a branch\n6.Print Highest Marks in a subject\n");
	
	while(scanf("%d",&choice)){
	switch(choice){

		case 1:
	//	printf("How many number of student that you want to store at this time...\n");
	//	int n;
	//	scanf("%d",&n);

	//	for (int i = 0; i < n; ++i)
	//	{
			Registerin(&student);//take user input
			//storedetails(student);
	//	}
		break;

		case 2:
		printf("All Registrations.....\n");
		printall();
		break;

		case 3:
		printf("Which perticular Branch's Registration You want to print and count.....\n1.CE\n2.CH\n3.EC\n4.CIVIL\n5.IT\ntype branch name\n");
		char branchchoice1[10];
		scanf("%s",branchchoice1);
		countforbranch(branchchoice1);
		break;

		case 4:
		printf("Highest Marks In University is");
		highest();
		break;

		case 5:
		printf("Enter branch name for counting highest marks..........\n");
		char branchchoice2[10];
		scanf("%s",branchchoice2);
		highestbranch(branchchoice2);
		break;

		case 6:
	//	printf("Enter Subject Name For printing highest marks in a subject.....\n");
		subjecthighest();
		break;

		// case 7:
		



	}}

	return 0;
}