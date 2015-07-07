//#include "mtp_proj.h"
#include "mtp_proj.cpp"

using namespace std;
class LocationStr
{
public:
	string name;
	string id;
	vector<string> invariants;
	vector<string> rate;
};

class EdgeStr
{
public:
	string pre;
	string post;
	vector<string> guards;
	vector<string> updates;
	string syn_lab;
	string aut_nm;
};

class AutomatonStr
{
public:
	string name;
	string id;
	Control_Variable_List cntr_var_lst;
	Parameter_List parameter_lst;
	Synchronizing_Label_List syn_lab_lst;
	Input_Variable_List in_var_lst;
	
	vector<LocationStr> loc_lst;
	vector<LocationStr> initial_loc_lst;
	vector<LocationStr> final_loc_lst;
	vector<EdgeStr> edge_lst;
};



class Parser_Automaton_List
{
public:
	vector<AutomatonStr> aut_arr;
};
map<string,string> createAutomatonMap(Automaton_List a_lst)
{
	map<string,string> cntrToautmap;
	for(vector<Automaton>::iterator it=a_lst.aut_arr.begin();it!=a_lst.aut_arr.end();it++)
	{
		
		for(map<string,string>::iterator itt=it->cntrToautmap.begin();itt!=it->cntrToautmap.end();itt++)
		{
			cntrToautmap[itt->first]=itt->second;
		}		
	}
	return cntrToautmap;
}

map<string,string> createAutomatonMap(Automaton a)
{
	map<string,string> cntrToautmap;
	
	for(map<string,string>::iterator itt=a.cntrToautmap.begin();itt!=a.cntrToautmap.end();itt++)
	{
		cntrToautmap[itt->first]=itt->second;
	}			

	return cntrToautmap;
}

map<string,string> createAutomatonMap(AutomatonStr a)
{
	map<string,string> cntrToautmap;
	
	for(vector<string>::iterator sit=a.cntr_var_lst.cntr_var_arr.begin();sit!=a.cntr_var_lst.cntr_var_arr.end();sit++)
	{
		cntrToautmap[*sit]=a.name;
	}		

	return cntrToautmap;
}


map<string,string> createAutomatonMap(vector<AutomatonStr> a_lst)
{
	map<string,string> cntrToautmap;
	
	for(vector<AutomatonStr>::iterator it=a_lst.begin();it!=a_lst.end();it++)
	{
		for(vector<string>::iterator sit=it->cntr_var_lst.cntr_var_arr.begin();sit!=it->cntr_var_lst.cntr_var_arr.end();sit++)
		{
			cntrToautmap[*sit]=it->name;
		}		
	}
	return cntrToautmap;
}
vector<string> takeUnionVS(vector<string> vs1,vector<string> vs2)
{
	set<string> ret;
	for(vector<string>::iterator it=vs1.begin();it!=vs1.end();it++)
	{
		ret.insert(*it);
	}
	for(vector<string>::iterator it=vs2.begin();it!=vs2.end();it++)
	{
		ret.insert(*it);
	}
	
	vector<string> vsret(ret.begin(),ret.end());
	return vsret;
}


vector<string> remove_duplicates(vector<string> vs)
{

	set<string> ret;
	for(vector<string>::iterator it=vs.begin();it!=vs.end();it++)
	{
		ret.insert(*it);
	}
	
	vector<string> vsret(ret.begin(),ret.end());
	return vsret;
}


vector<string> takeUnionVINV(vector<Input_Variable> vs1,vector<Input_Variable> vs2)
{
	set<string> ret;
	for(vector<Input_Variable>::iterator it=vs1.begin();it!=vs1.end();it++)
	{
		ret.insert(it->name);
	}
	for(vector<Input_Variable>::iterator it=vs2.begin();it!=vs2.end();it++)
	{
		ret.insert(it->name);
	}
	
	vector<string> vsret(ret.begin(),ret.end());
	return vsret;
}

bool is_disjoint(vector<string> vs1,vector<string> vs2)
{
	bool ret;
	set<string> s1;
	set<string> s2;
	for(vector<string>::iterator it=vs1.begin();it!=vs1.end();it++)
	{
		s1.insert(*it);
	}
	for(vector<string>::iterator it=vs2.begin();it!=vs2.end();it++)
	{
		s2.insert(*it);
	}
	

	vector<string> v(100);

	vector<string>::iterator it;
	it=set_intersection(vs1.begin(),vs1.end(),vs2.begin(),vs2.end(),v.begin());

	v.resize(it-v.begin());

	if(v.size()==0)
		ret=true;
	else
		ret=false;
	return ret;
}

bool is_in(vector<Input_Variable> vs1,vector<string> vs)
{
	bool ret=true;
	for(vector<Input_Variable>::iterator it=vs1.begin();it!=vs1.end();it++)
	{
		bool flg=false;
		for(vector<string>::iterator itt=vs.begin();itt!=vs.end();itt++)
		{
			if((*itt)==(it->name))
			{
				flg=true;
			}
			
		}
		if(flg==false)
		{
			ret=false;
		}
	}
	return ret;
}

void printHybridAutomatonStr(AutomatonStr *a)
{
	cout<<"\nAutomaton Name:"<<a->name<<endl;				
	
	cout<<"Control Variable List:"<<endl;
	for(vector<string>::iterator it=a->cntr_var_lst.cntr_var_arr.begin();it!=a->cntr_var_lst.cntr_var_arr.end();it++)
	{
		cout<<*it<<",";
	}
	cout<<endl;

	cout<<"Parameter List:"<<endl;
	for(vector<Parameter>::iterator it=a->parameter_lst.par_list_arr.begin();it!=a->parameter_lst.par_list_arr.end();it++)
	{
		cout<<it->name<<",";
	}
	cout<<endl;
	
	cout<<"Synchronizing Label List:"<<endl;
	for(vector<Synchronizing_Label>::iterator it=a->syn_lab_lst.syn_lab_arr.begin();it!=a->syn_lab_lst.syn_lab_arr.end();it++)
	{
		cout<<it->name<<",";
	}
	cout<<endl;

	cout<<"Input Variable List:"<<endl;
	for(vector<Input_Variable>::iterator it=a->in_var_lst.in_var_arr.begin();it!=a->in_var_lst.in_var_arr.end();it++)
	{
		cout<<it->name<<",";
	}
	cout<<endl;

	cout<<"Location List:"<<endl;
	for(vector<LocationStr>::iterator it=a->loc_lst.begin();it!=a->loc_lst.end();it++)
	{
		cout<<it->name<<" ";
		for(vector<string>::iterator itt=it->invariants.begin();itt!=it->invariants.end();itt++)
		{
			cout<<*itt<<",";
		}
		cout<<"      rates:";
		for(vector<string>::iterator itt=it->rate.begin();itt!=it->rate.end();itt++)
		{
			cout<<*itt<<",";
		}				
		cout<<endl;
	}
	cout<<"Initial Location List:"<<endl;
	for(vector<LocationStr>::iterator it=a->initial_loc_lst.begin();it!=a->initial_loc_lst.end();it++)
	{
		cout<<it->name<<" invariants:";
		for(vector<string>::iterator itt=it->invariants.begin();itt!=it->invariants.end();itt++)
		{
			cout<<*itt<<",";
		}
		cout<<endl;
	}

	cout<<"Edge List:"<<endl;
	for(vector<EdgeStr>::iterator it=a->edge_lst.begin();it!=a->edge_lst.end();it++)
	{
		cout<<it->pre<<" "<<it->post<<" "<<it->syn_lab<<" ";
		for(vector<string>::iterator itt=it->guards.begin();itt!=it->guards.end();itt++)
		{
			cout<<*itt<<",";
		}
		cout<<"      updates:";
		for(vector<string>::iterator itt=it->updates.begin();itt!=it->updates.end();itt++)
		{
			cout<<*itt<<",";
		}				
		cout<<endl;
	}
}

void printHybridAutStrSet(vector<AutomatonStr> vautstr)
{
	for(vector<AutomatonStr>::iterator it=vautstr.begin();it!=vautstr.end();it++)
	{
		printHybridAutomatonStr(&(*it));	
	}
}
/*Constraint findConstraintFromString(string str,Automaton a)
{
	Constraint ctmp;

	int bool_operator_pos;
	string bool_operator;	

	Linear_Expression left_le;
	Linear_Expression right_le;		


	if(str=="true")
	{
		ctmp.set_space_dimension(a.cntr_var_lst.cntr_var_arr.size());
		bool_operator="==";
		left_le.set_space_dimension(a.cntr_var_lst.cntr_var_arr.size());
		left_le.set_inhomogeneous_term(0);
		right_le.set_space_dimension(a.cntr_var_lst.cntr_var_arr.size());		
		right_le.set_inhomogeneous_term(0);		
		ctmp=make_Constraints(left_le,right_le,bool_operator);		
		return ctmp;
	}
	else
	{
		if(str=="false")
		{
			ctmp.set_space_dimension(a.cntr_var_lst.cntr_var_arr.size());
			bool_operator="<";
			left_le.set_space_dimension(a.cntr_var_lst.cntr_var_arr.size());
			left_le.set_inhomogeneous_term(0);
			right_le.set_space_dimension(a.cntr_var_lst.cntr_var_arr.size());		
			right_le.set_inhomogeneous_term(0);		
			ctmp=make_Constraints(left_le,right_le,bool_operator);		
			return ctmp;
		}
	}


	bool_operator=find_bool_operator(str);
	bool_operator_pos=str.find(bool_operator);

	left_le.set_space_dimension(a.cntr_var_lst.cntr_var_arr.size());
	left_le=find_Linear_Expression(str.substr(0,bool_operator_pos),a.cntr_var_lst.cntr_var_arr.size(),a);

	right_le.set_space_dimension(a.cntr_var_lst.cntr_var_arr.size());
	right_le=find_Linear_Expression(str.substr(bool_operator_pos+bool_operator.size()),a.cntr_var_lst.cntr_var_arr.size(),a);
	//cout<<"Left:"<<token.substr(0,bool_operator_pos)<<endl;
	//cout<<"Right:"<<token.substr(bool_operator_pos+bool_operator.size())<<endl;

	//cout<<"Left LE:"<<left_le<<endl;
	//cout<<"Right LE:"<<right_le<<endl;

	ctmp.set_space_dimension(a.cntr_var_lst.cntr_var_arr.size());
	ctmp=make_Constraints(left_le,right_le,bool_operator);
	//cout<<"Space dim size:"<<a.cntr_var_lst.cntr_var_arr.size()<<endl;
	//cout<<"Made Constraint:"<<ctmp<<endl;

	return ctmp;

}
*/

string find_bool_operator2(string str)
{
	vector<string> x = split(str, ' ');
	string ret="";
	for(vector<string>::iterator it=x.begin();it!=x.end();it++)
	{
		if((*it)=="<=" || (*it)==">=" || (*it)=="==" || (*it)=="<" || (*it)==">" || (*it)=="!=")
		{
			ret=(*it);
			break;
		}
	}
	return ret;	
}

Constraint findConstraintFromString(string str,Automaton a)
{
	Constraint ctmp;

	int bool_operator_pos;
	string bool_operator;	

	Linear_Expression left_le;
	Linear_Expression right_le;		


	if(str=="true")
	{
		ctmp.set_space_dimension(a.cntr_var_lst.cntr_var_arr.size());
		bool_operator="==";
		left_le.set_space_dimension(a.cntr_var_lst.cntr_var_arr.size());
		left_le.set_inhomogeneous_term(0);
		right_le.set_space_dimension(a.cntr_var_lst.cntr_var_arr.size());		
		right_le.set_inhomogeneous_term(0);		
		ctmp=make_Constraints(left_le,right_le,bool_operator);		
		return ctmp;
	}
	else
	{
		if(str=="false")
		{
			ctmp.set_space_dimension(a.cntr_var_lst.cntr_var_arr.size());
			bool_operator="<";
			left_le.set_space_dimension(a.cntr_var_lst.cntr_var_arr.size());
			left_le.set_inhomogeneous_term(0);
			right_le.set_space_dimension(a.cntr_var_lst.cntr_var_arr.size());		
			right_le.set_inhomogeneous_term(0);		
			ctmp=make_Constraints(left_le,right_le,bool_operator);		
			return ctmp;
		}
	}

		
	//cout<<"Before bool op finding:"<<str<<endl;
	
	bool_operator=find_bool_operator2(str);
	//cout<<"boolop:"<<bool_operator<<":"<<endl;	
	


	//bool_operator=find_bool_operator(str);
	bool_operator_pos=str.find(bool_operator);


	//cout<<"Left:"<<str.substr(0,bool_operator_pos)<<":"<<endl;
	left_le.set_space_dimension(a.cntr_var_lst.cntr_var_arr.size());
	left_le=find_Linear_Expression(str.substr(0,bool_operator_pos),a.cntr_var_lst.cntr_var_arr.size(),a);
	//cout<<"Found out linear exp:"<<left_le<<endl<<flush;

	//cout<<"string:"<<str<<endl;

	//cout<<"Right:"<<str.substr(bool_operator_pos+1+bool_operator.size())<<":"<<endl;
	right_le.set_space_dimension(a.cntr_var_lst.cntr_var_arr.size());
	right_le=find_Linear_Expression(str.substr(bool_operator_pos+1+bool_operator.size()),a.cntr_var_lst.cntr_var_arr.size(),a);
	//cout<<"Found out linear exp:"<<right_le<<endl;

	//cout<<"Left:"<<token.substr(0,bool_operator_pos)<<endl;
	//cout<<"Right:"<<token.substr(bool_operator_pos+bool_operator.size())<<endl;

	//cout<<"Left LE:"<<left_le<<endl;
	//cout<<"Right LE:"<<right_le<<endl;

	ctmp.set_space_dimension(a.cntr_var_lst.cntr_var_arr.size());
	ctmp=make_Constraints(left_le,right_le,bool_operator);
	//cout<<"Space dim size:"<<a.cntr_var_lst.cntr_var_arr.size()<<endl;
	//cout<<"Made Constraint:"<<ctmp<<endl;

	return ctmp;

}




Automaton autstrToaut(AutomatonStr in)
{
	Automaton ret;
	ret.name=in.name;
	ret.id=in.id;
	ret.cntr_var_lst=in.cntr_var_lst;
	ret.parameter_lst=in.parameter_lst;
	ret.syn_lab_lst=in.syn_lab_lst;
	ret.in_var_lst=in.in_var_lst;
	//cout<<"2aa"<<endl;
	ret.fillMaps();
	//cout<<"2ab:"<<in.loc_lst.size()<<endl;
	
	for(vector<LocationStr>::iterator it=in.loc_lst.begin();it!=in.loc_lst.end();it++)
	{
		Location l;	
		l.name=it->name;
		l.id=it->id;
		
		l.invariants.set_space_dimension(ret.cntr_var_lst.cntr_var_arr.size());
		l.rate.set_space_dimension(ret.cntr_var_lst.cntr_var_arr.size());


		for(vector<string>::iterator itt=it->invariants.begin();itt!=it->invariants.end();itt++)
		{
			//cout<<"Input:"<<(*itt)<<endl;
			l.invariants.insert(findConstraintFromString(*itt,ret));
			//cout<<"Out:"<<findConstraintFromString(*itt,ret)<<endl;
		}
		//cout<<"2aba"<<endl;
		for(vector<string>::iterator itt=it->rate.begin();itt!=it->rate.end();itt++)
		{
			l.rate.insert(findConstraintFromString(*itt,ret));
		}


		ret.loc_lst.location_arr.push_back(l);		
		//cout<<"2ac"<<endl;
	}

	for(vector<LocationStr>::iterator it=in.initial_loc_lst.begin();it!=in.initial_loc_lst.end();it++)
	{
		Location l;	
		l.name=it->name;
		l.id=it->id;

		l.invariants.set_space_dimension(ret.cntr_var_lst.cntr_var_arr.size());
		l.rate.set_space_dimension(ret.cntr_var_lst.cntr_var_arr.size());

		for(vector<string>::iterator itt=it->invariants.begin();itt!=it->invariants.end();itt++)
		{
			l.invariants.insert(findConstraintFromString(*itt,ret));
		}
		
		for(vector<string>::iterator itt=it->rate.begin();itt!=it->rate.end();itt++)
		{
			l.rate.insert(findConstraintFromString(*itt,ret));
		}

		ret.initial_loc_lst.location_arr.push_back(l);				
		//cout<<"2ad"<<endl;
	}

	for(vector<LocationStr>::iterator it=in.final_loc_lst.begin();it!=in.final_loc_lst.end();it++)
	{
		Location l;	
		l.name=it->name;
		l.id=it->id;

		l.invariants.set_space_dimension(ret.cntr_var_lst.cntr_var_arr.size());
		l.rate.set_space_dimension(ret.cntr_var_lst.cntr_var_arr.size());

		for(vector<string>::iterator itt=it->invariants.begin();itt!=it->invariants.end();itt++)
		{
			l.invariants.insert(findConstraintFromString(*itt,ret));
		}
		
		for(vector<string>::iterator itt=it->rate.begin();itt!=it->rate.end();itt++)
		{
			l.rate.insert(findConstraintFromString(*itt,ret));
		}		

		ret.final_loc_lst.location_arr.push_back(l);
		//cout<<"2ae"<<endl;				
	}

	for(vector<EdgeStr>::iterator it=in.edge_lst.begin();it!=in.edge_lst.end();it++)
	{
		Edge e;
		e.pre=it->pre;
		e.post=it->post;

		e.guards.set_space_dimension(ret.cntr_var_lst.cntr_var_arr.size());
		e.updates.set_space_dimension(ret.cntr_var_lst.cntr_var_arr.size());		


		for(vector<string>::iterator itt=it->guards.begin();itt!=it->guards.end();itt++)
		{
			e.guards.insert(findConstraintFromString(*itt,ret));
		}
		
		for(vector<string>::iterator itt=it->updates.begin();itt!=it->updates.end();itt++)
		{
			e.updates.insert(findConstraintFromString(*itt,ret));
		}


		e.syn_lab=it->syn_lab;
		e.aut_nm=it->aut_nm;
		
		ret.edge_lst.edge_arr.push_back(e);
		//cout<<"2af"<<endl;	
	}
	return ret;	
}



Automaton removeinvariants(Automaton a)
{
	Automaton ret;
	ret=a;
	for(vector<Edge>::iterator it=ret.edge_lst.edge_arr.begin();it!=ret.edge_lst.edge_arr.end();it++)
	{
		for(Constraint_System_const_iterator csit=a.loc_to_invar[it->pre].begin();csit!=a.loc_to_invar[it->pre].end();csit++)
		{
			it->guards.insert(*csit);
		}
		
	}
	for(vector<Location>::iterator lit=ret.loc_lst.location_arr.begin();lit!=ret.loc_lst.location_arr.end();lit++)
	{
		lit->invariants.clear();
	}
	ret.fillMaps();
	return ret;	
}





void initialize_final_states_from_symstate(vector<vector<State> > &R_f,pair<string,vector<string> > p,Automaton_List autlst)
{
	vector<State> rf;
	State s;
	s.l.name=p.first;
	s.poly.add_space_dimensions_and_embed(autlst.aut_arr.begin()->cntr_var_lst.cntr_var_arr.size());	
	for(vector<string>::iterator it=p.second.begin();it!=p.second.end();it++)
	{			
		s.poly.add_constraint(findConstraintFromString(*it,*(autlst.aut_arr.begin())));		
	}
	rf.push_back(s);
	R_f.push_back(rf);
}
void printHybridAutomaton(Automaton prod_aut)
{
	cout<<"Automaton Name:"<<prod_aut.name<<endl;
	cout<<"Control Variable List:";
	for(vector<string>::iterator sit=prod_aut.cntr_var_lst.cntr_var_arr.begin();sit!=prod_aut.cntr_var_lst.cntr_var_arr.end();sit++)
	{
		cout<<" "<<(*sit);
	}
	cout<<endl;

	cout<<"Synchronization Label:"<<endl;
	for(vector<Synchronizing_Label>::iterator it=prod_aut.syn_lab_lst.syn_lab_arr.begin();it!=prod_aut.syn_lab_lst.syn_lab_arr.end();it++)
	{
		cout<<" "<<it->name;
	}
	cout<<endl;

	cout<<"Parameters:"<<endl;
	for(vector<Parameter>::iterator it=prod_aut.parameter_lst.par_list_arr.begin();it!=prod_aut.parameter_lst.par_list_arr.end();it++)
	{
		cout<<" "<<it->name;
	}
	cout<<endl;
	cout<<"Initial Location:"<<endl;
	for(vector<Location>::iterator it=prod_aut.initial_loc_lst.location_arr.begin();it!=prod_aut.initial_loc_lst.location_arr.end();it++)
	{
		cout<<it->name<<", invar:"<<it->invariants<<endl;
	}
	cout<<"Location List:"<<endl;
	for(vector<Location>::iterator it=prod_aut.loc_lst.location_arr.begin();it!=prod_aut.loc_lst.location_arr.end();it++)
	{
		cout<<it->name<<", invar:"<<it->invariants<<", rate:"<<it->rate<<endl;
	}

	cout<<"Edge List:"<<endl;
	for(vector<Edge>::iterator it=prod_aut.edge_lst.edge_arr.begin();it!=prod_aut.edge_lst.edge_arr.end();it++)
	{
		cout<<" "<<it->pre<<" "<<it->post<<" "<<",guards:"<<it->guards<<", updates:"<<it->updates<<" "<<it->syn_lab<<endl;
	}
	cout<<"End2:"<<endl;


}

string constraintsystem_to_str(Constraint_System cs,int spacedim)
{
	NNC_Polyhedron np;
	np.add_space_dimensions_and_embed(spacedim);
	np.add_constraints(cs);


	ostringstream out;
	out<<np;
	//stringstream ss;
	//ss << out.rdbuf();
	//string mystring = ss.str();
	string mystring = out.str();
	return mystring;
}


void createDotFileFromAut(Automaton a,string str)
{
	map<string,int> m;

	ofstream dotfile;		
	string s=str+".dot";
	dotfile.open(s.c_str());
	
	dotfile<<"digraph "<<str<<" {\n rankdir=LR;\n size=\"8,5\"";

	int spacedim=a.cntr_var_lst.cntr_var_arr.size();

	int i=0;
	for(vector<Location>::iterator it=a.loc_lst.location_arr.begin();it!=a.loc_lst.location_arr.end();it++)
	{
		m[it->name]=i;
		string loc=it->name;
		loc=loc+"\\n";
		dotfile<<"\n";
		/*for(vector<string>::iterator itt=it->invariants.begin();itt!=it->invariants.end();itt++)
		{
			loc=loc+*itt;
		}*/
		loc=loc+constraintsystem_to_str(it->invariants,spacedim);
		loc=loc+"\\n";
		/*for(vector<string>::iterator itt=it->rate.begin();itt!=it->rate.end();itt++)
		{
			loc=loc+*itt;
		}*/
		loc=loc+constraintsystem_to_str(it->rate,spacedim);
		
		string formatcolor="red";
		dotfile<<i<<" ["<<"label=\""<<loc<<"\",color="<<formatcolor<<", style=filled];";
		i++;
	}
	for(vector<Edge>::iterator it=a.edge_lst.edge_arr.begin();it!=a.edge_lst.edge_arr.end();it++)
	{
		string guards;
		string updates;
		/*for(vector<string>::iterator itt=it->guards.begin();itt!=it->guards.end();itt++)
		{
			if(itt!=it->guards.begin())
				guards=guards+" & ";
			
			guards=guards+(*itt);
		}*/
		guards=guards+constraintsystem_to_str(it->guards,spacedim);

		/*for(vector<string>::iterator itt=it->updates.begin();itt!=it->updates.end();itt++)
		{
			if(itt!=it->updates.begin())
				updates=updates+" & ";
			updates=updates+(*itt);
		}*/
		updates=updates+constraintsystem_to_str(it->updates,spacedim);


		dotfile<<"\n"<<m[it->pre]<<" -> "<<m[it->post]<<" [label=\""<<it->syn_lab<<"\\n"<<guards<<"\\n"<<updates<<"\"];";
	}
	
	dotfile<<"\n}";
	dotfile.close();
}

void createDotFileFromAutStr(AutomatonStr a,string str)
{
	map<string,int> m;

	ofstream dotfile;		
	string s=str+".dot";
	dotfile.open(s.c_str());
	
	dotfile<<"digraph "<<str<<" {\n rankdir=LR;\n size=\"8,5\"";
	
	int i=0;
	for(vector<LocationStr>::iterator it=a.loc_lst.begin();it!=a.loc_lst.end();it++)
	{
		m[it->name]=i;
		string loc=it->name;
		loc=loc+"\\n";
		dotfile<<"\n";
		for(vector<string>::iterator itt=it->invariants.begin();itt!=it->invariants.end();itt++)
		{
			if(itt!=it->invariants.begin())
				loc=loc+" & ";
			loc=loc+*itt;
		}
		loc=loc+"\\n";
		for(vector<string>::iterator itt=it->rate.begin();itt!=it->rate.end();itt++)
		{
			if(itt!=it->rate.begin())
				loc=loc+" & ";
			loc=loc+*itt;
		}
		
		string formatcolor="red";
		dotfile<<i<<" ["<<"label=\""<<loc<<"\",color="<<formatcolor<<", style=filled];";
		i++;
	}
	for(vector<EdgeStr>::iterator it=a.edge_lst.begin();it!=a.edge_lst.end();it++)
	{
		string guards;
		string updates;
		for(vector<string>::iterator itt=it->guards.begin();itt!=it->guards.end();itt++)
		{
			if(itt!=it->guards.begin())
				guards=guards+" & ";
			
			guards=guards+(*itt);
		}
		for(vector<string>::iterator itt=it->updates.begin();itt!=it->updates.end();itt++)
		{
			if(itt!=it->updates.begin())
				updates=updates+" & ";
			updates=updates+(*itt);
		}
		dotfile<<"\n"<<m[it->pre]<<" -> "<<m[it->post]<<" [label=\""<<it->syn_lab<<"\\n"<<guards<<"\\n"<<updates<<"\"];";
	}
	
	dotfile<<"\n}";
	dotfile.close();
}

void createDotFileFromVAutStr(vector<AutomatonStr> vaut,string str)
{
	map<string,int> m;

	ofstream dotfile;		
	string s=str+".dot";
	dotfile.open(s.c_str());
	
	dotfile<<"digraph "<<str<<" {\n rankdir=LR;\n size=\"8,5\"";
	
	int i=0;
	for(vector<AutomatonStr>::iterator itp=vaut.begin();itp!=vaut.end();itp++)
	{
		for(vector<LocationStr>::iterator it=itp->loc_lst.begin();it!=itp->loc_lst.end();it++)
		{
			m[it->name]=i;
			string loc=it->name;
			loc=loc+"\\n";
			dotfile<<"\n";
			for(vector<string>::iterator itt=it->invariants.begin();itt!=it->invariants.end();itt++)
			{
				if(itt!=it->invariants.begin())
					loc=loc+" & ";
				loc=loc+*itt;
			}
			loc=loc+"\\n";
			for(vector<string>::iterator itt=it->rate.begin();itt!=it->rate.end();itt++)
			{
				if(itt!=it->rate.begin())
					loc=loc+" & ";
				loc=loc+*itt;
			}
		
			string formatcolor="red";
			dotfile<<i<<" ["<<"label=\""<<loc<<"\",color="<<formatcolor<<", style=filled];";
			i++;
		}
		for(vector<EdgeStr>::iterator it=itp->edge_lst.begin();it!=itp->edge_lst.end();it++)
		{
			string guards;
			string updates;
			for(vector<string>::iterator itt=it->guards.begin();itt!=it->guards.end();itt++)
			{
				if(itt!=it->guards.begin())
					guards=guards+" & ";
			
				guards=guards+(*itt);
			}
			for(vector<string>::iterator itt=it->updates.begin();itt!=it->updates.end();itt++)
			{
				if(itt!=it->updates.begin())
					updates=updates+" & ";
				updates=updates+(*itt);
			}
			dotfile<<"\n"<<m[it->pre]<<" -> "<<m[it->post]<<" [label=\""<<it->syn_lab<<"\\n"<<guards<<"\\n"<<updates<<"\"];";
		}
	}
	
	dotfile<<"\n}";
	dotfile.close();
}



