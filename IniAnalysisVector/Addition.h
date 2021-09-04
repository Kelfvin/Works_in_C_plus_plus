#pragma once
#include<vector>
#include<string>
#include"Addition.h"

using namespace std;

struct Pair
{
	string key;
	string value;
};

struct Paragraph
{
	string tittle;
	vector<Pair> content;
};




