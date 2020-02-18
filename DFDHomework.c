#include <stdio.h>
#include <string.h>
#include <stdbool.h>
enum Choice {ENTER_RECORD=1,VIEW_DAY,VIEW_WEEK,MODIFY,DELETE,SEARCH,QUIT};
enum WWWW {WHEN=1,WHO,WHERE,WHAT}; //4 �� W 


typedef struct Record 
{
	char date[5];
	char name[21];
	char location[31];
	char thing[81];
	
}record;

int enterchoice()
{
	printf("Enter a number.\nWhich service you want??\n");
	printf("1-Enter the who/when/what/where information.\n");
	printf("2-View a day.\n");
	printf("3-View a week.\n");
	printf("4-Modify a record.\n");
	printf("5-Delete a record.\n");
	printf("6-Search a record by one of when/what/who/where.\n");
	printf("7-Quit after save the record or discard.\n --> ");
	
	int choice;
	scanf("%d",&choice);
	return choice;
};

record InitialRecord(record initial)
{
	
	strcpy( initial.date , "0" );
	strcpy( initial.location , "Null" );
	strcpy( initial.name , "Null" );
	strcpy( initial.thing , "Null" );
	return initial;
}

record EnterRecord(record newrecord[],int i) //�n��warn if ��J��time�s�b
{
	int j;
	bool flag=true;
	do
	{
		setbuf(stdin, NULL);  //�M��buffer�̪� \n �ϱo[^\n]���`�B�@ 
		printf("Enter date (1~31): ");
		scanf("%[^\n]",&newrecord[i].date);
		for(j=0;j<i;j++)
		{
			if(atoi(newrecord[i].date)==atoi(newrecord[j].date))
			{
				printf(" the date exist. \n" );
				flag=false;
			}
			else
			{
				flag=true;
			}
		}	
	}while( atoi(newrecord[i].date)>31 || atoi(newrecord[i].date)<=0 || flag==false );
	
	setbuf(stdin, NULL);  //�M��buffer�̪� \n �ϱo[^\n]���`�B�@ 
	printf("Enter name : ");
	scanf("%[^\n]",&newrecord[i].name);
	
	setbuf(stdin, NULL);  //�M��buffer�̪� \n �ϱo[^\n]���`�B�@ 
	printf("Enter location : ");
	scanf("%[^\n]",&newrecord[i].location);
	
	setbuf(stdin, NULL);  //�M��buffer�̪� \n �ϱo[^\n]���`�B�@ 
	printf("Enter thing : ");
	scanf("%[^\n]",&newrecord[i].thing);

	return *newrecord;
};
void ViewDay(record viewrecord[],int n)
{
	//�̩��U������Ū���ɮ׿�X���覡 
	int i,temp;
	for(i=0;i<10;i++)
	{
		temp=atoi(viewrecord[i].date);
		if(temp==n)
		{
			printf("-> Date: %s \t-> Name: %-20s\n",viewrecord[i].date,viewrecord[i].name);
			printf("-> Location: %-30s\n",viewrecord[i].location);
			printf("-> Thing: %-80s\n",viewrecord[i].thing);
			printf("-----------------------\n");
			break;;
		}
	}
};

void ViewWeek(record viewrecord[],int n)
{
	//�̩��U������Ū���ɮ׿�X���覡
	int i,j,temp;
	for(j=n;j<n+7;j++)
	{
		bool flag=false;  //�Y������date��record flag�]��true 
		
		for(i=0;i<10;i++)  //��䦳�S��������record 
		{
			temp=atoi(viewrecord[i].date);
		
			if( temp== j ) //���N�L�X�� 
			{
				printf("-> Date: %s \t-> Name: %-20s\n",viewrecord[i].date,viewrecord[i].name);
				printf("-> Location: %-30s\n",viewrecord[i].location);
				printf("-> Thing: %-80s\n",viewrecord[i].thing);
				printf("-----------------------\n");
				flag=true;
			}
		}	
		if(!flag) //�S����� flag �� false �A !flag �� true 
		{
			printf("-> Date: %-2d \t-> Name: Null\n",j);
			printf("-> Location: Null\n");
			printf("-> Thing: Null\n");	
			printf("-----------------------\n");
		}
	}	
};//modify�S�g�n 
record Modify(record modifyrecord[],int n)
{
	int i,j=0,temp;
	record temprecord[10];
	bool flag=false;
	for(i=0;i<10;i++)
		InitialRecord(temprecord[i]);
	
	for(i=0;i<10;i++)
	{
		if(atoi(modifyrecord[i].date)==n)
		{
			flag=true;
			break;
		}
	}
	if(!flag)
	{
		printf("\n----------the date record can not found !!-----------\n\n ");
		return *modifyrecord;;
	}
	printf("\nEnter a number.\nWhich choice you want??\n");
	printf("1-Modify when.\n");
	printf("2-Modify who.\n");
	printf("3-Modify where.\n");
	printf("4-Modify what.\n");
	
	int modify_choice;
	scanf("%d",&modify_choice);

	switch( modify_choice )
	{	
		case WHEN:
		{
			int date;
			do
			{
				printf("Enter a new date number : ");
				scanf("%d",&date);
			}while(date>31 || date<=0);
			sprintf(modifyrecord[i].date,"%d",date);
		
			break;
		}
		case WHAT:
		{
			char thing[81];
			setbuf(stdin, NULL);  //�M��buffer�̪� \n �ϱo[^\n]���`�B�@ 
			printf("Enter a new thing (len<=80): ");
			scanf("%[^\n]",thing);
			
			strcpy(modifyrecord[i].thing,thing);
			
			break;
		}
		case WHERE:
		{
			char location[31];
			setbuf(stdin, NULL);  //�M��buffer�̪� \n �ϱo[^\n]���`�B�@ 
			printf("Enter a new location (len<=30): ");
			scanf("%[^\n]",location);
		
			strcpy(modifyrecord[i].location,location);
		
			break;
		}
		case WHO:
		{
			char name[21];
			setbuf(stdin, NULL);  //�M��buffer�̪� \n �ϱo[^\n]���`�B�@ 
			printf("Enter a new name (<=20): ");
			scanf("%[^\n]",name);
		
			strcpy(modifyrecord[i].name,name);
			break;
		}	
		default:	//�Y��J���~�������} 
			printf("Incorrect choice\n");
	}
	printf("\n----------modify success------------\n\n");
		
	return *modifyrecord;
};

record Delete(record deleterecord[],int n)
{
	int i,j=0,temp;
	bool flag=0;
	record temprecord[10];
	for(i=0;i<10;i++)
		InitialRecord(temprecord[i]);
	
	for(i=0;i<10;i++)
	{
		temp=atoi(deleterecord[i].date); //������靈�S���ؼи�� 
		if(temp==n)
		{
			temp=i;  //�N����ŦX�ݨD���� i ����ƪ� i �O���U�� 
			flag=true;  //��ܦ���� 
			break;
		}
	}

	// ���I���� delete������ ���F���R�������إ~�A��Lrecord�n�s��temprecord��
	// temprecord�h�����R�����\��record 
	for(i=0;i<10;i++)
	{
		if(i!=temp)
		{
			temprecord[j]=deleterecord[i];
			j++;	
		}
		InitialRecord(deleterecord[i]);
		
	}
	// �Ntemprecord �Ǧ^����Ӫ���m	
	for(i=0;i<10;i++)
	{
		deleterecord[i]=temprecord[i];
	}
	
	// �Y����� flag �b�e���Q�]�� true 
	if(flag)
		printf("\n----------delete success------------\n\n");
	else
		printf("\n--the date can not found at the record--\n\n");
		
	return *deleterecord;
};
void Search(record newrecord[])
{
	int i;
	bool flag=false;
	printf("\nEnter a number.\nWhich choice you want??\n");
	printf("1-Search when.\n");
	printf("2-Search who.\n");
	printf("3-Search where.\n");
	printf("4-Search what.\n");

	int search_choice;
	scanf("%d",&search_choice);

	switch( search_choice )
	{	
		case WHEN:
		{
			int n;
			do
			{
				printf("Enter the date number : ");
				scanf("%d",&n);
			}while(n>31 || n<=0);
			
			ViewDay(newrecord,n);
			break;
		}
		case WHAT:
		{
			char thing[81];
			setbuf(stdin, NULL);  //�M��buffer�̪� \n �ϱo[^\n]���`�B�@ 
			printf("Enter the thing (len<=80): ");
			scanf("%[^\n]",thing);
			system("pause");
			for(i=0;i<10;i++)	//�j�M�O�_���ŦX����� 
			{
				if(strcmp(newrecord[i].thing,thing)==0)
				{
					ViewDay(newrecord,atoi(newrecord[i].date));
					flag=true;	//��ܧ��L��� 
				}	
			}
			if(!flag)
				printf("\nthe record can not found by \"%s\"\n\n",thing); 
			break;
		}
		case WHERE:
		{
			char location[31];
			setbuf(stdin, NULL);  //�M��buffer�̪� \n �ϱo[^\n]���`�B�@ 
			printf("Enter the location (len<=30): ");
			scanf("%[^\n]",location);
			for(i=0;i<10;i++)	//�j�M�O�_���ŦX�����
			{
				if(strcmp(newrecord[i].location,location)==0)
				{
					ViewDay(newrecord,atoi(newrecord[i].date));	
					flag=true;	//��ܧ��L��� 
				}	
			}
			if(!flag)
				printf("\nthe record can not found by \"%s\"\n\n",location); 
			break;
		}
		case WHO:
		{
			char name[21];
			setbuf(stdin, NULL);  //�M��buffer�̪� \n �ϱo[^\n]���`�B�@ 
			printf("Enter the name (<=20): ");
			scanf("%[^\n]",name);
			for(i=0;i<10;i++)	//�j�M�O�_���ŦX�����
			{
				if(strcmp(newrecord[i].name,name)==0)
				{
					ViewDay(newrecord,atoi(newrecord[i].date));
					flag=true;	//��ܧ��L��� 
				}	
			}
			if(!flag)
				printf("\nthe record can not found by \"%s\"\n\n",name); 
			break;
		}	
		default:	//�Y��J���~�������} 
			printf("Incorrect choice\n");
	}
	
};//�x�s��������Ҧ��s�誺����or��� 
void Quit(record newrecord[],int i) 
{	//i�O��i�����N��A�YS�h�x�s��file�AD�h������� 
	char c[1];
	int j=0;
	do
	{
		printf("Do you want to save or discard the record?? (S/D) : ");
		scanf("%s",c);
		
		if(c[0]=='S')	//save ��sfile����������� 
		{
			FILE *fout;
			fout=fopen("Appointment_Book.dat","r+b");
			
			fprintf(fout,"%s   %-21s%-31s%-80s\r","date","name","locatoin","thing"); //����D 
			fseek(fout,sizeof(record)+4,SEEK_SET); //�M���m 		
			
			fclose(fout);
			for(;j<10;j++)		//��X���e�s�誺record 
			{
				fout=fopen("Appointment_Book.dat","r+b");
			
				fseek(fout,sizeof(record)*(j+1)+4,SEEK_SET); //�M���m 				
/*/���ե�
				printf("-> Date: +%s+\t-> Name: +%s+\n",newrecord[j].date,newrecord[j].name);
				printf("-> Location: +%s+\n",newrecord[j].location);
				printf("-> Thing: +%s+\n",newrecord[j].thing);
				printf("-----------------------\n");
*/
				fwrite( &newrecord[j],sizeof(record),1,fout);

//���ե�		printf("\n+%d+\n",ftell(fout));
				
				fclose(fout);
			}
			printf("\n-----------the record saved!!---------\n\n");
		}
		else if(c[0]=='D')
		{
			printf("\n-----------the record discard!!---------\n\n");
			break;
		}
	}while( c[0] != 'S' && c[0] != 'D' );	
};

//	initial the file 
void InitialFile(record Empty)
{
	int i;
	do		
	{
		printf("Do you want initial the record file? (Y/N) : ");
		char c;
		scanf("%c",&c);
		setbuf(stdin, NULL);  //�M��buffer�̪� \n �ϱo[^\n]���`�B�@ 
		if(c=='Y' || c=='y')
		{
			FILE *fout;
			fout=fopen("Appointment_Book.dat","wb");
			fprintf(fout,"%s   %-21s%-31s%-80s","date","name","locatoin","thing"); //����D 
			fwrite( "\n",sizeof(char),1,fout);
			
			fclose(fout);
			
//���ե�	printf("%d+",ftell(fout));
			
			for(i=1;i<=10;i++)	//�}�l��l�� 
			{	
				fout=fopen("Appointment_Book.dat","r+b");
				fseek(fout,sizeof(record),SEEK_SET);
				if(i==1)
					fseek(fout,2,SEEK_CUR); //�M���m
				else
					fseek(fout,2+sizeof(record)*(i-1),SEEK_CUR); //�M���m
						
				fwrite( " ",sizeof(char),2,fout);				
				fwrite( &Empty,sizeof(record)-3,1,fout);
				fwrite( "\n",sizeof(char),1,fout);		
				
				fclose(fout);
			}
			printf("initial success!!\n\n");
			break;
		}
		else if(c=='N' || c=='n')
		{
			break;
		}
	}while(1);
};
//�P�_�O�_��Null record
bool NullCompare(record A,record Empty) 
{
	/*�]��strcmp�L�k�Ҽ{���פ��P�����D�A�]�����g�@�Ӥ��string��
	�Helement�@�Ӥ@�Ӥ��*/ 
	//return true �N�� �Onull �]�N�O�S����ƪ�
	//return false �N�� �Ӧ�m����� 
	int i;
	
	for(i=0;i<strlen(Empty.date);i++)	//�ˬddate 
		if(A.date[i]!=Empty.date[i]) 
			return false;
			
	for(i=0;i<strlen(Empty.location);i++)	//�ˬdlocation 
	{
		if( A.location[i] != Empty.location[i] )
			return false;
	}
	
	for(i=0;i<strlen(Empty.name);i++)	//�ˬdname 
	{
		if( A.name[i] != Empty.name[i] )
			return false;
	}
	
	for(i=0;i<strlen(Empty.thing);i++)	//�ˬdthing 
	{
		if( A.thing[i] != Empty.thing[i] )
			return false;
	}
	
	return true;
}
int main()
{
	FILE *fout;
	fout=fopen("Appointment_Book.dat","r+b"); 
	static struct Record Empty;
	record newrecord[10];	//�s��file�̪��Q����ƪ� 
	int i=0;
	
	//�P�_�ɮ׬O�_�s�b 
	if( fout==NULL || fout==NULL )   
	{
		printf("Fail to open Appointment_Book.dat!!\n");
		printf("\n->Appointment_Book.dat established\n\n");
		printf("->please execute again...");
		FILE *f=fopen("Appointment_Book.dat","w");	//fail�O�]���S�����ɮ� �A ���s�и��ɦW���ɮ� 
		fclose(f);		//�A���}���F 
		return;
	}
	
	// �Nnewrecord�M�� 
	strcpy( Empty.date , "0" );
	strcpy( Empty.location , "Null" );
	strcpy( Empty.name , "Null" );
	strcpy( Empty.thing , "Null" );
	for(i=0;i<10;i++)
		newrecord[i]=Empty;		
	
	//	�O�_��l��Appointment_Book.dat���榡 
	InitialFile(Empty);


	//Ū��file�̪�record��� 
	fseek(fout,sizeof(record)+4,SEEK_SET); //�M��Ĥ@����ƪ���m 
	for(i=0;i<10;i++)
	{
//���ե�		printf("%d+",ftell(fout));
		fread(newrecord[i].date,4,1,fout); 
		fseek(fout,1,SEEK_CUR); 
		
		fread(newrecord[i].name,20,1,fout); //�qfileŪ���@���ƨ�newrecord[i].name�� 
		fseek(fout,1,SEEK_CUR); 

		fread(newrecord[i].location,30,1,fout); //�qfileŪ���@���ƨ�newrecord[i].location�� 
		fseek(fout,1,SEEK_CUR);  

		fread(newrecord[i].thing,80,1,fout); //�qfileŪ���@���ƨ�newrecord[i].thing�� 
		fseek(fout,1,SEEK_CUR);					
	}
	
/*/	���դW���O�_���\Ū��
	for(i=0;i<10;i++)
	{
		printf("-> Date: +%-s+\t-> Name: +%-s+\n",newrecord[i].date,newrecord[i].name);
		printf("-> Location: +%-s+\n",newrecord[i].location);
		printf("-> Thing: +%-s+\n",newrecord[i].thing);
		printf("-----------------------\n");	
		
	}
*/
	// record�̦h10���Y�n�s�W�n�q��i���}�l �A�]���M�䨺�� i 
	for(i=0;i<10;i++)
	{
		if( NullCompare(newrecord[i],Empty) )
			break;	
/*���ե� 
		printf("%s+\n->",newrecord[i].location);
		printf("%d=\n\n",strcmp(newrecord[i].location, Empty.location));			
*/ 		
	}
//���ե�*/	printf("%d+",i);
	
	

	//��ܨϥέ���service 
	int choice,n;   
	
 	while( ( choice = enterchoice() ) != QUIT  ) 
	{
		switch( choice )
		{	//�s�W��zdate���Ƨ� �Ѥp��j 
			case ENTER_RECORD:	//�s�Wrecord 
			{
				if( i < 10 )
					EnterRecord( newrecord , i );
				i++;
				break;
			}
			case VIEW_DAY:	//�ݬY�Ѫ�record 
			{
				do
				{
					printf( "Enter the date number : " );
					scanf( "%d" , &n );
				}while( n > 31 || n <= 0 );
				ViewDay( newrecord , n );
				break;
			}
			case VIEW_WEEK:	//�ݬY�Ѷ}�l���C�Ѫ�record 
			{
				do
				{
					printf( "Enter the date number : " );
					scanf( "%d" , &n );
				}while( n > 31 || n <= 0 );
				
				ViewWeek( newrecord , n ); //��X���U�ӤC�� 
				break;
			}
			case MODIFY:	//����� 
			{
				for(n=0;n<i;n++)
				{
					printf("-> Date: %-s\t-> Name: %-s\n",newrecord[n].date,newrecord[n].name);
					printf("-> Location: %-s\n",newrecord[n].location);
					printf("-> Thing: %-s\n",newrecord[n].thing);
					printf("-----------------------\n");
				}
				do
				{
					printf( "Enter the date number which you want modify : " );
					scanf( "%d" , &n );
				}while( n > 31 || n <= 0 );
				Modify( newrecord , n); 
				break;
			}
			case DELETE:	//�R���Y�� 
			{
			 	for(n=0;n<i;n++)
				{
					printf("-> Date: %-s\t-> Name: %-s\n",newrecord[n].date,newrecord[n].name);
					printf("-> Location: %-s\n",newrecord[n].location);
					printf("-> Thing: %-s\n",newrecord[n].thing);
					printf("-----------------------\n");
				}

				do
				{
					printf( "Enter the date number which you want delete : " );
					scanf( "%d" , &n );
				}while( n > 31 || n <= 0 );
				Delete( newrecord , n );
				i--;
				break;
			}
			case SEARCH:
				Search( newrecord );
				break;
			default:
				printf( "Incorrect service\n\n" );
		}
		setbuf( stdin, NULL );  //�M��buffer�̪����e�ϱo enterchoice ���`�B�@ 
	
	}
	//choice to save or discard
	Quit( newrecord , i );
	fclose( fout );
	
	
	return 0;
}
/*  �o�OviewdayŪ���ɮ׿�X���覡 
	int i,temp;
	char date[2]="",record[140]="";
	FILE *fout;
	fout=fopen("Appointment_Book.dat","r+b");

	fseek(fout,138,SEEK_SET); //�M��Ĥ@����ƪ���m 
		
	for(i=0;i<10;i++)
	{
		fread(date,2,1,fout); //�qfileŪ���@�ժ��׬�2����ƨ�date�� 
		
		sscanf(date, "%d", &temp); //char array �ഫ�� int 
		temp=atoi(data);�]�i�H 
		
		if(temp==n)
		{
			fseek(fout,138+i*(sizeof(record)),SEEK_SET); //�M���i����ƪ��}�Y 
				
			fread(record,138,1,fout); //�qfileŪ���@���ƨ�record�� 
			printf("the record at %d\n-> %s\n\n",n,record);
			return 0;
		}
		fseek(fout,(sizeof(record)-2),SEEK_CUR); //�M��U�@����ƪ���m
	}
	printf("\nthe record can not found at this date !!\n\n");
			
	fclose(fout);*/

/*	�o�OviewweekŪ���ɮ׿�X���覡 
	int i,temp;
	char date[2]="",temprecord[140];
	record record[7];
	bool hasrecord=false;
	FILE *fout;
	fout=fopen("Appointment_Book.dat","r+b");

	fseek(fout,138,SEEK_SET); //�M��Ĥ@����ƪ���m 
	
	for(i=0;i<7;i++)
	{
		viewrecord[i]=Empty;
		viewrecord[i].date=n+i;
	
	}	
	for(i=0;i<10;i++)
	{
		fread(date,2,1,fout); //�qfileŪ���@�ժ��׬�2����ƨ�date�� 
		sscanf(date, "%d", &temp); //char array �ഫ�� int 
		temp=atoi(data);�]�i�H 
		
		if(temp>=n && temp<n+7)
		{
			fseek(fout,144+i*(sizeof(record)+4),SEEK_SET); //�M���i����ƪ��}�Y 
			
		//	fread(temprecord,138,1,fout); //�qfileŪ���@���ƨ�temprecord�� 
		//	sscanf(date, "%d", &temp); //char array �ഫ�� int 

			fread(viewrecord[i].name,19,1,fout); //�qfileŪ���@���ƨ�viewrecord[i].name�� 
			fseek(fout,1,SEEK_CUR); 

			fread(viewrecord[i].location,29,1,fout); //�qfileŪ���@���ƨ�viewrecord[i].location�� 
			fseek(fout,1,SEEK_CUR); 

			fread(viewrecord[i].thing,79,1,fout); //�qfileŪ���@���ƨ�viewrecord[i].thing�� 
			fseek(fout,1,SEEK_CUR);
			
			fseek(fout,4,SEEK_CUR); //�M��U�@����ƪ���m
			hasrecord=true;
			
			
		}
		else
		{
			fseek(fout,(sizeof(record)+2),SEEK_CUR); //�M��U�@����ƪ���m
		}
	}
	if(hasrecord)
	{
		printf("the record at date %d ~ %d\n",n,n+7);	
		for(i=0;i<7;i++)
		{
			printf("-> Date: %2d \t-> Name: %-20s\n",viewrecord[i].date,viewrecord[i].name);
			printf("-> Location: %-30s\n",viewrecord[i].location);
			printf("-> Thing: %-80s\n",viewrecord[i].thing);
			printf("-----------------------\n");
		}
			
			
	}
	else
		printf("the record can not found at date %d ~ %d\n",n,n+7);	
	
	fclose(fout);*/

