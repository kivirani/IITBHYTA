
class Synchronizing_Label
{
public:
	string name;
	string id;
	friend bool operator==(const Synchronizing_Label &l1,const Synchronizing_Label &l2);
};
bool operator==(const Synchronizing_Label &l1,const Synchronizing_Label &l2)
{
	if(l1.name==l2.name)
		return true;
	return false;
}
