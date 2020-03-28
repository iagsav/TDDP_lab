#include<iostream>
using std::cout;
using std::cin;
using std::endl;
char logo[]=
"***************************************************************\n"
"                                  ______    ______            \n"
" \\        /       /\\     |        |        |     |   \\     / \n"
"  \\      /       /  \\    |        |        |_____|    \\   /  \n"
"   \\    /       /    \\   |        |_____   |  \\        \\ /   \n"
"    \\  /       /------\\  |        |        |   \\        /    \n"
"     \\/       /        \\ |_____   |_____   |    \\      /     \n"
"                                                              \n"
"**************************************************************\n";
int myLen(const char* str) {
	int res = 0;
	for (res; str[res] != '\0'; res++);
	return res;
}

int myCmp(const char* str1, const char* str2) {
	int res=0;
	int len=myLen(str1);
	if(myLen(str2)<len){len=myLen(str2);}
	for(int i=0;i<len;i++){
		if(str1[i]>str2[i]){res=1;break;}
		if(str1[i]<str2[i]){res=-1;break;}
	}
	if((res==0) && (myLen(str1)>myLen(str2))){res=1;}
	if((res==0) && (myLen(str1)<myLen(str2))){res=-1;}	
	return res;
}
class human{
	protected:
		char name[20];
		int id;
	public:
		human(void){
			id=0;
			name[0]='\0';
		}
		human(int _id,char* _name){
			id=_id;
			for(int i=0;i<myLen(_name);i++){
				name[i]=_name[i];			
			}
			name[myLen(_name)]='\0';
		}
		 ~human(){
			id=0;
			name[0]='\0';		
		}
		virtual void  employee(void){
			cout<< "this is a human"<< endl;
		}
		void print() {
			cout << id<< " " << name;
			employee();
			cout << endl;
		}
		
};
class student: public human{
	public:
		student() : human() {} 
		student(int _id,char* _name) : human(_id,_name) {} 
		~student()  {}
		void employee () override {
			cout<<"this is a student "<< endl;
		}
	
};
class programmer: public human{
	public:
	programmer() : human() {} 
	programmer(int _id,char* _name) : human(_id,_name) {} 
	~programmer() {}
	void employee () override {
		cout<<"this is a programmer "<< endl;
	}
	
};
class tester: public human{
	public:
		tester() : human() {} 
		tester(int _id,char* _name) : human(_id,_name) {} 
		~tester() {}
		void employee () override {
			cout<<"this is a tester "<< endl;
		}
	
};
class supervisor: public human{
	public:
		supervisor() : human() {} 
		supervisor(int _id,char* _name) : human(_id,_name) {} 
		~supervisor()  {}
		void employee () override {
			cout<<"this is a supervisor "<< endl;
		}
	
};

int main(int argc,char **argv){
	if (argc==1){
		cout<<"\x1B[32m"<<"Аргументы:"<<endl;
		cout<<"-h or --help для вызова подсказки"<<"\n";
		cout<<"-c  для создания таблицы работников и вывода ее на экран "<<endl;
	}
	if(myCmp(argv[1], "-h") == 0 || myCmp(argv[1], "--help") == 0 ){
		cout<<"\x1B[32m"<<"Программа хранит данные работников: идентификационный номер и имя."<<endl;	
	}
	if(myCmp(argv[1],"-c")==0){
		human arr[5];
		int id;
		char name[20];
		char position[20];
		for(int i=0;i<5;i++){
			cout<<"Введите номер работника"<<endl;
			cin>>id;
			cout<<"Введите имя работника"<<endl;
			cin>>name;
			cout<<"Введите должность работника"<<endl;
			cin>>position;
			int k=0;
			if(myCmp(position, "student") == 0){
				student st(id,name);
				arr[i]=st;
				k++;
			}
			if(myCmp(position, "programmer") == 0){
				programmer pg(id,name);
				arr[i]=pg;
				k++;
			}
			if(myCmp(position, "tester") == 0){
				tester ts(id,name);
				arr[i]=ts;
				k++;
			}
			if(myCmp(position, "supervisor") == 0){
				supervisor sp(id,name);
				arr[i]=sp;
				k++;
			}
			if(k==0){
				cout<<"Такой должности в организации нет"<<endl;
				exit(-1);
			}
		}		
		for (int i = 0; i < 5; i++) arr[i].print();
	}

	return 0;
}
