#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <fstream>
#include <stdlib.h>
#include <stdio.h>
#include <set>
using namespace std;

static int count_case = 0;
class Country {
public:
	string country_name;
	string state_name;
	string city_name;
	Country() {}
	Country(string country_name,string state_name, string city_name) {
		country_name = country_name;
		state_name = state_name;
		city_name = city_name;
	}
};
class disease {
public:
	string disease_string;
	bool operator==(const disease d)const {
		return disease_string == d.disease_string;
	}
	disease(string name) {
		this->disease_string = name;
	}
};

struct hash_disease{
	template <class T>
	size_t operator()(const disease& d)const {
		size_t h1 = hash<T>(d);
		return h1;
	}
};

class Case{
public:
	int case_id;
	string patient_name;
	Country country;
	string date;
	vector<disease> diseases;
	string status;
	Case(int case_id, string patient_id, Country& country, disease& d,string status) {
		this->case_id = case_id;
		this->patient_name = patient_name;
		this->country = country;
		this->diseases.push_back(d);
		this->status = status;
	}
};
class DiseaseTracker {
public:
	vector<Case> db;
	void report(string disease_name,string patient_id,string county_name,string state,string city) {
		disease *d = new disease(disease_name);
		Country *country = new Country(county_name, state, city);
		Case *nncase = new Case(count_case,patient_id,*country,*d,"active");
		bool flag = false;
		for (auto it = db.begin();it != db.end();++it) {
			if (it->patient_name == patient_id) {
				it->diseases.push_back(*d);
				flag = true;
				break;
			}
		}
		if (!flag) {
			db.push_back(*nncase);
		}
	
	}
	void showWorldSummary() {
		int a_count = 0;
		int c_count = 0;
		int f_count = 0;
		int total = 0;
		for (auto it = db.begin();it != db.end();++it) {
			if (it->status == "active") {
				a_count++;
			}
			else if (it->status == "cured") {
				c_count++;
			}
			else if (it->status == "fatality"){
				f_count++;
			}
		}
		cout << "Total :" << db.size() << endl << "Cured: " << c_count << endl << "Fatality: " << f_count << endl << "Active: " << a_count << endl;
	}
	void showWorldSummaryDiseaseBreakup() {
		unordered_map<string, vector<Case> > mmap;
		for (auto it = db.begin();it != db.end();++it) {
			mmap[it->country.country_name].push_back(*it);
		}
		for (auto it = mmap.begin();it != mmap.end();++it) {
			unordered_map<string, int> mymap;
			cout << it->first << ":" << endl;
			for (auto itr = it->second.begin();itr != it->second.end();++itr) {
				mymap[itr->status] += 1;
			}
			cout << "Total: " << it->second.size() << endl << "cured: " << mymap["cured"] <<endl<<"Active"<< mymap["active"]<<endl;
		}
	}
	void showCountryBreakup(string disease) {

	}
	void showStateBreakup(string disease, string country) {

	}
	void showTrends() {

	}
	void cured(string disease, string patient) {

	}
};
int main() {
	
	DiseaseTracker diseaseTracker;

	diseaseTracker.report("COVID - 19", "P1", "China", "Hubei", "Wuhan");
	//diseaseTracker.report("COVID - 19", "P89", "China", "Hubei", "Wuhan");
	diseaseTracker.report("COVID - 19", "P2", "China", "Hubei", "Wuhan");
	diseaseTracker.report("COVID - 19", "P3", "China", "Jiangsu", "Shanghai");
	diseaseTracker.report("COVID - 19", "P4", "India", "Uttar Pradesh", "Agra");
	diseaseTracker.report("COVID - 19", "P5", "India", "Uttar Pradesh", "Varanasi");
	diseaseTracker.report("COVID - 19", "P6", "India", "Karnataka", "Bangalore");
	diseaseTracker.report("COVID - 19", "P7", "India", "Karnataka", "Bangalore");
	diseaseTracker.report("COVID - 19", "P8", "India", "Karnataka", "Bangalore");
	diseaseTracker.report("Spanish Flu", "P9", "USA", "California", "Los Angeles");
	diseaseTracker.report("Spanish Flu", "P10", "USA", "California", "San - francisco");
	diseaseTracker.showWorldSummary();
	diseaseTracker.showWorldSummaryDiseaseBreakup();
	return 0;
}
