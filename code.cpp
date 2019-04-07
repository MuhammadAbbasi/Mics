#include <iostream>
#include <fstream>
#include <string>

using namespace std;

fstream myfile;																//changed form fstream to ifstream but no success
ifstream inData;													
ofstream fout;	

class Person
{
    public:
    	string firstname, lastname, tele, email;

    Person readfile( )
    {
		cout<<"\nin person readfile\n";
        inData>>firstname>>lastname>>tele>>email;
        cout<<"Taken info:"<<endl;
        cout<<firstname<<lastname<<tele<<email<<"done here";
    }
     void showpersoninfo()
    {
    	cout<<"\nin person showpersoninfo\n";
        cout<<firstname<<"  "<<lastname<<"  "<<tele<<"  "<<email<<endl;
    }

    void getpersoninfo()
    {
        cout<<"Enter first name only:"<<endl;
        cin>>firstname;
        cout<<"Enter last name only:"<<endl;
        cin>>lastname;
        cout<<" Enter telephone number:"<<endl;
        cin>>tele;
        cout<<" Enter email:"<<endl;
        cin>>email;

    }

    void writepersoninfotofile()
    {
    	cout<<"\nin person writepersoninfotofile\n";
        ofstream fout;
        fout<<firstname<<"  "<<lastname<<"  "<<tele<<"  "<<email<<endl;
    }

};



class Linklist
{
    struct nodeType
	{
		Person info;
		nodeType *link;
	};

 nodeType *head, *tail;
 int count;

 public:
    Linklist(void)
	{head=NULL; tail=NULL; count=0;
	cout<<"\nlinklist floatlist constructor\n";}

	void storeinlinklist(Person num)
	{
		cout<<"\nin linkedlist storeinlinkedlist\n";
		nodeType *newNode, *nodeptr;
		newNode = new nodeType;
		newNode->info=num;
		newNode->link=NULL;
		count++;

		if(head==NULL)
		{

			head=newNode;
		}
		else
		{
			nodeptr=head;
			while(nodeptr->link!=NULL)
			{nodeptr=nodeptr->link;}
			nodeptr->link=newNode;
			tail=newNode;
		}
	}

	void addpersontolist(Person num)
	{
	    cout<<"Info to list"<<endl;									//printed
	    nodeType *newNode;
		newNode= new nodeType;           //GET PERSON DATA IN PERSON CLASS
		cout<<"\nvalue of count in Linklist addpersontolist\n"<<count;
		//newNode->info=num;
		//newNode->link=NULL;
		count++;
		cout<<"Tail value or address:"<<tail<<endl;											//statement printed
		tail->link= newNode;																//possible problem here
		cout<<"Tail value or address:"<<tail<<endl;											//this statement not ruuning
		cout<<"\nvalue of count in Linklist addpersontolist\n"<<count;
		tail= newNode;
    }

    void displayfromlinklist()
    {
        nodeType *nodeptr;
		nodeptr=head;
		while(nodeptr!=NULL)
		{
			nodeptr->info.showpersoninfo();
			nodeptr=nodeptr->link;
		}
		cout<<endl;
    }

    void writelinklisttofile()
    {
        nodeType *nodeptr;
        nodeptr=head;
        while(nodeptr->link!=NULL)
        {
            nodeptr->info.writepersoninfotofile();
            nodeptr=nodeptr->link;
        }
    }

 };

int main()
{
    ifstream fin;													//opened
    ofstream fout;													//opened
    Person data;													//opened
    Linklist llist;													//opened
    
    
	cout<<"in main";												//displayed
    // OPEN AND READ FROM FILE, STORE IN LINKLIST
    fin.open("Assig01-person-data.txt");							//opened or may be not
    
    if(fin)															//check if file opens
    {
    	cout<<"File opened!!\n";									//file opened
	}
    
    if(fin.is_open())												//condition checked
    {  cout<<"open\n";												//displayed
        while(fin.eof())											//condition true
        {
        	cout<<"\nin while\n";									//displayed
            //data.readfile();        // output is taken info			//displayed and run problem here
            //llist.storeinlinklist(data);						//stuck
            //llist.displayfromlinklist();
            cout<<"\nWhile about to end\n";							//While not ending
        }
    }
    else
        cout<<"not open";


	
    char o;
    cout<<"  Choose number for following functions:"<<endl;
    cout<<"  1) Search person:"<<endl;
    cout<<"  2)	Add new Person:"<<endl;
    cout<<"  3)	Delete the data of a Person"<<endl;
    cout<<"  4)	Show the data of all Persons"<<endl;
    cin>>o;
    

    switch(o)
    {
    case '4':
        llist.displayfromlinklist();
        break;
    case '2':
        data.getpersoninfo();
        cout<<data.firstname;												//switch case running till here fine
        llist.addpersontolist(data);
    }

    fin.close();

    // OVERWRITE NEW DATA TO FILE
     fout.open("Assig01-person-data.txt");
    if(fout.is_open())
    {  cout<<"open";
        llist.writelinklisttofile();
    }
    else
        cout<<"not open:";
                        // WRITE TO FILE FROM LINK LIST TILL NULL

    return 0;
}
