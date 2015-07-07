#include <ppl.hh>
using namespace std;



void add_trivial_constraints_to_poly(NNC_Polyhedron &poly)
{
	//cout<<"PD:"<<poly.space_dimension()<<endl;
	
	//cout<<"CheckMarking"<<endl;
	/*for(int i=0;i<poly.space_dimension();i++)
	{
		poly.add_constraint(Variable(i)>=0);
	}*/
}

NNC_Polyhedron apply_Updates(NNC_Polyhedron p,Constraint_System updates)
{

	NNC_Polyhedron ret;
	ret.add_space_dimensions_and_embed(p.space_dimension());
	ret=p;
	int n=0;
	for(Constraint_System_const_iterator upit=updates.begin();upit!=updates.end();upit++)
	{
		n++;
		NNC_Polyhedron tmp1,tmp2;
		tmp1.add_space_dimensions_and_embed(p.space_dimension());
		tmp2.add_space_dimensions_and_embed(p.space_dimension());
		for(dimension_type i = upit->space_dimension(); i-- > 0; )
		{
			if(upit->coefficient(Variable(i)).get_si()!=0)
			{
				tmp1.add_constraint(Variable(i)==-1);
				tmp2.add_constraint(Variable(i)==1);
			}
			else
			{
				tmp1.add_constraint(Variable(i)==0);
				tmp2.add_constraint(Variable(i)==0);
			}
		}
		ret.time_elapse_assign(tmp1);
		ret.time_elapse_assign(tmp2);
	}
	if(n==0)
		return ret;
	//ret.add_constraints(updates);
	add_trivial_constraints_to_poly(ret);
	return ret;
}



NNC_Polyhedron apply_Updatess(NNC_Polyhedron p,Constraint_System updates)
{
	NNC_Polyhedron ret;
	ret.add_space_dimensions_and_embed(p.space_dimension());
	Constraint_System cs;
	cs.set_space_dimension(p.space_dimension());
	cs=p.constraints();

	Constraint_System cstmp;
	cstmp.set_space_dimension(p.space_dimension());
	//cstmp=p.constraints();

	for(Constraint_System_const_iterator csit=cs.begin();csit!=cs.end();csit++)
	{
		Constraint c;
		c.set_space_dimension(p.space_dimension());
		c=(*csit);
		for(Constraint_System_const_iterator upit=updates.begin();upit!=updates.end();upit++)
		{
			//apply upit on c store result into c
			c=apply_Update(c,*upit);

		}
		//add constraint to cstmp
		/*if(c.is_tautological() || c.is_inconsistent())
		{
			cout<<"true"<<endl;
		}
		else*/
			cstmp.insert(c);



	}
	ret.add_constraints(cstmp);

	/*for(Constraint_System_const_iterator csit=ret.constraints().begin();csit!=ret.constraints().end();csit++)
	{
		cout<<"Added constraints:"<<*csit<<endl;
	}*/
	return ret;

}

