class Parameter
{
public:
	string name;
	string id;
	friend bool operator==(const Parameter &p1,const Parameter &p2);
};
bool operator==(const Parameter &p1,const Parameter &p2)
{
	if(p1.name==p2.name)
		return true;
	return false;
}
