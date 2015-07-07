#include <vector>

#include "Edge.h"

bool compare_Edge_by_Syn_Lab(Edge e1,Edge e2)
{
	return (e1.syn_lab.compare(e2.syn_lab)<0);

}

bool compare_edge_by_aut(Edge e1,Edge e2)
{
	return (e1.aut_nm.compare(e2.aut_nm)<0);
}
class Edge_List
{
public:
	vector<Edge> edge_arr;
	void sort_by_syn_lab()
	{
		sort(edge_arr.begin(),edge_arr.end(),compare_Edge_by_Syn_Lab);
	}
	vector<vector<Edge> > aggregate_on_sync_lab()
	{
		vector<vector<Edge> > ret;
		sort_by_syn_lab();

		vector<Edge> tmp;
		string curr_sync="";
		for(vector<Edge>::iterator eit=edge_arr.begin();eit!=edge_arr.end();eit++)
		{
			if(eit->syn_lab!=curr_sync || eit->syn_lab=="")
			{
				if(eit!=edge_arr.begin())
				{
					ret.push_back(tmp);
					tmp.clear();
				}
				tmp.push_back(*eit);
			}
			else
			{
				tmp.push_back(*eit);
			}
			curr_sync=eit->syn_lab;
		}
		ret.push_back(tmp);

		return ret;

	}
	void sort_by_aut()
	{
		sort(edge_arr.begin(),edge_arr.end(),compare_edge_by_aut);
	}
	vector<vector<Edge> > aggregate_on_aut()
	{
		vector<vector<Edge> > ret;
		sort_by_aut();

		vector<Edge> tmp;
		string curr_aut="";
		for(vector<Edge>::iterator eit=edge_arr.begin();eit!=edge_arr.end();eit++)
		{
			if(eit->aut_nm!=curr_aut)
			{
				if(eit!=edge_arr.begin())
				{
					ret.push_back(tmp);
					tmp.clear();
				}
				tmp.push_back(*eit);
			}
			else
			{
				tmp.push_back(*eit);
			}
			curr_aut=eit->aut_nm;
		}
		ret.push_back(tmp);

		return ret;

	}
};

