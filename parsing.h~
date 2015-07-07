#include <iostream>
#include <cstdio>
#include <fstream>
#include <map>
#include <vector>

#include <ppl.hh>

using namespace std;
string find_bool_operator(string token)
{
	if(token.find("<=")!=string::npos)
	{
		return string("<=");
	}
	else if(token.find(">=")!=string::npos)
	{
		return string(">=");
	}
	else if(token.find("==")!=string::npos)
	{
		return string("==");
	}
	else if(token.find("!=")!=string::npos)
	{
		return string("!=");
	}
	else if(token.find("<")!=string::npos)
	{
		return string("<");
	}
	else if(token.find(">")!=string::npos)
	{
		return string(">");
	}
	return string("");
}


vector<std::string> &split(const string &s, char delim, vector<string> &elems) {
    stringstream ss(s);
    string item;
    while (getline(ss, item, delim)) {
        elems.push_back(item);
    }
    return elems;
}


vector<string> split(const string &s, char delim) {
    vector<string> elems;
    split(s, delim, elems);
    return elems;
}


Linear_Expression find_Linear_Expression(string str,int space_dim,Automaton a)
{
	

	vector<string> x = split(str, ' ');

	Linear_Expression ret;
	ret.set_space_dimension(space_dim);


	size_t pos = 0;
	std::string delimiter = "+";
	string token;
	int lastcoeff=0;

	//array<string,4> precop={string("+"),string("-"),string("/"),string("*")};
	vector<string> precop;
	precop.push_back("+");
	precop.push_back("-");
	precop.push_back("/");
	precop.push_back("*");
	vector<string> opstack;
	vector<string> postfix;

	for(vector<string>::iterator it=x.begin();it!=x.end();it++)
	{
		if( (*it)=="+" || (*it)=="-" || (*it)=="*" || (*it)=="/" )
		{
			//cout<<(*it)<<" Recognised as +,-,*,/"<<endl;
			if(opstack.size()==0)
			{
				opstack.push_back(*it);
			}
			else
			{
				//int d1=distance(a.cntr_var_lst.cntr_var_arr.begin(),find(a.cntr_var_lst.cntr_var_arr.begin(),a.cntr_var_lst.cntr_var_arr.end(),*it));
				//int d2=distance(a.cntr_var_lst.cntr_var_arr.begin(),find(a.cntr_var_lst.cntr_var_arr.begin(),a.cntr_var_lst.cntr_var_arr.end(),opstack.back()));

				int d1=distance(precop.begin(),find(precop.begin(),precop.end(),*it));
				int d2=distance(precop.begin(),find(precop.begin(),precop.end(),opstack.back()));

				//if(precop.index_of(*it)<precop.index_of(opstack.back()))
				if(d1<d2)
				{
					while(d1<d2 && precop.size()!=0 && opstack.size()!=0)
					{
						d2=distance(precop.begin(),find(precop.begin(),precop.end(),opstack.back()));
						postfix.push_back(opstack.back());
						opstack.pop_back();						
					}
					opstack.push_back(*it);
				}
				else
				{
					opstack.push_back(*it);
				}
			}
		}
		else
		{
			postfix.push_back(*it);
		}
	}

	//cout<<"Got input as "<<str<<endl;
	while(opstack.size()!=0)
	{
		postfix.push_back(opstack.back());
		opstack.pop_back();
	}
	

	
	/*cout<<"\nPostfix contents are:"<<postfix.size()<<endl;
	for(vector<string>::iterator it=postfix.begin();it!=postfix.end();it++)
	{
		cout<<(*it)<<endl;
	}
	cout<<endl;
	*/
	//vector<vector<double>(space_dim+1) > coeffstack;	


	//cout<<"Rahul"<<endl;
	vector<double*> coeffstack;	
	
	
	vector<string> operand_stack;
	for(vector<string>::iterator it=postfix.begin();it!=postfix.end();it++)
	{
		vector<string>::iterator strit=find(a.cntr_var_lst.cntr_var_arr.begin(),a.cntr_var_lst.cntr_var_arr.end(),*it);
		if(a.cntr_var_lst.cntr_var_arr.end()==strit )
		{
			//cout<<"Not in cntr_var"<<endl;
			if( (*it)=="+" || (*it)=="-" || (*it)=="*" || (*it)=="/" )
			{
				if( (*it)=="+" )
				{
					string op1=operand_stack.back();
					operand_stack.pop_back();
	
					string op2=operand_stack.back();
					operand_stack.pop_back();
				
					//array<double,space_dim+1> oparr1=coeffstack.back();
					double *oparr1=coeffstack.back();
					coeffstack.pop_back();

					//array<double,space_dim+1> oparr2=coeffstack.back();
					double *oparr2=coeffstack.back();
					coeffstack.pop_back();
		
					string opnew=op2.append("+").append(op1);
					operand_stack.push_back(opnew);

					//array<double,space_dim+1> oparrnew;
					double *oparrnew=new double[space_dim+1];
					for(int i=0;i<=space_dim;i++)
					{
						*(oparrnew+i)=0.0;
					}
					//cout<<opnew<<" oparrnew ";
					for(int i=0;i<space_dim+1;i++)
					{
						*(oparrnew+i)=(*(oparr2+i))+(*(oparr1+i));
						//cout<<*(oparrnew+i)<<endl;
					}			
					//cout<<endl;		
					coeffstack.push_back(oparrnew);
				}
				else if( (*it)=="-" )
				{
					string op1=operand_stack.back();
					operand_stack.pop_back();
	
					string op2=operand_stack.back();
					operand_stack.pop_back();
				
					//array<double,space_dim+1> oparr1=coeffstack.back();
					double *oparr1=coeffstack.back();
					coeffstack.pop_back();

					//array<double,space_dim+1> oparr2=coeffstack.back();
					double *oparr2=coeffstack.back();
					coeffstack.pop_back();
		
					string opnew=op2.append("-").append(op1);
					operand_stack.push_back(opnew);

					//array<double,space_dim+1> oparrnew;
					double *oparrnew=new double[space_dim+1];
					for(int i=0;i<=space_dim;i++)
					{
						*(oparrnew+i)=0.0;
					}
					for(int i=0;i<space_dim+1;i++)
					{
						*(oparrnew+i)=(*(oparr2+i))-(*(oparr1+i));
					}					
					coeffstack.push_back(oparrnew);
				}
				else if( (*it)=="*" )
				{
					string op1=operand_stack.back();
					operand_stack.pop_back();
	
					string op2=operand_stack.back();
					operand_stack.pop_back();
				
					//array<double,space_dim+1> oparr1=coeffstack.back();
					double *oparr1=coeffstack.back();
					coeffstack.pop_back();

					//array<double,space_dim+1> oparr2=coeffstack.back();
					double *oparr2=coeffstack.back();
					coeffstack.pop_back();
		
					string opnew=op2.append("*").append(op1);
					operand_stack.push_back(opnew);

					//array<double,space_dim+1> oparrnew;
					double *oparrnew=new double[space_dim+1];
					for(int i=0;i<=space_dim;i++)
					{
						*(oparrnew+i)=0.0;
					}
					
					for(int j=space_dim;j>=0;j--)
					{
						*(oparrnew+j)=(*(oparr2+space_dim))*(*(oparr1+j));
					}
					
					coeffstack.push_back(oparrnew);
				}
				else if( (*it)=="/" )
				{
					cout<<"This is not supported"<<endl;
				}
								
			}
			else
			{

				//cout<<(*it)<<" gonna be converted into float"<<endl; 
				double tmp=double(atof(it->c_str()));
				//cout<<endl<<(*it)<<" is converted into float value "<<tmp<<endl;			
				
				//if it is float
				if( (*it)=="0" || (*it)=="0.0" || tmp!=0.0)
				{						
					operand_stack.push_back(*it);
					//array<double,space_dim+1> ttmp;
					double *ttmp=new double[space_dim+1];
					for(int i=0;i<=space_dim;i++)
					{
						*(ttmp+i)=0.0;
					}
					*(ttmp+space_dim)=tmp;
					coeffstack.push_back(ttmp);				
					/*cout<<"ttmp:::::"<<endl;
					for(int i=0;i<=space_dim;i++)
					{
						cout<<*(ttmp+i)<<" ";
					}
					cout<<endl;*/
				}
				else
				{
					//it starts with negative followed by variable
					operand_stack.push_back(*it);

					string bool_operator("-");

					string str=(*it);
					int bool_operator_pos=str.find(bool_operator);
					
					

					vector<string>::iterator stritt=find(a.cntr_var_lst.cntr_var_arr.begin(),a.cntr_var_lst.cntr_var_arr.end(),str.substr(bool_operator_pos+bool_operator.size()));
					
					int dist=distance(a.cntr_var_lst.cntr_var_arr.begin(),stritt);
					//array<double,space_dim+1> ttmp;
					double *ttmp=new double[space_dim+1];
					for(int i=0;i<=space_dim;i++)
					{
						*(ttmp+i)=0.0;
					}
					*(ttmp+dist)=-1.0;
					coeffstack.push_back(ttmp);				
					
				}
			}
		}
		else
		{
			//cout<<"My god found loc"<<endl;
			operand_stack.push_back(*it);
			int dist=distance(a.cntr_var_lst.cntr_var_arr.begin(),strit);
			//cout<<"My god found loc2"<<endl;
			//array<double,space_dim+1> ttmp;
			double *ttmp=new double[space_dim+1];
			for(int i=0;i<=space_dim;i++)
			{
				*(ttmp+i)=0.0;
			}
			//cout<<"My god found loc3"<<endl;
			*(ttmp+dist)=1.0;
			//cout<<"My god found loc4"<<endl;
			coeffstack.push_back(ttmp);				
		}
	}
	

	

	for(int i=0;i<space_dim;i++)
	{
		//cout<<endl<<"Coeffstack:"<<*((*coeffstack.begin())+i)<<endl;
		//ret.set_coefficient(Variable(i),coeffstack.begin()->at(i));
		//cout<<"Is it "<<int(*((*coeffstack.begin())+i))<<endl;
		ret.set_coefficient(Variable(i),int(*((*coeffstack.begin())+i)));
	}
	//ret.set_inhomogeneous_term(coeffstack.begin()->at(space_dim));
	//cout<<"Have a seat"<<endl;
	ret.set_inhomogeneous_term(int(*((*coeffstack.begin())+space_dim)));
	//cout<<"Returning linear expression:"<<ret<<endl;

	return ret;
}




/*Linear_Expression find_Linear_Expression(string str,int space_dim,Automaton a)
{
	//cout<<"Str:"<<str<<endl;
	Linear_Expression ret;
	ret.set_space_dimension(space_dim);



	size_t pos = 0;
	std::string delimiter = "+";
	string token;
	int lastcoeff=0;


	while ((pos = str.find(delimiter)) != string::npos) {
	    token = str.substr(0, pos);
	    //cout <<"+:"<< token << endl;

	    lastcoeff=0;

	    size_t pos1 = 0;
    	std::string delimiter1 = "*";
    	string token1;
    	while ((pos1 = token.find(delimiter1)) != string::npos) {
    	    token1 = token.substr(0, pos1);
    	    //cout <<"p:*:"<< token1 << endl;
    	    if(atoi(token1.c_str())!=0)
    	    {
    	    	lastcoeff=atoi(token1.c_str());
    	    	std::string::iterator end_pos = std::remove(token1.begin(), token1.end(), ' ');
    	    	token1.erase(end_pos, token1.end());
    	    	//cout<<token1<<" Is number"<<endl;

    	    }
    	    else
    	    {
    	    	std::string::iterator end_pos = std::remove(token1.begin(), token1.end(), ' ');
   	   	    	token1.erase(end_pos, token1.end());

    	    	//cout<<token1<<" Is not a number"<<endl;



    	    	vector<string>::iterator i=find(a.cntr_var_lst.cntr_var_arr.begin(),a.cntr_var_lst.cntr_var_arr.end(),token1);
    	    	//cout<<"Index:"<<(i-a.cntr_var_lst.cntr_var_arr.begin())<<endl;

    	    	if(lastcoeff==0)
    	    		lastcoeff=1;

    	    	ret.set_coefficient(Variable(i-a.cntr_var_lst.cntr_var_arr.begin()),lastcoeff);

    	    	lastcoeff=0;
    	    }
    	    ret.set_inhomogeneous_term(lastcoeff);
    	    token.erase(0, pos1 + delimiter.length());
    	}


    	//cout<<"p:*:"<<token<<endl;


    	if(atoi(token.c_str())!=0)
    	{
    		lastcoeff=atoi(token.c_str());
    		std::string::iterator end_pos = std::remove(token.begin(), token.end(), ' ');
    		token.erase(end_pos, token.end());
    	  	//cout<<token<<" Is number"<<endl;
    	}
    	else
    	{
    		std::string::iterator end_pos = std::remove(token.begin(), token.end(), ' ');
   	    	token.erase(end_pos, token.end());

    		//cout<<token<<" Is not a number"<<endl;


    		vector<string>::iterator i=find(a.cntr_var_lst.cntr_var_arr.begin(),a.cntr_var_lst.cntr_var_arr.end(),token);
   	    	//cout<<"Index:"<<(i-a.cntr_var_lst.cntr_var_arr.begin())<<endl;

   	    	//Variable x(i-a.cntr_var_lst.cntr_var_arr.begin());
	    	if(lastcoeff==0)
	    		lastcoeff=1;


   	    	ret.set_coefficient(Variable(i-a.cntr_var_lst.cntr_var_arr.begin()),lastcoeff);

   	    	lastcoeff=0;
    	}
    	ret.set_inhomogeneous_term(lastcoeff);


	    str.erase(0, pos1 + delimiter1.length());
	}
	//cout<<"+:"<<str<<endl;

	size_t pos1 = 0;
	std::string delimiter1 = "*";
	string token1;
	while ((pos1 = str.find(delimiter1)) != string::npos) {
	    token1 = str.substr(0, pos1);
	    //cout <<"*:"<< token1 << endl;

	    //cout <<"q:*:"<< token1 << endl;
   	    if(atoi(token1.c_str())!=0)
   	    {
   	    	lastcoeff=atoi(token1.c_str());
   	    	std::string::iterator end_pos = std::remove(token1.begin(), token1.end(), ' ');
   	    	token1.erase(end_pos, token1.end());
   	    	//cout<<token1<<" Is number"<<endl;
   	    }
   	    else
   	    {
   	    	std::string::iterator end_pos = std::remove(token1.begin(), token1.end(), ' ');
   	    	token1.erase(end_pos, token1.end());
   	    	//cout<<token1<<" Is not a number"<<endl;


   	    	vector<string>::iterator i=find(a.cntr_var_lst.cntr_var_arr.begin(),a.cntr_var_lst.cntr_var_arr.end(),token1);
   	    	//cout<<"Index:"<<(i-a.cntr_var_lst.cntr_var_arr.begin())<<endl;
	    	if(lastcoeff==0)
	    		lastcoeff=1;


   	    	ret.set_coefficient(Variable(i-a.cntr_var_lst.cntr_var_arr.begin()),lastcoeff);

   	    	lastcoeff=0;
   	    }
   	    ret.set_inhomogeneous_term(lastcoeff);


		str.erase(0, pos1 + delimiter1.length());
	}

	//cout<<"*:"<<str<<endl;

    //cout <<"q:*:"<< str << endl;
    if(atoi(str.c_str())!=0)
    {
    	lastcoeff=atoi(str.c_str());
    	std::string::iterator end_pos = std::remove(str.begin(), str.end(), ' ');
    	str.erase(end_pos, str.end());

    	//cout<<str<<" Is number"<<endl;
    }
    else
    {
    	std::string::iterator end_pos = std::remove(str.begin(), str.end(), ' ');
    	str.erase(end_pos, str.end());
    	//cout<<str<<" Is not a number"<<endl;


    	vector<string>::iterator i=find(a.cntr_var_lst.cntr_var_arr.begin(),a.cntr_var_lst.cntr_var_arr.end(),str);
    	//cout<<"Index:"<<(i-a.cntr_var_lst.cntr_var_arr.begin())<<endl;
    	if(lastcoeff==0)
    		lastcoeff=1;


    	ret.set_coefficient(Variable(i-a.cntr_var_lst.cntr_var_arr.begin()),lastcoeff);

    	lastcoeff=0;
    }
    ret.set_inhomogeneous_term(lastcoeff);

	return ret;
}
*/
Constraint make_Constraints(Linear_Expression left_le,Linear_Expression right_le,string bool_operator)
{
	if(bool_operator=="<=")
	{
		return Constraint(left_le<=right_le);
	}
	else if(bool_operator==">=")
	{
		return Constraint(left_le>=right_le);
	}
	else if(bool_operator=="==")
	{
		return Constraint(left_le==right_le);
	}
	else if(bool_operator=="<")
	{
		return Constraint(left_le<right_le);
	}
	else if(bool_operator==">")
	{
		return Constraint(left_le>right_le);
	}
}

void parseInvariants(string &rem_guard_str,Location &current_loc,Automaton &a)
{


	string delimiter = "&";

	int pos = 0;
	string token;

	//Constraint_System invariants;
	Constraint ctmp;
	ctmp.set_space_dimension(a.cntr_var_lst.cntr_var_arr.size());


	string bool_operator;
	int bool_operator_pos;
	Linear_Expression left_le;
	Linear_Expression right_le;
	while ((pos = rem_guard_str.find(delimiter)) != string::npos) {
		token = rem_guard_str.substr(0, pos);
		//cout << token << endl;

		bool_operator=find_bool_operator(token);
		bool_operator_pos=token.find(bool_operator);

		left_le.set_space_dimension(a.cntr_var_lst.cntr_var_arr.size());
		left_le=find_Linear_Expression(token.substr(0,bool_operator_pos),a.cntr_var_lst.cntr_var_arr.size(),a);

		right_le.set_space_dimension(a.cntr_var_lst.cntr_var_arr.size());
		right_le=find_Linear_Expression(token.substr(bool_operator_pos+bool_operator.size()),a.cntr_var_lst.cntr_var_arr.size(),a);
		//cout<<"Left:"<<token.substr(0,bool_operator_pos)<<endl;
		//cout<<"Right:"<<token.substr(bool_operator_pos+bool_operator.size())<<endl;

		//cout<<"Left LE:"<<left_le<<endl;
		//cout<<"Right LE:"<<right_le<<endl;

		ctmp.set_space_dimension(a.cntr_var_lst.cntr_var_arr.size());
		ctmp=make_Constraints(left_le,right_le,bool_operator);
		//cout<<"Made Constraint:"<<ctmp<<endl;

		//invariants.insert(ctmp);
		current_loc.invariants.insert(ctmp);

		/*Linear_Expression e11;
		e11.set_space_dimension(2);
		e11.set_inhomogeneous_term(2);


		e11.set_coefficient(Variable(0),2);
		e11.set_coefficient(Variable(1),3);

		Linear_Expression e22;
		e22.set_space_dimension(2);
		e22.set_inhomogeneous_term(10);

		Constraint c(e11<e22);
		cout<<"New Constraint:"<<c<<endl;*/


	    rem_guard_str.erase(0, pos + delimiter.length());

	}
	//cout<<rem_guard_str<<endl;
	bool_operator=find_bool_operator(rem_guard_str);
	bool_operator_pos=rem_guard_str.find(bool_operator);

	//Linear_Expression left_le;
	left_le.set_space_dimension(a.cntr_var_lst.cntr_var_arr.size());
	left_le=find_Linear_Expression(rem_guard_str.substr(0,bool_operator_pos),a.cntr_var_lst.cntr_var_arr.size(),a);
	//Linear_Expression right_le;
	right_le.set_space_dimension(a.cntr_var_lst.cntr_var_arr.size());
	right_le=find_Linear_Expression(rem_guard_str.substr(bool_operator_pos+bool_operator.size()),a.cntr_var_lst.cntr_var_arr.size(),a);
	//cout<<"Left:"<<rem_guard_str.substr(0,bool_operator_pos)<<endl;
	//cout<<"Right:"<<rem_guard_str.substr(bool_operator_pos+bool_operator.size())<<endl;
	//cout<<"Left LE:"<<left_le<<endl;
	//cout<<"Right LE:"<<right_le<<endl;

	ctmp.set_space_dimension(a.cntr_var_lst.cntr_var_arr.size());
	ctmp=make_Constraints(left_le,right_le,bool_operator);
	//cout<<"Made constraint:"<<ctmp<<endl;

	current_loc.invariants.insert(ctmp);
	//invariants.insert(ctmp);
	add_trivial_constraints(current_loc.invariants);

}



void parseGuards(string &rem_guard_str,Edge &e,Automaton &a)
{


	string delimiter = "&";

	int pos = 0;
	string token;

	//Constraint_System invariants;
	Constraint ctmp;
	ctmp.set_space_dimension(a.cntr_var_lst.cntr_var_arr.size());


	string bool_operator;
	int bool_operator_pos;
	Linear_Expression left_le;
	Linear_Expression right_le;
	while ((pos = rem_guard_str.find(delimiter)) != string::npos) {
		token = rem_guard_str.substr(0, pos);
		//cout << token << endl;

		bool_operator=find_bool_operator(token);
		bool_operator_pos=token.find(bool_operator);

		left_le.set_space_dimension(a.cntr_var_lst.cntr_var_arr.size());
		left_le=find_Linear_Expression(token.substr(0,bool_operator_pos),a.cntr_var_lst.cntr_var_arr.size(),a);

		right_le.set_space_dimension(a.cntr_var_lst.cntr_var_arr.size());
		right_le=find_Linear_Expression(token.substr(bool_operator_pos+bool_operator.size()),a.cntr_var_lst.cntr_var_arr.size(),a);
		//cout<<"Left:"<<token.substr(0,bool_operator_pos)<<endl;
		//cout<<"Right:"<<token.substr(bool_operator_pos+bool_operator.size())<<endl;

		//cout<<"Left LE:"<<left_le<<endl;
		//cout<<"Right LE:"<<right_le<<endl;

		ctmp.set_space_dimension(a.cntr_var_lst.cntr_var_arr.size());
		ctmp=make_Constraints(left_le,right_le,bool_operator);
		//cout<<"Made Constraint:"<<ctmp<<endl;

		//invariants.insert(ctmp);
		//current_loc.invariants.insert(ctmp);
		e.guards.insert(ctmp);



	    rem_guard_str.erase(0, pos + delimiter.length());

	}
	//cout<<rem_guard_str<<endl;
	bool_operator=find_bool_operator(rem_guard_str);
	bool_operator_pos=rem_guard_str.find(bool_operator);

	//Linear_Expression left_le;
	left_le.set_space_dimension(a.cntr_var_lst.cntr_var_arr.size());
	left_le=find_Linear_Expression(rem_guard_str.substr(0,bool_operator_pos),a.cntr_var_lst.cntr_var_arr.size(),a);
	//Linear_Expression right_le;
	right_le.set_space_dimension(a.cntr_var_lst.cntr_var_arr.size());
	right_le=find_Linear_Expression(rem_guard_str.substr(bool_operator_pos+bool_operator.size()),a.cntr_var_lst.cntr_var_arr.size(),a);
	//cout<<"Left:"<<rem_guard_str.substr(0,bool_operator_pos)<<endl;
	//cout<<"Right:"<<rem_guard_str.substr(bool_operator_pos+bool_operator.size())<<endl;
	//cout<<"Left LE:"<<left_le<<endl;
	//cout<<"Right LE:"<<right_le<<endl;

	ctmp.set_space_dimension(a.cntr_var_lst.cntr_var_arr.size());
	ctmp=make_Constraints(left_le,right_le,bool_operator);
	//cout<<"Made constraint:"<<ctmp<<endl;

	e.guards.insert(ctmp);
	//current_loc.invariants.insert(ctmp);
	//invariants.insert(ctmp);
	add_trivial_constraints(e.guards);

}



void parseRateVector(string &rem_rate_str,Location &current_loc,Automaton &a)
{


	string delimiter = "&";

	int pos = 0;
	string token;

	//Constraint_System invariants;
	Constraint ctmp;
	ctmp.set_space_dimension(a.cntr_var_lst.cntr_var_arr.size());


	string bool_operator;
	int bool_operator_pos;
	Linear_Expression left_le;
	Linear_Expression right_le;
	while ((pos = rem_rate_str.find(delimiter)) != string::npos) {
		token = rem_rate_str.substr(0, pos);
		//cout << token << endl;

		bool_operator=find_bool_operator(token);
		bool_operator_pos=token.find(bool_operator);

		left_le.set_space_dimension(a.cntr_var_lst.cntr_var_arr.size());
		left_le=find_Linear_Expression(token.substr(0,bool_operator_pos),a.cntr_var_lst.cntr_var_arr.size(),a);

		right_le.set_space_dimension(a.cntr_var_lst.cntr_var_arr.size());
		right_le=find_Linear_Expression(token.substr(bool_operator_pos+bool_operator.size()),a.cntr_var_lst.cntr_var_arr.size(),a);
		//cout<<"Left:"<<token.substr(0,bool_operator_pos)<<endl;
		//cout<<"Right:"<<token.substr(bool_operator_pos+bool_operator.size())<<endl;

		//cout<<"Left LE:"<<left_le<<endl;
		//cout<<"Right LE:"<<right_le<<endl;

		ctmp.set_space_dimension(a.cntr_var_lst.cntr_var_arr.size());
		ctmp=make_Constraints(left_le,right_le,bool_operator);
		//cout<<"Made Constraint:"<<ctmp<<endl;

		//invariants.insert(ctmp);
		current_loc.rate.insert(ctmp);



	    rem_rate_str.erase(0, pos + delimiter.length());

	}
	//cout<<rem_rate_str<<endl;
	bool_operator=find_bool_operator(rem_rate_str);
	bool_operator_pos=rem_rate_str.find(bool_operator);

	//Linear_Expression left_le;
	left_le.set_space_dimension(a.cntr_var_lst.cntr_var_arr.size());
	left_le=find_Linear_Expression(rem_rate_str.substr(0,bool_operator_pos),a.cntr_var_lst.cntr_var_arr.size(),a);
	//Linear_Expression right_le;
	right_le.set_space_dimension(a.cntr_var_lst.cntr_var_arr.size());
	right_le=find_Linear_Expression(rem_rate_str.substr(bool_operator_pos+bool_operator.size()),a.cntr_var_lst.cntr_var_arr.size(),a);
	//cout<<"Left:"<<rem_guard_str.substr(0,bool_operator_pos)<<endl;
	//cout<<"Right:"<<rem_guard_str.substr(bool_operator_pos+bool_operator.size())<<endl;
	//cout<<"Left LE:"<<left_le<<endl;
	//cout<<"Right LE:"<<right_le<<endl;

	ctmp.set_space_dimension(a.cntr_var_lst.cntr_var_arr.size());
	ctmp=make_Constraints(left_le,right_le,bool_operator);
	//cout<<"Made constraint:"<<ctmp<<endl;

	current_loc.rate.insert(ctmp);
	//invariants.insert(ctmp);
	//add_trivial_constraints(current_loc.rate);

}



void parseUpdateVector(string &rem_rate_str,Edge &e,Automaton &a)
{


	string delimiter = "&";

	int pos = 0;
	string token;

	//Constraint_System invariants;
	Constraint ctmp;
	ctmp.set_space_dimension(a.cntr_var_lst.cntr_var_arr.size());


	string bool_operator;
	int bool_operator_pos;
	Linear_Expression left_le;
	Linear_Expression right_le;
	while ((pos = rem_rate_str.find(delimiter)) != string::npos) {
		token = rem_rate_str.substr(0, pos);
		//cout << token << endl;

		bool_operator=find_bool_operator(token);
		bool_operator_pos=token.find(bool_operator);

		left_le.set_space_dimension(a.cntr_var_lst.cntr_var_arr.size());
		left_le=find_Linear_Expression(token.substr(0,bool_operator_pos),a.cntr_var_lst.cntr_var_arr.size(),a);

		right_le.set_space_dimension(a.cntr_var_lst.cntr_var_arr.size());
		right_le=find_Linear_Expression(token.substr(bool_operator_pos+bool_operator.size()),a.cntr_var_lst.cntr_var_arr.size(),a);
		//cout<<"Left:"<<token.substr(0,bool_operator_pos)<<endl;
		//cout<<"Right:"<<token.substr(bool_operator_pos+bool_operator.size())<<endl;

		//cout<<"Left LE:"<<left_le<<endl;
		//cout<<"Right LE:"<<right_le<<endl;

		ctmp.set_space_dimension(a.cntr_var_lst.cntr_var_arr.size());
		ctmp=make_Constraints(left_le,right_le,bool_operator);
		//cout<<"Made Constraint:"<<ctmp<<endl;

		//invariants.insert(ctmp);
		//current_loc.rate.insert(ctmp);
		e.updates.insert(ctmp);



	    rem_rate_str.erase(0, pos + delimiter.length());

	}
	//cout<<rem_rate_str<<endl;
	bool_operator=find_bool_operator(rem_rate_str);
	bool_operator_pos=rem_rate_str.find(bool_operator);

	//Linear_Expression left_le;
	left_le.set_space_dimension(a.cntr_var_lst.cntr_var_arr.size());
	left_le=find_Linear_Expression(rem_rate_str.substr(0,bool_operator_pos),a.cntr_var_lst.cntr_var_arr.size(),a);
	//Linear_Expression right_le;
	right_le.set_space_dimension(a.cntr_var_lst.cntr_var_arr.size());
	right_le=find_Linear_Expression(rem_rate_str.substr(bool_operator_pos+bool_operator.size()),a.cntr_var_lst.cntr_var_arr.size(),a);
	//cout<<"Left:"<<rem_guard_str.substr(0,bool_operator_pos)<<endl;
	//cout<<"Right:"<<rem_guard_str.substr(bool_operator_pos+bool_operator.size())<<endl;
	//cout<<"Left LE:"<<left_le<<endl;
	//cout<<"Right LE:"<<right_le<<endl;

	ctmp.set_space_dimension(a.cntr_var_lst.cntr_var_arr.size());
	ctmp=make_Constraints(left_le,right_le,bool_operator);
	//cout<<"Made constraint:"<<ctmp<<endl;

	//current_loc.rate.insert(ctmp);
	//invariants.insert(ctmp);


	e.updates.insert(ctmp);
	//add_trivial_constraints(e.updates);

}


void parseInitialGuards(string &rem_guard_str,Location &init_loc,Automaton &a)
{


	string delimiter = "&";

	int pos = 0;
	string token;

	//Constraint_System invariants;
	Constraint ctmp;
	ctmp.set_space_dimension(a.cntr_var_lst.cntr_var_arr.size());


	string bool_operator;
	int bool_operator_pos;
	Linear_Expression left_le;
	Linear_Expression right_le;
	while ((pos = rem_guard_str.find(delimiter)) != string::npos) {
		token = rem_guard_str.substr(0, pos);
		//cout << token << endl;

		bool_operator=find_bool_operator(token);
		bool_operator_pos=token.find(bool_operator);

		left_le.set_space_dimension(a.cntr_var_lst.cntr_var_arr.size());
		left_le=find_Linear_Expression(token.substr(0,bool_operator_pos),a.cntr_var_lst.cntr_var_arr.size(),a);

		right_le.set_space_dimension(a.cntr_var_lst.cntr_var_arr.size());
		right_le=find_Linear_Expression(token.substr(bool_operator_pos+bool_operator.size()),a.cntr_var_lst.cntr_var_arr.size(),a);
		//cout<<"Left:"<<token.substr(0,bool_operator_pos)<<endl;
		//cout<<"Right:"<<token.substr(bool_operator_pos+bool_operator.size())<<endl;

		//cout<<"Left LE:"<<left_le<<endl;
		//cout<<"Right LE:"<<right_le<<endl;

		ctmp.set_space_dimension(a.cntr_var_lst.cntr_var_arr.size());
		ctmp=make_Constraints(left_le,right_le,bool_operator);
		//cout<<"Made Constraint:"<<ctmp<<endl;

		//invariants.insert(ctmp);
		//current_loc.invariants.insert(ctmp);
		//e.guards.insert(ctmp);
		init_loc.invariants.insert(ctmp);



	    rem_guard_str.erase(0, pos + delimiter.length());

	}
	//cout<<rem_guard_str<<endl;
	bool_operator=find_bool_operator(rem_guard_str);
	bool_operator_pos=rem_guard_str.find(bool_operator);

	//Linear_Expression left_le;
	left_le.set_space_dimension(a.cntr_var_lst.cntr_var_arr.size());
	left_le=find_Linear_Expression(rem_guard_str.substr(0,bool_operator_pos),a.cntr_var_lst.cntr_var_arr.size(),a);
	//Linear_Expression right_le;
	right_le.set_space_dimension(a.cntr_var_lst.cntr_var_arr.size());
	right_le=find_Linear_Expression(rem_guard_str.substr(bool_operator_pos+bool_operator.size()),a.cntr_var_lst.cntr_var_arr.size(),a);
	//cout<<"Left:"<<rem_guard_str.substr(0,bool_operator_pos)<<endl;
	//cout<<"Right:"<<rem_guard_str.substr(bool_operator_pos+bool_operator.size())<<endl;
	//cout<<"Left LE:"<<left_le<<endl;
	//cout<<"Right LE:"<<right_le<<endl;

	ctmp.set_space_dimension(a.cntr_var_lst.cntr_var_arr.size());
	ctmp=make_Constraints(left_le,right_le,bool_operator);
	//cout<<"Made constraint:"<<ctmp<<endl;

	init_loc.invariants.insert(ctmp);
	//e.guards.insert(ctmp);
	//current_loc.invariants.insert(ctmp);
	//invariants.insert(ctmp);


}


void parseAutomaton(string &aut,Automaton_List &aut_lst)
{
	//cout<<ret;
	Automaton a;
	string t;
	istringstream f(aut);
	string str_automaton="automaton";
	string str_cntr_var="contr_var";
	string str_parameter="parameter";
	string str_input_var="input_var";
	string str_synclabs="synclabs";
	string str_loc="loc";
	string str_initially="initially";
	string str_end="end";
	getline(f,t);
	while(true)
	{

		if(t.compare(0,str_automaton.size(),str_automaton)==0)
		{
			//cout<<t<<endl;
			//cout<<t.substr(str_automaton.size()+1)<<endl;
			a.name=t.substr(str_automaton.size()+1);

			getline(f,t);

		}
		else if(t.compare(0,str_cntr_var.size(),str_cntr_var)==0)
		{
			//cout<<t<<endl;
			string tmp;
			string cntr_val_str=t.substr(str_cntr_var.size()+2,t.size()-str_cntr_var.size()-3);
			//istringstream f(cntr_val_str);

			std::string delimiter = ",";

			size_t pos = 0;
			string token;
			//Control_Variable cvar;
			while ((pos = cntr_val_str.find(delimiter)) != string::npos) {
			    token = cntr_val_str.substr(0, pos);
			    //cout << token << endl;

			    //cvar.name=token;
			    a.cntr_var_lst.cntr_var_arr.push_back(token);
			    cntr_val_str.erase(0, pos + delimiter.length());
			}
			//cvar.name=cntr_val_str;
			a.cntr_var_lst.cntr_var_arr.push_back(cntr_val_str);
			//cout << cntr_val_str << endl;
			//for(vector<Control_Variable>::iterator i=a.cntr_var_lst.cntr_var_arr.begin();i!=a.cntr_var_lst.cntr_var_arr.end();i++)
			//{
			//	cout<<"p:"<<(*i).name<<endl;
			//}



			getline(f,t);
		}
		else if(t.compare(0,str_parameter.size(),str_parameter)==0)
		{
			//cout<<t<<endl;
			string tmp;
			string par_str=t.substr(str_parameter.size()+2,t.size()-str_parameter.size()-3);

			std::string delimiter = ",";

			size_t pos = 0;
			string token;
			Parameter par;
			while ((pos = par_str.find(delimiter)) != string::npos) {
			    token = par_str.substr(0, pos);
			    //cout << "" <<token << endl;

			    par.name=token;
			    a.parameter_lst.par_list_arr.push_back(par);
			    par_str.erase(0, pos + delimiter.length());
			}
			par.name=par_str;
			a.parameter_lst.par_list_arr.push_back(par);
			//cout << par_str << endl;
			//for(vector<Parameter>::iterator i=a.parameter_lst.par_list_arr.begin();i!=a.parameter_lst.par_list_arr.end();i++)
			//{
			//	cout<<"p:"<<(*i).name<<endl;
			//}


			getline(f,t);
		}
		else if(t.compare(0,str_input_var.size(),str_input_var)==0)
		{

			//cout<<t<<endl;
			string tmp;
			string input_var_str=t.substr(str_input_var.size()+2,t.size()-str_input_var.size()-3);


			std::string delimiter = ",";

			size_t pos = 0;
			string token;
			Input_Variable invar;
			while ((pos = input_var_str.find(delimiter)) != string::npos) {
			    token = input_var_str.substr(0, pos);
			    //cout << token << endl;

			    invar.name=token;
			    a.in_var_lst.in_var_arr.push_back(invar);
			    input_var_str.erase(0, pos + delimiter.length());
			}
			invar.name=input_var_str;
			a.in_var_lst.in_var_arr.push_back(invar);
			//cout << input_var_str << endl;
			//for(vector<Input_Variable>::iterator i=a.in_var_lst.in_var_arr.begin();i!=a.in_var_lst.in_var_arr.end();i++)
			//{
			//	cout<<"p:"<<(*i).name<<endl;
			//}



			getline(f,t);
		}
		else if(t.compare(0,str_synclabs.size(),str_synclabs)==0)
		{
			//cout<<t<<endl;
			string tmp;
			string synclabs_str=t.substr(str_synclabs.size()+2,t.size()-str_synclabs.size()-3);


			std::string delimiter = ",";

			size_t pos = 0;
			string token;
			Synchronizing_Label slab;
			while ((pos = synclabs_str.find(delimiter)) != string::npos) {
			    token = synclabs_str.substr(0, pos);
			    //cout << token << endl;

			    slab.name=token;
			    a.syn_lab_lst.syn_lab_arr.push_back(slab);
			    synclabs_str.erase(0, pos + delimiter.length());
			}
			slab.name=synclabs_str;
			a.syn_lab_lst.syn_lab_arr.push_back(slab);
			//cout << synclabs_str << endl;
			//for(vector<Synchronizing_Label>::iterator i=a.syn_lab_lst.syn_lab_arr.begin();i!=a.syn_lab_lst.syn_lab_arr.end();i++)
			//{
				//cout<<"p:"<<(*i).name<<endl;
			//}


			getline(f,t);
		}
		else if(t.compare(0,str_loc.size(),str_loc)==0)
		{
			//cout<<t<<endl;
			int colon_pos=t.find(':',0);
			//cout<<t.substr(4,pos-4)<<endl;
			Location current_loc;
			current_loc.name=t.substr(4,colon_pos-4);

			string rem_str=t.substr(colon_pos+2,t.size()-colon_pos-1);

			int e=rem_str.find("wait");

			string str_while="while";
			//cout<<rem_str.substr(6,e-7)<<endl;



			string rem_guard_str=rem_str.substr(6,e-7);

			parseInvariants(rem_guard_str,current_loc,a);


			/*cout<<"Invariants:"<<endl;
			for(Constraint_System::const_iterator i=current_loc.invariants.begin();i!=current_loc.invariants.end();i++)
			{
				cout<<*i<<endl;
			}*/


			//cout<<"Rem:"<<rem_str.substr(e+4)<<endl;
			string rem_rate_str=rem_str.substr(e+4);
			std::string::iterator end_pos = std::remove(rem_rate_str.begin(), rem_rate_str.end(), ' ');
			rem_rate_str.erase(end_pos, rem_rate_str.end());

			end_pos = std::remove(rem_rate_str.begin(), rem_rate_str.end(), '\'');
			rem_rate_str.erase(end_pos, rem_rate_str.end());

			end_pos = std::remove(rem_rate_str.begin(), rem_rate_str.end(), '{');
			rem_rate_str.erase(end_pos, rem_rate_str.end());

			end_pos = std::remove(rem_rate_str.begin(), rem_rate_str.end(), '}');
			rem_rate_str.erase(end_pos, rem_rate_str.end());
			//cout<<rem_rate_str<<endl;

			parseRateVector(rem_rate_str,current_loc,a);

			/*
			cout<<"Rate Vector:"<<endl;

			for(Constraint_System::const_iterator i=current_loc.rate.begin();i!=current_loc.rate.end();i++)
			{
				cout<<*i<<endl;
			}
			*/

			//cout<<a.name<<endl;
			string str_when="when";
			while(getline(f,t))
			{
				if(t.compare(1,str_when.size(),str_when)==0)
				{
					Edge e;
					e.pre=current_loc.name;

					t=t.substr(1);
					//cout<<"t:"<<t<<endl;

					int pos=t.find("sync");
					if(pos!=string::npos)
					{
						string tmp=t.substr(4,pos-4);


						//cout<<"Guards:"<<tmp<<endl;

						parseGuards(tmp,e,a);



						t=t.substr(pos+4);


						//cout<<"New t:"<<t<<endl;
						int do_pos=t.find("do");
						if(do_pos!=string::npos)
						{

							string do_str=t.substr(do_pos+2,t.find("goto")-do_pos-2);

							std::string::iterator end_p = std::remove(do_str.begin(), do_str.end(), '}');
							do_str.erase(end_p, do_str.end());

							end_p = std::remove(do_str.begin(), do_str.end(), '{');
							do_str.erase(end_p, do_str.end());

							end_p = std::remove(do_str.begin(), do_str.end(), '\'');
							do_str.erase(end_p, do_str.end());
							//cout<<"DO GUARDS:"<<do_str<<endl;

							parseUpdateVector(do_str,e,a);


							string synclab=t.substr(0,do_pos);
							std::string::iterator end_poss = std::remove(synclab.begin(), synclab.end(), ' ');
							synclab.erase(end_poss, synclab.end());
							//cout<<"Synclabs:"<<synclab<<endl;

							e.syn_lab=synclab;

							//cout<<"Rem string:"<<t.substr(do_pos)<<endl;


							t=t.substr(do_pos);
							int goto_pos=t.find("goto");
							if(goto_pos!=string::npos)
							{
								//cout<<"Goto string:"<<t.substr(goto_pos)<<endl;

								string goto_str=t.substr(goto_pos);
								//cout<<"Location:"<<goto_str.substr(4)<<endl;
								string loc=goto_str.substr(4);

								std::string::iterator end_pos = std::remove(loc.begin(), loc.end(), ' ');
								loc.erase(end_pos, loc.end());

								std::string::iterator end_pos1 = std::remove(loc.begin(), loc.end(), ';');
								loc.erase(end_pos1, loc.end());

								e.post=loc;
								//cout<<"Dest Loc:"<<loc<<endl;



							}
							else
							{
								//no goto in input
							}

						}
						else
						{
							//no do in input
							int goto_pos=t.find("goto");
							string synclab=t.substr(0,goto_pos);
							std::string::iterator end_poss = std::remove(synclab.begin(), synclab.end(), ' ');
							synclab.erase(end_poss, synclab.end());
							//cout<<"Synclabs:"<<synclab<<endl;
							e.syn_lab=synclab;

							//cout<<"Syncccccc:"<<t<<endl;




							//int goto_pos=t.find("goto");
							if(goto_pos!=string::npos)
							{
								//cout<<"Goto string:"<<t.substr(goto_pos)<<endl;

								string goto_str=t.substr(goto_pos);
								//cout<<"Location:"<<goto_str.substr(4)<<endl;
								string loc=goto_str.substr(4);

								std::string::iterator end_pos = std::remove(loc.begin(), loc.end(), ' ');
								loc.erase(end_pos, loc.end());

								std::string::iterator end_pos1 = std::remove(loc.begin(), loc.end(), ';');
								loc.erase(end_pos1, loc.end());

								e.post=loc;
								//cout<<"Dest Loc:"<<loc<<endl;



							}
							else
							{
								//no goto in input
							}

						}
					}
					else
					{
						//no sync in input
					}
					a.edge_lst.edge_arr.push_back(e);

				}
				else
				{
					//no while statement
					break;
				}

			}


			a.loc_lst.location_arr.push_back(current_loc);
		}
		else if(t.compare(0,str_initially.size(),str_initially)==0)
		{
			//cout<<t<<endl;
			t=t.substr(str_initially.size()+1);
			string delimiter="&";
			int pos=0;

			Location init_loc;
			string token;

			if ((pos = t.find(delimiter)) != string::npos) {
				token = t.substr(0, pos);
				std::string::iterator end_pos = std::remove(token.begin(), token.end(),' ');
				token.erase(end_pos, token.end());

				init_loc.name=token;

				t.erase(0, pos + delimiter.length());


				end_pos = std::remove(t.begin(), t.end(), ';');
				t.erase(end_pos, t.end());



				parseInitialGuards(t,init_loc,a);
			}
			else
			{
				init_loc.name=token;
			}

			a.initial_loc_lst.location_arr.push_back(init_loc);


			/*for(vector<Location>::iterator i=a.initial_loc_lst.location_arr.begin();i!=a.initial_loc_lst.location_arr.end();i++)
			{

				for(Constraint_System_const_iterator j=(*i).invariants.begin();j!=(*i).invariants.end();j++)
				{
					cout<<"q:"<<(*j)<<endl;

				}
				cout<<"p:"<<(*i).name<<endl;
			}*/

			getline(f,t);
		}
		else if(t.compare(0,str_end.size(),str_end)==0)
		{
			//cout<<t<<endl;
			break;
		}
	}
	aut_lst.aut_arr.push_back(a);
}
void parseFile(ifstream &f,Automaton_List &aut_lst)
{
	string s;
	getline(f,s);
	string ret;
	string aut="automaton";
	bool flg=false;
	while(true)
	{
		ret="";
		while(s.compare(0,aut.size(),aut)!=0)
		{
			if(s.size()!=aut.size() && s.size()<=1)
			{
				flg=true;
				break;
			}
			//cout<<s;
			getline(f,s);
			//cout<<endl;
		}
		if(flg==true)
			break;
		while(s!="end")
		{

			//cout<<s;
			ret+=s+"\n";
			getline(f,s);
			//cout<<endl;
		}
		ret+=s+"\n";
		//cout<<ret<<endl;
		parseAutomaton(ret,aut_lst);
	}
	//ret+=s;
	//return ret;
}
