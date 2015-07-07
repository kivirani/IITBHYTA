#include <ppl.hh>
using namespace std;

Constraint_System operator^(Constraint c1,Constraint c2)
{
	Constraint_System cs;
	cs.set_space_dimension(c1.space_dimension());
	cs.insert(c1);
	cs.insert(c2);
	return cs;
}

Constraint_System operator^(Constraint_System cs1,Constraint c1)
{
	Constraint_System cs;
	cs.set_space_dimension(cs1.space_dimension());
	cs=cs1;
	cs.insert(c1);
	return cs;
}
Constraint_System operator^(Constraint c1,Constraint_System cs1)
{
	Constraint_System cs;
	cs.set_space_dimension(cs1.space_dimension());
	cs=cs1;
	cs.insert(c1);
	return cs;
}
Constraint_System operator^(Constraint_System cs1,Constraint_System cs2)
{
	Constraint_System cs;
	cs.set_space_dimension(cs1.space_dimension());
	cs=cs1;
	for(Constraint_System_const_iterator csit=cs2.begin();csit!=cs2.end();csit++)
	{
		cs.insert(*csit);
	}
	return cs;
}
NNC_Polyhedron operator^(NNC_Polyhedron np1,Constraint c1)
{
	NNC_Polyhedron np;
	np.add_space_dimensions_and_embed(np1.space_dimension());
	np=np1;
	np.add_constraint(c1);
	return np;
}
NNC_Polyhedron operator^(Constraint c1,NNC_Polyhedron np1)
{
	NNC_Polyhedron np;
	np.add_space_dimensions_and_embed(np1.space_dimension());
	np=np1;
	np.add_constraint(c1);
	return np;
}

NNC_Polyhedron operator^(NNC_Polyhedron np1,Constraint_System cs)
{
	NNC_Polyhedron np;
	np.add_space_dimensions_and_embed(np1.space_dimension());
	np=np1;
	np.add_constraints(cs);
	return np;
}
NNC_Polyhedron operator^(Constraint_System cs,NNC_Polyhedron np1)
{
	NNC_Polyhedron np;
	np.add_space_dimensions_and_embed(np1.space_dimension());
	np=np1;
	np.add_constraints(cs);
	return np;
}



NNC_Polyhedron operator^(NNC_Polyhedron np1,NNC_Polyhedron np2)
{
	NNC_Polyhedron np;
	np.add_space_dimensions_and_embed(np1.space_dimension());
	np=np1;
	np.intersection_assign(np2);
	return np;
}




void add_trivial_constraints(Constraint_System &cs)
{

	//cout<<"SD:"<<cs.space_dimension()<<endl;
	for(int i=0;i<cs.space_dimension();i++)
	{
		cs.insert(Variable(i)>=0);

	}
}



Constraint_System invert_Coefficients(Constraint_System c)
{
	Constraint_System ret;
	ret.set_space_dimension(c.space_dimension());
	//add_trivial_constraints(ret);
	for(Constraint_System_const_iterator c1=c.begin();c1!=c.end();c1++)
	{
		//Constraint c1(x - 5*y + 3*z <= 4);
		Linear_Expression e;
		e.set_space_dimension(c.space_dimension());
		//cout << "Constraint c1: " << *c1 << endl;


		for (dimension_type i = (*c1).space_dimension(); i-- > 0; )
		{

			//cout<<"Coe:"<<(*c1).coefficient(Variable(i)).get_si()*(-1)<<endl;
			e.set_coefficient(Variable(i),(*c1).coefficient(Variable(i))*(-1));

		}
		e += (*c1).inhomogeneous_term();
		Constraint c2;
		c2.set_space_dimension(c.space_dimension());

		if((*c1).is_equality())
		{
			c2=(e==0);
		}
		else
			c2=(*c1).is_strict_inequality() ? (e > 0) : (e >= 0);
		//cout << "Complement c2: " << c2 << endl;
		ret.insert(c2);

	}
	/*for(Constraint_System_const_iterator c1=ret.begin();c1!=ret.end();c1++)
	{
		cout<<"ret:"<<(*c1)<<endl;
	}*/
	return ret;
}


Constraint apply_Update(Constraint c,Constraint up)
{
	Constraint ret;
	ret.set_space_dimension(c.space_dimension());
	int coeff=0;
	Linear_Expression e;
	e.set_space_dimension(c.space_dimension());

	//calculate value and dim
	int dim,val;
	for(dimension_type i = up.space_dimension(); i-- > 0; )
	{
		if(up.coefficient(Variable(i)).get_si()!=0)
		{
			//cout<<"found: "<<i<<" "<<up.coefficient(Variable(i)).get_si()<<endl;
			dim=i;
		}
	}


	val=(-1)*(up.inhomogeneous_term().get_si());

	//cout<<"dim:"<<dim<<" val:"<<val<<endl;

	for (dimension_type i = c.space_dimension(); i-- > 0; )
	{
		if(i==dim)
		{
			coeff=c.coefficient(Variable(i)).get_si();
		}
		else
		{
			e += c.coefficient(Variable(i))*Variable(i);
		}
	}
	//cout<<"e:"<<e<<" for c:"<<c<<" inho:"<<c.inhomogeneous_term().get_si()<<endl;

	e+=(c.inhomogeneous_term()+coeff*val);

	//Constraint cd(Variable(0)>=0);
	if(c.is_equality())
	{
		ret=(e==0);
	}
	else
	{
		if(c.is_strict_inequality())
		{
			ret=(e>0);
		}
		else
		{
			ret=(e>=0);
		}
	}

	if(ret.is_inconsistent())
	{
		ret=up;
	}

	//cout<<"Before:"<<c<<" Ret:"<<ret<<endl;

	//ret = c.is_strict_inequality() ? (e >= 0) : (e > 0);


	//cout<<"Before updation:"<<c<<endl;
	//cout << "Updated constraint: " << ret << endl;
	//cout<<"c:"<<c<<" up:"<<up<<" Return:"<<ret<<endl;

	return ret;


}
