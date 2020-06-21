class Solution {
public:
    vector<vector<string>> displayTable(vector<vector<string>>& orders) {
	vector<vector<string> > ans;
	unordered_map<string, int> food_to_int;

	vector<string> chart;
	chart.push_back("Table");
	/*
	auto comp = [](const string& a, const string& b) {
		if (a.compare(b)>0) {
			return false;
		}
		return true;
	};
	*/
	map<int, unordered_map<string, int>> db;

	for (auto it : orders) {
		/*if (db.find(it[1]) == db.end()) {
			unordered_map<string, int> tmp_map;
			db.insert(it[1], tmp_map);
		}*/
		if (db[stoi(it[1])].find(it[2]) == db[stoi(it[1])].end()) {
			db[stoi(it[1])][it[2]] = 1;

		}
		else {
			db[stoi(it[1])][it[2]] += 1;
		}
		if (food_to_int.find(it[2]) == food_to_int.end()) {
			chart.push_back(it[2]);
			food_to_int[it[2]] = 0;
		}
	}



	sort(chart.begin() + 1, chart.end());

	for (int i = 1;i<chart.size();++i) {
		food_to_int[chart[i]] = i;
	}

	ans.push_back(chart);

	for (auto it = db.begin();it != db.end();++it) {
		vector<string> row(chart.size(), "0");
		row[0] = to_string(it->first);
		for (auto jt = it->second.begin();jt != it->second.end();++jt) {
			string food = jt->first;
			int quantity = jt->second;
			row[food_to_int[food]] = to_string(quantity);
		}
		ans.push_back(row);
	}
	return ans;
}

};
