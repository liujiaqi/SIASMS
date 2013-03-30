/*************************************************************************
			Students Information and Score Mnanage System
										by:LiuJiaqi
2013.01.25	Design the framework
			Finish print()	add()	del()	inquiry()	main()
2013.01.26	Finish load()	sort()	save()
2013.01.27	Preliminarily amend error.
			Debug add()	//p1->next=p2;
			Add getchar(); in main() sort() del() inquiry()
				to clean the "surplus chars" in the buffer
2013.02.03	Debug.'m' is wrong data type in inquiry() del()
			Add change()
**************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LEN sizeof(struct student)

struct student{
	int num;
	char name[20];
	int score;
	struct student *next;
}*head=NULL;

void load(void){//load students' information from a file.
	int n=0;
	FILE *fp;
	struct student *p1,*p2;
	if((fp=fopen("student.bin","rb"))==NULL){
		printf("Open the file error.\n");	
	}
	else{
		while(!feof(fp)){
			p1=(struct student *)malloc(LEN);
			if(fread(p1,LEN,1,fp)){
				n++;
				if(n==1){
					p1->next=NULL;
					head=p2=p1;
				}
				else{
					p2->next=p1;
					p2=p1;
					p2->next=NULL;
				}
			}
		}
		fclose(fp);
		printf("Found %d students' informatiom.\n",n);
	}
}

void print(void){//print all students' information and scores.
	struct student *p;
	if(head==NULL){
		printf("There is no student.\n");
	}
	else{
		p=head;
		printf("Number   Name   Score\n");
		while(p!=NULL){
			printf("%d\t%s\t%d\n",p->num,p->name,p->score);
			p=p->next;
		}
	}
}

void add(void){//add a student.
	struct student *p1=NULL,*p2=NULL;
	printf("Please add a student:number,name,score\n");
	p2 = (struct student *)malloc(LEN);
	scanf("%d%s%d",&p2->num,p2->name,&p2->score);
	p2->next=NULL;
	if(head==NULL){//Add the first node.
		head=p2;
	}
	else{
		p1=head;
		while(p1->next!=NULL){//Put the pointer to the end
			p1=p1->next;
		}
		p1->next=p2;
	}
}

void del(void){//delete a student.
	int n;
	char m,na[20];
	struct student *p1=NULL,*p2=NULL;
	if(head==NULL){
		printf("There is no student's information!\n");	
	}
	else{
		printf("Please choose the method of deleting\nu:by number\ta:by name\n");
		getchar();//to clean the buffer
		m=getchar();
		p1=head;
		if(m=='u'){//Delete a student by number.
			printf("Please input the number.\n");
			scanf("%d",&n);
			while(p1!=NULL && p1->num!=n){//Look for the student.
				p2=p1;
				p1=p1->next;	
			}
			if(p1==NULL){
				printf("Didn't find the number!\n");	
			}
			else{//Delete the student from the linked list.
				if(p1==head){
					head=p1->next;
				}
				else{
					p2->next=p1->next;
				}
				printf("Delete successfully.\n");//2013.02.03
			}
		}
		else if(m=='a'){//Delete a student by name.
			printf("Please input the name.\n");
			scanf("%s",na);
			while(p1!=NULL && strcmp(p1->name,na)){//Look for the student.
				p2=p1;
				p1=p1->next;	
			}
			if(p1==NULL){
				printf("Don't find the name!\n");	
			}
			else{//Delete the student from the linked list.
				if(p1==head){
					head=p1->next;
				}
				else{
					p2->next=p1->next;
				}
				printf("Delete successfully.\n");//2013.02.03
			}
		}
		else{
			printf("Please choose a correct method.\n");
		}
	}
}

void inquiry(void){//inquiry information of a student.
	int n;
	char m,na[20];
	struct student *p;
	if(head==NULL){
		printf("There is no student's information!\n");
	}
	else{
		printf("Please choose the method of inquiry\nu:by number\ta:by name\n");
		getchar();//to clean the buffer
		m=getchar();
		p=head;
		if(m=='u'){//Inquiry a student by number.
			printf("Please input the number.\n");
			scanf("%d",&n);
			while(p!=NULL && p->num!=n){//Look for the student.
				p=p->next;	
			}
			if(p==NULL){
				printf("Don't find the number!\n");	
			}
			else{//Print the student's information.
				printf("Number   Name   Score\n");
				printf("%d\t%s\t%d\n",p->num,p->name,p->score);
			}
		}
		else if(m=='a'){//Inquiry a student by name.
			printf("Please input the name.\n");
			scanf("%s",na);
			while(p!=NULL && strcmp(p->name,na)){//Look for the student
				p=p->next;	
			}
			if(p==NULL){
				printf("Didn't find the name!\n");	
			}
			else{//Print the student's information.
				printf("Number   Name   Score\n");
				printf("%d\t%s\t%d\n",p->num,p->name,p->score);
			}
		}
		else{
			printf("Please choose a correct method.\n");
		}
	}
}

void sort(void){/*sort the students*/
	char m;
	struct student *p1,*p2,*p3=NULL;
	p1=p2=head;
	if(head==NULL){
		printf("There is no student.\n");
	}
	else{
		printf("Please choose the method of sorting\nn:by number\ts:by score\n");
		getchar();
		m=getchar();
		if(m!='n' && m!='s'){
			printf("Please choose a correct method.\n");
		}
		else{
			while(head!=p3){
				while(p1->next!=p3){
					if(m=='n'){//sort students by number.
						if(p1->num > p1->next->num){
							if(p1==head){
								head=p2=p1->next;
								p1->next=head->next;
								head->next=p1;
							}
							else{
								p2->next=p1->next;
								p2=p1->next;
								p1->next=p2->next;
								p2->next=p1;
							}
						}
						else{
							p2=p1;
							p1=p1->next;
						}
					}
					else{//sort students by score
						if(p1->score < p1->next->score){
							if(p1==head){
								head=p2=p1->next;
								p1->next=head->next;
								head->next=p1;
							}
							else{
								p2->next=p1->next;
								p2=p1->next;
								p1->next=p2->next;
								p2->next=p1;
							}
						}
						else{
							p2=p1;
							p1=p1->next;
						}
					}
				}
				p3=p1;
				p1=head;
			}
		}
		printf("Sorting finished.\n");
	}
}

void save(void){//save information to a file
	int n=0;
	FILE *fp;
	struct student *p;
	p=head;
	if((fp=fopen("student.bin","wb"))==NULL){
		printf("Build the file error.\n");	
	}
	else{
		while(p){
			if(fwrite(p,LEN,1,fp)==1){
				p=p->next;
				n++;
			}
			else{
				printf("save error.\n");
			}
		}
		printf("%d students' information saved.\n",n);
		fclose(fp);
	}
}

void change(void){
	int n;
	struct student *p;
	if(head==NULL){
		printf("There is no student's information!\n");
	}
	else{
		p=head;
		printf("Please input the number.\n");
		scanf("%d",&n);
		while(p!=NULL && p->num!=n){//Look for the student.
			p=p->next;	
		}
		if(p==NULL){
			printf("Don't find the number!\n");	
		}
		else{
			printf("Please input the student's name and score.\n");
			scanf("%s%d",p->name,&p->score);
			save();
		}
	}
}

main(){
	char cmd;
	printf("Welcome to use this system!\n");
	load();
	while(1){
		printf("Please enter the command you need.\n");
		printf("p:print  a:add  d:delete  i:inquiry  s:sort  c:change\n");
		cmd=getchar();
		switch(cmd)
		{
			case 'p':
				print();
				break;
			case 'a':
				add();
				save();
				break;
			case 'd':
				del();
				save();
				break;
			case 'i':
				inquiry();
				break;
			case 's':
				sort();
				save();
				break;
			case 'c':
				change();
				break;
			default:
				printf("Please print a correct command.\n");
				break;
		}
		getchar();//to clean the buffer
	}
}