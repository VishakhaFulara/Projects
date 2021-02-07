///////////////////////**HEADER FILES USED***////////////////////////////////
#include<iostream>
#include<string>
#include<fstream>
#include<conio.h>
#include<cstdlib>
#include<cstdio>
#include<iomanip>
using namespace std;

int gp[10]={0};                                  						//global variable declared which store grade point of each subject
class student{
	private:
		string name,father_name,Enrollement_no;       
		//data member for mid exam  theory subject         
		int prof_comm_mid,chem_mid,math_mid,cs_mid,EV_mid,prof_comm_ses,chem_ses,math_ses,cs_ses,EV_ses;//data member for mid exam 
		int EV_fin,prof_comm_fin,chem_fin,math_fin,cs_fin,prof_tot,chem_tot,math_tot,cs_tot,EV_tot;  //data member for final exam & total marks of particular subject
		static int max,max_f,tot_credits;
		//data members for practical subject
		int p_mid,ch_mid,m_mid,c_mid,E_mid,p_ses,ch_ses,m_ses,c_ses,E_ses;     
		int E_fin,p_fin,ch_fin,m_fin,c_fin,p_tot,ch_tot,m_tot,c_tot,E_tot;
		string grade[10]={"O","A+","A","B+","B","C+","C","D+","D","E"};       
		int g_point[10]={10,9,8,6,5,4,3,2,1},Roll_no,credits[10]={1,2,3,4,3,2,3,1,2,4};//credits for particular subject
	public:
	
	void input_student_data(){
		cout<<"Enter name of a student:";
		cin.ignore();
		getline(cin,name);
		cout<<"Enter Father's name of a student:";
		getline(cin,father_name);
		cout<<"Enter Enrollement number:";
		getline(cin,Enrollement_no);
		cout<<"Enter Roll number:";
		cin>>Roll_no;

	}	
	void inputMid_marks(){
		cout<<"\n\n\tENTER MID SEM MARKS FOR THEORY(out of 25)\n";
		cout<<"Enter Professional Communication marks:";
		cin>>prof_comm_mid;
		cout<<"Enter Maths marks:";
		cin>>math_mid;
		cout<<"Enter chemistry marks:";
		cin>>chem_mid;
		cout<<"Enter Computer Science marks:";
		cin>>cs_mid;
		cout<<"Enter Environmental Science marks:";
		cin>>EV_mid;
		
		cout<<"\n\n\tENTER MID SEM MARKS FOR PRACTICAL(out of 25)\n";
		cout<<"Enter Professional Communication marks:";
		cin>>p_mid;
		cout<<"Enter Maths marks:";
		cin>>m_mid;
		cout<<"Enter chemistry marks:";
		cin>>ch_mid;
		cout<<"Enter Computer Science marks:";
		cin>>c_mid;
		cout<<"Enter Environmental Science marks:";
		cin>>E_mid;
	}
	void inputSessional_marks(){
		cout<<"\n\n\tENTER SESSIONAL MARKS FOR THEORY(out of 25)\n";
		cout<<"Enter Professional Communication marks:";
		cin>>prof_comm_ses;
		cout<<"Enter Maths marks:";
		cin>>math_ses;
		cout<<"Enter chemistry marks:";
		cin>>chem_ses;
		cout<<"Enter Computer Science marks:";
		cin>>cs_ses;
		cout<<"Enter Environmental Science marks:";
		cin>>EV_ses;
		
		cout<<"\n\n\tENTER SESSIONAL MARKS FOR PRACTICAL(out of 25)\n";
		cout<<"Enter Professional Communication marks:";
		cin>>p_ses;
		cout<<"Enter Maths marks:";
		cin>>m_ses;
		cout<<"Enter chemistry marks:";
		cin>>ch_ses;
		cout<<"Enter Computer Science marks:";
		cin>>c_ses;
		cout<<"Enter Environmental Science marks:";
		cin>>E_ses;
	}
	void inputFinal_marks(){
		cout<<"\n\n\tENTER FINAL SEM MARKS FOR THEORY(out of 50)\n";
		cout<<"Enter Professional Communication marks:";
		cin>>prof_comm_fin;
		cout<<"Enter Maths marks:";
		cin>>math_fin;
		cout<<"Enter chemistry marks:";
		cin>>chem_fin;
		cout<<"Enter Computer Science marks:";
		cin>>cs_fin;
		cout<<"Enter Environmental Science marks:";
		cin>>EV_fin;
		
		cout<<"\n\n\tENTER FINAL SEM MARKS FOR PRACTICAL(out of 50)\n";
		cout<<"Enter Professional Communication marks:";
		cin>>p_fin;
		cout<<"Enter Maths marks:";
		cin>>m_fin;
		cout<<"Enter chemistry marks:";
		cin>>ch_fin;
		cout<<"Enter Computer Science marks:";
		cin>>c_fin;
		cout<<"Enter Environmental Science marks:";
		cin>>E_fin;
	}
	void Total_marks(){
		//TOTAL FOR THEORY SUBJECT
		prof_tot=prof_comm_mid+prof_comm_ses+prof_comm_fin;
		math_tot=math_mid+math_ses+math_fin;
		chem_tot=chem_mid+chem_ses+chem_fin;
		cs_tot=cs_mid+cs_ses+cs_fin;
		EV_tot=EV_mid+EV_ses+EV_fin;
		
		//TOTAL FOR PRACTICAL SUBJECT
		p_tot=p_mid+p_ses+p_fin;
		m_tot=m_mid+m_ses+m_fin;
		ch_tot=ch_mid+ch_ses+ch_fin;
		c_tot=c_mid+c_ses+c_fin;
		E_tot=E_mid+E_ses+E_fin;

	}
	string Grade(int marks){
		if(86<=marks && marks<=100)
			return grade[0];
		else if(76<=marks && marks<=85)
			return grade[1];
		else if(66<=marks && marks<=75)
			return grade[2];
		else if(56<=marks && marks<=65)
			return grade[3];
		else if(46<=marks && marks<=55)
			return grade[4];
		else if(36<=marks && marks<=45)
			return grade[5];
		else if(26<=marks && marks<=35)
			return grade[6];
		else if(16<=marks && marks<=25)
			return grade[7];
		else if(6<=marks && marks<=15)
			return grade[8];
		else
			return grade[9];	
	}
	int grade_point(string g,int j){
		for(int i=0;i<10;i++){
			if(g==grade[i])
			{
				gp[j]=g_point[i];
				return g_point[i];
			}
		}
	}
	int tot_earned(){
		int marks[10]={prof_tot,chem_tot,math_tot,cs_tot,EV_tot,p_tot,ch_tot,m_tot,c_tot,E_tot},total=0;
		for(int i=0;i<10;i++){
			if(marks[i]<=40){
				total=total+0;
			}
			else{
				total=total+credits[i];
			}
		}
		return total;
	}
	string res(int tot_r,int tot_e){
		if(tot_r==tot_e)
			return "Pass";
		else
			return "Fail";
	}
	//for caclculating sgpa	
	float sgpa(){
		float sum=0;                           
		for(int i=0;i<10;i++){
			sum=sum+(gp[i]*credits[i]);
		}
		float res=sum/tot_credits;
		return res;
	}

	void display_data(){
		cout<<"\n\n\t\t\t\t\t\tGRAPHIC ERA HILL UNIVERSITY\n";
		cout<<"\t\t\t\tSociety Area, Clement Town Dehradun-248002, Uttarakhand (INDIA)\n\n";
		cout<<"\t\t\t\t\t\tSTATEMENT OF MARKS(PROVISIONAL)\n";
		cout<<"\t\t\t\t\tBACHELOR OF TECHNOLOGY -II SEMESTER EXAMINATION\n\n\n";
		cout<<"Name of a student:"<<name<<"\t\t\t\t\t\t\t";
		cout<<"Enrollement number:"<<Enrollement_no<<"\n";
		cout<<"Father's name:"<<father_name<<"\t\t\t\t\t\t\t";
		cout<<"Roll number:"<<Roll_no<<"\n\n";
		cout<<"________________________________________________________________________________________________________________________________\n\n";
		cout<<"     		     Subject name             |Credits|Mid sem Exam|Sessional marks|End sem Exam|Total Marks|Grade|Grade points|\n";
		cout<<"                                              |       |Max.  | Obt.|Max.   | Obt.  |Max.  |Obt. |obtained   |     |            |\n";
		cout<<"________________________________________________________________________________________________________________________________\n";
		cout<<"THEORY 	          |Professional Communication |"<<credits[0]<<"      |"<<max<<"    |"<<prof_comm_mid<<"   |"<<max<<"     |"<<prof_comm_ses<<"     |"<<max_f<<"    |"<<prof_comm_fin<<"   |"<<prof_tot<<"   	    |"<<Grade(prof_tot)<<"    |"<<grade_point(Grade(prof_tot),0)<<"\n";
		cout<<"		  |Maths                      |"<<credits[1]<<"      |"<<max<<"    |"<<math_mid<<"   |"<<max<<"     |"<<math_ses<<"     |"<<max_f<<"    |"<<math_fin<<"   |"<<math_tot<<"  	    |"<<Grade(math_tot)<<"    |"<<grade_point(Grade(math_tot),1)<<"\n";
		cout<<"		  |Chemistry                  |"<<credits[2]<<"      |"<<max<<"    |"<<chem_mid<<"   |"<<max<<"     |"<<chem_ses<<"     |"<<max_f<<"    |"<<chem_fin<<"   |"<<chem_tot<<"	    |"<<Grade(chem_tot)<<"    |"<<grade_point(Grade(chem_tot),2)<<"\n";
		cout<<"		  |Computer Science           |"<<credits[3]<<"      |"<<max<<"    |"<<cs_mid<<"   |"<<max<<"     |"<<cs_ses<<"     |"<<max_f<<"    |"<<cs_fin<<"   |"<<cs_tot<<"	    |"<<Grade(cs_tot)<<"     |"<<grade_point(Grade(cs_tot),3)<<"\n";
		cout<<"		  |Environmental Science      |"<<credits[4]<<"      |"<<max<<"    |"<<EV_mid<<"   |"<<max<<"     |"<<EV_ses<<"     |"<<max_f<<"    |"<<EV_fin<<"   |"<<EV_tot<<"         |"<<Grade(EV_tot)<<"	 |"<<grade_point(Grade(EV_tot),4)<<"\n";
		cout<<"--------------------------------------------------------------------------------------------------------------------------------\n";
		cout<<"PRACTICAL 	  |Professional Communication |"<<credits[5]<<"      |"<<max<<"    |"<<p_mid<<"   |"<<max<<"     |"<<p_ses<<"     |"<<max_f<<"    |"<<p_fin<<"   |"<<p_tot<<"   	    |"<<Grade(p_tot)<<"    |"<<grade_point(Grade(p_tot),5)<<"\n";
		cout<<"		  |Maths                      |"<<credits[6]<<"      |"<<max<<"    |"<<m_mid<<"   |"<<max<<"     |"<<m_ses<<"     |"<<max_f<<"    |"<<m_fin<<"   |"<<m_tot<<"  	    |"<<Grade(m_tot)<<"    |"<<grade_point(Grade(m_tot),6)<<"\n";
		cout<<"		  |Chemistry                  |"<<credits[7]<<"      |"<<max<<"    |"<<ch_mid<<"   |"<<max<<"     |"<<ch_ses<<"     |"<<max_f<<"    |"<<ch_fin<<"   |"<<ch_tot<<"	    |"<<Grade(ch_tot)<<"    |"<<grade_point(Grade(ch_tot),7)<<"\n";
		cout<<"		  |Computer Science           |"<<credits[8]<<"      |"<<max<<"    |"<<c_mid<<"   |"<<max<<"     |"<<c_ses<<"     |"<<max_f<<"    |"<<c_fin<<"   |"<<c_tot<<"	    |"<<Grade(c_tot)<<"     |"<<grade_point(Grade(c_tot),8)<<"\n";
		cout<<"		  |Environmental Science      |"<<credits[9]<<"      |"<<max<<"    |"<<E_mid<<"   |"<<max<<"     |"<<E_ses<<"     |"<<max_f<<"    |"<<E_fin<<"   |"<<E_tot<<"         |"<<Grade(E_tot)<<"	|"<<grade_point(Grade(E_tot),9)<<"\n\n";

		cout<<"\nTotal No. of Credits Registered:"<<tot_credits<<"\n\n";
		cout<<"Total No. of Credits Earned:"<<tot_earned()<<"\n\n";
		cout<<"Result:"<<res(tot_credits,tot_earned())<<"\t\t\t\t\t\t\t\t\t\t\t\t\t\t"<<"SGPA:"<<fixed<<setprecision(1)<<sgpa()<<"\n\n\n\n";
		
	}
	
	void write_record();
	void view_record();
	void search_record(int n);
	void delete_record(int n);
	void update_record(int n);
	void set_value();
};
int student::max=25;
int student::max_f=50;                                       //maximum value for final exam(exam is of 50)
int student::tot_credits=25;                                //total credits registered

void student::set_value(){
		input_student_data();
		inputMid_marks();
		inputSessional_marks();
		inputFinal_marks();
		Total_marks();
}

//////////////////////////////***WRITING DATA INTO THE FILE***////////////////////////////////////////
void student::write_record(){
	set_value();
	ofstream file;
	file.open("student.dat",ios::app|ios::binary);
	file.write((char *)this,sizeof(*this));
	file.close();
}

/////////////////////////////***READING DATA FROM THE FILE***///////////////////////////////
void student::view_record()
{
	ifstream inp;
	inp.open("student.dat",ios::in|ios::binary);
	if(inp.fail())
	{
		cout<<"File is not created\n";
	}
	else{
		inp.read((char *)this,sizeof(*this));
		while(!inp.eof()){
			display_data();
			inp.read((char *)this,sizeof(*this));          
		}
		inp.close();
	}
	
}
////////////////////////////////////**SEARCH THE RECORD FROM THE FILE***///////////////////////
void student::search_record(int n){
	int c=0;
	ifstream inp;
	inp.open("student.dat",ios::in|ios::binary);
	if(!inp.is_open()){
		cout<<"File could not be open !! \n";
	}
	else{
		while(inp.read((char *)this,sizeof(*this))){
			if(n==Roll_no){                     
				display_data();
				c++;
			}
		}
		if(c==0){
			cout<<"Record not found!\n";
		}
		inp.close();
	}
}

/////////////////////////////////***DELETE A RECORD FROM A FILE***/////////////////////
void student::delete_record(int n){
	ofstream fout;
	ifstream fin;
	fin.open("student.dat",ios::in|ios::binary);
	if(!fin.is_open()){
		cout<<"File could not be open !! \n";
	}
	else{
		fout.open("temp.dat",ios::out|ios::binary);
		while(fin.read((char *)this,sizeof(*this))){
			if(n!=Roll_no){                     
				fout.write((char *)this,sizeof(*this));
			}
		}
		fin.close();
		fout.close();
		remove("student.dat");
		rename("temp.dat","student.dat");
		cout<<"\nRecord is successfully deleted!!!";
	}
}

////////////////////////////**UPDATE A RECORD IN A FILE**////////////////////////////
void student::update_record(int n){
	int c=0;
	fstream file;                                                 
	file.open("student.dat",ios::in|ios::out|ios::ate|ios::binary);                 //opening for both reading & writing
	file.seekg(0);
	while(file.read((char *)this,sizeof(*this))){
		if(n==Roll_no){
			set_value();
			c++;
			file.seekg(file.tellg()-sizeof(*this));
			file.write((char *)this,sizeof(*this));
			cout<<"\nRecord is successfully updated!!!";
		}
	}
	file.close();
	if(c==0){
		cout<<"\nRecord not found!\n";
	}
}
void intro(){
	cout<<"\n\n\n\t\t************************************************\n";
	cout<<"\t\t*		Name:Vishakha Fulara	   	*\n";
	cout<<"\t\t*		Sem-III (B.tech(CSE))	   	*\n";
	cout<<"\t\t************************************************\n";
}

int main(){
	intro();
	getch();
	student st;                                               //OBJECT OF STUDENT CLASSS
	int ch;
	int Roll_no;
	do{
		system("cls");
		cout<<"\n\n\n\tMENU";
		cout<<"\n\n\t1.CREATE STUDENT RECORD";
		cout<<"\n\n\t2.DISPLAY ALL STUDENT RECORD";
		cout<<"\n\n\t3.SEARCH STUDENT RECORD ";
		cout<<"\n\n\t4.DELETE STUDENT RECORD";
		cout<<"\n\n\t5.MODIFY STUDENT RECORD";
		cout<<"\n\n\t6.EXIT";
		cout<<"\n\n\tPlease Enter Your Choice (1-6):";
		cin>>ch;
		switch(ch)
		{
			case 1:st.write_record();
					break;
			case 2:st.view_record();                         //display all student record
					getch();
					break;
			case 3:{
					cout<<"Please enter the Roll number to search the record:";
					cin>>Roll_no;
					st.search_record(Roll_no);
					getch();
					break;
				}
			case 4:{
					cout<<"\nPlease enter the Roll number to delete the record:";
					cin>>Roll_no;
					st.delete_record(Roll_no);
					getch();
					break;
			}
			case 5:{
					cout<<"\nPlease enter the Roll number to update the record:";
					cin>>Roll_no;
					st.update_record(Roll_no);
					getch();
					break;
			}
			case 6:break;
			default:{
					cout<<"\a";
					main();
				}
		}
	
	}
	while(ch!=6);
	return 0;
}
