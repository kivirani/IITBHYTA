#include <iostream>
#include <cstring>

#include <ppl.hh>

using namespace std;
using namespace Parma_Polyhedra_Library;
using namespace Parma_Polyhedra_Library::IO_Operators;


vector<vector<State> > take_union(vector<vector<State> > R_old,vector<vector<State> > R_cur)
{
	vector<vector<State> > ret;
	for(vector<vector<State> >::iterator it=R_old.begin();it!=R_old.end();it++)
	{
		ret.push_back(*it);
	}
	for(vector<vector<State> >::iterator it=R_cur.begin();it!=R_cur.end();it++)
	{
		ret.push_back(*it);
	}
	return ret;
}

vector<vector<State> > operator+(vector<vector<State> > R_old,vector<vector<State> > R_cur)
{
	vector<vector<State> > ret;
	for(vector<vector<State> >::iterator it=R_old.begin();it!=R_old.end();it++)
	{
		ret.push_back(*it);
	}
	for(vector<vector<State> >::iterator it=R_cur.begin();it!=R_cur.end();it++)
	{
		ret.push_back(*it);
	}
	return ret;
}

vector<vector<State> > operator+(vector<vector<State> > R_old,vector<State> R_cur)
{
	vector<vector<State> > ret;
	for(vector<vector<State> >::iterator it=R_old.begin();it!=R_old.end();it++)
	{
		ret.push_back(*it);
	}
	ret.push_back(R_cur);

	return ret;
}

vector<vector<State> > operator+(vector<State> R_cur,vector<vector<State> > R_old)
{
	vector<vector<State> > ret;
	for(vector<vector<State> >::iterator it=R_old.begin();it!=R_old.end();it++)
	{
		ret.push_back(*it);
	}
	ret.push_back(R_cur);

	return ret;
}
vector<vector<State> > operator+(vector<State> R_cur,vector<State> R_old)
{
	vector<vector<State> > ret;

	ret.push_back(R_old);

	ret.push_back(R_cur);

	return ret;
}





bool is_intersection_phi_state(vector<State> R_cur,vector<State> R_i)
{
	if(R_cur.size()==0 || R_i.size()==0)
	{
		return true;
	}
	for(vector<State>::iterator it=R_cur.begin();it!=R_cur.end();it++)
	{
		for(vector<State>::iterator itt=R_i.begin();itt!=R_i.end();itt++)
		{
			if((*itt).l.name==(*it).l.name && (*it).poly.contains((*itt).poly))
			{
				//cout<<"Inside"<<endl;
				return false;
			}
		}
	}
	return true;

}


bool is_intersection_phi(vector<vector<State> > R_cur,vector<vector<State> > R_i)
{
	if(R_cur.size()==0 || R_i.size()==0)
	{
		return true;
	}
	for(vector<vector<State> >::iterator it=R_cur.begin();it!=R_cur.end();it++)
	{
		for(vector<vector<State> >::iterator itt=R_i.begin();itt!=R_i.end();itt++)
		{

			if(!is_intersection_phi_state(*it,*itt))
			{
				return false;
			}
			/*if((*itt).l.name==(*it).l.name && (*it).poly.contains((*itt).poly))
			{
				//cout<<"Inside"<<endl;
				return false;
			}*/
		}
	}
	return true;

}


bool is_subset_of_state(vector<State> R_cur,vector<State> R_old)
{
	bool flag=true;
	for(vector<State>::iterator it=R_cur.begin();it!=R_cur.end();it++)
	{
		//cout<<"Rcur:"<<(*it).poly<<endl;
		flag=false;
		for(vector<State>::iterator itt=R_old.begin();itt!=R_old.end();itt++)
		{

			NNC_Polyhedron ptmp;
			ptmp.add_space_dimensions_and_embed((*it).poly.space_dimension());
			ptmp=(*itt).poly;

			ptmp.intersection_assign((*it).poly);

			//if((*itt).l.name==(*it).l.name && (*itt).poly==(*it).poly)
			if((*itt).l.name==(*it).l.name && ptmp==(*it).poly)
			//if((*itt).l.name==(*it).l.name && n==(*it).poly)
			{
				//return false;
				//cout<<""<<(*it).l.name<<","<<(*it).poly<<" is contained in "<<(*itt).l.name<<","<<(*itt).poly<<endl;
				flag=true;
				break;
			}
		}
		if(flag==false)
			return false;
	}
	//cout<<"Flag:"<<flag<<endl;
	return flag;


}


bool is_subset_of(vector<vector<State> > R_cur,vector<vector<State> > R_old)
{
	bool flag=true;
	for(vector<vector<State> >::iterator it=R_cur.begin();it!=R_cur.end();it++)
	{
		//cout<<"Rcur:"<<(*it).poly<<endl;
		flag=false;
		for(vector<vector<State> >::iterator itt=R_old.begin();itt!=R_old.end();itt++)
		{


			if(is_subset_of_state((*it),(*itt)))
			//if((*itt).l.name==(*it).l.name && n==(*it).poly)
			{
				//return false;
				//cout<<""<<(*it).l.name<<","<<(*it).poly<<" is contained in "<<(*itt).l.name<<","<<(*itt).poly<<endl;
				flag=true;
				break;
			}
		}
		if(flag==false)
			return false;
	}
	//cout<<"Flag:"<<flag<<endl;
	return flag;

}
void printR(vector<vector<State> > v,int i)
{
	cout<<"Iteration:"<<i<<endl;

	for(vector<vector<State> >::iterator itt=v.begin();itt!=v.end();itt++)
	{
		cout<<"started:"<<endl;
		//cout<<"Insize:"<<itt->size()<<endl;
		for(vector<State>::iterator it=(*itt).begin();it!=(*itt).end();it++)
		{
			cout<<"  "<<(*it).l.name<<", "<<(*it).poly<<endl;
		}
		cout<<endl;
	}
	cout<<endl;
}
