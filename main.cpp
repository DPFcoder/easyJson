#include "jsonObj.h"
#include "iostream"
using namespace std;

int main(int argc, char* argv[])
{
	jsonObj test;
	const char* jsonstr =
	"{"
		"\"employees\": ["
			"{"
				"\"firstName\": \"Bill\","
				"\"lastName\" : \"Gates\""
			"},"
			"{"
				"\"firstName\": \"George\","
				"\"lastName\" : \"Bush\""
			"},"
			"{"
				"\"firstName\": \"Thomas\","
				"\"lastName\" : \"Carter\""
			"}"
		"]"
	"}";
	if (!test.CjsonParse(jsonstr)) {
		cout << "parse json err" << endl;
		return -1;
	}
	cout << "test1:" << endl;
	if (test["employees"].PushArrObj()) {
		for (int i = 0; test[i]; ++i) {
			cout << (const char*)test[i]["firstName"] << endl;
			cout << (const char*)test[i]["lastName"] << endl;
		}
		test.PopArrObj();
	}
	cout << endl <<  "test2:" << endl;
	cout << (const char*)test["employees"][0]["firstName"] << endl;
	cout << (const char*)test["employees"][0]["lastName"] << endl;
	cout << (const char*)test["employees"][1]["firstName"] << endl;
	cout << (const char*)test["employees"][1]["lastName"] << endl;
	cout << (const char*)test["employees"][2]["firstName"] << endl;
	cout << (const char*)test["employees"][2]["lastName"] << endl;
	cout << endl << "test3:" << endl;
	for (int i = 0; test["employees"][i]; ++i) {
		cout << (const char*)test["employees"][i]["firstName"] << endl;
		cout << (const char*)test["employees"][i]["lastName"] << endl;
	}
	return 0;
}